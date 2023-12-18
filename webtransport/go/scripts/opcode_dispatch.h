

IN_C(OP_ZoneEntry, ClientZoneEntry_Struct);
IN_C(OP_SetServerFilter, SetServerFilter_Struct);
IN_Cz(OP_SendAATable);
IN_Cz(OP_SendTributes);
IN_Cz(OP_SendGuildTributes);
IN_Cz(OP_SendAAStats);
IN_Cz(OP_ReqClientSpawn);
IN_Cz(OP_ReqNewZone);
IN_Cz(OP_SendExpZonein);

IN_Cz(OP_ClientReady);
IN_C(OP_ClientError, ClientError_Struct);
IN_C(OP_ApproveZone, ApproveZone_Struct);
IN_C(OP_TGB, Int_Struct);

IN(OP_AckPacket, Int_Struct);
IN(OP_ClientUpdate, PlayerPositionUpdateClient_Struct);
IN(OP_AutoAttack, Int_Struct);
IN(OP_AutoAttack2, Int_Struct);
INv(OP_Consent, Consent_Struct);
INv(OP_ConsentDeny, Consent_Struct);
IN(OP_TargetMouse, ClientTarget_Struct);
IN(OP_TargetCommand, ClientTarget_Struct);
IN(OP_Shielding, Shielding_Struct);
INz(OP_Jump);	
IN(OP_AdventureInfoRequest, EntityId_Struct);
IN(OP_AdventureRequest, AdventureRequest_Struct);
IN(OP_LDoNButton, Bool_Struct);	
INz(OP_LeaveAdventure);
IN(OP_Consume, Consume_Struct);
IN(OP_AdventureMerchantRequest, AdventureMerchant_Struct);
IN(OP_AdventureMerchantPurchase, Adventure_Purchase_Struct);
IN(OP_ConsiderCorpse, Consider_Struct);
IN(OP_Consider, Consider_Struct);
INz(OP_Begging);	
INz(OP_TestBuff);
IN(OP_Surname, Surname_Struct);
INz(OP_YellForHelp);
IN(OP_Assist, EntityId_Struct);		
IN(OP_GMTraining, GMTrainee_Struct);
IN(OP_GMEndTraining, GMTrainEnd_Struct);
IN(OP_GMTrainSkill, GMSkillChange_Struct);
IN(OP_RequestDuel, Duel_Struct);
IN(OP_DuelDecline, DuelResponse_Struct);
IN(OP_DuelAccept, Duel_Struct);
IN(OP_SpawnAppearance, SpawnAppearance_Struct);
IN(OP_BazaarInspect, BazaarInspect_Struct);
IN(OP_Death, Death_Struct);
IN(OP_MoveCoin, MoveCoin_Struct);
IN(OP_ItemLinkClick, ItemViewRequest_Struct);
IN(OP_MoveItem, MoveItem_Struct);
INz(OP_Camp);	
INz(OP_Logout);
INz(OP_SenseHeading);	
INz(OP_FeignDeath);	
INz(OP_Sneak);		
INz(OP_Hide);		
INv(OP_ChannelMessage, ChannelMessage_Struct);
IN(OP_WearChange, WearChange_Struct);
IN(OP_DeleteSpawn, EntityId_Struct);	
IN(OP_SaveOnZoneReq, Save_Struct);		
IN(OP_Save, Save_Struct);
IN(OP_WhoAllRequest, Who_All_Struct);
IN(OP_GMZoneRequest, GMZoneRequest_Struct);
IN(OP_GMZoneRequest2, Int_Struct);
IN(OP_EndLootRequest, EntityId_Struct);	
IN(OP_LootRequest, EntityId_Struct);	
IN(OP_Dye, DyeStruct);
INz(OP_ConfirmDelete);	
IN(OP_LootItem, LootingItem_Struct);
INz(OP_GuildDelete);	
IN(OP_GuildPublicNote, GuildUpdate_PublicNote);
INz(OP_GetGuildsList);	
IN(OP_SetGuildMOTD, GuildMOTD_Struct);
IN(OP_SetRunMode, SetRunMode_Struct);
INz(OP_GuildPeace);		
INz(OP_GuildWar);		
IN(OP_GuildLeader, GuildMakeLeader);
IN(OP_GuildDemote, GuildDemoteStruct);
IN(OP_GuildInvite, GuildCommand_Struct);
IN(OP_GuildRemove, GuildCommand_Struct);
IN(OP_GuildInviteAccept, GuildInviteAccept_Struct);
IN(OP_ManaChange, ManaChange_Struct);	
IN(OP_MemorizeSpell, MemorizeSpell_Struct);
IN(OP_SwapSpell, SwapSpell_Struct);
IN(OP_CastSpell, CastSpell_Struct);
IN(OP_DeleteItem, DeleteItem_Struct);
IN(OP_CombatAbility, CombatAbility_Struct);
IN(OP_Taunt, ClientTarget_Struct);
INz(OP_InstillDoubt);
IN(OP_RezzAnswer, Resurrect_Struct);
IN(OP_GMSummon, GMSummon_Struct);
IN(OP_TradeBusy, TradeBusy_Struct);
IN(OP_TradeRequest, TradeRequest_Struct);
IN(OP_TradeRequestAck, TradeRequest_Struct);	
IN(OP_CancelTrade, CancelTrade_Struct);
IN(OP_TradeAcceptClick, TradeAccept_Struct);
IN(OP_BoardBoat, EntityId_Struct);		
INz(OP_LeaveBoat);		
IN(OP_RandomReq, RandomReq_Struct);
IN(OP_Buff, SpellBuffPacket_Struct);
IN(OP_GMHideMe, SpawnAppearance_Struct);
IN(OP_GMNameChange, GMName_Struct);
IN(OP_GMKill, GMKill_Struct);
IN(OP_GMLastName, GMLastName_Struct);
IN(OP_GMToggle, GMToggle_Struct);
IN(OP_LFGCommand, LFG_Struct);
IN(OP_GMGoto, GMSummon_Struct);
INv(OP_TraderShop, TraderClick_Struct);
IN(OP_ShopRequest, Merchant_Click_Struct);
IN(OP_Bazaar, BazaarSearch_Struct);
IN(OP_ShopPlayerBuy, Merchant_Sell_Struct);
IN(OP_ShopPlayerSell, Merchant_Purchase_Struct);
INz(OP_ShopEnd);		
IN(OP_CloseContainer, ClickObjectAction_Struct);
IN(OP_ClickObjectAction, ClickObjectAction_Struct);
IN(OP_ClickObject, ClickObject_Struct);
IN(OP_RecipesFavorite, TradeskillFavorites_Struct);
IN(OP_RecipesSearch, RecipesSearch_Struct);
IN(OP_RecipeDetails, Int_Struct);

