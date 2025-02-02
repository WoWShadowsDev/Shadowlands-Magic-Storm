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

#include "AddonPackets.h"
#include "ByteBuffer.h"

ByteBuffer& WorldPackets::Addon::operator>>(ByteBuffer& data, AddOnInfo& addonInfo)
{
    data.ResetBitPos();

    uint32 nameLength = data.ReadBits(10);
    uint32 versionLength = data.ReadBits(10);
    addonInfo.Loaded = data.ReadBit();
    addonInfo.Disabled = data.ReadBit();
    if (nameLength > 1)
    {
        addonInfo.Name = data.ReadString(nameLength - 1);
        data.read_skip<uint8>(); // null terminator
    }
    if (versionLength > 1)
    {
        addonInfo.Version = data.ReadString(versionLength - 1);
        data.read_skip<uint8>(); // null terminator
    }

    return data;
}
