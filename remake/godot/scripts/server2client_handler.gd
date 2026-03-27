extends Node
class_name Server2ClientHandler
# Signal handlers for Server2Client_Proxy
# This file implements all signal handlers from Server2Client_Proxy class

var proxy: Server2Client_Proxy
var server_agent: ServerAgent

func set_proxy(p: Server2Client_Proxy, sa: ServerAgent):
	proxy = p
	server_agent = sa
	_connect_all_signals()

func _connect_all_signals():
	if not proxy:
		return

	proxy.pong.connect(pong)
	proxy.errorno.connect(errorno)
	proxy.teamerrorno.connect(teamerrorno)
	proxy.reconnection.connect(reconnection)
	proxy.sessionfailed.connect(sessionfailed)
	proxy.loginok.connect(loginok)
	proxy.logoutOk.connect(logoutOk)
	proxy.createPlayerOk.connect(createPlayerOk)
	proxy.deletePlayerOk.connect(deletePlayerOk)
	proxy.enterGameOk.connect(enterGameOk)
	proxy.initBabies.connect(initBabies)
	proxy.initEmployees.connect(initEmployees)
	proxy.initEmpBattleGroup.connect(initEmpBattleGroup)
	proxy.initNpc.connect(initNpc)
	proxy.initAchievement.connect(initAchievement)
	proxy.initGather.connect(initGather)
	proxy.initcompound.connect(initcompound)
	proxy.addBaby.connect(addBaby)
	proxy.refreshBaby.connect(refreshBaby)
	proxy.delBabyOK.connect(delBabyOK)
	proxy.changeBabyNameOK.connect(changeBabyNameOK)
	proxy.remouldBabyOK.connect(remouldBabyOK)
	proxy.intensifyBabyOK.connect(intensifyBabyOK)
	proxy.learnSkillOk.connect(learnSkillOk)
	proxy.forgetSkillOk.connect(forgetSkillOk)
	proxy.addSkillExp.connect(addSkillExp)
	proxy.babyLearnSkillOK.connect(babyLearnSkillOK)
	proxy.skillLevelUp.connect(skillLevelUp)
	proxy.joinScene.connect(joinScene)
	proxy.joinCopySceneOK.connect(joinCopySceneOK)
	proxy.initCopyNums.connect(initCopyNums)
	proxy.addToScene.connect(addToScene)
	proxy.delFormScene.connect(delFormScene)
	proxy.move2.connect(move2)
	proxy.cantMove.connect(cantMove)
	proxy.querySimplePlayerInstOk.connect(querySimplePlayerInstOk)
	proxy.transfor2.connect(transfor2)
	proxy.openScene.connect(openScene)
	proxy.autoBattleResult.connect(autoBattleResult)
	proxy.talked2Npc.connect(talked2Npc)
	proxy.talked2Player.connect(talked2Player)
	proxy.useItemOk.connect(useItemOk)
	proxy.syncBattleStatus.connect(syncBattleStatus)
	proxy.enterBattleOk.connect(enterBattleOk)
	proxy.exitBattleOk.connect(exitBattleOk)
	proxy.syncOrderOk.connect(syncOrderOk)
	proxy.syncOrderOkEX.connect(syncOrderOkEX)
	proxy.syncOneTurnAction.connect(syncOneTurnAction)
	proxy.syncProperties.connect(syncProperties)
	proxy.receiveChat.connect(receiveChat)
	proxy.requestAudioOk.connect(requestAudioOk)
	proxy.publishItemInstRes.connect(publishItemInstRes)
	proxy.queryItemInstRes.connect(queryItemInstRes)
	proxy.publishBabyInstRes.connect(publishBabyInstRes)
	proxy.queryBabyInstRes.connect(queryBabyInstRes)
	proxy.setNoTalkTime.connect(setNoTalkTime)
	proxy.addNpc.connect(addNpc)
	proxy.delNpc.connect(delNpc)
	proxy.setTeamLeader.connect(setTeamLeader)
	proxy.initBag.connect(initBag)
	proxy.addBagItem.connect(addBagItem)
	proxy.delBagItem.connect(delBagItem)
	proxy.updateBagItem.connect(updateBagItem)
	proxy.depositItemOK.connect(depositItemOK)
	proxy.getoutItemOK.connect(getoutItemOK)
	proxy.depositBabyOK.connect(depositBabyOK)
	proxy.getoutBabyOK.connect(getoutBabyOK)
	proxy.sortItemStorageOK.connect(sortItemStorageOK)
	proxy.sortBabyStorageOK.connect(sortBabyStorageOK)
	proxy.initItemStorage.connect(initItemStorage)
	proxy.initBabyStorage.connect(initBabyStorage)
	proxy.openStorageGrid.connect(openStorageGrid)
	proxy.delStorageBabyOK.connect(delStorageBabyOK)
	proxy.initPlayerEquips.connect(initPlayerEquips)
	proxy.wearEquipmentOk.connect(wearEquipmentOk)
	proxy.scenePlayerWearEquipment.connect(scenePlayerWearEquipment)
	proxy.delEquipmentOk.connect(delEquipmentOk)
	proxy.scenePlayerDoffEquipment.connect(scenePlayerDoffEquipment)
	proxy.sortBagItemOk.connect(sortBagItemOk)
	proxy.jointLobbyOk.connect(jointLobbyOk)
	proxy.exitLobbyOk.connect(exitLobbyOk)
	proxy.syncDelLobbyTeam.connect(syncDelLobbyTeam)
	proxy.syncUpdateLobbyTeam.connect(syncUpdateLobbyTeam)
	proxy.syncAddLobbyTeam.connect(syncAddLobbyTeam)
	proxy.createTeamOk.connect(createTeamOk)
	proxy.changeTeamOk.connect(changeTeamOk)
	proxy.joinTeamOk.connect(joinTeamOk)
	proxy.addTeamMember.connect(addTeamMember)
	proxy.delTeamMember.connect(delTeamMember)
	proxy.changeTeamLeaderOk.connect(changeTeamLeaderOk)
	proxy.exitTeamOk.connect(exitTeamOk)
	proxy.updateTeam.connect(updateTeam)
	proxy.joinTeamRoomOK.connect(joinTeamRoomOK)
	proxy.inviteJoinTeam.connect(inviteJoinTeam)
	proxy.syncTeamDirtyProp.connect(syncTeamDirtyProp)
	proxy.leaveTeamOk.connect(leaveTeamOk)
	proxy.backTeamOK.connect(backTeamOK)
	proxy.teamCallMemberBack.connect(teamCallMemberBack)
	proxy.refuseBackTeamOk.connect(refuseBackTeamOk)
	proxy.requestJoinTeamTranspond.connect(requestJoinTeamTranspond)
	proxy.drawLotteryBoxRep.connect(drawLotteryBoxRep)
	proxy.addEmployee.connect(addEmployee)
	proxy.battleEmployee.connect(battleEmployee)
	proxy.changeEmpBattleGroupOK.connect(changeEmpBattleGroupOK)
	proxy.evolveOK.connect(evolveOK)
	proxy.upStarOK.connect(upStarOK)
	proxy.delEmployeeOK.connect(delEmployeeOK)
	proxy.sycnEmployeeSoul.connect(sycnEmployeeSoul)
	proxy.initQuest.connect(initQuest)
	proxy.acceptQuestOk.connect(acceptQuestOk)
	proxy.submitQuestOk.connect(submitQuestOk)
	proxy.giveupQuestOk.connect(giveupQuestOk)
	proxy.updateQuestInst.connect(updateQuestInst)
	proxy.requestContactInfoOk.connect(requestContactInfoOk)
	proxy.addFriendOK.connect(addFriendOK)
	proxy.delFriendOK.connect(delFriendOK)
	proxy.addBlacklistOK.connect(addBlacklistOK)
	proxy.delBlacklistOK.connect(delBlacklistOK)
	proxy.findFriendFail.connect(findFriendFail)
	proxy.referrFriendOK.connect(referrFriendOK)
	proxy.requestFriendListOK.connect(requestFriendListOK)
	proxy.lotteryOk.connect(lotteryOk)
	proxy.openGatherOK.connect(openGatherOK)
	proxy.miningOk.connect(miningOk)
	proxy.openCompound.connect(openCompound)
	proxy.compoundItemOk.connect(compoundItemOk)
	proxy.openBagGridOk.connect(openBagGridOk)
	proxy.requestChallengeOK.connect(requestChallengeOK)
	proxy.requestMySelfJJCDataOK.connect(requestMySelfJJCDataOK)
	proxy.requestRivalOK.connect(requestRivalOK)
	proxy.rivalTimeOK.connect(rivalTimeOK)
	proxy.checkMsgOK.connect(checkMsgOK)
	proxy.requestMyAllbattleMsgOK.connect(requestMyAllbattleMsgOK)
	proxy.myBattleMsgOK.connect(myBattleMsgOK)
	proxy.requestJJCRankOK.connect(requestJJCRankOK)
	proxy.requestLevelRankOK.connect(requestLevelRankOK)
	proxy.requestBabyRankOK.connect(requestBabyRankOK)
	proxy.requestEmpRankOK.connect(requestEmpRankOK)
	proxy.requestPlayerFFRankOK.connect(requestPlayerFFRankOK)
	proxy.queryOnlinePlayerOK.connect(queryOnlinePlayerOK)
	proxy.queryPlayerOK.connect(queryPlayerOK)
	proxy.queryBabyOK.connect(queryBabyOK)
	proxy.queryEmployeeOK.connect(queryEmployeeOK)
	proxy.initGuide.connect(initGuide)
	proxy.buyShopItemOk.connect(buyShopItemOk)
	proxy.addPlayerTitle.connect(addPlayerTitle)
	proxy.delPlayerTitle.connect(delPlayerTitle)
	proxy.requestOpenBuyBox.connect(requestOpenBuyBox)
	proxy.requestGreenBoxTimeOk.connect(requestGreenBoxTimeOk)
	proxy.requestBlueBoxTimeOk.connect(requestBlueBoxTimeOk)
	proxy.updateAchievementinfo.connect(updateAchievementinfo)
	proxy.syncOpenSystemFlag.connect(syncOpenSystemFlag)
	proxy.requestActivityRewardOK.connect(requestActivityRewardOK)
	proxy.syncActivity.connect(syncActivity)
	proxy.updateActivityStatus.connect(updateActivityStatus)
	proxy.updateActivityCounter.connect(updateActivityCounter)
	proxy.syncExam.connect(syncExam)
	proxy.syncExamAnswer.connect(syncExamAnswer)
	proxy.petActivityNoNum.connect(petActivityNoNum)
	proxy.syncHundredInfo.connect(syncHundredInfo)
	proxy.initSignUp.connect(initSignUp)
	proxy.signUp.connect(signUp)
	proxy.requestSignupRewardOk7.connect(requestSignupRewardOk7)
	proxy.requestSignupRewardOk14.connect(requestSignupRewardOk14)
	proxy.requestSignupRewardOk28.connect(requestSignupRewardOk28)
	proxy.sycnDoubleExpTime.connect(sycnDoubleExpTime)
	proxy.sycnStates.connect(sycnStates)
	proxy.requestpvprankOK.connect(requestpvprankOK)
	proxy.syncMyJJCTeamMember.connect(syncMyJJCTeamMember)
	proxy.startMatchingOK.connect(startMatchingOK)
	proxy.stopMatchingOK.connect(stopMatchingOK)
	proxy.updatePvpJJCinfo.connect(updatePvpJJCinfo)
	proxy.exitPvpJJCOk.connect(exitPvpJJCOk)
	proxy.syncEnemyPvpJJCPlayerInfo.connect(syncEnemyPvpJJCPlayerInfo)
	proxy.syncEnemyPvpJJCTeamInfo.connect(syncEnemyPvpJJCTeamInfo)
	proxy.openWarriorchooseUI.connect(openWarriorchooseUI)
	proxy.warriorStartOK.connect(warriorStartOK)
	proxy.warriorStopOK.connect(warriorStopOK)
	proxy.syncWarriorEnemyTeamInfo.connect(syncWarriorEnemyTeamInfo)
	proxy.appendMail.connect(appendMail)
	proxy.delMail.connect(delMail)
	proxy.updateMailOk.connect(updateMailOk)
	proxy.boardcastNotice.connect(boardcastNotice)
	proxy.createGuildOK.connect(createGuildOK)
	proxy.delGuildOK.connect(delGuildOK)
	proxy.leaveGuildOk.connect(leaveGuildOk)
	proxy.initGuildData.connect(initGuildData)
	proxy.initGuildMemberList.connect(initGuildMemberList)
	proxy.modifyGuildMemberList.connect(modifyGuildMemberList)
	proxy.modifyGuildList.connect(modifyGuildList)
	proxy.queryGuildListResult.connect(queryGuildListResult)
	proxy.inviteGuild.connect(inviteGuild)
	proxy.updateGuildShopItems.connect(updateGuildShopItems)
	proxy.updateGuildBuilding.connect(updateGuildBuilding)
	proxy.updateGuildMyMember.connect(updateGuildMyMember)
	proxy.levelupGuildSkillOk.connect(levelupGuildSkillOk)
	proxy.presentGuildItemOk.connect(presentGuildItemOk)
	proxy.progenitusAddExpOk.connect(progenitusAddExpOk)
	proxy.setProgenitusPositionOk.connect(setProgenitusPositionOk)
	proxy.updateGuildFundz.connect(updateGuildFundz)
	proxy.updateGuildMemberContribution.connect(updateGuildMemberContribution)
	proxy.openGuildBattle.connect(openGuildBattle)
	proxy.startGuildBattle.connect(startGuildBattle)
	proxy.closeGuildBattle.connect(closeGuildBattle)
	proxy.syncGuildBattleWinCount.connect(syncGuildBattleWinCount)
	proxy.initMySelling.connect(initMySelling)
	proxy.initMySelled.connect(initMySelled)
	proxy.fetchSellingOk.connect(fetchSellingOk)
	proxy.fetchSellingOk2.connect(fetchSellingOk2)
	proxy.sellingOk.connect(sellingOk)
	proxy.selledOk.connect(selledOk)
	proxy.unsellingOk.connect(unsellingOk)
	proxy.redemptionSpreeOk.connect(redemptionSpreeOk)
	proxy.insertState.connect(insertState)
	proxy.updattState.connect(updattState)
	proxy.removeState.connect(removeState)
	proxy.requestFixItemOk.connect(requestFixItemOk)
	proxy.makeDebirsItemOK.connect(makeDebirsItemOK)
	proxy.updateMagicItem.connect(updateMagicItem)
	proxy.changeMagicJobOk.connect(changeMagicJobOk)
	proxy.magicItemTupoOk.connect(magicItemTupoOk)
	proxy.zhuanpanOK.connect(zhuanpanOK)
	proxy.updateZhuanpanNotice.connect(updateZhuanpanNotice)
	proxy.sycnZhuanpanData.connect(sycnZhuanpanData)
	proxy.copynonum.connect(copynonum)

