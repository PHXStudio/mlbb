#ifndef __GODOT_SERVER_PROXY_H__
#define __GODOT_SERVER_PROXY_H__

#include <godot_cpp/variant/packed_byte_array.hpp>
#include "../rpc_gen/proto_godot.h"
#include "../rpc/ProtocolWriter.h"

namespace godot {

/**
 * 服务器端代理类。
 * 继承 Client2Server_Stub 用于发送消息到服务器。
 * 通过组合关系被 ServerAgent 使用。
 */
class ServerProxy 
    :public Resource ,
    public Server2Client_Proxy {
    GDCLASS(ServerProxy, Resource)
public:
  ServerProxy();
  ~ServerProxy();

  static void _bind_methods();


  bool dispatch(ProtocolReader *r);
  /**
   * 设置发送数据的回调函数
   * @param send_func 发送数据的函数回调
   */
  virtual void pong() override;
  virtual void errorno(uint16_t e) override;
  virtual void teamerrorno(String name, uint16_t e) override;
  virtual void reconnection(Ref<COM_ReconnectInfo> recInfo) override;
  virtual void sessionfailed() override;
  virtual void loginok(String sessionkey,
                       TypedArray<COM_SimpleInformation> players) override;
  virtual void logoutOk() override;
  virtual void createPlayerOk(Ref<COM_SimpleInformation> player) override;
  virtual void deletePlayerOk(String name) override;
  virtual void enterGameOk(Ref<COM_PlayerInst> inst) override;
  virtual void initBabies(TypedArray<COM_BabyInst> insts) override;
  virtual void initEmployees(TypedArray<COM_EmployeeInst> insts,
                             bool isFlag) override;
  virtual void initEmpBattleGroup(Ref<COM_BattleEmp> bep) override;
  virtual void initNpc(TypedArray<int32_t> npcList) override;
  virtual void initAchievement(TypedArray<COM_Achievement> actlist) override;
  virtual void initGather(uint32_t allnum,
                          TypedArray<COM_Gather> gathers) override;
  virtual void initcompound(TypedArray<uint32_t> compounds) override;
  virtual void addBaby(Ref<COM_BabyInst> inst) override;
  virtual void refreshBaby(Ref<COM_BabyInst> inst) override;
  virtual void delBabyOK(uint32_t babyInstId) override;
  virtual void changeBabyNameOK(uint32_t babyId, String name) override;
  virtual void remouldBabyOK(uint32_t instid) override;
  virtual void intensifyBabyOK(uint32_t babyid,
                               uint32_t intensifyLevel) override;
  virtual void learnSkillOk(Ref<COM_Skill> inst) override;
  virtual void forgetSkillOk(uint32_t skid) override;
  virtual void addSkillExp(uint32_t skid, uint32_t uExp,
                           uint16_t flag) override;
  virtual void babyLearnSkillOK(uint32_t instId, uint32_t newSkId) override;
  virtual void skillLevelUp(uint32_t instId, Ref<COM_Skill> inst) override;
  virtual void joinScene(Ref<COM_SceneInfo> info) override;
  virtual void joinCopySceneOK(int32_t secneid) override;
  virtual void initCopyNums() override;
  virtual void addToScene(Ref<COM_ScenePlayerInformation> inst) override;
  virtual void delFormScene(int32_t instId) override;
  virtual void move2(int32_t instId, Ref<COM_FPosition> pos) override;
  virtual void cantMove() override;
  virtual void
  querySimplePlayerInstOk(Ref<COM_SimplePlayerInst> player) override;
  virtual void transfor2(int32_t instId, Ref<COM_FPosition> pos) override;
  virtual void openScene(int32_t sceneId) override;
  virtual void autoBattleResult(bool isOk) override;
  virtual void talked2Npc(int32_t npcId) override;
  virtual void talked2Player(int32_t playerId) override;
  virtual void useItemOk(int32_t itemId, int32_t stack) override;
  virtual void syncBattleStatus(int32_t playerId, bool inBattle) override;
  virtual void enterBattleOk(Ref<COM_InitBattle> initBattle) override;
  virtual void exitBattleOk(uint16_t bjt,
                            Ref<COM_BattleOverClearing> init) override;
  virtual void syncOrderOk(uint32_t uid) override;
  virtual void syncOrderOkEX() override;
  virtual void syncOneTurnAction(Ref<COM_BattleReport> reports) override;
  virtual void syncProperties(uint32_t guid,
                              TypedArray<COM_PropValue> props) override;
  virtual void receiveChat(Ref<COM_ChatInfo> info,
                           Ref<COM_ContactInfo> myinfo) override;
  virtual void requestAudioOk(int32_t audioId,
                              TypedArray<uint8_t> content) override;
  virtual void publishItemInstRes(Ref<COM_ShowItemInstInfo> info,
                                  uint16_t type) override;
  virtual void queryItemInstRes(Ref<COM_ShowItemInst> item) override;
  virtual void publishBabyInstRes(Ref<COM_ShowbabyInstInfo> info,
                                  uint16_t type) override;
  virtual void queryBabyInstRes(Ref<COM_ShowbabyInst> inst) override;
  virtual void setNoTalkTime(float t) override;
  virtual void addNpc(TypedArray<int32_t> npcList) override;
  virtual void delNpc(TypedArray<int32_t> npcList) override;
  virtual void setTeamLeader(int32_t playerId, bool isLeader) override;
  virtual void initBag(TypedArray<COM_Item> items) override;
  virtual void addBagItem(Ref<COM_Item> item) override;
  virtual void delBagItem(uint16_t slot) override;
  virtual void updateBagItem(Ref<COM_Item> item) override;
  virtual void depositItemOK(Ref<COM_Item> item) override;
  virtual void getoutItemOK(uint16_t slot) override;
  virtual void depositBabyOK(Ref<COM_BabyInst> baby) override;
  virtual void getoutBabyOK(uint16_t slot) override;
  virtual void sortItemStorageOK(TypedArray<COM_Item> items) override;
  virtual void sortBabyStorageOK(TypedArray<uint32_t> babys) override;
  virtual void initItemStorage(uint16_t gridNum,
                               TypedArray<COM_Item> items) override;
  virtual void initBabyStorage(uint16_t gridNum,
                               TypedArray<COM_BabyInst> babys) override;
  virtual void openStorageGrid(uint16_t tp, uint16_t gridNum) override;
  virtual void delStorageBabyOK(uint16_t slot) override;
  virtual void initPlayerEquips(TypedArray<COM_Item> equips) override;
  virtual void wearEquipmentOk(uint32_t target, Ref<COM_Item> equip) override;
  virtual void scenePlayerWearEquipment(uint32_t target,
                                        uint32_t itemId) override;
  virtual void delEquipmentOk(uint32_t target, uint32_t itemInstId) override;
  virtual void scenePlayerDoffEquipment(uint32_t target,
                                        uint32_t itemId) override;
  virtual void sortBagItemOk() override;
  virtual void jointLobbyOk(TypedArray<COM_SimpleTeamInfo> infos) override;
  virtual void exitLobbyOk() override;
  virtual void syncDelLobbyTeam(uint32_t teamId) override;
  virtual void syncUpdateLobbyTeam(Ref<COM_SimpleTeamInfo> info) override;
  virtual void syncAddLobbyTeam(Ref<COM_SimpleTeamInfo> team) override;
  virtual void createTeamOk(Ref<COM_TeamInfo> team) override;
  virtual void changeTeamOk(Ref<COM_TeamInfo> team) override;
  virtual void joinTeamOk(Ref<COM_TeamInfo> team) override;
  virtual void addTeamMember(Ref<COM_SimplePlayerInst> info) override;
  virtual void delTeamMember(int32_t instId) override;
  virtual void changeTeamLeaderOk(int32_t uuid) override;
  virtual void exitTeamOk(bool iskick) override;
  virtual void updateTeam(Ref<COM_TeamInfo> team) override;
  virtual void joinTeamRoomOK(Ref<COM_TeamInfo> team) override;
  virtual void inviteJoinTeam(uint32_t teamId, String name) override;
  virtual void syncTeamDirtyProp(int32_t guid,
                                 TypedArray<COM_PropValue> props) override;
  virtual void leaveTeamOk(int32_t playerId) override;
  virtual void backTeamOK(int32_t playerId) override;
  virtual void teamCallMemberBack() override;
  virtual void refuseBackTeamOk(int32_t playerId) override;
  virtual void requestJoinTeamTranspond(String reqName) override;
  virtual void drawLotteryBoxRep(TypedArray<COM_Item> items) override;
  virtual void addEmployee(Ref<COM_EmployeeInst> employee) override;
  virtual void battleEmployee(int32_t empId, uint16_t group,
                              bool forbattle) override;
  virtual void changeEmpBattleGroupOK(uint16_t group) override;
  virtual void evolveOK(int32_t guid, uint16_t qc) override;
  virtual void upStarOK(int32_t guid, int32_t star, Ref<COM_Skill> sk) override;
  virtual void delEmployeeOK(TypedArray<uint32_t> instids) override;
  virtual void sycnEmployeeSoul(int32_t guid, uint32_t soulNum) override;
  virtual void initQuest(TypedArray<COM_QuestInst> qlist,
                         TypedArray<int32_t> clist) override;
  virtual void acceptQuestOk(Ref<COM_QuestInst> inst) override;
  virtual void submitQuestOk(int32_t questId) override;
  virtual void giveupQuestOk(int32_t questId) override;
  virtual void updateQuestInst(Ref<COM_QuestInst> inst) override;
  virtual void requestContactInfoOk(Ref<COM_ContactInfo> contact) override;
  virtual void addFriendOK(Ref<COM_ContactInfo> inst) override;
  virtual void delFriendOK(uint32_t instId) override;
  virtual void addBlacklistOK(Ref<COM_ContactInfo> inst) override;
  virtual void delBlacklistOK(uint32_t instId) override;
  virtual void findFriendFail() override;
  virtual void referrFriendOK(TypedArray<COM_ContactInfo> insts) override;
  virtual void requestFriendListOK(TypedArray<COM_ContactInfo> insts) override;
  virtual void lotteryOk(int32_t lotteryId,
                         TypedArray<COM_DropItem> dropItem) override;
  virtual void openGatherOK(Ref<COM_Gather> gather) override;
  virtual void miningOk(TypedArray<COM_DropItem> items, Ref<COM_Gather> gather,
                        uint32_t gatherNum) override;
  virtual void openCompound(uint32_t compoundId) override;
  virtual void compoundItemOk(Ref<COM_Item> item) override;
  virtual void openBagGridOk(int32_t num) override;
  virtual void requestChallengeOK(bool isOK) override;
  virtual void requestMySelfJJCDataOK(Ref<COM_EndlessStair> info) override;
  virtual void requestRivalOK(TypedArray<COM_EndlessStair> infos) override;
  virtual void rivalTimeOK() override;
  virtual void checkMsgOK(Ref<COM_SimplePlayerInst> inst) override;
  virtual void
  requestMyAllbattleMsgOK(TypedArray<COM_JJCBattleMsg> infos) override;
  virtual void myBattleMsgOK(Ref<COM_JJCBattleMsg> info) override;
  virtual void requestJJCRankOK(uint32_t myRank,
                                TypedArray<COM_EndlessStair> infos) override;
  virtual void requestLevelRankOK(uint32_t myRank,
                                  TypedArray<COM_ContactInfo> infos) override;
  virtual void requestBabyRankOK(uint32_t myRank,
                                 TypedArray<COM_BabyRankData> infos) override;
  virtual void
  requestEmpRankOK(uint32_t myRank,
                   TypedArray<COM_EmployeeRankData> infos) override;
  virtual void
  requestPlayerFFRankOK(uint32_t myRank,
                        TypedArray<COM_ContactInfo> infos) override;
  virtual void queryOnlinePlayerOK(bool isOnline) override;
  virtual void queryPlayerOK(Ref<COM_SimplePlayerInst> inst) override;
  virtual void queryBabyOK(Ref<COM_BabyInst> inst) override;
  virtual void queryEmployeeOK(Ref<COM_EmployeeInst> inst) override;
  virtual void initGuide(uint32_t guideMask) override;
  virtual void buyShopItemOk(int32_t id) override;
  virtual void addPlayerTitle(int32_t title) override;
  virtual void delPlayerTitle(int32_t title) override;
  virtual void requestOpenBuyBox(float greenTime, float blueTime,
                                 int32_t greenFreeNum) override;
  virtual void requestGreenBoxTimeOk() override;
  virtual void requestBlueBoxTimeOk() override;
  virtual void updateAchievementinfo(Ref<COM_Achievement> achs) override;
  virtual void syncOpenSystemFlag(uint64_t flag) override;
  virtual void requestActivityRewardOK(uint32_t ar) override;
  virtual void syncActivity(Ref<COM_ActivityTable> table) override;
  virtual void updateActivityStatus(uint16_t type, bool open) override;
  virtual void updateActivityCounter(uint16_t type, int32_t counter,
                                     int32_t reward) override;
  virtual void syncExam(Ref<COM_Exam> exam) override;
  virtual void syncExamAnswer(Ref<COM_Answer> answer) override;
  virtual void petActivityNoNum(String name) override;
  virtual void syncHundredInfo(Ref<COM_HundredBattle> hb) override;
  virtual void initSignUp(TypedArray<int32_t> info, int32_t process, bool sign7,
                          bool sign14, bool sign28) override;
  virtual void signUp(bool flag) override;
  virtual void requestSignupRewardOk7() override;
  virtual void requestSignupRewardOk14() override;
  virtual void requestSignupRewardOk28() override;
  virtual void sycnDoubleExpTime(bool isFlag, float times) override;
  virtual void sycnStates(TypedArray<COM_State> states) override;
  virtual void requestpvprankOK(TypedArray<COM_ContactInfo> infos) override;
  virtual void syncMyJJCTeamMember() override;
  virtual void startMatchingOK() override;
  virtual void stopMatchingOK(float times) override;
  virtual void updatePvpJJCinfo(Ref<COM_PlayerVsPlayer> info) override;
  virtual void exitPvpJJCOk() override;
  virtual void
  syncEnemyPvpJJCPlayerInfo(Ref<COM_SimpleInformation> info) override;
  virtual void syncEnemyPvpJJCTeamInfo(TypedArray<COM_SimpleInformation> infos,
                                       uint32_t teamID_) override;
  virtual void openWarriorchooseUI() override;
  virtual void warriorStartOK() override;
  virtual void warriorStopOK() override;
  virtual void syncWarriorEnemyTeamInfo(TypedArray<COM_SimpleInformation> infos,
                                        uint32_t teamID_) override;
  virtual void appendMail(TypedArray<COM_Mail> mails) override;
  virtual void delMail(int32_t mailId) override;
  virtual void updateMailOk(Ref<COM_Mail> mail) override;
  virtual void boardcastNotice(String content, bool isGm) override;
  virtual void createGuildOK() override;
  virtual void delGuildOK() override;
  virtual void leaveGuildOk(String who, bool isKick) override;
  virtual void initGuildData(Ref<COM_Guild> guild) override;
  virtual void initGuildMemberList(TypedArray<COM_GuildMember> member) override;
  virtual void modifyGuildMemberList(Ref<COM_GuildMember> member,
                                     uint16_t flag) override;
  virtual void modifyGuildList(Ref<COM_GuildViewerData> data,
                               uint16_t flag) override;
  virtual void
  queryGuildListResult(int16_t page, int16_t pageNum,
                       TypedArray<COM_GuildViewerData> guildList) override;
  virtual void inviteGuild(String sendName, String guildName) override;
  virtual void
  updateGuildShopItems(TypedArray<COM_GuildShopItem> items) override;
  virtual void updateGuildBuilding(uint16_t type,
                                   Ref<COM_GuildBuilding> building) override;
  virtual void updateGuildMyMember(Ref<COM_GuildMember> member) override;
  virtual void levelupGuildSkillOk(Ref<COM_Skill> skInst) override;
  virtual void presentGuildItemOk(int32_t val) override;
  virtual void progenitusAddExpOk(Ref<COM_GuildProgen> mInst) override;
  virtual void setProgenitusPositionOk(
      TypedArray<int32_t> positions) override;
  virtual void updateGuildFundz(int32_t val) override;
  virtual void updateGuildMemberContribution(int32_t val) override;
  virtual void openGuildBattle(String otherName, int32_t playerNum,
                               int32_t level, bool isLeft,
                               int32_t lstime) override;
  virtual void startGuildBattle(String otherName, int32_t otherCon,
                                int32_t selfCon) override;
  virtual void closeGuildBattle(bool isWinner) override;
  virtual void syncGuildBattleWinCount(int32_t myWin,
                                       int32_t otherWin) override;
  virtual void initMySelling(TypedArray<COM_SellItem> items) override;
  virtual void initMySelled(TypedArray<COM_SelledItem> items) override;
  virtual void fetchSellingOk(TypedArray<COM_SellItem> items,
                              int32_t total) override;
  virtual void fetchSellingOk2(TypedArray<COM_SellItem> items,
                               int32_t total) override;
  virtual void sellingOk(Ref<COM_SellItem> item) override;
  virtual void selledOk(Ref<COM_SelledItem> item) override;
  virtual void unsellingOk(int32_t sellid) override;
  virtual void redemptionSpreeOk() override;
  virtual void insertState(Ref<COM_State> st) override;
  virtual void updattState(Ref<COM_State> st) override;
  virtual void removeState(uint32_t stid) override;
  virtual void requestFixItemOk(Ref<COM_Item> item) override;
  virtual void makeDebirsItemOK() override;
  virtual void updateMagicItem(int32_t level, int32_t exp) override;
  virtual void changeMagicJobOk(uint16_t job) override;
  virtual void magicItemTupoOk(int32_t level) override;
  virtual void zhuanpanOK(TypedArray<uint32_t> pond) override;
  virtual void updateZhuanpanNotice(Ref<COM_Zhuanpan> zhuanp) override;
  virtual void sycnZhuanpanData(Ref<COM_ZhuanpanData> data) override;
  virtual void copynonum(String name) override;
  virtual void sceneFilterOk(TypedArray<uint16_t> sfType) override;
  virtual void wishingOK() override;
  virtual void shareWishOK(Ref<COM_Wish> wish) override;
  virtual void leaderCloseDialogOk() override;
  virtual void startOnlineTime() override;
  virtual void requestOnlineTimeRewardOK(uint32_t index) override;
  virtual void sycnVipflag(bool flag) override;
  virtual void buyFundOK(bool flag) override;
  virtual void requestFundRewardOK(uint32_t level) override;
  virtual void firstRechargeOK(bool isFlag) override;
  virtual void firstRechargeGiftOK(bool isFlag) override;
  virtual void agencyActivity(uint16_t type, bool isFlag) override;
  virtual void updateFestival(Ref<COM_ADLoginTotal> festival) override;
  virtual void updateSelfRecharge(Ref<COM_ADChargeTotal> val) override;
  virtual void updateSysRecharge(Ref<COM_ADChargeTotal> val) override;
  virtual void updateSelfDiscountStore(Ref<COM_ADDiscountStore> val) override;
  virtual void updateSysDiscountStore(Ref<COM_ADDiscountStore> val) override;
  virtual void updateSelfOnceRecharge(Ref<COM_ADChargeEvery> val) override;
  virtual void updateSysOnceRecharge(Ref<COM_ADChargeEvery> val) override;
  virtual void openCardOK(Ref<COM_ADCardsContent> data) override;
  virtual void resetCardOK() override;
  virtual void sycnHotRole(Ref<COM_ADHotRole> data) override;
  virtual void hotRoleBuyOk(uint16_t buyNum) override;
  virtual void updateSevenday(Ref<COM_Sevenday> data) override;
  virtual void updateEmployeeActivity(Ref<COM_ADEmployeeTotal> data) override;
  virtual void updateMinGiftActivity(Ref<COM_ADGiftBag> data) override;
  virtual void updateIntegralShop(Ref<COM_IntegralData> data) override;
  virtual void updateShowBaby(uint32_t playerId, uint32_t showBabyTableId,
                              String showBabyName) override;
  virtual void updateMySelfRecharge(Ref<COM_ADChargeTotal> val) override;
  virtual void verificationSMSOk(String phoneNumber) override;
  virtual void requestLevelGiftOK(int32_t level) override;
  virtual void sycnConvertExp(int32_t val) override;
  virtual void wearFuwenOk(Ref<COM_Item> inst) override;
  virtual void takeoffFuwenOk(int32_t slot) override;
  virtual void compFuwenOk() override;
  virtual void
  requestEmployeeQuestOk(TypedArray<COM_EmployeeQuestInst> questList) override;
  virtual void acceptEmployeeQuestOk(Ref<COM_EmployeeQuestInst> inst) override;
  virtual void submitEmployeeQuestOk(int32_t questId, bool isSuccess) override;
  virtual void sycnCrystal(Ref<COM_CrystalData> data) override;
  virtual void crystalUpLeveResult(bool isOK) override;
  virtual void resetCrystalPropOK() override;
  virtual void sycnCourseGift(TypedArray<COM_CourseGift> data) override;
  virtual void orderOk(String orderId, int32_t shopId) override;
  virtual void updateRandSubmitQuestCount(int32_t submitCount) override;
  virtual void updateTeamMember(int32_t playerId, bool isMember) override;

};

} // namespace godot

#endif // __GODOT_SERVER_PROXY_H__
