UPDATE creature_template SET faction=14, minlevel= 50, maxlevel= 60 WHERE entry=166714;
UPDATE creature_template SET npcflag= 2 WHERE entry=170624;

REPLACE  INTO `creature_template_scaling`(`Entry`,`DifficultyID`,`LevelScalingMin`,`LevelScalingMax`,`LevelScalingDeltaMin`,`LevelScalingDeltaMax`,`ContentTuningID`,`VerifiedBuild`) VALUES 
(170624,0,50,60,0,0,0,36949),
(166714,0,50,60,0,0,0,36949);

REPLACE INTO creature_queststarter (id, quest) VALUES
(170624,59753);

REPLACE INTO creature_questender (id, quest) VALUES
(167187,59753),
(165918,59753);

REPLACE INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, event_param_string, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, COMMENT) VALUES
('165918','0','1','0','64','0','100','0','0','0','0','0','0','','33','165918','0','0','0','0','0','7','0','0','0','0','0','0','0','Primera mision SL, NPCs');


REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
('60000000000025200','170624','2222','0','0','0','0','0','0','-1','0','0','4303.47','7716.67','4928.42','2.88816','120','0','0','27','0','0','0','0','0','0','0','','0'),
('60000000000025201','166714','2222','0','0','0','0','0','0','-1','0','0','4461.73','7870.01','4904.57','4.59326','120','0','0','136','0','0','0','0','0','0','0','','0'),
('60000000000025202','166605','2222','0','0','0','0','0','0','-1','0','0','4470.11','7880.65','4904.57','4.38561','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025203','166605','2222','0','0','0','0','0','0','-1','0','0','4452.96','7880.84','4904.57','5.26126','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025205','166605','2222','0','0','0','0','0','0','-1','0','0','4486.47','7824.81','4903.12','0.530208','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025206','166605','2222','0','0','0','0','0','0','-1','0','0','4498.89','7744.29','4902.29','5.81986','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025207','166605','2222','0','0','0','0','0','0','-1','0','0','4494.43','7734.78','4902.56','5.14049','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025208','166605','2222','0','0','0','0','0','0','-1','0','0','4391.69','7819.03','4928.45','4.62527','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025209','166605','2222','0','0','0','0','0','0','-1','0','0','4401.56','7820.31','4928.45','5.66199','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025210','166605','2222','0','0','0','0','0','0','-1','0','0','4327.28','7963.46','4963.85','4.91272','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025211','166605','2222','0','0','0','0','0','0','-1','0','0','4321.4','7928.33','4953.07','2.12139','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025212','166605','2222','0','0','0','0','0','0','-1','0','0','4424.76','7811.86','4913.62','3.43065','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025213','165860','2222','0','0','0','0','0','0','-1','0','0','4389.08','7740.17','4915.61','3.4605','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025214','165860','2222','0','0','0','0','0','0','-1','0','0','4419.03','7748.19','4915.61','3.38196','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025215','165860','2222','0','0','0','0','0','0','-1','0','0','4491.33','7741.83','4902.26','2.57301','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025216','165860','2222','0','0','0','0','0','0','-1','0','0','4438.8','7812.9','4907.2','5.89294','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025217','165860','2222','0','0','0','0','0','0','-1','0','0','4482.17','7830.63','4903.98','3.90981','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025218','166605','2222','0','0','0','0','0','0','-1','0','0','4499.77','7805.91','4900.31','0.355894','120','0','0','4579','0','0','0','0','0','0','0','','0'),
('60000000000025219','165860','2222','0','0','0','0','0','0','-1','0','0','4490.07','7808.98','4901.17','4.54756','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025220','165860','2222','0','0','0','0','0','0','-1','0','0','4504.7','7766.92','4899.28','3.41039','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025221','165860','2222','0','0','0','0','0','0','-1','0','0','4467.49','7765.08','4904.77','3.70888','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025222','165860','2222','0','0','0','0','0','0','-1','0','0','4468.6','7792.52','4902.27','4.63172','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025223','165860','2222','0','0','0','0','0','0','-1','0','0','4258.83','7683.62','4927.46','0.812399','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025224','165974','2222','0','0','0','0','0','0','-1','0','0','4493.42','7743.95','4902.2','2.61936','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025225','165974','2222','0','0','0','0','0','0','-1','0','0','4441.14','7815.51','4907.32','5.43893','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025226','165974','2222','0','0','0','0','0','0','-1','0','0','4504.92','7761.55','4899.15','2.87432','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025227','165974','2222','0','0','0','0','0','0','-1','0','0','4469.17','7871.02','4904.57','4.60063','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025228','165974','2222','0','0','0','0','0','0','-1','0','0','4454.83','7872.84','4904.57','4.66739','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025229','165860','2222','0','0','0','0','0','0','-1','0','0','4455.61','7830.98','4906.48','5.62951','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025230','165974','2222','0','0','0','0','0','0','-1','0','0','4397.07','7828.05','4928.45','1.719','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025231','165860','2222','0','0','0','0','0','0','-1','0','0','4393.6','7827.53','4928.45','1.719','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025232','165860','2222','0','0','0','0','0','0','-1','0','0','4379.41','7878.23','4931.07','5.17004','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025233','165860','2222','0','0','0','0','0','0','-1','0','0','4327.19','7923.13','4952.59','5.35193','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025234','165860','2222','0','0','0','0','0','0','-1','0','0','4332.17','7968.33','4963.32','0.985624','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025235','165860','2222','0','0','0','0','0','0','-1','0','0','4394.83','7904.94','4936.67','4.64952','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025236','165860','2222','0','0','0','0','0','0','-1','0','0','4379.38','7956.78','4951.23','4.96368','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025237','165860','2222','0','0','0','0','0','0','-1','0','0','4342.07','8020.33','4962.29','4.4139','120','0','0','11791','0','0','0','0','0','0','0','','0'),
('60000000000025238','165918','2222','0','0','0','0','0','0','-1','0','1','4564.39','7788.11','4879.42','6.19064','120','0','0','294789','0','0','0','0','0','0','0','','0');