func pong():
	pass

func errorno(e: int) -> bool:
	print("errorno: ", e)
	return true

func teamerrorno(name: String, e: int) -> bool:
	print("teamerrorno: ", name, ", ", e)
	return true

func reconnection(recInfo: COM_ReconnectInfo):
	print("reconnection(recInfo: COM_ReconnectInfo)")
	PlayerSystem.init_session(recInfo.sessionKey_, recInfo.roles_)
	PlayerSystem.set_current_player(recInfo.playerInst_)

func sessionfailed():
	print("sessionfailed()")
	pass

func loginok(sessionkey: String, players: Array[COM_SimpleInformation]) -> bool:
	print("loginok: ", sessionkey)
	PlayerSystem.init_session(sessionkey, players)

	# 根据角色数量决定跳转
	if len(players) == 0:
		# 没有角色，跳转到创建角色界面（3D 版本）
		Global.change_scene("res://assets/ui/create_player_3d.tscn")
	else:
		# 有角色，跳转到角色选择界面
		Global.change_scene("res://assets/ui/player_select.tscn")
	return true

func logoutOk():
	print("logoutOk()")
	pass

func createPlayerOk(player: COM_SimpleInformation) -> bool:
	print("createPlayerOk: ", player.instId_)
	PlayerSystem.add_player(player)

	# 创建成功后直接进入游戏
	server_agent.get_server_stub().enterGame(player.instId_)
	return true

