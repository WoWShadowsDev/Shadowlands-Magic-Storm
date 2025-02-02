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

#ifndef SHADOW_LABYRINTH_H_
#define SHADOW_LABYRINTH_H_

#include "CreatureAIImpl.h"
#include "ObjectGuid.h"

#define SLScriptName "instance_shadow_labyrinth"
#define DataHeader "SL"

uint32 const EncounterCount = 4;

enum SLDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_AMBASSADOR_HELLMAW             = 0,
    DATA_BLACKHEART_THE_INCITER         = 1,
    DATA_GRANDMASTER_VORPIL             = 2,
    DATA_MURMUR                         = 3,

    // Additional Data
    DATA_FEL_OVERSEER                   = 4
};

enum SLCreatureIds
{
    NPC_AMBASSADOR_HELLMAW              = 18731,
    NPC_BLACKHEART                      = 18667,
    NPC_BLACKHEART_DUMMY1               = 19300,
    NPC_BLACKHEART_DUMMY2               = 19301,
    NPC_BLACKHEART_DUMMY3               = 19302,
    NPC_BLACKHEART_DUMMY4               = 19303,
    NPC_BLACKHEART_DUMMY5               = 19304,
    NPC_GRANDMASTER_VORPIL              = 18732,
    NPC_FEL_OVERSEER                    = 18796
};

enum SLGameObjectIds
{
    GO_REFECTORY_DOOR                   = 183296, // door opened when blackheart the inciter dies
    GO_SCREAMING_HALL_DOOR              = 183295  // door opened when grandmaster vorpil dies
};

enum SLMisc
{
    ACTION_AMBASSADOR_HELLMAW_INTRO     = 1,
    ACTION_AMBASSADOR_HELLMAW_BANISH    = 2,
};

GuidUnorderedSet const* GetBlackheartDummies(InstanceScript const* s);

template <class AI, class T>
inline AI* GetShadowLabyrinthAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SLScriptName);
}

#endif // SHADOW_LABYRINTH_H_
