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

/* ScriptData
SDName: Boss_Garr
SD%Complete: 50
SDComment: Adds NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    // Garr
    SPELL_ANTIMAGIC_PULSE   = 19492,
    SPELL_MAGMA_SHACKLES    = 19496,
    SPELL_ENRAGE            = 19516,

    // Adds
    SPELL_ERUPTION          = 19497,
    SPELL_IMMOLATE          = 20294,
};

enum Events
{
    EVENT_ANTIMAGIC_PULSE    = 1,
    EVENT_MAGMA_SHACKLES     = 2,
};

class boss_garr : public CreatureScript
{
    public:
        boss_garr() : CreatureScript("boss_garr") { }

        struct boss_garrAI : public BossAI
        {
            boss_garrAI(Creature* creature) : BossAI(creature, BOSS_GARR)
            {
            }

            void JustEngagedWith(Unit* victim) override
            {
                BossAI::JustEngagedWith(victim);
                events.ScheduleEvent(EVENT_ANTIMAGIC_PULSE, 25000);
                events.ScheduleEvent(EVENT_MAGMA_SHACKLES, 15000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ANTIMAGIC_PULSE:
                            DoCast(me, SPELL_ANTIMAGIC_PULSE);
                            events.ScheduleEvent(EVENT_ANTIMAGIC_PULSE, urand(10000, 15000));
                            break;
                        case EVENT_MAGMA_SHACKLES:
                            DoCast(me, SPELL_MAGMA_SHACKLES);
                            events.ScheduleEvent(EVENT_MAGMA_SHACKLES, urand(8000, 12000));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetMoltenCoreAI<boss_garrAI>(creature);
        }
};

class npc_firesworn : public CreatureScript
{
    public:
        npc_firesworn() : CreatureScript("npc_firesworn") { }

        struct npc_fireswornAI : public ScriptedAI
        {
            npc_fireswornAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                immolateTimer = 4000;                              //These times are probably wrong
            }

            uint32 immolateTimer;

            void Reset() override
            {
                Initialize();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                uint32 const health10pct = me->CountPctFromMaxHealth(10);
                uint32 health = me->GetHealth();
                if (int32(health) - int32(damage) < int32(health10pct))
                {
                    damage = 0;
                    DoCastVictim(SPELL_ERUPTION);
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (immolateTimer <= diff)
                {
                     if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_IMMOLATE);
                    immolateTimer = urand(5000, 10000);
                }
                else
                    immolateTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetMoltenCoreAI<npc_fireswornAI>(creature);
        }
};

void AddSC_boss_garr()
{
    new boss_garr();
    new npc_firesworn();
}