func deletePlayerOk(name: String):
	print("deletePlayerOk: ", name)
	PlayerSystem.remove_player(name)

	# 刷新角色选择界面
	var current_scene = get_tree().current_scene
	if current_scene != null and current_scene.has_method("refresh_after_delete"):
		current_scene.refresh_after_delete()

func enterGameOk(inst: COM_PlayerInst) -> bool:
	print("enterGameOk")
	PlayerSystem.set_current_player(inst)
	print("player name ", inst.instName_)

	# 进入主游戏界面
	Global.change_scene("res://assets/ui/main_game.tscn")
	return true

func initBabies(insts: Array[COM_BabyInst]):
	print("initBabies: ", insts.size())
	BabySystem.init_babies(insts)

func initEmployees(insts: Array[COM_EmployeeInst], isFlag: bool):
	print("initEmployees: ", insts.size(), ", isFlag: ", isFlag)
	EmployeeSystem.init_employees(insts, isFlag)

func initEmpBattleGroup(bep: COM_BattleEmp):
	print("initEmpBattleGroup")
	EmployeeSystem.init_battle_group(bep)

func initNpc(npcList: Array):
	print("initNpc: ", npcList.size())
	Player.npc_list = npcList

func initAchievement(actlist: Array[COM_Achievement]):
	print("initAchievement: ", actlist.size())
	Player.achievements = actlist

