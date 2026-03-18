#ifndef __proto_godot_h__
#define __proto_godot_h__

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/core/class_db.hpp>
#include "ProtocolReader.h"
#include "ProtocolWriter.h"
#include "FieldMask.h"

using namespace godot;

enum MajorVersion {
	Major_0,
	MajorNumber,
};
enum MinorVersion {
	Minor_0,
	Minor_1,
	Minor_2,
	Minor_3,
	Minor_4,
	Minor_5,
	Minor_6,
	MinorNumber,
};
enum PatchVersion {
	Patch_0,
	Patch_1,
	Patch_2,
	Patch_3,
	Patch_4,
	Patch_5,
	PatchNumber,
};
enum PetQuality {
	PE_None,
	PE_White,
	PE_Green,
	PE_Blue,
	PE_Purple,
	PE_Golden,
	PE_Orange,
	PE_Pink,
};
enum ErrorNo {
	EN_None,
	EN_VersionNotMatch,
	EN_AccountNameSame,
	EN_PlayerNameSame,
	EN_FilterWord,
	EN_CannotfindPlayer,
	EN_AcceptQuestNotFound,
	EN_AcceptQuestNoItem,
	EN_AcceptSecendDaily,
	EN_DailyNoNum,
	EN_AcceptSecendProfession,
	EN_Battle,
	EN_MoneyLess,
	EN_DiamondLess,
	EN_NoSubSyste,
	EN_InTeam,
	EN_NoTeamLeader,
	EN_TeamPassword,
	EN_TeamIsFull,
	EN_NoTeam,
	EN_TeamIsRunning,
	EN_TeamMemberLeaving,
	EN_NoBackTeam,
	EN_InTeamBlackList,
	EN_EmployeeIsFull,
	EN_NoUpSkill,
	EN_PropisNull,
	EN_DoubleExpTimeFull,
	EN_DoubleExpTimeNULL,
	EN_NoTeamNoTongji,
	EN_TongjiTimesMax,
	EN_TongjiTeamMemberTimesMax,
	EN_NoTeamLeaderNoTongji,
	EN_TeamSizeTongjiError,
	EN_GetPoisonMushroom,
	EN_GetMushroom,
	EN_TongjiTeamLevelTooLow,
	EN_PlayerIsInTeam,
	EN_AcceptQuestBagMax,
	EN_SubmitQuestBagMax,
	EN_GuildNameSame,
	EN_PlayerGoldLess,
	EN_PlayerHasGuild,
	EN_InRequestErr,
	EN_RequestListFull,
	EN_joinGuildRequestOk,
	EN_JoinOtherGuild,
	EN_PremierQuitError,
	EN_CommandPositionLess,
	EN_PositionUpMax,
	EN_MallBuyOk,
	EN_MallBuyFailBagFull,
	EN_MallBuyFailBabyFull,
	EN_MallBuyFailDiamondLess,
	EN_MallBuyFailSelled,
	EN_OpenBaoXiangBagFull,
	EN_NoBaby,
	EN_BagFull,
	EN_BagSizeMax,
	EN_BabyStorageFull,
	EN_BabyFullToStorage,
	EN_NewItemError,
	EN_BabyFull,
	EN_RemouldBabyLevel,
	EN_SkillSoltFull,
	EN_WorldChatPayError,
	EN_DontTalk,
	EN_BadMushroom,
	EN_ItemMushroom,
	EN_GetMailItemBagFull,
	EN_Materialless,
	EN_OpenGatherlose,
	EN_OpenGatherRepetition,
	EN_GatherLevelLess,
	EN_GatherTimesLess,
	EN_OpenBaoXiangLevel,
	EN_NoBattleBaby,
	EN_NoThisPoint,
	EN_BabyLevelHigh,
	EN_AddMoney1W,
	EN_AddDionmand100,
	EN_AddMoney2W,
	EN_AddDionmand200,
	EN_AddMoney3W,
	EN_AddDionmand300,
	EN_AddMoney4W,
	EN_AddDionmand400,
	EN_AddMoney5W,
	EN_AddDionmand500,
	EN_AddMoney6W,
	EN_AddDionmand600,
	EN_DelBaby1000,
	EN_DelBaby30,
	EN_DelBaby54,
	EN_DelBaby10030,
	EN_DelBaby10015,
	EN_DelBaby10157,
	EN_DelDefaultSkill,
	EN_GreenBoxFreeNum,
	EM_NotNormalVip,
	EN_NotSuperVip,
	EN_FirendNotOpen,
	EN_BlackCannotFriend,
	EN_HasFriend,
	EN_HunderdNoNum,
	EN_HunderdTier,
	EN_HunderdLevel,
	EN_SkillExperr,
	EN_TimeMushroom,
	EN_TimeTongji,
	EN_TimeXiji,
	EN_Storefull,
	EN_HasBattleTime,
	EN_HourLess24,
	EN_HourLess24_Join,
	EN_TeamMemberHourLess24,
	EN_GuildBattleJoinSceneMoveValue,
	EN_IdgenNull,
	EN_Idgenhas,
	EN_Gifthas,
	EN_UseMakeRepeat,
	EN_WishNull,
	EN_NoGuild,
	EN_GuildMemberMax,
	EN_LevelupGuildBuilding,
	EN_LevelupGuildBuildingLevelMax,
	EN_LevelupGuildBuildingMoneyLess,
	EN_LevelupGuildBuildingHallBuildLevelLess,
	EN_AddGuildMoneyMax,
	EN_PresentGuildOk,
	EN_RefreshShopTimeLess,
	EN_TeamMemberNoGuild,
	EN_MagicCurrencyLess,
	EN_DisShopLimitLess,
	EN_FamilyPremierCanntDelete,
	EN_MyFamilyMonster,
	EN_NoBattleTime,
	EN_OtherNoBattleTime,
	EN_GuildBattleTimeout2,
	EN_GuildBattleHasTeam,
	EN_AccountIsSeal,
	EN_PlayerNoOnline,
	EN_ActivityNoTime,
	EN_NoTeamExist,
	EN_GuildNoMember,
	EN_MallSellTimeLess,
	EN_GuildMemberLess24,
	EN_InviteeLeaveGuildLess24,
	EN_PboneNumberSuccess,
	EN_PhoneNumberError,
	EN_OtherPlayerInBattle,
	EN_GuildBattleNotMatch,
	EN_GuildBattleIsStart,
	EN_GuileBattleIsClose,
	EN_GuildBattleTeamNoSameGuild,
	EN_BackTeamCommandLeaderInGuildHomeSceneAndYouAreNotSameGuild,
	EN_AccecptRandQuestSizeLimitError,
	EN_Max,
};
enum OperateType {
	OT_0,
	OT_P1,
	OT_P2,
	OT_B,
};
enum BindType {
	BIT_None,
	BIT_Bag,
	BIT_Use,
	BIT_Max,
};
enum ReconnectType {
	RECT_None,
	RECT_LoginOk,
	RECT_EnterGameOk,
	RECT_JoinTeamOk,
	RECT_EnterSceneOk,
	RECT_EnterBattleOk,
	RECT_Max,
};
enum SexType {
	ST_Unknown,
	ST_Male,
	ST_Female,
};
enum BattleType {
	BT_None,
	BT_PVE,
	BT_PVR,
	BT_PVP,
	BT_PVH,
	BT_PET,
	BT_PK1,
	BT_PK2,
	BT_Guild,
	BT_MAX,
};
enum EntityType {
	ET_None,
	ET_Player,
	ET_Baby,
	ET_Monster,
	ET_Boss,
	ET_Emplyee,
	ET_Max,
};
enum MineType {
	MT_None,
	MT_JinShu,
	MT_MuCai,
	MT_BuLiao,
	MT_Max,
};
enum GroupType {
	GT_None,
	GT_Up,
	GT_Down,
};
enum SkillTargetType {
	STT_None,
	STT_Self,
	STT_Team,
	STT_TeamDead,
	STT_TeamNoSelf,
	STT_All,
	STT_AllNoSelf,
	STT_Max,
};
enum SkillType {
	SKT_None,
	SKT_DefaultSecActive,
	SKT_DefaultSecPassive,
	SKT_DefaultActive,
	SKT_DefaultPassive,
	SKT_Active,
	SKT_Passive,
	SKT_Gather,
	SKT_Make,
	SKT_CannotUse,
	SKT_GuildPlayerSkill,
	SKT_GuildBabySkill,
	SKT_Max,
};
enum PassiveType {
	PAT_None,
	PAT_Buff,
	PAT_Deference,
	PAT_Dodge,
	PAT_Counter,
	PAT_Change,
	PAT_Guard,
	PAT_Runaway,
	PAT_BabyInnout,
	PAT_SecKill,
};
enum PlayerStatus {
	PS_Idle,
	PS_Login,
	PS_Game,
	PS_Logout,
	PS_Illegal,
};
enum OccupationType {
	OT_None,
	OT_HeavyArmor,
	OT_LightArmor,
	OT_Spell,
	OT_Max,
};
enum PeriodType {
	PT_Daily,
	PT_Weekly,
	PT_Customly,
};
enum JobType {
	JT_None,
	JT_Newbie,
	JT_Axe,
	JT_Sword,
	JT_Knight,
	JT_Archer,
	JT_Fighter,
	JT_Ninja,
	JT_Mage,
	JT_Sage,
	JT_Wizard,
	JT_Word,
};
enum RaceType {
	RT_None,
	RT_Human,
	RT_Insect,
	RT_Plant,
	RT_Extra,
	RT_Dragon,
	RT_Animal,
	RT_Fly,
	RT_Undead,
	RT_Metal,
	RT_Max,
};
enum BabyInitGear {
	BIG_None,
	BIG_Stama,
	BIG_Strength,
	BIG_Power,
	BIG_Speed,
	BIG_Magic,
	BIG_Max,
};
enum QualityColor {
	QC_None,
	QC_White,
	QC_Green,
	QC_Blue,
	QC_Blue1,
	QC_Purple,
	QC_Purple1,
	QC_Purple2,
	QC_Golden,
	QC_Golden1,
	QC_Golden2,
	QC_Orange,
	QC_Orange1,
	QC_Orange2,
	QC_Pink,
	QC_Max,
};
enum PropertyType {
	PT_None,
	PT_NoSleep,
	PT_NoPetrifaction,
	PT_NoDrunk,
	PT_NoChaos,
	PT_NoForget,
	PT_NoPoison,
	PT_Assassinate,
	PT_Money,
	PT_Diamond,
	PT_MagicCurrency,
	PT_EmployeeCurrency,
	PT_Gather,
	PT_Level,
	PT_Exp,
	PT_ConvertExp,
	PT_OneDayReputation,
	PT_Reputation,
	PT_TableId,
	PT_AssetId,
	PT_Sex,
	PT_BagNum,
	PT_Race,
	PT_Profession,
	PT_ProfessionLevel,
	PT_Stama,
	PT_Strength,
	PT_Power,
	PT_Speed,
	PT_Magic,
	PT_Durability,
	PT_HpCurr,
	PT_MpCurr,
	PT_HpMax,
	PT_MpMax,
	PT_Attack,
	PT_Defense,
	PT_Agile,
	PT_Spirit,
	PT_Reply,
	PT_Magicattack,
	PT_Magicdefense,
	PT_Damage,
	PT_SneakAttack,
	PT_Hit,
	PT_Dodge,
	PT_Crit,
	PT_counterpunch,
	PT_Front,
	PT_Wind,
	PT_Land,
	PT_Water,
	PT_Fire,
	PT_Free,
	PT_Title,
	PT_GuildID,
	PT_Glamour,
	PT_DoubleExp,
	PT_TongjiComplateTimes,
	PT_VipLevel,
	PT_VipTime,
	PT_FightingForce,
	PT_Max,
};
enum VipLevel {
	VL_None,
	VL_1,
	VL_2,
	VL_Max,
};
enum ItemMainType {
	IMT_None,
	IMT_Quest,
	IMT_Consumables,
	IMT_Equip,
	IMT_Employee,
	IMT_EmployeeEquip,
	IMT_Debris,
	IMT_FuWen,
	IMT_BabyEquip,
	IMT_Max,
};
enum ItemSubType {
	IST_None,
	IST_Axe,
	IST_Sword,
	IST_Spear,
	IST_Bow,
	IST_Stick,
	IST_Knife,
	IST_Hat,
	IST_Helmet,
	IST_Clothes,
	IST_Robe,
	IST_Armor,
	IST_Boot,
	IST_Shoes,
	IST_Shield,
	IST_Crystal,
	IST_Charm,
	IST_Earrings,
	IST_Bracelet,
	IST_Ring,
	IST_Necklace,
	IST_Headband,
	IST_Instruments,
	IST_EquipMax,
	IST_Ornament,
	IST_Lottery,
	IST_Coupun,
	IST_OpenGird,
	IST_ConsBegin,
	IST_Consumables,
	IST_Blood,
	IST_Buff,
	IST_Gem,
	IST_Material,
	IST_ItemDebris,
	IST_BabyDebris,
	IST_EmployeeDebris,
	IST_BabyExp,
	IST_SkillExp,
	IST_ConsEnd,
	IST_Gloves,
	IST_EmployeeEquip,
	IST_PVP,
	IST_Fashion,
	IST_FuWenAttack,
	IST_FuWenDefense,
	IST_FuWenAssist,
	IST_Max,
};
enum ItemUseFlag {
	IUF_None,
	IUF_Battle,
	IUF_Scene,
	IUF_All,
};
enum EquipmentSlot {
	ES_None,
	ES_Boot,
	ES_SingleHand,
	ES_Ornament_0,
	ES_Head,
	ES_Ornament_1,
	ES_Body,
	ES_DoubleHand,
	ES_Crystal,
	ES_Fashion,
	ES_Max,
};
enum WeaponType {
	WT_None,
	WT_Axe,
	WT_Sword,
	WT_Spear,
	WT_Bow,
	WT_Stick,
	WT_Knife,
	WT_Hoe,
	WT_Pickax,
	WT_Lumberaxe,
	WT_Gloves,
	WT_Max,
};
enum ChatKind {
	CK_None,
	CK_World,
	CK_Team,
	CK_System,
	CK_Friend,
	CK_GM,
	CK_Guild,
	CK_Max,
};
enum BattlePosition {
	BP_None,
	BP_Down0,
	BP_Down1,
	BP_Down2,
	BP_Down3,
	BP_Down4,
	BP_Down5,
	BP_Down6,
	BP_Down7,
	BP_Down8,
	BP_Down9,
	BP_Up0,
	BP_Up1,
	BP_Up2,
	BP_Up3,
	BP_Up4,
	BP_Up5,
	BP_Up6,
	BP_Up7,
	BP_Up8,
	BP_Up9,
	BP_Max,
};
enum BattleJudgeType {
	BJT_None,
	BJT_Continue,
	BJT_Win,
	BJT_Lose,
};
enum OrderParamType {
	OPT_None,
	OPT_BabyId,
	OPT_Unite,
	OPT_Huwei,
	OPT_IsNo,
	OPT_Max,
};
enum OrderStatus {
	OS_None,
	OS_ActiveOk,
	OS_RunawayOk,
	OS_FangBaobao,
	OS_ShouBaobao,
	OS_Weapon,
	OS_Zhuachong,
	OS_Flee,
	OS_Summon,
};
enum AIEvent {
	ME_None,
	ME_Born,
	ME_Deadth,
	ME_AttackGo,
	ME_SkillGO,
	ME_Update,
	ME_Max,
};
enum SyncIPropType {
	SPT_None,
	SPT_Player,
	SPT_Baby,
	SPT_Employee,
	SPT_Max,
};
enum BoxType {
	BX_None,
	BX_Normal,
	BX_Blue,
	BX_Glod,
};
enum QuestKind {
	QK_None,
	QK_Main,
	QK_Daily,
	QK_Profession,
	QK_Sub,
	QK_Tongji,
	QK_Copy,
	QK_Wishing,
	QK_Guild,
	QK_Rand,
	QK_Sub1,
	QK_Max,
};
enum QuestType {
	QT_None,
	QT_Dialog,
	QT_Battle,
	QT_Kill,
	QT_KillAI,
	QT_Item,
	QT_Profession,
	QT_Other,
	QT_GiveItem,
	QT_GiveBaby,
	QT_Max,
};
enum RequireType {
	RT_Nil,
};
enum TeamType {
	TT_None,
	TT_MainQuest,
	TT_TongjiQuest,
	TT_Daochang,
	TT_CaoMoGu,
	TT_Zhanchang,
	TT_Hero,
	TT_Pet,
	TT_JJC,
	TT_ShuaGuai,
	TT_Copy,
	TT_Max,
};
enum StateType {
	ST_None,
	ST_Normal,
	ST_Defense,
	ST_Dodge,
	ST_ActionAbsorb,
	ST_MagicAbsorb,
	ST_Shield,
	ST_ActionBounce,
	ST_MagicBounce,
	ST_ActionInvalid,
	ST_MagicInvalid,
	ST_Defend,
	ST_NoDodge,
	ST_Poison,
	ST_Basilisk,
	ST_Sleep,
	ST_Chaos,
	ST_Drunk,
	ST_Forget,
	ST_BeatBack,
	ST_Recover,
	ST_StrongRecover,
	ST_GroupRecover,
	ST_MagicDef,
	ST_Max,
};
enum SceneType {
	SCT_None,
	SCT_New,
	SCT_Home,
	SCT_Scene,
	SCT_City,
	SCT_Bairen,
	SCT_Instance,
	SCT_AlonePK,
	SCT_TeamPK,
	SCT_GuildHome,
	SCT_GuildBattleScene,
	SCT_Max,
};
enum BornType {
	BOT_None,
	BOT_BornPos,
	BOT_Cached,
	BOT_FromSceneEntry,
	BOT_FromMazeEntry,
	BOT_NormalMazeEntry,
	BOT_Max,
};
enum WeaponActionType {
	WAT_None,
	WAT_Chop,
	WAT_Stab,
	WAT_Bow,
	WAT_Throw,
	WAT_Max,
};
enum SceneOutpuType {
	SOT_None,
	SOT_PVE,
	SOT_PVP,
	SOT_Max,
};
enum TogetherStateType {
	TST_None,
	TST_Self,
	TST_Enemy,
	TST_Max,
};
enum GuideAimType {
	GAT_None,
	GAT_FirstAchievement,
	GAT_FirstSkill,
	GAT_FirstLevelSkill,
	GAT_FirstQuest,
	GAT_DialogUI,
	GAT_MainTeamBtn,
	GAT_MainTaskBtn,
	GAT_QuestMiniFirst,
	GAT_QuestMiniSecond,
	GAT_QuestMiniThird,
	GAT_MainCrystal,
	GAT_MainCastle,
	GAT_MainJJC,
	GAT_OfflineJJC,
	GAT_OfflineJJC4,
	GAT_WorldMapER,
	GAT_WorldMapFL,
	GAT_WorldMapWorldBtn,
	GAT_MiniMap,
	GAT_TeamCreateBtn,
	GAT_TeamWorldMapBtn,
	GAT_FirstPartner_PosUI,
	GAT_FreeLootPartner,
	GAT_FriendAddBtn,
	GAT_PartnerShowCancel,
	GAT_PartnerPositionTab,
	GAT_PartnerDetailBaseTab,
	GAT_PartnerDetailBodySlot,
	GAT_PartnerDetailEquipBtn,
	GAT_PartnerDetailBaseFirstSkill,
	GAT_PartnerDetailBaseSkillLvUpBtn,
	GAT_LearnSkillAttackSkillTab,
	GAT_LearnSkillAttackMagicTab,
	GAT_LearnSkillStatusMagicTab,
	GAT_LearnSkillAidSkillTab,
	GAT_LearnSkillBtn,
	GAT_FirstLearningBabySkill,
	GAT_FirstLearningBabySkill_BabyList,
	GAT_ThirdLearningBabySkill_SkillSlot,
	GAT_BabySkillLearningBtn,
	GAT_MessageBoxOkBtn,
	GAT_MainReturn,
	GAT_MainBag,
	GAT_MainBagTipUseItem,
	GAT_MainbagTipEquip,
	GAT_MainBagFuwenTab,
	GAT_MainBagFuwenFirstItem,
	GAT_MainBagFuwenTipsCombieBtn,
	GAT_MainBagFuwenTipsInsertBtn,
	GAT_MainFuwenUICombieBtn,
	GAT_MainFuwenCloseBtn,
	GAT_MainSkill,
	GAT_MainMake,
	GAT_MainMakeSword,
	GAT_MainMakeAxe,
	GAT_MainMakeStick,
	GAT_MainMakeBow,
	GAT_MainMakeCompoundBtn,
	GAT_MainMakeLevel10,
	GAT_MainMakeSubFirst,
	GAT_MainMakeSubSecond,
	GAT_MainMakeSubThird,
	GAT_MainMakeGemBtn,
	GAT_MainMakeGemClose,
	GAT_MainMakeGemFirst,
	GAT_MainBaby,
	GAT_MainBabyStatusBtn,
	GAT_MainBabyPropertyBtn,
	GAT_MainBabyPropertyContainer,
	GAT_MainBabyPropertyConfirm,
	GAT_MainBabyClose,
	GAT_MainMagic,
	GAT_MainMagicLevelFirst,
	GAT_MainMagicLevelBtn,
	GAT_MainFriend,
	GAT_MainPartner,
	GAT_MainSetting,
	GAT_MainRecharge,
	GAT_MainActivity,
	GAT_MainPlayerInfo,
	GAT_MainPlayerInfoStatusBtn,
	GAT_MainPlayerInfoPropertyBtn,
	GAT_MainPlayerInfoPropertyContainer,
	GAT_MainPlayerInfoPropertyConfirm,
	GAT_MainPlayerInfoClose,
	GAT_MainJiubaHouse,
	GAT_MainStick,
	GAT_MainAchievement,
	GAT_MainRaise,
	GAT_MainFamily,
	GAT_BattleAttack,
	GAT_BattleSkill,
	GAT_BattleBabySkill,
	GAT_BattleDeference,
	GAT_BattleChangePosition,
	GAT_BattleAuto,
	GAT_BattleBag,
	GAT_BattleCatch,
	GAT_BattleBaby,
	GAT_BattleRunaway,
	GAT_BattlePlayerInfo,
	GAT_BattleRewardClose,
	GAT_FirstAutoSkill,
	GAT_PlayerAuto,
	GAT_Max,
};
enum ScriptGameEvent {
	SGE_None,
	SGE_MainPanelOpen,
	SGE_FirstEnterMainScene,
	SGE_EnterScene,
	SGE_EnterMainScene,
	SGE_Talk_FirstEnterMainScene,
	SGE_Talk_BattleReady,
	SGE_Talk_ActorReady,
	SGE_Talk_BattleOver,
	SGE_WorldMapOpen,
	SGE_WorldMapToWorld,
	SGE_MiniMapOpen,
	SGE_TeamUIOpen,
	SGE_AchievementUIOpen,
	SGE_AchievementReceived,
	SGE_TeamUISelectMapOpen,
	SGE_PartnerForBattle,
	SGE_PartnerPositionTabShow,
	SGE_PartnerListTabShow,
	SGE_PartnerDetailUIOpen,
	SGE_PartnerDetailBaseOpen,
	SGE_PartnerDetailEquipClick,
	SGE_PartnerDetailEquipSucc,
	SGE_PartnerDetailBaseSkillOpen,
	SGE_ParnterDetailBaseSkillLvUpSucc,
	SGE_MainMakeSub,
	SGE_MainMakeSubDetail,
	SGE_MainMakeItemOk,
	SGE_MainMakeGemUI,
	SGE_MainMakeGemOk,
	SGE_MainMakeGemUIClose,
	SGE_MainTeamUI,
	SGE_MainTaskUI,
	SGE_MainTaskFlushOk,
	SGE_JJCEntryUI,
	SGE_OfflineJJCUI,
	SGE_BagItemDoubleClick,
	SGE_BagFuwenOpen,
	SGE_BagFuwenCombieUI,
	SGE_BagFuwenCombieSuccess,
	SGE_BagFuwenClickTipsInsertBtn,
	SGE_FuwenUIClose,
	SGE_NpcDialogBegin,
	SGE_NpcRenwuUIOpen,
	SGE_NpcRenwuPreAccept,
	SGE_NpcRenwuAccept,
	SGE_NpcRenwuSubmit,
	SGE_EnterNPCBattle,
	SGE_EnterBattle,
	SGE_MessageBoxOpen,
	SGE_BeforeEnterBattle,
	SGE_PlayerLevelUp,
	SGE_PlayerUIOpen,
	SGE_PlayerUIStatusSwitch,
	SGE_PlayerUIPropertySwitch,
	SGE_PlayerUIAddPoint,
	SGE_PlayerUIPropertyConfirmClick,
	SGE_PlayerUIClose,
	SGE_BabyLevelUp,
	SGE_BabyUIOpen,
	SGE_BabyUIStatusSwitch,
	SGE_BabyUIPropertySwitch,
	SGE_BabyUIAddPoint,
	SGE_BabyUIPropertyConfirmClick,
	SGE_BabyUIClose,
	SGE_BattleTurn,
	SGE_ExitBattle,
	SGE_SelectTarget,
	SGE_SelectTargetOk,
	SGE_BabySelectSkill,
	SGE_SelectSkill,
	SGE_SelectSkillLevel,
	SGE_StickDisplay,
	SGE_StickTouchDown,
	SGE_StickTouchMove,
	SGE_StickTouchUp,
	SGE_BattleOverRewardOpen,
	SGE_BattleOverRewardClose,
	SGE_CheckState,
	SGE_TogetherState,
	SGE_BagTipOpen,
	SGE_UseItem,
	SGE_GainItem,
	SGE_EquipItem,
	SGE_MainLearningUI,
	SGE_MainLearningClickTab,
	SGE_MainLearningOneSkillClick,
	SGE_MainLearningSkillOk,
	SGE_MainMakeUIOpen,
	SGE_MainMagicTipClose,
	SGE_MainMagicUIOpen,
	SGE_MainMagicLevelUp,
	SGE_MainMagicFirstClick,
	SGE_PartnerShowUI,
	SGE_PartnerHideUI,
	SGE_BabyLearningSkillUI,
	SGE_BabyLearningSkill_BabyListUI,
	SGE_BabyLearningSkill_BabySkillUI,
	SGE_BabyLearningSkillOk,
	SGE_ClickBabyLearningSkill,
	SGE_ClickMiniQuest,
	SGE_ClickMainBag,
	SGE_ClickMainSkill,
	SGE_ClickMainBaby,
	SGE_ClickMainFriend,
	SGE_ClickMainPartner,
	SGE_ClickMainSetting,
	SGE_ClickMainRecharge,
	SGE_ClickMainActivity,
	SGE_ClickMainInfo,
	SGE_ClickBattleAttack,
	SGE_ClickBattleSkill,
	SGE_ClickBattleBabySkill,
	SGE_ClickBattleDeference,
	SGE_ClickBattleChangePosition,
	SGE_ClickBattleAuto,
	SGE_ClickBattleBag,
	SGE_ClickBattleBaby,
	SGE_ClickBattleRunaway,
	SGE_ClickBattleInfo,
	SGE_ClickAddFriendBtn,
	SGE_ClickMainFamily,
	SGE_ClickRaiseUpBtn,
	SGE_UseItemOk,
	SGE_CheckBuff,
	SGE_PlayerPropUpdate,
	SGE_NpcTalked,
	SGE_EnterCopy,
	SGE_PlayerAutoOrder,
	SGE_OpenAutoPanel,
	SGE_SenseEnter2,
	SGE_WaitTalk,
	SGE_SenseTalked,
	SGE_ExitSense,
	SGE_Max,
};
enum SenseActorType {
	SAT_Guard,
	SAT_Ambassdor,
	SAT_King,
	SAT_Yingzi,
	SAT_VillageKing,
	SAT_Archor,
	SAT_Axe,
	SAT_Sage,
	SAT_Mage,
	SAT_Girl,
	SAT_AllMonster,
};
enum GameEventType {
	GET_None,
	GET_Online,
	GET_Offline,
	GET_CreatePlayerOK,
	GET_Kill,
	GET_Die,
	GET_LevelUp,
	GET_Flee,
	GET_LearnSkill,
	GET_SkillLevelUp,
	GET_UseSkill,
	GET_EnterJJC,
	GET_MakeEquip,
	GET_RecruitEmp,
	GET_EmployeeEvolve,
	GET_AddBaby,
	GET_DelBaby,
	GET_CatchBaby,
	GET_DepositBaby,
	GET_BabyLevelUp,
	GET_ResetBaby,
	GET_BabyNo,
	GET_BabyLearnSkill,
	GET_AddSkillExp,
	GET_HalfHourAgo,
	GET_Sign,
	GET_BattleChangeProp,
	GET_BattleOver,
	GET_TalkNpc,
	GET_Activity,
	GET_PvR,
	GET_JJC,
	GET_Challenge,
	GET_Zhuanpan,
	GET_Richang,
	GET_Pet,
	GET_Tongji,
	GET_Babyintensify,
	GET_CreateGuild,
	GET_JoinGuild,
	GET_GuildBattleWin,
	GET_GuildBattleLose,
	GET_OpenGuildBattle,
	GET_CloseGuildBattle,
	GET_OpenGuildDemonInvaded,
	GET_CloseGuildDemonInvaded,
	GET_OpenGuildLeaderInvaded,
	GET_CloseGuildLeaderInvaded,
	GET_Exam,
	GET_Wish,
	GET_ChangeMoney,
	GET_ChangeDiamond,
	GET_ChangeMagicCurrency,
	GET_WearEquip,
	GET_AddFleeProp,
	GET_Gather,
	GET_AddFriend,
	GET_ExtendStorage,
	GET_FinishAch,
	GET_AddTeamMemberCondition,
	GET_Shenqishengji,
	GET_NewServer,
	GET_Recharge,
	GET_PhoneNumber,
	GET_ChangeProfession,
	GET_BagFullSendMail,
	GET_WearFuwen,
	GET_Max,
};
enum SneakAttackType {
	SAT_None,
	SAT_SneakAttack,
	SAT_SurpriseAttack,
	SAT_Max,
};
enum ShopType {
	SIT_None,
	SIT_FirstRecharge,
	SIT_Recharge,
	SIT_Shop,
	SIT_EmployeeShop,
	SIT_VIP,
	SIT_Fund,
	SIT_Giftbag,
	SIT_CourseGiftBag,
	SIT_Equip,
	SIT_Max,
};
enum ShopPayType {
	SPT_Nil,
	SPT_RMB,
	SPT_Diamond,
	SPT_MagicCurrency,
	SPT_Gold,
};
enum GuidePointerRotateType {
	GPRT_None,
	GPRT_R45,
	GPRT_R90,
	GPRT_R135,
	GPRT_R180,
	GPRT_R225,
	GPRT_R270,
	GPRT_R315,
	GPRT_Max,
};
enum NpcType {
	NT_None,
	NT_Normal,
	NT_Tongji,
	NT_SinglePK,
	NT_TeamPK,
	NT_Mogu,
	NT_Xiji,
	NT_Caiji1,
	NT_Caiji2,
	NT_Caiji3,
	NT_Max,
};
enum OpenSubSystemFlag {
	OSSF_None,
	OSSF_Skill,
	OSSF_Baby,
	OSSF_Friend,
	OSSF_EmployeeGet,
	OSSF_EmployeeList,
	OSSF_EmployeePosition,
	OSSF_EmployeeEquip,
	OSSF_Bar,
	OSSF_Castle,
	OSSF_JJC,
	OSSF_PVPJJC,
	OSSF_Make,
	OSSF_Hundred,
	OSSF_Activity,
	OSSF_Handbook,
	OSSF_EveryTask,
	OSSF_Achieve,
	OSSF_Rank,
	OSSF_OnKyTalk,
	OSSF_Setting,
	OSSF_Shop,
	OSSF_DoubleExp,
	OSSF_Family,
	OSSF_AuctionHouse,
	OSSF_BabyLeranSkill,
	OSSF_MagicItem,
	OSSF_EmployeePos10,
	OSSF_EmployeePos15,
	OSSF_EmployeePos20,
	OSSF_Guid,
	OSSF_Team,
	OSSF_choujiang,
	OSSF_Cystal,
	OSSF_PetEquip,
	OSSF_Max,
};
enum AchievementType {
	AT_None,
	AT_EarnConis,
	AT_SpendMoney,
	AT_SpendDiamond,
	AT_Recharge,
	AT_RoleLevel,
	AT_PetLevel,
	AT_AttackLevel,
	AT_DefenseLevel,
	AT_AgileLevel,
	AT_WearCrystal,
	AT_WearAccessories,
	AT_TotalDamage,
	AT_TotalTreatment,
	AT_HasSkillNum,
	AT_BabySkill,
	AT_CatchPet,
	AT_RecruitPartner,
	AT_PartnerCard,
	AT_PartnersUpgradeGreen,
	AT_PartnersUpgradeBlue,
	AT_PartnersUpgradePurple,
	AT_PartnersUpgradeGold,
	AT_PartnersUpgradeOrangle,
	AT_PartnersUpgradePink,
	AT_QualifyingAdvanced,
	AT_ArenaWin,
	AT_KillMonster,
	AT_KillBoss,
	AT_KillPlayer,
	AT_MakeEquipment,
	AT_Reward50,
	AT_EverydayActivities,
	AT_Sign,
	AT_Wanted,
	AT_Copy30,
	AT_Copy40,
	AT_Blood,
	AT_Magic,
	AT_Bag,
	AT_PetBag,
	AT_GoodMake,
	AT_PetIntensive,
	AT_PetHuman,
	AT_PetInsect,
	AT_PetPlant,
	AT_PetExtra,
	AT_PetDragon,
	AT_PetAnimal,
	AT_PetFly,
	AT_PetUndead,
	AT_PetMetal,
	AT_Home,
	AT_CollectMaterial,
	AT_Friend,
	AT_Billboard,
	AT_OwnConis,
	AT_MagicEquip,
	AT_RunesLevel,
	AT_Max,
};
enum CategoryType {
	ACH_All,
	ACH_Growup,
	ACH_Battle,
	ACH_Pet,
	ACH_Partner,
	ACH_Illustrations,
	ACH_Max,
};
enum ClassifyType {
	SD_Debris,
	SD_Data,
	SD_Pet,
	SD_Fashion,
	SD_Diamond,
	SD_1Ji,
	SD_2Ji,
};
enum FunctionalPointType {
	FPT_None,
	FPT_Tongji,
	FPT_Mogu,
	FPT_Xiji,
	FPT_Npc,
	FPT_Max,
};
enum ActivityType {
	ACT_None,
	ACT_Tongji,
	ACT_Mogu,
	ACT_Richang,
	ACT_Pet,
	ACT_AlonePK,
	ACT_TeamPK,
	ACT_JJC,
	ACT_Challenge,
	ACT_Exam,
	ACT_Copy,
	ACT_Xuyuan,
	ACT_Family_0,
	ACT_Family_1,
	ACT_Family_2,
	ACT_Family_3,
	ACT_Family_4,
	ACT_Warrior,
	ACT_Money,
	ACT_Rand,
	ACT_Max,
};
enum MailType {
	MT_Normal,
	MT_System,
};
enum HelpType {
	HT_None,
	HT_Money,
	HT_Diamond,
	HT_Role,
	HT_Baby,
	HT_Employee,
	HT_Skill,
	HT_Exp,
	HT_Magic,
	HT_Equip,
};
enum GuildJob {
	GJ_None,
	GJ_People,
	GJ_Minister,
	GJ_SecretaryHead,
	GJ_VicePremier,
	GJ_Premier,
	GJ_Max,
};
enum ModifyListFlag {
	MLF_Add,
	MLF_Delete,
	MLF_ChangeOnline,
	MLF_ChangeOffline,
	MLF_ChangePosition,
	MLF_ChangeContribution,
	MLF_ChangeLevel,
	MLF_ChangeProfession,
	MLF_ChangeGuuildBattleCon,
};
enum GuildBuildingType {
	GBT_MIN,
	GBT_Main,
	GBT_Bank,
	GBT_Shop,
	GBT_Collection,
	GBT_Goddess,
	GBT_Progenitus,
	GBT_MAX,
};
enum SellItemType {
	SelIT_None,
	SelIT_Max,
};
enum DiamondConfigClass {
	DBT_Type_None,
	DBT_Type_Mine_Famu,
	DBT_Type_Mine_Caikuang,
	DBT_Type_Mine_Zhibu,
	DBT_Type_Max,
};
enum DiamondConfigType {
	DBT_None,
	DBT_Day,
	DBT_Week,
	DBT_Month,
	DBT_Max,
};
enum FixType {
	FT_None,
	FT_Money,
	FT_Diamond,
	FT_Max,
};
enum StorageType {
	ST_Item,
	ST_Baby,
};
enum EmployeesBattleGroup {
	EBG_None,
	EBG_Free,
	EBG_GroupOne,
	EBG_GroupTwo,
	EBG_Max,
};
enum GiftType {
	GFT_Bug,
	GFT_UC1,
	GFT_UC2,
	GFT_Group,
};
enum GMT_Protocol {
	GMT_None,
	GMT_GMCommand,
	GMT_Notice,
	GMT_InsertMail,
	GMT_QueryPlayer,
	GMT_LoginActivity,
	GMT_7Days,
	GMT_Cards,
	GMT_ExtractEmployee,
	GMT_ChargeTotal,
	GMT_ChargeEvery,
	GMT_DiscountStore,
	GMT_Foundation,
	GMT_LoginTotal,
	GMT_OnlineReward,
	GMT_HotRole,
	GMT_SelfChargeTotal,
	GMT_SelfChargeEvery,
	GMT_MinGiftBag,
	GMT_DoScript,
	GNT_MakeOrder,
	GMT_Zhuanpan,
	GMT_IntegralShop,
	GMT_QueryRoleList,
	GMT_QueryRMB,
	GMT_QueryDia,
	GMT_QueryMoney,
	GMT_MAX,
};
enum GMCommandType {
	GMCT_NoTalk,
	GMCT_Freeze,
	GMCT_Seal,
	GMCT_Kick,
	GMCT_OpenTalk,
	GMCT_Unseal,
	GMCT_SkipGuide,
	GMCT_AddMoney,
	GMCT_AddDiamond,
	GMCT_AddExp,
	GMCT_OpenGM,
	GMCT_CloseGM,
	GMCT_DoScript,
	GMCT_Max,
};
enum NoticeSendType {
	NST_Immediately,
	NST_Timming,
	NST_Loop,
};
enum InsertMailType {
	IGMT_PlayerId,
	IGMT_AllOnline,
	IGMT_AllRegist,
};
enum ItemContainerType {
	ICT_EquipContainer,
	ICT_BagContainer,
};
enum UIBehaviorType {
	UBT_None,
	UBT_Bag,
	UBT_Baby,
	UBT_Employee,
	UBT_SkillView,
	UBT_SkillLearn,
	UBT_Task,
	UBT_Make,
	UBT_Gather,
	UBT_MagicItem,
	UBT_Store,
	UBT_Help,
	UBT_Friend,
	UBT_Email,
	UBT_Auction,
	UBT_Activity,
	UBT_SignUp,
	UBT_EmployessList,
	UBT_EmployessPos,
	UBT_EmployessTavern,
	UBT_PlayerProperty,
	UBT_Max,
};
enum HelpRaiseType {
	HRT_None,
	HRT_PlayerAddProp,
	HRT_PlayerResetProp,
	HRT_PlayerAddEvolve,
	HRT_BabyAddProp,
	HRT_BabyReset,
	HRT_BabyStr,
	HRT_BabySkill,
	HRT_BabyChange,
	HRT_SkillAuto,
	HRT_SkillItem,
	HRT_EquipCompound,
	HRT_EquipGem,
	HRT_EmployeeBuy,
	HRT_EmployeePos,
	HRT_EmployeeSkill,
	HRT_EmployeeEquip,
	HRT_EmployeeEvolve,
	HRT_MagicLevelUp,
	HRT_MagicEvolve,
	HRT_Max,
};
enum SceneFilterType {
	SFT_None,
	SFT_Team,
	SFT_Friend,
	SFT_Guild,
	SFT_All,
	SFT_Max,
};
enum GatherStateType {
	GST_None,
	GST_Vulgar,
	GST_Advanced,
	GST_Max,
};
enum WishType {
	WIT_None,
	WIT_Exp,
	WIT_Money,
	WIT_Baby,
	WIT_Employee,
	WIT_Max,
};
enum ADType {
	ADT_None,
	ADT_7Days,
	ADT_Cards,
	ADT_ChargeTotal,
	ADT_ChargeEvery,
	ADT_DiscountStore,
	ADT_Foundation,
	ADT_LoginTotal,
	ADT_OnlineReward,
	ADT_HotRole,
	ADT_SelfChargeTotal,
	ADT_SelfChargeEvery,
	ADT_SelfDiscountStore,
	ADT_BuyEmployee,
	ADT_PhoneNumber,
	ADT_Level,
	ADT_Sign,
	ADT_GiftBag,
	ADT_Zhuanpan,
	ADT_IntegralShop,
	ADT_Max,
};
enum EmployeeSkillType {
	EKT_GroupDamage,
	EKT_DeadlyDamage,
	EKT_BattleTimeLimit,
	EKT_Thump,
	EKT_SiegeDamage,
	EKT_SuperMagic,
	EKT_Debuff,
	EKT_PhysicalDefense,
	EKT_Max,
};
enum EmployeeQuestColor {
	EQC_White,
	EQC_Blue,
	EQC_Purple,
	EQC_Max,
};
enum EmployeeQuestStatus {
	EQS_None,
	EQS_Running,
	EQS_Complate,
};
enum RobotActionType {
	RAT_None,
	RAT_Resting,
	RAT_Move,
	RAT_QuestMove,
	RAT_TeamMove,
	RAT_Max,
};
// struct SGE_OrderInfo
class SGE_OrderInfo : public Resource {
	GDCLASS(SGE_OrderInfo, Resource);
protected:
	int32_t productId_ = 0;
	int32_t productCount_ = 0;
	float amount_ = 0.0;
	String orderId_ = "";
	String payTime_ = "";
public:
	void set_productId_(int32_t p_val) { productId_ = p_val; }
	int32_t get_productId_() const { return productId_; }
	void set_productCount_(int32_t p_val) { productCount_ = p_val; }
	int32_t get_productCount_() const { return productCount_; }
	void set_amount_(float p_val) { amount_ = p_val; }
	float get_amount_() const { return amount_; }
	void set_orderId_(String p_val) { orderId_ = p_val; }
	String get_orderId_() const { return orderId_; }
	void set_payTime_(String p_val) { payTime_ = p_val; }
	String get_payTime_() const { return payTime_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADLoginTotalContent
class COM_ADLoginTotalContent : public Resource {
	GDCLASS(COM_ADLoginTotalContent, Resource);
protected:
	uint32_t totalDays_ = 0;
	TypedArray<uint32_t> itemIds_ = {};
	TypedArray<uint32_t> itemStacks_ = {};
	uint8_t status_ = 0;
public:
	void set_totalDays_(uint32_t p_val) { totalDays_ = p_val; }
	uint32_t get_totalDays_() const { return totalDays_; }
	void set_itemIds_(TypedArray<uint32_t> p_val) { itemIds_ = p_val; }
	TypedArray<uint32_t> get_itemIds_() const { return itemIds_; }
	void set_itemStacks_(TypedArray<uint32_t> p_val) { itemStacks_ = p_val; }
	TypedArray<uint32_t> get_itemStacks_() const { return itemStacks_; }
	void set_status_(uint8_t p_val) { status_ = p_val; }
	uint8_t get_status_() const { return status_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADLoginTotal
class COM_ADLoginTotal : public Resource {
	GDCLASS(COM_ADLoginTotal, Resource);
protected:
	int32_t loginDays_ = 0;
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADLoginTotalContent> contents_ = {};
public:
	void set_loginDays_(int32_t p_val) { loginDays_ = p_val; }
	int32_t get_loginDays_() const { return loginDays_; }
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADLoginTotalContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADLoginTotalContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADChargeTotalContent
class COM_ADChargeTotalContent : public Resource {
	GDCLASS(COM_ADChargeTotalContent, Resource);
protected:
	uint32_t currencyCount_ = 0;
	TypedArray<uint32_t> itemIds_ = {};
	TypedArray<uint32_t> itemStacks_ = {};
	uint8_t status_ = 0;
public:
	void set_currencyCount_(uint32_t p_val) { currencyCount_ = p_val; }
	uint32_t get_currencyCount_() const { return currencyCount_; }
	void set_itemIds_(TypedArray<uint32_t> p_val) { itemIds_ = p_val; }
	TypedArray<uint32_t> get_itemIds_() const { return itemIds_; }
	void set_itemStacks_(TypedArray<uint32_t> p_val) { itemStacks_ = p_val; }
	TypedArray<uint32_t> get_itemStacks_() const { return itemStacks_; }
	void set_status_(uint8_t p_val) { status_ = p_val; }
	uint8_t get_status_() const { return status_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADChargeTotal
class COM_ADChargeTotal : public Resource {
	GDCLASS(COM_ADChargeTotal, Resource);
protected:
	int32_t recharge_ = 0;
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADChargeTotalContent> contents_ = {};
public:
	void set_recharge_(int32_t p_val) { recharge_ = p_val; }
	int32_t get_recharge_() const { return recharge_; }
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADChargeTotalContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADChargeTotalContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADDiscountStoreContent
class COM_ADDiscountStoreContent : public Resource {
	GDCLASS(COM_ADDiscountStoreContent, Resource);
protected:
	uint32_t price_ = 0;
	uint32_t itemId_ = 0;
	float discount_ = 0.0;
	uint32_t buyLimit_ = 0;
public:
	void set_price_(uint32_t p_val) { price_ = p_val; }
	uint32_t get_price_() const { return price_; }
	void set_itemId_(uint32_t p_val) { itemId_ = p_val; }
	uint32_t get_itemId_() const { return itemId_; }
	void set_discount_(float p_val) { discount_ = p_val; }
	float get_discount_() const { return discount_; }
	void set_buyLimit_(uint32_t p_val) { buyLimit_ = p_val; }
	uint32_t get_buyLimit_() const { return buyLimit_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADDiscountStore
class COM_ADDiscountStore : public Resource {
	GDCLASS(COM_ADDiscountStore, Resource);
protected:
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADDiscountStoreContent> contents_ = {};
public:
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADDiscountStoreContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADDiscountStoreContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADChargeEveryContent
class COM_ADChargeEveryContent : public Resource {
	GDCLASS(COM_ADChargeEveryContent, Resource);
protected:
	uint32_t currencyCount_ = 0;
	TypedArray<uint32_t> itemIds_ = {};
	TypedArray<uint32_t> itemStacks_ = {};
	uint8_t status_ = 0;
	uint8_t count_ = 0;
public:
	void set_currencyCount_(uint32_t p_val) { currencyCount_ = p_val; }
	uint32_t get_currencyCount_() const { return currencyCount_; }
	void set_itemIds_(TypedArray<uint32_t> p_val) { itemIds_ = p_val; }
	TypedArray<uint32_t> get_itemIds_() const { return itemIds_; }
	void set_itemStacks_(TypedArray<uint32_t> p_val) { itemStacks_ = p_val; }
	TypedArray<uint32_t> get_itemStacks_() const { return itemStacks_; }
	void set_status_(uint8_t p_val) { status_ = p_val; }
	uint8_t get_status_() const { return status_; }
	void set_count_(uint8_t p_val) { count_ = p_val; }
	uint8_t get_count_() const { return count_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADChargeEvery
class COM_ADChargeEvery : public Resource {
	GDCLASS(COM_ADChargeEvery, Resource);
protected:
	int32_t currentCount_ = 0;
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADChargeEveryContent> contents_ = {};
public:
	void set_currentCount_(int32_t p_val) { currentCount_ = p_val; }
	int32_t get_currentCount_() const { return currentCount_; }
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADChargeEveryContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADChargeEveryContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADCardsContent
class COM_ADCardsContent : public Resource {
	GDCLASS(COM_ADCardsContent, Resource);
protected:
	uint32_t count_ = 0;
	uint32_t rewardId_ = 0;
public:
	void set_count_(uint32_t p_val) { count_ = p_val; }
	uint32_t get_count_() const { return count_; }
	void set_rewardId_(uint32_t p_val) { rewardId_ = p_val; }
	uint32_t get_rewardId_() const { return rewardId_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADCards
class COM_ADCards : public Resource {
	GDCLASS(COM_ADCards, Resource);
protected:
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADCardsContent> contents_ = {};
public:
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADCardsContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADCardsContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADHotRoleContent
class COM_ADHotRoleContent : public Resource {
	GDCLASS(COM_ADHotRoleContent, Resource);
protected:
	uint16_t type_ = (EntityType)0;
	uint32_t buyNum_ = 0;
	uint32_t roleId_ = 0;
	uint32_t price_ = 0;
public:
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_buyNum_(uint32_t p_val) { buyNum_ = p_val; }
	uint32_t get_buyNum_() const { return buyNum_; }
	void set_roleId_(uint32_t p_val) { roleId_ = p_val; }
	uint32_t get_roleId_() const { return roleId_; }
	void set_price_(uint32_t p_val) { price_ = p_val; }
	uint32_t get_price_() const { return price_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADHotRole
class COM_ADHotRole : public Resource {
	GDCLASS(COM_ADHotRole, Resource);
protected:
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADHotRoleContent> contents_ = {};
public:
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADHotRoleContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADHotRoleContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADEmployeeTotalContent
class COM_ADEmployeeTotalContent : public Resource {
	GDCLASS(COM_ADEmployeeTotalContent, Resource);
protected:
	uint32_t outputCount_ = 0;
	TypedArray<uint32_t> itemIds_ = {};
	TypedArray<uint32_t> itemStacks_ = {};
	uint8_t status_ = 0;
public:
	void set_outputCount_(uint32_t p_val) { outputCount_ = p_val; }
	uint32_t get_outputCount_() const { return outputCount_; }
	void set_itemIds_(TypedArray<uint32_t> p_val) { itemIds_ = p_val; }
	TypedArray<uint32_t> get_itemIds_() const { return itemIds_; }
	void set_itemStacks_(TypedArray<uint32_t> p_val) { itemStacks_ = p_val; }
	TypedArray<uint32_t> get_itemStacks_() const { return itemStacks_; }
	void set_status_(uint8_t p_val) { status_ = p_val; }
	uint8_t get_status_() const { return status_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADEmployeeTotal
class COM_ADEmployeeTotal : public Resource {
	GDCLASS(COM_ADEmployeeTotal, Resource);
protected:
	int32_t outputNum_ = 0;
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ADEmployeeTotalContent> contents_ = {};
public:
	void set_outputNum_(int32_t p_val) { outputNum_ = p_val; }
	int32_t get_outputNum_() const { return outputNum_; }
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ADEmployeeTotalContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ADEmployeeTotalContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GiftItem
class COM_GiftItem : public Resource {
	GDCLASS(COM_GiftItem, Resource);
protected:
	uint32_t itemId_ = 0;
	uint32_t itemNum_ = 0;
public:
	void set_itemId_(uint32_t p_val) { itemId_ = p_val; }
	uint32_t get_itemId_() const { return itemId_; }
	void set_itemNum_(uint32_t p_val) { itemNum_ = p_val; }
	uint32_t get_itemNum_() const { return itemNum_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ADGiftBag
class COM_ADGiftBag : public Resource {
	GDCLASS(COM_ADGiftBag, Resource);
protected:
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	bool isflag_ = false;
	uint8_t price_ = 0;
	uint8_t oldprice_ = 0;
	TypedArray<COM_GiftItem> itemdata_ = {};
public:
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_isflag_(bool p_val) { isflag_ = p_val; }
	bool get_isflag_() const { return isflag_; }
	void set_price_(uint8_t p_val) { price_ = p_val; }
	uint8_t get_price_() const { return price_; }
	void set_oldprice_(uint8_t p_val) { oldprice_ = p_val; }
	uint8_t get_oldprice_() const { return oldprice_; }
	void set_itemdata_(TypedArray<COM_GiftItem> p_val) { itemdata_ = p_val; }
	TypedArray<COM_GiftItem> get_itemdata_() const { return itemdata_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Sevenday
class COM_Sevenday : public Resource {
	GDCLASS(COM_Sevenday, Resource);
protected:
	uint32_t quest_ = 0;
	uint16_t stype_ = (AchievementType)0;
	uint32_t qvalue_ = 0;
	bool isfinish_ = false;
	bool isreward_ = false;
public:
	void set_quest_(uint32_t p_val) { quest_ = p_val; }
	uint32_t get_quest_() const { return quest_; }
	void set_stype_(uint16_t p_val) { stype_ = p_val; }
	uint16_t get_stype_() const { return stype_; }
	void set_qvalue_(uint32_t p_val) { qvalue_ = p_val; }
	uint32_t get_qvalue_() const { return qvalue_; }
	void set_isfinish_(bool p_val) { isfinish_ = p_val; }
	bool get_isfinish_() const { return isfinish_; }
	void set_isreward_(bool p_val) { isreward_ = p_val; }
	bool get_isreward_() const { return isreward_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ZhuanpanContent
class COM_ZhuanpanContent : public Resource {
	GDCLASS(COM_ZhuanpanContent, Resource);
protected:
	uint32_t id_ = 0;
	uint32_t item_ = 0;
	uint32_t itemNum_ = 0;
	uint32_t rate_ = 0;
	uint32_t maxdrop_ = 0;
public:
	void set_id_(uint32_t p_val) { id_ = p_val; }
	uint32_t get_id_() const { return id_; }
	void set_item_(uint32_t p_val) { item_ = p_val; }
	uint32_t get_item_() const { return item_; }
	void set_itemNum_(uint32_t p_val) { itemNum_ = p_val; }
	uint32_t get_itemNum_() const { return itemNum_; }
	void set_rate_(uint32_t p_val) { rate_ = p_val; }
	uint32_t get_rate_() const { return rate_; }
	void set_maxdrop_(uint32_t p_val) { maxdrop_ = p_val; }
	uint32_t get_maxdrop_() const { return maxdrop_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Zhuanpan
class COM_Zhuanpan : public Resource {
	GDCLASS(COM_Zhuanpan, Resource);
protected:
	String playerName_ = "";
	uint32_t zhuanpanId_ = 0;
public:
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_zhuanpanId_(uint32_t p_val) { zhuanpanId_ = p_val; }
	uint32_t get_zhuanpanId_() const { return zhuanpanId_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ZhuanpanData
class COM_ZhuanpanData : public Resource {
	GDCLASS(COM_ZhuanpanData, Resource);
protected:
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	TypedArray<COM_ZhuanpanContent> contents_ = {};
	TypedArray<COM_Zhuanpan> rarity_ = {};
public:
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_contents_(TypedArray<COM_ZhuanpanContent> p_val) { contents_ = p_val; }
	TypedArray<COM_ZhuanpanContent> get_contents_() const { return contents_; }
	void set_rarity_(TypedArray<COM_Zhuanpan> p_val) { rarity_ = p_val; }
	TypedArray<COM_Zhuanpan> get_rarity_() const { return rarity_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_IntegralContent
class COM_IntegralContent : public Resource {
	GDCLASS(COM_IntegralContent, Resource);
protected:
	uint32_t id_ = 0;
	uint32_t itemid_ = 0;
	int32_t times_ = 0;
	int32_t cost_ = 0;
public:
	void set_id_(uint32_t p_val) { id_ = p_val; }
	uint32_t get_id_() const { return id_; }
	void set_itemid_(uint32_t p_val) { itemid_ = p_val; }
	uint32_t get_itemid_() const { return itemid_; }
	void set_times_(int32_t p_val) { times_ = p_val; }
	int32_t get_times_() const { return times_; }
	void set_cost_(int32_t p_val) { cost_ = p_val; }
	int32_t get_cost_() const { return cost_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_IntegralData
class COM_IntegralData : public Resource {
	GDCLASS(COM_IntegralData, Resource);
protected:
	uint64_t sinceStamp_ = 0;
	uint64_t endStamp_ = 0;
	uint32_t integral_ = 0;
	bool isflag_ = false;
	TypedArray<COM_IntegralContent> contents_ = {};
public:
	void set_sinceStamp_(uint64_t p_val) { sinceStamp_ = p_val; }
	uint64_t get_sinceStamp_() const { return sinceStamp_; }
	void set_endStamp_(uint64_t p_val) { endStamp_ = p_val; }
	uint64_t get_endStamp_() const { return endStamp_; }
	void set_integral_(uint32_t p_val) { integral_ = p_val; }
	uint32_t get_integral_() const { return integral_; }
	void set_isflag_(bool p_val) { isflag_ = p_val; }
	bool get_isflag_() const { return isflag_; }
	void set_contents_(TypedArray<COM_IntegralContent> p_val) { contents_ = p_val; }
	TypedArray<COM_IntegralContent> get_contents_() const { return contents_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_SysActivity
class SGE_SysActivity : public Resource {
	GDCLASS(SGE_SysActivity, Resource);
protected:
	Ref<COM_ADLoginTotal> loginData_ = Ref<COM_ADLoginTotal>();
	Ref<COM_ADChargeTotal> chData_ = Ref<COM_ADChargeTotal>();
	Ref<COM_ADDiscountStore> stData_ = Ref<COM_ADDiscountStore>();
	Ref<COM_ADChargeEvery> ceData_ = Ref<COM_ADChargeEvery>();
	Ref<COM_ADCards> acData_ = Ref<COM_ADCards>();
	Ref<COM_ADHotRole> hrData_ = Ref<COM_ADHotRole>();
	Ref<COM_ADEmployeeTotal> etdata_ = Ref<COM_ADEmployeeTotal>();
	Ref<COM_ADGiftBag> gbdata_ = Ref<COM_ADGiftBag>();
	Ref<COM_ZhuanpanData> zpdata_ = Ref<COM_ZhuanpanData>();
	Ref<COM_IntegralData> icdata_ = Ref<COM_IntegralData>();
public:
	void set_loginData_(Ref<COM_ADLoginTotal> p_val) { loginData_ = p_val; }
	Ref<COM_ADLoginTotal> get_loginData_() const { return loginData_; }
	void set_chData_(Ref<COM_ADChargeTotal> p_val) { chData_ = p_val; }
	Ref<COM_ADChargeTotal> get_chData_() const { return chData_; }
	void set_stData_(Ref<COM_ADDiscountStore> p_val) { stData_ = p_val; }
	Ref<COM_ADDiscountStore> get_stData_() const { return stData_; }
	void set_ceData_(Ref<COM_ADChargeEvery> p_val) { ceData_ = p_val; }
	Ref<COM_ADChargeEvery> get_ceData_() const { return ceData_; }
	void set_acData_(Ref<COM_ADCards> p_val) { acData_ = p_val; }
	Ref<COM_ADCards> get_acData_() const { return acData_; }
	void set_hrData_(Ref<COM_ADHotRole> p_val) { hrData_ = p_val; }
	Ref<COM_ADHotRole> get_hrData_() const { return hrData_; }
	void set_etdata_(Ref<COM_ADEmployeeTotal> p_val) { etdata_ = p_val; }
	Ref<COM_ADEmployeeTotal> get_etdata_() const { return etdata_; }
	void set_gbdata_(Ref<COM_ADGiftBag> p_val) { gbdata_ = p_val; }
	Ref<COM_ADGiftBag> get_gbdata_() const { return gbdata_; }
	void set_zpdata_(Ref<COM_ZhuanpanData> p_val) { zpdata_ = p_val; }
	Ref<COM_ZhuanpanData> get_zpdata_() const { return zpdata_; }
	void set_icdata_(Ref<COM_IntegralData> p_val) { icdata_ = p_val; }
	Ref<COM_IntegralData> get_icdata_() const { return icdata_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_LoginInfo
class COM_LoginInfo : public Resource {
	GDCLASS(COM_LoginInfo, Resource);
protected:
	String username_ = "";
	String password_ = "";
	uint32_t version_ = 0;
	String sessionkey_ = "";
	String mac_ = "";
	String idfa_ = "";
	String devicetype_ = "";
public:
	void set_username_(String p_val) { username_ = p_val; }
	String get_username_() const { return username_; }
	void set_password_(String p_val) { password_ = p_val; }
	String get_password_() const { return password_; }
	void set_version_(uint32_t p_val) { version_ = p_val; }
	uint32_t get_version_() const { return version_; }
	void set_sessionkey_(String p_val) { sessionkey_ = p_val; }
	String get_sessionkey_() const { return sessionkey_; }
	void set_mac_(String p_val) { mac_ = p_val; }
	String get_mac_() const { return mac_; }
	void set_idfa_(String p_val) { idfa_ = p_val; }
	String get_idfa_() const { return idfa_; }
	void set_devicetype_(String p_val) { devicetype_ = p_val; }
	String get_devicetype_() const { return devicetype_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_FPosition
class COM_FPosition : public Resource {
	GDCLASS(COM_FPosition, Resource);
protected:
	float x_ = 0.0;
	float z_ = 0.0;
	bool isLast_ = false;
public:
	void set_x_(float p_val) { x_ = p_val; }
	float get_x_() const { return x_; }
	void set_z_(float p_val) { z_ = p_val; }
	float get_z_() const { return z_; }
	void set_isLast_(bool p_val) { isLast_ = p_val; }
	bool get_isLast_() const { return isLast_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ScenePlayerInformation
class COM_ScenePlayerInformation : public Resource {
	GDCLASS(COM_ScenePlayerInformation, Resource);
protected:
	bool isLeader_ = false;
	bool isTeamMember_ = false;
	bool isInBattle_ = false;
	int16_t vip_ = 0;
	int32_t instId_ = 0;
	int32_t assetId_ = 0;
	int32_t weaponItemId_ = 0;
	int32_t fashionId_ = 0;
	int32_t hpMax_ = 0;
	int32_t hpCrt_ = 0;
	int32_t mpMax_ = 0;
	int32_t mpCrt_ = 0;
	int32_t level_ = 0;
	int32_t battlePower_ = 0;
	int32_t jl_ = 0;
	int32_t magicLv_ = 0;
	uint64_t openSubSystemFlag_ = 0;
	int32_t title_ = 0;
	String instName_ = "";
	String guildeName_ = "";
	uint16_t jt_ = (JobType)0;
	uint16_t type_ = (EntityType)0;
	Ref<COM_FPosition> originPos_ = Ref<COM_FPosition>();
	int32_t showBabyTableId_ = 0;
	String showBabyName_ = "";
public:
	void set_isLeader_(bool p_val) { isLeader_ = p_val; }
	bool get_isLeader_() const { return isLeader_; }
	void set_isTeamMember_(bool p_val) { isTeamMember_ = p_val; }
	bool get_isTeamMember_() const { return isTeamMember_; }
	void set_isInBattle_(bool p_val) { isInBattle_ = p_val; }
	bool get_isInBattle_() const { return isInBattle_; }
	void set_vip_(int16_t p_val) { vip_ = p_val; }
	int16_t get_vip_() const { return vip_; }
	void set_instId_(int32_t p_val) { instId_ = p_val; }
	int32_t get_instId_() const { return instId_; }
	void set_assetId_(int32_t p_val) { assetId_ = p_val; }
	int32_t get_assetId_() const { return assetId_; }
	void set_weaponItemId_(int32_t p_val) { weaponItemId_ = p_val; }
	int32_t get_weaponItemId_() const { return weaponItemId_; }
	void set_fashionId_(int32_t p_val) { fashionId_ = p_val; }
	int32_t get_fashionId_() const { return fashionId_; }
	void set_hpMax_(int32_t p_val) { hpMax_ = p_val; }
	int32_t get_hpMax_() const { return hpMax_; }
	void set_hpCrt_(int32_t p_val) { hpCrt_ = p_val; }
	int32_t get_hpCrt_() const { return hpCrt_; }
	void set_mpMax_(int32_t p_val) { mpMax_ = p_val; }
	int32_t get_mpMax_() const { return mpMax_; }
	void set_mpCrt_(int32_t p_val) { mpCrt_ = p_val; }
	int32_t get_mpCrt_() const { return mpCrt_; }
	void set_level_(int32_t p_val) { level_ = p_val; }
	int32_t get_level_() const { return level_; }
	void set_battlePower_(int32_t p_val) { battlePower_ = p_val; }
	int32_t get_battlePower_() const { return battlePower_; }
	void set_jl_(int32_t p_val) { jl_ = p_val; }
	int32_t get_jl_() const { return jl_; }
	void set_magicLv_(int32_t p_val) { magicLv_ = p_val; }
	int32_t get_magicLv_() const { return magicLv_; }
	void set_openSubSystemFlag_(uint64_t p_val) { openSubSystemFlag_ = p_val; }
	uint64_t get_openSubSystemFlag_() const { return openSubSystemFlag_; }
	void set_title_(int32_t p_val) { title_ = p_val; }
	int32_t get_title_() const { return title_; }
	void set_instName_(String p_val) { instName_ = p_val; }
	String get_instName_() const { return instName_; }
	void set_guildeName_(String p_val) { guildeName_ = p_val; }
	String get_guildeName_() const { return guildeName_; }
	void set_jt_(uint16_t p_val) { jt_ = p_val; }
	uint16_t get_jt_() const { return jt_; }
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_originPos_(Ref<COM_FPosition> p_val) { originPos_ = p_val; }
	Ref<COM_FPosition> get_originPos_() const { return originPos_; }
	void set_showBabyTableId_(int32_t p_val) { showBabyTableId_ = p_val; }
	int32_t get_showBabyTableId_() const { return showBabyTableId_; }
	void set_showBabyName_(String p_val) { showBabyName_ = p_val; }
	String get_showBabyName_() const { return showBabyName_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_BattleEntityInformation
class COM_BattleEntityInformation : public Resource {
	GDCLASS(COM_BattleEntityInformation, Resource);
protected:
	uint16_t type_ = (EntityType)0;
	String instName_ = "";
	int32_t instId_ = 0;
	int32_t tableId_ = 0;
	int32_t assetId_ = 0;
	uint16_t jt_ = (JobType)0;
	uint16_t battlePosition_ = (BattlePosition)0;
	int32_t weaponItemId_ = 0;
	int32_t fashionId_ = 0;
	int32_t hpMax_ = 0;
	int32_t hpCrt_ = 0;
	int32_t mpMax_ = 0;
	int32_t mpCrt_ = 0;
	int32_t level_ = 0;
public:
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_instName_(String p_val) { instName_ = p_val; }
	String get_instName_() const { return instName_; }
	void set_instId_(int32_t p_val) { instId_ = p_val; }
	int32_t get_instId_() const { return instId_; }
	void set_tableId_(int32_t p_val) { tableId_ = p_val; }
	int32_t get_tableId_() const { return tableId_; }
	void set_assetId_(int32_t p_val) { assetId_ = p_val; }
	int32_t get_assetId_() const { return assetId_; }
	void set_jt_(uint16_t p_val) { jt_ = p_val; }
	uint16_t get_jt_() const { return jt_; }
	void set_battlePosition_(uint16_t p_val) { battlePosition_ = p_val; }
	uint16_t get_battlePosition_() const { return battlePosition_; }
	void set_weaponItemId_(int32_t p_val) { weaponItemId_ = p_val; }
	int32_t get_weaponItemId_() const { return weaponItemId_; }
	void set_fashionId_(int32_t p_val) { fashionId_ = p_val; }
	int32_t get_fashionId_() const { return fashionId_; }
	void set_hpMax_(int32_t p_val) { hpMax_ = p_val; }
	int32_t get_hpMax_() const { return hpMax_; }
	void set_hpCrt_(int32_t p_val) { hpCrt_ = p_val; }
	int32_t get_hpCrt_() const { return hpCrt_; }
	void set_mpMax_(int32_t p_val) { mpMax_ = p_val; }
	int32_t get_mpMax_() const { return mpMax_; }
	void set_mpCrt_(int32_t p_val) { mpCrt_ = p_val; }
	int32_t get_mpCrt_() const { return mpCrt_; }
	void set_level_(int32_t p_val) { level_ = p_val; }
	int32_t get_level_() const { return level_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SimpleInformation
class COM_SimpleInformation : public Resource {
	GDCLASS(COM_SimpleInformation, Resource);
protected:
	int32_t instId_ = 0;
	int32_t level_ = 0;
	int32_t asset_id_ = 0;
	String instName_ = "";
	int32_t weaponItemId_ = 0;
	int32_t fashionId_ = 0;
	uint32_t section_ = 0;
	uint16_t jt_ = (JobType)0;
	int32_t jl_ = 0;
public:
	void set_instId_(int32_t p_val) { instId_ = p_val; }
	int32_t get_instId_() const { return instId_; }
	void set_level_(int32_t p_val) { level_ = p_val; }
	int32_t get_level_() const { return level_; }
	void set_asset_id_(int32_t p_val) { asset_id_ = p_val; }
	int32_t get_asset_id_() const { return asset_id_; }
	void set_instName_(String p_val) { instName_ = p_val; }
	String get_instName_() const { return instName_; }
	void set_weaponItemId_(int32_t p_val) { weaponItemId_ = p_val; }
	int32_t get_weaponItemId_() const { return weaponItemId_; }
	void set_fashionId_(int32_t p_val) { fashionId_ = p_val; }
	int32_t get_fashionId_() const { return fashionId_; }
	void set_section_(uint32_t p_val) { section_ = p_val; }
	uint32_t get_section_() const { return section_; }
	void set_jt_(uint16_t p_val) { jt_ = p_val; }
	uint16_t get_jt_() const { return jt_; }
	void set_jl_(int32_t p_val) { jl_ = p_val; }
	int32_t get_jl_() const { return jl_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_AccountInfo
class COM_AccountInfo : public Resource {
	GDCLASS(COM_AccountInfo, Resource);
protected:
	uint32_t guid_ = 0;
	String username_ = "";
	String password_ = "";
	uint64_t createtime_ = 0;
	String phoneNumber_ = "";
public:
	void set_guid_(uint32_t p_val) { guid_ = p_val; }
	uint32_t get_guid_() const { return guid_; }
	void set_username_(String p_val) { username_ = p_val; }
	String get_username_() const { return username_; }
	void set_password_(String p_val) { password_ = p_val; }
	String get_password_() const { return password_; }
	void set_createtime_(uint64_t p_val) { createtime_ = p_val; }
	uint64_t get_createtime_() const { return createtime_; }
	void set_phoneNumber_(String p_val) { phoneNumber_ = p_val; }
	String get_phoneNumber_() const { return phoneNumber_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_PropValue
class COM_PropValue : public Resource {
	GDCLASS(COM_PropValue, Resource);
protected:
	uint16_t type_ = (PropertyType)0;
	float value_ = 0.0;
public:
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_value_(float p_val) { value_ = p_val; }
	float get_value_() const { return value_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Item
class COM_Item : public Resource {
	GDCLASS(COM_Item, Resource);
protected:
	uint32_t itemId_ = 0;
	uint32_t instId_ = 0;
	int16_t stack_ = 0;
	bool isBind_ = false;
	bool isLock_ = false;
	int8_t strLevel_ = 0;
	int16_t slot_ = 0;
	int32_t skillID_ = 0;
	int32_t durability_ = 0;
	int32_t durabilityMax_ = 0;
	int32_t usedTimeout_ = 0;
	int32_t lastSellTime_ = 0;
	TypedArray<COM_PropValue> propArr = {};
public:
	void set_itemId_(uint32_t p_val) { itemId_ = p_val; }
	uint32_t get_itemId_() const { return itemId_; }
	void set_instId_(uint32_t p_val) { instId_ = p_val; }
	uint32_t get_instId_() const { return instId_; }
	void set_stack_(int16_t p_val) { stack_ = p_val; }
	int16_t get_stack_() const { return stack_; }
	void set_isBind_(bool p_val) { isBind_ = p_val; }
	bool get_isBind_() const { return isBind_; }
	void set_isLock_(bool p_val) { isLock_ = p_val; }
	bool get_isLock_() const { return isLock_; }
	void set_strLevel_(int8_t p_val) { strLevel_ = p_val; }
	int8_t get_strLevel_() const { return strLevel_; }
	void set_slot_(int16_t p_val) { slot_ = p_val; }
	int16_t get_slot_() const { return slot_; }
	void set_skillID_(int32_t p_val) { skillID_ = p_val; }
	int32_t get_skillID_() const { return skillID_; }
	void set_durability_(int32_t p_val) { durability_ = p_val; }
	int32_t get_durability_() const { return durability_; }
	void set_durabilityMax_(int32_t p_val) { durabilityMax_ = p_val; }
	int32_t get_durabilityMax_() const { return durabilityMax_; }
	void set_usedTimeout_(int32_t p_val) { usedTimeout_ = p_val; }
	int32_t get_usedTimeout_() const { return usedTimeout_; }
	void set_lastSellTime_(int32_t p_val) { lastSellTime_ = p_val; }
	int32_t get_lastSellTime_() const { return lastSellTime_; }
	void set_propArr(TypedArray<COM_PropValue> p_val) { propArr = p_val; }
	TypedArray<COM_PropValue> get_propArr() const { return propArr; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_DropItem
class COM_DropItem : public Resource {
	GDCLASS(COM_DropItem, Resource);
protected:
	uint32_t itemId_ = 0;
	uint32_t itemNum_ = 0;
public:
	void set_itemId_(uint32_t p_val) { itemId_ = p_val; }
	uint32_t get_itemId_() const { return itemId_; }
	void set_itemNum_(uint32_t p_val) { itemNum_ = p_val; }
	uint32_t get_itemNum_() const { return itemNum_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_CrystalProp
class COM_CrystalProp : public Resource {
	GDCLASS(COM_CrystalProp, Resource);
protected:
	uint32_t level_ = 0;
	uint16_t type_ = (PropertyType)0;
	uint32_t val_ = 0;
public:
	void set_level_(uint32_t p_val) { level_ = p_val; }
	uint32_t get_level_() const { return level_; }
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_val_(uint32_t p_val) { val_ = p_val; }
	uint32_t get_val_() const { return val_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_CrystalData
class COM_CrystalData : public Resource {
	GDCLASS(COM_CrystalData, Resource);
protected:
	uint32_t level_ = 0;
	TypedArray<COM_CrystalProp> props_ = {};
public:
	void set_level_(uint32_t p_val) { level_ = p_val; }
	uint32_t get_level_() const { return level_; }
	void set_props_(TypedArray<COM_CrystalProp> p_val) { props_ = p_val; }
	TypedArray<COM_CrystalProp> get_props_() const { return props_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_QuestTarget
class COM_QuestTarget : public Resource {
	GDCLASS(COM_QuestTarget, Resource);
protected:
	uint32_t targetId_ = 0;
	int32_t targetNum_ = 0;
public:
	void set_targetId_(uint32_t p_val) { targetId_ = p_val; }
	uint32_t get_targetId_() const { return targetId_; }
	void set_targetNum_(int32_t p_val) { targetNum_ = p_val; }
	int32_t get_targetNum_() const { return targetNum_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Skill
class COM_Skill : public Resource {
	GDCLASS(COM_Skill, Resource);
protected:
	uint32_t skillID_ = 0;
	uint32_t skillExp_ = 0;
	uint32_t skillLevel_ = 0;
public:
	void set_skillID_(uint32_t p_val) { skillID_ = p_val; }
	uint32_t get_skillID_() const { return skillID_; }
	void set_skillExp_(uint32_t p_val) { skillExp_ = p_val; }
	uint32_t get_skillExp_() const { return skillExp_; }
	void set_skillLevel_(uint32_t p_val) { skillLevel_ = p_val; }
	uint32_t get_skillLevel_() const { return skillLevel_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_QuestInst
class COM_QuestInst : public Resource {
	GDCLASS(COM_QuestInst, Resource);
protected:
	int32_t questId_ = 0;
	TypedArray<COM_QuestTarget> targets_ = {};
public:
	void set_questId_(int32_t p_val) { questId_ = p_val; }
	int32_t get_questId_() const { return questId_; }
	void set_targets_(TypedArray<COM_QuestTarget> p_val) { targets_ = p_val; }
	TypedArray<COM_QuestTarget> get_targets_() const { return targets_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_State
class COM_State : public Resource {
	GDCLASS(COM_State, Resource);
protected:
	uint32_t stateId_ = 0;
	int8_t turn_ = 0;
	int8_t tick_ = 0;
	int8_t type_ = 0;
	int32_t value0_ = 0;
	int32_t value1_ = 0;
public:
	void set_stateId_(uint32_t p_val) { stateId_ = p_val; }
	uint32_t get_stateId_() const { return stateId_; }
	void set_turn_(int8_t p_val) { turn_ = p_val; }
	int8_t get_turn_() const { return turn_; }
	void set_tick_(int8_t p_val) { tick_ = p_val; }
	int8_t get_tick_() const { return tick_; }
	void set_type_(int8_t p_val) { type_ = p_val; }
	int8_t get_type_() const { return type_; }
	void set_value0_(int32_t p_val) { value0_ = p_val; }
	int32_t get_value0_() const { return value0_; }
	void set_value1_(int32_t p_val) { value1_ = p_val; }
	int32_t get_value1_() const { return value1_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Entity
class COM_Entity : public Resource {
	GDCLASS(COM_Entity, Resource);
protected:
	uint16_t type_ = (EntityType)0;
	String instName_ = "";
	uint32_t instId_ = 0;
	uint16_t battlePosition_ = (BattlePosition)0;
	TypedArray<float> properties_ = {};
	TypedArray<COM_Skill> skill_ = {};
	TypedArray<COM_Item> equips_ = {};
	TypedArray<COM_State> states_ = {};
public:
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_instName_(String p_val) { instName_ = p_val; }
	String get_instName_() const { return instName_; }
	void set_instId_(uint32_t p_val) { instId_ = p_val; }
	uint32_t get_instId_() const { return instId_; }
	void set_battlePosition_(uint16_t p_val) { battlePosition_ = p_val; }
	uint16_t get_battlePosition_() const { return battlePosition_; }
	void set_properties_(TypedArray<float> p_val) { properties_ = p_val; }
	TypedArray<float> get_properties_() const { return properties_; }
	void set_skill_(TypedArray<COM_Skill> p_val) { skill_ = p_val; }
	TypedArray<COM_Skill> get_skill_() const { return skill_; }
	void set_equips_(TypedArray<COM_Item> p_val) { equips_ = p_val; }
	TypedArray<COM_Item> get_equips_() const { return equips_; }
	void set_states_(TypedArray<COM_State> p_val) { states_ = p_val; }
	TypedArray<COM_State> get_states_() const { return states_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_BabyInst
class COM_BabyInst : public COM_Entity {
	GDCLASS(COM_BabyInst, COM_Entity);
protected:
	String ownerName_ = "";
	bool isShow_ = false;
	bool isBattle_ = false;
	bool isBind_ = false;
	bool isLock_ = false;
	int32_t tableId_ = 0;
	int32_t slot_ = 0;
	uint32_t intensifyLevel_ = 0;
	uint32_t intensifynum_ = 0;
	int32_t lastSellTime_ = 0;
	TypedArray<int32_t> gear_ = {};
	TypedArray<float> addprop_ = {};
public:
	void set_ownerName_(String p_val) { ownerName_ = p_val; }
	String get_ownerName_() const { return ownerName_; }
	void set_isShow_(bool p_val) { isShow_ = p_val; }
	bool get_isShow_() const { return isShow_; }
	void set_isBattle_(bool p_val) { isBattle_ = p_val; }
	bool get_isBattle_() const { return isBattle_; }
	void set_isBind_(bool p_val) { isBind_ = p_val; }
	bool get_isBind_() const { return isBind_; }
	void set_isLock_(bool p_val) { isLock_ = p_val; }
	bool get_isLock_() const { return isLock_; }
	void set_tableId_(int32_t p_val) { tableId_ = p_val; }
	int32_t get_tableId_() const { return tableId_; }
	void set_slot_(int32_t p_val) { slot_ = p_val; }
	int32_t get_slot_() const { return slot_; }
	void set_intensifyLevel_(uint32_t p_val) { intensifyLevel_ = p_val; }
	uint32_t get_intensifyLevel_() const { return intensifyLevel_; }
	void set_intensifynum_(uint32_t p_val) { intensifynum_ = p_val; }
	uint32_t get_intensifynum_() const { return intensifynum_; }
	void set_lastSellTime_(int32_t p_val) { lastSellTime_ = p_val; }
	int32_t get_lastSellTime_() const { return lastSellTime_; }
	void set_gear_(TypedArray<int32_t> p_val) { gear_ = p_val; }
	TypedArray<int32_t> get_gear_() const { return gear_; }
	void set_addprop_(TypedArray<float> p_val) { addprop_ = p_val; }
	TypedArray<float> get_addprop_() const { return addprop_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_EmployeeInst
class COM_EmployeeInst : public COM_Entity {
	GDCLASS(COM_EmployeeInst, COM_Entity);
protected:
	String ownerName_ = "";
	bool isBattle_ = false;
	uint32_t weaponId_ = 0;
	uint16_t quality_ = (QualityColor)0;
	uint32_t star_ = 0;
	uint32_t soul_ = 0;
public:
	void set_ownerName_(String p_val) { ownerName_ = p_val; }
	String get_ownerName_() const { return ownerName_; }
	void set_isBattle_(bool p_val) { isBattle_ = p_val; }
	bool get_isBattle_() const { return isBattle_; }
	void set_weaponId_(uint32_t p_val) { weaponId_ = p_val; }
	uint32_t get_weaponId_() const { return weaponId_; }
	void set_quality_(uint16_t p_val) { quality_ = p_val; }
	uint16_t get_quality_() const { return quality_; }
	void set_star_(uint32_t p_val) { star_ = p_val; }
	uint32_t get_star_() const { return star_; }
	void set_soul_(uint32_t p_val) { soul_ = p_val; }
	uint32_t get_soul_() const { return soul_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ContactInfo
class COM_ContactInfo : public Resource {
	GDCLASS(COM_ContactInfo, Resource);
protected:
	uint32_t instId_ = 0;
	String name_ = "";
	uint32_t level_ = 0;
	float exp_ = 0.0;
	uint16_t job_ = (JobType)0;
	uint32_t assetId_ = 0;
	uint32_t jobLevel_ = 0;
	uint16_t vip_ = (VipLevel)0;
	uint32_t ff_ = 0;
	uint32_t rank_ = 0;
	int32_t section_ = 0;
	uint32_t value_ = 0;
	bool isLine_ = false;
public:
	void set_instId_(uint32_t p_val) { instId_ = p_val; }
	uint32_t get_instId_() const { return instId_; }
	void set_name_(String p_val) { name_ = p_val; }
	String get_name_() const { return name_; }
	void set_level_(uint32_t p_val) { level_ = p_val; }
	uint32_t get_level_() const { return level_; }
	void set_exp_(float p_val) { exp_ = p_val; }
	float get_exp_() const { return exp_; }
	void set_job_(uint16_t p_val) { job_ = p_val; }
	uint16_t get_job_() const { return job_; }
	void set_assetId_(uint32_t p_val) { assetId_ = p_val; }
	uint32_t get_assetId_() const { return assetId_; }
	void set_jobLevel_(uint32_t p_val) { jobLevel_ = p_val; }
	uint32_t get_jobLevel_() const { return jobLevel_; }
	void set_vip_(uint16_t p_val) { vip_ = p_val; }
	uint16_t get_vip_() const { return vip_; }
	void set_ff_(uint32_t p_val) { ff_ = p_val; }
	uint32_t get_ff_() const { return ff_; }
	void set_rank_(uint32_t p_val) { rank_ = p_val; }
	uint32_t get_rank_() const { return rank_; }
	void set_section_(int32_t p_val) { section_ = p_val; }
	int32_t get_section_() const { return section_; }
	void set_value_(uint32_t p_val) { value_ = p_val; }
	uint32_t get_value_() const { return value_; }
	void set_isLine_(bool p_val) { isLine_ = p_val; }
	bool get_isLine_() const { return isLine_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_ContactInfoExt
class SGE_ContactInfoExt : public COM_ContactInfo {
	GDCLASS(SGE_ContactInfoExt, COM_ContactInfo);
protected:
	uint64_t rolefirst_ = 0;
	uint64_t rolelast_ = 0;
	uint64_t logoutTime_ = 0;
	uint32_t gold_ = 0;
	uint32_t diamond_ = 0;
	uint32_t magicgold_ = 0;
	int32_t guildContribute_ = 0;
	String accName_ = "";
	String userid_ = "";
	String pfid_ = "";
	String pfname_ = "";
	uint32_t serverid_ = 0;
public:
	void set_rolefirst_(uint64_t p_val) { rolefirst_ = p_val; }
	uint64_t get_rolefirst_() const { return rolefirst_; }
	void set_rolelast_(uint64_t p_val) { rolelast_ = p_val; }
	uint64_t get_rolelast_() const { return rolelast_; }
	void set_logoutTime_(uint64_t p_val) { logoutTime_ = p_val; }
	uint64_t get_logoutTime_() const { return logoutTime_; }
	void set_gold_(uint32_t p_val) { gold_ = p_val; }
	uint32_t get_gold_() const { return gold_; }
	void set_diamond_(uint32_t p_val) { diamond_ = p_val; }
	uint32_t get_diamond_() const { return diamond_; }
	void set_magicgold_(uint32_t p_val) { magicgold_ = p_val; }
	uint32_t get_magicgold_() const { return magicgold_; }
	void set_guildContribute_(int32_t p_val) { guildContribute_ = p_val; }
	int32_t get_guildContribute_() const { return guildContribute_; }
	void set_accName_(String p_val) { accName_ = p_val; }
	String get_accName_() const { return accName_; }
	void set_userid_(String p_val) { userid_ = p_val; }
	String get_userid_() const { return userid_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_pfname_(String p_val) { pfname_ = p_val; }
	String get_pfname_() const { return pfname_; }
	void set_serverid_(uint32_t p_val) { serverid_ = p_val; }
	uint32_t get_serverid_() const { return serverid_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Achievement
class COM_Achievement : public Resource {
	GDCLASS(COM_Achievement, Resource);
protected:
	uint32_t achId_ = 0;
	uint16_t achType_ = (AchievementType)0;
	uint32_t achValue_ = 0;
	bool isAch_ = false;
	bool isAward_ = false;
public:
	void set_achId_(uint32_t p_val) { achId_ = p_val; }
	uint32_t get_achId_() const { return achId_; }
	void set_achType_(uint16_t p_val) { achType_ = p_val; }
	uint16_t get_achType_() const { return achType_; }
	void set_achValue_(uint32_t p_val) { achValue_ = p_val; }
	uint32_t get_achValue_() const { return achValue_; }
	void set_isAch_(bool p_val) { isAch_ = p_val; }
	bool get_isAch_() const { return isAch_; }
	void set_isAward_(bool p_val) { isAward_ = p_val; }
	bool get_isAward_() const { return isAward_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_HundredBattle
class COM_HundredBattle : public Resource {
	GDCLASS(COM_HundredBattle, Resource);
protected:
	uint32_t playerId_ = 0;
	uint32_t tier_ = 0;
	uint32_t curTier_ = 0;
	uint32_t surplus_ = 0;
	uint32_t resetNum_ = 0;
public:
	void set_playerId_(uint32_t p_val) { playerId_ = p_val; }
	uint32_t get_playerId_() const { return playerId_; }
	void set_tier_(uint32_t p_val) { tier_ = p_val; }
	uint32_t get_tier_() const { return tier_; }
	void set_curTier_(uint32_t p_val) { curTier_ = p_val; }
	uint32_t get_curTier_() const { return curTier_; }
	void set_surplus_(uint32_t p_val) { surplus_ = p_val; }
	uint32_t get_surplus_() const { return surplus_; }
	void set_resetNum_(uint32_t p_val) { resetNum_ = p_val; }
	uint32_t get_resetNum_() const { return resetNum_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_PlayerVsPlayer
class COM_PlayerVsPlayer : public Resource {
	GDCLASS(COM_PlayerVsPlayer, Resource);
protected:
	int32_t playerInst_ = 0;
	int32_t section_ = 0;
	int32_t value_ = 0;
	int32_t winNum_ = 0;
	int32_t battleNum_ = 0;
	float winValue_ = 0.0;
	int32_t contWin_ = 0;
	bool isCont_ = false;
public:
	void set_playerInst_(int32_t p_val) { playerInst_ = p_val; }
	int32_t get_playerInst_() const { return playerInst_; }
	void set_section_(int32_t p_val) { section_ = p_val; }
	int32_t get_section_() const { return section_; }
	void set_value_(int32_t p_val) { value_ = p_val; }
	int32_t get_value_() const { return value_; }
	void set_winNum_(int32_t p_val) { winNum_ = p_val; }
	int32_t get_winNum_() const { return winNum_; }
	void set_battleNum_(int32_t p_val) { battleNum_ = p_val; }
	int32_t get_battleNum_() const { return battleNum_; }
	void set_winValue_(float p_val) { winValue_ = p_val; }
	float get_winValue_() const { return winValue_; }
	void set_contWin_(int32_t p_val) { contWin_ = p_val; }
	int32_t get_contWin_() const { return contWin_; }
	void set_isCont_(bool p_val) { isCont_ = p_val; }
	bool get_isCont_() const { return isCont_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Activity
class COM_Activity : public Resource {
	GDCLASS(COM_Activity, Resource);
protected:
	int32_t actId_ = 0;
	int32_t counter_ = 0;
public:
	void set_actId_(int32_t p_val) { actId_ = p_val; }
	int32_t get_actId_() const { return actId_; }
	void set_counter_(int32_t p_val) { counter_ = p_val; }
	int32_t get_counter_() const { return counter_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ActivityTable
class COM_ActivityTable : public Resource {
	GDCLASS(COM_ActivityTable, Resource);
protected:
	TypedArray<COM_Activity> activities_ = {};
	TypedArray<uint32_t> flag_ = {};
	int32_t reward_ = 0;
public:
	void set_activities_(TypedArray<COM_Activity> p_val) { activities_ = p_val; }
	TypedArray<COM_Activity> get_activities_() const { return activities_; }
	void set_flag_(TypedArray<uint32_t> p_val) { flag_ = p_val; }
	TypedArray<uint32_t> get_flag_() const { return flag_; }
	void set_reward_(int32_t p_val) { reward_ = p_val; }
	int32_t get_reward_() const { return reward_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_CourseGift
class COM_CourseGift : public Resource {
	GDCLASS(COM_CourseGift, Resource);
protected:
	uint32_t id_ = 0;
	float timeout_ = 0.0;
public:
	void set_id_(uint32_t p_val) { id_ = p_val; }
	uint32_t get_id_() const { return id_; }
	void set_timeout_(float p_val) { timeout_ = p_val; }
	float get_timeout_() const { return timeout_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SimplePlayerInst
class COM_SimplePlayerInst : public COM_Entity {
	GDCLASS(COM_SimplePlayerInst, COM_Entity);
protected:
	bool isLeavingTeam_ = false;
	bool isBattle_ = false;
	bool autoBattle_ = false;
	bool isTeamLeader_ = false;
	int32_t sceneId_ = 0;
	uint64_t openSubSystemFlag_ = 0;
	int64_t createTime_ = 0;
	String guildName_ = "";
	Ref<COM_FPosition> scenePos_ = Ref<COM_FPosition>();
	Ref<COM_PlayerVsPlayer> pvpInfo_ = Ref<COM_PlayerVsPlayer>();
	TypedArray<COM_BabyInst> babies1_ = {};
	TypedArray<COM_EmployeeInst> battleEmps_ = {};
public:
	void set_isLeavingTeam_(bool p_val) { isLeavingTeam_ = p_val; }
	bool get_isLeavingTeam_() const { return isLeavingTeam_; }
	void set_isBattle_(bool p_val) { isBattle_ = p_val; }
	bool get_isBattle_() const { return isBattle_; }
	void set_autoBattle_(bool p_val) { autoBattle_ = p_val; }
	bool get_autoBattle_() const { return autoBattle_; }
	void set_isTeamLeader_(bool p_val) { isTeamLeader_ = p_val; }
	bool get_isTeamLeader_() const { return isTeamLeader_; }
	void set_sceneId_(int32_t p_val) { sceneId_ = p_val; }
	int32_t get_sceneId_() const { return sceneId_; }
	void set_openSubSystemFlag_(uint64_t p_val) { openSubSystemFlag_ = p_val; }
	uint64_t get_openSubSystemFlag_() const { return openSubSystemFlag_; }
	void set_createTime_(int64_t p_val) { createTime_ = p_val; }
	int64_t get_createTime_() const { return createTime_; }
	void set_guildName_(String p_val) { guildName_ = p_val; }
	String get_guildName_() const { return guildName_; }
	void set_scenePos_(Ref<COM_FPosition> p_val) { scenePos_ = p_val; }
	Ref<COM_FPosition> get_scenePos_() const { return scenePos_; }
	void set_pvpInfo_(Ref<COM_PlayerVsPlayer> p_val) { pvpInfo_ = p_val; }
	Ref<COM_PlayerVsPlayer> get_pvpInfo_() const { return pvpInfo_; }
	void set_babies1_(TypedArray<COM_BabyInst> p_val) { babies1_ = p_val; }
	TypedArray<COM_BabyInst> get_babies1_() const { return babies1_; }
	void set_battleEmps_(TypedArray<COM_EmployeeInst> p_val) { battleEmps_ = p_val; }
	TypedArray<COM_EmployeeInst> get_battleEmps_() const { return battleEmps_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_PlayerInst
class COM_PlayerInst : public COM_Entity {
	GDCLASS(COM_PlayerInst, COM_Entity);
protected:
	bool isLeavingTeam_ = false;
	bool isBattle_ = false;
	bool autoBattle_ = false;
	bool isTeamLeader_ = false;
	int32_t sceneId_ = 0;
	uint64_t openSubSystemFlag_ = 0;
	int64_t createTime_ = 0;
	String guildName_ = "";
	Ref<COM_FPosition> scenePos_ = Ref<COM_FPosition>();
	Ref<COM_PlayerVsPlayer> pvpInfo_ = Ref<COM_PlayerVsPlayer>();
	bool onlineTimeFlag_ = false;
	float onlineTime_ = 0.0;
	TypedArray<uint32_t> onlineTimeReward_ = {};
	bool isFund_ = false;
	TypedArray<uint32_t> fundtags_ = {};
	bool openDoubleTimeFlag_ = false;
	bool isFirstLogin_ = false;
	bool firstRechargeDiamond_ = false;
	bool isFirstRechargeGift_ = false;
	float offlineExp_ = 0.0;
	float rivalTime_ = 0.0;
	int8_t rivalNum_ = 0;
	int8_t promoteAward_ = 0;
	uint64_t guideIdx_ = 0;
	float noTalkTime_ = 0.0;
	uint32_t wishShareNum_ = 0;
	uint32_t warriortrophyNum_ = 0;
	uint32_t employeelasttime_ = 0;
	uint32_t employeeonecount_ = 0;
	uint32_t employeetencount_ = 0;
	float greenBoxTimes_ = 0.0;
	float blueBoxTimes_ = 0.0;
	uint32_t greenBoxFreeNum_ = 0;
	Ref<COM_HundredBattle> hbInfo_ = Ref<COM_HundredBattle>();
	TypedArray<int32_t> openScenes_ = {};
	TypedArray<uint32_t> copyNum_ = {};
	int32_t magicItemLevel_ = 0;
	int32_t magicItemeExp_ = 0;
	uint16_t magicItemeJob_ = (JobType)0;
	int32_t magicTupoLevel_ = 0;
	TypedArray<int32_t> cachedNpcs_ = {};
	TypedArray<String> gft_ = {};
	TypedArray<uint32_t> babycache_ = {};
	TypedArray<int32_t> titles_ = {};
	int32_t guildContribution_ = 0;
	uint32_t exitGuildTime_ = 0;
	TypedArray<COM_Skill> guildSkills_ = {};
	// enum array is stored as uint16_t array
	TypedArray<uint16_t> gmActivities_ = {};
	Ref<COM_ADLoginTotal> festival_ = Ref<COM_ADLoginTotal>();
	Ref<COM_ADChargeTotal> selfRecharge_ = Ref<COM_ADChargeTotal>();
	Ref<COM_ADChargeTotal> sysRecharge_ = Ref<COM_ADChargeTotal>();
	Ref<COM_ADDiscountStore> selfDiscountStore_ = Ref<COM_ADDiscountStore>();
	Ref<COM_ADDiscountStore> sysDiscountStore_ = Ref<COM_ADDiscountStore>();
	Ref<COM_ADChargeEvery> selfOnceRecharge_ = Ref<COM_ADChargeEvery>();
	Ref<COM_ADChargeEvery> sysOnceRecharge_ = Ref<COM_ADChargeEvery>();
	Ref<COM_ADEmployeeTotal> empact_ = Ref<COM_ADEmployeeTotal>();
	Ref<COM_ADCards> selfCards_ = Ref<COM_ADCards>();
	Ref<COM_ADChargeTotal> myselfRecharge_ = Ref<COM_ADChargeTotal>();
	Ref<COM_ADHotRole> hotdata_ = Ref<COM_ADHotRole>();
	Ref<COM_ADGiftBag> gbdata_ = Ref<COM_ADGiftBag>();
	bool sevenflag_ = false;
	bool signFlag_ = false;
	TypedArray<COM_Sevenday> sevendata_ = {};
	bool viprewardflag_ = false;
	String phoneNumber_ = "";
	TypedArray<uint32_t> levelgift_ = {};
	Ref<COM_ActivityTable> activity_ = Ref<COM_ActivityTable>();
	TypedArray<COM_Item> fuwen_ = {};
	Ref<COM_CrystalData> crystalData_ = Ref<COM_CrystalData>();
	Ref<COM_IntegralData> integralData_ = Ref<COM_IntegralData>();
	TypedArray<COM_CourseGift> coursegift_ = {};
public:
	void set_isLeavingTeam_(bool p_val) { isLeavingTeam_ = p_val; }
	bool get_isLeavingTeam_() const { return isLeavingTeam_; }
	void set_isBattle_(bool p_val) { isBattle_ = p_val; }
	bool get_isBattle_() const { return isBattle_; }
	void set_autoBattle_(bool p_val) { autoBattle_ = p_val; }
	bool get_autoBattle_() const { return autoBattle_; }
	void set_isTeamLeader_(bool p_val) { isTeamLeader_ = p_val; }
	bool get_isTeamLeader_() const { return isTeamLeader_; }
	void set_sceneId_(int32_t p_val) { sceneId_ = p_val; }
	int32_t get_sceneId_() const { return sceneId_; }
	void set_openSubSystemFlag_(uint64_t p_val) { openSubSystemFlag_ = p_val; }
	uint64_t get_openSubSystemFlag_() const { return openSubSystemFlag_; }
	void set_createTime_(int64_t p_val) { createTime_ = p_val; }
	int64_t get_createTime_() const { return createTime_; }
	void set_guildName_(String p_val) { guildName_ = p_val; }
	String get_guildName_() const { return guildName_; }
	void set_scenePos_(Ref<COM_FPosition> p_val) { scenePos_ = p_val; }
	Ref<COM_FPosition> get_scenePos_() const { return scenePos_; }
	void set_pvpInfo_(Ref<COM_PlayerVsPlayer> p_val) { pvpInfo_ = p_val; }
	Ref<COM_PlayerVsPlayer> get_pvpInfo_() const { return pvpInfo_; }
	void set_onlineTimeFlag_(bool p_val) { onlineTimeFlag_ = p_val; }
	bool get_onlineTimeFlag_() const { return onlineTimeFlag_; }
	void set_onlineTime_(float p_val) { onlineTime_ = p_val; }
	float get_onlineTime_() const { return onlineTime_; }
	void set_onlineTimeReward_(TypedArray<uint32_t> p_val) { onlineTimeReward_ = p_val; }
	TypedArray<uint32_t> get_onlineTimeReward_() const { return onlineTimeReward_; }
	void set_isFund_(bool p_val) { isFund_ = p_val; }
	bool get_isFund_() const { return isFund_; }
	void set_fundtags_(TypedArray<uint32_t> p_val) { fundtags_ = p_val; }
	TypedArray<uint32_t> get_fundtags_() const { return fundtags_; }
	void set_openDoubleTimeFlag_(bool p_val) { openDoubleTimeFlag_ = p_val; }
	bool get_openDoubleTimeFlag_() const { return openDoubleTimeFlag_; }
	void set_isFirstLogin_(bool p_val) { isFirstLogin_ = p_val; }
	bool get_isFirstLogin_() const { return isFirstLogin_; }
	void set_firstRechargeDiamond_(bool p_val) { firstRechargeDiamond_ = p_val; }
	bool get_firstRechargeDiamond_() const { return firstRechargeDiamond_; }
	void set_isFirstRechargeGift_(bool p_val) { isFirstRechargeGift_ = p_val; }
	bool get_isFirstRechargeGift_() const { return isFirstRechargeGift_; }
	void set_offlineExp_(float p_val) { offlineExp_ = p_val; }
	float get_offlineExp_() const { return offlineExp_; }
	void set_rivalTime_(float p_val) { rivalTime_ = p_val; }
	float get_rivalTime_() const { return rivalTime_; }
	void set_rivalNum_(int8_t p_val) { rivalNum_ = p_val; }
	int8_t get_rivalNum_() const { return rivalNum_; }
	void set_promoteAward_(int8_t p_val) { promoteAward_ = p_val; }
	int8_t get_promoteAward_() const { return promoteAward_; }
	void set_guideIdx_(uint64_t p_val) { guideIdx_ = p_val; }
	uint64_t get_guideIdx_() const { return guideIdx_; }
	void set_noTalkTime_(float p_val) { noTalkTime_ = p_val; }
	float get_noTalkTime_() const { return noTalkTime_; }
	void set_wishShareNum_(uint32_t p_val) { wishShareNum_ = p_val; }
	uint32_t get_wishShareNum_() const { return wishShareNum_; }
	void set_warriortrophyNum_(uint32_t p_val) { warriortrophyNum_ = p_val; }
	uint32_t get_warriortrophyNum_() const { return warriortrophyNum_; }
	void set_employeelasttime_(uint32_t p_val) { employeelasttime_ = p_val; }
	uint32_t get_employeelasttime_() const { return employeelasttime_; }
	void set_employeeonecount_(uint32_t p_val) { employeeonecount_ = p_val; }
	uint32_t get_employeeonecount_() const { return employeeonecount_; }
	void set_employeetencount_(uint32_t p_val) { employeetencount_ = p_val; }
	uint32_t get_employeetencount_() const { return employeetencount_; }
	void set_greenBoxTimes_(float p_val) { greenBoxTimes_ = p_val; }
	float get_greenBoxTimes_() const { return greenBoxTimes_; }
	void set_blueBoxTimes_(float p_val) { blueBoxTimes_ = p_val; }
	float get_blueBoxTimes_() const { return blueBoxTimes_; }
	void set_greenBoxFreeNum_(uint32_t p_val) { greenBoxFreeNum_ = p_val; }
	uint32_t get_greenBoxFreeNum_() const { return greenBoxFreeNum_; }
	void set_hbInfo_(Ref<COM_HundredBattle> p_val) { hbInfo_ = p_val; }
	Ref<COM_HundredBattle> get_hbInfo_() const { return hbInfo_; }
	void set_openScenes_(TypedArray<int32_t> p_val) { openScenes_ = p_val; }
	TypedArray<int32_t> get_openScenes_() const { return openScenes_; }
	void set_copyNum_(TypedArray<uint32_t> p_val) { copyNum_ = p_val; }
	TypedArray<uint32_t> get_copyNum_() const { return copyNum_; }
	void set_magicItemLevel_(int32_t p_val) { magicItemLevel_ = p_val; }
	int32_t get_magicItemLevel_() const { return magicItemLevel_; }
	void set_magicItemeExp_(int32_t p_val) { magicItemeExp_ = p_val; }
	int32_t get_magicItemeExp_() const { return magicItemeExp_; }
	void set_magicItemeJob_(uint16_t p_val) { magicItemeJob_ = p_val; }
	uint16_t get_magicItemeJob_() const { return magicItemeJob_; }
	void set_magicTupoLevel_(int32_t p_val) { magicTupoLevel_ = p_val; }
	int32_t get_magicTupoLevel_() const { return magicTupoLevel_; }
	void set_cachedNpcs_(TypedArray<int32_t> p_val) { cachedNpcs_ = p_val; }
	TypedArray<int32_t> get_cachedNpcs_() const { return cachedNpcs_; }
	void set_gft_(TypedArray<String> p_val) { gft_ = p_val; }
	TypedArray<String> get_gft_() const { return gft_; }
	void set_babycache_(TypedArray<uint32_t> p_val) { babycache_ = p_val; }
	TypedArray<uint32_t> get_babycache_() const { return babycache_; }
	void set_titles_(TypedArray<int32_t> p_val) { titles_ = p_val; }
	TypedArray<int32_t> get_titles_() const { return titles_; }
	void set_guildContribution_(int32_t p_val) { guildContribution_ = p_val; }
	int32_t get_guildContribution_() const { return guildContribution_; }
	void set_exitGuildTime_(uint32_t p_val) { exitGuildTime_ = p_val; }
	uint32_t get_exitGuildTime_() const { return exitGuildTime_; }
	void set_guildSkills_(TypedArray<COM_Skill> p_val) { guildSkills_ = p_val; }
	TypedArray<COM_Skill> get_guildSkills_() const { return guildSkills_; }
	void set_gmActivities_(TypedArray<uint16_t> p_val) { gmActivities_ = p_val; }
	TypedArray<uint16_t> get_gmActivities_() const { return gmActivities_; }
	void set_festival_(Ref<COM_ADLoginTotal> p_val) { festival_ = p_val; }
	Ref<COM_ADLoginTotal> get_festival_() const { return festival_; }
	void set_selfRecharge_(Ref<COM_ADChargeTotal> p_val) { selfRecharge_ = p_val; }
	Ref<COM_ADChargeTotal> get_selfRecharge_() const { return selfRecharge_; }
	void set_sysRecharge_(Ref<COM_ADChargeTotal> p_val) { sysRecharge_ = p_val; }
	Ref<COM_ADChargeTotal> get_sysRecharge_() const { return sysRecharge_; }
	void set_selfDiscountStore_(Ref<COM_ADDiscountStore> p_val) { selfDiscountStore_ = p_val; }
	Ref<COM_ADDiscountStore> get_selfDiscountStore_() const { return selfDiscountStore_; }
	void set_sysDiscountStore_(Ref<COM_ADDiscountStore> p_val) { sysDiscountStore_ = p_val; }
	Ref<COM_ADDiscountStore> get_sysDiscountStore_() const { return sysDiscountStore_; }
	void set_selfOnceRecharge_(Ref<COM_ADChargeEvery> p_val) { selfOnceRecharge_ = p_val; }
	Ref<COM_ADChargeEvery> get_selfOnceRecharge_() const { return selfOnceRecharge_; }
	void set_sysOnceRecharge_(Ref<COM_ADChargeEvery> p_val) { sysOnceRecharge_ = p_val; }
	Ref<COM_ADChargeEvery> get_sysOnceRecharge_() const { return sysOnceRecharge_; }
	void set_empact_(Ref<COM_ADEmployeeTotal> p_val) { empact_ = p_val; }
	Ref<COM_ADEmployeeTotal> get_empact_() const { return empact_; }
	void set_selfCards_(Ref<COM_ADCards> p_val) { selfCards_ = p_val; }
	Ref<COM_ADCards> get_selfCards_() const { return selfCards_; }
	void set_myselfRecharge_(Ref<COM_ADChargeTotal> p_val) { myselfRecharge_ = p_val; }
	Ref<COM_ADChargeTotal> get_myselfRecharge_() const { return myselfRecharge_; }
	void set_hotdata_(Ref<COM_ADHotRole> p_val) { hotdata_ = p_val; }
	Ref<COM_ADHotRole> get_hotdata_() const { return hotdata_; }
	void set_gbdata_(Ref<COM_ADGiftBag> p_val) { gbdata_ = p_val; }
	Ref<COM_ADGiftBag> get_gbdata_() const { return gbdata_; }
	void set_sevenflag_(bool p_val) { sevenflag_ = p_val; }
	bool get_sevenflag_() const { return sevenflag_; }
	void set_signFlag_(bool p_val) { signFlag_ = p_val; }
	bool get_signFlag_() const { return signFlag_; }
	void set_sevendata_(TypedArray<COM_Sevenday> p_val) { sevendata_ = p_val; }
	TypedArray<COM_Sevenday> get_sevendata_() const { return sevendata_; }
	void set_viprewardflag_(bool p_val) { viprewardflag_ = p_val; }
	bool get_viprewardflag_() const { return viprewardflag_; }
	void set_phoneNumber_(String p_val) { phoneNumber_ = p_val; }
	String get_phoneNumber_() const { return phoneNumber_; }
	void set_levelgift_(TypedArray<uint32_t> p_val) { levelgift_ = p_val; }
	TypedArray<uint32_t> get_levelgift_() const { return levelgift_; }
	void set_activity_(Ref<COM_ActivityTable> p_val) { activity_ = p_val; }
	Ref<COM_ActivityTable> get_activity_() const { return activity_; }
	void set_fuwen_(TypedArray<COM_Item> p_val) { fuwen_ = p_val; }
	TypedArray<COM_Item> get_fuwen_() const { return fuwen_; }
	void set_crystalData_(Ref<COM_CrystalData> p_val) { crystalData_ = p_val; }
	Ref<COM_CrystalData> get_crystalData_() const { return crystalData_; }
	void set_integralData_(Ref<COM_IntegralData> p_val) { integralData_ = p_val; }
	Ref<COM_IntegralData> get_integralData_() const { return integralData_; }
	void set_coursegift_(TypedArray<COM_CourseGift> p_val) { coursegift_ = p_val; }
	TypedArray<COM_CourseGift> get_coursegift_() const { return coursegift_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_MonsterInst
class COM_MonsterInst : public COM_Entity {
	GDCLASS(COM_MonsterInst, COM_Entity);
protected:
	TypedArray<int32_t> gear_ = {};
public:
	void set_gear_(TypedArray<int32_t> p_val) { gear_ = p_val; }
	TypedArray<int32_t> get_gear_() const { return gear_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ReportState
class COM_ReportState : public COM_State {
	GDCLASS(COM_ReportState, COM_State);
protected:
	bool add_ = false;
	int32_t ownerId_ = 0;
	int8_t addQueue_ = 0;
public:
	void set_add_(bool p_val) { add_ = p_val; }
	bool get_add_() const { return add_; }
	void set_ownerId_(int32_t p_val) { ownerId_ = p_val; }
	int32_t get_ownerId_() const { return ownerId_; }
	void set_addQueue_(int8_t p_val) { addQueue_ = p_val; }
	int8_t get_addQueue_() const { return addQueue_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ReportTargetBase
class COM_ReportTargetBase : public Resource {
	GDCLASS(COM_ReportTargetBase, Resource);
protected:
	uint16_t position_ = (BattlePosition)0;
	Ref<COM_PropValue> prop_ = Ref<COM_PropValue>();
	bool bao_ = false;
	bool fly_ = false;
public:
	void set_position_(uint16_t p_val) { position_ = p_val; }
	uint16_t get_position_() const { return position_; }
	void set_prop_(Ref<COM_PropValue> p_val) { prop_ = p_val; }
	Ref<COM_PropValue> get_prop_() const { return prop_; }
	void set_bao_(bool p_val) { bao_ = p_val; }
	bool get_bao_() const { return bao_; }
	void set_fly_(bool p_val) { fly_ = p_val; }
	bool get_fly_() const { return fly_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ReportTarget
class COM_ReportTarget : public COM_ReportTargetBase {
	GDCLASS(COM_ReportTarget, COM_ReportTargetBase);
protected:
	TypedArray<COM_ReportTargetBase> prop2_ = {};
public:
	void set_prop2_(TypedArray<COM_ReportTargetBase> p_val) { prop2_ = p_val; }
	TypedArray<COM_ReportTargetBase> get_prop2_() const { return prop2_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Order
class COM_Order : public Resource {
	GDCLASS(COM_Order, Resource);
protected:
	uint16_t status_ = (OrderStatus)0;
	int32_t casterId_ = 0;
	int32_t target_ = 0;
	int32_t skill_ = 0;
	int32_t itemId_ = 0;
	int32_t weaponInstId_ = 0;
	int32_t babyId_ = 0;
	int8_t isSec_ = 0;
	int8_t uinteGroup_ = 0;
	int32_t uniteNum_ = 0;
	bool isNo_ = false;
public:
	void set_status_(uint16_t p_val) { status_ = p_val; }
	uint16_t get_status_() const { return status_; }
	void set_casterId_(int32_t p_val) { casterId_ = p_val; }
	int32_t get_casterId_() const { return casterId_; }
	void set_target_(int32_t p_val) { target_ = p_val; }
	int32_t get_target_() const { return target_; }
	void set_skill_(int32_t p_val) { skill_ = p_val; }
	int32_t get_skill_() const { return skill_; }
	void set_itemId_(int32_t p_val) { itemId_ = p_val; }
	int32_t get_itemId_() const { return itemId_; }
	void set_weaponInstId_(int32_t p_val) { weaponInstId_ = p_val; }
	int32_t get_weaponInstId_() const { return weaponInstId_; }
	void set_babyId_(int32_t p_val) { babyId_ = p_val; }
	int32_t get_babyId_() const { return babyId_; }
	void set_isSec_(int8_t p_val) { isSec_ = p_val; }
	int8_t get_isSec_() const { return isSec_; }
	void set_uinteGroup_(int8_t p_val) { uinteGroup_ = p_val; }
	int8_t get_uinteGroup_() const { return uinteGroup_; }
	void set_uniteNum_(int32_t p_val) { uniteNum_ = p_val; }
	int32_t get_uniteNum_() const { return uniteNum_; }
	void set_isNo_(bool p_val) { isNo_ = p_val; }
	bool get_isNo_() const { return isNo_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ReportActionCounter
class COM_ReportActionCounter : public Resource {
	GDCLASS(COM_ReportActionCounter, Resource);
protected:
	int32_t casterId_ = 0;
	uint8_t targetPosition_ = 0;
	Ref<COM_ReportTarget> props_ = Ref<COM_ReportTarget>();
	TypedArray<COM_ReportState> states_ = {};
public:
	void set_casterId_(int32_t p_val) { casterId_ = p_val; }
	int32_t get_casterId_() const { return casterId_; }
	void set_targetPosition_(uint8_t p_val) { targetPosition_ = p_val; }
	uint8_t get_targetPosition_() const { return targetPosition_; }
	void set_props_(Ref<COM_ReportTarget> p_val) { props_ = p_val; }
	Ref<COM_ReportTarget> get_props_() const { return props_; }
	void set_states_(TypedArray<COM_ReportState> p_val) { states_ = p_val; }
	TypedArray<COM_ReportState> get_states_() const { return states_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ReportAction
class COM_ReportAction : public COM_Order {
	GDCLASS(COM_ReportAction, COM_Order);
protected:
	bool zhuachongOk_ = false;
	uint8_t skillLevel_ = 0;
	uint8_t huweiPosition_ = 0;
	uint16_t bp0_ = (BattlePosition)0;
	uint16_t bp1_ = (BattlePosition)0;
	Ref<COM_BattleEntityInformation> baby_ = Ref<COM_BattleEntityInformation>();
	TypedArray<int32_t> eraseEntities_ = {};
	TypedArray<COM_ReportTarget> targets_ = {};
	TypedArray<COM_ReportState> stateIds_ = {};
	TypedArray<COM_ReportActionCounter> counters_ = {};
	TypedArray<COM_BattleEntityInformation> dynamicEntities_ = {};
public:
	void set_zhuachongOk_(bool p_val) { zhuachongOk_ = p_val; }
	bool get_zhuachongOk_() const { return zhuachongOk_; }
	void set_skillLevel_(uint8_t p_val) { skillLevel_ = p_val; }
	uint8_t get_skillLevel_() const { return skillLevel_; }
	void set_huweiPosition_(uint8_t p_val) { huweiPosition_ = p_val; }
	uint8_t get_huweiPosition_() const { return huweiPosition_; }
	void set_bp0_(uint16_t p_val) { bp0_ = p_val; }
	uint16_t get_bp0_() const { return bp0_; }
	void set_bp1_(uint16_t p_val) { bp1_ = p_val; }
	uint16_t get_bp1_() const { return bp1_; }
	void set_baby_(Ref<COM_BattleEntityInformation> p_val) { baby_ = p_val; }
	Ref<COM_BattleEntityInformation> get_baby_() const { return baby_; }
	void set_eraseEntities_(TypedArray<int32_t> p_val) { eraseEntities_ = p_val; }
	TypedArray<int32_t> get_eraseEntities_() const { return eraseEntities_; }
	void set_targets_(TypedArray<COM_ReportTarget> p_val) { targets_ = p_val; }
	TypedArray<COM_ReportTarget> get_targets_() const { return targets_; }
	void set_stateIds_(TypedArray<COM_ReportState> p_val) { stateIds_ = p_val; }
	TypedArray<COM_ReportState> get_stateIds_() const { return stateIds_; }
	void set_counters_(TypedArray<COM_ReportActionCounter> p_val) { counters_ = p_val; }
	TypedArray<COM_ReportActionCounter> get_counters_() const { return counters_; }
	void set_dynamicEntities_(TypedArray<COM_BattleEntityInformation> p_val) { dynamicEntities_ = p_val; }
	TypedArray<COM_BattleEntityInformation> get_dynamicEntities_() const { return dynamicEntities_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_BattleReport
class COM_BattleReport : public Resource {
	GDCLASS(COM_BattleReport, Resource);
protected:
	TypedArray<COM_ReportState> stateIds_ = {};
	TypedArray<COM_ReportAction> actionResults_ = {};
	TypedArray<COM_ReportTarget> targets_ = {};
	TypedArray<COM_BattleEntityInformation> waveEntities_ = {};
public:
	void set_stateIds_(TypedArray<COM_ReportState> p_val) { stateIds_ = p_val; }
	TypedArray<COM_ReportState> get_stateIds_() const { return stateIds_; }
	void set_actionResults_(TypedArray<COM_ReportAction> p_val) { actionResults_ = p_val; }
	TypedArray<COM_ReportAction> get_actionResults_() const { return actionResults_; }
	void set_targets_(TypedArray<COM_ReportTarget> p_val) { targets_ = p_val; }
	TypedArray<COM_ReportTarget> get_targets_() const { return targets_; }
	void set_waveEntities_(TypedArray<COM_BattleEntityInformation> p_val) { waveEntities_ = p_val; }
	TypedArray<COM_BattleEntityInformation> get_waveEntities_() const { return waveEntities_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_InitBattle
class COM_InitBattle : public Resource {
	GDCLASS(COM_InitBattle, Resource);
protected:
	uint32_t battleId_ = 0;
	uint16_t bt_ = (BattleType)0;
	uint32_t roundCount_ = 0;
	uint16_t opType_ = (OperateType)0;
	uint16_t sneakAttack_ = (SneakAttackType)0;
	TypedArray<COM_BattleEntityInformation> actors_ = {};
public:
	void set_battleId_(uint32_t p_val) { battleId_ = p_val; }
	uint32_t get_battleId_() const { return battleId_; }
	void set_bt_(uint16_t p_val) { bt_ = p_val; }
	uint16_t get_bt_() const { return bt_; }
	void set_roundCount_(uint32_t p_val) { roundCount_ = p_val; }
	uint32_t get_roundCount_() const { return roundCount_; }
	void set_opType_(uint16_t p_val) { opType_ = p_val; }
	uint16_t get_opType_() const { return opType_; }
	void set_sneakAttack_(uint16_t p_val) { sneakAttack_ = p_val; }
	uint16_t get_sneakAttack_() const { return sneakAttack_; }
	void set_actors_(TypedArray<COM_BattleEntityInformation> p_val) { actors_ = p_val; }
	TypedArray<COM_BattleEntityInformation> get_actors_() const { return actors_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_CreateTeamInfo
class COM_CreateTeamInfo : public Resource {
	GDCLASS(COM_CreateTeamInfo, Resource);
protected:
	uint16_t type_ = (TeamType)0;
	uint8_t maxMemberSize_ = 0;
	String name_ = "";
	String pwd_ = "";
	uint16_t minLevel_ = 0;
	uint16_t maxLevel_ = 0;
public:
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_maxMemberSize_(uint8_t p_val) { maxMemberSize_ = p_val; }
	uint8_t get_maxMemberSize_() const { return maxMemberSize_; }
	void set_name_(String p_val) { name_ = p_val; }
	String get_name_() const { return name_; }
	void set_pwd_(String p_val) { pwd_ = p_val; }
	String get_pwd_() const { return pwd_; }
	void set_minLevel_(uint16_t p_val) { minLevel_ = p_val; }
	uint16_t get_minLevel_() const { return minLevel_; }
	void set_maxLevel_(uint16_t p_val) { maxLevel_ = p_val; }
	uint16_t get_maxLevel_() const { return maxLevel_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SimpleTeamInfo
class COM_SimpleTeamInfo : public COM_CreateTeamInfo {
	GDCLASS(COM_SimpleTeamInfo, COM_CreateTeamInfo);
protected:
	uint32_t teamId_ = 0;
	uint8_t curMemberSize_ = 0;
	String leaderName_ = "";
	uint16_t job_ = (JobType)0;
	uint32_t joblevel_ = 0;
	bool needPassword_ = false;
	bool isRunning_ = false;
	bool isWelcome_ = false;
public:
	void set_teamId_(uint32_t p_val) { teamId_ = p_val; }
	uint32_t get_teamId_() const { return teamId_; }
	void set_curMemberSize_(uint8_t p_val) { curMemberSize_ = p_val; }
	uint8_t get_curMemberSize_() const { return curMemberSize_; }
	void set_leaderName_(String p_val) { leaderName_ = p_val; }
	String get_leaderName_() const { return leaderName_; }
	void set_job_(uint16_t p_val) { job_ = p_val; }
	uint16_t get_job_() const { return job_; }
	void set_joblevel_(uint32_t p_val) { joblevel_ = p_val; }
	uint32_t get_joblevel_() const { return joblevel_; }
	void set_needPassword_(bool p_val) { needPassword_ = p_val; }
	bool get_needPassword_() const { return needPassword_; }
	void set_isRunning_(bool p_val) { isRunning_ = p_val; }
	bool get_isRunning_() const { return isRunning_; }
	void set_isWelcome_(bool p_val) { isWelcome_ = p_val; }
	bool get_isWelcome_() const { return isWelcome_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_TeamInfo
class COM_TeamInfo : public COM_SimpleTeamInfo {
	GDCLASS(COM_TeamInfo, COM_SimpleTeamInfo);
protected:
	TypedArray<COM_SimplePlayerInst> members_ = {};
public:
	void set_members_(TypedArray<COM_SimplePlayerInst> p_val) { members_ = p_val; }
	TypedArray<COM_SimplePlayerInst> get_members_() const { return members_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_JJCBattleMsg
class COM_JJCBattleMsg : public Resource {
	GDCLASS(COM_JJCBattleMsg, Resource);
protected:
	String defier_ = "";
	String bydefier_ = "";
	uint32_t rank_ = 0;
	bool isWin_ = false;
	int64_t curTime_ = 0;
public:
	void set_defier_(String p_val) { defier_ = p_val; }
	String get_defier_() const { return defier_; }
	void set_bydefier_(String p_val) { bydefier_ = p_val; }
	String get_bydefier_() const { return bydefier_; }
	void set_rank_(uint32_t p_val) { rank_ = p_val; }
	uint32_t get_rank_() const { return rank_; }
	void set_isWin_(bool p_val) { isWin_ = p_val; }
	bool get_isWin_() const { return isWin_; }
	void set_curTime_(int64_t p_val) { curTime_ = p_val; }
	int64_t get_curTime_() const { return curTime_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_BattleEmp
class COM_BattleEmp : public Resource {
	GDCLASS(COM_BattleEmp, Resource);
protected:
	uint16_t empBattleGroup_ = (EmployeesBattleGroup)0;
	TypedArray<uint32_t> employeeGroup1_ = {};
	TypedArray<uint32_t> employeeGroup2_ = {};
public:
	void set_empBattleGroup_(uint16_t p_val) { empBattleGroup_ = p_val; }
	uint16_t get_empBattleGroup_() const { return empBattleGroup_; }
	void set_employeeGroup1_(TypedArray<uint32_t> p_val) { employeeGroup1_ = p_val; }
	TypedArray<uint32_t> get_employeeGroup1_() const { return employeeGroup1_; }
	void set_employeeGroup2_(TypedArray<uint32_t> p_val) { employeeGroup2_ = p_val; }
	TypedArray<uint32_t> get_employeeGroup2_() const { return employeeGroup2_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Gather
class COM_Gather : public Resource {
	GDCLASS(COM_Gather, Resource);
protected:
	uint32_t gatherId_ = 0;
	uint16_t flag_ = (GatherStateType)0;
	uint32_t num_ = 0;
public:
	void set_gatherId_(uint32_t p_val) { gatherId_ = p_val; }
	uint32_t get_gatherId_() const { return gatherId_; }
	void set_flag_(uint16_t p_val) { flag_ = p_val; }
	uint16_t get_flag_() const { return flag_; }
	void set_num_(uint32_t p_val) { num_ = p_val; }
	uint32_t get_num_() const { return num_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_DBPlayerData
class SGE_DBPlayerData : public COM_PlayerInst {
	GDCLASS(SGE_DBPlayerData, COM_PlayerInst);
protected:
	int32_t versionNumber_ = 0;
	bool freeze_ = false;
	bool seal_ = false;
	uint32_t signs_ = 0;
	int32_t sellIdMax_ = 0;
	int32_t push_ = 0;
	int32_t acceptRandQuestCounter_ = 0;
	int32_t submitRandQuestCounter_ = 0;
	String pfid_ = "";
	int32_t itemStoreSize_ = 0;
	int32_t babyStoreSize_ = 0;
	TypedArray<SGE_OrderInfo> orders_ = {};
	uint64_t loginTime_ = 0;
	uint64_t logoutTime_ = 0;
	uint32_t genItemMaxGuid_ = 0;
	uint32_t gaterMaxNum_ = 0;
	bool firstRollEmployeeCon_ = false;
	bool firstRollEmployeeDia_ = false;
	TypedArray<COM_EmployeeInst> employees_ = {};
	TypedArray<COM_Item> itemStorage_ = {};
	TypedArray<COM_BabyInst> babyStorage_ = {};
	TypedArray<COM_BabyInst> babies_ = {};
	TypedArray<COM_Item> bagItems_ = {};
	TypedArray<COM_QuestInst> quests_ = {};
	TypedArray<int32_t> completeQuests_ = {};
	TypedArray<COM_Item> mineReward_ = {};
	TypedArray<COM_JJCBattleMsg> jjcBattleMsg_ = {};
	TypedArray<COM_ContactInfo> friend_ = {};
	TypedArray<COM_ContactInfo> blacklist_ = {};
	TypedArray<int32_t> achValues_ = {};
	TypedArray<COM_Achievement> achievement_ = {};
	uint16_t empBattleGroup_ = (EmployeesBattleGroup)0;
	TypedArray<uint32_t> employeeGroup1_ = {};
	TypedArray<uint32_t> employeeGroup2_ = {};
	TypedArray<COM_Gather> gatherData_ = {};
	TypedArray<uint32_t> compoundList_ = {};
public:
	void set_versionNumber_(int32_t p_val) { versionNumber_ = p_val; }
	int32_t get_versionNumber_() const { return versionNumber_; }
	void set_freeze_(bool p_val) { freeze_ = p_val; }
	bool get_freeze_() const { return freeze_; }
	void set_seal_(bool p_val) { seal_ = p_val; }
	bool get_seal_() const { return seal_; }
	void set_signs_(uint32_t p_val) { signs_ = p_val; }
	uint32_t get_signs_() const { return signs_; }
	void set_sellIdMax_(int32_t p_val) { sellIdMax_ = p_val; }
	int32_t get_sellIdMax_() const { return sellIdMax_; }
	void set_push_(int32_t p_val) { push_ = p_val; }
	int32_t get_push_() const { return push_; }
	void set_acceptRandQuestCounter_(int32_t p_val) { acceptRandQuestCounter_ = p_val; }
	int32_t get_acceptRandQuestCounter_() const { return acceptRandQuestCounter_; }
	void set_submitRandQuestCounter_(int32_t p_val) { submitRandQuestCounter_ = p_val; }
	int32_t get_submitRandQuestCounter_() const { return submitRandQuestCounter_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_itemStoreSize_(int32_t p_val) { itemStoreSize_ = p_val; }
	int32_t get_itemStoreSize_() const { return itemStoreSize_; }
	void set_babyStoreSize_(int32_t p_val) { babyStoreSize_ = p_val; }
	int32_t get_babyStoreSize_() const { return babyStoreSize_; }
	void set_orders_(TypedArray<SGE_OrderInfo> p_val) { orders_ = p_val; }
	TypedArray<SGE_OrderInfo> get_orders_() const { return orders_; }
	void set_loginTime_(uint64_t p_val) { loginTime_ = p_val; }
	uint64_t get_loginTime_() const { return loginTime_; }
	void set_logoutTime_(uint64_t p_val) { logoutTime_ = p_val; }
	uint64_t get_logoutTime_() const { return logoutTime_; }
	void set_genItemMaxGuid_(uint32_t p_val) { genItemMaxGuid_ = p_val; }
	uint32_t get_genItemMaxGuid_() const { return genItemMaxGuid_; }
	void set_gaterMaxNum_(uint32_t p_val) { gaterMaxNum_ = p_val; }
	uint32_t get_gaterMaxNum_() const { return gaterMaxNum_; }
	void set_firstRollEmployeeCon_(bool p_val) { firstRollEmployeeCon_ = p_val; }
	bool get_firstRollEmployeeCon_() const { return firstRollEmployeeCon_; }
	void set_firstRollEmployeeDia_(bool p_val) { firstRollEmployeeDia_ = p_val; }
	bool get_firstRollEmployeeDia_() const { return firstRollEmployeeDia_; }
	void set_employees_(TypedArray<COM_EmployeeInst> p_val) { employees_ = p_val; }
	TypedArray<COM_EmployeeInst> get_employees_() const { return employees_; }
	void set_itemStorage_(TypedArray<COM_Item> p_val) { itemStorage_ = p_val; }
	TypedArray<COM_Item> get_itemStorage_() const { return itemStorage_; }
	void set_babyStorage_(TypedArray<COM_BabyInst> p_val) { babyStorage_ = p_val; }
	TypedArray<COM_BabyInst> get_babyStorage_() const { return babyStorage_; }
	void set_babies_(TypedArray<COM_BabyInst> p_val) { babies_ = p_val; }
	TypedArray<COM_BabyInst> get_babies_() const { return babies_; }
	void set_bagItems_(TypedArray<COM_Item> p_val) { bagItems_ = p_val; }
	TypedArray<COM_Item> get_bagItems_() const { return bagItems_; }
	void set_quests_(TypedArray<COM_QuestInst> p_val) { quests_ = p_val; }
	TypedArray<COM_QuestInst> get_quests_() const { return quests_; }
	void set_completeQuests_(TypedArray<int32_t> p_val) { completeQuests_ = p_val; }
	TypedArray<int32_t> get_completeQuests_() const { return completeQuests_; }
	void set_mineReward_(TypedArray<COM_Item> p_val) { mineReward_ = p_val; }
	TypedArray<COM_Item> get_mineReward_() const { return mineReward_; }
	void set_jjcBattleMsg_(TypedArray<COM_JJCBattleMsg> p_val) { jjcBattleMsg_ = p_val; }
	TypedArray<COM_JJCBattleMsg> get_jjcBattleMsg_() const { return jjcBattleMsg_; }
	void set_friend_(TypedArray<COM_ContactInfo> p_val) { friend_ = p_val; }
	TypedArray<COM_ContactInfo> get_friend_() const { return friend_; }
	void set_blacklist_(TypedArray<COM_ContactInfo> p_val) { blacklist_ = p_val; }
	TypedArray<COM_ContactInfo> get_blacklist_() const { return blacklist_; }
	void set_achValues_(TypedArray<int32_t> p_val) { achValues_ = p_val; }
	TypedArray<int32_t> get_achValues_() const { return achValues_; }
	void set_achievement_(TypedArray<COM_Achievement> p_val) { achievement_ = p_val; }
	TypedArray<COM_Achievement> get_achievement_() const { return achievement_; }
	void set_empBattleGroup_(uint16_t p_val) { empBattleGroup_ = p_val; }
	uint16_t get_empBattleGroup_() const { return empBattleGroup_; }
	void set_employeeGroup1_(TypedArray<uint32_t> p_val) { employeeGroup1_ = p_val; }
	TypedArray<uint32_t> get_employeeGroup1_() const { return employeeGroup1_; }
	void set_employeeGroup2_(TypedArray<uint32_t> p_val) { employeeGroup2_ = p_val; }
	TypedArray<uint32_t> get_employeeGroup2_() const { return employeeGroup2_; }
	void set_gatherData_(TypedArray<COM_Gather> p_val) { gatherData_ = p_val; }
	TypedArray<COM_Gather> get_gatherData_() const { return gatherData_; }
	void set_compoundList_(TypedArray<uint32_t> p_val) { compoundList_ = p_val; }
	TypedArray<uint32_t> get_compoundList_() const { return compoundList_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_BattleOverClearing
class COM_BattleOverClearing : public Resource {
	GDCLASS(COM_BattleOverClearing, Resource);
protected:
	bool isFly_ = false;
	int32_t playExp_ = 0;
	uint32_t playLevel_ = 0;
	uint32_t playFree_ = 0;
	int32_t pvpJJCGrade_ = 0;
	int32_t money_ = 0;
	uint32_t babyExp_ = 0;
	uint32_t babyLevel_ = 0;
	TypedArray<COM_DropItem> items_ = {};
	TypedArray<COM_Skill> skills_ = {};
public:
	void set_isFly_(bool p_val) { isFly_ = p_val; }
	bool get_isFly_() const { return isFly_; }
	void set_playExp_(int32_t p_val) { playExp_ = p_val; }
	int32_t get_playExp_() const { return playExp_; }
	void set_playLevel_(uint32_t p_val) { playLevel_ = p_val; }
	uint32_t get_playLevel_() const { return playLevel_; }
	void set_playFree_(uint32_t p_val) { playFree_ = p_val; }
	uint32_t get_playFree_() const { return playFree_; }
	void set_pvpJJCGrade_(int32_t p_val) { pvpJJCGrade_ = p_val; }
	int32_t get_pvpJJCGrade_() const { return pvpJJCGrade_; }
	void set_money_(int32_t p_val) { money_ = p_val; }
	int32_t get_money_() const { return money_; }
	void set_babyExp_(uint32_t p_val) { babyExp_ = p_val; }
	uint32_t get_babyExp_() const { return babyExp_; }
	void set_babyLevel_(uint32_t p_val) { babyLevel_ = p_val; }
	uint32_t get_babyLevel_() const { return babyLevel_; }
	void set_items_(TypedArray<COM_DropItem> p_val) { items_ = p_val; }
	TypedArray<COM_DropItem> get_items_() const { return items_; }
	void set_skills_(TypedArray<COM_Skill> p_val) { skills_ = p_val; }
	TypedArray<COM_Skill> get_skills_() const { return skills_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Addprop
class COM_Addprop : public Resource {
	GDCLASS(COM_Addprop, Resource);
protected:
	uint16_t type_ = (PropertyType)0;
	uint32_t uVal_ = 0;
public:
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	void set_uVal_(uint32_t p_val) { uVal_ = p_val; }
	uint32_t get_uVal_() const { return uVal_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ExpendItem
class COM_ExpendItem : public Resource {
	GDCLASS(COM_ExpendItem, Resource);
protected:
	uint32_t itemInstId_ = 0;
	uint32_t num_ = 0;
public:
	void set_itemInstId_(uint32_t p_val) { itemInstId_ = p_val; }
	uint32_t get_itemInstId_() const { return itemInstId_; }
	void set_num_(uint32_t p_val) { num_ = p_val; }
	uint32_t get_num_() const { return num_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Chat
class COM_Chat : public Resource {
	GDCLASS(COM_Chat, Resource);
protected:
	uint16_t ck_ = (ChatKind)0;
	bool isAudio_ = false;
	String content_ = "";
	int32_t audioTime_ = 0;
	TypedArray<uint8_t> audio_ = {};
	bool isMe = false;
	int32_t teamId_ = 0;
	uint16_t teamType_ = (TeamType)0;
	int16_t teamMinLevel_ = 0;
	int16_t teamMaxLevel_ = 0;
	String teamName_ = "";
public:
	void set_ck_(uint16_t p_val) { ck_ = p_val; }
	uint16_t get_ck_() const { return ck_; }
	void set_isAudio_(bool p_val) { isAudio_ = p_val; }
	bool get_isAudio_() const { return isAudio_; }
	void set_content_(String p_val) { content_ = p_val; }
	String get_content_() const { return content_; }
	void set_audioTime_(int32_t p_val) { audioTime_ = p_val; }
	int32_t get_audioTime_() const { return audioTime_; }
	void set_audio_(TypedArray<uint8_t> p_val) { audio_ = p_val; }
	TypedArray<uint8_t> get_audio_() const { return audio_; }
	void set_isMe(bool p_val) { isMe = p_val; }
	bool get_isMe() const { return isMe; }
	void set_teamId_(int32_t p_val) { teamId_ = p_val; }
	int32_t get_teamId_() const { return teamId_; }
	void set_teamType_(uint16_t p_val) { teamType_ = p_val; }
	uint16_t get_teamType_() const { return teamType_; }
	void set_teamMinLevel_(int16_t p_val) { teamMinLevel_ = p_val; }
	int16_t get_teamMinLevel_() const { return teamMinLevel_; }
	void set_teamMaxLevel_(int16_t p_val) { teamMaxLevel_ = p_val; }
	int16_t get_teamMaxLevel_() const { return teamMaxLevel_; }
	void set_teamName_(String p_val) { teamName_ = p_val; }
	String get_teamName_() const { return teamName_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ChatInfo
class COM_ChatInfo : public COM_Chat {
	GDCLASS(COM_ChatInfo, COM_Chat);
protected:
	int32_t audioId_ = 0;
	uint16_t assetId_ = 0;
	String playerName_ = "";
	String guildName_ = "";
	uint32_t instId_ = 0;
public:
	void set_audioId_(int32_t p_val) { audioId_ = p_val; }
	int32_t get_audioId_() const { return audioId_; }
	void set_assetId_(uint16_t p_val) { assetId_ = p_val; }
	uint16_t get_assetId_() const { return assetId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_guildName_(String p_val) { guildName_ = p_val; }
	String get_guildName_() const { return guildName_; }
	void set_instId_(uint32_t p_val) { instId_ = p_val; }
	uint32_t get_instId_() const { return instId_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_EndlessStair
class COM_EndlessStair : public Resource {
	GDCLASS(COM_EndlessStair, Resource);
protected:
	uint32_t rank_ = 0;
	String name_ = "";
	uint16_t job_ = (JobType)0;
	uint32_t joblevel_ = 0;
	int32_t assetId_ = 0;
	uint32_t level_ = 0;
	float rivalTime_ = 0.0;
	int32_t rivalNum_ = 0;
public:
	void set_rank_(uint32_t p_val) { rank_ = p_val; }
	uint32_t get_rank_() const { return rank_; }
	void set_name_(String p_val) { name_ = p_val; }
	String get_name_() const { return name_; }
	void set_job_(uint16_t p_val) { job_ = p_val; }
	uint16_t get_job_() const { return job_; }
	void set_joblevel_(uint32_t p_val) { joblevel_ = p_val; }
	uint32_t get_joblevel_() const { return joblevel_; }
	void set_assetId_(int32_t p_val) { assetId_ = p_val; }
	int32_t get_assetId_() const { return assetId_; }
	void set_level_(uint32_t p_val) { level_ = p_val; }
	uint32_t get_level_() const { return level_; }
	void set_rivalTime_(float p_val) { rivalTime_ = p_val; }
	float get_rivalTime_() const { return rivalTime_; }
	void set_rivalNum_(int32_t p_val) { rivalNum_ = p_val; }
	int32_t get_rivalNum_() const { return rivalNum_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_BabyRankData
class COM_BabyRankData : public Resource {
	GDCLASS(COM_BabyRankData, Resource);
protected:
	uint32_t instId_ = 0;
	int32_t rank_ = 0;
	String name_ = "";
	String ownerName_ = "";
	int32_t ff_ = 0;
public:
	void set_instId_(uint32_t p_val) { instId_ = p_val; }
	uint32_t get_instId_() const { return instId_; }
	void set_rank_(int32_t p_val) { rank_ = p_val; }
	int32_t get_rank_() const { return rank_; }
	void set_name_(String p_val) { name_ = p_val; }
	String get_name_() const { return name_; }
	void set_ownerName_(String p_val) { ownerName_ = p_val; }
	String get_ownerName_() const { return ownerName_; }
	void set_ff_(int32_t p_val) { ff_ = p_val; }
	int32_t get_ff_() const { return ff_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_EmployeeRankData
class COM_EmployeeRankData : public Resource {
	GDCLASS(COM_EmployeeRankData, Resource);
protected:
	uint32_t instId_ = 0;
	int32_t rank_ = 0;
	String name_ = "";
	String ownerName_ = "";
	int32_t ff_ = 0;
public:
	void set_instId_(uint32_t p_val) { instId_ = p_val; }
	uint32_t get_instId_() const { return instId_; }
	void set_rank_(int32_t p_val) { rank_ = p_val; }
	int32_t get_rank_() const { return rank_; }
	void set_name_(String p_val) { name_ = p_val; }
	String get_name_() const { return name_; }
	void set_ownerName_(String p_val) { ownerName_ = p_val; }
	String get_ownerName_() const { return ownerName_; }
	void set_ff_(int32_t p_val) { ff_ = p_val; }
	int32_t get_ff_() const { return ff_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_MailItem
class COM_MailItem : public Resource {
	GDCLASS(COM_MailItem, Resource);
protected:
	int32_t itemId_ = 0;
	int32_t itemStack_ = 0;
public:
	void set_itemId_(int32_t p_val) { itemId_ = p_val; }
	int32_t get_itemId_() const { return itemId_; }
	void set_itemStack_(int32_t p_val) { itemStack_ = p_val; }
	int32_t get_itemStack_() const { return itemStack_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Mail
class COM_Mail : public Resource {
	GDCLASS(COM_Mail, Resource);
protected:
	int32_t mailId_ = 0;
	uint16_t mailType_ = (MailType)0;
	int64_t timestamp_ = 0;
	String sendPlayerName_ = "";
	String recvPlayerName_ = "";
	String title_ = "";
	String content_ = "";
	int32_t money_ = 0;
	int32_t diamond_ = 0;
	TypedArray<COM_MailItem> items_ = {};
	bool isRead_ = false;
public:
	void set_mailId_(int32_t p_val) { mailId_ = p_val; }
	int32_t get_mailId_() const { return mailId_; }
	void set_mailType_(uint16_t p_val) { mailType_ = p_val; }
	uint16_t get_mailType_() const { return mailType_; }
	void set_timestamp_(int64_t p_val) { timestamp_ = p_val; }
	int64_t get_timestamp_() const { return timestamp_; }
	void set_sendPlayerName_(String p_val) { sendPlayerName_ = p_val; }
	String get_sendPlayerName_() const { return sendPlayerName_; }
	void set_recvPlayerName_(String p_val) { recvPlayerName_ = p_val; }
	String get_recvPlayerName_() const { return recvPlayerName_; }
	void set_title_(String p_val) { title_ = p_val; }
	String get_title_() const { return title_; }
	void set_content_(String p_val) { content_ = p_val; }
	String get_content_() const { return content_; }
	void set_money_(int32_t p_val) { money_ = p_val; }
	int32_t get_money_() const { return money_; }
	void set_diamond_(int32_t p_val) { diamond_ = p_val; }
	int32_t get_diamond_() const { return diamond_; }
	void set_items_(TypedArray<COM_MailItem> p_val) { items_ = p_val; }
	TypedArray<COM_MailItem> get_items_() const { return items_; }
	void set_isRead_(bool p_val) { isRead_ = p_val; }
	bool get_isRead_() const { return isRead_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GuildBuilding
class COM_GuildBuilding : public Resource {
	GDCLASS(COM_GuildBuilding, Resource);
protected:
	int32_t level_ = 0;
	int32_t struction_ = 0;
public:
	void set_level_(int32_t p_val) { level_ = p_val; }
	int32_t get_level_() const { return level_; }
	void set_struction_(int32_t p_val) { struction_ = p_val; }
	int32_t get_struction_() const { return struction_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GuildRequestData
class COM_GuildRequestData : public Resource {
	GDCLASS(COM_GuildRequestData, Resource);
protected:
	int64_t roleId_ = 0;
	int8_t level_ = 0;
	String roleName_ = "";
	int32_t time_ = 0;
	int8_t prof_ = 0;
	int8_t profLevel_ = 0;
public:
	void set_roleId_(int64_t p_val) { roleId_ = p_val; }
	int64_t get_roleId_() const { return roleId_; }
	void set_level_(int8_t p_val) { level_ = p_val; }
	int8_t get_level_() const { return level_; }
	void set_roleName_(String p_val) { roleName_ = p_val; }
	String get_roleName_() const { return roleName_; }
	void set_time_(int32_t p_val) { time_ = p_val; }
	int32_t get_time_() const { return time_; }
	void set_prof_(int8_t p_val) { prof_ = p_val; }
	int8_t get_prof_() const { return prof_; }
	void set_profLevel_(int8_t p_val) { profLevel_ = p_val; }
	int8_t get_profLevel_() const { return profLevel_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GuildProgen
class COM_GuildProgen : public Resource {
	GDCLASS(COM_GuildProgen, Resource);
protected:
	int32_t mId_ = 0;
	int32_t lev_ = 0;
	int32_t exp_ = 0;
public:
	void set_mId_(int32_t p_val) { mId_ = p_val; }
	int32_t get_mId_() const { return mId_; }
	void set_lev_(int32_t p_val) { lev_ = p_val; }
	int32_t get_lev_() const { return lev_; }
	void set_exp_(int32_t p_val) { exp_ = p_val; }
	int32_t get_exp_() const { return exp_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Guild
class COM_Guild : public Resource {
	GDCLASS(COM_Guild, Resource);
protected:
	int8_t guildLevel_ = 0;
	int32_t createTime_ = 0;
	uint32_t guildId_ = 0;
	uint32_t guildContribution_ = 0;
	uint32_t fundz_ = 0;
	int32_t presentNum_ = 0;
	int64_t master_ = 0;
	String masterName_ = "";
	String guildName_ = "";
	String notice_ = "";
	TypedArray<COM_GuildRequestData> requestList_ = {};
	int32_t noFundzDays_ = 0;
	TypedArray<COM_GuildBuilding> buildings_ = {};
	TypedArray<COM_GuildProgen> progenitus_ = {};
	TypedArray<int32_t> progenitusPositions_ = {};
public:
	void set_guildLevel_(int8_t p_val) { guildLevel_ = p_val; }
	int8_t get_guildLevel_() const { return guildLevel_; }
	void set_createTime_(int32_t p_val) { createTime_ = p_val; }
	int32_t get_createTime_() const { return createTime_; }
	void set_guildId_(uint32_t p_val) { guildId_ = p_val; }
	uint32_t get_guildId_() const { return guildId_; }
	void set_guildContribution_(uint32_t p_val) { guildContribution_ = p_val; }
	uint32_t get_guildContribution_() const { return guildContribution_; }
	void set_fundz_(uint32_t p_val) { fundz_ = p_val; }
	uint32_t get_fundz_() const { return fundz_; }
	void set_presentNum_(int32_t p_val) { presentNum_ = p_val; }
	int32_t get_presentNum_() const { return presentNum_; }
	void set_master_(int64_t p_val) { master_ = p_val; }
	int64_t get_master_() const { return master_; }
	void set_masterName_(String p_val) { masterName_ = p_val; }
	String get_masterName_() const { return masterName_; }
	void set_guildName_(String p_val) { guildName_ = p_val; }
	String get_guildName_() const { return guildName_; }
	void set_notice_(String p_val) { notice_ = p_val; }
	String get_notice_() const { return notice_; }
	void set_requestList_(TypedArray<COM_GuildRequestData> p_val) { requestList_ = p_val; }
	TypedArray<COM_GuildRequestData> get_requestList_() const { return requestList_; }
	void set_noFundzDays_(int32_t p_val) { noFundzDays_ = p_val; }
	int32_t get_noFundzDays_() const { return noFundzDays_; }
	void set_buildings_(TypedArray<COM_GuildBuilding> p_val) { buildings_ = p_val; }
	TypedArray<COM_GuildBuilding> get_buildings_() const { return buildings_; }
	void set_progenitus_(TypedArray<COM_GuildProgen> p_val) { progenitus_ = p_val; }
	TypedArray<COM_GuildProgen> get_progenitus_() const { return progenitus_; }
	void set_progenitusPositions_(TypedArray<int32_t> p_val) { progenitusPositions_ = p_val; }
	TypedArray<int32_t> get_progenitusPositions_() const { return progenitusPositions_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GuildShopItem
class COM_GuildShopItem : public Resource {
	GDCLASS(COM_GuildShopItem, Resource);
protected:
	int32_t shopId_ = 0;
	int32_t buyLimit_ = 0;
public:
	void set_shopId_(int32_t p_val) { shopId_ = p_val; }
	int32_t get_shopId_() const { return shopId_; }
	void set_buyLimit_(int32_t p_val) { buyLimit_ = p_val; }
	int32_t get_buyLimit_() const { return buyLimit_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GuildMember
class COM_GuildMember : public Resource {
	GDCLASS(COM_GuildMember, Resource);
protected:
	int8_t level_ = 0;
	int8_t shopRefreshTimes_ = 0;
	uint32_t guildId_ = 0;
	int8_t profType_ = 0;
	int8_t profLevel_ = 0;
	int32_t contribution_ = 0;
	int8_t job_ = 0;
	int32_t roleId_ = 0;
	uint32_t offlineTime_ = 0;
	String roleName_ = "";
	uint32_t joinTime_ = 0;
	bool signflag_ = false;
	TypedArray<COM_GuildShopItem> shopItems_ = {};
public:
	void set_level_(int8_t p_val) { level_ = p_val; }
	int8_t get_level_() const { return level_; }
	void set_shopRefreshTimes_(int8_t p_val) { shopRefreshTimes_ = p_val; }
	int8_t get_shopRefreshTimes_() const { return shopRefreshTimes_; }
	void set_guildId_(uint32_t p_val) { guildId_ = p_val; }
	uint32_t get_guildId_() const { return guildId_; }
	void set_profType_(int8_t p_val) { profType_ = p_val; }
	int8_t get_profType_() const { return profType_; }
	void set_profLevel_(int8_t p_val) { profLevel_ = p_val; }
	int8_t get_profLevel_() const { return profLevel_; }
	void set_contribution_(int32_t p_val) { contribution_ = p_val; }
	int32_t get_contribution_() const { return contribution_; }
	void set_job_(int8_t p_val) { job_ = p_val; }
	int8_t get_job_() const { return job_; }
	void set_roleId_(int32_t p_val) { roleId_ = p_val; }
	int32_t get_roleId_() const { return roleId_; }
	void set_offlineTime_(uint32_t p_val) { offlineTime_ = p_val; }
	uint32_t get_offlineTime_() const { return offlineTime_; }
	void set_roleName_(String p_val) { roleName_ = p_val; }
	String get_roleName_() const { return roleName_; }
	void set_joinTime_(uint32_t p_val) { joinTime_ = p_val; }
	uint32_t get_joinTime_() const { return joinTime_; }
	void set_signflag_(bool p_val) { signflag_ = p_val; }
	bool get_signflag_() const { return signflag_; }
	void set_shopItems_(TypedArray<COM_GuildShopItem> p_val) { shopItems_ = p_val; }
	TypedArray<COM_GuildShopItem> get_shopItems_() const { return shopItems_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_GuildViewerData
class COM_GuildViewerData : public Resource {
	GDCLASS(COM_GuildViewerData, Resource);
protected:
	uint32_t guid_ = 0;
	String guildName_ = "";
	String playerName_ = "";
	String notice_ = "";
	int8_t level_ = 0;
	int16_t memberNum_ = 0;
	int16_t memberTotal_ = 0;
	int8_t guildRank_ = 0;
public:
	void set_guid_(uint32_t p_val) { guid_ = p_val; }
	uint32_t get_guid_() const { return guid_; }
	void set_guildName_(String p_val) { guildName_ = p_val; }
	String get_guildName_() const { return guildName_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_notice_(String p_val) { notice_ = p_val; }
	String get_notice_() const { return notice_; }
	void set_level_(int8_t p_val) { level_ = p_val; }
	int8_t get_level_() const { return level_; }
	void set_memberNum_(int16_t p_val) { memberNum_ = p_val; }
	int16_t get_memberNum_() const { return memberNum_; }
	void set_memberTotal_(int16_t p_val) { memberTotal_ = p_val; }
	int16_t get_memberTotal_() const { return memberTotal_; }
	void set_guildRank_(int8_t p_val) { guildRank_ = p_val; }
	int8_t get_guildRank_() const { return guildRank_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SearchContext
class COM_SearchContext : public Resource {
	GDCLASS(COM_SearchContext, Resource);
protected:
	String title_ = "";
	uint16_t ist_ = (ItemSubType)0;
	uint16_t rt_ = (RaceType)0;
	int32_t itemId_ = 0;
	int32_t babyId_ = 0;
	int32_t begin_ = 0;
	int32_t limit_ = 0;
public:
	void set_title_(String p_val) { title_ = p_val; }
	String get_title_() const { return title_; }
	void set_ist_(uint16_t p_val) { ist_ = p_val; }
	uint16_t get_ist_() const { return ist_; }
	void set_rt_(uint16_t p_val) { rt_ = p_val; }
	uint16_t get_rt_() const { return rt_; }
	void set_itemId_(int32_t p_val) { itemId_ = p_val; }
	int32_t get_itemId_() const { return itemId_; }
	void set_babyId_(int32_t p_val) { babyId_ = p_val; }
	int32_t get_babyId_() const { return babyId_; }
	void set_begin_(int32_t p_val) { begin_ = p_val; }
	int32_t get_begin_() const { return begin_; }
	void set_limit_(int32_t p_val) { limit_ = p_val; }
	int32_t get_limit_() const { return limit_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SellItem
class COM_SellItem : public Resource {
	GDCLASS(COM_SellItem, Resource);
protected:
	int32_t guid_ = 0;
	int32_t sellPlayerId_ = 0;
	int32_t sellPrice = 0;
	String title_ = "";
	uint16_t ist_ = (ItemSubType)0;
	uint16_t rt_ = (RaceType)0;
	Ref<COM_Item> item_ = Ref<COM_Item>();
	Ref<COM_BabyInst> baby_ = Ref<COM_BabyInst>();
	int32_t time_ = 0;
public:
	void set_guid_(int32_t p_val) { guid_ = p_val; }
	int32_t get_guid_() const { return guid_; }
	void set_sellPlayerId_(int32_t p_val) { sellPlayerId_ = p_val; }
	int32_t get_sellPlayerId_() const { return sellPlayerId_; }
	void set_sellPrice(int32_t p_val) { sellPrice = p_val; }
	int32_t get_sellPrice() const { return sellPrice; }
	void set_title_(String p_val) { title_ = p_val; }
	String get_title_() const { return title_; }
	void set_ist_(uint16_t p_val) { ist_ = p_val; }
	uint16_t get_ist_() const { return ist_; }
	void set_rt_(uint16_t p_val) { rt_ = p_val; }
	uint16_t get_rt_() const { return rt_; }
	void set_item_(Ref<COM_Item> p_val) { item_ = p_val; }
	Ref<COM_Item> get_item_() const { return item_; }
	void set_baby_(Ref<COM_BabyInst> p_val) { baby_ = p_val; }
	Ref<COM_BabyInst> get_baby_() const { return baby_; }
	void set_time_(int32_t p_val) { time_ = p_val; }
	int32_t get_time_() const { return time_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SelledItem
class COM_SelledItem : public Resource {
	GDCLASS(COM_SelledItem, Resource);
protected:
	int32_t guid_ = 0;
	int32_t sellPlayerId_ = 0;
	int32_t sellTime_ = 0;
	int32_t selledTime_ = 0;
	int32_t itemId_ = 0;
	int32_t babyId_ = 0;
	int32_t itemStack_ = 0;
	int32_t price_ = 0;
	int32_t tax_ = 0;
public:
	void set_guid_(int32_t p_val) { guid_ = p_val; }
	int32_t get_guid_() const { return guid_; }
	void set_sellPlayerId_(int32_t p_val) { sellPlayerId_ = p_val; }
	int32_t get_sellPlayerId_() const { return sellPlayerId_; }
	void set_sellTime_(int32_t p_val) { sellTime_ = p_val; }
	int32_t get_sellTime_() const { return sellTime_; }
	void set_selledTime_(int32_t p_val) { selledTime_ = p_val; }
	int32_t get_selledTime_() const { return selledTime_; }
	void set_itemId_(int32_t p_val) { itemId_ = p_val; }
	int32_t get_itemId_() const { return itemId_; }
	void set_babyId_(int32_t p_val) { babyId_ = p_val; }
	int32_t get_babyId_() const { return babyId_; }
	void set_itemStack_(int32_t p_val) { itemStack_ = p_val; }
	int32_t get_itemStack_() const { return itemStack_; }
	void set_price_(int32_t p_val) { price_ = p_val; }
	int32_t get_price_() const { return price_; }
	void set_tax_(int32_t p_val) { tax_ = p_val; }
	int32_t get_tax_() const { return tax_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_BuyContent
class SGE_BuyContent : public Resource {
	GDCLASS(SGE_BuyContent, Resource);
protected:
	int32_t playerId_ = 0;
	int32_t guid_ = 0;
	int32_t diamond_ = 0;
	int32_t magic_ = 0;
	bool isBabyFull_ = false;
	bool isBagFull_ = false;
public:
	void set_playerId_(int32_t p_val) { playerId_ = p_val; }
	int32_t get_playerId_() const { return playerId_; }
	void set_guid_(int32_t p_val) { guid_ = p_val; }
	int32_t get_guid_() const { return guid_; }
	void set_diamond_(int32_t p_val) { diamond_ = p_val; }
	int32_t get_diamond_() const { return diamond_; }
	void set_magic_(int32_t p_val) { magic_ = p_val; }
	int32_t get_magic_() const { return magic_; }
	void set_isBabyFull_(bool p_val) { isBabyFull_ = p_val; }
	bool get_isBabyFull_() const { return isBabyFull_; }
	void set_isBagFull_(bool p_val) { isBagFull_ = p_val; }
	bool get_isBagFull_() const { return isBagFull_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_ScenePlayerInfo
class SGE_ScenePlayerInfo : public Resource {
	GDCLASS(SGE_ScenePlayerInfo, Resource);
protected:
	int32_t playerId_ = 0;
	int32_t playerLevel_ = 0;
	int32_t sceneId_ = 0;
	int32_t entryId_ = 0;
	TypedArray<int32_t> currentQuestIds_ = {};
	TypedArray<int32_t> accecptQuestIds_ = {};
	TypedArray<int32_t> openScenes_ = {};
public:
	void set_playerId_(int32_t p_val) { playerId_ = p_val; }
	int32_t get_playerId_() const { return playerId_; }
	void set_playerLevel_(int32_t p_val) { playerLevel_ = p_val; }
	int32_t get_playerLevel_() const { return playerLevel_; }
	void set_sceneId_(int32_t p_val) { sceneId_ = p_val; }
	int32_t get_sceneId_() const { return sceneId_; }
	void set_entryId_(int32_t p_val) { entryId_ = p_val; }
	int32_t get_entryId_() const { return entryId_; }
	void set_currentQuestIds_(TypedArray<int32_t> p_val) { currentQuestIds_ = p_val; }
	TypedArray<int32_t> get_currentQuestIds_() const { return currentQuestIds_; }
	void set_accecptQuestIds_(TypedArray<int32_t> p_val) { accecptQuestIds_ = p_val; }
	TypedArray<int32_t> get_accecptQuestIds_() const { return accecptQuestIds_; }
	void set_openScenes_(TypedArray<int32_t> p_val) { openScenes_ = p_val; }
	TypedArray<int32_t> get_openScenes_() const { return openScenes_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_SceneInfo
class COM_SceneInfo : public Resource {
	GDCLASS(COM_SceneInfo, Resource);
protected:
	int32_t sceneId_ = 0;
	Ref<COM_FPosition> position_ = Ref<COM_FPosition>();
	TypedArray<COM_ScenePlayerInformation> players_ = {};
	TypedArray<int32_t> npcs_ = {};
public:
	void set_sceneId_(int32_t p_val) { sceneId_ = p_val; }
	int32_t get_sceneId_() const { return sceneId_; }
	void set_position_(Ref<COM_FPosition> p_val) { position_ = p_val; }
	Ref<COM_FPosition> get_position_() const { return position_; }
	void set_players_(TypedArray<COM_ScenePlayerInformation> p_val) { players_ = p_val; }
	TypedArray<COM_ScenePlayerInformation> get_players_() const { return players_; }
	void set_npcs_(TypedArray<int32_t> p_val) { npcs_ = p_val; }
	TypedArray<int32_t> get_npcs_() const { return npcs_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ReconnectInfo
class COM_ReconnectInfo : public Resource {
	GDCLASS(COM_ReconnectInfo, Resource);
protected:
	uint16_t reconnectProcess_ = (ReconnectType)0;
	String sessionKey_ = "";
	TypedArray<COM_SimpleInformation> roles_ = {};
	Ref<COM_PlayerInst> playerInst_ = Ref<COM_PlayerInst>();
	Ref<COM_SceneInfo> sceneInfo_ = Ref<COM_SceneInfo>();
	Ref<COM_TeamInfo> team_ = Ref<COM_TeamInfo>();
	Ref<COM_InitBattle> initBattle_ = Ref<COM_InitBattle>();
public:
	void set_reconnectProcess_(uint16_t p_val) { reconnectProcess_ = p_val; }
	uint16_t get_reconnectProcess_() const { return reconnectProcess_; }
	void set_sessionKey_(String p_val) { sessionKey_ = p_val; }
	String get_sessionKey_() const { return sessionKey_; }
	void set_roles_(TypedArray<COM_SimpleInformation> p_val) { roles_ = p_val; }
	TypedArray<COM_SimpleInformation> get_roles_() const { return roles_; }
	void set_playerInst_(Ref<COM_PlayerInst> p_val) { playerInst_ = p_val; }
	Ref<COM_PlayerInst> get_playerInst_() const { return playerInst_; }
	void set_sceneInfo_(Ref<COM_SceneInfo> p_val) { sceneInfo_ = p_val; }
	Ref<COM_SceneInfo> get_sceneInfo_() const { return sceneInfo_; }
	void set_team_(Ref<COM_TeamInfo> p_val) { team_ = p_val; }
	Ref<COM_TeamInfo> get_team_() const { return team_; }
	void set_initBattle_(Ref<COM_InitBattle> p_val) { initBattle_ = p_val; }
	Ref<COM_InitBattle> get_initBattle_() const { return initBattle_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Notice
class COM_Notice : public Resource {
	GDCLASS(COM_Notice, Resource);
protected:
	uint16_t SendType_ = (NoticeSendType)0;
	String note_ = "";
	float accumulate_ = 0.0;
	float startTime_ = 0.0;
	float stopTime_ = 0.0;
	float interval_ = 0.0;
	bool validate_ = false;
public:
	void set_SendType_(uint16_t p_val) { SendType_ = p_val; }
	uint16_t get_SendType_() const { return SendType_; }
	void set_note_(String p_val) { note_ = p_val; }
	String get_note_() const { return note_; }
	void set_accumulate_(float p_val) { accumulate_ = p_val; }
	float get_accumulate_() const { return accumulate_; }
	void set_startTime_(float p_val) { startTime_ = p_val; }
	float get_startTime_() const { return startTime_; }
	void set_stopTime_(float p_val) { stopTime_ = p_val; }
	float get_stopTime_() const { return stopTime_; }
	void set_interval_(float p_val) { interval_ = p_val; }
	float get_interval_() const { return interval_; }
	void set_validate_(bool p_val) { validate_ = p_val; }
	bool get_validate_() const { return validate_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ShowItemInst
class COM_ShowItemInst : public Resource {
	GDCLASS(COM_ShowItemInst, Resource);
protected:
	int32_t showId_ = 0;
	String playerName_ = "";
	Ref<COM_Item> itemInst_ = Ref<COM_Item>();
public:
	void set_showId_(int32_t p_val) { showId_ = p_val; }
	int32_t get_showId_() const { return showId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_itemInst_(Ref<COM_Item> p_val) { itemInst_ = p_val; }
	Ref<COM_Item> get_itemInst_() const { return itemInst_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ShowItemInstInfo
class COM_ShowItemInstInfo : public Resource {
	GDCLASS(COM_ShowItemInstInfo, Resource);
protected:
	int32_t showId_ = 0;
	String playerName_ = "";
	uint32_t itemId_ = 0;
public:
	void set_showId_(int32_t p_val) { showId_ = p_val; }
	int32_t get_showId_() const { return showId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_itemId_(uint32_t p_val) { itemId_ = p_val; }
	uint32_t get_itemId_() const { return itemId_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ShowbabyInst
class COM_ShowbabyInst : public Resource {
	GDCLASS(COM_ShowbabyInst, Resource);
protected:
	int32_t showId_ = 0;
	String playerName_ = "";
	Ref<COM_BabyInst> babyInst_ = Ref<COM_BabyInst>();
public:
	void set_showId_(int32_t p_val) { showId_ = p_val; }
	int32_t get_showId_() const { return showId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_babyInst_(Ref<COM_BabyInst> p_val) { babyInst_ = p_val; }
	Ref<COM_BabyInst> get_babyInst_() const { return babyInst_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_ShowbabyInstInfo
class COM_ShowbabyInstInfo : public Resource {
	GDCLASS(COM_ShowbabyInstInfo, Resource);
protected:
	int32_t showId_ = 0;
	String playerName_ = "";
	uint32_t babyId_ = 0;
public:
	void set_showId_(int32_t p_val) { showId_ = p_val; }
	int32_t get_showId_() const { return showId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_babyId_(uint32_t p_val) { babyId_ = p_val; }
	uint32_t get_babyId_() const { return babyId_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_Account
class SGE_Account : public Resource {
	GDCLASS(SGE_Account, Resource);
protected:
	String gamename_ = "";
	String pfid_ = "";
	String pfname_ = "";
	String accountid_ = "";
	uint64_t createtime_ = 0;
	String mac_ = "";
	String idfa_ = "";
	String ip_ = "";
	String devicetype_ = "";
public:
	void set_gamename_(String p_val) { gamename_ = p_val; }
	String get_gamename_() const { return gamename_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_pfname_(String p_val) { pfname_ = p_val; }
	String get_pfname_() const { return pfname_; }
	void set_accountid_(String p_val) { accountid_ = p_val; }
	String get_accountid_() const { return accountid_; }
	void set_createtime_(uint64_t p_val) { createtime_ = p_val; }
	uint64_t get_createtime_() const { return createtime_; }
	void set_mac_(String p_val) { mac_ = p_val; }
	String get_mac_() const { return mac_; }
	void set_idfa_(String p_val) { idfa_ = p_val; }
	String get_idfa_() const { return idfa_; }
	void set_ip_(String p_val) { ip_ = p_val; }
	String get_ip_() const { return ip_; }
	void set_devicetype_(String p_val) { devicetype_ = p_val; }
	String get_devicetype_() const { return devicetype_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_Login
class SGE_Login : public Resource {
	GDCLASS(SGE_Login, Resource);
protected:
	String gamename_ = "";
	String pfid_ = "";
	String pfname_ = "";
	String accountid_ = "";
	uint32_t roleId_ = 0;
	uint64_t logintime_ = 0;
	uint64_t logouttime_ = 0;
	uint64_t firsttime_ = 0;
	uint64_t rolefirsttime_ = 0;
	uint32_t firstserid_ = 0;
	uint32_t serverid_ = 0;
	String mac_ = "";
	String idfa_ = "";
	String ip_ = "";
	String devicetype_ = "";
public:
	void set_gamename_(String p_val) { gamename_ = p_val; }
	String get_gamename_() const { return gamename_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_pfname_(String p_val) { pfname_ = p_val; }
	String get_pfname_() const { return pfname_; }
	void set_accountid_(String p_val) { accountid_ = p_val; }
	String get_accountid_() const { return accountid_; }
	void set_roleId_(uint32_t p_val) { roleId_ = p_val; }
	uint32_t get_roleId_() const { return roleId_; }
	void set_logintime_(uint64_t p_val) { logintime_ = p_val; }
	uint64_t get_logintime_() const { return logintime_; }
	void set_logouttime_(uint64_t p_val) { logouttime_ = p_val; }
	uint64_t get_logouttime_() const { return logouttime_; }
	void set_firsttime_(uint64_t p_val) { firsttime_ = p_val; }
	uint64_t get_firsttime_() const { return firsttime_; }
	void set_rolefirsttime_(uint64_t p_val) { rolefirsttime_ = p_val; }
	uint64_t get_rolefirsttime_() const { return rolefirsttime_; }
	void set_firstserid_(uint32_t p_val) { firstserid_ = p_val; }
	uint32_t get_firstserid_() const { return firstserid_; }
	void set_serverid_(uint32_t p_val) { serverid_ = p_val; }
	uint32_t get_serverid_() const { return serverid_; }
	void set_mac_(String p_val) { mac_ = p_val; }
	String get_mac_() const { return mac_; }
	void set_idfa_(String p_val) { idfa_ = p_val; }
	String get_idfa_() const { return idfa_; }
	void set_ip_(String p_val) { ip_ = p_val; }
	String get_ip_() const { return ip_; }
	void set_devicetype_(String p_val) { devicetype_ = p_val; }
	String get_devicetype_() const { return devicetype_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_Order
class SGE_Order : public Resource {
	GDCLASS(SGE_Order, Resource);
protected:
	String gamename_ = "";
	String pfid_ = "";
	String pfname_ = "";
	String orderid_ = "";
	uint32_t roleId_ = 0;
	uint32_t rolelv_ = 0;
	String accountid_ = "";
	float payment_ = 0.0;
	String paytime_ = "";
public:
	void set_gamename_(String p_val) { gamename_ = p_val; }
	String get_gamename_() const { return gamename_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_pfname_(String p_val) { pfname_ = p_val; }
	String get_pfname_() const { return pfname_; }
	void set_orderid_(String p_val) { orderid_ = p_val; }
	String get_orderid_() const { return orderid_; }
	void set_roleId_(uint32_t p_val) { roleId_ = p_val; }
	uint32_t get_roleId_() const { return roleId_; }
	void set_rolelv_(uint32_t p_val) { rolelv_ = p_val; }
	uint32_t get_rolelv_() const { return rolelv_; }
	void set_accountid_(String p_val) { accountid_ = p_val; }
	String get_accountid_() const { return accountid_; }
	void set_payment_(float p_val) { payment_ = p_val; }
	float get_payment_() const { return payment_; }
	void set_paytime_(String p_val) { paytime_ = p_val; }
	String get_paytime_() const { return paytime_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_LogUIBehavior
class SGE_LogUIBehavior : public Resource {
	GDCLASS(SGE_LogUIBehavior, Resource);
protected:
	uint32_t accountGuid_ = 0;
	String accountName_ = "";
	uint32_t playerGuid_ = 0;
	String playerName_ = "";
	String clientIp_ = "";
	uint16_t type_ = (UIBehaviorType)0;
public:
	void set_accountGuid_(uint32_t p_val) { accountGuid_ = p_val; }
	uint32_t get_accountGuid_() const { return accountGuid_; }
	void set_accountName_(String p_val) { accountName_ = p_val; }
	String get_accountName_() const { return accountName_; }
	void set_playerGuid_(uint32_t p_val) { playerGuid_ = p_val; }
	uint32_t get_playerGuid_() const { return playerGuid_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_clientIp_(String p_val) { clientIp_ = p_val; }
	String get_clientIp_() const { return clientIp_; }
	void set_type_(uint16_t p_val) { type_ = p_val; }
	uint16_t get_type_() const { return type_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_LogRole
class SGE_LogRole : public Resource {
	GDCLASS(SGE_LogRole, Resource);
protected:
	String gamename_ = "";
	String pfid_ = "";
	String pfname_ = "";
	uint32_t roleid_ = 0;
	uint64_t cachetime_ = 0;
	String accountid_ = "";
	int8_t serverid_ = 0;
	String servername_ = "";
	int8_t firstserid_ = 0;
	uint64_t rolefirsttime_ = 0;
	uint64_t rolelasttime_ = 0;
	int8_t rolelv_ = 0;
	int64_t gold_ = 0;
	int64_t diamond_ = 0;
	int64_t magicgold_ = 0;
	int8_t vip_ = 0;
	int64_t ce_ = 0;
public:
	void set_gamename_(String p_val) { gamename_ = p_val; }
	String get_gamename_() const { return gamename_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_pfname_(String p_val) { pfname_ = p_val; }
	String get_pfname_() const { return pfname_; }
	void set_roleid_(uint32_t p_val) { roleid_ = p_val; }
	uint32_t get_roleid_() const { return roleid_; }
	void set_cachetime_(uint64_t p_val) { cachetime_ = p_val; }
	uint64_t get_cachetime_() const { return cachetime_; }
	void set_accountid_(String p_val) { accountid_ = p_val; }
	String get_accountid_() const { return accountid_; }
	void set_serverid_(int8_t p_val) { serverid_ = p_val; }
	int8_t get_serverid_() const { return serverid_; }
	void set_servername_(String p_val) { servername_ = p_val; }
	String get_servername_() const { return servername_; }
	void set_firstserid_(int8_t p_val) { firstserid_ = p_val; }
	int8_t get_firstserid_() const { return firstserid_; }
	void set_rolefirsttime_(uint64_t p_val) { rolefirsttime_ = p_val; }
	uint64_t get_rolefirsttime_() const { return rolefirsttime_; }
	void set_rolelasttime_(uint64_t p_val) { rolelasttime_ = p_val; }
	uint64_t get_rolelasttime_() const { return rolelasttime_; }
	void set_rolelv_(int8_t p_val) { rolelv_ = p_val; }
	int8_t get_rolelv_() const { return rolelv_; }
	void set_gold_(int64_t p_val) { gold_ = p_val; }
	int64_t get_gold_() const { return gold_; }
	void set_diamond_(int64_t p_val) { diamond_ = p_val; }
	int64_t get_diamond_() const { return diamond_; }
	void set_magicgold_(int64_t p_val) { magicgold_ = p_val; }
	int64_t get_magicgold_() const { return magicgold_; }
	void set_vip_(int8_t p_val) { vip_ = p_val; }
	int8_t get_vip_() const { return vip_; }
	void set_ce_(int64_t p_val) { ce_ = p_val; }
	int64_t get_ce_() const { return ce_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_LogProduceTrack
class SGE_LogProduceTrack : public Resource {
	GDCLASS(SGE_LogProduceTrack, Resource);
protected:
	uint64_t timestamp_ = 0;
	int32_t from_ = 0;
	uint32_t playerId_ = 0;
	String playerName_ = "";
	uint32_t itemId_ = 0;
	uint32_t itemInstId_ = 0;
	int32_t itemStack_ = 0;
	int32_t diamond_ = 0;
	int32_t money_ = 0;
	int32_t exp_ = 0;
	int32_t magic_ = 0;
public:
	void set_timestamp_(uint64_t p_val) { timestamp_ = p_val; }
	uint64_t get_timestamp_() const { return timestamp_; }
	void set_from_(int32_t p_val) { from_ = p_val; }
	int32_t get_from_() const { return from_; }
	void set_playerId_(uint32_t p_val) { playerId_ = p_val; }
	uint32_t get_playerId_() const { return playerId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_itemId_(uint32_t p_val) { itemId_ = p_val; }
	uint32_t get_itemId_() const { return itemId_; }
	void set_itemInstId_(uint32_t p_val) { itemInstId_ = p_val; }
	uint32_t get_itemInstId_() const { return itemInstId_; }
	void set_itemStack_(int32_t p_val) { itemStack_ = p_val; }
	int32_t get_itemStack_() const { return itemStack_; }
	void set_diamond_(int32_t p_val) { diamond_ = p_val; }
	int32_t get_diamond_() const { return diamond_; }
	void set_money_(int32_t p_val) { money_ = p_val; }
	int32_t get_money_() const { return money_; }
	void set_exp_(int32_t p_val) { exp_ = p_val; }
	int32_t get_exp_() const { return exp_; }
	void set_magic_(int32_t p_val) { magic_ = p_val; }
	int32_t get_magic_() const { return magic_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Exam
class COM_Exam : public Resource {
	GDCLASS(COM_Exam, Resource);
protected:
	uint8_t questionIndex_ = 0;
	uint8_t rightNum_ = 0;
	uint8_t errorNum_ = 0;
	uint32_t money_ = 0;
	uint32_t exp_ = 0;
	TypedArray<uint32_t> questions_ = {};
public:
	void set_questionIndex_(uint8_t p_val) { questionIndex_ = p_val; }
	uint8_t get_questionIndex_() const { return questionIndex_; }
	void set_rightNum_(uint8_t p_val) { rightNum_ = p_val; }
	uint8_t get_rightNum_() const { return rightNum_; }
	void set_errorNum_(uint8_t p_val) { errorNum_ = p_val; }
	uint8_t get_errorNum_() const { return errorNum_; }
	void set_money_(uint32_t p_val) { money_ = p_val; }
	uint32_t get_money_() const { return money_; }
	void set_exp_(uint32_t p_val) { exp_ = p_val; }
	uint32_t get_exp_() const { return exp_; }
	void set_questions_(TypedArray<uint32_t> p_val) { questions_ = p_val; }
	TypedArray<uint32_t> get_questions_() const { return questions_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Answer
class COM_Answer : public Resource {
	GDCLASS(COM_Answer, Resource);
protected:
	uint8_t questionIndex_ = 0;
	uint32_t money_ = 0;
	uint32_t exp_ = 0;
	bool isRigth_ = false;
public:
	void set_questionIndex_(uint8_t p_val) { questionIndex_ = p_val; }
	uint8_t get_questionIndex_() const { return questionIndex_; }
	void set_money_(uint32_t p_val) { money_ = p_val; }
	uint32_t get_money_() const { return money_; }
	void set_exp_(uint32_t p_val) { exp_ = p_val; }
	uint32_t get_exp_() const { return exp_; }
	void set_isRigth_(bool p_val) { isRigth_ = p_val; }
	bool get_isRigth_() const { return isRigth_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Wishing
class COM_Wishing : public Resource {
	GDCLASS(COM_Wishing, Resource);
protected:
	uint16_t wt_ = (WishType)0;
	String wish_ = "";
public:
	void set_wt_(uint16_t p_val) { wt_ = p_val; }
	uint16_t get_wt_() const { return wt_; }
	void set_wish_(String p_val) { wish_ = p_val; }
	String get_wish_() const { return wish_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_Wish
class COM_Wish : public Resource {
	GDCLASS(COM_Wish, Resource);
protected:
	uint32_t playerInstId_ = 0;
	String playerName_ = "";
	String wish_ = "";
public:
	void set_playerInstId_(uint32_t p_val) { playerInstId_ = p_val; }
	uint32_t get_playerInstId_() const { return playerInstId_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_wish_(String p_val) { wish_ = p_val; }
	String get_wish_() const { return wish_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_GmtOrder
class SGE_GmtOrder : public Resource {
	GDCLASS(SGE_GmtOrder, Resource);
protected:
	int32_t shopId_ = 0;
	String orderId_ = "";
	float payment_ = 0.0;
public:
	void set_shopId_(int32_t p_val) { shopId_ = p_val; }
	int32_t get_shopId_() const { return shopId_; }
	void set_orderId_(String p_val) { orderId_ = p_val; }
	String get_orderId_() const { return orderId_; }
	void set_payment_(float p_val) { payment_ = p_val; }
	float get_payment_() const { return payment_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_KeyContent
class COM_KeyContent : public Resource {
	GDCLASS(COM_KeyContent, Resource);
protected:
	String giftname_ = "";
	String pfid_ = "";
	String key_ = "";
	String playerName_ = "";
	int64_t usetime_ = 0;
	TypedArray<COM_GiftItem> items_ = {};
public:
	void set_giftname_(String p_val) { giftname_ = p_val; }
	String get_giftname_() const { return giftname_; }
	void set_pfid_(String p_val) { pfid_ = p_val; }
	String get_pfid_() const { return pfid_; }
	void set_key_(String p_val) { key_ = p_val; }
	String get_key_() const { return key_; }
	void set_playerName_(String p_val) { playerName_ = p_val; }
	String get_playerName_() const { return playerName_; }
	void set_usetime_(int64_t p_val) { usetime_ = p_val; }
	int64_t get_usetime_() const { return usetime_; }
	void set_items_(TypedArray<COM_GiftItem> p_val) { items_ = p_val; }
	TypedArray<COM_GiftItem> get_items_() const { return items_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct COM_EmployeeQuestInst
class COM_EmployeeQuestInst : public Resource {
	GDCLASS(COM_EmployeeQuestInst, Resource);
protected:
	uint16_t status_ = (EmployeeQuestStatus)0;
	int32_t questId_ = 0;
	int32_t timeout_ = 0;
	TypedArray<int32_t> usedEmployees_ = {};
public:
	void set_status_(uint16_t p_val) { status_ = p_val; }
	uint16_t get_status_() const { return status_; }
	void set_questId_(int32_t p_val) { questId_ = p_val; }
	int32_t get_questId_() const { return questId_; }
	void set_timeout_(int32_t p_val) { timeout_ = p_val; }
	int32_t get_timeout_() const { return timeout_; }
	void set_usedEmployees_(TypedArray<int32_t> p_val) { usedEmployees_ = p_val; }
	TypedArray<int32_t> get_usedEmployees_() const { return usedEmployees_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_EmployeeQuestInst
class SGE_EmployeeQuestInst : public COM_EmployeeQuestInst {
	GDCLASS(SGE_EmployeeQuestInst, COM_EmployeeQuestInst);
protected:
	int64_t doTime_ = 0;
	int64_t refreshTime_ = 0;
public:
	void set_doTime_(int64_t p_val) { doTime_ = p_val; }
	int64_t get_doTime_() const { return doTime_; }
	void set_refreshTime_(int64_t p_val) { refreshTime_ = p_val; }
	int64_t get_refreshTime_() const { return refreshTime_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_PlayerEmployeeQuestArray
class SGE_PlayerEmployeeQuestArray : public Resource {
	GDCLASS(SGE_PlayerEmployeeQuestArray, Resource);
protected:
	TypedArray<SGE_EmployeeQuestInst> value_ = {};
public:
	void set_value_(TypedArray<SGE_EmployeeQuestInst> p_val) { value_ = p_val; }
	TypedArray<SGE_EmployeeQuestInst> get_value_() const { return value_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
// struct SGE_PlayerEmployeeQuest
class SGE_PlayerEmployeeQuest : public Resource {
	GDCLASS(SGE_PlayerEmployeeQuest, Resource);
protected:
	int32_t playerId_ = 0;
	TypedArray<int32_t> usedEmployees_ = {};
	TypedArray<SGE_PlayerEmployeeQuestArray> quests_ = {};
public:
	void set_playerId_(int32_t p_val) { playerId_ = p_val; }
	int32_t get_playerId_() const { return playerId_; }
	void set_usedEmployees_(TypedArray<int32_t> p_val) { usedEmployees_ = p_val; }
	TypedArray<int32_t> get_usedEmployees_() const { return usedEmployees_; }
	void set_quests_(TypedArray<SGE_PlayerEmployeeQuestArray> p_val) { quests_ = p_val; }
	TypedArray<SGE_PlayerEmployeeQuestArray> get_quests_() const { return quests_; }
	static void _bind_methods();
	
	void serialize(ProtocolWriter* s) const;
	bool deserialize(ProtocolReader* r);
};
class Client2Server_Proxy {
public:
	virtual ~Client2Server_Proxy() {}
	virtual void openvip(uint16_t vl) = 0;
	virtual void requestPhoto() = 0;
	virtual void ping() = 0;
	virtual void sessionlogin(Ref<COM_LoginInfo> info) = 0;
	virtual void login(Ref<COM_LoginInfo> info) = 0;
	virtual void createPlayer(String playername, uint8_t playerTmpId) = 0;
	virtual void deletePlayer(String playername) = 0;
	virtual void enterGame(uint32_t playerInstId) = 0;
	virtual void requestBag() = 0;
	virtual void requestEmployees() = 0;
	virtual void requestStorage(uint16_t tp) = 0;
	virtual void requestAchievement() = 0;
	virtual void initminig() = 0;
	virtual void requestCompound() = 0;
	virtual void move(float x, float z) = 0;
	virtual void moveToNpc(int32_t npcid) = 0;
	virtual void moveToNpc2(uint16_t type) = 0;
	virtual void moveToZone(int32_t sceneId, int32_t zoneId) = 0;
	virtual void autoBattle() = 0;
	virtual void stopAutoBattle() = 0;
	virtual void stopMove() = 0;
	virtual void exitCopy() = 0;
	virtual void transforScene(int32_t sceneId) = 0;
	virtual void sceneLoaded() = 0;
	virtual void querySimplePlayerInst(uint32_t instId) = 0;
	virtual void logout() = 0;
	virtual void changProp(uint32_t guid, TypedArray<COM_Addprop> props) = 0;
	virtual void learnSkill(uint32_t skid) = 0;
	virtual void babyLearnSkill(uint32_t instId, uint32_t oldSkId, uint32_t newSkId, uint32_t newSkLv) = 0;
	virtual void forgetSkill(uint32_t skid) = 0;
	virtual void syncOrder(Ref<COM_Order> order) = 0;
	virtual void syncOrderTimeout() = 0;
	virtual void sendChat(Ref<COM_Chat> content, String targetName) = 0;
	virtual void requestAudio(int32_t audioId) = 0;
	virtual void publishItemInst(uint16_t type, uint32_t itemInstId, uint16_t chatType, String playerName) = 0;
	virtual void queryItemInst(int32_t showId) = 0;
	virtual void publishbabyInst(uint16_t type, uint32_t babyInstId, String playerName) = 0;
	virtual void querybabyInst(int32_t showId) = 0;
	virtual void useItem(uint32_t slot, uint32_t target, uint32_t stack) = 0;
	virtual void wearEquipment(uint32_t target, uint32_t itemInstId) = 0;
	virtual void delEquipment(uint32_t target, uint32_t itemInstId) = 0;
	virtual void setPlayerFront(bool isFront) = 0;
	virtual void setBattlebaby(uint32_t babyID, bool isBattle) = 0;
	virtual void changeBabyName(uint32_t babyID, String name) = 0;
	virtual void intensifyBaby(uint32_t babyid) = 0;
	virtual void setBattleEmp(uint32_t empID, uint16_t group, bool isBattle) = 0;
	virtual void changeEmpBattleGroup(uint16_t group) = 0;
	virtual void requestEvolve(uint32_t empInstId) = 0;
	virtual void requestUpStar(uint32_t empInstId) = 0;
	virtual void requestDelEmp(uint32_t empInstId) = 0;
	virtual void delEmployee(TypedArray<uint32_t> emps) = 0;
	virtual void onekeyDelEmp() = 0;
	virtual void delEmployeeSoul(uint32_t instid, uint32_t soulNum) = 0;
	virtual void sortBagItem() = 0;
	virtual void sellBagItem(uint32_t instId, uint32_t stack) = 0;
	virtual void depositItemToStorage(uint32_t instid) = 0;
	virtual void depositBabyToStorage(uint32_t instid) = 0;
	virtual void storageItemToBag(uint32_t instid) = 0;
	virtual void storageBabyToPlayer(uint32_t instid) = 0;
	virtual void sortStorage(uint16_t tp) = 0;
	virtual void delStorageBaby(uint32_t instid) = 0;
	virtual void jointLobby() = 0;
	virtual void exitLobby() = 0;
	virtual void createTeam(Ref<COM_CreateTeamInfo> cti) = 0;
	virtual void changeTeam(Ref<COM_CreateTeamInfo> info) = 0;
	virtual void kickTeamMember(uint32_t uuid) = 0;
	virtual void changeTeamLeader(uint32_t uuid) = 0;
	virtual void joinTeam(uint32_t teamId, String pwd) = 0;
	virtual void exitTeam() = 0;
	virtual void changeTeamPassword(String pwd) = 0;
	virtual void joinTeamRoom() = 0;
	virtual void inviteTeamMember(String name) = 0;
	virtual void isjoinTeam(uint32_t teamId, bool isFlag) = 0;
	virtual void leaveTeam() = 0;
	virtual void backTeam() = 0;
	virtual void refuseBackTeam() = 0;
	virtual void teamCallMember(int32_t playerId) = 0;
	virtual void requestJoinTeam(String targetName) = 0;
	virtual void ratifyJoinTeam(String sendName) = 0;
	virtual void drawLotteryBox(uint16_t type, bool isFree) = 0;
	virtual void acceptQuest(int32_t questId) = 0;
	virtual void submitQuest(int32_t npcId, int32_t questId) = 0;
	virtual void giveupQuest(int32_t questId) = 0;
	virtual void requestContactInfoById(uint32_t instId) = 0;
	virtual void requestContactInfoByName(String instName) = 0;
	virtual void requestFriendList() = 0;
	virtual void addFriend(uint32_t instId) = 0;
	virtual void delFriend(uint32_t instId) = 0;
	virtual void addBlacklist(uint32_t instId) = 0;
	virtual void delBlacklist(uint32_t instId) = 0;
	virtual void requestReferrFriend() = 0;
	virtual void mining(int32_t gatherId, int32_t times) = 0;
	virtual void compoundItem(int32_t itemId, int32_t gemId) = 0;
	virtual void bagItemSplit(int32_t instId, int32_t splitNum) = 0;
	virtual void requestChallenge(String name) = 0;
	virtual void requestRival() = 0;
	virtual void requestMySelfJJCData() = 0;
	virtual void requestCheckMsg(String name) = 0;
	virtual void requestMyAllbattleMsg() = 0;
	virtual void requestJJCRank() = 0;
	virtual void requestLevelRank() = 0;
	virtual void requestBabyRank() = 0;
	virtual void requestEmpRank() = 0;
	virtual void requestPlayerFFRank() = 0;
	virtual void queryOnlinePlayerbyName(String name) = 0;
	virtual void queryPlayerbyName(String name) = 0;
	virtual void queryBaby(uint32_t instId) = 0;
	virtual void queryEmployee(uint32_t instId) = 0;
	virtual void guideFinish(uint64_t guideIdx) = 0;
	virtual void enterBattle(int32_t battleId) = 0;
	virtual void shopBuyItem(int32_t id, int32_t num) = 0;
	virtual void getFirstRechargeItem() = 0;
	virtual void requestLevelGift(int32_t level) = 0;
	virtual void setCurrentTitle(int32_t title) = 0;
	virtual void openBuyBox() = 0;
	virtual void requestAchaward(int32_t achId) = 0;
	virtual void sign(int32_t index) = 0;
	virtual void requestSignupReward7() = 0;
	virtual void requestSignupReward14() = 0;
	virtual void requestSignupReward28() = 0;
	virtual void requestActivityReward(int32_t index) = 0;
	virtual void resetHundredTier() = 0;
	virtual void enterHundredScene(int32_t level) = 0;
	virtual void delBaby(int32_t instId) = 0;
	virtual void resetBaby(int32_t instId) = 0;
	virtual void resetBabyProp(int32_t instId) = 0;
	virtual void remouldBaby(int32_t instid) = 0;
	virtual void empSkillLevelUp(uint32_t empId, int32_t skillId) = 0;
	virtual void setOpenDoubleTimeFlag(bool isFlag) = 0;
	virtual void talkedNpc(int32_t npcId) = 0;
	virtual void jjcBattleGo(uint32_t id) = 0;
	virtual void requestMyJJCTeamMsg() = 0;
	virtual void startMatching() = 0;
	virtual void stopMatching() = 0;
	virtual void exitPvpJJC() = 0;
	virtual void joinPvpLobby() = 0;
	virtual void exitPvpLobby() = 0;
	virtual void requestpvprank() = 0;
	virtual void joinWarriorchoose() = 0;
	virtual void warriorStart() = 0;
	virtual void warriorStop() = 0;
	virtual void sendMail(String playername, String title, String content) = 0;
	virtual void readMail(int32_t mailId) = 0;
	virtual void delMail(int32_t mailId) = 0;
	virtual void getMailItem(int32_t mailId) = 0;
	virtual void requestState() = 0;
	virtual void createGuild(String guildName) = 0;
	virtual void delGuild(uint32_t guildId) = 0;
	virtual void requestJoinGuild(uint32_t guid) = 0;
	virtual void leaveGuild() = 0;
	virtual void kickOut(int32_t guid) = 0;
	virtual void acceptRequestGuild(int32_t playerId) = 0;
	virtual void refuseRequestGuild(int32_t playerId) = 0;
	virtual void changeMemberPosition(int32_t targetId, uint16_t job) = 0;
	virtual void transferPremier(int32_t targetId) = 0;
	virtual void changeGuildNotice(String notice) = 0;
	virtual void queryGuildList(int16_t page) = 0;
	virtual void inviteJoinGuild(String playerName) = 0;
	virtual void respondInviteJoinGuild(String sendName) = 0;
	virtual void buyGuildItem(int32_t tableId, int32_t times) = 0;
	virtual void entryGuildBattle() = 0;
	virtual void transforGuildBattleScene() = 0;
	virtual void addGuildMoney(int32_t money) = 0;
	virtual void updateGuildBuiling(uint16_t gbt) = 0;
	virtual void refreshGuildShop() = 0;
	virtual void levelupGuildSkill(int32_t skId) = 0;
	virtual void presentGuildItem(int32_t num) = 0;
	virtual void progenitusAddExp(int32_t monsterId, bool isSuper) = 0;
	virtual void setProgenitusPosition(int32_t mId, int32_t pos) = 0;
	virtual void guildsign() = 0;
	virtual void fetchSelling(Ref<COM_SearchContext> context) = 0;
	virtual void fetchSelling2(Ref<COM_SearchContext> context) = 0;
	virtual void selling(int32_t iteminstid, int32_t babyinstid, int32_t price) = 0;
	virtual void unselling(int32_t sellid) = 0;
	virtual void buy(int32_t sellid) = 0;
	virtual void fixItem(int32_t instId, uint16_t type) = 0;
	virtual void fixAllItem(TypedArray<uint32_t> items, uint16_t type) = 0;
	virtual void makeDebirsItem(int32_t instId, int32_t num) = 0;
	virtual void levelUpMagicItem(TypedArray<uint32_t> items) = 0;
	virtual void tupoMagicItem(int32_t level) = 0;
	virtual void changeMagicJob(uint16_t job) = 0;
	virtual void requestPk(uint32_t playerId) = 0;
	virtual void uiBehavior(uint16_t type) = 0;
	virtual void openZhuanpan() = 0;
	virtual void zhuanpanGo(uint32_t counter) = 0;
	virtual void redemptionSpree(String code) = 0;
	virtual void sceneFilter(TypedArray<uint16_t> sfType) = 0;
	virtual void sendExamAnswer(uint32_t questionId, uint8_t answer) = 0;
	virtual void sendwishing(Ref<COM_Wishing> wish) = 0;
	virtual void requestWish() = 0;
	virtual void leaderCloseDialog() = 0;
	virtual void requestOnlineReward(uint32_t index) = 0;
	virtual void requestFundReward(uint32_t level) = 0;
	virtual void openCard(uint16_t index) = 0;
	virtual void resetCard() = 0;
	virtual void hotRoleBuy() = 0;
	virtual void requestSevenReward(uint32_t qid) = 0;
	virtual void vipreward() = 0;
	virtual void requestChargeTotalSingleReward(uint32_t index) = 0;
	virtual void requestChargeTotalReward(uint32_t index) = 0;
	virtual void requestChargeEverySingleReward(uint32_t index) = 0;
	virtual void requestChargeEveryReward(uint32_t index) = 0;
	virtual void requestLoginTotal(uint32_t index) = 0;
	virtual void buyDiscountStoreSingle(int32_t itemId, int32_t itemStack) = 0;
	virtual void buyDiscountStore(int32_t itemId, int32_t itemStack) = 0;
	virtual void requestEmployeeActivityReward(uint32_t index) = 0;
	virtual void requestmyselfrechargeleReward(uint32_t index) = 0;
	virtual void requestEverydayIntegral() = 0;
	virtual void buyIntegralItem(uint32_t id, uint32_t num) = 0;
	virtual void familyLoseLeader() = 0;
	virtual void verificationSMS(String phoneNumber, String code) = 0;
	virtual void lockItem(int32_t instId, bool isLock) = 0;
	virtual void lockBaby(int32_t instId, bool isLock) = 0;
	virtual void showBaby(int32_t instId) = 0;
	virtual void wearFuwen(int32_t itemInstId) = 0;
	virtual void takeoffFuwen(int32_t slotId) = 0;
	virtual void compFuwen(int32_t itemInstId) = 0;
	virtual void requestEmployeeQuest() = 0;
	virtual void acceptEmployeeQuest(int32_t questId, TypedArray<int32_t> employees) = 0;
	virtual void submitEmployeeQuest(int32_t questId) = 0;
	virtual void crystalUpLevel() = 0;
	virtual void resetCrystalProp(TypedArray<int32_t> locklist) = 0;
	virtual void magicItemOneKeyLevel() = 0;
	virtual void submitQuest2(int32_t npcId, int32_t questId, int32_t instId) = 0;
};

class Client2Server_Stub {
public:
	virtual ~Client2Server_Stub() {}
	void openvip(uint16_t vl);
	void requestPhoto();
	void ping();
	void sessionlogin(Ref<COM_LoginInfo> info);
	void login(Ref<COM_LoginInfo> info);
	void createPlayer(String playername, uint8_t playerTmpId);
	void deletePlayer(String playername);
	void enterGame(uint32_t playerInstId);
	void requestBag();
	void requestEmployees();
	void requestStorage(uint16_t tp);
	void requestAchievement();
	void initminig();
	void requestCompound();
	void move(float x, float z);
	void moveToNpc(int32_t npcid);
	void moveToNpc2(uint16_t type);
	void moveToZone(int32_t sceneId, int32_t zoneId);
	void autoBattle();
	void stopAutoBattle();
	void stopMove();
	void exitCopy();
	void transforScene(int32_t sceneId);
	void sceneLoaded();
	void querySimplePlayerInst(uint32_t instId);
	void logout();
	void changProp(uint32_t guid, TypedArray<COM_Addprop> props);
	void learnSkill(uint32_t skid);
	void babyLearnSkill(uint32_t instId, uint32_t oldSkId, uint32_t newSkId, uint32_t newSkLv);
	void forgetSkill(uint32_t skid);
	void syncOrder(Ref<COM_Order> order);
	void syncOrderTimeout();
	void sendChat(Ref<COM_Chat> content, String targetName);
	void requestAudio(int32_t audioId);
	void publishItemInst(uint16_t type, uint32_t itemInstId, uint16_t chatType, String playerName);
	void queryItemInst(int32_t showId);
	void publishbabyInst(uint16_t type, uint32_t babyInstId, String playerName);
	void querybabyInst(int32_t showId);
	void useItem(uint32_t slot, uint32_t target, uint32_t stack);
	void wearEquipment(uint32_t target, uint32_t itemInstId);
	void delEquipment(uint32_t target, uint32_t itemInstId);
	void setPlayerFront(bool isFront);
	void setBattlebaby(uint32_t babyID, bool isBattle);
	void changeBabyName(uint32_t babyID, String name);
	void intensifyBaby(uint32_t babyid);
	void setBattleEmp(uint32_t empID, uint16_t group, bool isBattle);
	void changeEmpBattleGroup(uint16_t group);
	void requestEvolve(uint32_t empInstId);
	void requestUpStar(uint32_t empInstId);
	void requestDelEmp(uint32_t empInstId);
	void delEmployee(TypedArray<uint32_t> emps);
	void onekeyDelEmp();
	void delEmployeeSoul(uint32_t instid, uint32_t soulNum);
	void sortBagItem();
	void sellBagItem(uint32_t instId, uint32_t stack);
	void depositItemToStorage(uint32_t instid);
	void depositBabyToStorage(uint32_t instid);
	void storageItemToBag(uint32_t instid);
	void storageBabyToPlayer(uint32_t instid);
	void sortStorage(uint16_t tp);
	void delStorageBaby(uint32_t instid);
	void jointLobby();
	void exitLobby();
	void createTeam(Ref<COM_CreateTeamInfo> cti);
	void changeTeam(Ref<COM_CreateTeamInfo> info);
	void kickTeamMember(uint32_t uuid);
	void changeTeamLeader(uint32_t uuid);
	void joinTeam(uint32_t teamId, String pwd);
	void exitTeam();
	void changeTeamPassword(String pwd);
	void joinTeamRoom();
	void inviteTeamMember(String name);
	void isjoinTeam(uint32_t teamId, bool isFlag);
	void leaveTeam();
	void backTeam();
	void refuseBackTeam();
	void teamCallMember(int32_t playerId);
	void requestJoinTeam(String targetName);
	void ratifyJoinTeam(String sendName);
	void drawLotteryBox(uint16_t type, bool isFree);
	void acceptQuest(int32_t questId);
	void submitQuest(int32_t npcId, int32_t questId);
	void giveupQuest(int32_t questId);
	void requestContactInfoById(uint32_t instId);
	void requestContactInfoByName(String instName);
	void requestFriendList();
	void addFriend(uint32_t instId);
	void delFriend(uint32_t instId);
	void addBlacklist(uint32_t instId);
	void delBlacklist(uint32_t instId);
	void requestReferrFriend();
	void mining(int32_t gatherId, int32_t times);
	void compoundItem(int32_t itemId, int32_t gemId);
	void bagItemSplit(int32_t instId, int32_t splitNum);
	void requestChallenge(String name);
	void requestRival();
	void requestMySelfJJCData();
	void requestCheckMsg(String name);
	void requestMyAllbattleMsg();
	void requestJJCRank();
	void requestLevelRank();
	void requestBabyRank();
	void requestEmpRank();
	void requestPlayerFFRank();
	void queryOnlinePlayerbyName(String name);
	void queryPlayerbyName(String name);
	void queryBaby(uint32_t instId);
	void queryEmployee(uint32_t instId);
	void guideFinish(uint64_t guideIdx);
	void enterBattle(int32_t battleId);
	void shopBuyItem(int32_t id, int32_t num);
	void getFirstRechargeItem();
	void requestLevelGift(int32_t level);
	void setCurrentTitle(int32_t title);
	void openBuyBox();
	void requestAchaward(int32_t achId);
	void sign(int32_t index);
	void requestSignupReward7();
	void requestSignupReward14();
	void requestSignupReward28();
	void requestActivityReward(int32_t index);
	void resetHundredTier();
	void enterHundredScene(int32_t level);
	void delBaby(int32_t instId);
	void resetBaby(int32_t instId);
	void resetBabyProp(int32_t instId);
	void remouldBaby(int32_t instid);
	void empSkillLevelUp(uint32_t empId, int32_t skillId);
	void setOpenDoubleTimeFlag(bool isFlag);
	void talkedNpc(int32_t npcId);
	void jjcBattleGo(uint32_t id);
	void requestMyJJCTeamMsg();
	void startMatching();
	void stopMatching();
	void exitPvpJJC();
	void joinPvpLobby();
	void exitPvpLobby();
	void requestpvprank();
	void joinWarriorchoose();
	void warriorStart();
	void warriorStop();
	void sendMail(String playername, String title, String content);
	void readMail(int32_t mailId);
	void delMail(int32_t mailId);
	void getMailItem(int32_t mailId);
	void requestState();
	void createGuild(String guildName);
	void delGuild(uint32_t guildId);
	void requestJoinGuild(uint32_t guid);
	void leaveGuild();
	void kickOut(int32_t guid);
	void acceptRequestGuild(int32_t playerId);
	void refuseRequestGuild(int32_t playerId);
	void changeMemberPosition(int32_t targetId, uint16_t job);
	void transferPremier(int32_t targetId);
	void changeGuildNotice(String notice);
	void queryGuildList(int16_t page);
	void inviteJoinGuild(String playerName);
	void respondInviteJoinGuild(String sendName);
	void buyGuildItem(int32_t tableId, int32_t times);
	void entryGuildBattle();
	void transforGuildBattleScene();
	void addGuildMoney(int32_t money);
	void updateGuildBuiling(uint16_t gbt);
	void refreshGuildShop();
	void levelupGuildSkill(int32_t skId);
	void presentGuildItem(int32_t num);
	void progenitusAddExp(int32_t monsterId, bool isSuper);
	void setProgenitusPosition(int32_t mId, int32_t pos);
	void guildsign();
	void fetchSelling(Ref<COM_SearchContext> context);
	void fetchSelling2(Ref<COM_SearchContext> context);
	void selling(int32_t iteminstid, int32_t babyinstid, int32_t price);
	void unselling(int32_t sellid);
	void buy(int32_t sellid);
	void fixItem(int32_t instId, uint16_t type);
	void fixAllItem(TypedArray<uint32_t> items, uint16_t type);
	void makeDebirsItem(int32_t instId, int32_t num);
	void levelUpMagicItem(TypedArray<uint32_t> items);
	void tupoMagicItem(int32_t level);
	void changeMagicJob(uint16_t job);
	void requestPk(uint32_t playerId);
	void uiBehavior(uint16_t type);
	void openZhuanpan();
	void zhuanpanGo(uint32_t counter);
	void redemptionSpree(String code);
	void sceneFilter(TypedArray<uint16_t> sfType);
	void sendExamAnswer(uint32_t questionId, uint8_t answer);
	void sendwishing(Ref<COM_Wishing> wish);
	void requestWish();
	void leaderCloseDialog();
	void requestOnlineReward(uint32_t index);
	void requestFundReward(uint32_t level);
	void openCard(uint16_t index);
	void resetCard();
	void hotRoleBuy();
	void requestSevenReward(uint32_t qid);
	void vipreward();
	void requestChargeTotalSingleReward(uint32_t index);
	void requestChargeTotalReward(uint32_t index);
	void requestChargeEverySingleReward(uint32_t index);
	void requestChargeEveryReward(uint32_t index);
	void requestLoginTotal(uint32_t index);
	void buyDiscountStoreSingle(int32_t itemId, int32_t itemStack);
	void buyDiscountStore(int32_t itemId, int32_t itemStack);
	void requestEmployeeActivityReward(uint32_t index);
	void requestmyselfrechargeleReward(uint32_t index);
	void requestEverydayIntegral();
	void buyIntegralItem(uint32_t id, uint32_t num);
	void familyLoseLeader();
	void verificationSMS(String phoneNumber, String code);
	void lockItem(int32_t instId, bool isLock);
	void lockBaby(int32_t instId, bool isLock);
	void showBaby(int32_t instId);
	void wearFuwen(int32_t itemInstId);
	void takeoffFuwen(int32_t slotId);
	void compFuwen(int32_t itemInstId);
	void requestEmployeeQuest();
	void acceptEmployeeQuest(int32_t questId, TypedArray<int32_t> employees);
	void submitEmployeeQuest(int32_t questId);
	void crystalUpLevel();
	void resetCrystalProp(TypedArray<int32_t> locklist);
	void magicItemOneKeyLevel();
	void submitQuest2(int32_t npcId, int32_t questId, int32_t instId);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class Client2Server_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, Client2Server_Proxy* proxy);
};
class Server2Client_Proxy {
public:
	virtual bool dispatch(ProtocolReader *r) = 0; 
	virtual ~Server2Client_Proxy() {}
	virtual void pong() = 0;
	virtual void errorno(uint16_t e) = 0;
	virtual void teamerrorno(String name, uint16_t e) = 0;
	virtual void reconnection(Ref<COM_ReconnectInfo> recInfo) = 0;
	virtual void sessionfailed() = 0;
	virtual void loginok(String sessionkey, TypedArray<COM_SimpleInformation> players) = 0;
	virtual void logoutOk() = 0;
	virtual void createPlayerOk(Ref<COM_SimpleInformation> player) = 0;
	virtual void deletePlayerOk(String name) = 0;
	virtual void enterGameOk(Ref<COM_PlayerInst> inst) = 0;
	virtual void initBabies(TypedArray<COM_BabyInst> insts) = 0;
	virtual void initEmployees(TypedArray<COM_EmployeeInst> insts, bool isFlag) = 0;
	virtual void initEmpBattleGroup(Ref<COM_BattleEmp> bep) = 0;
	virtual void initNpc(TypedArray<int32_t> npcList) = 0;
	virtual void initAchievement(TypedArray<COM_Achievement> actlist) = 0;
	virtual void initGather(uint32_t allnum, TypedArray<COM_Gather> gathers) = 0;
	virtual void initcompound(TypedArray<uint32_t> compounds) = 0;
	virtual void addBaby(Ref<COM_BabyInst> inst) = 0;
	virtual void refreshBaby(Ref<COM_BabyInst> inst) = 0;
	virtual void delBabyOK(uint32_t babyInstId) = 0;
	virtual void changeBabyNameOK(uint32_t babyId, String name) = 0;
	virtual void remouldBabyOK(uint32_t instid) = 0;
	virtual void intensifyBabyOK(uint32_t babyid, uint32_t intensifyLevel) = 0;
	virtual void learnSkillOk(Ref<COM_Skill> inst) = 0;
	virtual void forgetSkillOk(uint32_t skid) = 0;
	virtual void addSkillExp(uint32_t skid, uint32_t uExp, uint16_t flag) = 0;
	virtual void babyLearnSkillOK(uint32_t instId, uint32_t newSkId) = 0;
	virtual void skillLevelUp(uint32_t instId, Ref<COM_Skill> inst) = 0;
	virtual void joinScene(Ref<COM_SceneInfo> info) = 0;
	virtual void joinCopySceneOK(int32_t secneid) = 0;
	virtual void initCopyNums() = 0;
	virtual void addToScene(Ref<COM_ScenePlayerInformation> inst) = 0;
	virtual void delFormScene(int32_t instId) = 0;
	virtual void move2(int32_t instId, Ref<COM_FPosition> pos) = 0;
	virtual void cantMove() = 0;
	virtual void querySimplePlayerInstOk(Ref<COM_SimplePlayerInst> player) = 0;
	virtual void transfor2(int32_t instId, Ref<COM_FPosition> pos) = 0;
	virtual void openScene(int32_t sceneId) = 0;
	virtual void autoBattleResult(bool isOk) = 0;
	virtual void talked2Npc(int32_t npcId) = 0;
	virtual void talked2Player(int32_t playerId) = 0;
	virtual void useItemOk(int32_t itemId, int32_t stack) = 0;
	virtual void syncBattleStatus(int32_t playerId, bool inBattle) = 0;
	virtual void enterBattleOk(Ref<COM_InitBattle> initBattle) = 0;
	virtual void exitBattleOk(uint16_t bjt, Ref<COM_BattleOverClearing> init) = 0;
	virtual void syncOrderOk(uint32_t uid) = 0;
	virtual void syncOrderOkEX() = 0;
	virtual void syncOneTurnAction(Ref<COM_BattleReport> reports) = 0;
	virtual void syncProperties(uint32_t guid, TypedArray<COM_PropValue> props) = 0;
	virtual void receiveChat(Ref<COM_ChatInfo> info, Ref<COM_ContactInfo> myinfo) = 0;
	virtual void requestAudioOk(int32_t audioId, TypedArray<uint8_t> content) = 0;
	virtual void publishItemInstRes(Ref<COM_ShowItemInstInfo> info, uint16_t type) = 0;
	virtual void queryItemInstRes(Ref<COM_ShowItemInst> item) = 0;
	virtual void publishBabyInstRes(Ref<COM_ShowbabyInstInfo> info, uint16_t type) = 0;
	virtual void queryBabyInstRes(Ref<COM_ShowbabyInst> inst) = 0;
	virtual void setNoTalkTime(float t) = 0;
	virtual void addNpc(TypedArray<int32_t> npcList) = 0;
	virtual void delNpc(TypedArray<int32_t> npcList) = 0;
	virtual void setTeamLeader(int32_t playerId, bool isLeader) = 0;
	virtual void initBag(TypedArray<COM_Item> items) = 0;
	virtual void addBagItem(Ref<COM_Item> item) = 0;
	virtual void delBagItem(uint16_t slot) = 0;
	virtual void updateBagItem(Ref<COM_Item> item) = 0;
	virtual void depositItemOK(Ref<COM_Item> item) = 0;
	virtual void getoutItemOK(uint16_t slot) = 0;
	virtual void depositBabyOK(Ref<COM_BabyInst> baby) = 0;
	virtual void getoutBabyOK(uint16_t slot) = 0;
	virtual void sortItemStorageOK(TypedArray<COM_Item> items) = 0;
	virtual void sortBabyStorageOK(TypedArray<uint32_t> babys) = 0;
	virtual void initItemStorage(uint16_t gridNum, TypedArray<COM_Item> items) = 0;
	virtual void initBabyStorage(uint16_t gridNum, TypedArray<COM_BabyInst> babys) = 0;
	virtual void openStorageGrid(uint16_t tp, uint16_t gridNum) = 0;
	virtual void delStorageBabyOK(uint16_t slot) = 0;
	virtual void initPlayerEquips(TypedArray<COM_Item> equips) = 0;
	virtual void wearEquipmentOk(uint32_t target, Ref<COM_Item> equip) = 0;
	virtual void scenePlayerWearEquipment(uint32_t target, uint32_t itemId) = 0;
	virtual void delEquipmentOk(uint32_t target, uint32_t itemInstId) = 0;
	virtual void scenePlayerDoffEquipment(uint32_t target, uint32_t itemId) = 0;
	virtual void sortBagItemOk() = 0;
	virtual void jointLobbyOk(TypedArray<COM_SimpleTeamInfo> infos) = 0;
	virtual void exitLobbyOk() = 0;
	virtual void syncDelLobbyTeam(uint32_t teamId) = 0;
	virtual void syncUpdateLobbyTeam(Ref<COM_SimpleTeamInfo> info) = 0;
	virtual void syncAddLobbyTeam(Ref<COM_SimpleTeamInfo> team) = 0;
	virtual void createTeamOk(Ref<COM_TeamInfo> team) = 0;
	virtual void changeTeamOk(Ref<COM_TeamInfo> team) = 0;
	virtual void joinTeamOk(Ref<COM_TeamInfo> team) = 0;
	virtual void addTeamMember(Ref<COM_SimplePlayerInst> info) = 0;
	virtual void delTeamMember(int32_t instId) = 0;
	virtual void changeTeamLeaderOk(int32_t uuid) = 0;
	virtual void exitTeamOk(bool iskick) = 0;
	virtual void updateTeam(Ref<COM_TeamInfo> team) = 0;
	virtual void joinTeamRoomOK(Ref<COM_TeamInfo> team) = 0;
	virtual void inviteJoinTeam(uint32_t teamId, String name) = 0;
	virtual void syncTeamDirtyProp(int32_t guid, TypedArray<COM_PropValue> props) = 0;
	virtual void leaveTeamOk(int32_t playerId) = 0;
	virtual void backTeamOK(int32_t playerId) = 0;
	virtual void teamCallMemberBack() = 0;
	virtual void refuseBackTeamOk(int32_t playerId) = 0;
	virtual void requestJoinTeamTranspond(String reqName) = 0;
	virtual void drawLotteryBoxRep(TypedArray<COM_Item> items) = 0;
	virtual void addEmployee(Ref<COM_EmployeeInst> employee) = 0;
	virtual void battleEmployee(int32_t empId, uint16_t group, bool forbattle) = 0;
	virtual void changeEmpBattleGroupOK(uint16_t group) = 0;
	virtual void evolveOK(int32_t guid, uint16_t qc) = 0;
	virtual void upStarOK(int32_t guid, int32_t star, Ref<COM_Skill> sk) = 0;
	virtual void delEmployeeOK(TypedArray<uint32_t> instids) = 0;
	virtual void sycnEmployeeSoul(int32_t guid, uint32_t soulNum) = 0;
	virtual void initQuest(TypedArray<COM_QuestInst> qlist, TypedArray<int32_t> clist) = 0;
	virtual void acceptQuestOk(Ref<COM_QuestInst> inst) = 0;
	virtual void submitQuestOk(int32_t questId) = 0;
	virtual void giveupQuestOk(int32_t questId) = 0;
	virtual void updateQuestInst(Ref<COM_QuestInst> inst) = 0;
	virtual void requestContactInfoOk(Ref<COM_ContactInfo> contact) = 0;
	virtual void addFriendOK(Ref<COM_ContactInfo> inst) = 0;
	virtual void delFriendOK(uint32_t instId) = 0;
	virtual void addBlacklistOK(Ref<COM_ContactInfo> inst) = 0;
	virtual void delBlacklistOK(uint32_t instId) = 0;
	virtual void findFriendFail() = 0;
	virtual void referrFriendOK(TypedArray<COM_ContactInfo> insts) = 0;
	virtual void requestFriendListOK(TypedArray<COM_ContactInfo> insts) = 0;
	virtual void lotteryOk(int32_t lotteryId, TypedArray<COM_DropItem> dropItem) = 0;
	virtual void openGatherOK(Ref<COM_Gather> gather) = 0;
	virtual void miningOk(TypedArray<COM_DropItem> items, Ref<COM_Gather> gather, uint32_t gatherNum) = 0;
	virtual void openCompound(uint32_t compoundId) = 0;
	virtual void compoundItemOk(Ref<COM_Item> item) = 0;
	virtual void openBagGridOk(int32_t num) = 0;
	virtual void requestChallengeOK(bool isOK) = 0;
	virtual void requestMySelfJJCDataOK(Ref<COM_EndlessStair> info) = 0;
	virtual void requestRivalOK(TypedArray<COM_EndlessStair> infos) = 0;
	virtual void rivalTimeOK() = 0;
	virtual void checkMsgOK(Ref<COM_SimplePlayerInst> inst) = 0;
	virtual void requestMyAllbattleMsgOK(TypedArray<COM_JJCBattleMsg> infos) = 0;
	virtual void myBattleMsgOK(Ref<COM_JJCBattleMsg> info) = 0;
	virtual void requestJJCRankOK(uint32_t myRank, TypedArray<COM_EndlessStair> infos) = 0;
	virtual void requestLevelRankOK(uint32_t myRank, TypedArray<COM_ContactInfo> infos) = 0;
	virtual void requestBabyRankOK(uint32_t myRank, TypedArray<COM_BabyRankData> infos) = 0;
	virtual void requestEmpRankOK(uint32_t myRank, TypedArray<COM_EmployeeRankData> infos) = 0;
	virtual void requestPlayerFFRankOK(uint32_t myRank, TypedArray<COM_ContactInfo> infos) = 0;
	virtual void queryOnlinePlayerOK(bool isOnline) = 0;
	virtual void queryPlayerOK(Ref<COM_SimplePlayerInst> inst) = 0;
	virtual void queryBabyOK(Ref<COM_BabyInst> inst) = 0;
	virtual void queryEmployeeOK(Ref<COM_EmployeeInst> inst) = 0;
	virtual void initGuide(uint32_t guideMask) = 0;
	virtual void buyShopItemOk(int32_t id) = 0;
	virtual void addPlayerTitle(int32_t title) = 0;
	virtual void delPlayerTitle(int32_t title) = 0;
	virtual void requestOpenBuyBox(float greenTime, float blueTime, int32_t greenFreeNum) = 0;
	virtual void requestGreenBoxTimeOk() = 0;
	virtual void requestBlueBoxTimeOk() = 0;
	virtual void updateAchievementinfo(Ref<COM_Achievement> achs) = 0;
	virtual void syncOpenSystemFlag(uint64_t flag) = 0;
	virtual void requestActivityRewardOK(uint32_t ar) = 0;
	virtual void syncActivity(Ref<COM_ActivityTable> table) = 0;
	virtual void updateActivityStatus(uint16_t type, bool open) = 0;
	virtual void updateActivityCounter(uint16_t type, int32_t counter, int32_t reward) = 0;
	virtual void syncExam(Ref<COM_Exam> exam) = 0;
	virtual void syncExamAnswer(Ref<COM_Answer> answer) = 0;
	virtual void petActivityNoNum(String name) = 0;
	virtual void syncHundredInfo(Ref<COM_HundredBattle> hb) = 0;
	virtual void initSignUp(TypedArray<int32_t> info, int32_t process, bool sign7, bool sign14, bool sign28) = 0;
	virtual void signUp(bool flag) = 0;
	virtual void requestSignupRewardOk7() = 0;
	virtual void requestSignupRewardOk14() = 0;
	virtual void requestSignupRewardOk28() = 0;
	virtual void sycnDoubleExpTime(bool isFlag, float times) = 0;
	virtual void sycnStates(TypedArray<COM_State> states) = 0;
	virtual void requestpvprankOK(TypedArray<COM_ContactInfo> infos) = 0;
	virtual void syncMyJJCTeamMember() = 0;
	virtual void startMatchingOK() = 0;
	virtual void stopMatchingOK(float times) = 0;
	virtual void updatePvpJJCinfo(Ref<COM_PlayerVsPlayer> info) = 0;
	virtual void exitPvpJJCOk() = 0;
	virtual void syncEnemyPvpJJCPlayerInfo(Ref<COM_SimpleInformation> info) = 0;
	virtual void syncEnemyPvpJJCTeamInfo(TypedArray<COM_SimpleInformation> infos, uint32_t teamID_) = 0;
	virtual void openWarriorchooseUI() = 0;
	virtual void warriorStartOK() = 0;
	virtual void warriorStopOK() = 0;
	virtual void syncWarriorEnemyTeamInfo(TypedArray<COM_SimpleInformation> infos, uint32_t teamID_) = 0;
	virtual void appendMail(TypedArray<COM_Mail> mails) = 0;
	virtual void delMail(int32_t mailId) = 0;
	virtual void updateMailOk(Ref<COM_Mail> mail) = 0;
	virtual void boardcastNotice(String content, bool isGm) = 0;
	virtual void createGuildOK() = 0;
	virtual void delGuildOK() = 0;
	virtual void leaveGuildOk(String who, bool isKick) = 0;
	virtual void initGuildData(Ref<COM_Guild> guild) = 0;
	virtual void initGuildMemberList(TypedArray<COM_GuildMember> member) = 0;
	virtual void modifyGuildMemberList(Ref<COM_GuildMember> member, uint16_t flag) = 0;
	virtual void modifyGuildList(Ref<COM_GuildViewerData> data, uint16_t flag) = 0;
	virtual void queryGuildListResult(int16_t page, int16_t pageNum, TypedArray<COM_GuildViewerData> guildList) = 0;
	virtual void inviteGuild(String sendName, String guildName) = 0;
	virtual void updateGuildShopItems(TypedArray<COM_GuildShopItem> items) = 0;
	virtual void updateGuildBuilding(uint16_t type, Ref<COM_GuildBuilding> building) = 0;
	virtual void updateGuildMyMember(Ref<COM_GuildMember> member) = 0;
	virtual void levelupGuildSkillOk(Ref<COM_Skill> skInst) = 0;
	virtual void presentGuildItemOk(int32_t val) = 0;
	virtual void progenitusAddExpOk(Ref<COM_GuildProgen> mInst) = 0;
	virtual void setProgenitusPositionOk(TypedArray<int32_t> positions) = 0;
	virtual void updateGuildFundz(int32_t val) = 0;
	virtual void updateGuildMemberContribution(int32_t val) = 0;
	virtual void openGuildBattle(String otherName, int32_t playerNum, int32_t level, bool isLeft, int32_t lstime) = 0;
	virtual void startGuildBattle(String otherName, int32_t otherCon, int32_t selfCon) = 0;
	virtual void closeGuildBattle(bool isWinner) = 0;
	virtual void syncGuildBattleWinCount(int32_t myWin, int32_t otherWin) = 0;
	virtual void initMySelling(TypedArray<COM_SellItem> items) = 0;
	virtual void initMySelled(TypedArray<COM_SelledItem> items) = 0;
	virtual void fetchSellingOk(TypedArray<COM_SellItem> items, int32_t total) = 0;
	virtual void fetchSellingOk2(TypedArray<COM_SellItem> items, int32_t total) = 0;
	virtual void sellingOk(Ref<COM_SellItem> item) = 0;
	virtual void selledOk(Ref<COM_SelledItem> item) = 0;
	virtual void unsellingOk(int32_t sellid) = 0;
	virtual void redemptionSpreeOk() = 0;
	virtual void insertState(Ref<COM_State> st) = 0;
	virtual void updattState(Ref<COM_State> st) = 0;
	virtual void removeState(uint32_t stid) = 0;
	virtual void requestFixItemOk(Ref<COM_Item> item) = 0;
	virtual void makeDebirsItemOK() = 0;
	virtual void updateMagicItem(int32_t level, int32_t exp) = 0;
	virtual void changeMagicJobOk(uint16_t job) = 0;
	virtual void magicItemTupoOk(int32_t level) = 0;
	virtual void zhuanpanOK(TypedArray<uint32_t> pond) = 0;
	virtual void updateZhuanpanNotice(Ref<COM_Zhuanpan> zhuanp) = 0;
	virtual void sycnZhuanpanData(Ref<COM_ZhuanpanData> data) = 0;
	virtual void copynonum(String name) = 0;
	virtual void sceneFilterOk(TypedArray<uint16_t> sfType) = 0;
	virtual void wishingOK() = 0;
	virtual void shareWishOK(Ref<COM_Wish> wish) = 0;
	virtual void leaderCloseDialogOk() = 0;
	virtual void startOnlineTime() = 0;
	virtual void requestOnlineTimeRewardOK(uint32_t index) = 0;
	virtual void sycnVipflag(bool flag) = 0;
	virtual void buyFundOK(bool flag) = 0;
	virtual void requestFundRewardOK(uint32_t level) = 0;
	virtual void firstRechargeOK(bool isFlag) = 0;
	virtual void firstRechargeGiftOK(bool isFlag) = 0;
	virtual void agencyActivity(uint16_t type, bool isFlag) = 0;
	virtual void updateFestival(Ref<COM_ADLoginTotal> festival) = 0;
	virtual void updateSelfRecharge(Ref<COM_ADChargeTotal> val) = 0;
	virtual void updateSysRecharge(Ref<COM_ADChargeTotal> val) = 0;
	virtual void updateSelfDiscountStore(Ref<COM_ADDiscountStore> val) = 0;
	virtual void updateSysDiscountStore(Ref<COM_ADDiscountStore> val) = 0;
	virtual void updateSelfOnceRecharge(Ref<COM_ADChargeEvery> val) = 0;
	virtual void updateSysOnceRecharge(Ref<COM_ADChargeEvery> val) = 0;
	virtual void openCardOK(Ref<COM_ADCardsContent> data) = 0;
	virtual void resetCardOK() = 0;
	virtual void sycnHotRole(Ref<COM_ADHotRole> data) = 0;
	virtual void hotRoleBuyOk(uint16_t buyNum) = 0;
	virtual void updateSevenday(Ref<COM_Sevenday> data) = 0;
	virtual void updateEmployeeActivity(Ref<COM_ADEmployeeTotal> data) = 0;
	virtual void updateMinGiftActivity(Ref<COM_ADGiftBag> data) = 0;
	virtual void updateIntegralShop(Ref<COM_IntegralData> data) = 0;
	virtual void updateShowBaby(uint32_t playerId, uint32_t showBabyTableId, String showBabyName) = 0;
	virtual void updateMySelfRecharge(Ref<COM_ADChargeTotal> val) = 0;
	virtual void verificationSMSOk(String phoneNumber) = 0;
	virtual void requestLevelGiftOK(int32_t level) = 0;
	virtual void sycnConvertExp(int32_t val) = 0;
	virtual void wearFuwenOk(Ref<COM_Item> inst) = 0;
	virtual void takeoffFuwenOk(int32_t slot) = 0;
	virtual void compFuwenOk() = 0;
	virtual void requestEmployeeQuestOk(TypedArray<COM_EmployeeQuestInst> questList) = 0;
	virtual void acceptEmployeeQuestOk(Ref<COM_EmployeeQuestInst> inst) = 0;
	virtual void submitEmployeeQuestOk(int32_t questId, bool isSuccess) = 0;
	virtual void sycnCrystal(Ref<COM_CrystalData> data) = 0;
	virtual void crystalUpLeveResult(bool isOK) = 0;
	virtual void resetCrystalPropOK() = 0;
	virtual void sycnCourseGift(TypedArray<COM_CourseGift> data) = 0;
	virtual void orderOk(String orderId, int32_t shopId) = 0;
	virtual void updateRandSubmitQuestCount(int32_t submitCount) = 0;
	virtual void updateTeamMember(int32_t playerId, bool isMember) = 0;
};

class Server2Client_Stub {
public:
	virtual ~Server2Client_Stub() {}
	void pong();
	void errorno(uint16_t e);
	void teamerrorno(String name, uint16_t e);
	void reconnection(Ref<COM_ReconnectInfo> recInfo);
	void sessionfailed();
	void loginok(String sessionkey, TypedArray<COM_SimpleInformation> players);
	void logoutOk();
	void createPlayerOk(Ref<COM_SimpleInformation> player);
	void deletePlayerOk(String name);
	void enterGameOk(Ref<COM_PlayerInst> inst);
	void initBabies(TypedArray<COM_BabyInst> insts);
	void initEmployees(TypedArray<COM_EmployeeInst> insts, bool isFlag);
	void initEmpBattleGroup(Ref<COM_BattleEmp> bep);
	void initNpc(TypedArray<int32_t> npcList);
	void initAchievement(TypedArray<COM_Achievement> actlist);
	void initGather(uint32_t allnum, TypedArray<COM_Gather> gathers);
	void initcompound(TypedArray<uint32_t> compounds);
	void addBaby(Ref<COM_BabyInst> inst);
	void refreshBaby(Ref<COM_BabyInst> inst);
	void delBabyOK(uint32_t babyInstId);
	void changeBabyNameOK(uint32_t babyId, String name);
	void remouldBabyOK(uint32_t instid);
	void intensifyBabyOK(uint32_t babyid, uint32_t intensifyLevel);
	void learnSkillOk(Ref<COM_Skill> inst);
	void forgetSkillOk(uint32_t skid);
	void addSkillExp(uint32_t skid, uint32_t uExp, uint16_t flag);
	void babyLearnSkillOK(uint32_t instId, uint32_t newSkId);
	void skillLevelUp(uint32_t instId, Ref<COM_Skill> inst);
	void joinScene(Ref<COM_SceneInfo> info);
	void joinCopySceneOK(int32_t secneid);
	void initCopyNums();
	void addToScene(Ref<COM_ScenePlayerInformation> inst);
	void delFormScene(int32_t instId);
	void move2(int32_t instId, Ref<COM_FPosition> pos);
	void cantMove();
	void querySimplePlayerInstOk(Ref<COM_SimplePlayerInst> player);
	void transfor2(int32_t instId, Ref<COM_FPosition> pos);
	void openScene(int32_t sceneId);
	void autoBattleResult(bool isOk);
	void talked2Npc(int32_t npcId);
	void talked2Player(int32_t playerId);
	void useItemOk(int32_t itemId, int32_t stack);
	void syncBattleStatus(int32_t playerId, bool inBattle);
	void enterBattleOk(Ref<COM_InitBattle> initBattle);
	void exitBattleOk(uint16_t bjt, Ref<COM_BattleOverClearing> init);
	void syncOrderOk(uint32_t uid);
	void syncOrderOkEX();
	void syncOneTurnAction(Ref<COM_BattleReport> reports);
	void syncProperties(uint32_t guid, TypedArray<COM_PropValue> props);
	void receiveChat(Ref<COM_ChatInfo> info, Ref<COM_ContactInfo> myinfo);
	void requestAudioOk(int32_t audioId, TypedArray<uint8_t> content);
	void publishItemInstRes(Ref<COM_ShowItemInstInfo> info, uint16_t type);
	void queryItemInstRes(Ref<COM_ShowItemInst> item);
	void publishBabyInstRes(Ref<COM_ShowbabyInstInfo> info, uint16_t type);
	void queryBabyInstRes(Ref<COM_ShowbabyInst> inst);
	void setNoTalkTime(float t);
	void addNpc(TypedArray<int32_t> npcList);
	void delNpc(TypedArray<int32_t> npcList);
	void setTeamLeader(int32_t playerId, bool isLeader);
	void initBag(TypedArray<COM_Item> items);
	void addBagItem(Ref<COM_Item> item);
	void delBagItem(uint16_t slot);
	void updateBagItem(Ref<COM_Item> item);
	void depositItemOK(Ref<COM_Item> item);
	void getoutItemOK(uint16_t slot);
	void depositBabyOK(Ref<COM_BabyInst> baby);
	void getoutBabyOK(uint16_t slot);
	void sortItemStorageOK(TypedArray<COM_Item> items);
	void sortBabyStorageOK(TypedArray<uint32_t> babys);
	void initItemStorage(uint16_t gridNum, TypedArray<COM_Item> items);
	void initBabyStorage(uint16_t gridNum, TypedArray<COM_BabyInst> babys);
	void openStorageGrid(uint16_t tp, uint16_t gridNum);
	void delStorageBabyOK(uint16_t slot);
	void initPlayerEquips(TypedArray<COM_Item> equips);
	void wearEquipmentOk(uint32_t target, Ref<COM_Item> equip);
	void scenePlayerWearEquipment(uint32_t target, uint32_t itemId);
	void delEquipmentOk(uint32_t target, uint32_t itemInstId);
	void scenePlayerDoffEquipment(uint32_t target, uint32_t itemId);
	void sortBagItemOk();
	void jointLobbyOk(TypedArray<COM_SimpleTeamInfo> infos);
	void exitLobbyOk();
	void syncDelLobbyTeam(uint32_t teamId);
	void syncUpdateLobbyTeam(Ref<COM_SimpleTeamInfo> info);
	void syncAddLobbyTeam(Ref<COM_SimpleTeamInfo> team);
	void createTeamOk(Ref<COM_TeamInfo> team);
	void changeTeamOk(Ref<COM_TeamInfo> team);
	void joinTeamOk(Ref<COM_TeamInfo> team);
	void addTeamMember(Ref<COM_SimplePlayerInst> info);
	void delTeamMember(int32_t instId);
	void changeTeamLeaderOk(int32_t uuid);
	void exitTeamOk(bool iskick);
	void updateTeam(Ref<COM_TeamInfo> team);
	void joinTeamRoomOK(Ref<COM_TeamInfo> team);
	void inviteJoinTeam(uint32_t teamId, String name);
	void syncTeamDirtyProp(int32_t guid, TypedArray<COM_PropValue> props);
	void leaveTeamOk(int32_t playerId);
	void backTeamOK(int32_t playerId);
	void teamCallMemberBack();
	void refuseBackTeamOk(int32_t playerId);
	void requestJoinTeamTranspond(String reqName);
	void drawLotteryBoxRep(TypedArray<COM_Item> items);
	void addEmployee(Ref<COM_EmployeeInst> employee);
	void battleEmployee(int32_t empId, uint16_t group, bool forbattle);
	void changeEmpBattleGroupOK(uint16_t group);
	void evolveOK(int32_t guid, uint16_t qc);
	void upStarOK(int32_t guid, int32_t star, Ref<COM_Skill> sk);
	void delEmployeeOK(TypedArray<uint32_t> instids);
	void sycnEmployeeSoul(int32_t guid, uint32_t soulNum);
	void initQuest(TypedArray<COM_QuestInst> qlist, TypedArray<int32_t> clist);
	void acceptQuestOk(Ref<COM_QuestInst> inst);
	void submitQuestOk(int32_t questId);
	void giveupQuestOk(int32_t questId);
	void updateQuestInst(Ref<COM_QuestInst> inst);
	void requestContactInfoOk(Ref<COM_ContactInfo> contact);
	void addFriendOK(Ref<COM_ContactInfo> inst);
	void delFriendOK(uint32_t instId);
	void addBlacklistOK(Ref<COM_ContactInfo> inst);
	void delBlacklistOK(uint32_t instId);
	void findFriendFail();
	void referrFriendOK(TypedArray<COM_ContactInfo> insts);
	void requestFriendListOK(TypedArray<COM_ContactInfo> insts);
	void lotteryOk(int32_t lotteryId, TypedArray<COM_DropItem> dropItem);
	void openGatherOK(Ref<COM_Gather> gather);
	void miningOk(TypedArray<COM_DropItem> items, Ref<COM_Gather> gather, uint32_t gatherNum);
	void openCompound(uint32_t compoundId);
	void compoundItemOk(Ref<COM_Item> item);
	void openBagGridOk(int32_t num);
	void requestChallengeOK(bool isOK);
	void requestMySelfJJCDataOK(Ref<COM_EndlessStair> info);
	void requestRivalOK(TypedArray<COM_EndlessStair> infos);
	void rivalTimeOK();
	void checkMsgOK(Ref<COM_SimplePlayerInst> inst);
	void requestMyAllbattleMsgOK(TypedArray<COM_JJCBattleMsg> infos);
	void myBattleMsgOK(Ref<COM_JJCBattleMsg> info);
	void requestJJCRankOK(uint32_t myRank, TypedArray<COM_EndlessStair> infos);
	void requestLevelRankOK(uint32_t myRank, TypedArray<COM_ContactInfo> infos);
	void requestBabyRankOK(uint32_t myRank, TypedArray<COM_BabyRankData> infos);
	void requestEmpRankOK(uint32_t myRank, TypedArray<COM_EmployeeRankData> infos);
	void requestPlayerFFRankOK(uint32_t myRank, TypedArray<COM_ContactInfo> infos);
	void queryOnlinePlayerOK(bool isOnline);
	void queryPlayerOK(Ref<COM_SimplePlayerInst> inst);
	void queryBabyOK(Ref<COM_BabyInst> inst);
	void queryEmployeeOK(Ref<COM_EmployeeInst> inst);
	void initGuide(uint32_t guideMask);
	void buyShopItemOk(int32_t id);
	void addPlayerTitle(int32_t title);
	void delPlayerTitle(int32_t title);
	void requestOpenBuyBox(float greenTime, float blueTime, int32_t greenFreeNum);
	void requestGreenBoxTimeOk();
	void requestBlueBoxTimeOk();
	void updateAchievementinfo(Ref<COM_Achievement> achs);
	void syncOpenSystemFlag(uint64_t flag);
	void requestActivityRewardOK(uint32_t ar);
	void syncActivity(Ref<COM_ActivityTable> table);
	void updateActivityStatus(uint16_t type, bool open);
	void updateActivityCounter(uint16_t type, int32_t counter, int32_t reward);
	void syncExam(Ref<COM_Exam> exam);
	void syncExamAnswer(Ref<COM_Answer> answer);
	void petActivityNoNum(String name);
	void syncHundredInfo(Ref<COM_HundredBattle> hb);
	void initSignUp(TypedArray<int32_t> info, int32_t process, bool sign7, bool sign14, bool sign28);
	void signUp(bool flag);
	void requestSignupRewardOk7();
	void requestSignupRewardOk14();
	void requestSignupRewardOk28();
	void sycnDoubleExpTime(bool isFlag, float times);
	void sycnStates(TypedArray<COM_State> states);
	void requestpvprankOK(TypedArray<COM_ContactInfo> infos);
	void syncMyJJCTeamMember();
	void startMatchingOK();
	void stopMatchingOK(float times);
	void updatePvpJJCinfo(Ref<COM_PlayerVsPlayer> info);
	void exitPvpJJCOk();
	void syncEnemyPvpJJCPlayerInfo(Ref<COM_SimpleInformation> info);
	void syncEnemyPvpJJCTeamInfo(TypedArray<COM_SimpleInformation> infos, uint32_t teamID_);
	void openWarriorchooseUI();
	void warriorStartOK();
	void warriorStopOK();
	void syncWarriorEnemyTeamInfo(TypedArray<COM_SimpleInformation> infos, uint32_t teamID_);
	void appendMail(TypedArray<COM_Mail> mails);
	void delMail(int32_t mailId);
	void updateMailOk(Ref<COM_Mail> mail);
	void boardcastNotice(String content, bool isGm);
	void createGuildOK();
	void delGuildOK();
	void leaveGuildOk(String who, bool isKick);
	void initGuildData(Ref<COM_Guild> guild);
	void initGuildMemberList(TypedArray<COM_GuildMember> member);
	void modifyGuildMemberList(Ref<COM_GuildMember> member, uint16_t flag);
	void modifyGuildList(Ref<COM_GuildViewerData> data, uint16_t flag);
	void queryGuildListResult(int16_t page, int16_t pageNum, TypedArray<COM_GuildViewerData> guildList);
	void inviteGuild(String sendName, String guildName);
	void updateGuildShopItems(TypedArray<COM_GuildShopItem> items);
	void updateGuildBuilding(uint16_t type, Ref<COM_GuildBuilding> building);
	void updateGuildMyMember(Ref<COM_GuildMember> member);
	void levelupGuildSkillOk(Ref<COM_Skill> skInst);
	void presentGuildItemOk(int32_t val);
	void progenitusAddExpOk(Ref<COM_GuildProgen> mInst);
	void setProgenitusPositionOk(TypedArray<int32_t> positions);
	void updateGuildFundz(int32_t val);
	void updateGuildMemberContribution(int32_t val);
	void openGuildBattle(String otherName, int32_t playerNum, int32_t level, bool isLeft, int32_t lstime);
	void startGuildBattle(String otherName, int32_t otherCon, int32_t selfCon);
	void closeGuildBattle(bool isWinner);
	void syncGuildBattleWinCount(int32_t myWin, int32_t otherWin);
	void initMySelling(TypedArray<COM_SellItem> items);
	void initMySelled(TypedArray<COM_SelledItem> items);
	void fetchSellingOk(TypedArray<COM_SellItem> items, int32_t total);
	void fetchSellingOk2(TypedArray<COM_SellItem> items, int32_t total);
	void sellingOk(Ref<COM_SellItem> item);
	void selledOk(Ref<COM_SelledItem> item);
	void unsellingOk(int32_t sellid);
	void redemptionSpreeOk();
	void insertState(Ref<COM_State> st);
	void updattState(Ref<COM_State> st);
	void removeState(uint32_t stid);
	void requestFixItemOk(Ref<COM_Item> item);
	void makeDebirsItemOK();
	void updateMagicItem(int32_t level, int32_t exp);
	void changeMagicJobOk(uint16_t job);
	void magicItemTupoOk(int32_t level);
	void zhuanpanOK(TypedArray<uint32_t> pond);
	void updateZhuanpanNotice(Ref<COM_Zhuanpan> zhuanp);
	void sycnZhuanpanData(Ref<COM_ZhuanpanData> data);
	void copynonum(String name);
	void sceneFilterOk(TypedArray<uint16_t> sfType);
	void wishingOK();
	void shareWishOK(Ref<COM_Wish> wish);
	void leaderCloseDialogOk();
	void startOnlineTime();
	void requestOnlineTimeRewardOK(uint32_t index);
	void sycnVipflag(bool flag);
	void buyFundOK(bool flag);
	void requestFundRewardOK(uint32_t level);
	void firstRechargeOK(bool isFlag);
	void firstRechargeGiftOK(bool isFlag);
	void agencyActivity(uint16_t type, bool isFlag);
	void updateFestival(Ref<COM_ADLoginTotal> festival);
	void updateSelfRecharge(Ref<COM_ADChargeTotal> val);
	void updateSysRecharge(Ref<COM_ADChargeTotal> val);
	void updateSelfDiscountStore(Ref<COM_ADDiscountStore> val);
	void updateSysDiscountStore(Ref<COM_ADDiscountStore> val);
	void updateSelfOnceRecharge(Ref<COM_ADChargeEvery> val);
	void updateSysOnceRecharge(Ref<COM_ADChargeEvery> val);
	void openCardOK(Ref<COM_ADCardsContent> data);
	void resetCardOK();
	void sycnHotRole(Ref<COM_ADHotRole> data);
	void hotRoleBuyOk(uint16_t buyNum);
	void updateSevenday(Ref<COM_Sevenday> data);
	void updateEmployeeActivity(Ref<COM_ADEmployeeTotal> data);
	void updateMinGiftActivity(Ref<COM_ADGiftBag> data);
	void updateIntegralShop(Ref<COM_IntegralData> data);
	void updateShowBaby(uint32_t playerId, uint32_t showBabyTableId, String showBabyName);
	void updateMySelfRecharge(Ref<COM_ADChargeTotal> val);
	void verificationSMSOk(String phoneNumber);
	void requestLevelGiftOK(int32_t level);
	void sycnConvertExp(int32_t val);
	void wearFuwenOk(Ref<COM_Item> inst);
	void takeoffFuwenOk(int32_t slot);
	void compFuwenOk();
	void requestEmployeeQuestOk(TypedArray<COM_EmployeeQuestInst> questList);
	void acceptEmployeeQuestOk(Ref<COM_EmployeeQuestInst> inst);
	void submitEmployeeQuestOk(int32_t questId, bool isSuccess);
	void sycnCrystal(Ref<COM_CrystalData> data);
	void crystalUpLeveResult(bool isOK);
	void resetCrystalPropOK();
	void sycnCourseGift(TypedArray<COM_CourseGift> data);
	void orderOk(String orderId, int32_t shopId);
	void updateRandSubmitQuestCount(int32_t submitCount);
	void updateTeamMember(int32_t playerId, bool isMember);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class Server2Client_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, Server2Client_Proxy* proxy);
};
class SGE_World2Login_Proxy {
public:
	virtual ~SGE_World2Login_Proxy() {}
	virtual void queryAccount(Ref<COM_LoginInfo> info) = 0;
	virtual void setAccountSeal(String accountname, bool val) = 0;
	virtual void setPhoneNumber(String accountname, String phoneNumber) = 0;
};

class SGE_World2Login_Stub {
public:
	virtual ~SGE_World2Login_Stub() {}
	void queryAccount(Ref<COM_LoginInfo> info);
	void setAccountSeal(String accountname, bool val);
	void setPhoneNumber(String accountname, String phoneNumber);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_World2Login_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_World2Login_Proxy* proxy);
};
class SGE_Login2World_Proxy {
public:
	virtual ~SGE_Login2World_Proxy() {}
	virtual void queryAccountOk(Ref<COM_AccountInfo> info, bool isNew, bool isSeal) = 0;
	virtual void setAccountSealOk(String accountname) = 0;
};

class SGE_Login2World_Stub {
public:
	virtual ~SGE_Login2World_Stub() {}
	void queryAccountOk(Ref<COM_AccountInfo> info, bool isNew, bool isSeal);
	void setAccountSealOk(String accountname);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Login2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Login2World_Proxy* proxy);
};
class SGE_Gateway2World_Proxy {
public:
	virtual ~SGE_Gateway2World_Proxy() {}
	virtual void syncConnectInfo(int32_t indoor, String ip) = 0;
};

class SGE_Gateway2World_Stub {
public:
	virtual ~SGE_Gateway2World_Stub() {}
	void syncConnectInfo(int32_t indoor, String ip);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Gateway2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Gateway2World_Proxy* proxy);
};
class SGE_World2DB_Proxy {
public:
	virtual ~SGE_World2DB_Proxy() {}
	virtual void queryPlayerSimpleInformation(String username, int32_t serverId) = 0;
	virtual void queryPlayer(String username, int32_t playerId) = 0;
	virtual void createPlayer(String username, Ref<SGE_DBPlayerData> inst, int32_t serverId) = 0;
	virtual void updatePlayer(String username, Ref<SGE_DBPlayerData> inst) = 0;
	virtual void deletePlayer(String playername) = 0;
	virtual void queryPlayerById(String name, int32_t instId, int32_t where) = 0;
	virtual void insertEndlessStair(int32_t rank, String name) = 0;
	virtual void updateEndlessStair(int32_t rank, String name) = 0;
	virtual void createBaby(String playername, Ref<COM_BabyInst> inst, bool isToStorage) = 0;
	virtual void deleteBaby(String playername, int32_t babyInstId) = 0;
	virtual void updateBaby(Ref<COM_BabyInst> inst) = 0;
	virtual void updateBabys(String playername, TypedArray<COM_BabyInst> babys) = 0;
	virtual void queryBabyById(String name, uint32_t instid) = 0;
	virtual void createEmployee(String playername, Ref<COM_EmployeeInst> inst) = 0;
	virtual void deleteEmployee(String playername, TypedArray<uint32_t> instIds) = 0;
	virtual void updateEmployee(Ref<COM_EmployeeInst> inst) = 0;
	virtual void queryEmployeeById(String name, uint32_t instid) = 0;
	virtual void insertMail(Ref<COM_Mail> mail) = 0;
	virtual void insertMailAll(Ref<COM_Mail> mail) = 0;
	virtual void insertMailByRecvs(Ref<COM_Mail> mail, TypedArray<String> recvs) = 0;
	virtual void fatchMail(String recvName, int32_t mailId) = 0;
	virtual void delMail(String recvName, int32_t mailId) = 0;
	virtual void updateMail(Ref<COM_Mail> mail) = 0;
	virtual void insertGuild(Ref<COM_Guild> guild, Ref<COM_GuildMember> guildMember) = 0;
	virtual void updateGuildRequestList(uint32_t guildId, TypedArray<COM_GuildRequestData> data) = 0;
	virtual void createGuildMember(Ref<COM_GuildMember> guildMember) = 0;
	virtual void delGuild(int32_t guildId) = 0;
	virtual void updateGuildNotice(uint32_t guildId, String notice) = 0;
	virtual void updateGuild(Ref<COM_Guild> guild) = 0;
	virtual void updateMemberPosition(int32_t roleId, uint16_t job) = 0;
	virtual void updateMemberContribution(int32_t roleId, int32_t contribution) = 0;
	virtual void updateGuildStruction(uint32_t guildId, int8_t level, int32_t struction) = 0;
	virtual void deleteGuildMember(int32_t playerId) = 0;
	virtual void insertActivity(uint16_t adt, Ref<SGE_SysActivity> date) = 0;
	virtual void insertLoseCharge(int32_t playerId, Ref<SGE_OrderInfo> order) = 0;
	virtual void insertEmployeeQuest(uint32_t playerId, Ref<SGE_PlayerEmployeeQuest> data) = 0;
	virtual void delEmployeeQuest(uint32_t playerId) = 0;
	virtual void deleteEndlessStair(String name) = 0;
};

class SGE_World2DB_Stub {
public:
	virtual ~SGE_World2DB_Stub() {}
	void queryPlayerSimpleInformation(String username, int32_t serverId);
	void queryPlayer(String username, int32_t playerId);
	void createPlayer(String username, Ref<SGE_DBPlayerData> inst, int32_t serverId);
	void updatePlayer(String username, Ref<SGE_DBPlayerData> inst);
	void deletePlayer(String playername);
	void queryPlayerById(String name, int32_t instId, int32_t where);
	void insertEndlessStair(int32_t rank, String name);
	void updateEndlessStair(int32_t rank, String name);
	void createBaby(String playername, Ref<COM_BabyInst> inst, bool isToStorage);
	void deleteBaby(String playername, int32_t babyInstId);
	void updateBaby(Ref<COM_BabyInst> inst);
	void updateBabys(String playername, TypedArray<COM_BabyInst> babys);
	void queryBabyById(String name, uint32_t instid);
	void createEmployee(String playername, Ref<COM_EmployeeInst> inst);
	void deleteEmployee(String playername, TypedArray<uint32_t> instIds);
	void updateEmployee(Ref<COM_EmployeeInst> inst);
	void queryEmployeeById(String name, uint32_t instid);
	void insertMail(Ref<COM_Mail> mail);
	void insertMailAll(Ref<COM_Mail> mail);
	void insertMailByRecvs(Ref<COM_Mail> mail, TypedArray<String> recvs);
	void fatchMail(String recvName, int32_t mailId);
	void delMail(String recvName, int32_t mailId);
	void updateMail(Ref<COM_Mail> mail);
	void insertGuild(Ref<COM_Guild> guild, Ref<COM_GuildMember> guildMember);
	void updateGuildRequestList(uint32_t guildId, TypedArray<COM_GuildRequestData> data);
	void createGuildMember(Ref<COM_GuildMember> guildMember);
	void delGuild(int32_t guildId);
	void updateGuildNotice(uint32_t guildId, String notice);
	void updateGuild(Ref<COM_Guild> guild);
	void updateMemberPosition(int32_t roleId, uint16_t job);
	void updateMemberContribution(int32_t roleId, int32_t contribution);
	void updateGuildStruction(uint32_t guildId, int8_t level, int32_t struction);
	void deleteGuildMember(int32_t playerId);
	void insertActivity(uint16_t adt, Ref<SGE_SysActivity> date);
	void insertLoseCharge(int32_t playerId, Ref<SGE_OrderInfo> order);
	void insertEmployeeQuest(uint32_t playerId, Ref<SGE_PlayerEmployeeQuest> data);
	void delEmployeeQuest(uint32_t playerId);
	void deleteEndlessStair(String name);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_World2DB_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_World2DB_Proxy* proxy);
};
class SGE_DB2World_Proxy {
public:
	virtual ~SGE_DB2World_Proxy() {}
	virtual void syncGlobalGuid(uint32_t id) = 0;
	virtual void syncContactInfo(TypedArray<SGE_ContactInfoExt> info) = 0;
	virtual void queryPlayerSimpleInformationOk(String username, TypedArray<COM_SimpleInformation> insts, int32_t serverId) = 0;
	virtual void queryPlayerOk(String username, Ref<SGE_DBPlayerData> player) = 0;
	virtual void createPlayerOk(String username, Ref<SGE_DBPlayerData> inst, int32_t inDoorId) = 0;
	virtual void createPlayerSameName(String username) = 0;
	virtual void queryPlayerByIdOK(String playername, Ref<SGE_DBPlayerData> inst, int32_t where) = 0;
	virtual void queryEndlessStairAllDateOK(TypedArray<String> name) = 0;
	virtual void queryPlayerByLevelOK(TypedArray<COM_ContactInfo> info) = 0;
	virtual void queryPlayerByFFOK(TypedArray<COM_ContactInfo> info) = 0;
	virtual void createBabyOK(String playername, Ref<COM_BabyInst> inst, bool isToStorage) = 0;
	virtual void deleteBabyOK(String playername, int32_t babyInstId) = 0;
	virtual void queryBabyByFFOK(TypedArray<COM_BabyRankData> infos) = 0;
	virtual void queryBabyByIdOK(String name, Ref<COM_BabyInst> inst) = 0;
	virtual void UpdateBabysOK(String playername) = 0;
	virtual void createEmployeeOK(String playername, Ref<COM_EmployeeInst> inst) = 0;
	virtual void deleteEmployeeOK(String playername, TypedArray<uint32_t> instIds) = 0;
	virtual void queryEmployeeByFFOK(TypedArray<COM_EmployeeRankData> infos) = 0;
	virtual void queryEmployeeByIdOK(String name, Ref<COM_EmployeeInst> inst) = 0;
	virtual void appendMail(String playerName, TypedArray<COM_Mail> mails) = 0;
	virtual void insertGuildOK(Ref<COM_Guild> guild, Ref<COM_GuildMember> guildMember) = 0;
	virtual void updateMemberJobOk(int32_t roleId, uint16_t job) = 0;
	virtual void syncGuild(TypedArray<COM_Guild> guilds) = 0;
	virtual void syncGuildMember(TypedArray<COM_GuildMember> guildMember) = 0;
	virtual void fatchActivity(Ref<SGE_SysActivity> date) = 0;
	virtual void syncEmployeeQuest(TypedArray<SGE_PlayerEmployeeQuest> info) = 0;
};

class SGE_DB2World_Stub {
public:
	virtual ~SGE_DB2World_Stub() {}
	void syncGlobalGuid(uint32_t id);
	void syncContactInfo(TypedArray<SGE_ContactInfoExt> info);
	void queryPlayerSimpleInformationOk(String username, TypedArray<COM_SimpleInformation> insts, int32_t serverId);
	void queryPlayerOk(String username, Ref<SGE_DBPlayerData> player);
	void createPlayerOk(String username, Ref<SGE_DBPlayerData> inst, int32_t inDoorId);
	void createPlayerSameName(String username);
	void queryPlayerByIdOK(String playername, Ref<SGE_DBPlayerData> inst, int32_t where);
	void queryEndlessStairAllDateOK(TypedArray<String> name);
	void queryPlayerByLevelOK(TypedArray<COM_ContactInfo> info);
	void queryPlayerByFFOK(TypedArray<COM_ContactInfo> info);
	void createBabyOK(String playername, Ref<COM_BabyInst> inst, bool isToStorage);
	void deleteBabyOK(String playername, int32_t babyInstId);
	void queryBabyByFFOK(TypedArray<COM_BabyRankData> infos);
	void queryBabyByIdOK(String name, Ref<COM_BabyInst> inst);
	void UpdateBabysOK(String playername);
	void createEmployeeOK(String playername, Ref<COM_EmployeeInst> inst);
	void deleteEmployeeOK(String playername, TypedArray<uint32_t> instIds);
	void queryEmployeeByFFOK(TypedArray<COM_EmployeeRankData> infos);
	void queryEmployeeByIdOK(String name, Ref<COM_EmployeeInst> inst);
	void appendMail(String playerName, TypedArray<COM_Mail> mails);
	void insertGuildOK(Ref<COM_Guild> guild, Ref<COM_GuildMember> guildMember);
	void updateMemberJobOk(int32_t roleId, uint16_t job);
	void syncGuild(TypedArray<COM_Guild> guilds);
	void syncGuildMember(TypedArray<COM_GuildMember> guildMember);
	void fatchActivity(Ref<SGE_SysActivity> date);
	void syncEmployeeQuest(TypedArray<SGE_PlayerEmployeeQuest> info);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_DB2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_DB2World_Proxy* proxy);
};
class SGE_Scene2World_Proxy {
public:
	virtual ~SGE_Scene2World_Proxy() {}
};

class SGE_Scene2World_Stub {
public:
	virtual ~SGE_Scene2World_Stub() {}
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Scene2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Scene2World_Proxy* proxy);
};
class SGE_World2Scene_Proxy {
public:
	virtual ~SGE_World2Scene_Proxy() {}
	virtual void initDynamicNpcs(uint16_t type, int32_t count) = 0;
	virtual void refreshDynamicNpcs(uint16_t type, int32_t count) = 0;
	virtual void finiDynamicNpcs(uint16_t type) = 0;
	virtual void addDynamicNpcs(int32_t sceneId, TypedArray<int32_t> npcs) = 0;
	virtual void delDynamicNpc(int32_t npcId) = 0;
	virtual void delDynamicNpc2(int32_t sceneId, int32_t npcId) = 0;
	virtual void openSceneCopy(int32_t instId) = 0;
	virtual void closeSceneCopy(int32_t instId) = 0;
};

class SGE_World2Scene_Stub {
public:
	virtual ~SGE_World2Scene_Stub() {}
	void initDynamicNpcs(uint16_t type, int32_t count);
	void refreshDynamicNpcs(uint16_t type, int32_t count);
	void finiDynamicNpcs(uint16_t type);
	void addDynamicNpcs(int32_t sceneId, TypedArray<int32_t> npcs);
	void delDynamicNpc(int32_t npcId);
	void delDynamicNpc2(int32_t sceneId, int32_t npcId);
	void openSceneCopy(int32_t instId);
	void closeSceneCopy(int32_t instId);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_World2Scene_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_World2Scene_Proxy* proxy);
};
class SGE_Player_Scene2World_Proxy {
public:
	virtual ~SGE_Player_Scene2World_Proxy() {}
	virtual void joinScene(Ref<COM_SceneInfo> info) = 0;
	virtual void move2(Ref<COM_FPosition> pos) = 0;
	virtual void cantMove() = 0;
	virtual void transfor2(Ref<COM_FPosition> pos) = 0;
	virtual void autoBattleResult(bool isOk) = 0;
	virtual void zoneJoinBattle(int32_t zoneId) = 0;
	virtual void playerAddNpc(TypedArray<int32_t> npcs) = 0;
	virtual void playerDelNpc(TypedArray<int32_t> npcs) = 0;
	virtual void talkedNpc(int32_t npcid) = 0;
	virtual void findDynamicNpcOK(int32_t npcid, bool hasnpc) = 0;
};

class SGE_Player_Scene2World_Stub {
public:
	virtual ~SGE_Player_Scene2World_Stub() {}
	void joinScene(Ref<COM_SceneInfo> info);
	void move2(Ref<COM_FPosition> pos);
	void cantMove();
	void transfor2(Ref<COM_FPosition> pos);
	void autoBattleResult(bool isOk);
	void zoneJoinBattle(int32_t zoneId);
	void playerAddNpc(TypedArray<int32_t> npcs);
	void playerDelNpc(TypedArray<int32_t> npcs);
	void talkedNpc(int32_t npcid);
	void findDynamicNpcOK(int32_t npcid, bool hasnpc);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Player_Scene2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Player_Scene2World_Proxy* proxy);
};
class SGE_Player_World2Scene_Proxy {
public:
	virtual ~SGE_Player_World2Scene_Proxy() {}
	virtual void initScenePlayer(Ref<SGE_ScenePlayerInfo> info) = 0;
	virtual void scenePlayerUpLevel(int32_t level) = 0;
	virtual void scenePlayerAddCurrentQuest(int32_t questId) = 0;
	virtual void scenePlayerDelCurrentQuest(int32_t questId) = 0;
	virtual void scenePlayerAddAcceptableQuest(int32_t questId) = 0;
	virtual void scenePlayerDelAcceptableQuest(int32_t questId) = 0;
	virtual void openScene(int32_t sceneId) = 0;
	virtual void joinBattle() = 0;
	virtual void finishBattle() = 0;
	virtual void transforScene(int32_t sceneId) = 0;
	virtual void transforSceneByEntry(int32_t sceneId, int32_t entryId) = 0;
	virtual void backHomeScene() = 0;
	virtual void sceneLoaded() = 0;
	virtual void move(Ref<COM_FPosition> pos) = 0;
	virtual void moveToNpc(int32_t npcid) = 0;
	virtual void moveToNpc2(uint16_t type) = 0;
	virtual void moveToZone(int32_t sceneId, int32_t zoneId) = 0;
	virtual void autoBattle() = 0;
	virtual void stopMove() = 0;
	virtual void addFollow(int32_t scenePlayerId) = 0;
	virtual void delFollow(int32_t scenePlayerId) = 0;
	virtual void delFollows() = 0;
	virtual void addFollows(TypedArray<int32_t> scenePlayers) = 0;
	virtual void setEntryFlag(int32_t scenePlayerId, bool isFlag) = 0;
	virtual void addNpc(int32_t npcid) = 0;
	virtual void delNpc(int32_t npcid) = 0;
	virtual void findDynamicNpc(int32_t npcId) = 0;
};

class SGE_Player_World2Scene_Stub {
public:
	virtual ~SGE_Player_World2Scene_Stub() {}
	void initScenePlayer(Ref<SGE_ScenePlayerInfo> info);
	void scenePlayerUpLevel(int32_t level);
	void scenePlayerAddCurrentQuest(int32_t questId);
	void scenePlayerDelCurrentQuest(int32_t questId);
	void scenePlayerAddAcceptableQuest(int32_t questId);
	void scenePlayerDelAcceptableQuest(int32_t questId);
	void openScene(int32_t sceneId);
	void joinBattle();
	void finishBattle();
	void transforScene(int32_t sceneId);
	void transforSceneByEntry(int32_t sceneId, int32_t entryId);
	void backHomeScene();
	void sceneLoaded();
	void move(Ref<COM_FPosition> pos);
	void moveToNpc(int32_t npcid);
	void moveToNpc2(uint16_t type);
	void moveToZone(int32_t sceneId, int32_t zoneId);
	void autoBattle();
	void stopMove();
	void addFollow(int32_t scenePlayerId);
	void delFollow(int32_t scenePlayerId);
	void delFollows();
	void addFollows(TypedArray<int32_t> scenePlayers);
	void setEntryFlag(int32_t scenePlayerId, bool isFlag);
	void addNpc(int32_t npcid);
	void delNpc(int32_t npcid);
	void findDynamicNpc(int32_t npcId);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Player_World2Scene_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Player_World2Scene_Proxy* proxy);
};
class SGE_World2GMT_Proxy {
public:
	virtual ~SGE_World2GMT_Proxy() {}
};

class SGE_World2GMT_Stub {
public:
	virtual ~SGE_World2GMT_Stub() {}
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_World2GMT_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_World2GMT_Proxy* proxy);
};
class SGE_GMT2World_Proxy {
public:
	virtual ~SGE_GMT2World_Proxy() {}
	virtual void addExp(uint32_t playerId, uint32_t exp) = 0;
	virtual void addMoney(uint32_t playerId, int32_t money) = 0;
	virtual void addDiamond(uint32_t playerId, int32_t diamond) = 0;
	virtual void openGM(uint32_t playerId) = 0;
	virtual void closeGM(uint32_t playerId) = 0;
	virtual void noTalkPlayer(uint32_t playerId, uint32_t time) = 0;
	virtual void sealPlayer(uint32_t playerId) = 0;
	virtual void kickPlayer(uint32_t playerId) = 0;
	virtual void openTalkPlayer(uint32_t playerId) = 0;
	virtual void unsealPlayer(uint32_t playerId) = 0;
	virtual void sendMailAllOnline(Ref<COM_Mail> mail, int32_t lowLevel, int32_t highLevel, int64_t lowRegTime, int64_t highRegTime) = 0;
	virtual void gmtNotice(uint16_t bType, String note, uint64_t thetime, int64_t itvtime) = 0;
	virtual void setChargeTotal(Ref<COM_ADChargeTotal> data) = 0;
	virtual void setChargeEvery(Ref<COM_ADChargeEvery> data) = 0;
	virtual void setDiscountStore(Ref<COM_ADDiscountStore> data) = 0;
	virtual void setLoginTotal(Ref<COM_ADLoginTotal> data) = 0;
	virtual void setHotRole(Ref<COM_ADHotRole> data) = 0;
	virtual void setEmployeeActivity(Ref<COM_ADEmployeeTotal> data) = 0;
	virtual void setMinGiftBagActivity(Ref<COM_ADGiftBag> data) = 0;
	virtual void setZhuanpanActivity(Ref<COM_ZhuanpanData> data) = 0;
	virtual void setIntegralshop(Ref<COM_IntegralData> data) = 0;
	virtual void makeOrder(uint32_t playerId, Ref<SGE_GmtOrder> order) = 0;
	virtual void doScript(String script) = 0;
	virtual void playerDoScript(uint32_t playerId, String script) = 0;
};

class SGE_GMT2World_Stub {
public:
	virtual ~SGE_GMT2World_Stub() {}
	void addExp(uint32_t playerId, uint32_t exp);
	void addMoney(uint32_t playerId, int32_t money);
	void addDiamond(uint32_t playerId, int32_t diamond);
	void openGM(uint32_t playerId);
	void closeGM(uint32_t playerId);
	void noTalkPlayer(uint32_t playerId, uint32_t time);
	void sealPlayer(uint32_t playerId);
	void kickPlayer(uint32_t playerId);
	void openTalkPlayer(uint32_t playerId);
	void unsealPlayer(uint32_t playerId);
	void sendMailAllOnline(Ref<COM_Mail> mail, int32_t lowLevel, int32_t highLevel, int64_t lowRegTime, int64_t highRegTime);
	void gmtNotice(uint16_t bType, String note, uint64_t thetime, int64_t itvtime);
	void setChargeTotal(Ref<COM_ADChargeTotal> data);
	void setChargeEvery(Ref<COM_ADChargeEvery> data);
	void setDiscountStore(Ref<COM_ADDiscountStore> data);
	void setLoginTotal(Ref<COM_ADLoginTotal> data);
	void setHotRole(Ref<COM_ADHotRole> data);
	void setEmployeeActivity(Ref<COM_ADEmployeeTotal> data);
	void setMinGiftBagActivity(Ref<COM_ADGiftBag> data);
	void setZhuanpanActivity(Ref<COM_ZhuanpanData> data);
	void setIntegralshop(Ref<COM_IntegralData> data);
	void makeOrder(uint32_t playerId, Ref<SGE_GmtOrder> order);
	void doScript(String script);
	void playerDoScript(uint32_t playerId, String script);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_GMT2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_GMT2World_Proxy* proxy);
};
class SGE_World2Mall_Proxy {
public:
	virtual ~SGE_World2Mall_Proxy() {}
	virtual void fetchSell(int32_t playerid, Ref<COM_SearchContext> context) = 0;
	virtual void fetchMySell(int32_t playerid) = 0;
	virtual void fetchSelledItem(int32_t playerId) = 0;
	virtual void sell(Ref<COM_SellItem> item) = 0;
	virtual void unSell(int32_t playerid, int32_t sellid) = 0;
	virtual void buy(Ref<SGE_BuyContent> content) = 0;
	virtual void insertSelledItem(Ref<COM_SelledItem> item) = 0;
};

class SGE_World2Mall_Stub {
public:
	virtual ~SGE_World2Mall_Stub() {}
	void fetchSell(int32_t playerid, Ref<COM_SearchContext> context);
	void fetchMySell(int32_t playerid);
	void fetchSelledItem(int32_t playerId);
	void sell(Ref<COM_SellItem> item);
	void unSell(int32_t playerid, int32_t sellid);
	void buy(Ref<SGE_BuyContent> content);
	void insertSelledItem(Ref<COM_SelledItem> item);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_World2Mall_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_World2Mall_Proxy* proxy);
};
class SGE_Mall2World_Proxy {
public:
	virtual ~SGE_Mall2World_Proxy() {}
	virtual void fetchSellOk(int32_t playerid, TypedArray<COM_SellItem> items, int32_t totalSize) = 0;
	virtual void fetchMySellOk(int32_t playerid, TypedArray<COM_SellItem> items) = 0;
	virtual void fetchSelledItemOk(int32_t playerId, TypedArray<COM_SelledItem> items) = 0;
	virtual void sellOk(int32_t playerid, Ref<COM_SellItem> item) = 0;
	virtual void unSellOk(int32_t playerid, int32_t sellid) = 0;
	virtual void buyOk(int32_t playerid, Ref<COM_SellItem> item) = 0;
	virtual void buyFail(int32_t playerid, uint16_t errorno) = 0;
};

class SGE_Mall2World_Stub {
public:
	virtual ~SGE_Mall2World_Stub() {}
	void fetchSellOk(int32_t playerid, TypedArray<COM_SellItem> items, int32_t totalSize);
	void fetchMySellOk(int32_t playerid, TypedArray<COM_SellItem> items);
	void fetchSelledItemOk(int32_t playerId, TypedArray<COM_SelledItem> items);
	void sellOk(int32_t playerid, Ref<COM_SellItem> item);
	void unSellOk(int32_t playerid, int32_t sellid);
	void buyOk(int32_t playerid, Ref<COM_SellItem> item);
	void buyFail(int32_t playerid, uint16_t errorno);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Mall2World_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Mall2World_Proxy* proxy);
};
class Backlog_Proxy {
public:
	virtual ~Backlog_Proxy() {}
	virtual void log(String key, String msg, String stack, String version) = 0;
};

class Backlog_Stub {
public:
	virtual ~Backlog_Stub() {}
	void log(String key, String msg, String stack, String version);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class Backlog_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, Backlog_Proxy* proxy);
};
class SGE_Log_Proxy {
public:
	virtual ~SGE_Log_Proxy() {}
	virtual void account(Ref<SGE_Account> data) = 0;
	virtual void login(Ref<SGE_Login> data) = 0;
	virtual void order(Ref<SGE_Order> data) = 0;
	virtual void role(Ref<SGE_LogRole> data) = 0;
	virtual void playersay(uint32_t senderId, String senderName, Ref<COM_Chat> chat) = 0;
	virtual void playerTrack(Ref<SGE_LogProduceTrack> data) = 0;
	virtual void playerUIBehavior(Ref<SGE_LogUIBehavior> core) = 0;
};

class SGE_Log_Stub {
public:
	virtual ~SGE_Log_Stub() {}
	void account(Ref<SGE_Account> data);
	void login(Ref<SGE_Login> data);
	void order(Ref<SGE_Order> data);
	void role(Ref<SGE_LogRole> data);
	void playersay(uint32_t senderId, String senderName, Ref<COM_Chat> chat);
	void playerTrack(Ref<SGE_LogProduceTrack> data);
	void playerUIBehavior(Ref<SGE_LogUIBehavior> core);
protected:
	// events to be processed.
	virtual ProtocolWriter* methodBegin() = 0;
	virtual void methodEnd() = 0;
};

class SGE_Log_Dispatcher {
public:
	static bool dispatch(ProtocolReader* r, SGE_Log_Proxy* proxy);
};

#endif