IN(OP_RecipeAutoCombine, RecipeAutoCombine_Struct);
IN(OP_TradeSkillCombine, NewCombine_Struct);
IN(OP_ItemName, ItemNamePacket_Struct);
IN(OP_AugmentItem, AugmentItem_Struct);
IN(OP_ClickDoor, ClickDoor_Struct);
IN(OP_FaceChange, FaceChange_Struct);
IN(OP_GroupInvite, GroupInvite_Struct);
IN(OP_GroupInvite2, GroupInvite_Struct);	
IN(OP_GroupFollow, GroupGeneric_Struct);	
IN(OP_GroupFollow2, GroupGeneric_Struct);	
INz(OP_GroupAcknowledge);	
IN(OP_GroupCancelInvite, GroupGeneric_Struct);	
IN(OP_GroupDisband, GroupGeneric_Struct);
INz(OP_GroupDelete);	
IN(OP_GMEmoteZone, GMEmoteZone_Struct);
IN(OP_InspectRequest, Inspect_Struct);
IN(OP_InspectAnswer, Inspect_Struct);	
IN(OP_DeleteSpell, DeleteSpell_Struct);
IN(OP_PetitionBug, PetitionBug_Struct);
IN(OP_Bug, BugStruct);



IN(OP_Petition, String_Struct)
IN(OP_PetitionCheckIn, Petition_Struct);
IN(OP_PetitionResolve, PetitionUpdate_Struct);
IN(OP_PetitionDelete, PetitionUpdate_Struct);
IN(OP_PetitionUnCheckout, Int_Struct);
INz(OP_PetitionQue);
IN(OP_PDeletePetition, String_Struct);
IN(OP_PetitionCheckout, Int_Struct);
INz(OP_PetitionRefresh);