func initGather(allnum: int, gathers: Array[COM_Gather]):
	print("initGather: allnum=", allnum)
	Player.gathers = gathers

func initcompound(compounds: Array):
	print("initcompound: ", compounds.size())
	Player.compounds = compounds

func addBaby(inst: COM_BabyInst):
	print("addBaby: ", inst.instId_)
	BabySystem.add_baby(inst)

func refreshBaby(inst: COM_BabyInst):
	print("refreshBaby: ", inst.instId_)
	BabySystem.update_baby(inst)

func delBabyOK(babyInstId: int):
	print("delBabyOK: ", babyInstId)
	BabySystem.remove_baby(babyInstId)

func changeBabyNameOK(babyId: int, name: String):
	print("changeBabyNameOK: ", babyId, ", ", name)
	BabySystem.change_name(babyId, name)

func remouldBabyOK(instid: int):
	print("remouldBabyOK: ", instid)
	BabySystem.remold(instid)

func intensifyBabyOK(babyid: int, intensifyLevel: int):
	print("intensifyBabyOK: ", babyid, ", level=", intensifyLevel)
	BabySystem.intensify(babyid, intensifyLevel)

func learnSkillOk(inst: COM_Skill):
	print("learnSkillOk: ", inst.skId_)
	pass

func forgetSkillOk(skid: int):
	print("forgetSkillOk: ", skid)
	pass

func addSkillExp(skid: int, uExp: int, flag: int):
	print("addSkillExp: ", skid, ", exp=", uExp)
	pass

func babyLearnSkillOK(instId: int, newSkId: int):
	print("babyLearnSkillOK: ", instId, ", skill=", newSkId)
	pass

func skillLevelUp(instId: int, inst: COM_Skill):
	print("skillLevelUp: ", instId)
	pass

func joinScene(info: COM_SceneInfo):
	print("joinScene: ", info.sceneId_)
	pass

func joinCopySceneOK(secneid: int):
	print("joinCopySceneOK: ", secneid)
	pass

func initCopyNums():
	print("initCopyNums()")
	pass

func addToScene(inst: COM_ScenePlayerInformation):
	print("addToScene: ", inst.instId_)
	pass

func delFormScene(instId: int):
	print("delFormScene: ", instId)
	pass

func move2(instId: int, pos: COM_FPosition):
	pass

func cantMove():
	print("cantMove()")
	pass

func querySimplePlayerInstOk(player: COM_SimplePlayerInst):
	print("querySimplePlayerInstOk: ", player.instName_)
	pass

func transfor2(instId: int, pos: COM_FPosition):
	pass

func openScene(sceneId: int):
	print("openScene: ", sceneId)
	pass

func autoBattleResult(isOk: bool):
	print("autoBattleResult: ", isOk)
	pass

func talked2Npc(npcId: int):
	print("talked2Npc: ", npcId)
	pass

func talked2Player(playerId: int):
	print("talked2Player: ", playerId)
	pass

func useItemOk(itemId: int, stack: int):
	print("useItemOk: ", itemId, ", stack=", stack)
	pass

func syncBattleStatus(playerId: int, inBattle: bool):
	print("syncBattleStatus: playerId=", playerId, ", inBattle=", inBattle)
	BattleSystem.set_battle_status(inBattle)

func enterBattleOk(initBattle: COM_InitBattle):
	print("enterBattleOk: battle_id=", initBattle.battleId_)
	BattleSystem.init_battle(initBattle)

func exitBattleOk(bjt: int, init: COM_BattleOverClearing):
	print("exitBattleOk: type=", bjt)
	BattleSystem.end_battle(bjt, init)

func syncOrderOk(uid: int):
	print("syncOrderOk: uid=", uid)
	BattleSystem.set_current_actor(uid)

func syncOrderOkEX():
	print("syncOrderOkEX")
	BattleSystem.next_round()

func syncOneTurnAction(reports: COM_BattleReport):
	print("syncOneTurnAction")
	BattleSystem.process_turn_report(reports)

func syncProperties(guid: int, props: Array[COM_PropValue]):
	# 1. 优先检查当前玩家
	var current_player = PlayerSystem.get_current()
	if current_player != null and current_player.get_instId_() == guid:
		PlayerSystem.update_properties(props)
		return

	# 2. 检查宝宝系统
	var baby = BabySystem.get_baby_by_id(guid)
	if baby != null:
		BabySystem.update_properties(guid, props)
		return

	# 3. 检查员工系统
	var employee = EmployeeSystem.get_employee_by_id(guid)
	if employee != null:
		EmployeeSystem.update_properties(guid, props)
		return

	# 4. 未找到对应实体
	print("警告: syncProperties - 找不到 guid 对应的实体: ", guid)

