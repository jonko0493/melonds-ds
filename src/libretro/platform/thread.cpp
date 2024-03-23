/*
    Copyright 2023 Jesse Talavera-Greenberg

    melonDS DS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS DS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS DS. If not, see http://www.gnu.org/licenses/.
*/

#include <libretro.h>
#include <rthreads/rthreads.h>
#include <Platform.h>

#include <utility>

using namespace melonDS;
using Platform::Thread;
struct Platform::Thread {
    sthread_t *thread;
};
struct ThreadData {
    std::function<void()> fn;
};

static void function_trampoline(void *param) {
    auto *data = (ThreadData *) param;
    data->fn();
    delete data;
}

Thread *Platform::Thread_Create(std::function<void()> func) {
#ifndef EMSCRIPTEN
    return new Thread {
        sthread_create(function_trampoline, new ThreadData{std::move(func)})
    };
#else
    return nullptr;
#endif
}

void Platform::Thread_Wait(Thread *thread) {
#ifndef EMSCRIPTEN
    sthread_join(thread->thread);
    thread->thread = nullptr;
#endif
}

void Platform::Thread_Free(Thread *thread) {
#ifndef EMSCRIPTEN
    if (thread->thread) {
        sthread_join(thread->thread);
        thread->thread = nullptr;
    }

    delete thread;
#endif
}
