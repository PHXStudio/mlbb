#include "Server2ClientProxy.h"

namespace godot {

Server2ClientProxy::Server2ClientProxy() {}
Server2ClientProxy::~Server2ClientProxy() {}

bool Server2ClientProxy::dispatch(ProtocolReader *r) {
  return Server2Client_Dispatcher::dispatch(r, this);
}

void Server2ClientProxy::pong() { emit_signal("pong"); }

void Server2ClientProxy::errorno(uint16_t e) { emit_signal("errorno", e); }

void Server2ClientProxy::teamerrorno(String name, uint16_t e) {
  emit_signal("teamerrorno", name, e);
}

void Server2ClientProxy::reconnection(Ref<COM_ReconnectInfo> recInfo) {
  emit_signal("reconnection", recInfo);
}

void Server2ClientProxy::sessionfailed() { emit_signal("sessionfailed"); }

void Server2ClientProxy::loginok(String sessionkey,
                                 TypedArray<COM_SimpleInformation> players) {
  emit_signal("loginok", sessionkey, players);
}

void Server2ClientProxy::logoutOk() { emit_signal("logoutOk"); }

void Server2ClientProxy::createPlayerOk(Ref<COM_SimpleInformation> player) {
  emit_signal("createPlayerOk", player);
}

void Server2ClientProxy::deletePlayerOk(String name) {
  emit_signal("deletePlayerOk", name);
}

void Server2ClientProxy::enterGameOk(Ref<COM_PlayerInst> inst) {
  emit_signal("enterGameOk", inst);
}

void Server2ClientProxy::initBabies(TypedArray<COM_BabyInst> insts) {
  emit_signal("initBabies", insts);
}

void Server2ClientProxy::initEmployees(TypedArray<COM_EmployeeInst> insts,
                                       bool isFlag) {
  emit_signal("initEmployees", insts, isFlag);
}

void Server2ClientProxy::initEmpBattleGroup(Ref<COM_BattleEmp> bep) {
  emit_signal("initEmpBattleGroup", bep);
}

void Server2ClientProxy::initNpc(TypedArray<int32_t> npcList) {
  emit_signal("initNpc", npcList);
}

void Server2ClientProxy::initAchievement(TypedArray<COM_Achievement> actlist) {
  emit_signal("initAchievement", actlist);
}

void Server2ClientProxy::initGather(uint32_t allnum,
                                    TypedArray<COM_Gather> gathers) {
  emit_signal("initGather", allnum, gathers);
}

void Server2ClientProxy::initcompound(TypedArray<uint32_t> compounds) {
  emit_signal("initcompound", compounds);
}

void Server2ClientProxy::addBaby(Ref<COM_BabyInst> inst) {
  emit_signal("addBaby", inst);
}

void Server2ClientProxy::refreshBaby(Ref<COM_BabyInst> inst) {
  emit_signal("refreshBaby", inst);
}

void Server2ClientProxy::delBabyOK(uint32_t babyInstId) {
  emit_signal("delBabyOK", babyInstId);
}

void Server2ClientProxy::changeBabyNameOK(uint32_t babyId, String name) {
  emit_signal("changeBabyNameOK", babyId, name);
}

void Server2ClientProxy::remouldBabyOK(uint32_t instid) {
  emit_signal("remouldBabyOK", instid);
}

void Server2ClientProxy::intensifyBabyOK(uint32_t babyid,
                                         uint32_t intensifyLevel) {
  emit_signal("intensifyBabyOK", babyid, intensifyLevel);
}

void Server2ClientProxy::learnSkillOk(Ref<COM_Skill> inst) {
  emit_signal("learnSkillOk", inst);
}

void Server2ClientProxy::forgetSkillOk(uint32_t skid) {
  emit_signal("forgetSkillOk", skid);
}

void Server2ClientProxy::addSkillExp(uint32_t skid, uint32_t uExp,
                                     uint16_t flag) {
  emit_signal("addSkillExp", skid, uExp, flag);
}

void Server2ClientProxy::babyLearnSkillOK(uint32_t instId, uint32_t newSkId) {
  emit_signal("babyLearnSkillOK", instId, newSkId);
}

void Server2ClientProxy::skillLevelUp(uint32_t instId, Ref<COM_Skill> inst) {
  emit_signal("skillLevelUp", instId, inst);
}

void Server2ClientProxy::joinScene(Ref<COM_SceneInfo> info) {
  emit_signal("joinScene", info);
}

void Server2ClientProxy::joinCopySceneOK(int32_t secneid) {
  emit_signal("joinCopySceneOK", secneid);
}

void Server2ClientProxy::initCopyNums() { emit_signal("initCopyNums"); }

void Server2ClientProxy::addToScene(Ref<COM_ScenePlayerInformation> inst) {
  emit_signal("addToScene", inst);
}

void Server2ClientProxy::delFormScene(int32_t instId) {
  emit_signal("delFormScene", instId);
}

void Server2ClientProxy::move2(int32_t instId, Ref<COM_FPosition> pos) {
  emit_signal("move2", instId, pos);
}

void Server2ClientProxy::cantMove() { emit_signal("cantMove"); }

void Server2ClientProxy::querySimplePlayerInstOk(
    Ref<COM_SimplePlayerInst> player) {
  emit_signal("querySimplePlayerInstOk", player);
}

void Server2ClientProxy::transfor2(int32_t instId, Ref<COM_FPosition> pos) {
  emit_signal("transfor2", instId, pos);
}

void Server2ClientProxy::openScene(int32_t sceneId) {
  emit_signal("openScene", sceneId);
}

void Server2ClientProxy::autoBattleResult(bool isOk) {
  emit_signal("autoBattleResult", isOk);
}

void Server2ClientProxy::talked2Npc(int32_t npcId) {
  emit_signal("talked2Npc", npcId);
}

void Server2ClientProxy::talked2Player(int32_t playerId) {
  emit_signal("talked2Player", playerId);
}

void Server2ClientProxy::useItemOk(int32_t itemId, int32_t stack) {
  emit_signal("useItemOk", itemId, stack);
}

void Server2ClientProxy::syncBattleStatus(int32_t playerId, bool inBattle) {
  emit_signal("syncBattleStatus", playerId, inBattle);
}

void Server2ClientProxy::enterBattleOk(Ref<COM_InitBattle> initBattle) {
  emit_signal("enterBattleOk", initBattle);
}

void Server2ClientProxy::exitBattleOk(uint16_t bjt,
                                      Ref<COM_BattleOverClearing> init) {
  emit_signal("exitBattleOk", bjt, init);
}

void Server2ClientProxy::syncOrderOk(uint32_t uid) {
  emit_signal("syncOrderOk", uid);
}

void Server2ClientProxy::syncOrderOkEX() { emit_signal("syncOrderOkEX"); }

void Server2ClientProxy::syncOneTurnAction(Ref<COM_BattleReport> reports) {
  emit_signal("syncOneTurnAction", reports);
}

void Server2ClientProxy::syncProperties(uint32_t guid,
                                        TypedArray<COM_PropValue> props) {
  emit_signal("syncProperties", guid, props);
}

void Server2ClientProxy::receiveChat(Ref<COM_ChatInfo> info,
                                     Ref<COM_ContactInfo> myinfo) {
  emit_signal("receiveChat", info, myinfo);
}

void Server2ClientProxy::requestAudioOk(int32_t audioId,
                                        TypedArray<uint8_t> content) {
  emit_signal("requestAudioOk", audioId, content);
}

void Server2ClientProxy::publishItemInstRes(Ref<COM_ShowItemInstInfo> info,
                                            uint16_t type) {
  emit_signal("publishItemInstRes", info, type);
}

void Server2ClientProxy::queryItemInstRes(Ref<COM_ShowItemInst> item) {
  emit_signal("queryItemInstRes", item);
}

void Server2ClientProxy::publishBabyInstRes(Ref<COM_ShowbabyInstInfo> info,
                                            uint16_t type) {
  emit_signal("publishBabyInstRes", info, type);
}

void Server2ClientProxy::queryBabyInstRes(Ref<COM_ShowbabyInst> inst) {
  emit_signal("queryBabyInstRes", inst);
}

void Server2ClientProxy::setNoTalkTime(float t) {
  emit_signal("setNoTalkTime", t);
}

void Server2ClientProxy::addNpc(TypedArray<int32_t> npcList) {
  emit_signal("addNpc", npcList);
}

void Server2ClientProxy::delNpc(TypedArray<int32_t> npcList) {
  emit_signal("delNpc", npcList);
}

void Server2ClientProxy::setTeamLeader(int32_t playerId, bool isLeader) {
  emit_signal("setTeamLeader", playerId, isLeader);
}

void Server2ClientProxy::initBag(TypedArray<COM_Item> items) {
  emit_signal("initBag", items);
}

void Server2ClientProxy::addBagItem(Ref<COM_Item> item) {
  emit_signal("addBagItem", item);
}

void Server2ClientProxy::delBagItem(uint16_t slot) {
  emit_signal("delBagItem", slot);
}

void Server2ClientProxy::updateBagItem(Ref<COM_Item> item) {
  emit_signal("updateBagItem", item);
}

void Server2ClientProxy::depositItemOK(Ref<COM_Item> item) {
  emit_signal("depositItemOK", item);
}

void Server2ClientProxy::getoutItemOK(uint16_t slot) {
  emit_signal("getoutItemOK", slot);
}

void Server2ClientProxy::depositBabyOK(Ref<COM_BabyInst> baby) {
  emit_signal("depositBabyOK", baby);
}

void Server2ClientProxy::getoutBabyOK(uint16_t slot) {
  emit_signal("getoutBabyOK", slot);
}

void Server2ClientProxy::sortItemStorageOK(TypedArray<COM_Item> items) {
  emit_signal("sortItemStorageOK", items);
}

void Server2ClientProxy::sortBabyStorageOK(TypedArray<uint32_t> babys) {
  emit_signal("sortBabyStorageOK", babys);
}

void Server2ClientProxy::initItemStorage(uint16_t gridNum,
                                         TypedArray<COM_Item> items) {
  emit_signal("initItemStorage", gridNum, items);
}

void Server2ClientProxy::initBabyStorage(uint16_t gridNum,
                                         TypedArray<COM_BabyInst> babys) {
  emit_signal("initBabyStorage", gridNum, babys);
}

void Server2ClientProxy::openStorageGrid(uint16_t tp, uint16_t gridNum) {
  emit_signal("openStorageGrid", tp, gridNum);
}

void Server2ClientProxy::delStorageBabyOK(uint16_t slot) {
  emit_signal("delStorageBabyOK", slot);
}

void Server2ClientProxy::initPlayerEquips(TypedArray<COM_Item> equips) {
  emit_signal("initPlayerEquips", equips);
}

void Server2ClientProxy::wearEquipmentOk(uint32_t target, Ref<COM_Item> equip) {
  emit_signal("wearEquipmentOk", target, equip);
}

void Server2ClientProxy::scenePlayerWearEquipment(uint32_t target,
                                                  uint32_t itemId) {
  emit_signal("scenePlayerWearEquipment", target, itemId);
}

void Server2ClientProxy::delEquipmentOk(uint32_t target, uint32_t itemInstId) {
  emit_signal("delEquipmentOk", target, itemInstId);
}

void Server2ClientProxy::scenePlayerDoffEquipment(uint32_t target,
                                                  uint32_t itemId) {
  emit_signal("scenePlayerDoffEquipment", target, itemId);
}

void Server2ClientProxy::sortBagItemOk() { emit_signal("sortBagItemOk"); }

void Server2ClientProxy::jointLobbyOk(TypedArray<COM_SimpleTeamInfo> infos) {
  emit_signal("jointLobbyOk", infos);
}

void Server2ClientProxy::exitLobbyOk() { emit_signal("exitLobbyOk"); }

void Server2ClientProxy::syncDelLobbyTeam(uint32_t teamId) {
  emit_signal("syncDelLobbyTeam", teamId);
}

void Server2ClientProxy::syncUpdateLobbyTeam(Ref<COM_SimpleTeamInfo> info) {
  emit_signal("syncUpdateLobbyTeam", info);
}

void Server2ClientProxy::syncAddLobbyTeam(Ref<COM_SimpleTeamInfo> team) {
  emit_signal("syncAddLobbyTeam", team);
}

void Server2ClientProxy::createTeamOk(Ref<COM_TeamInfo> team) {
  emit_signal("createTeamOk", team);
}

void Server2ClientProxy::changeTeamOk(Ref<COM_TeamInfo> team) {
  emit_signal("changeTeamOk", team);
}

void Server2ClientProxy::joinTeamOk(Ref<COM_TeamInfo> team) {
  emit_signal("joinTeamOk", team);
}

void Server2ClientProxy::addTeamMember(Ref<COM_SimplePlayerInst> info) {
  emit_signal("addTeamMember", info);
}

void Server2ClientProxy::delTeamMember(int32_t instId) {
  emit_signal("delTeamMember", instId);
}

void Server2ClientProxy::changeTeamLeaderOk(int32_t uuid) {
  emit_signal("changeTeamLeaderOk", uuid);
}

void Server2ClientProxy::exitTeamOk(bool iskick) {
  emit_signal("exitTeamOk", iskick);
}

void Server2ClientProxy::updateTeam(Ref<COM_TeamInfo> team) {
  emit_signal("updateTeam", team);
}

void Server2ClientProxy::joinTeamRoomOK(Ref<COM_TeamInfo> team) {
  emit_signal("joinTeamRoomOK", team);
}

void Server2ClientProxy::inviteJoinTeam(uint32_t teamId, String name) {
  emit_signal("inviteJoinTeam", teamId, name);
}

void Server2ClientProxy::syncTeamDirtyProp(int32_t guid,
                                           TypedArray<COM_PropValue> props) {
  emit_signal("syncTeamDirtyProp", guid, props);
}

void Server2ClientProxy::leaveTeamOk(int32_t playerId) {
  emit_signal("leaveTeamOk", playerId);
}

void Server2ClientProxy::backTeamOK(int32_t playerId) {
  emit_signal("backTeamOK", playerId);
}

void Server2ClientProxy::teamCallMemberBack() {
  emit_signal("teamCallMemberBack");
}

void Server2ClientProxy::refuseBackTeamOk(int32_t playerId) {
  emit_signal("refuseBackTeamOk", playerId);
}

void Server2ClientProxy::requestJoinTeamTranspond(String reqName) {
  emit_signal("requestJoinTeamTranspond", reqName);
}

void Server2ClientProxy::drawLotteryBoxRep(TypedArray<COM_Item> items) {
  emit_signal("drawLotteryBoxRep", items);
}

void Server2ClientProxy::addEmployee(Ref<COM_EmployeeInst> employee) {
  emit_signal("addEmployee", employee);
}

void Server2ClientProxy::battleEmployee(int32_t empId, uint16_t group,
                                        bool forbattle) {
  emit_signal("battleEmployee", empId, group, forbattle);
}

void Server2ClientProxy::changeEmpBattleGroupOK(uint16_t group) {
  emit_signal("changeEmpBattleGroupOK", group);
}

void Server2ClientProxy::evolveOK(int32_t guid, uint16_t qc) {
  emit_signal("evolveOK", guid, qc);
}

void Server2ClientProxy::upStarOK(int32_t guid, int32_t star,
                                  Ref<COM_Skill> sk) {
  emit_signal("upStarOK", guid, star, sk);
}

void Server2ClientProxy::delEmployeeOK(TypedArray<uint32_t> instids) {
  emit_signal("delEmployeeOK", instids);
}

void Server2ClientProxy::sycnEmployeeSoul(int32_t guid, uint32_t soulNum) {
  emit_signal("sycnEmployeeSoul", guid, soulNum);
}

void Server2ClientProxy::initQuest(TypedArray<COM_QuestInst> qlist,
                                   TypedArray<int32_t> clist) {
  emit_signal("initQuest", qlist, clist);
}

void Server2ClientProxy::acceptQuestOk(Ref<COM_QuestInst> inst) {
  emit_signal("acceptQuestOk", inst);
}

void Server2ClientProxy::submitQuestOk(int32_t questId) {
  emit_signal("submitQuestOk", questId);
}

void Server2ClientProxy::giveupQuestOk(int32_t questId) {
  emit_signal("giveupQuestOk", questId);
}

void Server2ClientProxy::updateQuestInst(Ref<COM_QuestInst> inst) {
  emit_signal("updateQuestInst", inst);
}

void Server2ClientProxy::requestContactInfoOk(Ref<COM_ContactInfo> contact) {
  emit_signal("requestContactInfoOk", contact);
}

void Server2ClientProxy::addFriendOK(Ref<COM_ContactInfo> inst) {
  emit_signal("addFriendOK", inst);
}

void Server2ClientProxy::delFriendOK(uint32_t instId) {
  emit_signal("delFriendOK", instId);
}

void Server2ClientProxy::addBlacklistOK(Ref<COM_ContactInfo> inst) {
  emit_signal("addBlacklistOK", inst);
}

void Server2ClientProxy::delBlacklistOK(uint32_t instId) {
  emit_signal("delBlacklistOK", instId);
}

void Server2ClientProxy::findFriendFail() { emit_signal("findFriendFail"); }

void Server2ClientProxy::referrFriendOK(TypedArray<COM_ContactInfo> insts) {
  emit_signal("referrFriendOK", insts);
}

void Server2ClientProxy::requestFriendListOK(
    TypedArray<COM_ContactInfo> insts) {
  emit_signal("requestFriendListOK", insts);
}

void Server2ClientProxy::lotteryOk(int32_t lotteryId,
                                   TypedArray<COM_DropItem> dropItem) {
  emit_signal("lotteryOk", lotteryId, dropItem);
}

void Server2ClientProxy::openGatherOK(Ref<COM_Gather> gather) {
  emit_signal("openGatherOK", gather);
}

void Server2ClientProxy::miningOk(TypedArray<COM_DropItem> items,
                                  Ref<COM_Gather> gather, uint32_t gatherNum) {
  emit_signal("miningOk", items, gather, gatherNum);
}

void Server2ClientProxy::openCompound(uint32_t compoundId) {
  emit_signal("openCompound", compoundId);
}

void Server2ClientProxy::compoundItemOk(Ref<COM_Item> item) {
  emit_signal("compoundItemOk", item);
}

void Server2ClientProxy::openBagGridOk(int32_t num) {
  emit_signal("openBagGridOk", num);
}

void Server2ClientProxy::requestChallengeOK(bool isOK) {
  emit_signal("requestChallengeOK", isOK);
}

void Server2ClientProxy::requestMySelfJJCDataOK(Ref<COM_EndlessStair> info) {
  emit_signal("requestMySelfJJCDataOK", info);
}

void Server2ClientProxy::requestRivalOK(TypedArray<COM_EndlessStair> infos) {
  emit_signal("requestRivalOK", infos);
}

void Server2ClientProxy::rivalTimeOK() { emit_signal("rivalTimeOK"); }

void Server2ClientProxy::checkMsgOK(Ref<COM_SimplePlayerInst> inst) {
  emit_signal("checkMsgOK", inst);
}

void Server2ClientProxy::requestMyAllbattleMsgOK(
    TypedArray<COM_JJCBattleMsg> infos) {
  emit_signal("requestMyAllbattleMsgOK", infos);
}

void Server2ClientProxy::myBattleMsgOK(Ref<COM_JJCBattleMsg> info) {
  emit_signal("myBattleMsgOK", info);
}

void Server2ClientProxy::requestJJCRankOK(uint32_t myRank,
                                          TypedArray<COM_EndlessStair> infos) {
  emit_signal("requestJJCRankOK", myRank, infos);
}

void Server2ClientProxy::requestLevelRankOK(uint32_t myRank,
                                            TypedArray<COM_ContactInfo> infos) {
  emit_signal("requestLevelRankOK", myRank, infos);
}

void Server2ClientProxy::requestBabyRankOK(uint32_t myRank,
                                           TypedArray<COM_BabyRankData> infos) {
  emit_signal("requestBabyRankOK", myRank, infos);
}

void Server2ClientProxy::requestEmpRankOK(
    uint32_t myRank, TypedArray<COM_EmployeeRankData> infos) {
  emit_signal("requestEmpRankOK", myRank, infos);
}

void Server2ClientProxy::requestPlayerFFRankOK(
    uint32_t myRank, TypedArray<COM_ContactInfo> infos) {
  emit_signal("requestPlayerFFRankOK", myRank, infos);
}

void Server2ClientProxy::queryOnlinePlayerOK(bool isOnline) {
  emit_signal("queryOnlinePlayerOK", isOnline);
}

void Server2ClientProxy::queryPlayerOK(Ref<COM_SimplePlayerInst> inst) {
  emit_signal("queryPlayerOK", inst);
}

void Server2ClientProxy::queryBabyOK(Ref<COM_BabyInst> inst) {
  emit_signal("queryBabyOK", inst);
}

void Server2ClientProxy::queryEmployeeOK(Ref<COM_EmployeeInst> inst) {
  emit_signal("queryEmployeeOK", inst);
}

void Server2ClientProxy::initGuide(uint32_t guideMask) {
  emit_signal("initGuide", guideMask);
}

void Server2ClientProxy::buyShopItemOk(int32_t id) {
  emit_signal("buyShopItemOk", id);
}

void Server2ClientProxy::addPlayerTitle(int32_t title) {
  emit_signal("addPlayerTitle", title);
}

void Server2ClientProxy::delPlayerTitle(int32_t title) {
  emit_signal("delPlayerTitle", title);
}

void Server2ClientProxy::requestOpenBuyBox(float greenTime, float blueTime,
                                           int32_t greenFreeNum) {
  emit_signal("requestOpenBuyBox", greenTime, blueTime, greenFreeNum);
}

void Server2ClientProxy::requestGreenBoxTimeOk() {
  emit_signal("requestGreenBoxTimeOk");
}

void Server2ClientProxy::requestBlueBoxTimeOk() {
  emit_signal("requestBlueBoxTimeOk");
}

void Server2ClientProxy::updateAchievementinfo(Ref<COM_Achievement> achs) {
  emit_signal("updateAchievementinfo", achs);
}

void Server2ClientProxy::syncOpenSystemFlag(uint64_t flag) {
  emit_signal("syncOpenSystemFlag", flag);
}

void Server2ClientProxy::requestActivityRewardOK(uint32_t ar) {
  emit_signal("requestActivityRewardOK", ar);
}

void Server2ClientProxy::syncActivity(Ref<COM_ActivityTable> table) {
  emit_signal("syncActivity", table);
}

void Server2ClientProxy::updateActivityStatus(uint16_t type, bool open) {
  emit_signal("updateActivityStatus", type, open);
}

void Server2ClientProxy::updateActivityCounter(uint16_t type, int32_t counter,
                                               int32_t reward) {
  emit_signal("updateActivityCounter", type, counter, reward);
}

void Server2ClientProxy::syncExam(Ref<COM_Exam> exam) {
  emit_signal("syncExam", exam);
}

void Server2ClientProxy::syncExamAnswer(Ref<COM_Answer> answer) {
  emit_signal("syncExamAnswer", answer);
}

void Server2ClientProxy::petActivityNoNum(String name) {
  emit_signal("petActivityNoNum", name);
}

void Server2ClientProxy::syncHundredInfo(Ref<COM_HundredBattle> hb) {
  emit_signal("syncHundredInfo", hb);
}

void Server2ClientProxy::initSignUp(TypedArray<int32_t> info, int32_t process,
                                    bool sign7, bool sign14, bool sign28) {
  emit_signal("initSignUp", info, process, sign7, sign14, sign28);
}

void Server2ClientProxy::signUp(bool flag) { emit_signal("signUp", flag); }

void Server2ClientProxy::requestSignupRewardOk7() {
  emit_signal("requestSignupRewardOk7");
}

void Server2ClientProxy::requestSignupRewardOk14() {
  emit_signal("requestSignupRewardOk14");
}

void Server2ClientProxy::requestSignupRewardOk28() {
  emit_signal("requestSignupRewardOk28");
}

void Server2ClientProxy::sycnDoubleExpTime(bool isFlag, float times) {
  emit_signal("sycnDoubleExpTime", isFlag, times);
}

void Server2ClientProxy::sycnStates(TypedArray<COM_State> states) {
  emit_signal("sycnStates", states);
}

void Server2ClientProxy::requestpvprankOK(TypedArray<COM_ContactInfo> infos) {
  emit_signal("requestpvprankOK", infos);
}

void Server2ClientProxy::syncMyJJCTeamMember() {
  emit_signal("syncMyJJCTeamMember");
}

void Server2ClientProxy::startMatchingOK() { emit_signal("startMatchingOK"); }

void Server2ClientProxy::stopMatchingOK(float times) {
  emit_signal("stopMatchingOK", times);
}

void Server2ClientProxy::updatePvpJJCinfo(Ref<COM_PlayerVsPlayer> info) {
  emit_signal("updatePvpJJCinfo", info);
}

void Server2ClientProxy::exitPvpJJCOk() { emit_signal("exitPvpJJCOk"); }

void Server2ClientProxy::syncEnemyPvpJJCPlayerInfo(
    Ref<COM_SimpleInformation> info) {
  emit_signal("syncEnemyPvpJJCPlayerInfo", info);
}

void Server2ClientProxy::syncEnemyPvpJJCTeamInfo(
    TypedArray<COM_SimpleInformation> infos, uint32_t teamID_) {
  emit_signal("syncEnemyPvpJJCTeamInfo", infos, teamID_);
}

void Server2ClientProxy::openWarriorchooseUI() {
  emit_signal("openWarriorchooseUI");
}

void Server2ClientProxy::warriorStartOK() { emit_signal("warriorStartOK"); }

void Server2ClientProxy::warriorStopOK() { emit_signal("warriorStopOK"); }

void Server2ClientProxy::syncWarriorEnemyTeamInfo(
    TypedArray<COM_SimpleInformation> infos, uint32_t teamID_) {
  emit_signal("syncWarriorEnemyTeamInfo", infos, teamID_);
}

void Server2ClientProxy::appendMail(TypedArray<COM_Mail> mails) {
  emit_signal("appendMail", mails);
}

void Server2ClientProxy::delMail(int32_t mailId) {
  emit_signal("delMail", mailId);
}

void Server2ClientProxy::updateMailOk(Ref<COM_Mail> mail) {
  emit_signal("updateMailOk", mail);
}

void Server2ClientProxy::boardcastNotice(String content, bool isGm) {
  emit_signal("boardcastNotice", content, isGm);
}

void Server2ClientProxy::createGuildOK() { emit_signal("createGuildOK"); }

void Server2ClientProxy::delGuildOK() { emit_signal("delGuildOK"); }

void Server2ClientProxy::leaveGuildOk(String who, bool isKick) {
  emit_signal("leaveGuildOk", who, isKick);
}

void Server2ClientProxy::initGuildData(Ref<COM_Guild> guild) {
  emit_signal("initGuildData", guild);
}

void Server2ClientProxy::initGuildMemberList(
    TypedArray<COM_GuildMember> member) {
  emit_signal("initGuildMemberList", member);
}

void Server2ClientProxy::modifyGuildMemberList(Ref<COM_GuildMember> member,
                                               uint16_t flag) {
  emit_signal("modifyGuildMemberList", member, flag);
}

void Server2ClientProxy::modifyGuildList(Ref<COM_GuildViewerData> data,
                                         uint16_t flag) {
  emit_signal("modifyGuildList", data, flag);
}

void Server2ClientProxy::queryGuildListResult(
    int16_t page, int16_t pageNum, TypedArray<COM_GuildViewerData> guildList) {
  emit_signal("queryGuildListResult", page, pageNum, guildList);
}

void Server2ClientProxy::inviteGuild(String sendName, String guildName) {
  emit_signal("inviteGuild", sendName, guildName);
}

void Server2ClientProxy::updateGuildShopItems(
    TypedArray<COM_GuildShopItem> items) {
  emit_signal("updateGuildShopItems", items);
}

void Server2ClientProxy::updateGuildBuilding(uint16_t type,
                                             Ref<COM_GuildBuilding> building) {
  emit_signal("updateGuildBuilding", type, building);
}

void Server2ClientProxy::updateGuildMyMember(Ref<COM_GuildMember> member) {
  emit_signal("updateGuildMyMember", member);
}

void Server2ClientProxy::levelupGuildSkillOk(Ref<COM_Skill> skInst) {
  emit_signal("levelupGuildSkillOk", skInst);
}

void Server2ClientProxy::presentGuildItemOk(int32_t val) {
  emit_signal("presentGuildItemOk", val);
}

void Server2ClientProxy::progenitusAddExpOk(Ref<COM_GuildProgen> mInst) {
  emit_signal("progenitusAddExpOk", mInst);
}

void Server2ClientProxy::setProgenitusPositionOk(
    TypedArray<int32_t> positions) {
  emit_signal("setProgenitusPositionOk", positions);
}

void Server2ClientProxy::updateGuildFundz(int32_t val) {
  emit_signal("updateGuildFundz", val);
}

void Server2ClientProxy::updateGuildMemberContribution(int32_t val) {
  emit_signal("updateGuildMemberContribution", val);
}

void Server2ClientProxy::openGuildBattle(String otherName, int32_t playerNum,
                                         int32_t level, bool isLeft,
                                         int32_t lstime) {
  emit_signal("openGuildBattle", otherName, playerNum, level, isLeft, lstime);
}

void Server2ClientProxy::startGuildBattle(String otherName, int32_t otherCon,
                                          int32_t selfCon) {
  emit_signal("startGuildBattle", otherName, otherCon, selfCon);
}

void Server2ClientProxy::closeGuildBattle(bool isWinner) {
  emit_signal("closeGuildBattle", isWinner);
}

void Server2ClientProxy::syncGuildBattleWinCount(int32_t myWin,
                                                 int32_t otherWin) {
  emit_signal("syncGuildBattleWinCount", myWin, otherWin);
}

void Server2ClientProxy::initMySelling(TypedArray<COM_SellItem> items) {
  emit_signal("initMySelling", items);
}

void Server2ClientProxy::initMySelled(TypedArray<COM_SelledItem> items) {
  emit_signal("initMySelled", items);
}

void Server2ClientProxy::fetchSellingOk(TypedArray<COM_SellItem> items,
                                        int32_t total) {
  emit_signal("fetchSellingOk", items, total);
}

void Server2ClientProxy::fetchSellingOk2(TypedArray<COM_SellItem> items,
                                         int32_t total) {
  emit_signal("fetchSellingOk2", items, total);
}

void Server2ClientProxy::sellingOk(Ref<COM_SellItem> item) {
  emit_signal("sellingOk", item);
}

void Server2ClientProxy::selledOk(Ref<COM_SelledItem> item) {
  emit_signal("selledOk", item);
}

void Server2ClientProxy::unsellingOk(int32_t sellid) {
  emit_signal("unsellingOk", sellid);
}

void Server2ClientProxy::redemptionSpreeOk() {
  emit_signal("redemptionSpreeOk");
}

void Server2ClientProxy::insertState(Ref<COM_State> st) {
  emit_signal("insertState", st);
}

void Server2ClientProxy::updattState(Ref<COM_State> st) {
  emit_signal("updattState", st);
}

void Server2ClientProxy::removeState(uint32_t stid) {
  emit_signal("removeState", stid);
}

void Server2ClientProxy::requestFixItemOk(Ref<COM_Item> item) {
  emit_signal("requestFixItemOk", item);
}

void Server2ClientProxy::makeDebirsItemOK() { emit_signal("makeDebirsItemOK"); }

void Server2ClientProxy::updateMagicItem(int32_t level, int32_t exp) {
  emit_signal("updateMagicItem", level, exp);
}

void Server2ClientProxy::changeMagicJobOk(uint16_t job) {
  emit_signal("changeMagicJobOk", job);
}

void Server2ClientProxy::magicItemTupoOk(int32_t level) {
  emit_signal("magicItemTupoOk", level);
}

void Server2ClientProxy::zhuanpanOK(TypedArray<uint32_t> pond) {
  emit_signal("zhuanpanOK", pond);
}

void Server2ClientProxy::updateZhuanpanNotice(Ref<COM_Zhuanpan> zhuanp) {
  emit_signal("updateZhuanpanNotice", zhuanp);
}

void Server2ClientProxy::sycnZhuanpanData(Ref<COM_ZhuanpanData> data) {
  emit_signal("sycnZhuanpanData", data);
}

void Server2ClientProxy::copynonum(String name) {
  emit_signal("copynonum", name);
}

void Server2ClientProxy::sceneFilterOk(TypedArray<uint16_t> sfType) {
  emit_signal("sceneFilterOk", sfType);
}

void Server2ClientProxy::wishingOK() { emit_signal("wishingOK"); }

void Server2ClientProxy::shareWishOK(Ref<COM_Wish> wish) {
  emit_signal("shareWishOK", wish);
}

void Server2ClientProxy::leaderCloseDialogOk() {
  emit_signal("leaderCloseDialogOk");
}

void Server2ClientProxy::startOnlineTime() { emit_signal("startOnlineTime"); }

void Server2ClientProxy::requestOnlineTimeRewardOK(uint32_t index) {
  emit_signal("requestOnlineTimeRewardOK", index);
}

void Server2ClientProxy::sycnVipflag(bool flag) {
  emit_signal("sycnVipflag", flag);
}

void Server2ClientProxy::buyFundOK(bool flag) {
  emit_signal("buyFundOK", flag);
}

void Server2ClientProxy::requestFundRewardOK(uint32_t level) {
  emit_signal("requestFundRewardOK", level);
}

void Server2ClientProxy::firstRechargeOK(bool isFlag) {
  emit_signal("firstRechargeOK", isFlag);
}

void Server2ClientProxy::firstRechargeGiftOK(bool isFlag) {
  emit_signal("firstRechargeGiftOK", isFlag);
}

void Server2ClientProxy::agencyActivity(uint16_t type, bool isFlag) {
  emit_signal("agencyActivity", type, isFlag);
}

void Server2ClientProxy::updateFestival(Ref<COM_ADLoginTotal> festival) {
  emit_signal("updateFestival", festival);
}

void Server2ClientProxy::updateSelfRecharge(Ref<COM_ADChargeTotal> val) {
  emit_signal("updateSelfRecharge", val);
}

void Server2ClientProxy::updateSysRecharge(Ref<COM_ADChargeTotal> val) {
  emit_signal("updateSysRecharge", val);
}

void Server2ClientProxy::updateSelfDiscountStore(Ref<COM_ADDiscountStore> val) {
  emit_signal("updateSelfDiscountStore", val);
}

void Server2ClientProxy::updateSysDiscountStore(Ref<COM_ADDiscountStore> val) {
  emit_signal("updateSysDiscountStore", val);
}

void Server2ClientProxy::updateSelfOnceRecharge(Ref<COM_ADChargeEvery> val) {
  emit_signal("updateSelfOnceRecharge", val);
}

void Server2ClientProxy::updateSysOnceRecharge(Ref<COM_ADChargeEvery> val) {
  emit_signal("updateSysOnceRecharge", val);
}

void Server2ClientProxy::openCardOK(Ref<COM_ADCardsContent> data) {
  emit_signal("openCardOK", data);
}

void Server2ClientProxy::resetCardOK() { emit_signal("resetCardOK"); }

void Server2ClientProxy::sycnHotRole(Ref<COM_ADHotRole> data) {
  emit_signal("sycnHotRole", data);
}

void Server2ClientProxy::hotRoleBuyOk(uint16_t buyNum) {
  emit_signal("hotRoleBuyOk", buyNum);
}

void Server2ClientProxy::updateSevenday(Ref<COM_Sevenday> data) {
  emit_signal("updateSevenday", data);
}

void Server2ClientProxy::updateEmployeeActivity(Ref<COM_ADEmployeeTotal> data) {
  emit_signal("updateEmployeeActivity", data);
}

void Server2ClientProxy::updateMinGiftActivity(Ref<COM_ADGiftBag> data) {
  emit_signal("updateMinGiftActivity", data);
}

void Server2ClientProxy::updateIntegralShop(Ref<COM_IntegralData> data) {
  emit_signal("updateIntegralShop", data);
}

void Server2ClientProxy::updateShowBaby(uint32_t playerId,
                                        uint32_t showBabyTableId,
                                        String showBabyName) {
  emit_signal("updateShowBaby", playerId, showBabyTableId, showBabyName);
}

void Server2ClientProxy::updateMySelfRecharge(Ref<COM_ADChargeTotal> val) {
  emit_signal("updateMySelfRecharge", val);
}

void Server2ClientProxy::verificationSMSOk(String phoneNumber) {
  emit_signal("verificationSMSOk", phoneNumber);
}

void Server2ClientProxy::requestLevelGiftOK(int32_t level) {
  emit_signal("requestLevelGiftOK", level);
}

void Server2ClientProxy::sycnConvertExp(int32_t val) {
  emit_signal("sycnConvertExp", val);
}

void Server2ClientProxy::wearFuwenOk(Ref<COM_Item> inst) {
  emit_signal("wearFuwenOk", inst);
}

void Server2ClientProxy::takeoffFuwenOk(int32_t slot) {
  emit_signal("takeoffFuwenOk", slot);
}

void Server2ClientProxy::compFuwenOk() { emit_signal("compFuwenOk"); }

void Server2ClientProxy::requestEmployeeQuestOk(
    TypedArray<COM_EmployeeQuestInst> questList) {
  emit_signal("requestEmployeeQuestOk", questList);
}

void Server2ClientProxy::acceptEmployeeQuestOk(
    Ref<COM_EmployeeQuestInst> inst) {
  emit_signal("acceptEmployeeQuestOk", inst);
}

void Server2ClientProxy::submitEmployeeQuestOk(int32_t questId,
                                               bool isSuccess) {
  emit_signal("submitEmployeeQuestOk", questId, isSuccess);
}

void Server2ClientProxy::sycnCrystal(Ref<COM_CrystalData> data) {
  emit_signal("sycnCrystal", data);
}

void Server2ClientProxy::crystalUpLeveResult(bool isOK) {
  emit_signal("crystalUpLeveResult", isOK);
}

void Server2ClientProxy::resetCrystalPropOK() {
  emit_signal("resetCrystalPropOK");
}

void Server2ClientProxy::sycnCourseGift(TypedArray<COM_CourseGift> data) {
  emit_signal("sycnCourseGift", data);
}

void Server2ClientProxy::orderOk(String orderId, int32_t shopId) {
  emit_signal("orderOk", orderId, shopId);
}

void Server2ClientProxy::updateRandSubmitQuestCount(int32_t submitCount) {
  emit_signal("updateRandSubmitQuestCount", submitCount);
}

void Server2ClientProxy::updateTeamMember(int32_t playerId, bool isMember) {
  emit_signal("updateTeamMember", playerId, isMember);
}

void Server2ClientProxy::_bind_methods() {
  ADD_SIGNAL(MethodInfo("pong"));
  ADD_SIGNAL(MethodInfo("errorno", PropertyInfo(Variant::INT, "e")));
  ADD_SIGNAL(MethodInfo("teamerrorno", PropertyInfo(Variant::STRING, "name"),
                        PropertyInfo(Variant::INT, "e")));
  ADD_SIGNAL(
      MethodInfo("reconnection", PropertyInfo(Variant::OBJECT, "recInfo")));
  ADD_SIGNAL(MethodInfo("sessionfailed"));
  ADD_SIGNAL(MethodInfo("loginok", PropertyInfo(Variant::STRING, "sessionkey"),
                        PropertyInfo(Variant::ARRAY, "players")));
  ADD_SIGNAL(MethodInfo("logoutOk"));
  ADD_SIGNAL(
      MethodInfo("createPlayerOk", PropertyInfo(Variant::OBJECT, "player")));
  ADD_SIGNAL(
      MethodInfo("deletePlayerOk", PropertyInfo(Variant::STRING, "name")));
  ADD_SIGNAL(MethodInfo("enterGameOk", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("initBabies", PropertyInfo(Variant::ARRAY, "insts")));
  ADD_SIGNAL(MethodInfo("initEmployees", PropertyInfo(Variant::ARRAY, "insts"),
                        PropertyInfo(Variant::BOOL, "isFlag")));
  ADD_SIGNAL(
      MethodInfo("initEmpBattleGroup", PropertyInfo(Variant::OBJECT, "bep")));
  ADD_SIGNAL(MethodInfo("initNpc", PropertyInfo(Variant::INT, "npcList")));
  ADD_SIGNAL(
      MethodInfo("initAchievement", PropertyInfo(Variant::ARRAY, "actlist")));
  ADD_SIGNAL(MethodInfo("initGather", PropertyInfo(Variant::INT, "allnum"),
                        PropertyInfo(Variant::ARRAY, "gathers")));
  ADD_SIGNAL(
      MethodInfo("initcompound", PropertyInfo(Variant::INT, "compounds")));
  ADD_SIGNAL(MethodInfo("addBaby", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("refreshBaby", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("delBabyOK", PropertyInfo(Variant::INT, "babyInstId")));
  ADD_SIGNAL(MethodInfo("changeBabyNameOK",
                        PropertyInfo(Variant::INT, "babyId"),
                        PropertyInfo(Variant::STRING, "name")));
  ADD_SIGNAL(MethodInfo("remouldBabyOK", PropertyInfo(Variant::INT, "instid")));
  ADD_SIGNAL(MethodInfo("intensifyBabyOK", PropertyInfo(Variant::INT, "babyid"),
                        PropertyInfo(Variant::INT, "intensifyLevel")));
  ADD_SIGNAL(MethodInfo("learnSkillOk", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("forgetSkillOk", PropertyInfo(Variant::INT, "skid")));
  ADD_SIGNAL(MethodInfo("addSkillExp", PropertyInfo(Variant::INT, "skid"),
                        PropertyInfo(Variant::INT, "uExp"),
                        PropertyInfo(Variant::INT, "flag")));
  ADD_SIGNAL(MethodInfo("babyLearnSkillOK",
                        PropertyInfo(Variant::INT, "instId"),
                        PropertyInfo(Variant::INT, "newSkId")));
  ADD_SIGNAL(MethodInfo("skillLevelUp", PropertyInfo(Variant::INT, "instId"),
                        PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("joinScene", PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(
      MethodInfo("joinCopySceneOK", PropertyInfo(Variant::INT, "secneid")));
  ADD_SIGNAL(MethodInfo("initCopyNums"));
  ADD_SIGNAL(MethodInfo("addToScene", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("delFormScene", PropertyInfo(Variant::INT, "instId")));
  ADD_SIGNAL(MethodInfo("move2", PropertyInfo(Variant::INT, "instId"),
                        PropertyInfo(Variant::OBJECT, "pos")));
  ADD_SIGNAL(MethodInfo("cantMove"));
  ADD_SIGNAL(MethodInfo("querySimplePlayerInstOk",
                        PropertyInfo(Variant::OBJECT, "player")));
  ADD_SIGNAL(MethodInfo("transfor2", PropertyInfo(Variant::INT, "instId"),
                        PropertyInfo(Variant::OBJECT, "pos")));
  ADD_SIGNAL(MethodInfo("openScene", PropertyInfo(Variant::INT, "sceneId")));
  ADD_SIGNAL(
      MethodInfo("autoBattleResult", PropertyInfo(Variant::BOOL, "isOk")));
  ADD_SIGNAL(MethodInfo("talked2Npc", PropertyInfo(Variant::INT, "npcId")));
  ADD_SIGNAL(
      MethodInfo("talked2Player", PropertyInfo(Variant::INT, "playerId")));
  ADD_SIGNAL(MethodInfo("useItemOk", PropertyInfo(Variant::INT, "itemId"),
                        PropertyInfo(Variant::INT, "stack")));
  ADD_SIGNAL(MethodInfo("syncBattleStatus",
                        PropertyInfo(Variant::INT, "playerId"),
                        PropertyInfo(Variant::BOOL, "inBattle")));
  ADD_SIGNAL(
      MethodInfo("enterBattleOk", PropertyInfo(Variant::OBJECT, "initBattle")));
  ADD_SIGNAL(MethodInfo("exitBattleOk", PropertyInfo(Variant::INT, "bjt"),
                        PropertyInfo(Variant::OBJECT, "init")));
  ADD_SIGNAL(MethodInfo("syncOrderOk", PropertyInfo(Variant::INT, "uid")));
  ADD_SIGNAL(MethodInfo("syncOrderOkEX"));
  ADD_SIGNAL(MethodInfo("syncOneTurnAction",
                        PropertyInfo(Variant::OBJECT, "reports")));
  ADD_SIGNAL(MethodInfo("syncProperties", PropertyInfo(Variant::INT, "guid"),
                        PropertyInfo(Variant::ARRAY, "props")));
  ADD_SIGNAL(MethodInfo("receiveChat", PropertyInfo(Variant::OBJECT, "info"),
                        PropertyInfo(Variant::OBJECT, "myinfo")));
  ADD_SIGNAL(MethodInfo("requestAudioOk", PropertyInfo(Variant::INT, "audioId"),
                        PropertyInfo(Variant::INT, "content")));
  ADD_SIGNAL(MethodInfo("publishItemInstRes",
                        PropertyInfo(Variant::OBJECT, "info"),
                        PropertyInfo(Variant::INT, "type")));
  ADD_SIGNAL(
      MethodInfo("queryItemInstRes", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("publishBabyInstRes",
                        PropertyInfo(Variant::OBJECT, "info"),
                        PropertyInfo(Variant::INT, "type")));
  ADD_SIGNAL(
      MethodInfo("queryBabyInstRes", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("setNoTalkTime", PropertyInfo(Variant::FLOAT, "t")));
  ADD_SIGNAL(MethodInfo("addNpc", PropertyInfo(Variant::INT, "npcList")));
  ADD_SIGNAL(MethodInfo("delNpc", PropertyInfo(Variant::INT, "npcList")));
  ADD_SIGNAL(MethodInfo("setTeamLeader", PropertyInfo(Variant::INT, "playerId"),
                        PropertyInfo(Variant::BOOL, "isLeader")));
  ADD_SIGNAL(MethodInfo("initBag", PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(MethodInfo("addBagItem", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("delBagItem", PropertyInfo(Variant::INT, "slot")));
  ADD_SIGNAL(
      MethodInfo("updateBagItem", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(
      MethodInfo("depositItemOK", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("getoutItemOK", PropertyInfo(Variant::INT, "slot")));
  ADD_SIGNAL(
      MethodInfo("depositBabyOK", PropertyInfo(Variant::OBJECT, "baby")));
  ADD_SIGNAL(MethodInfo("getoutBabyOK", PropertyInfo(Variant::INT, "slot")));
  ADD_SIGNAL(
      MethodInfo("sortItemStorageOK", PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(
      MethodInfo("sortBabyStorageOK", PropertyInfo(Variant::INT, "babys")));
  ADD_SIGNAL(MethodInfo("initItemStorage",
                        PropertyInfo(Variant::INT, "gridNum"),
                        PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(MethodInfo("initBabyStorage",
                        PropertyInfo(Variant::INT, "gridNum"),
                        PropertyInfo(Variant::ARRAY, "babys")));
  ADD_SIGNAL(MethodInfo("openStorageGrid", PropertyInfo(Variant::INT, "tp"),
                        PropertyInfo(Variant::INT, "gridNum")));
  ADD_SIGNAL(
      MethodInfo("delStorageBabyOK", PropertyInfo(Variant::INT, "slot")));
  ADD_SIGNAL(
      MethodInfo("initPlayerEquips", PropertyInfo(Variant::ARRAY, "equips")));
  ADD_SIGNAL(MethodInfo("wearEquipmentOk", PropertyInfo(Variant::INT, "target"),
                        PropertyInfo(Variant::OBJECT, "equip")));
  ADD_SIGNAL(MethodInfo("scenePlayerWearEquipment",
                        PropertyInfo(Variant::INT, "target"),
                        PropertyInfo(Variant::INT, "itemId")));
  ADD_SIGNAL(MethodInfo("delEquipmentOk", PropertyInfo(Variant::INT, "target"),
                        PropertyInfo(Variant::INT, "itemInstId")));
  ADD_SIGNAL(MethodInfo("scenePlayerDoffEquipment",
                        PropertyInfo(Variant::INT, "target"),
                        PropertyInfo(Variant::INT, "itemId")));
  ADD_SIGNAL(MethodInfo("sortBagItemOk"));
  ADD_SIGNAL(MethodInfo("jointLobbyOk", PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("exitLobbyOk"));
  ADD_SIGNAL(
      MethodInfo("syncDelLobbyTeam", PropertyInfo(Variant::INT, "teamId")));
  ADD_SIGNAL(
      MethodInfo("syncUpdateLobbyTeam", PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(
      MethodInfo("syncAddLobbyTeam", PropertyInfo(Variant::OBJECT, "team")));
  ADD_SIGNAL(MethodInfo("createTeamOk", PropertyInfo(Variant::OBJECT, "team")));
  ADD_SIGNAL(MethodInfo("changeTeamOk", PropertyInfo(Variant::OBJECT, "team")));
  ADD_SIGNAL(MethodInfo("joinTeamOk", PropertyInfo(Variant::OBJECT, "team")));
  ADD_SIGNAL(
      MethodInfo("addTeamMember", PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(MethodInfo("delTeamMember", PropertyInfo(Variant::INT, "instId")));
  ADD_SIGNAL(
      MethodInfo("changeTeamLeaderOk", PropertyInfo(Variant::INT, "uuid")));
  ADD_SIGNAL(MethodInfo("exitTeamOk", PropertyInfo(Variant::BOOL, "iskick")));
  ADD_SIGNAL(MethodInfo("updateTeam", PropertyInfo(Variant::OBJECT, "team")));
  ADD_SIGNAL(
      MethodInfo("joinTeamRoomOK", PropertyInfo(Variant::OBJECT, "team")));
  ADD_SIGNAL(MethodInfo("inviteJoinTeam", PropertyInfo(Variant::INT, "teamId"),
                        PropertyInfo(Variant::STRING, "name")));
  ADD_SIGNAL(MethodInfo("syncTeamDirtyProp", PropertyInfo(Variant::INT, "guid"),
                        PropertyInfo(Variant::ARRAY, "props")));
  ADD_SIGNAL(MethodInfo("leaveTeamOk", PropertyInfo(Variant::INT, "playerId")));
  ADD_SIGNAL(MethodInfo("backTeamOK", PropertyInfo(Variant::INT, "playerId")));
  ADD_SIGNAL(MethodInfo("teamCallMemberBack"));
  ADD_SIGNAL(
      MethodInfo("refuseBackTeamOk", PropertyInfo(Variant::INT, "playerId")));
  ADD_SIGNAL(MethodInfo("requestJoinTeamTranspond",
                        PropertyInfo(Variant::STRING, "reqName")));
  ADD_SIGNAL(
      MethodInfo("drawLotteryBoxRep", PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(
      MethodInfo("addEmployee", PropertyInfo(Variant::OBJECT, "employee")));
  ADD_SIGNAL(MethodInfo("battleEmployee", PropertyInfo(Variant::INT, "empId"),
                        PropertyInfo(Variant::INT, "group"),
                        PropertyInfo(Variant::BOOL, "forbattle")));
  ADD_SIGNAL(MethodInfo("changeEmpBattleGroupOK",
                        PropertyInfo(Variant::INT, "group")));
  ADD_SIGNAL(MethodInfo("evolveOK", PropertyInfo(Variant::INT, "guid"),
                        PropertyInfo(Variant::INT, "qc")));
  ADD_SIGNAL(MethodInfo("upStarOK", PropertyInfo(Variant::INT, "guid"),
                        PropertyInfo(Variant::INT, "star"),
                        PropertyInfo(Variant::OBJECT, "sk")));
  ADD_SIGNAL(
      MethodInfo("delEmployeeOK", PropertyInfo(Variant::INT, "instids")));
  ADD_SIGNAL(MethodInfo("sycnEmployeeSoul", PropertyInfo(Variant::INT, "guid"),
                        PropertyInfo(Variant::INT, "soulNum")));
  ADD_SIGNAL(MethodInfo("initQuest", PropertyInfo(Variant::ARRAY, "qlist"),
                        PropertyInfo(Variant::INT, "clist")));
  ADD_SIGNAL(
      MethodInfo("acceptQuestOk", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(
      MethodInfo("submitQuestOk", PropertyInfo(Variant::INT, "questId")));
  ADD_SIGNAL(
      MethodInfo("giveupQuestOk", PropertyInfo(Variant::INT, "questId")));
  ADD_SIGNAL(
      MethodInfo("updateQuestInst", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("requestContactInfoOk",
                        PropertyInfo(Variant::OBJECT, "contact")));
  ADD_SIGNAL(MethodInfo("addFriendOK", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("delFriendOK", PropertyInfo(Variant::INT, "instId")));
  ADD_SIGNAL(
      MethodInfo("addBlacklistOK", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(
      MethodInfo("delBlacklistOK", PropertyInfo(Variant::INT, "instId")));
  ADD_SIGNAL(MethodInfo("findFriendFail"));
  ADD_SIGNAL(
      MethodInfo("referrFriendOK", PropertyInfo(Variant::ARRAY, "insts")));
  ADD_SIGNAL(
      MethodInfo("requestFriendListOK", PropertyInfo(Variant::ARRAY, "insts")));
  ADD_SIGNAL(MethodInfo("lotteryOk", PropertyInfo(Variant::INT, "lotteryId"),
                        PropertyInfo(Variant::ARRAY, "dropItem")));
  ADD_SIGNAL(
      MethodInfo("openGatherOK", PropertyInfo(Variant::OBJECT, "gather")));
  ADD_SIGNAL(MethodInfo("miningOk", PropertyInfo(Variant::ARRAY, "items"),
                        PropertyInfo(Variant::OBJECT, "gather"),
                        PropertyInfo(Variant::INT, "gatherNum")));
  ADD_SIGNAL(
      MethodInfo("openCompound", PropertyInfo(Variant::INT, "compoundId")));
  ADD_SIGNAL(
      MethodInfo("compoundItemOk", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("openBagGridOk", PropertyInfo(Variant::INT, "num")));
  ADD_SIGNAL(
      MethodInfo("requestChallengeOK", PropertyInfo(Variant::BOOL, "isOK")));
  ADD_SIGNAL(MethodInfo("requestMySelfJJCDataOK",
                        PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(
      MethodInfo("requestRivalOK", PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("rivalTimeOK"));
  ADD_SIGNAL(MethodInfo("checkMsgOK", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("requestMyAllbattleMsgOK",
                        PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(
      MethodInfo("myBattleMsgOK", PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(MethodInfo("requestJJCRankOK",
                        PropertyInfo(Variant::INT, "myRank"),
                        PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("requestLevelRankOK",
                        PropertyInfo(Variant::INT, "myRank"),
                        PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("requestBabyRankOK",
                        PropertyInfo(Variant::INT, "myRank"),
                        PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("requestEmpRankOK",
                        PropertyInfo(Variant::INT, "myRank"),
                        PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("requestPlayerFFRankOK",
                        PropertyInfo(Variant::INT, "myRank"),
                        PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("queryOnlinePlayerOK",
                        PropertyInfo(Variant::BOOL, "isOnline")));
  ADD_SIGNAL(
      MethodInfo("queryPlayerOK", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("queryBabyOK", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(
      MethodInfo("queryEmployeeOK", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("initGuide", PropertyInfo(Variant::INT, "guideMask")));
  ADD_SIGNAL(MethodInfo("buyShopItemOk", PropertyInfo(Variant::INT, "id")));
  ADD_SIGNAL(MethodInfo("addPlayerTitle", PropertyInfo(Variant::INT, "title")));
  ADD_SIGNAL(MethodInfo("delPlayerTitle", PropertyInfo(Variant::INT, "title")));
  ADD_SIGNAL(MethodInfo("requestOpenBuyBox",
                        PropertyInfo(Variant::FLOAT, "greenTime"),
                        PropertyInfo(Variant::FLOAT, "blueTime"),
                        PropertyInfo(Variant::INT, "greenFreeNum")));
  ADD_SIGNAL(MethodInfo("requestGreenBoxTimeOk"));
  ADD_SIGNAL(MethodInfo("requestBlueBoxTimeOk"));
  ADD_SIGNAL(MethodInfo("updateAchievementinfo",
                        PropertyInfo(Variant::OBJECT, "achs")));
  ADD_SIGNAL(
      MethodInfo("syncOpenSystemFlag", PropertyInfo(Variant::INT, "flag")));
  ADD_SIGNAL(
      MethodInfo("requestActivityRewardOK", PropertyInfo(Variant::INT, "ar")));
  ADD_SIGNAL(
      MethodInfo("syncActivity", PropertyInfo(Variant::OBJECT, "table")));
  ADD_SIGNAL(MethodInfo("updateActivityStatus",
                        PropertyInfo(Variant::INT, "type"),
                        PropertyInfo(Variant::BOOL, "open")));
  ADD_SIGNAL(MethodInfo("updateActivityCounter",
                        PropertyInfo(Variant::INT, "type"),
                        PropertyInfo(Variant::INT, "counter"),
                        PropertyInfo(Variant::INT, "reward")));
  ADD_SIGNAL(MethodInfo("syncExam", PropertyInfo(Variant::OBJECT, "exam")));
  ADD_SIGNAL(
      MethodInfo("syncExamAnswer", PropertyInfo(Variant::OBJECT, "answer")));
  ADD_SIGNAL(
      MethodInfo("petActivityNoNum", PropertyInfo(Variant::STRING, "name")));
  ADD_SIGNAL(
      MethodInfo("syncHundredInfo", PropertyInfo(Variant::OBJECT, "hb")));
  ADD_SIGNAL(MethodInfo("initSignUp", PropertyInfo(Variant::INT, "info"),
                        PropertyInfo(Variant::INT, "process"),
                        PropertyInfo(Variant::BOOL, "sign7"),
                        PropertyInfo(Variant::BOOL, "sign14"),
                        PropertyInfo(Variant::BOOL, "sign28")));
  ADD_SIGNAL(MethodInfo("signUp", PropertyInfo(Variant::BOOL, "flag")));
  ADD_SIGNAL(MethodInfo("requestSignupRewardOk7"));
  ADD_SIGNAL(MethodInfo("requestSignupRewardOk14"));
  ADD_SIGNAL(MethodInfo("requestSignupRewardOk28"));
  ADD_SIGNAL(MethodInfo("sycnDoubleExpTime",
                        PropertyInfo(Variant::BOOL, "isFlag"),
                        PropertyInfo(Variant::FLOAT, "times")));
  ADD_SIGNAL(MethodInfo("sycnStates", PropertyInfo(Variant::ARRAY, "states")));
  ADD_SIGNAL(
      MethodInfo("requestpvprankOK", PropertyInfo(Variant::ARRAY, "infos")));
  ADD_SIGNAL(MethodInfo("syncMyJJCTeamMember"));
  ADD_SIGNAL(MethodInfo("startMatchingOK"));
  ADD_SIGNAL(
      MethodInfo("stopMatchingOK", PropertyInfo(Variant::FLOAT, "times")));
  ADD_SIGNAL(
      MethodInfo("updatePvpJJCinfo", PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(MethodInfo("exitPvpJJCOk"));
  ADD_SIGNAL(MethodInfo("syncEnemyPvpJJCPlayerInfo",
                        PropertyInfo(Variant::OBJECT, "info")));
  ADD_SIGNAL(MethodInfo("syncEnemyPvpJJCTeamInfo",
                        PropertyInfo(Variant::ARRAY, "infos"),
                        PropertyInfo(Variant::INT, "teamID_")));
  ADD_SIGNAL(MethodInfo("openWarriorchooseUI"));
  ADD_SIGNAL(MethodInfo("warriorStartOK"));
  ADD_SIGNAL(MethodInfo("warriorStopOK"));
  ADD_SIGNAL(MethodInfo("syncWarriorEnemyTeamInfo",
                        PropertyInfo(Variant::ARRAY, "infos"),
                        PropertyInfo(Variant::INT, "teamID_")));
  ADD_SIGNAL(MethodInfo("appendMail", PropertyInfo(Variant::ARRAY, "mails")));
  ADD_SIGNAL(MethodInfo("delMail", PropertyInfo(Variant::INT, "mailId")));
  ADD_SIGNAL(MethodInfo("updateMailOk", PropertyInfo(Variant::OBJECT, "mail")));
  ADD_SIGNAL(MethodInfo("boardcastNotice",
                        PropertyInfo(Variant::STRING, "content"),
                        PropertyInfo(Variant::BOOL, "isGm")));
  ADD_SIGNAL(MethodInfo("createGuildOK"));
  ADD_SIGNAL(MethodInfo("delGuildOK"));
  ADD_SIGNAL(MethodInfo("leaveGuildOk", PropertyInfo(Variant::STRING, "who"),
                        PropertyInfo(Variant::BOOL, "isKick")));
  ADD_SIGNAL(
      MethodInfo("initGuildData", PropertyInfo(Variant::OBJECT, "guild")));
  ADD_SIGNAL(MethodInfo("initGuildMemberList",
                        PropertyInfo(Variant::ARRAY, "member")));
  ADD_SIGNAL(MethodInfo("modifyGuildMemberList",
                        PropertyInfo(Variant::OBJECT, "member"),
                        PropertyInfo(Variant::INT, "flag")));
  ADD_SIGNAL(MethodInfo("modifyGuildList",
                        PropertyInfo(Variant::OBJECT, "data"),
                        PropertyInfo(Variant::INT, "flag")));
  ADD_SIGNAL(MethodInfo("queryGuildListResult",
                        PropertyInfo(Variant::INT, "page"),
                        PropertyInfo(Variant::INT, "pageNum"),
                        PropertyInfo(Variant::ARRAY, "guildList")));
  ADD_SIGNAL(MethodInfo("inviteGuild",
                        PropertyInfo(Variant::STRING, "sendName"),
                        PropertyInfo(Variant::STRING, "guildName")));
  ADD_SIGNAL(MethodInfo("updateGuildShopItems",
                        PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(MethodInfo("updateGuildBuilding",
                        PropertyInfo(Variant::INT, "type"),
                        PropertyInfo(Variant::OBJECT, "building")));
  ADD_SIGNAL(MethodInfo("updateGuildMyMember",
                        PropertyInfo(Variant::OBJECT, "member")));
  ADD_SIGNAL(MethodInfo("levelupGuildSkillOk",
                        PropertyInfo(Variant::OBJECT, "skInst")));
  ADD_SIGNAL(
      MethodInfo("presentGuildItemOk", PropertyInfo(Variant::INT, "val")));
  ADD_SIGNAL(
      MethodInfo("progenitusAddExpOk", PropertyInfo(Variant::OBJECT, "mInst")));
  ADD_SIGNAL(MethodInfo("setProgenitusPositionOk",
                        PropertyInfo(Variant::INT, "positions")));
  ADD_SIGNAL(MethodInfo("updateGuildFundz", PropertyInfo(Variant::INT, "val")));
  ADD_SIGNAL(MethodInfo("updateGuildMemberContribution",
                        PropertyInfo(Variant::INT, "val")));
  ADD_SIGNAL(MethodInfo("openGuildBattle",
                        PropertyInfo(Variant::STRING, "otherName"),
                        PropertyInfo(Variant::INT, "playerNum"),
                        PropertyInfo(Variant::INT, "level"),
                        PropertyInfo(Variant::BOOL, "isLeft"),
                        PropertyInfo(Variant::INT, "lstime")));
  ADD_SIGNAL(MethodInfo("startGuildBattle",
                        PropertyInfo(Variant::STRING, "otherName"),
                        PropertyInfo(Variant::INT, "otherCon"),
                        PropertyInfo(Variant::INT, "selfCon")));
  ADD_SIGNAL(
      MethodInfo("closeGuildBattle", PropertyInfo(Variant::BOOL, "isWinner")));
  ADD_SIGNAL(MethodInfo("syncGuildBattleWinCount",
                        PropertyInfo(Variant::INT, "myWin"),
                        PropertyInfo(Variant::INT, "otherWin")));
  ADD_SIGNAL(
      MethodInfo("initMySelling", PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(MethodInfo("initMySelled", PropertyInfo(Variant::ARRAY, "items")));
  ADD_SIGNAL(MethodInfo("fetchSellingOk", PropertyInfo(Variant::ARRAY, "items"),
                        PropertyInfo(Variant::INT, "total")));
  ADD_SIGNAL(MethodInfo("fetchSellingOk2",
                        PropertyInfo(Variant::ARRAY, "items"),
                        PropertyInfo(Variant::INT, "total")));
  ADD_SIGNAL(MethodInfo("sellingOk", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("selledOk", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("unsellingOk", PropertyInfo(Variant::INT, "sellid")));
  ADD_SIGNAL(MethodInfo("redemptionSpreeOk"));
  ADD_SIGNAL(MethodInfo("insertState", PropertyInfo(Variant::OBJECT, "st")));
  ADD_SIGNAL(MethodInfo("updattState", PropertyInfo(Variant::OBJECT, "st")));
  ADD_SIGNAL(MethodInfo("removeState", PropertyInfo(Variant::INT, "stid")));
  ADD_SIGNAL(
      MethodInfo("requestFixItemOk", PropertyInfo(Variant::OBJECT, "item")));
  ADD_SIGNAL(MethodInfo("makeDebirsItemOK"));
  ADD_SIGNAL(MethodInfo("updateMagicItem", PropertyInfo(Variant::INT, "level"),
                        PropertyInfo(Variant::INT, "exp")));
  ADD_SIGNAL(MethodInfo("changeMagicJobOk", PropertyInfo(Variant::INT, "job")));
  ADD_SIGNAL(
      MethodInfo("magicItemTupoOk", PropertyInfo(Variant::INT, "level")));
  ADD_SIGNAL(MethodInfo("zhuanpanOK", PropertyInfo(Variant::INT, "pond")));
  ADD_SIGNAL(MethodInfo("updateZhuanpanNotice",
                        PropertyInfo(Variant::OBJECT, "zhuanp")));
  ADD_SIGNAL(
      MethodInfo("sycnZhuanpanData", PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(MethodInfo("copynonum", PropertyInfo(Variant::STRING, "name")));
  ADD_SIGNAL(MethodInfo("sceneFilterOk", PropertyInfo(Variant::INT, "sfType")));
  ADD_SIGNAL(MethodInfo("wishingOK"));
  ADD_SIGNAL(MethodInfo("shareWishOK", PropertyInfo(Variant::OBJECT, "wish")));
  ADD_SIGNAL(MethodInfo("leaderCloseDialogOk"));
  ADD_SIGNAL(MethodInfo("startOnlineTime"));
  ADD_SIGNAL(MethodInfo("requestOnlineTimeRewardOK",
                        PropertyInfo(Variant::INT, "index")));
  ADD_SIGNAL(MethodInfo("sycnVipflag", PropertyInfo(Variant::BOOL, "flag")));
  ADD_SIGNAL(MethodInfo("buyFundOK", PropertyInfo(Variant::BOOL, "flag")));
  ADD_SIGNAL(
      MethodInfo("requestFundRewardOK", PropertyInfo(Variant::INT, "level")));
  ADD_SIGNAL(
      MethodInfo("firstRechargeOK", PropertyInfo(Variant::BOOL, "isFlag")));
  ADD_SIGNAL(
      MethodInfo("firstRechargeGiftOK", PropertyInfo(Variant::BOOL, "isFlag")));
  ADD_SIGNAL(MethodInfo("agencyActivity", PropertyInfo(Variant::INT, "type"),
                        PropertyInfo(Variant::BOOL, "isFlag")));
  ADD_SIGNAL(
      MethodInfo("updateFestival", PropertyInfo(Variant::INT, "festival")));
  ADD_SIGNAL(
      MethodInfo("updateSelfRecharge", PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(
      MethodInfo("updateSysRecharge", PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(MethodInfo("updateSelfDiscountStore",
                        PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(MethodInfo("updateSysDiscountStore",
                        PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(MethodInfo("updateSelfOnceRecharge",
                        PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(MethodInfo("updateSysOnceRecharge",
                        PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(MethodInfo("openCardOK", PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(MethodInfo("resetCardOK"));
  ADD_SIGNAL(MethodInfo("sycnHotRole", PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(MethodInfo("hotRoleBuyOk", PropertyInfo(Variant::INT, "buyNum")));
  ADD_SIGNAL(
      MethodInfo("updateSevenday", PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(MethodInfo("updateEmployeeActivity",
                        PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(MethodInfo("updateMinGiftActivity",
                        PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(
      MethodInfo("updateIntegralShop", PropertyInfo(Variant::INT, "data")));
  ADD_SIGNAL(MethodInfo("updateShowBaby",
                        PropertyInfo(Variant::INT, "playerId"),
                        PropertyInfo(Variant::INT, "showBabyTableId"),
                        PropertyInfo(Variant::STRING, "showBabyName")));
  ADD_SIGNAL(
      MethodInfo("updateMySelfRecharge", PropertyInfo(Variant::OBJECT, "val")));
  ADD_SIGNAL(MethodInfo("verificationSMSOk",
                        PropertyInfo(Variant::STRING, "phoneNumber")));
  ADD_SIGNAL(
      MethodInfo("requestLevelGiftOK", PropertyInfo(Variant::INT, "level")));
  ADD_SIGNAL(MethodInfo("sycnConvertExp", PropertyInfo(Variant::INT, "val")));
  ADD_SIGNAL(MethodInfo("wearFuwenOk", PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("takeoffFuwenOk", PropertyInfo(Variant::INT, "slot")));
  ADD_SIGNAL(MethodInfo("compFuwenOk"));
  ADD_SIGNAL(MethodInfo("requestEmployeeQuestOk",
                        PropertyInfo(Variant::ARRAY, "questList")));
  ADD_SIGNAL(MethodInfo("acceptEmployeeQuestOk",
                        PropertyInfo(Variant::OBJECT, "inst")));
  ADD_SIGNAL(MethodInfo("submitEmployeeQuestOk",
                        PropertyInfo(Variant::INT, "questId"),
                        PropertyInfo(Variant::BOOL, "isSuccess")));
  ADD_SIGNAL(MethodInfo("sycnCrystal", PropertyInfo(Variant::OBJECT, "data")));
  ADD_SIGNAL(
      MethodInfo("crystalUpLeveResult", PropertyInfo(Variant::BOOL, "isOK")));
  ADD_SIGNAL(MethodInfo("resetCrystalPropOK"));
  ADD_SIGNAL(
      MethodInfo("sycnCourseGift", PropertyInfo(Variant::ARRAY, "data")));
  ADD_SIGNAL(MethodInfo("orderOk", PropertyInfo(Variant::STRING, "orderId"),
                        PropertyInfo(Variant::INT, "shopId")));
  ADD_SIGNAL(MethodInfo("updateRandSubmitQuestCount",
                        PropertyInfo(Variant::INT, "submitCount")));
  ADD_SIGNAL(MethodInfo("updateTeamMember",
                        PropertyInfo(Variant::INT, "playerId"),
                        PropertyInfo(Variant::BOOL, "isMember")));
}

} // namespace godot