func receiveChat(info: COM_ChatInfo, myinfo: COM_ContactInfo):
	print("receiveChat")
	pass

func requestAudioOk(audioId: int, content: Array):
	print("requestAudioOk: ", audioId)
	pass

func publishItemInstRes(info: COM_ShowItemInstInfo, type: int):
	print("publishItemInstRes: type=", type)
	pass

func queryItemInstRes(item: COM_ShowItemInst):
	print("queryItemInstRes")
	pass

func publishBabyInstRes(info: COM_ShowbabyInstInfo, type: int):
	print("publishBabyInstRes: type=", type)
	pass

func queryBabyInstRes(inst: COM_ShowbabyInst):
	print("queryBabyInstRes")
	pass

func setNoTalkTime(t: float):
	pass

func addNpc(npcList: Array):
	print("addNpc: ", npcList.size())
	pass

func delNpc(npcList: Array):
	print("delNpc: ", npcList.size())
	pass

func setTeamLeader(playerId: int, isLeader: bool):
	print("setTeamLeader: ", playerId, ", isLeader=", isLeader)
	pass

func initBag(items: Array[COM_Item]):
	print("initBag: ", items.size())
	ItemSystem.init_bag(items)

func addBagItem(item: COM_Item):
	print("addBagItem: slot=", item.slot_)
	ItemSystem.add_item(item)

func delBagItem(slot: int):
	print("delBagItem: ", slot)
	ItemSystem.remove_item(slot)

func updateBagItem(item: COM_Item):
	print("updateBagItem: slot=", item.slot_)
	ItemSystem.update_item(item)

func depositItemOK(item: COM_Item):
	print("depositItemOK")
	ItemSystem.deposit_item(item)

func getoutItemOK(slot: int):
	print("getoutItemOK: ", slot)
	ItemSystem.withdraw_item(slot)

func depositBabyOK(baby: COM_BabyInst):
	print("depositBabyOK: ", baby.instId_)
	BabySystem.deposit_baby(baby)

func getoutBabyOK(slot: int):
	print("getoutBabyOK: ", slot)
	BabySystem.withdraw_baby(slot)

func sortItemStorageOK(items: Array[COM_Item]):
	print("sortItemStorageOK")
	ItemSystem.sort_storage(items)

func sortBabyStorageOK(babys: Array):
	print("sortBabyStorageOK")
	BabySystem.sort_storage(babys)

func initItemStorage(gridNum: int, items: Array[COM_Item]):
	print("initItemStorage: gridNum=", gridNum)
	ItemSystem.init_storage(gridNum, items)

func initBabyStorage(gridNum: int, babys: Array[COM_BabyInst]):
	print("initBabyStorage: gridNum=", gridNum)
	BabySystem.init_storage(gridNum, babys)

func openStorageGrid(tp: int, gridNum: int):
	print("openStorageGrid: tp=", tp, ", gridNum=", gridNum)
	if tp == 0:  # Item storage
		ItemSystem.open_storage_grid(gridNum)
	elif tp == 1:  # Baby storage
		BabySystem.open_storage_grid(gridNum)

func delStorageBabyOK(slot: int):
	print("delStorageBabyOK: ", slot)
	BabySystem.remove_storage_baby(slot)

func initPlayerEquips(equips: Array[COM_Item]):
	print("initPlayerEquips: ", equips.size())
	ItemSystem.init_equips(equips)

func wearEquipmentOk(target: int, equip: COM_Item):
	print("wearEquipmentOk: target=", target)
	ItemSystem.wear_equipment(target, equip)

func scenePlayerWearEquipment(target: int, itemId: int):
	# Another player equipped item, update scene
	pass

func delEquipmentOk(target: int, itemInstId: int):
	print("delEquipmentOk: target=", target)
	ItemSystem.remove_equipment(target, itemInstId)

func scenePlayerDoffEquipment(target: int, itemId: int):
	# Another player removed equipment, update scene
	pass

func sortBagItemOk():
	print("sortBagItemOk()")
	ItemSystem.sort_bag()

func jointLobbyOk(infos: Array[COM_SimpleTeamInfo]):
	print("jointLobbyOk: ", infos.size())
	pass

func exitLobbyOk():
	print("exitLobbyOk()")
	pass

func syncDelLobbyTeam(teamId: int):
	print("syncDelLobbyTeam: ", teamId)
	pass

func syncUpdateLobbyTeam(info: COM_SimpleTeamInfo):
	print("syncUpdateLobbyTeam")
	pass

func syncAddLobbyTeam(team: COM_SimpleTeamInfo):
	print("syncAddLobbyTeam")
	pass

func createTeamOk(team: COM_TeamInfo):
	print("createTeamOk")
	pass

func changeTeamOk(team: COM_TeamInfo):
	print("changeTeamOk")
	pass

func joinTeamOk(team: COM_TeamInfo):
	print("joinTeamOk")
	pass

func addTeamMember(info: COM_SimplePlayerInst):
	print("addTeamMember: ", info.instName_)
	pass

func delTeamMember(instId: int):
	print("delTeamMember: ", instId)
	pass

func changeTeamLeaderOk(uuid: int):
	print("changeTeamLeaderOk: ", uuid)
	pass

func exitTeamOk(iskick: bool):
	print("exitTeamOk: iskick=", iskick)
	pass

func updateTeam(team: COM_TeamInfo):
	print("updateTeam")
	pass

func joinTeamRoomOK(team: COM_TeamInfo):
	print("joinTeamRoomOK")
	pass

func inviteJoinTeam(teamId: int, name: String):
	print("inviteJoinTeam: ", teamId, ", ", name)
	pass

