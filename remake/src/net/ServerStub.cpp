#include "ServerStub.h"

namespace godot {


void ServerStub::_bind_methods() {
    ClassDB::bind_method(D_METHOD("openvip", "vl"), &ServerStub::openvip);
    ClassDB::bind_method(D_METHOD("requestPhoto"), &ServerStub::requestPhoto);
    ClassDB::bind_method(D_METHOD("ping"), &ServerStub::ping);
    ClassDB::bind_method(D_METHOD("sessionlogin", "info"), &ServerStub::sessionlogin);
    ClassDB::bind_method(D_METHOD("login", "info"), &ServerStub::login);
    ClassDB::bind_method(D_METHOD("createPlayer", "playername", "playerTmpId"), &ServerStub::createPlayer);
    ClassDB::bind_method(D_METHOD("deletePlayer", "playername"), &ServerStub::deletePlayer);
    ClassDB::bind_method(D_METHOD("enterGame", "playerInstId"), &ServerStub::enterGame);
    ClassDB::bind_method(D_METHOD("requestBag"), &ServerStub::requestBag);
    ClassDB::bind_method(D_METHOD("requestEmployees"), &ServerStub::requestEmployees);
    ClassDB::bind_method(D_METHOD("requestStorage", "tp"), &ServerStub::requestStorage);
    ClassDB::bind_method(D_METHOD("requestAchievement"), &ServerStub::requestAchievement);
    ClassDB::bind_method(D_METHOD("initminig"), &ServerStub::initminig);
    ClassDB::bind_method(D_METHOD("requestCompound"), &ServerStub::requestCompound);
    ClassDB::bind_method(D_METHOD("move", "x", "z"), &ServerStub::move);
    ClassDB::bind_method(D_METHOD("moveToNpc", "npcid"), &ServerStub::moveToNpc);
    ClassDB::bind_method(D_METHOD("moveToNpc2", "type"), &ServerStub::moveToNpc2);
    ClassDB::bind_method(D_METHOD("moveToZone", "sceneId", "zoneId"), &ServerStub::moveToZone);
    ClassDB::bind_method(D_METHOD("autoBattle"), &ServerStub::autoBattle);
    ClassDB::bind_method(D_METHOD("stopAutoBattle"), &ServerStub::stopAutoBattle);
    ClassDB::bind_method(D_METHOD("stopMove"), &ServerStub::stopMove);
    ClassDB::bind_method(D_METHOD("exitCopy"), &ServerStub::exitCopy);
    ClassDB::bind_method(D_METHOD("transforScene", "sceneId"), &ServerStub::transforScene);
    ClassDB::bind_method(D_METHOD("sceneLoaded"), &ServerStub::sceneLoaded);
    ClassDB::bind_method(D_METHOD("querySimplePlayerInst", "instId"), &ServerStub::querySimplePlayerInst);
    ClassDB::bind_method(D_METHOD("logout"), &ServerStub::logout);
    ClassDB::bind_method(D_METHOD("changProp", "guid", "props"), &ServerStub::changProp);
    ClassDB::bind_method(D_METHOD("learnSkill", "skid"), &ServerStub::learnSkill);
    ClassDB::bind_method(D_METHOD("babyLearnSkill", "instId", "oldSkId", "newSkId", "newSkLv"), &ServerStub::babyLearnSkill);
    ClassDB::bind_method(D_METHOD("forgetSkill", "skid"), &ServerStub::forgetSkill);
    ClassDB::bind_method(D_METHOD("syncOrder", "order"), &ServerStub::syncOrder);
    ClassDB::bind_method(D_METHOD("syncOrderTimeout"), &ServerStub::syncOrderTimeout);
    ClassDB::bind_method(D_METHOD("sendChat", "content", "targetName"), &ServerStub::sendChat);
    ClassDB::bind_method(D_METHOD("requestAudio", "audioId"), &ServerStub::requestAudio);
    ClassDB::bind_method(D_METHOD("publishItemInst", "type", "itemInstId", "chatType", "playerName"), &ServerStub::publishItemInst);
    ClassDB::bind_method(D_METHOD("queryItemInst", "showId"), &ServerStub::queryItemInst);
    ClassDB::bind_method(D_METHOD("publishbabyInst", "type", "babyInstId", "playerName"), &ServerStub::publishbabyInst);
    ClassDB::bind_method(D_METHOD("querybabyInst", "showId"), &ServerStub::querybabyInst);
    ClassDB::bind_method(D_METHOD("useItem", "slot", "target", "stack"), &ServerStub::useItem);
    ClassDB::bind_method(D_METHOD("wearEquipment", "target", "itemInstId"), &ServerStub::wearEquipment);
    ClassDB::bind_method(D_METHOD("delEquipment", "target", "itemInstId"), &ServerStub::delEquipment);
    ClassDB::bind_method(D_METHOD("setPlayerFront", "isFront"), &ServerStub::setPlayerFront);
    ClassDB::bind_method(D_METHOD("setBattlebaby", "babyID", "isBattle"), &ServerStub::setBattlebaby);
    ClassDB::bind_method(D_METHOD("changeBabyName", "babyID", "name"), &ServerStub::changeBabyName);
    ClassDB::bind_method(D_METHOD("intensifyBaby", "babyid"), &ServerStub::intensifyBaby);
    ClassDB::bind_method(D_METHOD("setBattleEmp", "empID", "group", "isBattle"), &ServerStub::setBattleEmp);
    ClassDB::bind_method(D_METHOD("changeEmpBattleGroup", "group"), &ServerStub::changeEmpBattleGroup);
    ClassDB::bind_method(D_METHOD("requestEvolve", "empInstId"), &ServerStub::requestEvolve);
    ClassDB::bind_method(D_METHOD("requestUpStar", "empInstId"), &ServerStub::requestUpStar);
    ClassDB::bind_method(D_METHOD("requestDelEmp", "empInstId"), &ServerStub::requestDelEmp);
    ClassDB::bind_method(D_METHOD("delEmployee", "emps"), &ServerStub::delEmployee);
    ClassDB::bind_method(D_METHOD("onekeyDelEmp"), &ServerStub::onekeyDelEmp);
    ClassDB::bind_method(D_METHOD("delEmployeeSoul", "instid", "soulNum"), &ServerStub::delEmployeeSoul);
    ClassDB::bind_method(D_METHOD("sortBagItem"), &ServerStub::sortBagItem);
    ClassDB::bind_method(D_METHOD("sellBagItem", "instId", "stack"), &ServerStub::sellBagItem);
    ClassDB::bind_method(D_METHOD("depositItemToStorage", "instid"), &ServerStub::depositItemToStorage);
    ClassDB::bind_method(D_METHOD("depositBabyToStorage", "instid"), &ServerStub::depositBabyToStorage);
    ClassDB::bind_method(D_METHOD("storageItemToBag", "instid"), &ServerStub::storageItemToBag);
    ClassDB::bind_method(D_METHOD("storageBabyToPlayer", "instid"), &ServerStub::storageBabyToPlayer);
    ClassDB::bind_method(D_METHOD("sortStorage", "tp"), &ServerStub::sortStorage);
    ClassDB::bind_method(D_METHOD("delStorageBaby", "instid"), &ServerStub::delStorageBaby);
    ClassDB::bind_method(D_METHOD("jointLobby"), &ServerStub::jointLobby);
    ClassDB::bind_method(D_METHOD("exitLobby"), &ServerStub::exitLobby);
    ClassDB::bind_method(D_METHOD("createTeam", "cti"), &ServerStub::createTeam);
    ClassDB::bind_method(D_METHOD("changeTeam", "info"), &ServerStub::changeTeam);
    ClassDB::bind_method(D_METHOD("kickTeamMember", "uuid"), &ServerStub::kickTeamMember);
    ClassDB::bind_method(D_METHOD("changeTeamLeader", "uuid"), &ServerStub::changeTeamLeader);
    ClassDB::bind_method(D_METHOD("joinTeam", "teamId", "pwd"), &ServerStub::joinTeam);
    ClassDB::bind_method(D_METHOD("exitTeam"), &ServerStub::exitTeam);
    ClassDB::bind_method(D_METHOD("changeTeamPassword", "pwd"), &ServerStub::changeTeamPassword);
    ClassDB::bind_method(D_METHOD("joinTeamRoom"), &ServerStub::joinTeamRoom);
    ClassDB::bind_method(D_METHOD("inviteTeamMember", "name"), &ServerStub::inviteTeamMember);
    ClassDB::bind_method(D_METHOD("isjoinTeam", "teamId", "isFlag"), &ServerStub::isjoinTeam);
    ClassDB::bind_method(D_METHOD("leaveTeam"), &ServerStub::leaveTeam);
    ClassDB::bind_method(D_METHOD("backTeam"), &ServerStub::backTeam);
    ClassDB::bind_method(D_METHOD("refuseBackTeam"), &ServerStub::refuseBackTeam);
    ClassDB::bind_method(D_METHOD("teamCallMember", "playerId"), &ServerStub::teamCallMember);
    ClassDB::bind_method(D_METHOD("requestJoinTeam", "targetName"), &ServerStub::requestJoinTeam);
    ClassDB::bind_method(D_METHOD("ratifyJoinTeam", "sendName"), &ServerStub::ratifyJoinTeam);
    ClassDB::bind_method(D_METHOD("drawLotteryBox", "type", "isFree"), &ServerStub::drawLotteryBox);
    ClassDB::bind_method(D_METHOD("acceptQuest", "questId"), &ServerStub::acceptQuest);
    ClassDB::bind_method(D_METHOD("submitQuest", "npcId", "questId"), &ServerStub::submitQuest);
    ClassDB::bind_method(D_METHOD("giveupQuest", "questId"), &ServerStub::giveupQuest);
    ClassDB::bind_method(D_METHOD("requestContactInfoById", "instId"), &ServerStub::requestContactInfoById);
    ClassDB::bind_method(D_METHOD("requestContactInfoByName", "instName"), &ServerStub::requestContactInfoByName);
    ClassDB::bind_method(D_METHOD("requestFriendList"), &ServerStub::requestFriendList);
    ClassDB::bind_method(D_METHOD("addFriend", "instId"), &ServerStub::addFriend);
    ClassDB::bind_method(D_METHOD("delFriend", "instId"), &ServerStub::delFriend);
    ClassDB::bind_method(D_METHOD("addBlacklist", "instId"), &ServerStub::addBlacklist);
    ClassDB::bind_method(D_METHOD("delBlacklist", "instId"), &ServerStub::delBlacklist);
    ClassDB::bind_method(D_METHOD("requestReferrFriend"), &ServerStub::requestReferrFriend);
    ClassDB::bind_method(D_METHOD("mining", "gatherId", "times"), &ServerStub::mining);
    ClassDB::bind_method(D_METHOD("compoundItem", "itemId", "gemId"), &ServerStub::compoundItem);
    ClassDB::bind_method(D_METHOD("bagItemSplit", "instId", "splitNum"), &ServerStub::bagItemSplit);
    ClassDB::bind_method(D_METHOD("requestChallenge", "name"), &ServerStub::requestChallenge);
    ClassDB::bind_method(D_METHOD("requestRival"), &ServerStub::requestRival);
    ClassDB::bind_method(D_METHOD("requestMySelfJJCData"), &ServerStub::requestMySelfJJCData);
    ClassDB::bind_method(D_METHOD("requestCheckMsg", "name"), &ServerStub::requestCheckMsg);
    ClassDB::bind_method(D_METHOD("requestMyAllbattleMsg"), &ServerStub::requestMyAllbattleMsg);
    ClassDB::bind_method(D_METHOD("requestJJCRank"), &ServerStub::requestJJCRank);
    ClassDB::bind_method(D_METHOD("requestLevelRank"), &ServerStub::requestLevelRank);
    ClassDB::bind_method(D_METHOD("requestBabyRank"), &ServerStub::requestBabyRank);
    ClassDB::bind_method(D_METHOD("requestEmpRank"), &ServerStub::requestEmpRank);
    ClassDB::bind_method(D_METHOD("requestPlayerFFRank"), &ServerStub::requestPlayerFFRank);
    ClassDB::bind_method(D_METHOD("queryOnlinePlayerbyName", "name"), &ServerStub::queryOnlinePlayerbyName);
    ClassDB::bind_method(D_METHOD("queryPlayerbyName", "name"), &ServerStub::queryPlayerbyName);
    ClassDB::bind_method(D_METHOD("queryBaby", "instId"), &ServerStub::queryBaby);
    ClassDB::bind_method(D_METHOD("queryEmployee", "instId"), &ServerStub::queryEmployee);
    ClassDB::bind_method(D_METHOD("guideFinish", "guideIdx"), &ServerStub::guideFinish);
    ClassDB::bind_method(D_METHOD("enterBattle", "battleId"), &ServerStub::enterBattle);
    ClassDB::bind_method(D_METHOD("shopBuyItem", "id", "num"), &ServerStub::shopBuyItem);
    ClassDB::bind_method(D_METHOD("getFirstRechargeItem"), &ServerStub::getFirstRechargeItem);
    ClassDB::bind_method(D_METHOD("requestLevelGift", "level"), &ServerStub::requestLevelGift);
    ClassDB::bind_method(D_METHOD("setCurrentTitle", "title"), &ServerStub::setCurrentTitle);
    ClassDB::bind_method(D_METHOD("openBuyBox"), &ServerStub::openBuyBox);
    ClassDB::bind_method(D_METHOD("requestAchaward", "achId"), &ServerStub::requestAchaward);
    ClassDB::bind_method(D_METHOD("sign", "index"), &ServerStub::sign);
    ClassDB::bind_method(D_METHOD("requestSignupReward7"), &ServerStub::requestSignupReward7);
    ClassDB::bind_method(D_METHOD("requestSignupReward14"), &ServerStub::requestSignupReward14);
    ClassDB::bind_method(D_METHOD("requestSignupReward28"), &ServerStub::requestSignupReward28);
    ClassDB::bind_method(D_METHOD("requestActivityReward", "index"), &ServerStub::requestActivityReward);
    ClassDB::bind_method(D_METHOD("resetHundredTier"), &ServerStub::resetHundredTier);
    ClassDB::bind_method(D_METHOD("enterHundredScene", "level"), &ServerStub::enterHundredScene);
    ClassDB::bind_method(D_METHOD("delBaby", "instId"), &ServerStub::delBaby);
    ClassDB::bind_method(D_METHOD("resetBaby", "instId"), &ServerStub::resetBaby);
    ClassDB::bind_method(D_METHOD("resetBabyProp", "instId"), &ServerStub::resetBabyProp);
    ClassDB::bind_method(D_METHOD("remouldBaby", "instid"), &ServerStub::remouldBaby);
    ClassDB::bind_method(D_METHOD("empSkillLevelUp", "empId", "skillId"), &ServerStub::empSkillLevelUp);
    ClassDB::bind_method(D_METHOD("setOpenDoubleTimeFlag", "isFlag"), &ServerStub::setOpenDoubleTimeFlag);
    ClassDB::bind_method(D_METHOD("talkedNpc", "npcId"), &ServerStub::talkedNpc);
    ClassDB::bind_method(D_METHOD("jjcBattleGo", "id"), &ServerStub::jjcBattleGo);
    ClassDB::bind_method(D_METHOD("requestMyJJCTeamMsg"), &ServerStub::requestMyJJCTeamMsg);
    ClassDB::bind_method(D_METHOD("startMatching"), &ServerStub::startMatching);
    ClassDB::bind_method(D_METHOD("stopMatching"), &ServerStub::stopMatching);
    ClassDB::bind_method(D_METHOD("exitPvpJJC"), &ServerStub::exitPvpJJC);
    ClassDB::bind_method(D_METHOD("joinPvpLobby"), &ServerStub::joinPvpLobby);
    ClassDB::bind_method(D_METHOD("exitPvpLobby"), &ServerStub::exitPvpLobby);
    ClassDB::bind_method(D_METHOD("requestpvprank"), &ServerStub::requestpvprank);
    ClassDB::bind_method(D_METHOD("joinWarriorchoose"), &ServerStub::joinWarriorchoose);
    ClassDB::bind_method(D_METHOD("warriorStart"), &ServerStub::warriorStart);
    ClassDB::bind_method(D_METHOD("warriorStop"), &ServerStub::warriorStop);
    ClassDB::bind_method(D_METHOD("sendMail", "playername", "title", "content"), &ServerStub::sendMail);
    ClassDB::bind_method(D_METHOD("readMail", "mailId"), &ServerStub::readMail);
    ClassDB::bind_method(D_METHOD("delMail", "mailId"), &ServerStub::delMail);
    ClassDB::bind_method(D_METHOD("getMailItem", "mailId"), &ServerStub::getMailItem);
    ClassDB::bind_method(D_METHOD("requestState"), &ServerStub::requestState);
    ClassDB::bind_method(D_METHOD("createGuild", "guildName"), &ServerStub::createGuild);
    ClassDB::bind_method(D_METHOD("delGuild", "guildId"), &ServerStub::delGuild);
    ClassDB::bind_method(D_METHOD("requestJoinGuild", "guid"), &ServerStub::requestJoinGuild);
    ClassDB::bind_method(D_METHOD("leaveGuild"), &ServerStub::leaveGuild);
    ClassDB::bind_method(D_METHOD("kickOut", "guid"), &ServerStub::kickOut);
    ClassDB::bind_method(D_METHOD("acceptRequestGuild", "playerId"), &ServerStub::acceptRequestGuild);
    ClassDB::bind_method(D_METHOD("refuseRequestGuild", "playerId"), &ServerStub::refuseRequestGuild);
    ClassDB::bind_method(D_METHOD("changeMemberPosition", "targetId", "job"), &ServerStub::changeMemberPosition);
    ClassDB::bind_method(D_METHOD("transferPremier", "targetId"), &ServerStub::transferPremier);
    ClassDB::bind_method(D_METHOD("changeGuildNotice", "notice"), &ServerStub::changeGuildNotice);
    ClassDB::bind_method(D_METHOD("queryGuildList", "page"), &ServerStub::queryGuildList);
    ClassDB::bind_method(D_METHOD("inviteJoinGuild", "playerName"), &ServerStub::inviteJoinGuild);
    ClassDB::bind_method(D_METHOD("respondInviteJoinGuild", "sendName"), &ServerStub::respondInviteJoinGuild);
    ClassDB::bind_method(D_METHOD("buyGuildItem", "tableId", "times"), &ServerStub::buyGuildItem);
    ClassDB::bind_method(D_METHOD("entryGuildBattle"), &ServerStub::entryGuildBattle);
    ClassDB::bind_method(D_METHOD("transforGuildBattleScene"), &ServerStub::transforGuildBattleScene);
    ClassDB::bind_method(D_METHOD("addGuildMoney", "money"), &ServerStub::addGuildMoney);
    ClassDB::bind_method(D_METHOD("updateGuildBuiling", "gbt"), &ServerStub::updateGuildBuiling);
    ClassDB::bind_method(D_METHOD("refreshGuildShop"), &ServerStub::refreshGuildShop);
    ClassDB::bind_method(D_METHOD("levelupGuildSkill", "skId"), &ServerStub::levelupGuildSkill);
    ClassDB::bind_method(D_METHOD("presentGuildItem", "num"), &ServerStub::presentGuildItem);
    ClassDB::bind_method(D_METHOD("progenitusAddExp", "monsterId", "isSuper"), &ServerStub::progenitusAddExp);
    ClassDB::bind_method(D_METHOD("setProgenitusPosition", "mId", "pos"), &ServerStub::setProgenitusPosition);
    ClassDB::bind_method(D_METHOD("guildsign"), &ServerStub::guildsign);
    ClassDB::bind_method(D_METHOD("fetchSelling", "context"), &ServerStub::fetchSelling);
    ClassDB::bind_method(D_METHOD("fetchSelling2", "context"), &ServerStub::fetchSelling2);
    ClassDB::bind_method(D_METHOD("selling", "iteminstid", "babyinstid", "price"), &ServerStub::selling);
    ClassDB::bind_method(D_METHOD("unselling", "sellid"), &ServerStub::unselling);
    ClassDB::bind_method(D_METHOD("buy", "sellid"), &ServerStub::buy);
    ClassDB::bind_method(D_METHOD("fixItem", "instId", "type"), &ServerStub::fixItem);
    ClassDB::bind_method(D_METHOD("fixAllItem", "items", "type"), &ServerStub::fixAllItem);
    ClassDB::bind_method(D_METHOD("makeDebirsItem", "instId", "num"), &ServerStub::makeDebirsItem);
    ClassDB::bind_method(D_METHOD("levelUpMagicItem", "items"), &ServerStub::levelUpMagicItem);
    ClassDB::bind_method(D_METHOD("tupoMagicItem", "level"), &ServerStub::tupoMagicItem);
    ClassDB::bind_method(D_METHOD("changeMagicJob", "job"), &ServerStub::changeMagicJob);
    ClassDB::bind_method(D_METHOD("requestPk", "playerId"), &ServerStub::requestPk);
    ClassDB::bind_method(D_METHOD("uiBehavior", "type"), &ServerStub::uiBehavior);
    ClassDB::bind_method(D_METHOD("openZhuanpan"), &ServerStub::openZhuanpan);
    ClassDB::bind_method(D_METHOD("zhuanpanGo", "counter"), &ServerStub::zhuanpanGo);
    ClassDB::bind_method(D_METHOD("redemptionSpree", "code"), &ServerStub::redemptionSpree);
    ClassDB::bind_method(D_METHOD("sceneFilter", "sfType"), &ServerStub::sceneFilter);
    ClassDB::bind_method(D_METHOD("sendExamAnswer", "questionId", "answer"), &ServerStub::sendExamAnswer);
    ClassDB::bind_method(D_METHOD("sendwishing", "wish"), &ServerStub::sendwishing);
    ClassDB::bind_method(D_METHOD("requestWish"), &ServerStub::requestWish);
    ClassDB::bind_method(D_METHOD("leaderCloseDialog"), &ServerStub::leaderCloseDialog);
    ClassDB::bind_method(D_METHOD("requestOnlineReward", "index"), &ServerStub::requestOnlineReward);
    ClassDB::bind_method(D_METHOD("requestFundReward", "level"), &ServerStub::requestFundReward);
    ClassDB::bind_method(D_METHOD("openCard", "index"), &ServerStub::openCard);
    ClassDB::bind_method(D_METHOD("resetCard"), &ServerStub::resetCard);
    ClassDB::bind_method(D_METHOD("hotRoleBuy"), &ServerStub::hotRoleBuy);
    ClassDB::bind_method(D_METHOD("requestSevenReward", "qid"), &ServerStub::requestSevenReward);
    ClassDB::bind_method(D_METHOD("vipreward"), &ServerStub::vipreward);
    ClassDB::bind_method(D_METHOD("requestChargeTotalSingleReward", "index"), &ServerStub::requestChargeTotalSingleReward);
    ClassDB::bind_method(D_METHOD("requestChargeTotalReward", "index"), &ServerStub::requestChargeTotalReward);
    ClassDB::bind_method(D_METHOD("requestChargeEverySingleReward", "index"), &ServerStub::requestChargeEverySingleReward);
    ClassDB::bind_method(D_METHOD("requestChargeEveryReward", "index"), &ServerStub::requestChargeEveryReward);
    ClassDB::bind_method(D_METHOD("requestLoginTotal", "index"), &ServerStub::requestLoginTotal);
    ClassDB::bind_method(D_METHOD("buyDiscountStoreSingle", "itemId", "itemStack"), &ServerStub::buyDiscountStoreSingle);
    ClassDB::bind_method(D_METHOD("buyDiscountStore", "itemId", "itemStack"), &ServerStub::buyDiscountStore);
    ClassDB::bind_method(D_METHOD("requestEmployeeActivityReward", "index"), &ServerStub::requestEmployeeActivityReward);
    ClassDB::bind_method(D_METHOD("requestmyselfrechargeleReward", "index"), &ServerStub::requestmyselfrechargeleReward);
    ClassDB::bind_method(D_METHOD("requestEverydayIntegral"), &ServerStub::requestEverydayIntegral);
    ClassDB::bind_method(D_METHOD("buyIntegralItem", "id", "num"), &ServerStub::buyIntegralItem);
    ClassDB::bind_method(D_METHOD("familyLoseLeader"), &ServerStub::familyLoseLeader);
    ClassDB::bind_method(D_METHOD("verificationSMS", "phoneNumber", "code"), &ServerStub::verificationSMS);
    ClassDB::bind_method(D_METHOD("lockItem", "instId", "isLock"), &ServerStub::lockItem);
    ClassDB::bind_method(D_METHOD("lockBaby", "instId", "isLock"), &ServerStub::lockBaby);
    ClassDB::bind_method(D_METHOD("showBaby", "instId"), &ServerStub::showBaby);
    ClassDB::bind_method(D_METHOD("wearFuwen", "itemInstId"), &ServerStub::wearFuwen);
    ClassDB::bind_method(D_METHOD("takeoffFuwen", "slotId"), &ServerStub::takeoffFuwen);
    ClassDB::bind_method(D_METHOD("compFuwen", "itemInstId"), &ServerStub::compFuwen);
    ClassDB::bind_method(D_METHOD("requestEmployeeQuest"), &ServerStub::requestEmployeeQuest);
    ClassDB::bind_method(D_METHOD("acceptEmployeeQuest", "questId", "employees"), &ServerStub::acceptEmployeeQuest);
    ClassDB::bind_method(D_METHOD("submitEmployeeQuest", "questId"), &ServerStub::submitEmployeeQuest);
    ClassDB::bind_method(D_METHOD("crystalUpLevel"), &ServerStub::crystalUpLevel);
    ClassDB::bind_method(D_METHOD("resetCrystalProp", "locklist"), &ServerStub::resetCrystalProp);
    ClassDB::bind_method(D_METHOD("magicItemOneKeyLevel"), &ServerStub::magicItemOneKeyLevel);
    ClassDB::bind_method(D_METHOD("submitQuest2", "npcId", "questId", "instId"), &ServerStub::submitQuest2);
}

void ServerStub::openvip(uint16_t vl) {
    if (stub) stub->openvip(vl);
}

void ServerStub::requestPhoto() {
    if (stub) stub->requestPhoto();
}

void ServerStub::ping() {
    if (stub) stub->ping();
}

void ServerStub::sessionlogin(Ref<COM_LoginInfo> info) {
    if (stub) stub->sessionlogin(info);
}

void ServerStub::login(Ref<COM_LoginInfo> info) {
    if (stub) stub->login(info);
}

void ServerStub::createPlayer(String playername, uint8_t playerTmpId) {
    if (stub) stub->createPlayer(playername, playerTmpId);
}

void ServerStub::deletePlayer(String playername) {
    if (stub) stub->deletePlayer(playername);
}

void ServerStub::enterGame(uint32_t playerInstId) {
    if (stub) stub->enterGame(playerInstId);
}

void ServerStub::requestBag() {
    if (stub) stub->requestBag();
}

void ServerStub::requestEmployees() {
    if (stub) stub->requestEmployees();
}

void ServerStub::requestStorage(uint16_t tp) {
    if (stub) stub->requestStorage(tp);
}

void ServerStub::requestAchievement() {
    if (stub) stub->requestAchievement();
}

void ServerStub::initminig() {
    if (stub) stub->initminig();
}

void ServerStub::requestCompound() {
    if (stub) stub->requestCompound();
}

void ServerStub::move(float x, float z) {
    if (stub) stub->move(x, z);
}

void ServerStub::moveToNpc(int32_t npcid) {
    if (stub) stub->moveToNpc(npcid);
}

void ServerStub::moveToNpc2(uint16_t type) {
    if (stub) stub->moveToNpc2(type);
}

void ServerStub::moveToZone(int32_t sceneId, int32_t zoneId) {
    if (stub) stub->moveToZone(sceneId, zoneId);
}

void ServerStub::autoBattle() {
    if (stub) stub->autoBattle();
}

void ServerStub::stopAutoBattle() {
    if (stub) stub->stopAutoBattle();
}

void ServerStub::stopMove() {
    if (stub) stub->stopMove();
}

void ServerStub::exitCopy() {
    if (stub) stub->exitCopy();
}

void ServerStub::transforScene(int32_t sceneId) {
    if (stub) stub->transforScene(sceneId);
}

void ServerStub::sceneLoaded() {
    if (stub) stub->sceneLoaded();
}

void ServerStub::querySimplePlayerInst(uint32_t instId) {
    if (stub) stub->querySimplePlayerInst(instId);
}

void ServerStub::logout() {
    if (stub) stub->logout();
}

void ServerStub::changProp(uint32_t guid, TypedArray<COM_Addprop> props) {
    if (stub) stub->changProp(guid, props);
}

void ServerStub::learnSkill(uint32_t skid) {
    if (stub) stub->learnSkill(skid);
}

void ServerStub::babyLearnSkill(uint32_t instId, uint32_t oldSkId, uint32_t newSkId, uint32_t newSkLv) {
    if (stub) stub->babyLearnSkill(instId, oldSkId, newSkId, newSkLv);
}

void ServerStub::forgetSkill(uint32_t skid) {
    if (stub) stub->forgetSkill(skid);
}

void ServerStub::syncOrder(Ref<COM_Order> order) {
    if (stub) stub->syncOrder(order);
}

void ServerStub::syncOrderTimeout() {
    if (stub) stub->syncOrderTimeout();
}

void ServerStub::sendChat(Ref<COM_Chat> content, String targetName) {
    if (stub) stub->sendChat(content, targetName);
}

void ServerStub::requestAudio(int32_t audioId) {
    if (stub) stub->requestAudio(audioId);
}

void ServerStub::publishItemInst(uint16_t type, uint32_t itemInstId, uint16_t chatType, String playerName) {
    if (stub) stub->publishItemInst(type, itemInstId, chatType, playerName);
}

void ServerStub::queryItemInst(int32_t showId) {
    if (stub) stub->queryItemInst(showId);
}

void ServerStub::publishbabyInst(uint16_t type, uint32_t babyInstId, String playerName) {
    if (stub) stub->publishbabyInst(type, babyInstId, playerName);
}

void ServerStub::querybabyInst(int32_t showId) {
    if (stub) stub->querybabyInst(showId);
}

void ServerStub::useItem(uint32_t slot, uint32_t target, uint32_t stack) {
    if (stub) stub->useItem(slot, target, stack);
}

void ServerStub::wearEquipment(uint32_t target, uint32_t itemInstId) {
    if (stub) stub->wearEquipment(target, itemInstId);
}

void ServerStub::delEquipment(uint32_t target, uint32_t itemInstId) {
    if (stub) stub->delEquipment(target, itemInstId);
}

void ServerStub::setPlayerFront(bool isFront) {
    if (stub) stub->setPlayerFront(isFront);
}

void ServerStub::setBattlebaby(uint32_t babyID, bool isBattle) {
    if (stub) stub->setBattlebaby(babyID, isBattle);
}

void ServerStub::changeBabyName(uint32_t babyID, String name) {
    if (stub) stub->changeBabyName(babyID, name);
}

void ServerStub::intensifyBaby(uint32_t babyid) {
    if (stub) stub->intensifyBaby(babyid);
}

void ServerStub::setBattleEmp(uint32_t empID, uint16_t group, bool isBattle) {
    if (stub) stub->setBattleEmp(empID, group, isBattle);
}

void ServerStub::changeEmpBattleGroup(uint16_t group) {
    if (stub) stub->changeEmpBattleGroup(group);
}

void ServerStub::requestEvolve(uint32_t empInstId) {
    if (stub) stub->requestEvolve(empInstId);
}

void ServerStub::requestUpStar(uint32_t empInstId) {
    if (stub) stub->requestUpStar(empInstId);
}

void ServerStub::requestDelEmp(uint32_t empInstId) {
    if (stub) stub->requestDelEmp(empInstId);
}

void ServerStub::delEmployee(TypedArray<uint32_t> emps) {
    if (stub) stub->delEmployee(emps);
}

void ServerStub::onekeyDelEmp() {
    if (stub) stub->onekeyDelEmp();
}

void ServerStub::delEmployeeSoul(uint32_t instid, uint32_t soulNum) {
    if (stub) stub->delEmployeeSoul(instid, soulNum);
}

void ServerStub::sortBagItem() {
    if (stub) stub->sortBagItem();
}

void ServerStub::sellBagItem(uint32_t instId, uint32_t stack) {
    if (stub) stub->sellBagItem(instId, stack);
}

void ServerStub::depositItemToStorage(uint32_t instid) {
    if (stub) stub->depositItemToStorage(instid);
}

void ServerStub::depositBabyToStorage(uint32_t instid) {
    if (stub) stub->depositBabyToStorage(instid);
}

void ServerStub::storageItemToBag(uint32_t instid) {
    if (stub) stub->storageItemToBag(instid);
}

void ServerStub::storageBabyToPlayer(uint32_t instid) {
    if (stub) stub->storageBabyToPlayer(instid);
}

void ServerStub::sortStorage(uint16_t tp) {
    if (stub) stub->sortStorage(tp);
}

void ServerStub::delStorageBaby(uint32_t instid) {
    if (stub) stub->delStorageBaby(instid);
}

void ServerStub::jointLobby() {
    if (stub) stub->jointLobby();
}

void ServerStub::exitLobby() {
    if (stub) stub->exitLobby();
}

void ServerStub::createTeam(Ref<COM_CreateTeamInfo> cti) {
    if (stub) stub->createTeam(cti);
}

void ServerStub::changeTeam(Ref<COM_CreateTeamInfo> info) {
    if (stub) stub->changeTeam(info);
}

void ServerStub::kickTeamMember(uint32_t uuid) {
    if (stub) stub->kickTeamMember(uuid);
}

void ServerStub::changeTeamLeader(uint32_t uuid) {
    if (stub) stub->changeTeamLeader(uuid);
}

void ServerStub::joinTeam(uint32_t teamId, String pwd) {
    if (stub) stub->joinTeam(teamId, pwd);
}

void ServerStub::exitTeam() {
    if (stub) stub->exitTeam();
}

void ServerStub::changeTeamPassword(String pwd) {
    if (stub) stub->changeTeamPassword(pwd);
}

void ServerStub::joinTeamRoom() {
    if (stub) stub->joinTeamRoom();
}

void ServerStub::inviteTeamMember(String name) {
    if (stub) stub->inviteTeamMember(name);
}

void ServerStub::isjoinTeam(uint32_t teamId, bool isFlag) {
    if (stub) stub->isjoinTeam(teamId, isFlag);
}

void ServerStub::leaveTeam() {
    if (stub) stub->leaveTeam();
}

void ServerStub::backTeam() {
    if (stub) stub->backTeam();
}

void ServerStub::refuseBackTeam() {
    if (stub) stub->refuseBackTeam();
}

void ServerStub::teamCallMember(int32_t playerId) {
    if (stub) stub->teamCallMember(playerId);
}

void ServerStub::requestJoinTeam(String targetName) {
    if (stub) stub->requestJoinTeam(targetName);
}

void ServerStub::ratifyJoinTeam(String sendName) {
    if (stub) stub->ratifyJoinTeam(sendName);
}

void ServerStub::drawLotteryBox(uint16_t type, bool isFree) {
    if (stub) stub->drawLotteryBox(type, isFree);
}

void ServerStub::acceptQuest(int32_t questId) {
    if (stub) stub->acceptQuest(questId);
}

void ServerStub::submitQuest(int32_t npcId, int32_t questId) {
    if (stub) stub->submitQuest(npcId, questId);
}

void ServerStub::giveupQuest(int32_t questId) {
    if (stub) stub->giveupQuest(questId);
}

void ServerStub::requestContactInfoById(uint32_t instId) {
    if (stub) stub->requestContactInfoById(instId);
}

void ServerStub::requestContactInfoByName(String instName) {
    if (stub) stub->requestContactInfoByName(instName);
}

void ServerStub::requestFriendList() {
    if (stub) stub->requestFriendList();
}

void ServerStub::addFriend(uint32_t instId) {
    if (stub) stub->addFriend(instId);
}

void ServerStub::delFriend(uint32_t instId) {
    if (stub) stub->delFriend(instId);
}

void ServerStub::addBlacklist(uint32_t instId) {
    if (stub) stub->addBlacklist(instId);
}

void ServerStub::delBlacklist(uint32_t instId) {
    if (stub) stub->delBlacklist(instId);
}

void ServerStub::requestReferrFriend() {
    if (stub) stub->requestReferrFriend();
}

void ServerStub::mining(int32_t gatherId, int32_t times) {
    if (stub) stub->mining(gatherId, times);
}

void ServerStub::compoundItem(int32_t itemId, int32_t gemId) {
    if (stub) stub->compoundItem(itemId, gemId);
}

void ServerStub::bagItemSplit(int32_t instId, int32_t splitNum) {
    if (stub) stub->bagItemSplit(instId, splitNum);
}

void ServerStub::requestChallenge(String name) {
    if (stub) stub->requestChallenge(name);
}

void ServerStub::requestRival() {
    if (stub) stub->requestRival();
}

void ServerStub::requestMySelfJJCData() {
    if (stub) stub->requestMySelfJJCData();
}

void ServerStub::requestCheckMsg(String name) {
    if (stub) stub->requestCheckMsg(name);
}

void ServerStub::requestMyAllbattleMsg() {
    if (stub) stub->requestMyAllbattleMsg();
}

void ServerStub::requestJJCRank() {
    if (stub) stub->requestJJCRank();
}

void ServerStub::requestLevelRank() {
    if (stub) stub->requestLevelRank();
}

void ServerStub::requestBabyRank() {
    if (stub) stub->requestBabyRank();
}

void ServerStub::requestEmpRank() {
    if (stub) stub->requestEmpRank();
}

void ServerStub::requestPlayerFFRank() {
    if (stub) stub->requestPlayerFFRank();
}

void ServerStub::queryOnlinePlayerbyName(String name) {
    if (stub) stub->queryOnlinePlayerbyName(name);
}

void ServerStub::queryPlayerbyName(String name) {
    if (stub) stub->queryPlayerbyName(name);
}

void ServerStub::queryBaby(uint32_t instId) {
    if (stub) stub->queryBaby(instId);
}

void ServerStub::queryEmployee(uint32_t instId) {
    if (stub) stub->queryEmployee(instId);
}

void ServerStub::guideFinish(uint64_t guideIdx) {
    if (stub) stub->guideFinish(guideIdx);
}

void ServerStub::enterBattle(int32_t battleId) {
    if (stub) stub->enterBattle(battleId);
}

void ServerStub::shopBuyItem(int32_t id, int32_t num) {
    if (stub) stub->shopBuyItem(id, num);
}

void ServerStub::getFirstRechargeItem() {
    if (stub) stub->getFirstRechargeItem();
}

void ServerStub::requestLevelGift(int32_t level) {
    if (stub) stub->requestLevelGift(level);
}

void ServerStub::setCurrentTitle(int32_t title) {
    if (stub) stub->setCurrentTitle(title);
}

void ServerStub::openBuyBox() {
    if (stub) stub->openBuyBox();
}

void ServerStub::requestAchaward(int32_t achId) {
    if (stub) stub->requestAchaward(achId);
}

void ServerStub::sign(int32_t index) {
    if (stub) stub->sign(index);
}

void ServerStub::requestSignupReward7() {
    if (stub) stub->requestSignupReward7();
}

void ServerStub::requestSignupReward14() {
    if (stub) stub->requestSignupReward14();
}

void ServerStub::requestSignupReward28() {
    if (stub) stub->requestSignupReward28();
}

void ServerStub::requestActivityReward(int32_t index) {
    if (stub) stub->requestActivityReward(index);
}

void ServerStub::resetHundredTier() {
    if (stub) stub->resetHundredTier();
}

void ServerStub::enterHundredScene(int32_t level) {
    if (stub) stub->enterHundredScene(level);
}

void ServerStub::delBaby(int32_t instId) {
    if (stub) stub->delBaby(instId);
}

void ServerStub::resetBaby(int32_t instId) {
    if (stub) stub->resetBaby(instId);
}

void ServerStub::resetBabyProp(int32_t instId) {
    if (stub) stub->resetBabyProp(instId);
}

void ServerStub::remouldBaby(int32_t instid) {
    if (stub) stub->remouldBaby(instid);
}

void ServerStub::empSkillLevelUp(uint32_t empId, int32_t skillId) {
    if (stub) stub->empSkillLevelUp(empId, skillId);
}

void ServerStub::setOpenDoubleTimeFlag(bool isFlag) {
    if (stub) stub->setOpenDoubleTimeFlag(isFlag);
}

void ServerStub::talkedNpc(int32_t npcId) {
    if (stub) stub->talkedNpc(npcId);
}

void ServerStub::jjcBattleGo(uint32_t id) {
    if (stub) stub->jjcBattleGo(id);
}

void ServerStub::requestMyJJCTeamMsg() {
    if (stub) stub->requestMyJJCTeamMsg();
}

void ServerStub::startMatching() {
    if (stub) stub->startMatching();
}

void ServerStub::stopMatching() {
    if (stub) stub->stopMatching();
}

void ServerStub::exitPvpJJC() {
    if (stub) stub->exitPvpJJC();
}

void ServerStub::joinPvpLobby() {
    if (stub) stub->joinPvpLobby();
}

void ServerStub::exitPvpLobby() {
    if (stub) stub->exitPvpLobby();
}

void ServerStub::requestpvprank() {
    if (stub) stub->requestpvprank();
}

void ServerStub::joinWarriorchoose() {
    if (stub) stub->joinWarriorchoose();
}

void ServerStub::warriorStart() {
    if (stub) stub->warriorStart();
}

void ServerStub::warriorStop() {
    if (stub) stub->warriorStop();
}

void ServerStub::sendMail(String playername, String title, String content) {
    if (stub) stub->sendMail(playername, title, content);
}

void ServerStub::readMail(int32_t mailId) {
    if (stub) stub->readMail(mailId);
}

void ServerStub::delMail(int32_t mailId) {
    if (stub) stub->delMail(mailId);
}

void ServerStub::getMailItem(int32_t mailId) {
    if (stub) stub->getMailItem(mailId);
}

void ServerStub::requestState() {
    if (stub) stub->requestState();
}

void ServerStub::createGuild(String guildName) {
    if (stub) stub->createGuild(guildName);
}

void ServerStub::delGuild(uint32_t guildId) {
    if (stub) stub->delGuild(guildId);
}

void ServerStub::requestJoinGuild(uint32_t guid) {
    if (stub) stub->requestJoinGuild(guid);
}

void ServerStub::leaveGuild() {
    if (stub) stub->leaveGuild();
}

void ServerStub::kickOut(int32_t guid) {
    if (stub) stub->kickOut(guid);
}

void ServerStub::acceptRequestGuild(int32_t playerId) {
    if (stub) stub->acceptRequestGuild(playerId);
}

void ServerStub::refuseRequestGuild(int32_t playerId) {
    if (stub) stub->refuseRequestGuild(playerId);
}

void ServerStub::changeMemberPosition(int32_t targetId, uint16_t job) {
    if (stub) stub->changeMemberPosition(targetId, job);
}

void ServerStub::transferPremier(int32_t targetId) {
    if (stub) stub->transferPremier(targetId);
}

void ServerStub::changeGuildNotice(String notice) {
    if (stub) stub->changeGuildNotice(notice);
}

void ServerStub::queryGuildList(int16_t page) {
    if (stub) stub->queryGuildList(page);
}

void ServerStub::inviteJoinGuild(String playerName) {
    if (stub) stub->inviteJoinGuild(playerName);
}

void ServerStub::respondInviteJoinGuild(String sendName) {
    if (stub) stub->respondInviteJoinGuild(sendName);
}

void ServerStub::buyGuildItem(int32_t tableId, int32_t times) {
    if (stub) stub->buyGuildItem(tableId, times);
}

void ServerStub::entryGuildBattle() {
    if (stub) stub->entryGuildBattle();
}

void ServerStub::transforGuildBattleScene() {
    if (stub) stub->transforGuildBattleScene();
}

void ServerStub::addGuildMoney(int32_t money) {
    if (stub) stub->addGuildMoney(money);
}

void ServerStub::updateGuildBuiling(uint16_t gbt) {
    if (stub) stub->updateGuildBuiling(gbt);
}

void ServerStub::refreshGuildShop() {
    if (stub) stub->refreshGuildShop();
}

void ServerStub::levelupGuildSkill(int32_t skId) {
    if (stub) stub->levelupGuildSkill(skId);
}

void ServerStub::presentGuildItem(int32_t num) {
    if (stub) stub->presentGuildItem(num);
}

void ServerStub::progenitusAddExp(int32_t monsterId, bool isSuper) {
    if (stub) stub->progenitusAddExp(monsterId, isSuper);
}

void ServerStub::setProgenitusPosition(int32_t mId, int32_t pos) {
    if (stub) stub->setProgenitusPosition(mId, pos);
}

void ServerStub::guildsign() {
    if (stub) stub->guildsign();
}

void ServerStub::fetchSelling(Ref<COM_SearchContext> context) {
    if (stub) stub->fetchSelling(context);
}

void ServerStub::fetchSelling2(Ref<COM_SearchContext> context) {
    if (stub) stub->fetchSelling2(context);
}

void ServerStub::selling(int32_t iteminstid, int32_t babyinstid, int32_t price) {
    if (stub) stub->selling(iteminstid, babyinstid, price);
}

void ServerStub::unselling(int32_t sellid) {
    if (stub) stub->unselling(sellid);
}

void ServerStub::buy(int32_t sellid) {
    if (stub) stub->buy(sellid);
}

void ServerStub::fixItem(int32_t instId, uint16_t type) {
    if (stub) stub->fixItem(instId, type);
}

void ServerStub::fixAllItem(TypedArray<uint32_t> items, uint16_t type) {
    if (stub) stub->fixAllItem(items, type);
}

void ServerStub::makeDebirsItem(int32_t instId, int32_t num) {
    if (stub) stub->makeDebirsItem(instId, num);
}

void ServerStub::levelUpMagicItem(TypedArray<uint32_t> items) {
    if (stub) stub->levelUpMagicItem(items);
}

void ServerStub::tupoMagicItem(int32_t level) {
    if (stub) stub->tupoMagicItem(level);
}

void ServerStub::changeMagicJob(uint16_t job) {
    if (stub) stub->changeMagicJob(job);
}

void ServerStub::requestPk(uint32_t playerId) {
    if (stub) stub->requestPk(playerId);
}

void ServerStub::uiBehavior(uint16_t type) {
    if (stub) stub->uiBehavior(type);
}

void ServerStub::openZhuanpan() {
    if (stub) stub->openZhuanpan();
}

void ServerStub::zhuanpanGo(uint32_t counter) {
    if (stub) stub->zhuanpanGo(counter);
}

void ServerStub::redemptionSpree(String code) {
    if (stub) stub->redemptionSpree(code);
}

void ServerStub::sceneFilter(TypedArray<uint16_t> sfType) {
    if (stub) stub->sceneFilter(sfType);
}

void ServerStub::sendExamAnswer(uint32_t questionId, uint8_t answer) {
    if (stub) stub->sendExamAnswer(questionId, answer);
}

void ServerStub::sendwishing(Ref<COM_Wishing> wish) {
    if (stub) stub->sendwishing(wish);
}

void ServerStub::requestWish() {
    if (stub) stub->requestWish();
}

void ServerStub::leaderCloseDialog() {
    if (stub) stub->leaderCloseDialog();
}

void ServerStub::requestOnlineReward(uint32_t index) {
    if (stub) stub->requestOnlineReward(index);
}

void ServerStub::requestFundReward(uint32_t level) {
    if (stub) stub->requestFundReward(level);
}

void ServerStub::openCard(uint16_t index) {
    if (stub) stub->openCard(index);
}

void ServerStub::resetCard() {
    if (stub) stub->resetCard();
}

void ServerStub::hotRoleBuy() {
    if (stub) stub->hotRoleBuy();
}

void ServerStub::requestSevenReward(uint32_t qid) {
    if (stub) stub->requestSevenReward(qid);
}

void ServerStub::vipreward() {
    if (stub) stub->vipreward();
}

void ServerStub::requestChargeTotalSingleReward(uint32_t index) {
    if (stub) stub->requestChargeTotalSingleReward(index);
}

void ServerStub::requestChargeTotalReward(uint32_t index) {
    if (stub) stub->requestChargeTotalReward(index);
}

void ServerStub::requestChargeEverySingleReward(uint32_t index) {
    if (stub) stub->requestChargeEverySingleReward(index);
}

void ServerStub::requestChargeEveryReward(uint32_t index) {
    if (stub) stub->requestChargeEveryReward(index);
}

void ServerStub::requestLoginTotal(uint32_t index) {
    if (stub) stub->requestLoginTotal(index);
}

void ServerStub::buyDiscountStoreSingle(int32_t itemId, int32_t itemStack) {
    if (stub) stub->buyDiscountStoreSingle(itemId, itemStack);
}

void ServerStub::buyDiscountStore(int32_t itemId, int32_t itemStack) {
    if (stub) stub->buyDiscountStore(itemId, itemStack);
}

void ServerStub::requestEmployeeActivityReward(uint32_t index) {
    if (stub) stub->requestEmployeeActivityReward(index);
}

void ServerStub::requestmyselfrechargeleReward(uint32_t index) {
    if (stub) stub->requestmyselfrechargeleReward(index);
}

void ServerStub::requestEverydayIntegral() {
    if (stub) stub->requestEverydayIntegral();
}

void ServerStub::buyIntegralItem(uint32_t id, uint32_t num) {
    if (stub) stub->buyIntegralItem(id, num);
}

void ServerStub::familyLoseLeader() {
    if (stub) stub->familyLoseLeader();
}

void ServerStub::verificationSMS(String phoneNumber, String code) {
    if (stub) stub->verificationSMS(phoneNumber, code);
}

void ServerStub::lockItem(int32_t instId, bool isLock) {
    if (stub) stub->lockItem(instId, isLock);
}

void ServerStub::lockBaby(int32_t instId, bool isLock) {
    if (stub) stub->lockBaby(instId, isLock);
}

void ServerStub::showBaby(int32_t instId) {
    if (stub) stub->showBaby(instId);
}

void ServerStub::wearFuwen(int32_t itemInstId) {
    if (stub) stub->wearFuwen(itemInstId);
}

void ServerStub::takeoffFuwen(int32_t slotId) {
    if (stub) stub->takeoffFuwen(slotId);
}

void ServerStub::compFuwen(int32_t itemInstId) {
    if (stub) stub->compFuwen(itemInstId);
}

void ServerStub::requestEmployeeQuest() {
    if (stub) stub->requestEmployeeQuest();
}

void ServerStub::acceptEmployeeQuest(int32_t questId, TypedArray<int32_t> employees) {
    if (stub) stub->acceptEmployeeQuest(questId, employees);
}

void ServerStub::submitEmployeeQuest(int32_t questId) {
    if (stub) stub->submitEmployeeQuest(questId);
}

void ServerStub::crystalUpLevel() {
    if (stub) stub->crystalUpLevel();
}

void ServerStub::resetCrystalProp(TypedArray<int32_t> locklist) {
    if (stub) stub->resetCrystalProp(locklist);
}

void ServerStub::magicItemOneKeyLevel() {
    if (stub) stub->magicItemOneKeyLevel();
}

void ServerStub::submitQuest2(int32_t npcId, int32_t questId, int32_t instId) {
    if (stub) stub->submitQuest2(npcId, questId, instId);
}

} // namespace godot
