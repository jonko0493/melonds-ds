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

#include "threads.hpp"

#include <new>
#include <stdexcept>

retro::slock::slock() {
    #ifndef EMSCRIPTEN
    mutex = slock_new();
    if (!mutex) {
        throw std::bad_alloc();
    }
    #endif
}

retro::slock::~slock() noexcept {
    #ifndef EMSCRIPTEN
    if (mutex) {
        slock_free(mutex);
    }
    mutex = nullptr;
    #endif
}

void retro::slock::lock() noexcept {
    #ifndef EMSCRIPTEN
    slock_lock(mutex);
    #endif
}

void retro::slock::unlock() noexcept {
    #ifndef EMSCRIPTEN
    slock_unlock(mutex);
    #endif
}

bool retro::slock::try_lock() noexcept {
    #ifndef EMSCRIPTEN
    return slock_try_lock(mutex);
    #else
    return false;
    #endif
}