func syncTeamDirtyProp(guid: int, props: Array[COM_PropValue]):
	pass

func leaveTeamOk(playerId: int):
	print("leaveTeamOk: ", playerId)
	pass

func backTeamOK(playerId: int):
	print("backTeamOK: ", playerId)
	pass

func teamCallMemberBack():
	print("teamCallMemberBack()")
	pass

func refuseBackTeamOk(playerId: int):
	print("refuseBackTeamOk: ", playerId)
	pass

func requestJoinTeamTranspond(reqName: String):
	print("requestJoinTeamTranspond: ", reqName)
	pass

func drawLotteryBoxRep(items: Array[COM_Item]):
	print("drawLotteryBoxRep: ", items.size())
	pass

func addEmployee(employee: COM_EmployeeInst):
	print("addEmployee: ", employee.instId_)
	EmployeeSystem.add_employee(employee)

func battleEmployee(empId: int, group: int, forbattle: bool):
	print("battleEmployee: empId=", empId, ", group=", group, ", forbattle=", forbattle)
	EmployeeSystem.set_battle_employee(empId, group, forbattle)

func changeEmpBattleGroupOK(group: int):
	print("changeEmpBattleGroupOK: ", group)
	EmployeeSystem.change_battle_group(group)

func evolveOK(guid: int, qc: int):
	print("evolveOK: guid=", guid, ", qc=", qc)
	EmployeeSystem.evolve_employee(guid, qc)

func upStarOK(guid: int, star: int, sk: COM_Skill):
	print("upStarOK: guid=", guid, ", star=", star)
	EmployeeSystem.up_star_employee(guid, star, sk)

func delEmployeeOK(instids: Array):
	print("delEmployeeOK: ", instids.size())
	EmployeeSystem.remove_employees(instids)

func sycnEmployeeSoul(guid: int, soulNum: int):
	print("sycnEmployeeSoul: guid=", guid, ", soulNum=", soulNum)
	EmployeeSystem.update_soul(guid, soulNum)

func initQuest(qlist: Array[COM_QuestInst], clist: Array):
	print("initQuest: ", qlist.size())
	Player.quest_list = qlist
	Player.completed_quests = clist

func acceptQuestOk(inst: COM_QuestInst):
	print("acceptQuestOk: ", inst.questId_)
	Player.quest_list.append(inst)

func submitQuestOk(questId: int):
	print("submitQuestOk: ", questId)
	# Remove from active quests, add to completed
	for i in range(Player.quest_list.size()):
		if Player.quest_list[i].questId_ == questId:
			Player.quest_list.remove_at(i)
			break
	if questId not in Player.completed_quests:
		Player.completed_quests.append(questId)

func giveupQuestOk(questId: int):
	print("giveupQuestOk: ", questId)
	for i in range(Player.quest_list.size()):
		if Player.quest_list[i].questId_ == questId:
			Player.quest_list.remove_at(i)
			break

func updateQuestInst(inst: COM_QuestInst):
	print("updateQuestInst: ", inst.questId_)
	for i in range(Player.quest_list.size()):
		if Player.quest_list[i].questId_ == inst.questId_:
			Player.quest_list[i] = inst
			break

func requestContactInfoOk(contact: COM_ContactInfo):
	print("requestContactInfoOk")
	pass

func addFriendOK(inst: COM_ContactInfo):
	print("addFriendOK: ", inst.name_)
	pass

func delFriendOK(instId: int):
	print("delFriendOK: ", instId)
	pass

func addBlacklistOK(inst: COM_ContactInfo):
	print("addBlacklistOK: ", inst.name_)
	pass

func delBlacklistOK(instId: int):
	print("delBlacklistOK: ", instId)
	pass

func findFriendFail():
	print("findFriendFail()")
	pass

func referrFriendOK(insts: Array[COM_ContactInfo]):
	print("referrFriendOK: ", insts.size())
	pass

func requestFriendListOK(insts: Array[COM_ContactInfo]):
	print("requestFriendListOK: ", insts.size())
	pass

func lotteryOk(lotteryId: int, dropItem: Array[COM_DropItem]):
	print("lotteryOk: ", lotteryId)
	pass

func openGatherOK(gather: COM_Gather):
	print("openGatherOK")
	pass

func miningOk(items: Array[COM_DropItem], gather: COM_Gather, gatherNum: int):
	print("miningOk")
	pass

func openCompound(compoundId: int):
	print("openCompound: ", compoundId)
	pass

func compoundItemOk(item: COM_Item):
	print("compoundItemOk")
	pass

func openBagGridOk(num: int):
	print("openBagGridOk: ", num)
	pass

func requestChallengeOK(isOK: bool):
	print("requestChallengeOK: ", isOK)
	pass

func requestMySelfJJCDataOK(info: COM_EndlessStair):
	print("requestMySelfJJCDataOK")
	pass

func requestRivalOK(infos: Array[COM_EndlessStair]):
	print("requestRivalOK: ", infos.size())
	pass

func rivalTimeOK():
	print("rivalTimeOK()")
	pass

func checkMsgOK(inst: COM_SimplePlayerInst):
	print("checkMsgOK")
	pass

func requestMyAllbattleMsgOK(infos: Array[COM_JJCBattleMsg]):
	print("requestMyAllbattleMsgOK: ", infos.size())
	pass

func myBattleMsgOK(info: COM_JJCBattleMsg):
	print("myBattleMsgOK")
	pass

func requestJJCRankOK(myRank: int, infos: Array[COM_EndlessStair]):
	print("requestJJCRankOK: myRank=", myRank)
	pass

func requestLevelRankOK(myRank: int, infos: Array[COM_ContactInfo]):
	print("requestLevelRankOK: myRank=", myRank)
	pass

