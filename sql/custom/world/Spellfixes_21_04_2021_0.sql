-- delete non existant spell entries according to startup errors

DELETE
FROM `spell_custom_attr`
WHERE `entry` IN (207194, 70324, 66765, 67331, 67333, 67097, 67098, 67099, 72447, 72448, 72449, 73797, 73798, 73799, 66809);

DELETE
FROM `spell_group`
WHERE `spell_id` IN (17629, 42735, 62380, 67016, 67017, 67018, 2380, 17629, 42735, 62380, 67016, 67017, 67018, 12292, 20784, 33127);

DELETE
FROM `spell_proc`
WHERE `SpellId` IN (20784, 33127);

-- delete several legacy tier set bonus spells from spell_proc since they are no longer used

DELETE
FROM `spell_proc`
WHERE `SpellId` IN (37603, 38394, 60170, 64752, 64824, 64914, 70664, 70727, 70854);

-- several spell_proc fixes according to startup errors

UPDATE `spell_proc` SET `SpellPhaseMask`='2' WHERE  `SpellId`=7434;
UPDATE `spell_proc` SET `SpellPhaseMask`='1' WHERE  `SpellId`=39958;
UPDATE `spell_proc` SET `SpellPhaseMask`='1' WHERE  `SpellId`=40438;
UPDATE `spell_proc` SET `SpellPhaseMask`='1' WHERE  `SpellId`=40478;
UPDATE `spell_proc` SET `SpellPhaseMask`='1' WHERE  `SpellId`=55380;
UPDATE `spell_proc` SET `SpellPhaseMask`='2' WHERE  `SpellId`=53651;
UPDATE `spell_proc` SET `SpellPhaseMask`='2' WHERE  `SpellId`=60487;
UPDATE `spell_proc` SET `SchoolMask`='64', `ProcFlags`='262144', `SpellPhaseMask`='0', `Chance`='25' WHERE  `SpellId`=45054;
UPDATE `spell_proc` SET `SchoolMask`='64', `ProcFlags`='262144', `SpellPhaseMask`='0', `Chance`='30' WHERE  `SpellId`=71606;
UPDATE `spell_proc` SET `SchoolMask`='64', `ProcFlags`='262144', `SpellPhaseMask`='0', `Chance`='30' WHERE  `SpellId`=71637;