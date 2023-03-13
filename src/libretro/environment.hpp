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

#ifndef MELONDS_DS_ENVIRONMENT_HPP
#define MELONDS_DS_ENVIRONMENT_HPP

#include <string>
#include <libretro.h>

namespace retro {
    /// For use by other parts of the core
    bool environment(unsigned cmd, void *data);

    void log(enum retro_log_level level, const char *fmt, ...);

    bool supports_bitmasks();
    void input_poll();
    int16_t input_state(unsigned port, unsigned device, unsigned index, unsigned id);
    size_t audio_sample_batch(const int16_t *data, size_t frames);
    void video_refresh(const void *data, unsigned width, unsigned height, size_t pitch);

}

#endif //MELONDS_DS_ENVIRONMENT_HPP
