/*
 * This file is part of the KyrianCORE HolyDEEW Project. See AUTHORS file for Copyright information

 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "GameTime.h"
#include "Timer.h"
#include "Util.h"

namespace GameTime
{
    time_t const StartTime = time(nullptr);

    time_t GameTime = 0;
    uint32 GameMSTime = 0;

    std::chrono::system_clock::time_point GameTimeSystemPoint = std::chrono::system_clock::time_point::min();
    std::chrono::steady_clock::time_point GameTimeSteadyPoint = std::chrono::steady_clock::time_point::min();

    tm DateTime;

    time_t GetStartTime()
    {
        return StartTime;
    }

    time_t GetGameTime()
    {
        return GameTime;
    }

    uint32 GetGameTimeMS()
    {
        return GameMSTime;
    }

    std::chrono::system_clock::time_point GetGameTimeSystemPoint()
    {
        return GameTimeSystemPoint;
    }

    std::chrono::steady_clock::time_point GetGameTimeSteadyPoint()
    {
        return GameTimeSteadyPoint;
    }

    template<typename Clock>
    typename Clock::time_point GetGameTimePoint()
    {
        static_assert(!std::is_same<Clock, Clock>::value, "Missing specialization for GetGameTimePoint");
    }

    template<>
    TC_GAME_API std::chrono::system_clock::time_point GetGameTimePoint<std::chrono::system_clock>()
    {
        return GetGameTimeSystemPoint();
    }

    template<>
    TC_GAME_API std::chrono::steady_clock::time_point GetGameTimePoint<std::chrono::steady_clock>()
    {
        return GetGameTimeSteadyPoint();
    }

    uint32 GetUptime()
    {
        return uint32(GameTime - StartTime);
    }

    tm const* GetDateAndTime()
    {
        return &DateTime;
    }

    void UpdateGameTimers()
    {
        GameTime = time(nullptr);
        GameMSTime = getMSTime();
        GameTimeSystemPoint = std::chrono::system_clock::now();
        GameTimeSteadyPoint = std::chrono::steady_clock::now();
        localtime_r(&GameTime, &DateTime);
    }
}