func requestBabyRankOK(myRank: int, infos: Array[COM_BabyRankData]):
	print("requestBabyRankOK: myRank=", myRank)
	pass

func requestEmpRankOK(myRank: int, infos: Array[COM_EmployeeRankData]):
	print("requestEmpRankOK: myRank=", myRank)
	pass

func requestPlayerFFRankOK(myRank: int, infos: Array[COM_ContactInfo]):
	print("requestPlayerFFRankOK: myRank=", myRank)
	pass

func queryOnlinePlayerOK(isOnline: bool):
	print("queryOnlinePlayerOK: ", isOnline)
	pass

func queryPlayerOK(inst: COM_SimplePlayerInst):
	print("queryPlayerOK")
	pass

func queryBabyOK(inst: COM_BabyInst):
	print("queryBabyOK")
	pass

func queryEmployeeOK(inst: COM_EmployeeInst):
	print("queryEmployeeOK")
	pass

func initGuide(guideMask: int):
	print("initGuide: mask=", guideMask)
	pass

func buyShopItemOk(id: int):
	print("buyShopItemOk: ", id)
	pass

func addPlayerTitle(title: int):
	print("addPlayerTitle: ", title)
	pass

func delPlayerTitle(title: int):
	print("delPlayerTitle: ", title)
	pass

func requestOpenBuyBox(greenTime: float, blueTime: float, greenFreeNum: int):
	print("requestOpenBuyBox")
	pass

func requestGreenBoxTimeOk():
	print("requestGreenBoxTimeOk()")
	pass

func requestBlueBoxTimeOk():
	print("requestBlueBoxTimeOk()")
	pass

func updateAchievementinfo(achs: COM_Achievement):
	print("updateAchievementinfo")
	pass

func syncOpenSystemFlag(flag: int):
	print("syncOpenSystemFlag: ", flag)
	pass

func requestActivityRewardOK(ar: int):
	print("requestActivityRewardOK: ", ar)
	pass

func syncActivity(table: COM_ActivityTable):
	print("syncActivity")
	pass

func updateActivityStatus(type: int, open: bool):
	print("updateActivityStatus: type=", type, ", open=", open)
	pass

func updateActivityCounter(type: int, counter: int, reward: int):
	print("updateActivityCounter: type=", type)
	pass

func syncExam(exam: COM_Exam):
	print("syncExam")
	pass

func syncExamAnswer(answer: COM_Answer):
	print("syncExamAnswer")
	pass

func petActivityNoNum(name: String):
	print("petActivityNoNum: ", name)
	pass

func syncHundredInfo(hb: COM_HundredBattle):
	print("syncHundredInfo")
	pass

func initSignUp(info: Array, process: int, sign7: bool, sign14: bool, sign28: bool):
	print("initSignUp: process=", process)
	pass

func signUp(flag: bool):
	print("signUp: ", flag)
	pass

func requestSignupRewardOk7():
	print("requestSignupRewardOk7()")
	pass

func requestSignupRewardOk14():
	print("requestSignupRewardOk14()")
	pass

func requestSignupRewardOk28():
	print("requestSignupRewardOk28()")
	pass

func sycnDoubleExpTime(isFlag: bool, times: float):
	print("sycnDoubleExpTime: isFlag=", isFlag)
	pass

func sycnStates(states: Array[COM_State]):
	print("sycnStates: ", states.size())
	Player.states = states

func requestpvprankOK(infos: Array[COM_ContactInfo]):
	print("requestpvprankOK: ", infos.size())
	pass

func syncMyJJCTeamMember():
	print("syncMyJJCTeamMember()")
	pass

func startMatchingOK():
	print("startMatchingOK()")
	pass

func stopMatchingOK(times: float):
	print("stopMatchingOK: times=", times)
	pass

func updatePvpJJCinfo(info: COM_PlayerVsPlayer):
	print("updatePvpJJCinfo")
	pass

func exitPvpJJCOk():
	print("exitPvpJJCOk()")
	pass

func syncEnemyPvpJJCPlayerInfo(info: COM_SimpleInformation):
	print("syncEnemyPvpJJCPlayerInfo")
	pass

func syncEnemyPvpJJCTeamInfo(infos: Array[COM_SimpleInformation], teamID_: int):
	print("syncEnemyPvpJJCTeamInfo: teamID=", teamID_)
	pass

func openWarriorchooseUI():
	print("openWarriorchooseUI()")
	pass

func warriorStartOK():
	print("warriorStartOK()")
	pass

func warriorStopOK():
	print("warriorStopOK()")
	pass

func syncWarriorEnemyTeamInfo(infos: Array[COM_SimpleInformation], teamID_: int):
	print("syncWarriorEnemyTeamInfo: teamID=", teamID_)
	pass

func appendMail(mails: Array[COM_Mail]):
	print("appendMail: ", mails.size())
	for mail in mails:
		Player.mails.append(mail)

func delMail(mailId: int):
	print("delMail: ", mailId)
	for i in range(Player.mails.size()):
		if Player.mails[i].mailId_ == mailId:
			Player.mails.remove_at(i)
			break

func updateMailOk(mail: COM_Mail):
	print("updateMailOk: ", mail.mailId_)
	for i in range(Player.mails.size()):
		if Player.mails[i].mailId_ == mail.mailId_:
			Player.mails[i] = mail
			break

func boardcastNotice(content: String, isGm: bool):
	print("boardcastNotice: ", content)
	# Show broadcast notice to player
	pass

func createGuildOK():
	print("createGuildOK()")
	# Guild created successfully

func delGuildOK():
	print("delGuildOK()")
	Player.guild = null
	Player.guild_members.clear()

