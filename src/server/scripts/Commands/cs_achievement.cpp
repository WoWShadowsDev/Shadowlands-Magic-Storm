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
Name: achievement_commandscript
%Complete: 100
Comment: All achievement related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AchievementMgr.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "Language.h"
#include "Player.h"
#include "RBAC.h"

class achievement_commandscript : public CommandScript
{
public:
    achievement_commandscript() : CommandScript("achievement_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> achievementCommandTable =
        {
            { "add", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT_ADD, false, &HandleAchievementAddCommand, "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "achievement", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT,  false, nullptr, "", achievementCommandTable },
        };
        return commandTable;
    }

    static bool HandleAchievementAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 achievementId = atoi((char*)args);
        if (!achievementId)
        {
            if (char* id = handler->extractKeyFromLink((char*)args, "Hachievement"))
                achievementId = atoul(id);
            if (!achievementId)
                return false;
        }

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(achievementId))
            target->CompletedAchievement(achievementEntry);

        return true;
    }
};

void AddSC_achievement_commandscript()
{
    new achievement_commandscript();
}
