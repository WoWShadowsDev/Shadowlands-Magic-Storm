/*
 * This file is part of the KyrianCORE HolyDEEW Project. See AUTHORS file for Copyright information
 *
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

#ifndef __NPCHANDLER_H
#define __NPCHANDLER_H

struct NpcTextData
{
    float Probability;
    uint32 BroadcastTextID;
};

#define MAX_NPC_TEXT_OPTIONS 8

struct NpcText
{
    NpcTextData Data[MAX_NPC_TEXT_OPTIONS];
};

struct PageTextLocale
{
    std::vector<std::string> Text;
};

#endif