IN(OP_PetCommands, PetCommand_Struct);
IN(OP_ReadBook, BookRequest_Struct);
IN(OP_Emote, Emote_Struct);
IN(OP_GMDelCorpse, GMDelCorpse_Struct);
IN(OP_GMKick, GMKick_Struct);
INz(OP_GMServers);	
IN(OP_Illusion, Illusion_Struct);
IN(OP_GMBecomeNPC, BecomeNPC_Struct);
INz(OP_Fishing);	
INz(OP_Forage);		
INz(OP_Mend);		
IN(OP_EnvDamage, EnvDamage2_Struct);
IN(OP_Damage, CombatDamage_Struct);
IN(OP_AAAction, AA_Action);
IN(OP_TraderBuy, TraderBuy_Struct);
IN(OP_Trader, Trader_ShowItems_Struct);
IN(OP_GMFind, GMSummon_Struct);
IN(OP_PickPocket, PickPocket_Struct);
IN(OP_Bind_Wound, BindWound_Struct);
IN(OP_TrackTarget, TrackTarget_Struct);
INz(OP_Track);
INz(OP_TrackUnknown);
INz(OP_ReloadUI);
IN(OP_Split, Split_Struct);
INz(OP_SenseTraps);
INz(OP_DisarmTraps);
IN(OP_OpenTributeMaster, StartTribute_Struct);
IN(OP_OpenGuildTributeMaster, StartTribute_Struct);
IN(OP_TributeItem, TributeItem_Struct);
IN(OP_TributeMoney, TributeMoney_Struct);
IN(OP_SelectTribute, SelectTributeReq_Struct);
IN(OP_TributeUpdate, TributeInfo_Struct);
IN(OP_TributeToggle, uint32);
IN(OP_TributeNPC, uint32);
INz(OP_CrashDump);
IN(OP_ControlBoat, ControlBoat_Struct);
INz(OP_DumpName);
INz(OP_SafeFallSuccess);
INz(OP_Heartbeat);
INz(OP_SafePoint);
IN(OP_FindPersonRequest, FindPersonRequest_Struct);
IN(OP_LeadershipExpToggle, Int_Struct);
IN(OP_PurchaseLeadershipAA, Int_Struct);
IN(OP_BankerChange, BankerChange_Struct);
IN(OP_SetTitle, SetTitle_Struct);
INz(OP_RequestTitles);
IN(OP_ItemVerifyRequest, ItemVerifyRequest_Struct);