func leaveGuildOk(who: String, isKick: bool):
	print("leaveGuildOk: who=", who, ", isKick=", isKick)
	if who == Player.current.instName_:
		# I left the guild
		Player.guild = null
		Player.guild_members.clear()
	else:
		# Someone else left
		for i in range(Player.guild_members.size()):
			if Player.guild_members[i].name_ == who:
				Player.guild_members.remove_at(i)
				break

func initGuildData(guild: COM_Guild):
	print("initGuildData")
	Player.guild = guild

func initGuildMemberList(member: Array[COM_GuildMember]):
	print("initGuildMemberList: ", member.size())
	Player.guild_members = member

func modifyGuildMemberList(member: COM_GuildMember, flag: int):
	print("modifyGuildMemberList: flag=", flag)
	if flag == 0:  # Add
		Player.guild_members.append(member)
	elif flag == 1:  # Update
		for i in range(Player.guild_members.size()):
			if Player.guild_members[i].instId_ == member.instId_:
				Player.guild_members[i] = member
				break
	elif flag == 2:  # Delete
		for i in range(Player.guild_members.size()):
			if Player.guild_members[i].instId_ == member.instId_:
				Player.guild_members.remove_at(i)
				break

func modifyGuildList(data: COM_GuildViewerData, flag: int):
	print("modifyGuildList: flag=", flag)
	pass

func queryGuildListResult(page: int, pageNum: int, guildList: Array[COM_GuildViewerData]):
	print("queryGuildListResult: page=", page, "/", pageNum)
	pass

func inviteGuild(sendName: String, guildName: String):
	print("inviteGuild: ", sendName, " -> ", guildName)
	pass

func updateGuildShopItems(items: Array[COM_GuildShopItem]):
	print("updateGuildShopItems: ", items.size())
	pass

func updateGuildBuilding(type: int, building: COM_GuildBuilding):
	print("updateGuildBuilding: type=", type)
	pass

func updateGuildMyMember(member: COM_GuildMember):
	print("updateGuildMyMember")
	pass

func levelupGuildSkillOk(skInst: COM_Skill):
	print("levelupGuildSkillOk")
	pass

func presentGuildItemOk(val: int):
	print("presentGuildItemOk: val=", val)
	pass

func progenitusAddExpOk(mInst: COM_GuildProgen):
	print("progenitusAddExpOk")
	pass

func setProgenitusPositionOk(positions: Array):
	print("setProgenitusPositionOk")
	pass

func updateGuildFundz(val: int):
	print("updateGuildFundz: val=", val)
	pass

func updateGuildMemberContribution(val: int):
	print("updateGuildMemberContribution: val=", val)
	pass

func openGuildBattle(otherName: String, playerNum: int, level: int, isLeft: bool, lstime: int):
	print("openGuildBattle: ", otherName)
	pass

func startGuildBattle(otherName: String, otherCon: int, selfCon: int):
	print("startGuildBattle: ", otherName)
	pass

func closeGuildBattle(isWinner: bool):
	print("closeGuildBattle: isWinner=", isWinner)
	pass

func syncGuildBattleWinCount(myWin: int, otherWin: int):
	print("syncGuildBattleWinCount: ", myWin, "/", otherWin)
	pass

func initMySelling(items: Array[COM_SellItem]):
	print("initMySelling: ", items.size())
	pass

func initMySelled(items: Array[COM_SelledItem]):
	print("initMySelled: ", items.size())
	pass

func fetchSellingOk(items: Array[COM_SellItem], total: int):
	print("fetchSellingOk: total=", total)
	pass

func fetchSellingOk2(items: Array[COM_SellItem], total: int):
	print("fetchSellingOk2: total=", total)
	pass

func sellingOk(item: COM_SellItem):
	print("sellingOk")
	pass

func selledOk(item: COM_SelledItem):
	print("selledOk")
	pass

func unsellingOk(sellid: int):
	print("unsellingOk: ", sellid)
	pass

func redemptionSpreeOk():
	print("redemptionSpreeOk()")
	pass

func insertState(st: COM_State):
	print("insertState: id=", st.stateId_)
	# 检查是否已存在相同ID的状态
	for i in range(Player.states.size()):
		if Player.states[i].stateId_ == st.stateId_:
			# 更新现有状态
			Player.states[i] = st
			return
	# 不存在则添加
	Player.states.append(st)

func updattState(st: COM_State):
	print("updattState: id=", st.stateId_)
	for i in range(Player.states.size()):
		if Player.states[i].stateId_ == st.stateId_:
			Player.states[i] = st
			return
	# 未找到则添加
	Player.states.append(st)

func removeState(stid: int):
	print("removeState: ", stid)
	for i in range(Player.states.size()):
		if Player.states[i].stateId_ == stid:
			Player.states.remove_at(i)
			return

func requestFixItemOk(item: COM_Item):
	print("requestFixItemOk")
	pass

func makeDebirsItemOK():
	print("makeDebirsItemOK()")
	pass

func updateMagicItem(level: int, exp: int):
	print("updateMagicItem: level=", level, ", exp=", exp)
	pass

func changeMagicJobOk(job: int):
	print("changeMagicJobOk: job=", job)
	pass

func magicItemTupoOk(level: int):
	print("magicItemTupoOk: level=", level)
	pass

func zhuanpanOK(pond: Array):
	print("zhuanpanOK")
	pass

func updateZhuanpanNotice(zhuanp: COM_Zhuanpan):
	print("updateZhuanpanNotice")
	pass

func sycnZhuanpanData(data: COM_ZhuanpanData):
	print("sycnZhuanpanData")
	pass

func copynonum(name: String):
	print("copynonum: ", name)
	pass
