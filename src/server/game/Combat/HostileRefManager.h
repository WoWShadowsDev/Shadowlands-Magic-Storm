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

#ifndef _HOSTILEREFMANAGER
#define _HOSTILEREFMANAGER

#include "Common.h"
#include "RefManager.h"

class Unit;
class ThreatManager;
class HostileReference;
class SpellInfo;

//=================================================

class TC_GAME_API HostileRefManager : public RefManager<Unit, ThreatManager>
{
    public:
        explicit HostileRefManager(Unit* owner) : iOwner(owner) { }
        ~HostileRefManager();

        Unit* GetOwner() const { return iOwner; }

        // send threat to all my hateres for the victim
        // The victim is hated than by them as well
        // use for buffs and healing threat functionality
        void threatAssist(Unit* victim, float baseThreat, SpellInfo const* threatSpell = nullptr);

        void addTempThreat(float threat, bool apply);

        void addThreatPercent(int32 percent);

        // The references are not needed anymore
        // tell the source to remove them from the list and free the mem
        void deleteReferences();

        // Remove specific faction references
        void deleteReferencesForFaction(uint32 faction);

        // for combat bugs
        void deleteReferencesOutOfRange(float range);

        HostileReference* getFirst() { return ((HostileReference*) RefManager<Unit, ThreatManager>::getFirst()); }

        void updateThreatTables();

        void setOnlineOfflineState(bool isOnline);

        // set state for one reference, defined by Unit
        void setOnlineOfflineState(Unit* creature, bool isOnline);

        // delete one reference, defined by Unit
        void deleteReference(Unit* creature);

        void UpdateVisibility();

    private:
        Unit* iOwner;
};
//=================================================
#endif