OUTz(OP_ClearObject);
OUTz(OP_FinishTrade);
OUTz(OP_GMEndTrainingResponse);
OUTz(OP_LootComplete);
OUTz(OP_WorldObjectsSent);
OUTz(OP_FinishWindow);
OUTz(OP_FinishWindow2);
OUTv(OP_ItemPacket, ItemPacket_Struct);
OUTv(OP_ColoredText, ColoredText_Struct);
OUTv(OP_ItemRecastDelay, ItemRecastDelay_Struct);
OUTv(OP_FormattedMessage, FormattedMessage_Struct);
OUTv(OP_GuildMemberList, uint32);
OUTv(OP_InterruptCast, InterruptCast_Struct);
OUTv(OP_ItemLinkResponse, ItemPacket_Struct);
OUTv(OP_ZoneSpawns, Spawn_Struct);
OUTv(OP_CompletedTasks, TaskHistory_Struct);
OUTv(OP_CharInventory, ItemPacket_Struct);
OUTv(OP_CustomTitles, Titles_Struct);
OUTv(OP_SpawnDoor, Door_Struct);
OUTv(OP_SendZonepoints, ZonePoints);
OUTv(OP_TributeInfo, TributeAbility_Struct);
OUTv(OP_GuildTributeInfo, GuildTributeAbility_Struct);
OUTv(OP_SendTitleList, TitleList_Struct);
OUT(OP_SendMaxCharacters, MaxCharacters_Struct);
OUT(OP_AAExpUpdate, AAExpUpdate_Struct);
OUT(OP_Action, Action_Struct);
OUT(OP_AdventureData, AdventureRequestResponse_Struct);
OUT(OP_AdventureFinish, AdventureFinish_Struct);
OUT(OP_AdventurePointsUpdate, AdventurePoints_Update_Struct);
OUT(OP_Animation, Animation_Struct);
OUT(OP_AnnoyingZoneUnknown, AnnoyingZoneUnknown_Struct);
OUT(OP_BankerChange, BankerChange_Struct);
OUT(OP_BecomeTrader, BecomeTrader_Struct);
OUT(OP_BeginCast, BeginCast_Struct);
OUT(OP_Charm, Charm_Struct);
OUT(OP_CameraEffect, Camera_Struct);
OUT(OP_ClickObjectAction, ClickObjectAction_Struct);
OUT(OP_ConsentResponse, ConsentResponse_Struct);
OUT(OP_EnduranceUpdate, EnduranceUpdate_Struct);
OUT(OP_ExpUpdate, ExpUpdate_Struct);
OUT(OP_GroundSpawn, Object_Struct);
OUT(OP_GroupUpdate, GroupJoin_Struct);	
OUT(OP_GuildMOTD, GuildMOTD_Struct);
OUT(OP_GuildManageAdd, GuildJoin_Struct);
OUT(OP_GuildManageRemove, GuildManageRemove_Struct);
OUT(OP_GuildManageStatus, GuildManageStatus_Struct);
OUT(OP_GuildMemberUpdate, GuildMemberUpdate_Struct);
OUT(OP_HPUpdate, SpawnHPUpdate_Struct);
OUT(OP_IncreaseStats, IncreaseStat_Struct);
OUT(OP_ItemVerifyReply, ItemVerifyReply_Struct);
OUT(OP_LFGAppearance, LFG_Appearance_Struct);
OUT(OP_LeadershipExpUpdate, LeadershipExpUpdate_Struct);
OUT(OP_LevelAppearance, LevelAppearance_Struct);
OUT(OP_LevelUpdate, LevelUpdate_Struct);
OUT(OP_ManaUpdate, ManaUpdate_Struct);
OUT(OP_MobEnduranceUpdate, MobEnduranceUpdate_Struct);
OUT(OP_MobHealth, MobHealth_Struct);
OUT(OP_MobManaUpdate, MobManaUpdate_Struct);
OUT(OP_MobRename, MobRename_Struct);
OUT(OP_MoneyOnCorpse, moneyOnCorpseStruct);
OUT(OP_MoneyUpdate, MoneyUpdate_Struct);
OUT(OP_MoveDoor, MoveDoor_Struct);
OUT(OP_NewSpawn, NewSpawn_Struct);
OUT(OP_NewZone, NewZone_Struct);
OUT(OP_PetitionCheckout, Petition_Struct);
OUT(OP_PetitionUpdate, PetitionUpdate_Struct);
OUT(OP_PlayerProfile, PlayerProfile_Struct);
OUT(OP_RaidUpdate, ZoneInSendName_Struct);
OUT(OP_RandomReply, RandomReply_Struct);
OUT(OP_RecipeReply, RecipeReply_Struct);
OUT(OP_RequestClientZoneChange, RequestClientZoneChange_Struct);
OUT(OP_RespondAA, AATable_Struct);
OUT(OP_RezzRequest, Resurrect_Struct);
OUT(OP_SetTitleReply, SetTitleReply_Struct);
OUT(OP_ShopDelItem, Merchant_DelItem_Struct);
OUT(OP_SimpleMessage, SimpleMessage_Struct);
OUT(OP_SkillUpdate, SkillUpdate_Struct);
OUT(OP_SomeItemPacketMaybe, Arrow_Struct);
OUT(OP_SpellEffect, SpellEffect_Struct);
OUT(OP_Stamina, Stamina_Struct);
OUT(OP_Stun, Stun_Struct);
OUT(OP_TargetReject, TargetReject_Struct);
OUT(OP_TimeOfDay, TimeOfDay_Struct);
OUT(OP_Track, Track_Struct);
OUT(OP_TradeCoins, TradeCoin_Struct);
OUT(OP_TradeMoneyUpdate, TradeMoneyUpdate_Struct);
OUT(OP_TraderDelItem, TraderDelItem_Struct);
OUT(OP_TraderItemUpdate, TraderItemUpdate_Struct);
OUT(OP_TributeTimer, Bool_Struct);
OUT(OP_UpdateLeadershipAA, UpdateLeadershipAA_Struct);
OUT(OP_Weather, Weather_Struct);
OUT(OP_ZoneChange, ZoneChange_Struct);
OUT(OP_ZoneInUnknown, ZoneInUnknown_Struct);
