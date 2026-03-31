/* arpcc auto generated cpp file. */
#include "FieldMask.h"
#include "proto.h"
//=============================================================
void Client2ServerStub::openvip(VipLevel vl)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize vl
	{
		uint8_t __e__ = (uint8_t)vl;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::requestPhoto()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::ping()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::sessionlogin(const COM_LoginInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::login(const COM_LoginInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::createPlayer(const std::string& playername,uint8_t playerTmpId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize playerTmpId
	{
		w->writeType(playerTmpId);
	}
	methodEnd();
}
void Client2ServerStub::deletePlayer(const std::string& playername)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	methodEnd();
}
void Client2ServerStub::enterGame(uint32_t playerInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize playerInstId
	{
		w->writeType(playerInstId);
	}
	methodEnd();
}
void Client2ServerStub::requestBag()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestEmployees()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestStorage(StorageType tp)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 10;
	w->writeType(pid);
	// serialize tp
	{
		uint8_t __e__ = (uint8_t)tp;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::requestAchievement()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 11;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::initminig()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 12;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestCompound()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 13;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::move(float x,float z)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 14;
	w->writeType(pid);
	// serialize x
	{
		w->writeType(x);
	}
	// serialize z
	{
		w->writeType(z);
	}
	methodEnd();
}
void Client2ServerStub::moveToNpc(int32_t npcid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 15;
	w->writeType(pid);
	// serialize npcid
	{
		w->writeType(npcid);
	}
	methodEnd();
}
void Client2ServerStub::moveToNpc2(NpcType type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 16;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::moveToZone(int32_t sceneId,int32_t zoneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 17;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	// serialize zoneId
	{
		w->writeType(zoneId);
	}
	methodEnd();
}
void Client2ServerStub::autoBattle()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 18;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::stopAutoBattle()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 19;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::stopMove()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 20;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::exitCopy()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 21;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::transforScene(int32_t sceneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 22;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	methodEnd();
}
void Client2ServerStub::sceneLoaded()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 23;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::querySimplePlayerInst(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 24;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::logout()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 25;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::changProp(uint32_t guid,const std::vector< COM_Addprop >& props)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 26;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	// serialize props
	{
		uint32_t __len__ = (uint32_t)props.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			props[i].serialize(w);
		}
	}
	methodEnd();
}
void Client2ServerStub::learnSkill(uint32_t skid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 27;
	w->writeType(pid);
	// serialize skid
	{
		w->writeType(skid);
	}
	methodEnd();
}
void Client2ServerStub::babyLearnSkill(uint32_t instId,uint32_t oldSkId,uint32_t newSkId,uint32_t newSkLv)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 28;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize oldSkId
	{
		w->writeType(oldSkId);
	}
	// serialize newSkId
	{
		w->writeType(newSkId);
	}
	// serialize newSkLv
	{
		w->writeType(newSkLv);
	}
	methodEnd();
}
void Client2ServerStub::forgetSkill(uint32_t skid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 29;
	w->writeType(pid);
	// serialize skid
	{
		w->writeType(skid);
	}
	methodEnd();
}
void Client2ServerStub::syncOrder(const COM_Order& order)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 30;
	w->writeType(pid);
	// serialize order
	{
		order.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::syncOrderTimeout()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 31;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::sendChat(const COM_Chat& content,const std::string& targetName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 32;
	w->writeType(pid);
	// serialize content
	{
		content.serialize(w);
	}
	// serialize targetName
	{
		w->writeType(targetName);
	}
	methodEnd();
}
void Client2ServerStub::requestAudio(int32_t audioId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 33;
	w->writeType(pid);
	// serialize audioId
	{
		w->writeType(audioId);
	}
	methodEnd();
}
void Client2ServerStub::publishItemInst(ItemContainerType type,uint32_t itemInstId,ChatKind chatType,const std::string& playerName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 34;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize itemInstId
	{
		w->writeType(itemInstId);
	}
	// serialize chatType
	{
		uint8_t __e__ = (uint8_t)chatType;
		w->writeType(__e__);
	}
	// serialize playerName
	{
		w->writeType(playerName);
	}
	methodEnd();
}
void Client2ServerStub::queryItemInst(int32_t showId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 35;
	w->writeType(pid);
	// serialize showId
	{
		w->writeType(showId);
	}
	methodEnd();
}
void Client2ServerStub::publishbabyInst(ChatKind type,uint32_t babyInstId,const std::string& playerName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 36;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize babyInstId
	{
		w->writeType(babyInstId);
	}
	// serialize playerName
	{
		w->writeType(playerName);
	}
	methodEnd();
}
void Client2ServerStub::querybabyInst(int32_t showId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 37;
	w->writeType(pid);
	// serialize showId
	{
		w->writeType(showId);
	}
	methodEnd();
}
void Client2ServerStub::useItem(uint32_t slot,uint32_t target,uint32_t stack)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 38;
	w->writeType(pid);
	// serialize slot
	{
		w->writeType(slot);
	}
	// serialize target
	{
		w->writeType(target);
	}
	// serialize stack
	{
		w->writeType(stack);
	}
	methodEnd();
}
void Client2ServerStub::wearEquipment(uint32_t target,uint32_t itemInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 39;
	w->writeType(pid);
	// serialize target
	{
		w->writeType(target);
	}
	// serialize itemInstId
	{
		w->writeType(itemInstId);
	}
	methodEnd();
}
void Client2ServerStub::delEquipment(uint32_t target,uint32_t itemInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 40;
	w->writeType(pid);
	// serialize target
	{
		w->writeType(target);
	}
	// serialize itemInstId
	{
		w->writeType(itemInstId);
	}
	methodEnd();
}
void Client2ServerStub::setPlayerFront(bool isFront)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 41;
	w->writeType(pid);
	// serialize isFront
	{
		w->writeType(isFront);
	}
	methodEnd();
}
void Client2ServerStub::setBattlebaby(uint32_t babyID,bool isBattle)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 42;
	w->writeType(pid);
	// serialize babyID
	{
		w->writeType(babyID);
	}
	// serialize isBattle
	{
		w->writeType(isBattle);
	}
	methodEnd();
}
void Client2ServerStub::changeBabyName(uint32_t babyID,const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 43;
	w->writeType(pid);
	// serialize babyID
	{
		w->writeType(babyID);
	}
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Client2ServerStub::intensifyBaby(uint32_t babyid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 44;
	w->writeType(pid);
	// serialize babyid
	{
		w->writeType(babyid);
	}
	methodEnd();
}
void Client2ServerStub::setBattleEmp(uint32_t empID,EmployeesBattleGroup group,bool isBattle)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 45;
	w->writeType(pid);
	// serialize empID
	{
		w->writeType(empID);
	}
	// serialize group
	{
		uint8_t __e__ = (uint8_t)group;
		w->writeType(__e__);
	}
	// serialize isBattle
	{
		w->writeType(isBattle);
	}
	methodEnd();
}
void Client2ServerStub::changeEmpBattleGroup(EmployeesBattleGroup group)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 46;
	w->writeType(pid);
	// serialize group
	{
		uint8_t __e__ = (uint8_t)group;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::requestEvolve(uint32_t empInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 47;
	w->writeType(pid);
	// serialize empInstId
	{
		w->writeType(empInstId);
	}
	methodEnd();
}
void Client2ServerStub::requestUpStar(uint32_t empInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 48;
	w->writeType(pid);
	// serialize empInstId
	{
		w->writeType(empInstId);
	}
	methodEnd();
}
void Client2ServerStub::requestDelEmp(uint32_t empInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 49;
	w->writeType(pid);
	// serialize empInstId
	{
		w->writeType(empInstId);
	}
	methodEnd();
}
void Client2ServerStub::delEmployee(const std::vector< uint32_t >& emps)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 50;
	w->writeType(pid);
	// serialize emps
	{
		uint32_t __len__ = (uint32_t)emps.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(emps[i]);
		}
	}
	methodEnd();
}
void Client2ServerStub::onekeyDelEmp()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 51;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::delEmployeeSoul(uint32_t instid,uint32_t soulNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 52;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	// serialize soulNum
	{
		w->writeType(soulNum);
	}
	methodEnd();
}
void Client2ServerStub::sortBagItem()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 53;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::sellBagItem(uint32_t instId,uint32_t stack)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 54;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize stack
	{
		w->writeType(stack);
	}
	methodEnd();
}
void Client2ServerStub::depositItemToStorage(uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 55;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Client2ServerStub::depositBabyToStorage(uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 56;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Client2ServerStub::storageItemToBag(uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 57;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Client2ServerStub::storageBabyToPlayer(uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 58;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Client2ServerStub::sortStorage(StorageType tp)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 59;
	w->writeType(pid);
	// serialize tp
	{
		uint8_t __e__ = (uint8_t)tp;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::delStorageBaby(uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 60;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Client2ServerStub::jointLobby()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 61;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::exitLobby()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 62;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::createTeam(const COM_CreateTeamInfo& cti)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 63;
	w->writeType(pid);
	// serialize cti
	{
		cti.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::changeTeam(const COM_CreateTeamInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 64;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::kickTeamMember(uint32_t uuid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 65;
	w->writeType(pid);
	// serialize uuid
	{
		w->writeType(uuid);
	}
	methodEnd();
}
void Client2ServerStub::changeTeamLeader(uint32_t uuid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 66;
	w->writeType(pid);
	// serialize uuid
	{
		w->writeType(uuid);
	}
	methodEnd();
}
void Client2ServerStub::joinTeam(uint32_t teamId,const std::string& pwd)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 67;
	w->writeType(pid);
	// serialize teamId
	{
		w->writeType(teamId);
	}
	// serialize pwd
	{
		w->writeType(pwd);
	}
	methodEnd();
}
void Client2ServerStub::exitTeam()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 68;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::changeTeamPassword(const std::string& pwd)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 69;
	w->writeType(pid);
	// serialize pwd
	{
		w->writeType(pwd);
	}
	methodEnd();
}
void Client2ServerStub::joinTeamRoom()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 70;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::inviteTeamMember(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 71;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Client2ServerStub::isjoinTeam(uint32_t teamId,bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 72;
	w->writeType(pid);
	// serialize teamId
	{
		w->writeType(teamId);
	}
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void Client2ServerStub::leaveTeam()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 73;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::backTeam()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 74;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::refuseBackTeam()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 75;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::teamCallMember(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 76;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Client2ServerStub::requestJoinTeam(const std::string& targetName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 77;
	w->writeType(pid);
	// serialize targetName
	{
		w->writeType(targetName);
	}
	methodEnd();
}
void Client2ServerStub::ratifyJoinTeam(const std::string& sendName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 78;
	w->writeType(pid);
	// serialize sendName
	{
		w->writeType(sendName);
	}
	methodEnd();
}
void Client2ServerStub::drawLotteryBox(BoxType type,bool isFree)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 79;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize isFree
	{
		w->writeType(isFree);
	}
	methodEnd();
}
void Client2ServerStub::acceptQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 80;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void Client2ServerStub::submitQuest(int32_t npcId,int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 81;
	w->writeType(pid);
	// serialize npcId
	{
		w->writeType(npcId);
	}
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void Client2ServerStub::giveupQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 82;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void Client2ServerStub::requestContactInfoById(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 83;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::requestContactInfoByName(const std::string& instName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 84;
	w->writeType(pid);
	// serialize instName
	{
		w->writeType(instName);
	}
	methodEnd();
}
void Client2ServerStub::requestFriendList()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 85;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::addFriend(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 86;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::delFriend(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 87;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::addBlacklist(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 88;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::delBlacklist(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 89;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::requestReferrFriend()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 90;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::mining(int32_t gatherId,int32_t times)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 91;
	w->writeType(pid);
	// serialize gatherId
	{
		w->writeType(gatherId);
	}
	// serialize times
	{
		w->writeType(times);
	}
	methodEnd();
}
void Client2ServerStub::compoundItem(int32_t itemId,int32_t gemId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 92;
	w->writeType(pid);
	// serialize itemId
	{
		w->writeType(itemId);
	}
	// serialize gemId
	{
		w->writeType(gemId);
	}
	methodEnd();
}
void Client2ServerStub::bagItemSplit(int32_t instId,int32_t splitNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 93;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize splitNum
	{
		w->writeType(splitNum);
	}
	methodEnd();
}
void Client2ServerStub::requestChallenge(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 94;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Client2ServerStub::requestRival()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 95;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestMySelfJJCData()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 96;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestCheckMsg(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 97;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Client2ServerStub::requestMyAllbattleMsg()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 98;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestJJCRank()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 99;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestLevelRank()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 100;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestBabyRank()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 101;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestEmpRank()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 102;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestPlayerFFRank()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 103;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::queryOnlinePlayerbyName(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 104;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Client2ServerStub::queryPlayerbyName(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 105;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Client2ServerStub::queryBaby(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 106;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::queryEmployee(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 107;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::guideFinish(uint64_t guideIdx)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 108;
	w->writeType(pid);
	// serialize guideIdx
	{
		w->writeType(guideIdx);
	}
	methodEnd();
}
void Client2ServerStub::enterBattle(int32_t battleId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 109;
	w->writeType(pid);
	// serialize battleId
	{
		w->writeType(battleId);
	}
	methodEnd();
}
void Client2ServerStub::shopBuyItem(int32_t id,int32_t num)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 110;
	w->writeType(pid);
	// serialize id
	{
		w->writeType(id);
	}
	// serialize num
	{
		w->writeType(num);
	}
	methodEnd();
}
void Client2ServerStub::getFirstRechargeItem()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 111;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestLevelGift(int32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 112;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Client2ServerStub::setCurrentTitle(int32_t title)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 113;
	w->writeType(pid);
	// serialize title
	{
		w->writeType(title);
	}
	methodEnd();
}
void Client2ServerStub::openBuyBox()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 114;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestAchaward(int32_t achId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 115;
	w->writeType(pid);
	// serialize achId
	{
		w->writeType(achId);
	}
	methodEnd();
}
void Client2ServerStub::sign(int32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 116;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestSignupReward7()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 117;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestSignupReward14()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 118;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestSignupReward28()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 119;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestActivityReward(int32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 120;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::resetHundredTier()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 121;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::enterHundredScene(int32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 122;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Client2ServerStub::delBaby(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 123;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::resetBaby(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 124;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::resetBabyProp(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 125;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::remouldBaby(int32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 126;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Client2ServerStub::empSkillLevelUp(uint32_t empId,int32_t skillId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 127;
	w->writeType(pid);
	// serialize empId
	{
		w->writeType(empId);
	}
	// serialize skillId
	{
		w->writeType(skillId);
	}
	methodEnd();
}
void Client2ServerStub::setOpenDoubleTimeFlag(bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 128;
	w->writeType(pid);
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void Client2ServerStub::talkedNpc(int32_t npcId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 129;
	w->writeType(pid);
	// serialize npcId
	{
		w->writeType(npcId);
	}
	methodEnd();
}
void Client2ServerStub::jjcBattleGo(uint32_t id)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 130;
	w->writeType(pid);
	// serialize id
	{
		w->writeType(id);
	}
	methodEnd();
}
void Client2ServerStub::requestMyJJCTeamMsg()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 131;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::startMatching()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 132;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::stopMatching()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 133;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::exitPvpJJC()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 134;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::joinPvpLobby()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 135;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::exitPvpLobby()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 136;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestpvprank()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 137;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::joinWarriorchoose()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 138;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::warriorStart()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 139;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::warriorStop()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 140;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::sendMail(const std::string& playername,const std::string& title,const std::string& content)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 141;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize title
	{
		w->writeType(title);
	}
	// serialize content
	{
		w->writeType(content);
	}
	methodEnd();
}
void Client2ServerStub::readMail(int32_t mailId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 142;
	w->writeType(pid);
	// serialize mailId
	{
		w->writeType(mailId);
	}
	methodEnd();
}
void Client2ServerStub::delMail(int32_t mailId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 143;
	w->writeType(pid);
	// serialize mailId
	{
		w->writeType(mailId);
	}
	methodEnd();
}
void Client2ServerStub::getMailItem(int32_t mailId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 144;
	w->writeType(pid);
	// serialize mailId
	{
		w->writeType(mailId);
	}
	methodEnd();
}
void Client2ServerStub::requestState()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 145;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::createGuild(const std::string& guildName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 146;
	w->writeType(pid);
	// serialize guildName
	{
		w->writeType(guildName);
	}
	methodEnd();
}
void Client2ServerStub::delGuild(uint32_t guildId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 147;
	w->writeType(pid);
	// serialize guildId
	{
		w->writeType(guildId);
	}
	methodEnd();
}
void Client2ServerStub::requestJoinGuild(uint32_t guid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 148;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	methodEnd();
}
void Client2ServerStub::leaveGuild()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 149;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::kickOut(int32_t guid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 150;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	methodEnd();
}
void Client2ServerStub::acceptRequestGuild(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 151;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Client2ServerStub::refuseRequestGuild(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 152;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Client2ServerStub::changeMemberPosition(int32_t targetId,GuildJob job)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 153;
	w->writeType(pid);
	// serialize targetId
	{
		w->writeType(targetId);
	}
	// serialize job
	{
		uint8_t __e__ = (uint8_t)job;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::transferPremier(int32_t targetId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 154;
	w->writeType(pid);
	// serialize targetId
	{
		w->writeType(targetId);
	}
	methodEnd();
}
void Client2ServerStub::changeGuildNotice(const std::string& notice)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 155;
	w->writeType(pid);
	// serialize notice
	{
		w->writeType(notice);
	}
	methodEnd();
}
void Client2ServerStub::queryGuildList(int16_t page)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 156;
	w->writeType(pid);
	// serialize page
	{
		w->writeType(page);
	}
	methodEnd();
}
void Client2ServerStub::inviteJoinGuild(const std::string& playerName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 157;
	w->writeType(pid);
	// serialize playerName
	{
		w->writeType(playerName);
	}
	methodEnd();
}
void Client2ServerStub::respondInviteJoinGuild(const std::string& sendName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 158;
	w->writeType(pid);
	// serialize sendName
	{
		w->writeType(sendName);
	}
	methodEnd();
}
void Client2ServerStub::buyGuildItem(int32_t tableId,int32_t times)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 159;
	w->writeType(pid);
	// serialize tableId
	{
		w->writeType(tableId);
	}
	// serialize times
	{
		w->writeType(times);
	}
	methodEnd();
}
void Client2ServerStub::entryGuildBattle()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 160;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::transforGuildBattleScene()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 161;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::addGuildMoney(int32_t money)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 162;
	w->writeType(pid);
	// serialize money
	{
		w->writeType(money);
	}
	methodEnd();
}
void Client2ServerStub::updateGuildBuiling(GuildBuildingType gbt)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 163;
	w->writeType(pid);
	// serialize gbt
	{
		uint8_t __e__ = (uint8_t)gbt;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::refreshGuildShop()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 164;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::levelupGuildSkill(int32_t skId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 165;
	w->writeType(pid);
	// serialize skId
	{
		w->writeType(skId);
	}
	methodEnd();
}
void Client2ServerStub::presentGuildItem(int32_t num)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 166;
	w->writeType(pid);
	// serialize num
	{
		w->writeType(num);
	}
	methodEnd();
}
void Client2ServerStub::progenitusAddExp(int32_t monsterId,bool isSuper)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 167;
	w->writeType(pid);
	// serialize monsterId
	{
		w->writeType(monsterId);
	}
	// serialize isSuper
	{
		w->writeType(isSuper);
	}
	methodEnd();
}
void Client2ServerStub::setProgenitusPosition(int32_t mId,int32_t pos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 168;
	w->writeType(pid);
	// serialize mId
	{
		w->writeType(mId);
	}
	// serialize pos
	{
		w->writeType(pos);
	}
	methodEnd();
}
void Client2ServerStub::guildsign()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 169;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::fetchSelling(const COM_SearchContext& context)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 170;
	w->writeType(pid);
	// serialize context
	{
		context.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::fetchSelling2(const COM_SearchContext& context)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 171;
	w->writeType(pid);
	// serialize context
	{
		context.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::selling(int32_t iteminstid,int32_t babyinstid,int32_t price)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 172;
	w->writeType(pid);
	// serialize iteminstid
	{
		w->writeType(iteminstid);
	}
	// serialize babyinstid
	{
		w->writeType(babyinstid);
	}
	// serialize price
	{
		w->writeType(price);
	}
	methodEnd();
}
void Client2ServerStub::unselling(int32_t sellid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 173;
	w->writeType(pid);
	// serialize sellid
	{
		w->writeType(sellid);
	}
	methodEnd();
}
void Client2ServerStub::buy(int32_t sellid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 174;
	w->writeType(pid);
	// serialize sellid
	{
		w->writeType(sellid);
	}
	methodEnd();
}
void Client2ServerStub::fixItem(int32_t instId,FixType type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 175;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::fixAllItem(const std::vector< uint32_t >& items,FixType type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 176;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(items[i]);
		}
	}
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::makeDebirsItem(int32_t instId,int32_t num)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 177;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize num
	{
		w->writeType(num);
	}
	methodEnd();
}
void Client2ServerStub::levelUpMagicItem(const std::vector< uint32_t >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 178;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(items[i]);
		}
	}
	methodEnd();
}
void Client2ServerStub::tupoMagicItem(int32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 179;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Client2ServerStub::changeMagicJob(JobType job)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 180;
	w->writeType(pid);
	// serialize job
	{
		uint8_t __e__ = (uint8_t)job;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::requestPk(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 181;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Client2ServerStub::uiBehavior(UIBehaviorType type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 182;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void Client2ServerStub::openZhuanpan()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 183;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::zhuanpanGo(uint32_t counter)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 184;
	w->writeType(pid);
	// serialize counter
	{
		w->writeType(counter);
	}
	methodEnd();
}
void Client2ServerStub::redemptionSpree(const std::string& code)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 185;
	w->writeType(pid);
	// serialize code
	{
		w->writeType(code);
	}
	methodEnd();
}
void Client2ServerStub::sceneFilter(const std::vector< SceneFilterType >& sfType)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 186;
	w->writeType(pid);
	// serialize sfType
	{
		uint32_t __len__ = (uint32_t)sfType.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			uint8_t __e__ = (uint8_t)sfType[i];
			w->writeType(__e__);
		}
	}
	methodEnd();
}
void Client2ServerStub::sendExamAnswer(uint32_t questionId,uint8_t answer)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 187;
	w->writeType(pid);
	// serialize questionId
	{
		w->writeType(questionId);
	}
	// serialize answer
	{
		w->writeType(answer);
	}
	methodEnd();
}
void Client2ServerStub::sendwishing(const COM_Wishing& wish)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 188;
	w->writeType(pid);
	// serialize wish
	{
		wish.serialize(w);
	}
	methodEnd();
}
void Client2ServerStub::requestWish()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 189;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::leaderCloseDialog()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 190;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestOnlineReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 191;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestFundReward(uint32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 192;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Client2ServerStub::openCard(uint16_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 193;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::resetCard()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 194;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::hotRoleBuy()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 195;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestSevenReward(uint32_t qid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 196;
	w->writeType(pid);
	// serialize qid
	{
		w->writeType(qid);
	}
	methodEnd();
}
void Client2ServerStub::vipreward()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 197;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::requestChargeTotalSingleReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 198;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestChargeTotalReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 199;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestChargeEverySingleReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 200;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestChargeEveryReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 201;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestLoginTotal(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 202;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::buyDiscountStoreSingle(int32_t itemId,int32_t itemStack)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 203;
	w->writeType(pid);
	// serialize itemId
	{
		w->writeType(itemId);
	}
	// serialize itemStack
	{
		w->writeType(itemStack);
	}
	methodEnd();
}
void Client2ServerStub::buyDiscountStore(int32_t itemId,int32_t itemStack)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 204;
	w->writeType(pid);
	// serialize itemId
	{
		w->writeType(itemId);
	}
	// serialize itemStack
	{
		w->writeType(itemStack);
	}
	methodEnd();
}
void Client2ServerStub::requestEmployeeActivityReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 205;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestmyselfrechargeleReward(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 206;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Client2ServerStub::requestEverydayIntegral()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 207;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::buyIntegralItem(uint32_t id,uint32_t num)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 208;
	w->writeType(pid);
	// serialize id
	{
		w->writeType(id);
	}
	// serialize num
	{
		w->writeType(num);
	}
	methodEnd();
}
void Client2ServerStub::familyLoseLeader()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 209;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::verificationSMS(const std::string& phoneNumber,const std::string& code)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 210;
	w->writeType(pid);
	// serialize phoneNumber
	{
		w->writeType(phoneNumber);
	}
	// serialize code
	{
		w->writeType(code);
	}
	methodEnd();
}
void Client2ServerStub::lockItem(int32_t instId,bool isLock)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 211;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize isLock
	{
		w->writeType(isLock);
	}
	methodEnd();
}
void Client2ServerStub::lockBaby(int32_t instId,bool isLock)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 212;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize isLock
	{
		w->writeType(isLock);
	}
	methodEnd();
}
void Client2ServerStub::showBaby(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 213;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Client2ServerStub::wearFuwen(int32_t itemInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 214;
	w->writeType(pid);
	// serialize itemInstId
	{
		w->writeType(itemInstId);
	}
	methodEnd();
}
void Client2ServerStub::takeoffFuwen(int32_t slotId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 215;
	w->writeType(pid);
	// serialize slotId
	{
		w->writeType(slotId);
	}
	methodEnd();
}
void Client2ServerStub::compFuwen(int32_t itemInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 216;
	w->writeType(pid);
	// serialize itemInstId
	{
		w->writeType(itemInstId);
	}
	methodEnd();
}
void Client2ServerStub::requestEmployeeQuest()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 217;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::acceptEmployeeQuest(int32_t questId,const std::vector< int32_t >& employees)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 218;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	// serialize employees
	{
		uint32_t __len__ = (uint32_t)employees.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(employees[i]);
		}
	}
	methodEnd();
}
void Client2ServerStub::submitEmployeeQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 219;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void Client2ServerStub::crystalUpLevel()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 220;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::resetCrystalProp(const std::vector< int32_t >& locklist)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 221;
	w->writeType(pid);
	// serialize locklist
	{
		uint32_t __len__ = (uint32_t)locklist.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(locklist[i]);
		}
	}
	methodEnd();
}
void Client2ServerStub::magicItemOneKeyLevel()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 222;
	w->writeType(pid);
	methodEnd();
}
void Client2ServerStub::submitQuest2(int32_t npcId,int32_t questId,int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 223;
	w->writeType(pid);
	// serialize npcId
	{
		w->writeType(npcId);
	}
	// serialize questId
	{
		w->writeType(questId);
	}
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
bool Client2ServerProxy::openvip(ProtocolReader* __r__)
{
	VipLevel vl=(VipLevel)(0);
	// deserialize vl
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 4) return false;
		vl = (VipLevel)__e__;
	}
	return openvip(vl);
}
bool Client2ServerProxy::requestPhoto(ProtocolReader* __r__)
{
	return requestPhoto();
}
bool Client2ServerProxy::ping(ProtocolReader* __r__)
{
	return ping();
}
bool Client2ServerProxy::sessionlogin(ProtocolReader* __r__)
{
	COM_LoginInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return sessionlogin(info);
}
bool Client2ServerProxy::login(ProtocolReader* __r__)
{
	COM_LoginInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return login(info);
}
bool Client2ServerProxy::createPlayer(ProtocolReader* __r__)
{
	std::string playername;
	uint8_t playerTmpId=0;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize playerTmpId
	{
		if(!__r__->readType(playerTmpId)) return false;
	}
	return createPlayer(playername,playerTmpId);
}
bool Client2ServerProxy::deletePlayer(ProtocolReader* __r__)
{
	std::string playername;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	return deletePlayer(playername);
}
bool Client2ServerProxy::enterGame(ProtocolReader* __r__)
{
	uint32_t playerInstId=0;
	// deserialize playerInstId
	{
		if(!__r__->readType(playerInstId)) return false;
	}
	return enterGame(playerInstId);
}
bool Client2ServerProxy::requestBag(ProtocolReader* __r__)
{
	return requestBag();
}
bool Client2ServerProxy::requestEmployees(ProtocolReader* __r__)
{
	return requestEmployees();
}
bool Client2ServerProxy::requestStorage(ProtocolReader* __r__)
{
	StorageType tp=(StorageType)(0);
	// deserialize tp
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 2) return false;
		tp = (StorageType)__e__;
	}
	return requestStorage(tp);
}
bool Client2ServerProxy::requestAchievement(ProtocolReader* __r__)
{
	return requestAchievement();
}
bool Client2ServerProxy::initminig(ProtocolReader* __r__)
{
	return initminig();
}
bool Client2ServerProxy::requestCompound(ProtocolReader* __r__)
{
	return requestCompound();
}
bool Client2ServerProxy::move(ProtocolReader* __r__)
{
	float x=0;
	float z=0;
	// deserialize x
	{
		if(!__r__->readType(x)) return false;
	}
	// deserialize z
	{
		if(!__r__->readType(z)) return false;
	}
	return move(x,z);
}
bool Client2ServerProxy::moveToNpc(ProtocolReader* __r__)
{
	int32_t npcid=0;
	// deserialize npcid
	{
		if(!__r__->readType(npcid)) return false;
	}
	return moveToNpc(npcid);
}
bool Client2ServerProxy::moveToNpc2(ProtocolReader* __r__)
{
	NpcType type=(NpcType)(0);
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 11) return false;
		type = (NpcType)__e__;
	}
	return moveToNpc2(type);
}
bool Client2ServerProxy::moveToZone(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	int32_t zoneId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	// deserialize zoneId
	{
		if(!__r__->readType(zoneId)) return false;
	}
	return moveToZone(sceneId,zoneId);
}
bool Client2ServerProxy::autoBattle(ProtocolReader* __r__)
{
	return autoBattle();
}
bool Client2ServerProxy::stopAutoBattle(ProtocolReader* __r__)
{
	return stopAutoBattle();
}
bool Client2ServerProxy::stopMove(ProtocolReader* __r__)
{
	return stopMove();
}
bool Client2ServerProxy::exitCopy(ProtocolReader* __r__)
{
	return exitCopy();
}
bool Client2ServerProxy::transforScene(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	return transforScene(sceneId);
}
bool Client2ServerProxy::sceneLoaded(ProtocolReader* __r__)
{
	return sceneLoaded();
}
bool Client2ServerProxy::querySimplePlayerInst(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return querySimplePlayerInst(instId);
}
bool Client2ServerProxy::logout(ProtocolReader* __r__)
{
	return logout();
}
bool Client2ServerProxy::changProp(ProtocolReader* __r__)
{
	uint32_t guid=0;
	std::vector< COM_Addprop > props;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	// deserialize props
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		props.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!props[i].deserialize(__r__)) return false;
		}
	}
	return changProp(guid,props);
}
bool Client2ServerProxy::learnSkill(ProtocolReader* __r__)
{
	uint32_t skid=0;
	// deserialize skid
	{
		if(!__r__->readType(skid)) return false;
	}
	return learnSkill(skid);
}
bool Client2ServerProxy::babyLearnSkill(ProtocolReader* __r__)
{
	uint32_t instId=0;
	uint32_t oldSkId=0;
	uint32_t newSkId=0;
	uint32_t newSkLv=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize oldSkId
	{
		if(!__r__->readType(oldSkId)) return false;
	}
	// deserialize newSkId
	{
		if(!__r__->readType(newSkId)) return false;
	}
	// deserialize newSkLv
	{
		if(!__r__->readType(newSkLv)) return false;
	}
	return babyLearnSkill(instId,oldSkId,newSkId,newSkLv);
}
bool Client2ServerProxy::forgetSkill(ProtocolReader* __r__)
{
	uint32_t skid=0;
	// deserialize skid
	{
		if(!__r__->readType(skid)) return false;
	}
	return forgetSkill(skid);
}
bool Client2ServerProxy::syncOrder(ProtocolReader* __r__)
{
	COM_Order order;
	// deserialize order
	{
		if(!order.deserialize(__r__)) return false;
	}
	return syncOrder(order);
}
bool Client2ServerProxy::syncOrderTimeout(ProtocolReader* __r__)
{
	return syncOrderTimeout();
}
bool Client2ServerProxy::sendChat(ProtocolReader* __r__)
{
	COM_Chat content;
	std::string targetName;
	// deserialize content
	{
		if(!content.deserialize(__r__)) return false;
	}
	// deserialize targetName
	{
		if(!__r__->readType(targetName, 65535)) return false;
	}
	return sendChat(content,targetName);
}
bool Client2ServerProxy::requestAudio(ProtocolReader* __r__)
{
	int32_t audioId=0;
	// deserialize audioId
	{
		if(!__r__->readType(audioId)) return false;
	}
	return requestAudio(audioId);
}
bool Client2ServerProxy::publishItemInst(ProtocolReader* __r__)
{
	ItemContainerType type=(ItemContainerType)(0);
	uint32_t itemInstId=0;
	ChatKind chatType=(ChatKind)(0);
	std::string playerName;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 2) return false;
		type = (ItemContainerType)__e__;
	}
	// deserialize itemInstId
	{
		if(!__r__->readType(itemInstId)) return false;
	}
	// deserialize chatType
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 8) return false;
		chatType = (ChatKind)__e__;
	}
	// deserialize playerName
	{
		if(!__r__->readType(playerName, 65535)) return false;
	}
	return publishItemInst(type,itemInstId,chatType,playerName);
}
bool Client2ServerProxy::queryItemInst(ProtocolReader* __r__)
{
	int32_t showId=0;
	// deserialize showId
	{
		if(!__r__->readType(showId)) return false;
	}
	return queryItemInst(showId);
}
bool Client2ServerProxy::publishbabyInst(ProtocolReader* __r__)
{
	ChatKind type=(ChatKind)(0);
	uint32_t babyInstId=0;
	std::string playerName;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 8) return false;
		type = (ChatKind)__e__;
	}
	// deserialize babyInstId
	{
		if(!__r__->readType(babyInstId)) return false;
	}
	// deserialize playerName
	{
		if(!__r__->readType(playerName, 65535)) return false;
	}
	return publishbabyInst(type,babyInstId,playerName);
}
bool Client2ServerProxy::querybabyInst(ProtocolReader* __r__)
{
	int32_t showId=0;
	// deserialize showId
	{
		if(!__r__->readType(showId)) return false;
	}
	return querybabyInst(showId);
}
bool Client2ServerProxy::useItem(ProtocolReader* __r__)
{
	uint32_t slot=0;
	uint32_t target=0;
	uint32_t stack=0;
	// deserialize slot
	{
		if(!__r__->readType(slot)) return false;
	}
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize stack
	{
		if(!__r__->readType(stack)) return false;
	}
	return useItem(slot,target,stack);
}
bool Client2ServerProxy::wearEquipment(ProtocolReader* __r__)
{
	uint32_t target=0;
	uint32_t itemInstId=0;
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize itemInstId
	{
		if(!__r__->readType(itemInstId)) return false;
	}
	return wearEquipment(target,itemInstId);
}
bool Client2ServerProxy::delEquipment(ProtocolReader* __r__)
{
	uint32_t target=0;
	uint32_t itemInstId=0;
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize itemInstId
	{
		if(!__r__->readType(itemInstId)) return false;
	}
	return delEquipment(target,itemInstId);
}
bool Client2ServerProxy::setPlayerFront(ProtocolReader* __r__)
{
	bool isFront=false;
	// deserialize isFront
	{
		if(!__r__->readType(isFront)) return false;
	}
	return setPlayerFront(isFront);
}
bool Client2ServerProxy::setBattlebaby(ProtocolReader* __r__)
{
	uint32_t babyID=0;
	bool isBattle=false;
	// deserialize babyID
	{
		if(!__r__->readType(babyID)) return false;
	}
	// deserialize isBattle
	{
		if(!__r__->readType(isBattle)) return false;
	}
	return setBattlebaby(babyID,isBattle);
}
bool Client2ServerProxy::changeBabyName(ProtocolReader* __r__)
{
	uint32_t babyID=0;
	std::string name;
	// deserialize babyID
	{
		if(!__r__->readType(babyID)) return false;
	}
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return changeBabyName(babyID,name);
}
bool Client2ServerProxy::intensifyBaby(ProtocolReader* __r__)
{
	uint32_t babyid=0;
	// deserialize babyid
	{
		if(!__r__->readType(babyid)) return false;
	}
	return intensifyBaby(babyid);
}
bool Client2ServerProxy::setBattleEmp(ProtocolReader* __r__)
{
	uint32_t empID=0;
	EmployeesBattleGroup group=(EmployeesBattleGroup)(0);
	bool isBattle=false;
	// deserialize empID
	{
		if(!__r__->readType(empID)) return false;
	}
	// deserialize group
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 5) return false;
		group = (EmployeesBattleGroup)__e__;
	}
	// deserialize isBattle
	{
		if(!__r__->readType(isBattle)) return false;
	}
	return setBattleEmp(empID,group,isBattle);
}
bool Client2ServerProxy::changeEmpBattleGroup(ProtocolReader* __r__)
{
	EmployeesBattleGroup group=(EmployeesBattleGroup)(0);
	// deserialize group
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 5) return false;
		group = (EmployeesBattleGroup)__e__;
	}
	return changeEmpBattleGroup(group);
}
bool Client2ServerProxy::requestEvolve(ProtocolReader* __r__)
{
	uint32_t empInstId=0;
	// deserialize empInstId
	{
		if(!__r__->readType(empInstId)) return false;
	}
	return requestEvolve(empInstId);
}
bool Client2ServerProxy::requestUpStar(ProtocolReader* __r__)
{
	uint32_t empInstId=0;
	// deserialize empInstId
	{
		if(!__r__->readType(empInstId)) return false;
	}
	return requestUpStar(empInstId);
}
bool Client2ServerProxy::requestDelEmp(ProtocolReader* __r__)
{
	uint32_t empInstId=0;
	// deserialize empInstId
	{
		if(!__r__->readType(empInstId)) return false;
	}
	return requestDelEmp(empInstId);
}
bool Client2ServerProxy::delEmployee(ProtocolReader* __r__)
{
	std::vector< uint32_t > emps;
	// deserialize emps
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		emps.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(emps[i])) return false;
		}
	}
	return delEmployee(emps);
}
bool Client2ServerProxy::onekeyDelEmp(ProtocolReader* __r__)
{
	return onekeyDelEmp();
}
bool Client2ServerProxy::delEmployeeSoul(ProtocolReader* __r__)
{
	uint32_t instid=0;
	uint32_t soulNum=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	// deserialize soulNum
	{
		if(!__r__->readType(soulNum)) return false;
	}
	return delEmployeeSoul(instid,soulNum);
}
bool Client2ServerProxy::sortBagItem(ProtocolReader* __r__)
{
	return sortBagItem();
}
bool Client2ServerProxy::sellBagItem(ProtocolReader* __r__)
{
	uint32_t instId=0;
	uint32_t stack=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize stack
	{
		if(!__r__->readType(stack)) return false;
	}
	return sellBagItem(instId,stack);
}
bool Client2ServerProxy::depositItemToStorage(ProtocolReader* __r__)
{
	uint32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return depositItemToStorage(instid);
}
bool Client2ServerProxy::depositBabyToStorage(ProtocolReader* __r__)
{
	uint32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return depositBabyToStorage(instid);
}
bool Client2ServerProxy::storageItemToBag(ProtocolReader* __r__)
{
	uint32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return storageItemToBag(instid);
}
bool Client2ServerProxy::storageBabyToPlayer(ProtocolReader* __r__)
{
	uint32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return storageBabyToPlayer(instid);
}
bool Client2ServerProxy::sortStorage(ProtocolReader* __r__)
{
	StorageType tp=(StorageType)(0);
	// deserialize tp
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 2) return false;
		tp = (StorageType)__e__;
	}
	return sortStorage(tp);
}
bool Client2ServerProxy::delStorageBaby(ProtocolReader* __r__)
{
	uint32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return delStorageBaby(instid);
}
bool Client2ServerProxy::jointLobby(ProtocolReader* __r__)
{
	return jointLobby();
}
bool Client2ServerProxy::exitLobby(ProtocolReader* __r__)
{
	return exitLobby();
}
bool Client2ServerProxy::createTeam(ProtocolReader* __r__)
{
	COM_CreateTeamInfo cti;
	// deserialize cti
	{
		if(!cti.deserialize(__r__)) return false;
	}
	return createTeam(cti);
}
bool Client2ServerProxy::changeTeam(ProtocolReader* __r__)
{
	COM_CreateTeamInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return changeTeam(info);
}
bool Client2ServerProxy::kickTeamMember(ProtocolReader* __r__)
{
	uint32_t uuid=0;
	// deserialize uuid
	{
		if(!__r__->readType(uuid)) return false;
	}
	return kickTeamMember(uuid);
}
bool Client2ServerProxy::changeTeamLeader(ProtocolReader* __r__)
{
	uint32_t uuid=0;
	// deserialize uuid
	{
		if(!__r__->readType(uuid)) return false;
	}
	return changeTeamLeader(uuid);
}
bool Client2ServerProxy::joinTeam(ProtocolReader* __r__)
{
	uint32_t teamId=0;
	std::string pwd;
	// deserialize teamId
	{
		if(!__r__->readType(teamId)) return false;
	}
	// deserialize pwd
	{
		if(!__r__->readType(pwd, 65535)) return false;
	}
	return joinTeam(teamId,pwd);
}
bool Client2ServerProxy::exitTeam(ProtocolReader* __r__)
{
	return exitTeam();
}
bool Client2ServerProxy::changeTeamPassword(ProtocolReader* __r__)
{
	std::string pwd;
	// deserialize pwd
	{
		if(!__r__->readType(pwd, 65535)) return false;
	}
	return changeTeamPassword(pwd);
}
bool Client2ServerProxy::joinTeamRoom(ProtocolReader* __r__)
{
	return joinTeamRoom();
}
bool Client2ServerProxy::inviteTeamMember(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return inviteTeamMember(name);
}
bool Client2ServerProxy::isjoinTeam(ProtocolReader* __r__)
{
	uint32_t teamId=0;
	bool isFlag=false;
	// deserialize teamId
	{
		if(!__r__->readType(teamId)) return false;
	}
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return isjoinTeam(teamId,isFlag);
}
bool Client2ServerProxy::leaveTeam(ProtocolReader* __r__)
{
	return leaveTeam();
}
bool Client2ServerProxy::backTeam(ProtocolReader* __r__)
{
	return backTeam();
}
bool Client2ServerProxy::refuseBackTeam(ProtocolReader* __r__)
{
	return refuseBackTeam();
}
bool Client2ServerProxy::teamCallMember(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return teamCallMember(playerId);
}
bool Client2ServerProxy::requestJoinTeam(ProtocolReader* __r__)
{
	std::string targetName;
	// deserialize targetName
	{
		if(!__r__->readType(targetName, 65535)) return false;
	}
	return requestJoinTeam(targetName);
}
bool Client2ServerProxy::ratifyJoinTeam(ProtocolReader* __r__)
{
	std::string sendName;
	// deserialize sendName
	{
		if(!__r__->readType(sendName, 65535)) return false;
	}
	return ratifyJoinTeam(sendName);
}
bool Client2ServerProxy::drawLotteryBox(ProtocolReader* __r__)
{
	BoxType type=(BoxType)(0);
	bool isFree=false;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 4) return false;
		type = (BoxType)__e__;
	}
	// deserialize isFree
	{
		if(!__r__->readType(isFree)) return false;
	}
	return drawLotteryBox(type,isFree);
}
bool Client2ServerProxy::acceptQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return acceptQuest(questId);
}
bool Client2ServerProxy::submitQuest(ProtocolReader* __r__)
{
	int32_t npcId=0;
	int32_t questId=0;
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return submitQuest(npcId,questId);
}
bool Client2ServerProxy::giveupQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return giveupQuest(questId);
}
bool Client2ServerProxy::requestContactInfoById(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return requestContactInfoById(instId);
}
bool Client2ServerProxy::requestContactInfoByName(ProtocolReader* __r__)
{
	std::string instName;
	// deserialize instName
	{
		if(!__r__->readType(instName, 65535)) return false;
	}
	return requestContactInfoByName(instName);
}
bool Client2ServerProxy::requestFriendList(ProtocolReader* __r__)
{
	return requestFriendList();
}
bool Client2ServerProxy::addFriend(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return addFriend(instId);
}
bool Client2ServerProxy::delFriend(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delFriend(instId);
}
bool Client2ServerProxy::addBlacklist(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return addBlacklist(instId);
}
bool Client2ServerProxy::delBlacklist(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delBlacklist(instId);
}
bool Client2ServerProxy::requestReferrFriend(ProtocolReader* __r__)
{
	return requestReferrFriend();
}
bool Client2ServerProxy::mining(ProtocolReader* __r__)
{
	int32_t gatherId=0;
	int32_t times=0;
	// deserialize gatherId
	{
		if(!__r__->readType(gatherId)) return false;
	}
	// deserialize times
	{
		if(!__r__->readType(times)) return false;
	}
	return mining(gatherId,times);
}
bool Client2ServerProxy::compoundItem(ProtocolReader* __r__)
{
	int32_t itemId=0;
	int32_t gemId=0;
	// deserialize itemId
	{
		if(!__r__->readType(itemId)) return false;
	}
	// deserialize gemId
	{
		if(!__r__->readType(gemId)) return false;
	}
	return compoundItem(itemId,gemId);
}
bool Client2ServerProxy::bagItemSplit(ProtocolReader* __r__)
{
	int32_t instId=0;
	int32_t splitNum=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize splitNum
	{
		if(!__r__->readType(splitNum)) return false;
	}
	return bagItemSplit(instId,splitNum);
}
bool Client2ServerProxy::requestChallenge(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return requestChallenge(name);
}
bool Client2ServerProxy::requestRival(ProtocolReader* __r__)
{
	return requestRival();
}
bool Client2ServerProxy::requestMySelfJJCData(ProtocolReader* __r__)
{
	return requestMySelfJJCData();
}
bool Client2ServerProxy::requestCheckMsg(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return requestCheckMsg(name);
}
bool Client2ServerProxy::requestMyAllbattleMsg(ProtocolReader* __r__)
{
	return requestMyAllbattleMsg();
}
bool Client2ServerProxy::requestJJCRank(ProtocolReader* __r__)
{
	return requestJJCRank();
}
bool Client2ServerProxy::requestLevelRank(ProtocolReader* __r__)
{
	return requestLevelRank();
}
bool Client2ServerProxy::requestBabyRank(ProtocolReader* __r__)
{
	return requestBabyRank();
}
bool Client2ServerProxy::requestEmpRank(ProtocolReader* __r__)
{
	return requestEmpRank();
}
bool Client2ServerProxy::requestPlayerFFRank(ProtocolReader* __r__)
{
	return requestPlayerFFRank();
}
bool Client2ServerProxy::queryOnlinePlayerbyName(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return queryOnlinePlayerbyName(name);
}
bool Client2ServerProxy::queryPlayerbyName(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return queryPlayerbyName(name);
}
bool Client2ServerProxy::queryBaby(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return queryBaby(instId);
}
bool Client2ServerProxy::queryEmployee(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return queryEmployee(instId);
}
bool Client2ServerProxy::guideFinish(ProtocolReader* __r__)
{
	uint64_t guideIdx=0;
	// deserialize guideIdx
	{
		if(!__r__->readType(guideIdx)) return false;
	}
	return guideFinish(guideIdx);
}
bool Client2ServerProxy::enterBattle(ProtocolReader* __r__)
{
	int32_t battleId=0;
	// deserialize battleId
	{
		if(!__r__->readType(battleId)) return false;
	}
	return enterBattle(battleId);
}
bool Client2ServerProxy::shopBuyItem(ProtocolReader* __r__)
{
	int32_t id=0;
	int32_t num=0;
	// deserialize id
	{
		if(!__r__->readType(id)) return false;
	}
	// deserialize num
	{
		if(!__r__->readType(num)) return false;
	}
	return shopBuyItem(id,num);
}
bool Client2ServerProxy::getFirstRechargeItem(ProtocolReader* __r__)
{
	return getFirstRechargeItem();
}
bool Client2ServerProxy::requestLevelGift(ProtocolReader* __r__)
{
	int32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return requestLevelGift(level);
}
bool Client2ServerProxy::setCurrentTitle(ProtocolReader* __r__)
{
	int32_t title=0;
	// deserialize title
	{
		if(!__r__->readType(title)) return false;
	}
	return setCurrentTitle(title);
}
bool Client2ServerProxy::openBuyBox(ProtocolReader* __r__)
{
	return openBuyBox();
}
bool Client2ServerProxy::requestAchaward(ProtocolReader* __r__)
{
	int32_t achId=0;
	// deserialize achId
	{
		if(!__r__->readType(achId)) return false;
	}
	return requestAchaward(achId);
}
bool Client2ServerProxy::sign(ProtocolReader* __r__)
{
	int32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return sign(index);
}
bool Client2ServerProxy::requestSignupReward7(ProtocolReader* __r__)
{
	return requestSignupReward7();
}
bool Client2ServerProxy::requestSignupReward14(ProtocolReader* __r__)
{
	return requestSignupReward14();
}
bool Client2ServerProxy::requestSignupReward28(ProtocolReader* __r__)
{
	return requestSignupReward28();
}
bool Client2ServerProxy::requestActivityReward(ProtocolReader* __r__)
{
	int32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestActivityReward(index);
}
bool Client2ServerProxy::resetHundredTier(ProtocolReader* __r__)
{
	return resetHundredTier();
}
bool Client2ServerProxy::enterHundredScene(ProtocolReader* __r__)
{
	int32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return enterHundredScene(level);
}
bool Client2ServerProxy::delBaby(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delBaby(instId);
}
bool Client2ServerProxy::resetBaby(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return resetBaby(instId);
}
bool Client2ServerProxy::resetBabyProp(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return resetBabyProp(instId);
}
bool Client2ServerProxy::remouldBaby(ProtocolReader* __r__)
{
	int32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return remouldBaby(instid);
}
bool Client2ServerProxy::empSkillLevelUp(ProtocolReader* __r__)
{
	uint32_t empId=0;
	int32_t skillId=0;
	// deserialize empId
	{
		if(!__r__->readType(empId)) return false;
	}
	// deserialize skillId
	{
		if(!__r__->readType(skillId)) return false;
	}
	return empSkillLevelUp(empId,skillId);
}
bool Client2ServerProxy::setOpenDoubleTimeFlag(ProtocolReader* __r__)
{
	bool isFlag=false;
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return setOpenDoubleTimeFlag(isFlag);
}
bool Client2ServerProxy::talkedNpc(ProtocolReader* __r__)
{
	int32_t npcId=0;
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	return talkedNpc(npcId);
}
bool Client2ServerProxy::jjcBattleGo(ProtocolReader* __r__)
{
	uint32_t id=0;
	// deserialize id
	{
		if(!__r__->readType(id)) return false;
	}
	return jjcBattleGo(id);
}
bool Client2ServerProxy::requestMyJJCTeamMsg(ProtocolReader* __r__)
{
	return requestMyJJCTeamMsg();
}
bool Client2ServerProxy::startMatching(ProtocolReader* __r__)
{
	return startMatching();
}
bool Client2ServerProxy::stopMatching(ProtocolReader* __r__)
{
	return stopMatching();
}
bool Client2ServerProxy::exitPvpJJC(ProtocolReader* __r__)
{
	return exitPvpJJC();
}
bool Client2ServerProxy::joinPvpLobby(ProtocolReader* __r__)
{
	return joinPvpLobby();
}
bool Client2ServerProxy::exitPvpLobby(ProtocolReader* __r__)
{
	return exitPvpLobby();
}
bool Client2ServerProxy::requestpvprank(ProtocolReader* __r__)
{
	return requestpvprank();
}
bool Client2ServerProxy::joinWarriorchoose(ProtocolReader* __r__)
{
	return joinWarriorchoose();
}
bool Client2ServerProxy::warriorStart(ProtocolReader* __r__)
{
	return warriorStart();
}
bool Client2ServerProxy::warriorStop(ProtocolReader* __r__)
{
	return warriorStop();
}
bool Client2ServerProxy::sendMail(ProtocolReader* __r__)
{
	std::string playername;
	std::string title;
	std::string content;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize title
	{
		if(!__r__->readType(title, 65535)) return false;
	}
	// deserialize content
	{
		if(!__r__->readType(content, 65535)) return false;
	}
	return sendMail(playername,title,content);
}
bool Client2ServerProxy::readMail(ProtocolReader* __r__)
{
	int32_t mailId=0;
	// deserialize mailId
	{
		if(!__r__->readType(mailId)) return false;
	}
	return readMail(mailId);
}
bool Client2ServerProxy::delMail(ProtocolReader* __r__)
{
	int32_t mailId=0;
	// deserialize mailId
	{
		if(!__r__->readType(mailId)) return false;
	}
	return delMail(mailId);
}
bool Client2ServerProxy::getMailItem(ProtocolReader* __r__)
{
	int32_t mailId=0;
	// deserialize mailId
	{
		if(!__r__->readType(mailId)) return false;
	}
	return getMailItem(mailId);
}
bool Client2ServerProxy::requestState(ProtocolReader* __r__)
{
	return requestState();
}
bool Client2ServerProxy::createGuild(ProtocolReader* __r__)
{
	std::string guildName;
	// deserialize guildName
	{
		if(!__r__->readType(guildName, 65535)) return false;
	}
	return createGuild(guildName);
}
bool Client2ServerProxy::delGuild(ProtocolReader* __r__)
{
	uint32_t guildId=0;
	// deserialize guildId
	{
		if(!__r__->readType(guildId)) return false;
	}
	return delGuild(guildId);
}
bool Client2ServerProxy::requestJoinGuild(ProtocolReader* __r__)
{
	uint32_t guid=0;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	return requestJoinGuild(guid);
}
bool Client2ServerProxy::leaveGuild(ProtocolReader* __r__)
{
	return leaveGuild();
}
bool Client2ServerProxy::kickOut(ProtocolReader* __r__)
{
	int32_t guid=0;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	return kickOut(guid);
}
bool Client2ServerProxy::acceptRequestGuild(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return acceptRequestGuild(playerId);
}
bool Client2ServerProxy::refuseRequestGuild(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return refuseRequestGuild(playerId);
}
bool Client2ServerProxy::changeMemberPosition(ProtocolReader* __r__)
{
	int32_t targetId=0;
	GuildJob job=(GuildJob)(0);
	// deserialize targetId
	{
		if(!__r__->readType(targetId)) return false;
	}
	// deserialize job
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 7) return false;
		job = (GuildJob)__e__;
	}
	return changeMemberPosition(targetId,job);
}
bool Client2ServerProxy::transferPremier(ProtocolReader* __r__)
{
	int32_t targetId=0;
	// deserialize targetId
	{
		if(!__r__->readType(targetId)) return false;
	}
	return transferPremier(targetId);
}
bool Client2ServerProxy::changeGuildNotice(ProtocolReader* __r__)
{
	std::string notice;
	// deserialize notice
	{
		if(!__r__->readType(notice, 65535)) return false;
	}
	return changeGuildNotice(notice);
}
bool Client2ServerProxy::queryGuildList(ProtocolReader* __r__)
{
	int16_t page=0;
	// deserialize page
	{
		if(!__r__->readType(page)) return false;
	}
	return queryGuildList(page);
}
bool Client2ServerProxy::inviteJoinGuild(ProtocolReader* __r__)
{
	std::string playerName;
	// deserialize playerName
	{
		if(!__r__->readType(playerName, 65535)) return false;
	}
	return inviteJoinGuild(playerName);
}
bool Client2ServerProxy::respondInviteJoinGuild(ProtocolReader* __r__)
{
	std::string sendName;
	// deserialize sendName
	{
		if(!__r__->readType(sendName, 65535)) return false;
	}
	return respondInviteJoinGuild(sendName);
}
bool Client2ServerProxy::buyGuildItem(ProtocolReader* __r__)
{
	int32_t tableId=0;
	int32_t times=0;
	// deserialize tableId
	{
		if(!__r__->readType(tableId)) return false;
	}
	// deserialize times
	{
		if(!__r__->readType(times)) return false;
	}
	return buyGuildItem(tableId,times);
}
bool Client2ServerProxy::entryGuildBattle(ProtocolReader* __r__)
{
	return entryGuildBattle();
}
bool Client2ServerProxy::transforGuildBattleScene(ProtocolReader* __r__)
{
	return transforGuildBattleScene();
}
bool Client2ServerProxy::addGuildMoney(ProtocolReader* __r__)
{
	int32_t money=0;
	// deserialize money
	{
		if(!__r__->readType(money)) return false;
	}
	return addGuildMoney(money);
}
bool Client2ServerProxy::updateGuildBuiling(ProtocolReader* __r__)
{
	GuildBuildingType gbt=(GuildBuildingType)(0);
	// deserialize gbt
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 8) return false;
		gbt = (GuildBuildingType)__e__;
	}
	return updateGuildBuiling(gbt);
}
bool Client2ServerProxy::refreshGuildShop(ProtocolReader* __r__)
{
	return refreshGuildShop();
}
bool Client2ServerProxy::levelupGuildSkill(ProtocolReader* __r__)
{
	int32_t skId=0;
	// deserialize skId
	{
		if(!__r__->readType(skId)) return false;
	}
	return levelupGuildSkill(skId);
}
bool Client2ServerProxy::presentGuildItem(ProtocolReader* __r__)
{
	int32_t num=0;
	// deserialize num
	{
		if(!__r__->readType(num)) return false;
	}
	return presentGuildItem(num);
}
bool Client2ServerProxy::progenitusAddExp(ProtocolReader* __r__)
{
	int32_t monsterId=0;
	bool isSuper=false;
	// deserialize monsterId
	{
		if(!__r__->readType(monsterId)) return false;
	}
	// deserialize isSuper
	{
		if(!__r__->readType(isSuper)) return false;
	}
	return progenitusAddExp(monsterId,isSuper);
}
bool Client2ServerProxy::setProgenitusPosition(ProtocolReader* __r__)
{
	int32_t mId=0;
	int32_t pos=0;
	// deserialize mId
	{
		if(!__r__->readType(mId)) return false;
	}
	// deserialize pos
	{
		if(!__r__->readType(pos)) return false;
	}
	return setProgenitusPosition(mId,pos);
}
bool Client2ServerProxy::guildsign(ProtocolReader* __r__)
{
	return guildsign();
}
bool Client2ServerProxy::fetchSelling(ProtocolReader* __r__)
{
	COM_SearchContext context;
	// deserialize context
	{
		if(!context.deserialize(__r__)) return false;
	}
	return fetchSelling(context);
}
bool Client2ServerProxy::fetchSelling2(ProtocolReader* __r__)
{
	COM_SearchContext context;
	// deserialize context
	{
		if(!context.deserialize(__r__)) return false;
	}
	return fetchSelling2(context);
}
bool Client2ServerProxy::selling(ProtocolReader* __r__)
{
	int32_t iteminstid=0;
	int32_t babyinstid=0;
	int32_t price=0;
	// deserialize iteminstid
	{
		if(!__r__->readType(iteminstid)) return false;
	}
	// deserialize babyinstid
	{
		if(!__r__->readType(babyinstid)) return false;
	}
	// deserialize price
	{
		if(!__r__->readType(price)) return false;
	}
	return selling(iteminstid,babyinstid,price);
}
bool Client2ServerProxy::unselling(ProtocolReader* __r__)
{
	int32_t sellid=0;
	// deserialize sellid
	{
		if(!__r__->readType(sellid)) return false;
	}
	return unselling(sellid);
}
bool Client2ServerProxy::buy(ProtocolReader* __r__)
{
	int32_t sellid=0;
	// deserialize sellid
	{
		if(!__r__->readType(sellid)) return false;
	}
	return buy(sellid);
}
bool Client2ServerProxy::fixItem(ProtocolReader* __r__)
{
	int32_t instId=0;
	FixType type=(FixType)(0);
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 4) return false;
		type = (FixType)__e__;
	}
	return fixItem(instId,type);
}
bool Client2ServerProxy::fixAllItem(ProtocolReader* __r__)
{
	std::vector< uint32_t > items;
	FixType type=(FixType)(0);
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(items[i])) return false;
		}
	}
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 4) return false;
		type = (FixType)__e__;
	}
	return fixAllItem(items,type);
}
bool Client2ServerProxy::makeDebirsItem(ProtocolReader* __r__)
{
	int32_t instId=0;
	int32_t num=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize num
	{
		if(!__r__->readType(num)) return false;
	}
	return makeDebirsItem(instId,num);
}
bool Client2ServerProxy::levelUpMagicItem(ProtocolReader* __r__)
{
	std::vector< uint32_t > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(items[i])) return false;
		}
	}
	return levelUpMagicItem(items);
}
bool Client2ServerProxy::tupoMagicItem(ProtocolReader* __r__)
{
	int32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return tupoMagicItem(level);
}
bool Client2ServerProxy::changeMagicJob(ProtocolReader* __r__)
{
	JobType job=(JobType)(0);
	// deserialize job
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 12) return false;
		job = (JobType)__e__;
	}
	return changeMagicJob(job);
}
bool Client2ServerProxy::requestPk(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return requestPk(playerId);
}
bool Client2ServerProxy::uiBehavior(ProtocolReader* __r__)
{
	UIBehaviorType type=(UIBehaviorType)(0);
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 22) return false;
		type = (UIBehaviorType)__e__;
	}
	return uiBehavior(type);
}
bool Client2ServerProxy::openZhuanpan(ProtocolReader* __r__)
{
	return openZhuanpan();
}
bool Client2ServerProxy::zhuanpanGo(ProtocolReader* __r__)
{
	uint32_t counter=0;
	// deserialize counter
	{
		if(!__r__->readType(counter)) return false;
	}
	return zhuanpanGo(counter);
}
bool Client2ServerProxy::redemptionSpree(ProtocolReader* __r__)
{
	std::string code;
	// deserialize code
	{
		if(!__r__->readType(code, 65535)) return false;
	}
	return redemptionSpree(code);
}
bool Client2ServerProxy::sceneFilter(ProtocolReader* __r__)
{
	std::vector< SceneFilterType > sfType;
	// deserialize sfType
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		sfType.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			uint8_t __e__;
			if(!__r__->readType(__e__) || __e__ >= 6) return false;
			sfType[i] = (SceneFilterType)__e__;
		}
	}
	return sceneFilter(sfType);
}
bool Client2ServerProxy::sendExamAnswer(ProtocolReader* __r__)
{
	uint32_t questionId=0;
	uint8_t answer=0;
	// deserialize questionId
	{
		if(!__r__->readType(questionId)) return false;
	}
	// deserialize answer
	{
		if(!__r__->readType(answer)) return false;
	}
	return sendExamAnswer(questionId,answer);
}
bool Client2ServerProxy::sendwishing(ProtocolReader* __r__)
{
	COM_Wishing wish;
	// deserialize wish
	{
		if(!wish.deserialize(__r__)) return false;
	}
	return sendwishing(wish);
}
bool Client2ServerProxy::requestWish(ProtocolReader* __r__)
{
	return requestWish();
}
bool Client2ServerProxy::leaderCloseDialog(ProtocolReader* __r__)
{
	return leaderCloseDialog();
}
bool Client2ServerProxy::requestOnlineReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestOnlineReward(index);
}
bool Client2ServerProxy::requestFundReward(ProtocolReader* __r__)
{
	uint32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return requestFundReward(level);
}
bool Client2ServerProxy::openCard(ProtocolReader* __r__)
{
	uint16_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return openCard(index);
}
bool Client2ServerProxy::resetCard(ProtocolReader* __r__)
{
	return resetCard();
}
bool Client2ServerProxy::hotRoleBuy(ProtocolReader* __r__)
{
	return hotRoleBuy();
}
bool Client2ServerProxy::requestSevenReward(ProtocolReader* __r__)
{
	uint32_t qid=0;
	// deserialize qid
	{
		if(!__r__->readType(qid)) return false;
	}
	return requestSevenReward(qid);
}
bool Client2ServerProxy::vipreward(ProtocolReader* __r__)
{
	return vipreward();
}
bool Client2ServerProxy::requestChargeTotalSingleReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestChargeTotalSingleReward(index);
}
bool Client2ServerProxy::requestChargeTotalReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestChargeTotalReward(index);
}
bool Client2ServerProxy::requestChargeEverySingleReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestChargeEverySingleReward(index);
}
bool Client2ServerProxy::requestChargeEveryReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestChargeEveryReward(index);
}
bool Client2ServerProxy::requestLoginTotal(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestLoginTotal(index);
}
bool Client2ServerProxy::buyDiscountStoreSingle(ProtocolReader* __r__)
{
	int32_t itemId=0;
	int32_t itemStack=0;
	// deserialize itemId
	{
		if(!__r__->readType(itemId)) return false;
	}
	// deserialize itemStack
	{
		if(!__r__->readType(itemStack)) return false;
	}
	return buyDiscountStoreSingle(itemId,itemStack);
}
bool Client2ServerProxy::buyDiscountStore(ProtocolReader* __r__)
{
	int32_t itemId=0;
	int32_t itemStack=0;
	// deserialize itemId
	{
		if(!__r__->readType(itemId)) return false;
	}
	// deserialize itemStack
	{
		if(!__r__->readType(itemStack)) return false;
	}
	return buyDiscountStore(itemId,itemStack);
}
bool Client2ServerProxy::requestEmployeeActivityReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestEmployeeActivityReward(index);
}
bool Client2ServerProxy::requestmyselfrechargeleReward(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestmyselfrechargeleReward(index);
}
bool Client2ServerProxy::requestEverydayIntegral(ProtocolReader* __r__)
{
	return requestEverydayIntegral();
}
bool Client2ServerProxy::buyIntegralItem(ProtocolReader* __r__)
{
	uint32_t id=0;
	uint32_t num=0;
	// deserialize id
	{
		if(!__r__->readType(id)) return false;
	}
	// deserialize num
	{
		if(!__r__->readType(num)) return false;
	}
	return buyIntegralItem(id,num);
}
bool Client2ServerProxy::familyLoseLeader(ProtocolReader* __r__)
{
	return familyLoseLeader();
}
bool Client2ServerProxy::verificationSMS(ProtocolReader* __r__)
{
	std::string phoneNumber;
	std::string code;
	// deserialize phoneNumber
	{
		if(!__r__->readType(phoneNumber, 65535)) return false;
	}
	// deserialize code
	{
		if(!__r__->readType(code, 65535)) return false;
	}
	return verificationSMS(phoneNumber,code);
}
bool Client2ServerProxy::lockItem(ProtocolReader* __r__)
{
	int32_t instId=0;
	bool isLock=false;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize isLock
	{
		if(!__r__->readType(isLock)) return false;
	}
	return lockItem(instId,isLock);
}
bool Client2ServerProxy::lockBaby(ProtocolReader* __r__)
{
	int32_t instId=0;
	bool isLock=false;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize isLock
	{
		if(!__r__->readType(isLock)) return false;
	}
	return lockBaby(instId,isLock);
}
bool Client2ServerProxy::showBaby(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return showBaby(instId);
}
bool Client2ServerProxy::wearFuwen(ProtocolReader* __r__)
{
	int32_t itemInstId=0;
	// deserialize itemInstId
	{
		if(!__r__->readType(itemInstId)) return false;
	}
	return wearFuwen(itemInstId);
}
bool Client2ServerProxy::takeoffFuwen(ProtocolReader* __r__)
{
	int32_t slotId=0;
	// deserialize slotId
	{
		if(!__r__->readType(slotId)) return false;
	}
	return takeoffFuwen(slotId);
}
bool Client2ServerProxy::compFuwen(ProtocolReader* __r__)
{
	int32_t itemInstId=0;
	// deserialize itemInstId
	{
		if(!__r__->readType(itemInstId)) return false;
	}
	return compFuwen(itemInstId);
}
bool Client2ServerProxy::requestEmployeeQuest(ProtocolReader* __r__)
{
	return requestEmployeeQuest();
}
bool Client2ServerProxy::acceptEmployeeQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	std::vector< int32_t > employees;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	// deserialize employees
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		employees.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(employees[i])) return false;
		}
	}
	return acceptEmployeeQuest(questId,employees);
}
bool Client2ServerProxy::submitEmployeeQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return submitEmployeeQuest(questId);
}
bool Client2ServerProxy::crystalUpLevel(ProtocolReader* __r__)
{
	return crystalUpLevel();
}
bool Client2ServerProxy::resetCrystalProp(ProtocolReader* __r__)
{
	std::vector< int32_t > locklist;
	// deserialize locklist
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		locklist.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(locklist[i])) return false;
		}
	}
	return resetCrystalProp(locklist);
}
bool Client2ServerProxy::magicItemOneKeyLevel(ProtocolReader* __r__)
{
	return magicItemOneKeyLevel();
}
bool Client2ServerProxy::submitQuest2(ProtocolReader* __r__)
{
	int32_t npcId=0;
	int32_t questId=0;
	int32_t instId=0;
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return submitQuest2(npcId,questId,instId);
}
bool Client2ServerProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!openvip(r)) return false;
		}
		break;
		case 1:
		{
			if(!requestPhoto(r)) return false;
		}
		break;
		case 2:
		{
			if(!ping(r)) return false;
		}
		break;
		case 3:
		{
			if(!sessionlogin(r)) return false;
		}
		break;
		case 4:
		{
			if(!login(r)) return false;
		}
		break;
		case 5:
		{
			if(!createPlayer(r)) return false;
		}
		break;
		case 6:
		{
			if(!deletePlayer(r)) return false;
		}
		break;
		case 7:
		{
			if(!enterGame(r)) return false;
		}
		break;
		case 8:
		{
			if(!requestBag(r)) return false;
		}
		break;
		case 9:
		{
			if(!requestEmployees(r)) return false;
		}
		break;
		case 10:
		{
			if(!requestStorage(r)) return false;
		}
		break;
		case 11:
		{
			if(!requestAchievement(r)) return false;
		}
		break;
		case 12:
		{
			if(!initminig(r)) return false;
		}
		break;
		case 13:
		{
			if(!requestCompound(r)) return false;
		}
		break;
		case 14:
		{
			if(!move(r)) return false;
		}
		break;
		case 15:
		{
			if(!moveToNpc(r)) return false;
		}
		break;
		case 16:
		{
			if(!moveToNpc2(r)) return false;
		}
		break;
		case 17:
		{
			if(!moveToZone(r)) return false;
		}
		break;
		case 18:
		{
			if(!autoBattle(r)) return false;
		}
		break;
		case 19:
		{
			if(!stopAutoBattle(r)) return false;
		}
		break;
		case 20:
		{
			if(!stopMove(r)) return false;
		}
		break;
		case 21:
		{
			if(!exitCopy(r)) return false;
		}
		break;
		case 22:
		{
			if(!transforScene(r)) return false;
		}
		break;
		case 23:
		{
			if(!sceneLoaded(r)) return false;
		}
		break;
		case 24:
		{
			if(!querySimplePlayerInst(r)) return false;
		}
		break;
		case 25:
		{
			if(!logout(r)) return false;
		}
		break;
		case 26:
		{
			if(!changProp(r)) return false;
		}
		break;
		case 27:
		{
			if(!learnSkill(r)) return false;
		}
		break;
		case 28:
		{
			if(!babyLearnSkill(r)) return false;
		}
		break;
		case 29:
		{
			if(!forgetSkill(r)) return false;
		}
		break;
		case 30:
		{
			if(!syncOrder(r)) return false;
		}
		break;
		case 31:
		{
			if(!syncOrderTimeout(r)) return false;
		}
		break;
		case 32:
		{
			if(!sendChat(r)) return false;
		}
		break;
		case 33:
		{
			if(!requestAudio(r)) return false;
		}
		break;
		case 34:
		{
			if(!publishItemInst(r)) return false;
		}
		break;
		case 35:
		{
			if(!queryItemInst(r)) return false;
		}
		break;
		case 36:
		{
			if(!publishbabyInst(r)) return false;
		}
		break;
		case 37:
		{
			if(!querybabyInst(r)) return false;
		}
		break;
		case 38:
		{
			if(!useItem(r)) return false;
		}
		break;
		case 39:
		{
			if(!wearEquipment(r)) return false;
		}
		break;
		case 40:
		{
			if(!delEquipment(r)) return false;
		}
		break;
		case 41:
		{
			if(!setPlayerFront(r)) return false;
		}
		break;
		case 42:
		{
			if(!setBattlebaby(r)) return false;
		}
		break;
		case 43:
		{
			if(!changeBabyName(r)) return false;
		}
		break;
		case 44:
		{
			if(!intensifyBaby(r)) return false;
		}
		break;
		case 45:
		{
			if(!setBattleEmp(r)) return false;
		}
		break;
		case 46:
		{
			if(!changeEmpBattleGroup(r)) return false;
		}
		break;
		case 47:
		{
			if(!requestEvolve(r)) return false;
		}
		break;
		case 48:
		{
			if(!requestUpStar(r)) return false;
		}
		break;
		case 49:
		{
			if(!requestDelEmp(r)) return false;
		}
		break;
		case 50:
		{
			if(!delEmployee(r)) return false;
		}
		break;
		case 51:
		{
			if(!onekeyDelEmp(r)) return false;
		}
		break;
		case 52:
		{
			if(!delEmployeeSoul(r)) return false;
		}
		break;
		case 53:
		{
			if(!sortBagItem(r)) return false;
		}
		break;
		case 54:
		{
			if(!sellBagItem(r)) return false;
		}
		break;
		case 55:
		{
			if(!depositItemToStorage(r)) return false;
		}
		break;
		case 56:
		{
			if(!depositBabyToStorage(r)) return false;
		}
		break;
		case 57:
		{
			if(!storageItemToBag(r)) return false;
		}
		break;
		case 58:
		{
			if(!storageBabyToPlayer(r)) return false;
		}
		break;
		case 59:
		{
			if(!sortStorage(r)) return false;
		}
		break;
		case 60:
		{
			if(!delStorageBaby(r)) return false;
		}
		break;
		case 61:
		{
			if(!jointLobby(r)) return false;
		}
		break;
		case 62:
		{
			if(!exitLobby(r)) return false;
		}
		break;
		case 63:
		{
			if(!createTeam(r)) return false;
		}
		break;
		case 64:
		{
			if(!changeTeam(r)) return false;
		}
		break;
		case 65:
		{
			if(!kickTeamMember(r)) return false;
		}
		break;
		case 66:
		{
			if(!changeTeamLeader(r)) return false;
		}
		break;
		case 67:
		{
			if(!joinTeam(r)) return false;
		}
		break;
		case 68:
		{
			if(!exitTeam(r)) return false;
		}
		break;
		case 69:
		{
			if(!changeTeamPassword(r)) return false;
		}
		break;
		case 70:
		{
			if(!joinTeamRoom(r)) return false;
		}
		break;
		case 71:
		{
			if(!inviteTeamMember(r)) return false;
		}
		break;
		case 72:
		{
			if(!isjoinTeam(r)) return false;
		}
		break;
		case 73:
		{
			if(!leaveTeam(r)) return false;
		}
		break;
		case 74:
		{
			if(!backTeam(r)) return false;
		}
		break;
		case 75:
		{
			if(!refuseBackTeam(r)) return false;
		}
		break;
		case 76:
		{
			if(!teamCallMember(r)) return false;
		}
		break;
		case 77:
		{
			if(!requestJoinTeam(r)) return false;
		}
		break;
		case 78:
		{
			if(!ratifyJoinTeam(r)) return false;
		}
		break;
		case 79:
		{
			if(!drawLotteryBox(r)) return false;
		}
		break;
		case 80:
		{
			if(!acceptQuest(r)) return false;
		}
		break;
		case 81:
		{
			if(!submitQuest(r)) return false;
		}
		break;
		case 82:
		{
			if(!giveupQuest(r)) return false;
		}
		break;
		case 83:
		{
			if(!requestContactInfoById(r)) return false;
		}
		break;
		case 84:
		{
			if(!requestContactInfoByName(r)) return false;
		}
		break;
		case 85:
		{
			if(!requestFriendList(r)) return false;
		}
		break;
		case 86:
		{
			if(!addFriend(r)) return false;
		}
		break;
		case 87:
		{
			if(!delFriend(r)) return false;
		}
		break;
		case 88:
		{
			if(!addBlacklist(r)) return false;
		}
		break;
		case 89:
		{
			if(!delBlacklist(r)) return false;
		}
		break;
		case 90:
		{
			if(!requestReferrFriend(r)) return false;
		}
		break;
		case 91:
		{
			if(!mining(r)) return false;
		}
		break;
		case 92:
		{
			if(!compoundItem(r)) return false;
		}
		break;
		case 93:
		{
			if(!bagItemSplit(r)) return false;
		}
		break;
		case 94:
		{
			if(!requestChallenge(r)) return false;
		}
		break;
		case 95:
		{
			if(!requestRival(r)) return false;
		}
		break;
		case 96:
		{
			if(!requestMySelfJJCData(r)) return false;
		}
		break;
		case 97:
		{
			if(!requestCheckMsg(r)) return false;
		}
		break;
		case 98:
		{
			if(!requestMyAllbattleMsg(r)) return false;
		}
		break;
		case 99:
		{
			if(!requestJJCRank(r)) return false;
		}
		break;
		case 100:
		{
			if(!requestLevelRank(r)) return false;
		}
		break;
		case 101:
		{
			if(!requestBabyRank(r)) return false;
		}
		break;
		case 102:
		{
			if(!requestEmpRank(r)) return false;
		}
		break;
		case 103:
		{
			if(!requestPlayerFFRank(r)) return false;
		}
		break;
		case 104:
		{
			if(!queryOnlinePlayerbyName(r)) return false;
		}
		break;
		case 105:
		{
			if(!queryPlayerbyName(r)) return false;
		}
		break;
		case 106:
		{
			if(!queryBaby(r)) return false;
		}
		break;
		case 107:
		{
			if(!queryEmployee(r)) return false;
		}
		break;
		case 108:
		{
			if(!guideFinish(r)) return false;
		}
		break;
		case 109:
		{
			if(!enterBattle(r)) return false;
		}
		break;
		case 110:
		{
			if(!shopBuyItem(r)) return false;
		}
		break;
		case 111:
		{
			if(!getFirstRechargeItem(r)) return false;
		}
		break;
		case 112:
		{
			if(!requestLevelGift(r)) return false;
		}
		break;
		case 113:
		{
			if(!setCurrentTitle(r)) return false;
		}
		break;
		case 114:
		{
			if(!openBuyBox(r)) return false;
		}
		break;
		case 115:
		{
			if(!requestAchaward(r)) return false;
		}
		break;
		case 116:
		{
			if(!sign(r)) return false;
		}
		break;
		case 117:
		{
			if(!requestSignupReward7(r)) return false;
		}
		break;
		case 118:
		{
			if(!requestSignupReward14(r)) return false;
		}
		break;
		case 119:
		{
			if(!requestSignupReward28(r)) return false;
		}
		break;
		case 120:
		{
			if(!requestActivityReward(r)) return false;
		}
		break;
		case 121:
		{
			if(!resetHundredTier(r)) return false;
		}
		break;
		case 122:
		{
			if(!enterHundredScene(r)) return false;
		}
		break;
		case 123:
		{
			if(!delBaby(r)) return false;
		}
		break;
		case 124:
		{
			if(!resetBaby(r)) return false;
		}
		break;
		case 125:
		{
			if(!resetBabyProp(r)) return false;
		}
		break;
		case 126:
		{
			if(!remouldBaby(r)) return false;
		}
		break;
		case 127:
		{
			if(!empSkillLevelUp(r)) return false;
		}
		break;
		case 128:
		{
			if(!setOpenDoubleTimeFlag(r)) return false;
		}
		break;
		case 129:
		{
			if(!talkedNpc(r)) return false;
		}
		break;
		case 130:
		{
			if(!jjcBattleGo(r)) return false;
		}
		break;
		case 131:
		{
			if(!requestMyJJCTeamMsg(r)) return false;
		}
		break;
		case 132:
		{
			if(!startMatching(r)) return false;
		}
		break;
		case 133:
		{
			if(!stopMatching(r)) return false;
		}
		break;
		case 134:
		{
			if(!exitPvpJJC(r)) return false;
		}
		break;
		case 135:
		{
			if(!joinPvpLobby(r)) return false;
		}
		break;
		case 136:
		{
			if(!exitPvpLobby(r)) return false;
		}
		break;
		case 137:
		{
			if(!requestpvprank(r)) return false;
		}
		break;
		case 138:
		{
			if(!joinWarriorchoose(r)) return false;
		}
		break;
		case 139:
		{
			if(!warriorStart(r)) return false;
		}
		break;
		case 140:
		{
			if(!warriorStop(r)) return false;
		}
		break;
		case 141:
		{
			if(!sendMail(r)) return false;
		}
		break;
		case 142:
		{
			if(!readMail(r)) return false;
		}
		break;
		case 143:
		{
			if(!delMail(r)) return false;
		}
		break;
		case 144:
		{
			if(!getMailItem(r)) return false;
		}
		break;
		case 145:
		{
			if(!requestState(r)) return false;
		}
		break;
		case 146:
		{
			if(!createGuild(r)) return false;
		}
		break;
		case 147:
		{
			if(!delGuild(r)) return false;
		}
		break;
		case 148:
		{
			if(!requestJoinGuild(r)) return false;
		}
		break;
		case 149:
		{
			if(!leaveGuild(r)) return false;
		}
		break;
		case 150:
		{
			if(!kickOut(r)) return false;
		}
		break;
		case 151:
		{
			if(!acceptRequestGuild(r)) return false;
		}
		break;
		case 152:
		{
			if(!refuseRequestGuild(r)) return false;
		}
		break;
		case 153:
		{
			if(!changeMemberPosition(r)) return false;
		}
		break;
		case 154:
		{
			if(!transferPremier(r)) return false;
		}
		break;
		case 155:
		{
			if(!changeGuildNotice(r)) return false;
		}
		break;
		case 156:
		{
			if(!queryGuildList(r)) return false;
		}
		break;
		case 157:
		{
			if(!inviteJoinGuild(r)) return false;
		}
		break;
		case 158:
		{
			if(!respondInviteJoinGuild(r)) return false;
		}
		break;
		case 159:
		{
			if(!buyGuildItem(r)) return false;
		}
		break;
		case 160:
		{
			if(!entryGuildBattle(r)) return false;
		}
		break;
		case 161:
		{
			if(!transforGuildBattleScene(r)) return false;
		}
		break;
		case 162:
		{
			if(!addGuildMoney(r)) return false;
		}
		break;
		case 163:
		{
			if(!updateGuildBuiling(r)) return false;
		}
		break;
		case 164:
		{
			if(!refreshGuildShop(r)) return false;
		}
		break;
		case 165:
		{
			if(!levelupGuildSkill(r)) return false;
		}
		break;
		case 166:
		{
			if(!presentGuildItem(r)) return false;
		}
		break;
		case 167:
		{
			if(!progenitusAddExp(r)) return false;
		}
		break;
		case 168:
		{
			if(!setProgenitusPosition(r)) return false;
		}
		break;
		case 169:
		{
			if(!guildsign(r)) return false;
		}
		break;
		case 170:
		{
			if(!fetchSelling(r)) return false;
		}
		break;
		case 171:
		{
			if(!fetchSelling2(r)) return false;
		}
		break;
		case 172:
		{
			if(!selling(r)) return false;
		}
		break;
		case 173:
		{
			if(!unselling(r)) return false;
		}
		break;
		case 174:
		{
			if(!buy(r)) return false;
		}
		break;
		case 175:
		{
			if(!fixItem(r)) return false;
		}
		break;
		case 176:
		{
			if(!fixAllItem(r)) return false;
		}
		break;
		case 177:
		{
			if(!makeDebirsItem(r)) return false;
		}
		break;
		case 178:
		{
			if(!levelUpMagicItem(r)) return false;
		}
		break;
		case 179:
		{
			if(!tupoMagicItem(r)) return false;
		}
		break;
		case 180:
		{
			if(!changeMagicJob(r)) return false;
		}
		break;
		case 181:
		{
			if(!requestPk(r)) return false;
		}
		break;
		case 182:
		{
			if(!uiBehavior(r)) return false;
		}
		break;
		case 183:
		{
			if(!openZhuanpan(r)) return false;
		}
		break;
		case 184:
		{
			if(!zhuanpanGo(r)) return false;
		}
		break;
		case 185:
		{
			if(!redemptionSpree(r)) return false;
		}
		break;
		case 186:
		{
			if(!sceneFilter(r)) return false;
		}
		break;
		case 187:
		{
			if(!sendExamAnswer(r)) return false;
		}
		break;
		case 188:
		{
			if(!sendwishing(r)) return false;
		}
		break;
		case 189:
		{
			if(!requestWish(r)) return false;
		}
		break;
		case 190:
		{
			if(!leaderCloseDialog(r)) return false;
		}
		break;
		case 191:
		{
			if(!requestOnlineReward(r)) return false;
		}
		break;
		case 192:
		{
			if(!requestFundReward(r)) return false;
		}
		break;
		case 193:
		{
			if(!openCard(r)) return false;
		}
		break;
		case 194:
		{
			if(!resetCard(r)) return false;
		}
		break;
		case 195:
		{
			if(!hotRoleBuy(r)) return false;
		}
		break;
		case 196:
		{
			if(!requestSevenReward(r)) return false;
		}
		break;
		case 197:
		{
			if(!vipreward(r)) return false;
		}
		break;
		case 198:
		{
			if(!requestChargeTotalSingleReward(r)) return false;
		}
		break;
		case 199:
		{
			if(!requestChargeTotalReward(r)) return false;
		}
		break;
		case 200:
		{
			if(!requestChargeEverySingleReward(r)) return false;
		}
		break;
		case 201:
		{
			if(!requestChargeEveryReward(r)) return false;
		}
		break;
		case 202:
		{
			if(!requestLoginTotal(r)) return false;
		}
		break;
		case 203:
		{
			if(!buyDiscountStoreSingle(r)) return false;
		}
		break;
		case 204:
		{
			if(!buyDiscountStore(r)) return false;
		}
		break;
		case 205:
		{
			if(!requestEmployeeActivityReward(r)) return false;
		}
		break;
		case 206:
		{
			if(!requestmyselfrechargeleReward(r)) return false;
		}
		break;
		case 207:
		{
			if(!requestEverydayIntegral(r)) return false;
		}
		break;
		case 208:
		{
			if(!buyIntegralItem(r)) return false;
		}
		break;
		case 209:
		{
			if(!familyLoseLeader(r)) return false;
		}
		break;
		case 210:
		{
			if(!verificationSMS(r)) return false;
		}
		break;
		case 211:
		{
			if(!lockItem(r)) return false;
		}
		break;
		case 212:
		{
			if(!lockBaby(r)) return false;
		}
		break;
		case 213:
		{
			if(!showBaby(r)) return false;
		}
		break;
		case 214:
		{
			if(!wearFuwen(r)) return false;
		}
		break;
		case 215:
		{
			if(!takeoffFuwen(r)) return false;
		}
		break;
		case 216:
		{
			if(!compFuwen(r)) return false;
		}
		break;
		case 217:
		{
			if(!requestEmployeeQuest(r)) return false;
		}
		break;
		case 218:
		{
			if(!acceptEmployeeQuest(r)) return false;
		}
		break;
		case 219:
		{
			if(!submitEmployeeQuest(r)) return false;
		}
		break;
		case 220:
		{
			if(!crystalUpLevel(r)) return false;
		}
		break;
		case 221:
		{
			if(!resetCrystalProp(r)) return false;
		}
		break;
		case 222:
		{
			if(!magicItemOneKeyLevel(r)) return false;
		}
		break;
		case 223:
		{
			if(!submitQuest2(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void Server2ClientStub::pong()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::errorno(ErrorNo e)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize e
	{
		uint8_t __e__ = (uint8_t)e;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::teamerrorno(const std::string& name,ErrorNo e)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	// serialize e
	{
		uint8_t __e__ = (uint8_t)e;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::reconnection(const COM_ReconnectInfo& recInfo)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize recInfo
	{
		recInfo.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::sessionfailed()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::loginok(const std::string& sessionkey,const std::vector< COM_SimpleInformation >& players)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize sessionkey
	{
		w->writeType(sessionkey);
	}
	// serialize players
	{
		uint32_t __len__ = (uint32_t)players.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			players[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::logoutOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::createPlayerOk(const COM_SimpleInformation& player)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize player
	{
		player.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::deletePlayerOk(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Server2ClientStub::enterGameOk(const COM_PlayerInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::initBabies(const std::vector< COM_BabyInst >& insts)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 10;
	w->writeType(pid);
	// serialize insts
	{
		uint32_t __len__ = (uint32_t)insts.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			insts[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::initEmployees(const std::vector< COM_EmployeeInst >& insts,bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 11;
	w->writeType(pid);
	// serialize insts
	{
		uint32_t __len__ = (uint32_t)insts.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			insts[i].serialize(w);
		}
	}
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void Server2ClientStub::initEmpBattleGroup(const COM_BattleEmp& bep)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 12;
	w->writeType(pid);
	// serialize bep
	{
		bep.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::initNpc(const std::vector< int32_t >& npcList)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 13;
	w->writeType(pid);
	// serialize npcList
	{
		uint32_t __len__ = (uint32_t)npcList.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(npcList[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::initAchievement(const std::vector< COM_Achievement >& actlist)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 14;
	w->writeType(pid);
	// serialize actlist
	{
		uint32_t __len__ = (uint32_t)actlist.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			actlist[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::initGather(uint32_t allnum,const std::vector< COM_Gather >& gathers)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 15;
	w->writeType(pid);
	// serialize allnum
	{
		w->writeType(allnum);
	}
	// serialize gathers
	{
		uint32_t __len__ = (uint32_t)gathers.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			gathers[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::initcompound(const std::vector< uint32_t >& compounds)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 16;
	w->writeType(pid);
	// serialize compounds
	{
		uint32_t __len__ = (uint32_t)compounds.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(compounds[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::addBaby(const COM_BabyInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 17;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::refreshBaby(const COM_BabyInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 18;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delBabyOK(uint32_t babyInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 19;
	w->writeType(pid);
	// serialize babyInstId
	{
		w->writeType(babyInstId);
	}
	methodEnd();
}
void Server2ClientStub::changeBabyNameOK(uint32_t babyId,const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 20;
	w->writeType(pid);
	// serialize babyId
	{
		w->writeType(babyId);
	}
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Server2ClientStub::remouldBabyOK(uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 21;
	w->writeType(pid);
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void Server2ClientStub::intensifyBabyOK(uint32_t babyid,uint32_t intensifyLevel)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 22;
	w->writeType(pid);
	// serialize babyid
	{
		w->writeType(babyid);
	}
	// serialize intensifyLevel
	{
		w->writeType(intensifyLevel);
	}
	methodEnd();
}
void Server2ClientStub::learnSkillOk(const COM_Skill& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 23;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::forgetSkillOk(uint32_t skid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 24;
	w->writeType(pid);
	// serialize skid
	{
		w->writeType(skid);
	}
	methodEnd();
}
void Server2ClientStub::addSkillExp(uint32_t skid,uint32_t uExp,ItemUseFlag flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 25;
	w->writeType(pid);
	// serialize skid
	{
		w->writeType(skid);
	}
	// serialize uExp
	{
		w->writeType(uExp);
	}
	// serialize flag
	{
		uint8_t __e__ = (uint8_t)flag;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::babyLearnSkillOK(uint32_t instId,uint32_t newSkId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 26;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize newSkId
	{
		w->writeType(newSkId);
	}
	methodEnd();
}
void Server2ClientStub::skillLevelUp(uint32_t instId,const COM_Skill& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 27;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::joinScene(const COM_SceneInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 28;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::joinCopySceneOK(int32_t secneid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 29;
	w->writeType(pid);
	// serialize secneid
	{
		w->writeType(secneid);
	}
	methodEnd();
}
void Server2ClientStub::initCopyNums()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 30;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::addToScene(const COM_ScenePlayerInformation& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 31;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delFormScene(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 32;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Server2ClientStub::move2(int32_t instId,const COM_FPosition& pos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 33;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize pos
	{
		pos.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::cantMove()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 34;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::querySimplePlayerInstOk(const COM_SimplePlayerInst& player)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 35;
	w->writeType(pid);
	// serialize player
	{
		player.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::transfor2(int32_t instId,const COM_FPosition& pos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 36;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize pos
	{
		pos.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::openScene(int32_t sceneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 37;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	methodEnd();
}
void Server2ClientStub::autoBattleResult(bool isOk)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 38;
	w->writeType(pid);
	// serialize isOk
	{
		w->writeType(isOk);
	}
	methodEnd();
}
void Server2ClientStub::talked2Npc(int32_t npcId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 39;
	w->writeType(pid);
	// serialize npcId
	{
		w->writeType(npcId);
	}
	methodEnd();
}
void Server2ClientStub::talked2Player(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 40;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Server2ClientStub::useItemOk(int32_t itemId,int32_t stack)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 41;
	w->writeType(pid);
	// serialize itemId
	{
		w->writeType(itemId);
	}
	// serialize stack
	{
		w->writeType(stack);
	}
	methodEnd();
}
void Server2ClientStub::syncBattleStatus(int32_t playerId,bool inBattle)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 42;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize inBattle
	{
		w->writeType(inBattle);
	}
	methodEnd();
}
void Server2ClientStub::enterBattleOk(const COM_InitBattle& initBattle)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 43;
	w->writeType(pid);
	// serialize initBattle
	{
		initBattle.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::exitBattleOk(BattleJudgeType bjt,const COM_BattleOverClearing& init)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 44;
	w->writeType(pid);
	// serialize bjt
	{
		uint8_t __e__ = (uint8_t)bjt;
		w->writeType(__e__);
	}
	// serialize init
	{
		init.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::syncOrderOk(uint32_t uid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 45;
	w->writeType(pid);
	// serialize uid
	{
		w->writeType(uid);
	}
	methodEnd();
}
void Server2ClientStub::syncOrderOkEX()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 46;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::syncOneTurnAction(const COM_BattleReport& reports)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 47;
	w->writeType(pid);
	// serialize reports
	{
		reports.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::syncProperties(uint32_t guid,const std::vector< COM_PropValue >& props)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 48;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	// serialize props
	{
		uint32_t __len__ = (uint32_t)props.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			props[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::receiveChat(const COM_ChatInfo& info,const COM_ContactInfo& myinfo)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 49;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	// serialize myinfo
	{
		myinfo.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::requestAudioOk(int32_t audioId,const std::vector< uint8_t >& content)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 50;
	w->writeType(pid);
	// serialize audioId
	{
		w->writeType(audioId);
	}
	// serialize content
	{
		uint32_t __len__ = (uint32_t)content.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(content[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::publishItemInstRes(const COM_ShowItemInstInfo& info,ChatKind type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 51;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::queryItemInstRes(const COM_ShowItemInst& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 52;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::publishBabyInstRes(const COM_ShowbabyInstInfo& info,ChatKind type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 53;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::queryBabyInstRes(const COM_ShowbabyInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 54;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::setNoTalkTime(float t)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 55;
	w->writeType(pid);
	// serialize t
	{
		w->writeType(t);
	}
	methodEnd();
}
void Server2ClientStub::addNpc(const std::vector< int32_t >& npcList)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 56;
	w->writeType(pid);
	// serialize npcList
	{
		uint32_t __len__ = (uint32_t)npcList.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(npcList[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::delNpc(const std::vector< int32_t >& npcList)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 57;
	w->writeType(pid);
	// serialize npcList
	{
		uint32_t __len__ = (uint32_t)npcList.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(npcList[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::setTeamLeader(int32_t playerId,bool isLeader)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 58;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize isLeader
	{
		w->writeType(isLeader);
	}
	methodEnd();
}
void Server2ClientStub::initBag(const std::vector< COM_Item >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 59;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::addBagItem(const COM_Item& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 60;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delBagItem(uint16_t slot)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 61;
	w->writeType(pid);
	// serialize slot
	{
		w->writeType(slot);
	}
	methodEnd();
}
void Server2ClientStub::updateBagItem(const COM_Item& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 62;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::depositItemOK(const COM_Item& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 63;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::getoutItemOK(uint16_t slot)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 64;
	w->writeType(pid);
	// serialize slot
	{
		w->writeType(slot);
	}
	methodEnd();
}
void Server2ClientStub::depositBabyOK(const COM_BabyInst& baby)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 65;
	w->writeType(pid);
	// serialize baby
	{
		baby.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::getoutBabyOK(uint16_t slot)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 66;
	w->writeType(pid);
	// serialize slot
	{
		w->writeType(slot);
	}
	methodEnd();
}
void Server2ClientStub::sortItemStorageOK(const std::vector< COM_Item >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 67;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::sortBabyStorageOK(const std::vector< uint32_t >& babys)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 68;
	w->writeType(pid);
	// serialize babys
	{
		uint32_t __len__ = (uint32_t)babys.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(babys[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::initItemStorage(uint16_t gridNum,const std::vector< COM_Item >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 69;
	w->writeType(pid);
	// serialize gridNum
	{
		w->writeType(gridNum);
	}
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::initBabyStorage(uint16_t gridNum,const std::vector< COM_BabyInst >& babys)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 70;
	w->writeType(pid);
	// serialize gridNum
	{
		w->writeType(gridNum);
	}
	// serialize babys
	{
		uint32_t __len__ = (uint32_t)babys.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			babys[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::openStorageGrid(StorageType tp,uint16_t gridNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 71;
	w->writeType(pid);
	// serialize tp
	{
		uint8_t __e__ = (uint8_t)tp;
		w->writeType(__e__);
	}
	// serialize gridNum
	{
		w->writeType(gridNum);
	}
	methodEnd();
}
void Server2ClientStub::delStorageBabyOK(uint16_t slot)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 72;
	w->writeType(pid);
	// serialize slot
	{
		w->writeType(slot);
	}
	methodEnd();
}
void Server2ClientStub::initPlayerEquips(const std::vector< COM_Item >& equips)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 73;
	w->writeType(pid);
	// serialize equips
	{
		uint32_t __len__ = (uint32_t)equips.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			equips[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::wearEquipmentOk(uint32_t target,const COM_Item& equip)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 74;
	w->writeType(pid);
	// serialize target
	{
		w->writeType(target);
	}
	// serialize equip
	{
		equip.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::scenePlayerWearEquipment(uint32_t target,uint32_t itemId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 75;
	w->writeType(pid);
	// serialize target
	{
		w->writeType(target);
	}
	// serialize itemId
	{
		w->writeType(itemId);
	}
	methodEnd();
}
void Server2ClientStub::delEquipmentOk(uint32_t target,uint32_t itemInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 76;
	w->writeType(pid);
	// serialize target
	{
		w->writeType(target);
	}
	// serialize itemInstId
	{
		w->writeType(itemInstId);
	}
	methodEnd();
}
void Server2ClientStub::scenePlayerDoffEquipment(uint32_t target,uint32_t itemId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 77;
	w->writeType(pid);
	// serialize target
	{
		w->writeType(target);
	}
	// serialize itemId
	{
		w->writeType(itemId);
	}
	methodEnd();
}
void Server2ClientStub::sortBagItemOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 78;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::jointLobbyOk(const std::vector< COM_SimpleTeamInfo >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 79;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::exitLobbyOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 80;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::syncDelLobbyTeam(uint32_t teamId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 81;
	w->writeType(pid);
	// serialize teamId
	{
		w->writeType(teamId);
	}
	methodEnd();
}
void Server2ClientStub::syncUpdateLobbyTeam(const COM_SimpleTeamInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 82;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::syncAddLobbyTeam(const COM_SimpleTeamInfo& team)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 83;
	w->writeType(pid);
	// serialize team
	{
		team.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::createTeamOk(const COM_TeamInfo& team)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 84;
	w->writeType(pid);
	// serialize team
	{
		team.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::changeTeamOk(const COM_TeamInfo& team)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 85;
	w->writeType(pid);
	// serialize team
	{
		team.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::joinTeamOk(const COM_TeamInfo& team)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 86;
	w->writeType(pid);
	// serialize team
	{
		team.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::addTeamMember(const COM_SimplePlayerInst& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 87;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delTeamMember(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 88;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Server2ClientStub::changeTeamLeaderOk(int32_t uuid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 89;
	w->writeType(pid);
	// serialize uuid
	{
		w->writeType(uuid);
	}
	methodEnd();
}
void Server2ClientStub::exitTeamOk(bool iskick)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 90;
	w->writeType(pid);
	// serialize iskick
	{
		w->writeType(iskick);
	}
	methodEnd();
}
void Server2ClientStub::updateTeam(const COM_TeamInfo& team)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 91;
	w->writeType(pid);
	// serialize team
	{
		team.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::joinTeamRoomOK(const COM_TeamInfo& team)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 92;
	w->writeType(pid);
	// serialize team
	{
		team.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::inviteJoinTeam(uint32_t teamId,const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 93;
	w->writeType(pid);
	// serialize teamId
	{
		w->writeType(teamId);
	}
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Server2ClientStub::syncTeamDirtyProp(int32_t guid,const std::vector< COM_PropValue >& props)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 94;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	// serialize props
	{
		uint32_t __len__ = (uint32_t)props.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			props[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::leaveTeamOk(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 95;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Server2ClientStub::backTeamOK(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 96;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Server2ClientStub::teamCallMemberBack()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 97;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::refuseBackTeamOk(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 98;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void Server2ClientStub::requestJoinTeamTranspond(const std::string& reqName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 99;
	w->writeType(pid);
	// serialize reqName
	{
		w->writeType(reqName);
	}
	methodEnd();
}
void Server2ClientStub::drawLotteryBoxRep(const std::vector< COM_Item >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 100;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::addEmployee(const COM_EmployeeInst& employee)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 101;
	w->writeType(pid);
	// serialize employee
	{
		employee.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::battleEmployee(int32_t empId,EmployeesBattleGroup group,bool forbattle)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 102;
	w->writeType(pid);
	// serialize empId
	{
		w->writeType(empId);
	}
	// serialize group
	{
		uint8_t __e__ = (uint8_t)group;
		w->writeType(__e__);
	}
	// serialize forbattle
	{
		w->writeType(forbattle);
	}
	methodEnd();
}
void Server2ClientStub::changeEmpBattleGroupOK(EmployeesBattleGroup group)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 103;
	w->writeType(pid);
	// serialize group
	{
		uint8_t __e__ = (uint8_t)group;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::evolveOK(int32_t guid,QualityColor qc)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 104;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	// serialize qc
	{
		uint8_t __e__ = (uint8_t)qc;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::upStarOK(int32_t guid,int32_t star,const COM_Skill& sk)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 105;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	// serialize star
	{
		w->writeType(star);
	}
	// serialize sk
	{
		sk.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delEmployeeOK(const std::vector< uint32_t >& instids)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 106;
	w->writeType(pid);
	// serialize instids
	{
		uint32_t __len__ = (uint32_t)instids.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(instids[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::sycnEmployeeSoul(int32_t guid,uint32_t soulNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 107;
	w->writeType(pid);
	// serialize guid
	{
		w->writeType(guid);
	}
	// serialize soulNum
	{
		w->writeType(soulNum);
	}
	methodEnd();
}
void Server2ClientStub::initQuest(const std::vector< COM_QuestInst >& qlist,const std::vector< int32_t >& clist)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 108;
	w->writeType(pid);
	// serialize qlist
	{
		uint32_t __len__ = (uint32_t)qlist.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			qlist[i].serialize(w);
		}
	}
	// serialize clist
	{
		uint32_t __len__ = (uint32_t)clist.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(clist[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::acceptQuestOk(const COM_QuestInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 109;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::submitQuestOk(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 110;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void Server2ClientStub::giveupQuestOk(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 111;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void Server2ClientStub::updateQuestInst(const COM_QuestInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 112;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::requestContactInfoOk(const COM_ContactInfo& contact)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 113;
	w->writeType(pid);
	// serialize contact
	{
		contact.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::addFriendOK(const COM_ContactInfo& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 114;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delFriendOK(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 115;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Server2ClientStub::addBlacklistOK(const COM_ContactInfo& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 116;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::delBlacklistOK(uint32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 117;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void Server2ClientStub::findFriendFail()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 118;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::referrFriendOK(const std::vector< COM_ContactInfo >& insts)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 119;
	w->writeType(pid);
	// serialize insts
	{
		uint32_t __len__ = (uint32_t)insts.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			insts[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::requestFriendListOK(const std::vector< COM_ContactInfo >& insts)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 120;
	w->writeType(pid);
	// serialize insts
	{
		uint32_t __len__ = (uint32_t)insts.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			insts[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::lotteryOk(int32_t lotteryId,const std::vector< COM_DropItem >& dropItem)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 121;
	w->writeType(pid);
	// serialize lotteryId
	{
		w->writeType(lotteryId);
	}
	// serialize dropItem
	{
		uint32_t __len__ = (uint32_t)dropItem.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			dropItem[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::openGatherOK(const COM_Gather& gather)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 122;
	w->writeType(pid);
	// serialize gather
	{
		gather.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::miningOk(const std::vector< COM_DropItem >& items,const COM_Gather& gather,uint32_t gatherNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 123;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	// serialize gather
	{
		gather.serialize(w);
	}
	// serialize gatherNum
	{
		w->writeType(gatherNum);
	}
	methodEnd();
}
void Server2ClientStub::openCompound(uint32_t compoundId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 124;
	w->writeType(pid);
	// serialize compoundId
	{
		w->writeType(compoundId);
	}
	methodEnd();
}
void Server2ClientStub::compoundItemOk(const COM_Item& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 125;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::openBagGridOk(int32_t num)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 126;
	w->writeType(pid);
	// serialize num
	{
		w->writeType(num);
	}
	methodEnd();
}
void Server2ClientStub::requestChallengeOK(bool isOK)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 127;
	w->writeType(pid);
	// serialize isOK
	{
		w->writeType(isOK);
	}
	methodEnd();
}
void Server2ClientStub::requestMySelfJJCDataOK(const COM_EndlessStair& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 128;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::requestRivalOK(const std::vector< COM_EndlessStair >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 129;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::rivalTimeOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 130;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::checkMsgOK(const COM_SimplePlayerInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 131;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::requestMyAllbattleMsgOK(const std::vector< COM_JJCBattleMsg >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 132;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::myBattleMsgOK(const COM_JJCBattleMsg& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 133;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::requestJJCRankOK(uint32_t myRank,const std::vector< COM_EndlessStair >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 134;
	w->writeType(pid);
	// serialize myRank
	{
		w->writeType(myRank);
	}
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::requestLevelRankOK(uint32_t myRank,const std::vector< COM_ContactInfo >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 135;
	w->writeType(pid);
	// serialize myRank
	{
		w->writeType(myRank);
	}
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::requestBabyRankOK(uint32_t myRank,const std::vector< COM_BabyRankData >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 136;
	w->writeType(pid);
	// serialize myRank
	{
		w->writeType(myRank);
	}
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::requestEmpRankOK(uint32_t myRank,const std::vector< COM_EmployeeRankData >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 137;
	w->writeType(pid);
	// serialize myRank
	{
		w->writeType(myRank);
	}
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::requestPlayerFFRankOK(uint32_t myRank,const std::vector< COM_ContactInfo >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 138;
	w->writeType(pid);
	// serialize myRank
	{
		w->writeType(myRank);
	}
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::queryOnlinePlayerOK(bool isOnline)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 139;
	w->writeType(pid);
	// serialize isOnline
	{
		w->writeType(isOnline);
	}
	methodEnd();
}
void Server2ClientStub::queryPlayerOK(const COM_SimplePlayerInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 140;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::queryBabyOK(const COM_BabyInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 141;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::queryEmployeeOK(const COM_EmployeeInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 142;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::initGuide(uint32_t guideMask)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 143;
	w->writeType(pid);
	// serialize guideMask
	{
		w->writeType(guideMask);
	}
	methodEnd();
}
void Server2ClientStub::buyShopItemOk(int32_t id)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 144;
	w->writeType(pid);
	// serialize id
	{
		w->writeType(id);
	}
	methodEnd();
}
void Server2ClientStub::addPlayerTitle(int32_t title)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 145;
	w->writeType(pid);
	// serialize title
	{
		w->writeType(title);
	}
	methodEnd();
}
void Server2ClientStub::delPlayerTitle(int32_t title)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 146;
	w->writeType(pid);
	// serialize title
	{
		w->writeType(title);
	}
	methodEnd();
}
void Server2ClientStub::requestOpenBuyBox(float greenTime,float blueTime,int32_t greenFreeNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 147;
	w->writeType(pid);
	// serialize greenTime
	{
		w->writeType(greenTime);
	}
	// serialize blueTime
	{
		w->writeType(blueTime);
	}
	// serialize greenFreeNum
	{
		w->writeType(greenFreeNum);
	}
	methodEnd();
}
void Server2ClientStub::requestGreenBoxTimeOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 148;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::requestBlueBoxTimeOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 149;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::updateAchievementinfo(const COM_Achievement& achs)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 150;
	w->writeType(pid);
	// serialize achs
	{
		achs.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::syncOpenSystemFlag(uint64_t flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 151;
	w->writeType(pid);
	// serialize flag
	{
		w->writeType(flag);
	}
	methodEnd();
}
void Server2ClientStub::requestActivityRewardOK(uint32_t ar)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 152;
	w->writeType(pid);
	// serialize ar
	{
		w->writeType(ar);
	}
	methodEnd();
}
void Server2ClientStub::syncActivity(const COM_ActivityTable& table)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 153;
	w->writeType(pid);
	// serialize table
	{
		table.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateActivityStatus(ActivityType type,bool open)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 154;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize open
	{
		w->writeType(open);
	}
	methodEnd();
}
void Server2ClientStub::updateActivityCounter(ActivityType type,int32_t counter,int32_t reward)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 155;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize counter
	{
		w->writeType(counter);
	}
	// serialize reward
	{
		w->writeType(reward);
	}
	methodEnd();
}
void Server2ClientStub::syncExam(const COM_Exam& exam)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 156;
	w->writeType(pid);
	// serialize exam
	{
		exam.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::syncExamAnswer(const COM_Answer& answer)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 157;
	w->writeType(pid);
	// serialize answer
	{
		answer.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::petActivityNoNum(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 158;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Server2ClientStub::syncHundredInfo(const COM_HundredBattle& hb)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 159;
	w->writeType(pid);
	// serialize hb
	{
		hb.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::initSignUp(const std::vector< int32_t >& info,int32_t process,bool sign7,bool sign14,bool sign28)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 160;
	w->writeType(pid);
	// serialize info
	{
		uint32_t __len__ = (uint32_t)info.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(info[i]);
		}
	}
	// serialize process
	{
		w->writeType(process);
	}
	// serialize sign7
	{
		w->writeType(sign7);
	}
	// serialize sign14
	{
		w->writeType(sign14);
	}
	// serialize sign28
	{
		w->writeType(sign28);
	}
	methodEnd();
}
void Server2ClientStub::signUp(bool flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 161;
	w->writeType(pid);
	// serialize flag
	{
		w->writeType(flag);
	}
	methodEnd();
}
void Server2ClientStub::requestSignupRewardOk7()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 162;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::requestSignupRewardOk14()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 163;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::requestSignupRewardOk28()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 164;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::sycnDoubleExpTime(bool isFlag,float times)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 165;
	w->writeType(pid);
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	// serialize times
	{
		w->writeType(times);
	}
	methodEnd();
}
void Server2ClientStub::sycnStates(const std::vector< COM_State >& states)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 166;
	w->writeType(pid);
	// serialize states
	{
		uint32_t __len__ = (uint32_t)states.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			states[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::requestpvprankOK(const std::vector< COM_ContactInfo >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 167;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::syncMyJJCTeamMember()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 168;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::startMatchingOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 169;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::stopMatchingOK(float times)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 170;
	w->writeType(pid);
	// serialize times
	{
		w->writeType(times);
	}
	methodEnd();
}
void Server2ClientStub::updatePvpJJCinfo(const COM_PlayerVsPlayer& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 171;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::exitPvpJJCOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 172;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::syncEnemyPvpJJCPlayerInfo(const COM_SimpleInformation& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 173;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::syncEnemyPvpJJCTeamInfo(const std::vector< COM_SimpleInformation >& infos,uint32_t teamID_)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 174;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	// serialize teamID_
	{
		w->writeType(teamID_);
	}
	methodEnd();
}
void Server2ClientStub::openWarriorchooseUI()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 175;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::warriorStartOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 176;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::warriorStopOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 177;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::syncWarriorEnemyTeamInfo(const std::vector< COM_SimpleInformation >& infos,uint32_t teamID_)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 178;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	// serialize teamID_
	{
		w->writeType(teamID_);
	}
	methodEnd();
}
void Server2ClientStub::appendMail(const std::vector< COM_Mail >& mails)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 179;
	w->writeType(pid);
	// serialize mails
	{
		uint32_t __len__ = (uint32_t)mails.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			mails[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::delMail(int32_t mailId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 180;
	w->writeType(pid);
	// serialize mailId
	{
		w->writeType(mailId);
	}
	methodEnd();
}
void Server2ClientStub::updateMailOk(const COM_Mail& mail)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 181;
	w->writeType(pid);
	// serialize mail
	{
		mail.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::boardcastNotice(const std::string& content,bool isGm)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 182;
	w->writeType(pid);
	// serialize content
	{
		w->writeType(content);
	}
	// serialize isGm
	{
		w->writeType(isGm);
	}
	methodEnd();
}
void Server2ClientStub::createGuildOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 183;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::delGuildOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 184;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::leaveGuildOk(const std::string& who,bool isKick)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 185;
	w->writeType(pid);
	// serialize who
	{
		w->writeType(who);
	}
	// serialize isKick
	{
		w->writeType(isKick);
	}
	methodEnd();
}
void Server2ClientStub::initGuildData(const COM_Guild& guild)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 186;
	w->writeType(pid);
	// serialize guild
	{
		guild.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::initGuildMemberList(const std::vector< COM_GuildMember >& member)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 187;
	w->writeType(pid);
	// serialize member
	{
		uint32_t __len__ = (uint32_t)member.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			member[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::modifyGuildMemberList(const COM_GuildMember& member,ModifyListFlag flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 188;
	w->writeType(pid);
	// serialize member
	{
		member.serialize(w);
	}
	// serialize flag
	{
		uint8_t __e__ = (uint8_t)flag;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::modifyGuildList(const COM_GuildViewerData& data,ModifyListFlag flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 189;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	// serialize flag
	{
		uint8_t __e__ = (uint8_t)flag;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::queryGuildListResult(int16_t page,int16_t pageNum,const std::vector< COM_GuildViewerData >& guildList)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 190;
	w->writeType(pid);
	// serialize page
	{
		w->writeType(page);
	}
	// serialize pageNum
	{
		w->writeType(pageNum);
	}
	// serialize guildList
	{
		uint32_t __len__ = (uint32_t)guildList.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			guildList[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::inviteGuild(const std::string& sendName,const std::string& guildName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 191;
	w->writeType(pid);
	// serialize sendName
	{
		w->writeType(sendName);
	}
	// serialize guildName
	{
		w->writeType(guildName);
	}
	methodEnd();
}
void Server2ClientStub::updateGuildShopItems(const std::vector< COM_GuildShopItem >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 192;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::updateGuildBuilding(GuildBuildingType type,const COM_GuildBuilding& building)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 193;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize building
	{
		building.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateGuildMyMember(const COM_GuildMember& member)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 194;
	w->writeType(pid);
	// serialize member
	{
		member.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::levelupGuildSkillOk(const COM_Skill& skInst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 195;
	w->writeType(pid);
	// serialize skInst
	{
		skInst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::presentGuildItemOk(int32_t val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 196;
	w->writeType(pid);
	// serialize val
	{
		w->writeType(val);
	}
	methodEnd();
}
void Server2ClientStub::progenitusAddExpOk(const COM_GuildProgen& mInst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 197;
	w->writeType(pid);
	// serialize mInst
	{
		mInst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::setProgenitusPositionOk(const std::vector< int32_t >& positions)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 198;
	w->writeType(pid);
	// serialize positions
	{
		uint32_t __len__ = (uint32_t)positions.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(positions[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::updateGuildFundz(int32_t val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 199;
	w->writeType(pid);
	// serialize val
	{
		w->writeType(val);
	}
	methodEnd();
}
void Server2ClientStub::updateGuildMemberContribution(int32_t val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 200;
	w->writeType(pid);
	// serialize val
	{
		w->writeType(val);
	}
	methodEnd();
}
void Server2ClientStub::openGuildBattle(const std::string& otherName,int32_t playerNum,int32_t level,bool isLeft,int32_t lstime)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 201;
	w->writeType(pid);
	// serialize otherName
	{
		w->writeType(otherName);
	}
	// serialize playerNum
	{
		w->writeType(playerNum);
	}
	// serialize level
	{
		w->writeType(level);
	}
	// serialize isLeft
	{
		w->writeType(isLeft);
	}
	// serialize lstime
	{
		w->writeType(lstime);
	}
	methodEnd();
}
void Server2ClientStub::startGuildBattle(const std::string& otherName,int32_t otherCon,int32_t selfCon)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 202;
	w->writeType(pid);
	// serialize otherName
	{
		w->writeType(otherName);
	}
	// serialize otherCon
	{
		w->writeType(otherCon);
	}
	// serialize selfCon
	{
		w->writeType(selfCon);
	}
	methodEnd();
}
void Server2ClientStub::closeGuildBattle(bool isWinner)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 203;
	w->writeType(pid);
	// serialize isWinner
	{
		w->writeType(isWinner);
	}
	methodEnd();
}
void Server2ClientStub::syncGuildBattleWinCount(int32_t myWin,int32_t otherWin)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 204;
	w->writeType(pid);
	// serialize myWin
	{
		w->writeType(myWin);
	}
	// serialize otherWin
	{
		w->writeType(otherWin);
	}
	methodEnd();
}
void Server2ClientStub::initMySelling(const std::vector< COM_SellItem >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 205;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::initMySelled(const std::vector< COM_SelledItem >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 206;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::fetchSellingOk(const std::vector< COM_SellItem >& items,int32_t total)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 207;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	// serialize total
	{
		w->writeType(total);
	}
	methodEnd();
}
void Server2ClientStub::fetchSellingOk2(const std::vector< COM_SellItem >& items,int32_t total)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 208;
	w->writeType(pid);
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	// serialize total
	{
		w->writeType(total);
	}
	methodEnd();
}
void Server2ClientStub::sellingOk(const COM_SellItem& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 209;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::selledOk(const COM_SelledItem& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 210;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::unsellingOk(int32_t sellid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 211;
	w->writeType(pid);
	// serialize sellid
	{
		w->writeType(sellid);
	}
	methodEnd();
}
void Server2ClientStub::redemptionSpreeOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 212;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::insertState(const COM_State& st)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 213;
	w->writeType(pid);
	// serialize st
	{
		st.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updattState(const COM_State& st)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 214;
	w->writeType(pid);
	// serialize st
	{
		st.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::removeState(uint32_t stid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 215;
	w->writeType(pid);
	// serialize stid
	{
		w->writeType(stid);
	}
	methodEnd();
}
void Server2ClientStub::requestFixItemOk(const COM_Item& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 216;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::makeDebirsItemOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 217;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::updateMagicItem(int32_t level,int32_t exp)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 218;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	// serialize exp
	{
		w->writeType(exp);
	}
	methodEnd();
}
void Server2ClientStub::changeMagicJobOk(JobType job)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 219;
	w->writeType(pid);
	// serialize job
	{
		uint8_t __e__ = (uint8_t)job;
		w->writeType(__e__);
	}
	methodEnd();
}
void Server2ClientStub::magicItemTupoOk(int32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 220;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Server2ClientStub::zhuanpanOK(const std::vector< uint32_t >& pond)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 221;
	w->writeType(pid);
	// serialize pond
	{
		uint32_t __len__ = (uint32_t)pond.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(pond[i]);
		}
	}
	methodEnd();
}
void Server2ClientStub::updateZhuanpanNotice(const COM_Zhuanpan& zhuanp)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 222;
	w->writeType(pid);
	// serialize zhuanp
	{
		zhuanp.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::sycnZhuanpanData(const COM_ZhuanpanData& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 223;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::copynonum(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 224;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void Server2ClientStub::sceneFilterOk(const std::vector< SceneFilterType >& sfType)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 225;
	w->writeType(pid);
	// serialize sfType
	{
		uint32_t __len__ = (uint32_t)sfType.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			uint8_t __e__ = (uint8_t)sfType[i];
			w->writeType(__e__);
		}
	}
	methodEnd();
}
void Server2ClientStub::wishingOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 226;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::shareWishOK(const COM_Wish& wish)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 227;
	w->writeType(pid);
	// serialize wish
	{
		wish.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::leaderCloseDialogOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 228;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::startOnlineTime()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 229;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::requestOnlineTimeRewardOK(uint32_t index)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 230;
	w->writeType(pid);
	// serialize index
	{
		w->writeType(index);
	}
	methodEnd();
}
void Server2ClientStub::sycnVipflag(bool flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 231;
	w->writeType(pid);
	// serialize flag
	{
		w->writeType(flag);
	}
	methodEnd();
}
void Server2ClientStub::buyFundOK(bool flag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 232;
	w->writeType(pid);
	// serialize flag
	{
		w->writeType(flag);
	}
	methodEnd();
}
void Server2ClientStub::requestFundRewardOK(uint32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 233;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Server2ClientStub::firstRechargeOK(bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 234;
	w->writeType(pid);
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void Server2ClientStub::firstRechargeGiftOK(bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 235;
	w->writeType(pid);
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void Server2ClientStub::agencyActivity(ADType type,bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 236;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void Server2ClientStub::updateFestival(const COM_ADLoginTotal& festival)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 237;
	w->writeType(pid);
	// serialize festival
	{
		festival.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateSelfRecharge(const COM_ADChargeTotal& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 238;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateSysRecharge(const COM_ADChargeTotal& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 239;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateSelfDiscountStore(const COM_ADDiscountStore& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 240;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateSysDiscountStore(const COM_ADDiscountStore& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 241;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateSelfOnceRecharge(const COM_ADChargeEvery& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 242;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateSysOnceRecharge(const COM_ADChargeEvery& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 243;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::openCardOK(const COM_ADCardsContent& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 244;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::resetCardOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 245;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::sycnHotRole(const COM_ADHotRole& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 246;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::hotRoleBuyOk(uint16_t buyNum)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 247;
	w->writeType(pid);
	// serialize buyNum
	{
		w->writeType(buyNum);
	}
	methodEnd();
}
void Server2ClientStub::updateSevenday(const COM_Sevenday& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 248;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateEmployeeActivity(const COM_ADEmployeeTotal& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 249;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateMinGiftActivity(const COM_ADGiftBag& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 250;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateIntegralShop(const COM_IntegralData& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 251;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::updateShowBaby(uint32_t playerId,uint32_t showBabyTableId,const std::string& showBabyName)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 252;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize showBabyTableId
	{
		w->writeType(showBabyTableId);
	}
	// serialize showBabyName
	{
		w->writeType(showBabyName);
	}
	methodEnd();
}
void Server2ClientStub::updateMySelfRecharge(const COM_ADChargeTotal& val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 253;
	w->writeType(pid);
	// serialize val
	{
		val.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::verificationSMSOk(const std::string& phoneNumber)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 254;
	w->writeType(pid);
	// serialize phoneNumber
	{
		w->writeType(phoneNumber);
	}
	methodEnd();
}
void Server2ClientStub::requestLevelGiftOK(int32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 255;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void Server2ClientStub::sycnConvertExp(int32_t val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 256;
	w->writeType(pid);
	// serialize val
	{
		w->writeType(val);
	}
	methodEnd();
}
void Server2ClientStub::wearFuwenOk(const COM_Item& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 257;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::takeoffFuwenOk(int32_t slot)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 258;
	w->writeType(pid);
	// serialize slot
	{
		w->writeType(slot);
	}
	methodEnd();
}
void Server2ClientStub::compFuwenOk()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 259;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::requestEmployeeQuestOk(const std::vector< COM_EmployeeQuestInst >& questList)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 260;
	w->writeType(pid);
	// serialize questList
	{
		uint32_t __len__ = (uint32_t)questList.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			questList[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::acceptEmployeeQuestOk(const COM_EmployeeQuestInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 261;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::submitEmployeeQuestOk(int32_t questId,bool isSuccess)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 262;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	// serialize isSuccess
	{
		w->writeType(isSuccess);
	}
	methodEnd();
}
void Server2ClientStub::sycnCrystal(const COM_CrystalData& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 263;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void Server2ClientStub::crystalUpLeveResult(bool isOK)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 264;
	w->writeType(pid);
	// serialize isOK
	{
		w->writeType(isOK);
	}
	methodEnd();
}
void Server2ClientStub::resetCrystalPropOK()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 265;
	w->writeType(pid);
	methodEnd();
}
void Server2ClientStub::sycnCourseGift(const std::vector< COM_CourseGift >& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 266;
	w->writeType(pid);
	// serialize data
	{
		uint32_t __len__ = (uint32_t)data.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			data[i].serialize(w);
		}
	}
	methodEnd();
}
void Server2ClientStub::orderOk(const std::string& orderId,int32_t shopId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 267;
	w->writeType(pid);
	// serialize orderId
	{
		w->writeType(orderId);
	}
	// serialize shopId
	{
		w->writeType(shopId);
	}
	methodEnd();
}
void Server2ClientStub::updateRandSubmitQuestCount(int32_t submitCount)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 268;
	w->writeType(pid);
	// serialize submitCount
	{
		w->writeType(submitCount);
	}
	methodEnd();
}
void Server2ClientStub::updateTeamMember(int32_t playerId,bool isMember)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 269;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize isMember
	{
		w->writeType(isMember);
	}
	methodEnd();
}
bool Server2ClientProxy::pong(ProtocolReader* __r__)
{
	return pong();
}
bool Server2ClientProxy::errorno(ProtocolReader* __r__)
{
	ErrorNo e=(ErrorNo)(0);
	// deserialize e
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 158) return false;
		e = (ErrorNo)__e__;
	}
	return errorno(e);
}
bool Server2ClientProxy::teamerrorno(ProtocolReader* __r__)
{
	std::string name;
	ErrorNo e=(ErrorNo)(0);
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	// deserialize e
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 158) return false;
		e = (ErrorNo)__e__;
	}
	return teamerrorno(name,e);
}
bool Server2ClientProxy::reconnection(ProtocolReader* __r__)
{
	COM_ReconnectInfo recInfo;
	// deserialize recInfo
	{
		if(!recInfo.deserialize(__r__)) return false;
	}
	return reconnection(recInfo);
}
bool Server2ClientProxy::sessionfailed(ProtocolReader* __r__)
{
	return sessionfailed();
}
bool Server2ClientProxy::loginok(ProtocolReader* __r__)
{
	std::string sessionkey;
	std::vector< COM_SimpleInformation > players;
	// deserialize sessionkey
	{
		if(!__r__->readType(sessionkey, 65535)) return false;
	}
	// deserialize players
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		players.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!players[i].deserialize(__r__)) return false;
		}
	}
	return loginok(sessionkey,players);
}
bool Server2ClientProxy::logoutOk(ProtocolReader* __r__)
{
	return logoutOk();
}
bool Server2ClientProxy::createPlayerOk(ProtocolReader* __r__)
{
	COM_SimpleInformation player;
	// deserialize player
	{
		if(!player.deserialize(__r__)) return false;
	}
	return createPlayerOk(player);
}
bool Server2ClientProxy::deletePlayerOk(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return deletePlayerOk(name);
}
bool Server2ClientProxy::enterGameOk(ProtocolReader* __r__)
{
	COM_PlayerInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return enterGameOk(inst);
}
bool Server2ClientProxy::initBabies(ProtocolReader* __r__)
{
	std::vector< COM_BabyInst > insts;
	// deserialize insts
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		insts.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!insts[i].deserialize(__r__)) return false;
		}
	}
	return initBabies(insts);
}
bool Server2ClientProxy::initEmployees(ProtocolReader* __r__)
{
	std::vector< COM_EmployeeInst > insts;
	bool isFlag=false;
	// deserialize insts
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		insts.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!insts[i].deserialize(__r__)) return false;
		}
	}
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return initEmployees(insts,isFlag);
}
bool Server2ClientProxy::initEmpBattleGroup(ProtocolReader* __r__)
{
	COM_BattleEmp bep;
	// deserialize bep
	{
		if(!bep.deserialize(__r__)) return false;
	}
	return initEmpBattleGroup(bep);
}
bool Server2ClientProxy::initNpc(ProtocolReader* __r__)
{
	std::vector< int32_t > npcList;
	// deserialize npcList
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		npcList.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(npcList[i])) return false;
		}
	}
	return initNpc(npcList);
}
bool Server2ClientProxy::initAchievement(ProtocolReader* __r__)
{
	std::vector< COM_Achievement > actlist;
	// deserialize actlist
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		actlist.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!actlist[i].deserialize(__r__)) return false;
		}
	}
	return initAchievement(actlist);
}
bool Server2ClientProxy::initGather(ProtocolReader* __r__)
{
	uint32_t allnum=0;
	std::vector< COM_Gather > gathers;
	// deserialize allnum
	{
		if(!__r__->readType(allnum)) return false;
	}
	// deserialize gathers
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		gathers.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!gathers[i].deserialize(__r__)) return false;
		}
	}
	return initGather(allnum,gathers);
}
bool Server2ClientProxy::initcompound(ProtocolReader* __r__)
{
	std::vector< uint32_t > compounds;
	// deserialize compounds
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		compounds.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(compounds[i])) return false;
		}
	}
	return initcompound(compounds);
}
bool Server2ClientProxy::addBaby(ProtocolReader* __r__)
{
	COM_BabyInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return addBaby(inst);
}
bool Server2ClientProxy::refreshBaby(ProtocolReader* __r__)
{
	COM_BabyInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return refreshBaby(inst);
}
bool Server2ClientProxy::delBabyOK(ProtocolReader* __r__)
{
	uint32_t babyInstId=0;
	// deserialize babyInstId
	{
		if(!__r__->readType(babyInstId)) return false;
	}
	return delBabyOK(babyInstId);
}
bool Server2ClientProxy::changeBabyNameOK(ProtocolReader* __r__)
{
	uint32_t babyId=0;
	std::string name;
	// deserialize babyId
	{
		if(!__r__->readType(babyId)) return false;
	}
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return changeBabyNameOK(babyId,name);
}
bool Server2ClientProxy::remouldBabyOK(ProtocolReader* __r__)
{
	uint32_t instid=0;
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return remouldBabyOK(instid);
}
bool Server2ClientProxy::intensifyBabyOK(ProtocolReader* __r__)
{
	uint32_t babyid=0;
	uint32_t intensifyLevel=0;
	// deserialize babyid
	{
		if(!__r__->readType(babyid)) return false;
	}
	// deserialize intensifyLevel
	{
		if(!__r__->readType(intensifyLevel)) return false;
	}
	return intensifyBabyOK(babyid,intensifyLevel);
}
bool Server2ClientProxy::learnSkillOk(ProtocolReader* __r__)
{
	COM_Skill inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return learnSkillOk(inst);
}
bool Server2ClientProxy::forgetSkillOk(ProtocolReader* __r__)
{
	uint32_t skid=0;
	// deserialize skid
	{
		if(!__r__->readType(skid)) return false;
	}
	return forgetSkillOk(skid);
}
bool Server2ClientProxy::addSkillExp(ProtocolReader* __r__)
{
	uint32_t skid=0;
	uint32_t uExp=0;
	ItemUseFlag flag=(ItemUseFlag)(0);
	// deserialize skid
	{
		if(!__r__->readType(skid)) return false;
	}
	// deserialize uExp
	{
		if(!__r__->readType(uExp)) return false;
	}
	// deserialize flag
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 4) return false;
		flag = (ItemUseFlag)__e__;
	}
	return addSkillExp(skid,uExp,flag);
}
bool Server2ClientProxy::babyLearnSkillOK(ProtocolReader* __r__)
{
	uint32_t instId=0;
	uint32_t newSkId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize newSkId
	{
		if(!__r__->readType(newSkId)) return false;
	}
	return babyLearnSkillOK(instId,newSkId);
}
bool Server2ClientProxy::skillLevelUp(ProtocolReader* __r__)
{
	uint32_t instId=0;
	COM_Skill inst;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return skillLevelUp(instId,inst);
}
bool Server2ClientProxy::joinScene(ProtocolReader* __r__)
{
	COM_SceneInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return joinScene(info);
}
bool Server2ClientProxy::joinCopySceneOK(ProtocolReader* __r__)
{
	int32_t secneid=0;
	// deserialize secneid
	{
		if(!__r__->readType(secneid)) return false;
	}
	return joinCopySceneOK(secneid);
}
bool Server2ClientProxy::initCopyNums(ProtocolReader* __r__)
{
	return initCopyNums();
}
bool Server2ClientProxy::addToScene(ProtocolReader* __r__)
{
	COM_ScenePlayerInformation inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return addToScene(inst);
}
bool Server2ClientProxy::delFormScene(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delFormScene(instId);
}
bool Server2ClientProxy::move2(ProtocolReader* __r__)
{
	int32_t instId=0;
	COM_FPosition pos;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize pos
	{
		if(!pos.deserialize(__r__)) return false;
	}
	return move2(instId,pos);
}
bool Server2ClientProxy::cantMove(ProtocolReader* __r__)
{
	return cantMove();
}
bool Server2ClientProxy::querySimplePlayerInstOk(ProtocolReader* __r__)
{
	COM_SimplePlayerInst player;
	// deserialize player
	{
		if(!player.deserialize(__r__)) return false;
	}
	return querySimplePlayerInstOk(player);
}
bool Server2ClientProxy::transfor2(ProtocolReader* __r__)
{
	int32_t instId=0;
	COM_FPosition pos;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize pos
	{
		if(!pos.deserialize(__r__)) return false;
	}
	return transfor2(instId,pos);
}
bool Server2ClientProxy::openScene(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	return openScene(sceneId);
}
bool Server2ClientProxy::autoBattleResult(ProtocolReader* __r__)
{
	bool isOk=false;
	// deserialize isOk
	{
		if(!__r__->readType(isOk)) return false;
	}
	return autoBattleResult(isOk);
}
bool Server2ClientProxy::talked2Npc(ProtocolReader* __r__)
{
	int32_t npcId=0;
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	return talked2Npc(npcId);
}
bool Server2ClientProxy::talked2Player(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return talked2Player(playerId);
}
bool Server2ClientProxy::useItemOk(ProtocolReader* __r__)
{
	int32_t itemId=0;
	int32_t stack=0;
	// deserialize itemId
	{
		if(!__r__->readType(itemId)) return false;
	}
	// deserialize stack
	{
		if(!__r__->readType(stack)) return false;
	}
	return useItemOk(itemId,stack);
}
bool Server2ClientProxy::syncBattleStatus(ProtocolReader* __r__)
{
	int32_t playerId=0;
	bool inBattle=false;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize inBattle
	{
		if(!__r__->readType(inBattle)) return false;
	}
	return syncBattleStatus(playerId,inBattle);
}
bool Server2ClientProxy::enterBattleOk(ProtocolReader* __r__)
{
	COM_InitBattle initBattle;
	// deserialize initBattle
	{
		if(!initBattle.deserialize(__r__)) return false;
	}
	return enterBattleOk(initBattle);
}
bool Server2ClientProxy::exitBattleOk(ProtocolReader* __r__)
{
	BattleJudgeType bjt=(BattleJudgeType)(0);
	COM_BattleOverClearing init;
	// deserialize bjt
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 4) return false;
		bjt = (BattleJudgeType)__e__;
	}
	// deserialize init
	{
		if(!init.deserialize(__r__)) return false;
	}
	return exitBattleOk(bjt,init);
}
bool Server2ClientProxy::syncOrderOk(ProtocolReader* __r__)
{
	uint32_t uid=0;
	// deserialize uid
	{
		if(!__r__->readType(uid)) return false;
	}
	return syncOrderOk(uid);
}
bool Server2ClientProxy::syncOrderOkEX(ProtocolReader* __r__)
{
	return syncOrderOkEX();
}
bool Server2ClientProxy::syncOneTurnAction(ProtocolReader* __r__)
{
	COM_BattleReport reports;
	// deserialize reports
	{
		if(!reports.deserialize(__r__)) return false;
	}
	return syncOneTurnAction(reports);
}
bool Server2ClientProxy::syncProperties(ProtocolReader* __r__)
{
	uint32_t guid=0;
	std::vector< COM_PropValue > props;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	// deserialize props
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		props.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!props[i].deserialize(__r__)) return false;
		}
	}
	return syncProperties(guid,props);
}
bool Server2ClientProxy::receiveChat(ProtocolReader* __r__)
{
	COM_ChatInfo info;
	COM_ContactInfo myinfo;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	// deserialize myinfo
	{
		if(!myinfo.deserialize(__r__)) return false;
	}
	return receiveChat(info,myinfo);
}
bool Server2ClientProxy::requestAudioOk(ProtocolReader* __r__)
{
	int32_t audioId=0;
	std::vector< uint8_t > content;
	// deserialize audioId
	{
		if(!__r__->readType(audioId)) return false;
	}
	// deserialize content
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		content.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(content[i])) return false;
		}
	}
	return requestAudioOk(audioId,content);
}
bool Server2ClientProxy::publishItemInstRes(ProtocolReader* __r__)
{
	COM_ShowItemInstInfo info;
	ChatKind type=(ChatKind)(0);
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 8) return false;
		type = (ChatKind)__e__;
	}
	return publishItemInstRes(info,type);
}
bool Server2ClientProxy::queryItemInstRes(ProtocolReader* __r__)
{
	COM_ShowItemInst item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return queryItemInstRes(item);
}
bool Server2ClientProxy::publishBabyInstRes(ProtocolReader* __r__)
{
	COM_ShowbabyInstInfo info;
	ChatKind type=(ChatKind)(0);
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 8) return false;
		type = (ChatKind)__e__;
	}
	return publishBabyInstRes(info,type);
}
bool Server2ClientProxy::queryBabyInstRes(ProtocolReader* __r__)
{
	COM_ShowbabyInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return queryBabyInstRes(inst);
}
bool Server2ClientProxy::setNoTalkTime(ProtocolReader* __r__)
{
	float t=0;
	// deserialize t
	{
		if(!__r__->readType(t)) return false;
	}
	return setNoTalkTime(t);
}
bool Server2ClientProxy::addNpc(ProtocolReader* __r__)
{
	std::vector< int32_t > npcList;
	// deserialize npcList
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		npcList.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(npcList[i])) return false;
		}
	}
	return addNpc(npcList);
}
bool Server2ClientProxy::delNpc(ProtocolReader* __r__)
{
	std::vector< int32_t > npcList;
	// deserialize npcList
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		npcList.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(npcList[i])) return false;
		}
	}
	return delNpc(npcList);
}
bool Server2ClientProxy::setTeamLeader(ProtocolReader* __r__)
{
	int32_t playerId=0;
	bool isLeader=false;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize isLeader
	{
		if(!__r__->readType(isLeader)) return false;
	}
	return setTeamLeader(playerId,isLeader);
}
bool Server2ClientProxy::initBag(ProtocolReader* __r__)
{
	std::vector< COM_Item > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return initBag(items);
}
bool Server2ClientProxy::addBagItem(ProtocolReader* __r__)
{
	COM_Item item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return addBagItem(item);
}
bool Server2ClientProxy::delBagItem(ProtocolReader* __r__)
{
	uint16_t slot=0;
	// deserialize slot
	{
		if(!__r__->readType(slot)) return false;
	}
	return delBagItem(slot);
}
bool Server2ClientProxy::updateBagItem(ProtocolReader* __r__)
{
	COM_Item item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return updateBagItem(item);
}
bool Server2ClientProxy::depositItemOK(ProtocolReader* __r__)
{
	COM_Item item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return depositItemOK(item);
}
bool Server2ClientProxy::getoutItemOK(ProtocolReader* __r__)
{
	uint16_t slot=0;
	// deserialize slot
	{
		if(!__r__->readType(slot)) return false;
	}
	return getoutItemOK(slot);
}
bool Server2ClientProxy::depositBabyOK(ProtocolReader* __r__)
{
	COM_BabyInst baby;
	// deserialize baby
	{
		if(!baby.deserialize(__r__)) return false;
	}
	return depositBabyOK(baby);
}
bool Server2ClientProxy::getoutBabyOK(ProtocolReader* __r__)
{
	uint16_t slot=0;
	// deserialize slot
	{
		if(!__r__->readType(slot)) return false;
	}
	return getoutBabyOK(slot);
}
bool Server2ClientProxy::sortItemStorageOK(ProtocolReader* __r__)
{
	std::vector< COM_Item > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return sortItemStorageOK(items);
}
bool Server2ClientProxy::sortBabyStorageOK(ProtocolReader* __r__)
{
	std::vector< uint32_t > babys;
	// deserialize babys
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		babys.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(babys[i])) return false;
		}
	}
	return sortBabyStorageOK(babys);
}
bool Server2ClientProxy::initItemStorage(ProtocolReader* __r__)
{
	uint16_t gridNum=0;
	std::vector< COM_Item > items;
	// deserialize gridNum
	{
		if(!__r__->readType(gridNum)) return false;
	}
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return initItemStorage(gridNum,items);
}
bool Server2ClientProxy::initBabyStorage(ProtocolReader* __r__)
{
	uint16_t gridNum=0;
	std::vector< COM_BabyInst > babys;
	// deserialize gridNum
	{
		if(!__r__->readType(gridNum)) return false;
	}
	// deserialize babys
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		babys.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!babys[i].deserialize(__r__)) return false;
		}
	}
	return initBabyStorage(gridNum,babys);
}
bool Server2ClientProxy::openStorageGrid(ProtocolReader* __r__)
{
	StorageType tp=(StorageType)(0);
	uint16_t gridNum=0;
	// deserialize tp
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 2) return false;
		tp = (StorageType)__e__;
	}
	// deserialize gridNum
	{
		if(!__r__->readType(gridNum)) return false;
	}
	return openStorageGrid(tp,gridNum);
}
bool Server2ClientProxy::delStorageBabyOK(ProtocolReader* __r__)
{
	uint16_t slot=0;
	// deserialize slot
	{
		if(!__r__->readType(slot)) return false;
	}
	return delStorageBabyOK(slot);
}
bool Server2ClientProxy::initPlayerEquips(ProtocolReader* __r__)
{
	std::vector< COM_Item > equips;
	// deserialize equips
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		equips.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!equips[i].deserialize(__r__)) return false;
		}
	}
	return initPlayerEquips(equips);
}
bool Server2ClientProxy::wearEquipmentOk(ProtocolReader* __r__)
{
	uint32_t target=0;
	COM_Item equip;
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize equip
	{
		if(!equip.deserialize(__r__)) return false;
	}
	return wearEquipmentOk(target,equip);
}
bool Server2ClientProxy::scenePlayerWearEquipment(ProtocolReader* __r__)
{
	uint32_t target=0;
	uint32_t itemId=0;
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize itemId
	{
		if(!__r__->readType(itemId)) return false;
	}
	return scenePlayerWearEquipment(target,itemId);
}
bool Server2ClientProxy::delEquipmentOk(ProtocolReader* __r__)
{
	uint32_t target=0;
	uint32_t itemInstId=0;
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize itemInstId
	{
		if(!__r__->readType(itemInstId)) return false;
	}
	return delEquipmentOk(target,itemInstId);
}
bool Server2ClientProxy::scenePlayerDoffEquipment(ProtocolReader* __r__)
{
	uint32_t target=0;
	uint32_t itemId=0;
	// deserialize target
	{
		if(!__r__->readType(target)) return false;
	}
	// deserialize itemId
	{
		if(!__r__->readType(itemId)) return false;
	}
	return scenePlayerDoffEquipment(target,itemId);
}
bool Server2ClientProxy::sortBagItemOk(ProtocolReader* __r__)
{
	return sortBagItemOk();
}
bool Server2ClientProxy::jointLobbyOk(ProtocolReader* __r__)
{
	std::vector< COM_SimpleTeamInfo > infos;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return jointLobbyOk(infos);
}
bool Server2ClientProxy::exitLobbyOk(ProtocolReader* __r__)
{
	return exitLobbyOk();
}
bool Server2ClientProxy::syncDelLobbyTeam(ProtocolReader* __r__)
{
	uint32_t teamId=0;
	// deserialize teamId
	{
		if(!__r__->readType(teamId)) return false;
	}
	return syncDelLobbyTeam(teamId);
}
bool Server2ClientProxy::syncUpdateLobbyTeam(ProtocolReader* __r__)
{
	COM_SimpleTeamInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return syncUpdateLobbyTeam(info);
}
bool Server2ClientProxy::syncAddLobbyTeam(ProtocolReader* __r__)
{
	COM_SimpleTeamInfo team;
	// deserialize team
	{
		if(!team.deserialize(__r__)) return false;
	}
	return syncAddLobbyTeam(team);
}
bool Server2ClientProxy::createTeamOk(ProtocolReader* __r__)
{
	COM_TeamInfo team;
	// deserialize team
	{
		if(!team.deserialize(__r__)) return false;
	}
	return createTeamOk(team);
}
bool Server2ClientProxy::changeTeamOk(ProtocolReader* __r__)
{
	COM_TeamInfo team;
	// deserialize team
	{
		if(!team.deserialize(__r__)) return false;
	}
	return changeTeamOk(team);
}
bool Server2ClientProxy::joinTeamOk(ProtocolReader* __r__)
{
	COM_TeamInfo team;
	// deserialize team
	{
		if(!team.deserialize(__r__)) return false;
	}
	return joinTeamOk(team);
}
bool Server2ClientProxy::addTeamMember(ProtocolReader* __r__)
{
	COM_SimplePlayerInst info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return addTeamMember(info);
}
bool Server2ClientProxy::delTeamMember(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delTeamMember(instId);
}
bool Server2ClientProxy::changeTeamLeaderOk(ProtocolReader* __r__)
{
	int32_t uuid=0;
	// deserialize uuid
	{
		if(!__r__->readType(uuid)) return false;
	}
	return changeTeamLeaderOk(uuid);
}
bool Server2ClientProxy::exitTeamOk(ProtocolReader* __r__)
{
	bool iskick=false;
	// deserialize iskick
	{
		if(!__r__->readType(iskick)) return false;
	}
	return exitTeamOk(iskick);
}
bool Server2ClientProxy::updateTeam(ProtocolReader* __r__)
{
	COM_TeamInfo team;
	// deserialize team
	{
		if(!team.deserialize(__r__)) return false;
	}
	return updateTeam(team);
}
bool Server2ClientProxy::joinTeamRoomOK(ProtocolReader* __r__)
{
	COM_TeamInfo team;
	// deserialize team
	{
		if(!team.deserialize(__r__)) return false;
	}
	return joinTeamRoomOK(team);
}
bool Server2ClientProxy::inviteJoinTeam(ProtocolReader* __r__)
{
	uint32_t teamId=0;
	std::string name;
	// deserialize teamId
	{
		if(!__r__->readType(teamId)) return false;
	}
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return inviteJoinTeam(teamId,name);
}
bool Server2ClientProxy::syncTeamDirtyProp(ProtocolReader* __r__)
{
	int32_t guid=0;
	std::vector< COM_PropValue > props;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	// deserialize props
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		props.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!props[i].deserialize(__r__)) return false;
		}
	}
	return syncTeamDirtyProp(guid,props);
}
bool Server2ClientProxy::leaveTeamOk(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return leaveTeamOk(playerId);
}
bool Server2ClientProxy::backTeamOK(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return backTeamOK(playerId);
}
bool Server2ClientProxy::teamCallMemberBack(ProtocolReader* __r__)
{
	return teamCallMemberBack();
}
bool Server2ClientProxy::refuseBackTeamOk(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return refuseBackTeamOk(playerId);
}
bool Server2ClientProxy::requestJoinTeamTranspond(ProtocolReader* __r__)
{
	std::string reqName;
	// deserialize reqName
	{
		if(!__r__->readType(reqName, 65535)) return false;
	}
	return requestJoinTeamTranspond(reqName);
}
bool Server2ClientProxy::drawLotteryBoxRep(ProtocolReader* __r__)
{
	std::vector< COM_Item > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return drawLotteryBoxRep(items);
}
bool Server2ClientProxy::addEmployee(ProtocolReader* __r__)
{
	COM_EmployeeInst employee;
	// deserialize employee
	{
		if(!employee.deserialize(__r__)) return false;
	}
	return addEmployee(employee);
}
bool Server2ClientProxy::battleEmployee(ProtocolReader* __r__)
{
	int32_t empId=0;
	EmployeesBattleGroup group=(EmployeesBattleGroup)(0);
	bool forbattle=false;
	// deserialize empId
	{
		if(!__r__->readType(empId)) return false;
	}
	// deserialize group
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 5) return false;
		group = (EmployeesBattleGroup)__e__;
	}
	// deserialize forbattle
	{
		if(!__r__->readType(forbattle)) return false;
	}
	return battleEmployee(empId,group,forbattle);
}
bool Server2ClientProxy::changeEmpBattleGroupOK(ProtocolReader* __r__)
{
	EmployeesBattleGroup group=(EmployeesBattleGroup)(0);
	// deserialize group
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 5) return false;
		group = (EmployeesBattleGroup)__e__;
	}
	return changeEmpBattleGroupOK(group);
}
bool Server2ClientProxy::evolveOK(ProtocolReader* __r__)
{
	int32_t guid=0;
	QualityColor qc=(QualityColor)(0);
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	// deserialize qc
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 16) return false;
		qc = (QualityColor)__e__;
	}
	return evolveOK(guid,qc);
}
bool Server2ClientProxy::upStarOK(ProtocolReader* __r__)
{
	int32_t guid=0;
	int32_t star=0;
	COM_Skill sk;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	// deserialize star
	{
		if(!__r__->readType(star)) return false;
	}
	// deserialize sk
	{
		if(!sk.deserialize(__r__)) return false;
	}
	return upStarOK(guid,star,sk);
}
bool Server2ClientProxy::delEmployeeOK(ProtocolReader* __r__)
{
	std::vector< uint32_t > instids;
	// deserialize instids
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		instids.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(instids[i])) return false;
		}
	}
	return delEmployeeOK(instids);
}
bool Server2ClientProxy::sycnEmployeeSoul(ProtocolReader* __r__)
{
	int32_t guid=0;
	uint32_t soulNum=0;
	// deserialize guid
	{
		if(!__r__->readType(guid)) return false;
	}
	// deserialize soulNum
	{
		if(!__r__->readType(soulNum)) return false;
	}
	return sycnEmployeeSoul(guid,soulNum);
}
bool Server2ClientProxy::initQuest(ProtocolReader* __r__)
{
	std::vector< COM_QuestInst > qlist;
	std::vector< int32_t > clist;
	// deserialize qlist
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		qlist.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!qlist[i].deserialize(__r__)) return false;
		}
	}
	// deserialize clist
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		clist.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(clist[i])) return false;
		}
	}
	return initQuest(qlist,clist);
}
bool Server2ClientProxy::acceptQuestOk(ProtocolReader* __r__)
{
	COM_QuestInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return acceptQuestOk(inst);
}
bool Server2ClientProxy::submitQuestOk(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return submitQuestOk(questId);
}
bool Server2ClientProxy::giveupQuestOk(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return giveupQuestOk(questId);
}
bool Server2ClientProxy::updateQuestInst(ProtocolReader* __r__)
{
	COM_QuestInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return updateQuestInst(inst);
}
bool Server2ClientProxy::requestContactInfoOk(ProtocolReader* __r__)
{
	COM_ContactInfo contact;
	// deserialize contact
	{
		if(!contact.deserialize(__r__)) return false;
	}
	return requestContactInfoOk(contact);
}
bool Server2ClientProxy::addFriendOK(ProtocolReader* __r__)
{
	COM_ContactInfo inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return addFriendOK(inst);
}
bool Server2ClientProxy::delFriendOK(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delFriendOK(instId);
}
bool Server2ClientProxy::addBlacklistOK(ProtocolReader* __r__)
{
	COM_ContactInfo inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return addBlacklistOK(inst);
}
bool Server2ClientProxy::delBlacklistOK(ProtocolReader* __r__)
{
	uint32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return delBlacklistOK(instId);
}
bool Server2ClientProxy::findFriendFail(ProtocolReader* __r__)
{
	return findFriendFail();
}
bool Server2ClientProxy::referrFriendOK(ProtocolReader* __r__)
{
	std::vector< COM_ContactInfo > insts;
	// deserialize insts
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		insts.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!insts[i].deserialize(__r__)) return false;
		}
	}
	return referrFriendOK(insts);
}
bool Server2ClientProxy::requestFriendListOK(ProtocolReader* __r__)
{
	std::vector< COM_ContactInfo > insts;
	// deserialize insts
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		insts.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!insts[i].deserialize(__r__)) return false;
		}
	}
	return requestFriendListOK(insts);
}
bool Server2ClientProxy::lotteryOk(ProtocolReader* __r__)
{
	int32_t lotteryId=0;
	std::vector< COM_DropItem > dropItem;
	// deserialize lotteryId
	{
		if(!__r__->readType(lotteryId)) return false;
	}
	// deserialize dropItem
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		dropItem.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!dropItem[i].deserialize(__r__)) return false;
		}
	}
	return lotteryOk(lotteryId,dropItem);
}
bool Server2ClientProxy::openGatherOK(ProtocolReader* __r__)
{
	COM_Gather gather;
	// deserialize gather
	{
		if(!gather.deserialize(__r__)) return false;
	}
	return openGatherOK(gather);
}
bool Server2ClientProxy::miningOk(ProtocolReader* __r__)
{
	std::vector< COM_DropItem > items;
	COM_Gather gather;
	uint32_t gatherNum=0;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	// deserialize gather
	{
		if(!gather.deserialize(__r__)) return false;
	}
	// deserialize gatherNum
	{
		if(!__r__->readType(gatherNum)) return false;
	}
	return miningOk(items,gather,gatherNum);
}
bool Server2ClientProxy::openCompound(ProtocolReader* __r__)
{
	uint32_t compoundId=0;
	// deserialize compoundId
	{
		if(!__r__->readType(compoundId)) return false;
	}
	return openCompound(compoundId);
}
bool Server2ClientProxy::compoundItemOk(ProtocolReader* __r__)
{
	COM_Item item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return compoundItemOk(item);
}
bool Server2ClientProxy::openBagGridOk(ProtocolReader* __r__)
{
	int32_t num=0;
	// deserialize num
	{
		if(!__r__->readType(num)) return false;
	}
	return openBagGridOk(num);
}
bool Server2ClientProxy::requestChallengeOK(ProtocolReader* __r__)
{
	bool isOK=false;
	// deserialize isOK
	{
		if(!__r__->readType(isOK)) return false;
	}
	return requestChallengeOK(isOK);
}
bool Server2ClientProxy::requestMySelfJJCDataOK(ProtocolReader* __r__)
{
	COM_EndlessStair info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return requestMySelfJJCDataOK(info);
}
bool Server2ClientProxy::requestRivalOK(ProtocolReader* __r__)
{
	std::vector< COM_EndlessStair > infos;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestRivalOK(infos);
}
bool Server2ClientProxy::rivalTimeOK(ProtocolReader* __r__)
{
	return rivalTimeOK();
}
bool Server2ClientProxy::checkMsgOK(ProtocolReader* __r__)
{
	COM_SimplePlayerInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return checkMsgOK(inst);
}
bool Server2ClientProxy::requestMyAllbattleMsgOK(ProtocolReader* __r__)
{
	std::vector< COM_JJCBattleMsg > infos;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestMyAllbattleMsgOK(infos);
}
bool Server2ClientProxy::myBattleMsgOK(ProtocolReader* __r__)
{
	COM_JJCBattleMsg info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return myBattleMsgOK(info);
}
bool Server2ClientProxy::requestJJCRankOK(ProtocolReader* __r__)
{
	uint32_t myRank=0;
	std::vector< COM_EndlessStair > infos;
	// deserialize myRank
	{
		if(!__r__->readType(myRank)) return false;
	}
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestJJCRankOK(myRank,infos);
}
bool Server2ClientProxy::requestLevelRankOK(ProtocolReader* __r__)
{
	uint32_t myRank=0;
	std::vector< COM_ContactInfo > infos;
	// deserialize myRank
	{
		if(!__r__->readType(myRank)) return false;
	}
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestLevelRankOK(myRank,infos);
}
bool Server2ClientProxy::requestBabyRankOK(ProtocolReader* __r__)
{
	uint32_t myRank=0;
	std::vector< COM_BabyRankData > infos;
	// deserialize myRank
	{
		if(!__r__->readType(myRank)) return false;
	}
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestBabyRankOK(myRank,infos);
}
bool Server2ClientProxy::requestEmpRankOK(ProtocolReader* __r__)
{
	uint32_t myRank=0;
	std::vector< COM_EmployeeRankData > infos;
	// deserialize myRank
	{
		if(!__r__->readType(myRank)) return false;
	}
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestEmpRankOK(myRank,infos);
}
bool Server2ClientProxy::requestPlayerFFRankOK(ProtocolReader* __r__)
{
	uint32_t myRank=0;
	std::vector< COM_ContactInfo > infos;
	// deserialize myRank
	{
		if(!__r__->readType(myRank)) return false;
	}
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestPlayerFFRankOK(myRank,infos);
}
bool Server2ClientProxy::queryOnlinePlayerOK(ProtocolReader* __r__)
{
	bool isOnline=false;
	// deserialize isOnline
	{
		if(!__r__->readType(isOnline)) return false;
	}
	return queryOnlinePlayerOK(isOnline);
}
bool Server2ClientProxy::queryPlayerOK(ProtocolReader* __r__)
{
	COM_SimplePlayerInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return queryPlayerOK(inst);
}
bool Server2ClientProxy::queryBabyOK(ProtocolReader* __r__)
{
	COM_BabyInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return queryBabyOK(inst);
}
bool Server2ClientProxy::queryEmployeeOK(ProtocolReader* __r__)
{
	COM_EmployeeInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return queryEmployeeOK(inst);
}
bool Server2ClientProxy::initGuide(ProtocolReader* __r__)
{
	uint32_t guideMask=0;
	// deserialize guideMask
	{
		if(!__r__->readType(guideMask)) return false;
	}
	return initGuide(guideMask);
}
bool Server2ClientProxy::buyShopItemOk(ProtocolReader* __r__)
{
	int32_t id=0;
	// deserialize id
	{
		if(!__r__->readType(id)) return false;
	}
	return buyShopItemOk(id);
}
bool Server2ClientProxy::addPlayerTitle(ProtocolReader* __r__)
{
	int32_t title=0;
	// deserialize title
	{
		if(!__r__->readType(title)) return false;
	}
	return addPlayerTitle(title);
}
bool Server2ClientProxy::delPlayerTitle(ProtocolReader* __r__)
{
	int32_t title=0;
	// deserialize title
	{
		if(!__r__->readType(title)) return false;
	}
	return delPlayerTitle(title);
}
bool Server2ClientProxy::requestOpenBuyBox(ProtocolReader* __r__)
{
	float greenTime=0;
	float blueTime=0;
	int32_t greenFreeNum=0;
	// deserialize greenTime
	{
		if(!__r__->readType(greenTime)) return false;
	}
	// deserialize blueTime
	{
		if(!__r__->readType(blueTime)) return false;
	}
	// deserialize greenFreeNum
	{
		if(!__r__->readType(greenFreeNum)) return false;
	}
	return requestOpenBuyBox(greenTime,blueTime,greenFreeNum);
}
bool Server2ClientProxy::requestGreenBoxTimeOk(ProtocolReader* __r__)
{
	return requestGreenBoxTimeOk();
}
bool Server2ClientProxy::requestBlueBoxTimeOk(ProtocolReader* __r__)
{
	return requestBlueBoxTimeOk();
}
bool Server2ClientProxy::updateAchievementinfo(ProtocolReader* __r__)
{
	COM_Achievement achs;
	// deserialize achs
	{
		if(!achs.deserialize(__r__)) return false;
	}
	return updateAchievementinfo(achs);
}
bool Server2ClientProxy::syncOpenSystemFlag(ProtocolReader* __r__)
{
	uint64_t flag=0;
	// deserialize flag
	{
		if(!__r__->readType(flag)) return false;
	}
	return syncOpenSystemFlag(flag);
}
bool Server2ClientProxy::requestActivityRewardOK(ProtocolReader* __r__)
{
	uint32_t ar=0;
	// deserialize ar
	{
		if(!__r__->readType(ar)) return false;
	}
	return requestActivityRewardOK(ar);
}
bool Server2ClientProxy::syncActivity(ProtocolReader* __r__)
{
	COM_ActivityTable table;
	// deserialize table
	{
		if(!table.deserialize(__r__)) return false;
	}
	return syncActivity(table);
}
bool Server2ClientProxy::updateActivityStatus(ProtocolReader* __r__)
{
	ActivityType type=(ActivityType)(0);
	bool open=false;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 21) return false;
		type = (ActivityType)__e__;
	}
	// deserialize open
	{
		if(!__r__->readType(open)) return false;
	}
	return updateActivityStatus(type,open);
}
bool Server2ClientProxy::updateActivityCounter(ProtocolReader* __r__)
{
	ActivityType type=(ActivityType)(0);
	int32_t counter=0;
	int32_t reward=0;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 21) return false;
		type = (ActivityType)__e__;
	}
	// deserialize counter
	{
		if(!__r__->readType(counter)) return false;
	}
	// deserialize reward
	{
		if(!__r__->readType(reward)) return false;
	}
	return updateActivityCounter(type,counter,reward);
}
bool Server2ClientProxy::syncExam(ProtocolReader* __r__)
{
	COM_Exam exam;
	// deserialize exam
	{
		if(!exam.deserialize(__r__)) return false;
	}
	return syncExam(exam);
}
bool Server2ClientProxy::syncExamAnswer(ProtocolReader* __r__)
{
	COM_Answer answer;
	// deserialize answer
	{
		if(!answer.deserialize(__r__)) return false;
	}
	return syncExamAnswer(answer);
}
bool Server2ClientProxy::petActivityNoNum(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return petActivityNoNum(name);
}
bool Server2ClientProxy::syncHundredInfo(ProtocolReader* __r__)
{
	COM_HundredBattle hb;
	// deserialize hb
	{
		if(!hb.deserialize(__r__)) return false;
	}
	return syncHundredInfo(hb);
}
bool Server2ClientProxy::initSignUp(ProtocolReader* __r__)
{
	std::vector< int32_t > info;
	int32_t process=0;
	bool sign7=false;
	bool sign14=false;
	bool sign28=false;
	// deserialize info
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		info.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(info[i])) return false;
		}
	}
	// deserialize process
	{
		if(!__r__->readType(process)) return false;
	}
	// deserialize sign7
	{
		if(!__r__->readType(sign7)) return false;
	}
	// deserialize sign14
	{
		if(!__r__->readType(sign14)) return false;
	}
	// deserialize sign28
	{
		if(!__r__->readType(sign28)) return false;
	}
	return initSignUp(info,process,sign7,sign14,sign28);
}
bool Server2ClientProxy::signUp(ProtocolReader* __r__)
{
	bool flag=false;
	// deserialize flag
	{
		if(!__r__->readType(flag)) return false;
	}
	return signUp(flag);
}
bool Server2ClientProxy::requestSignupRewardOk7(ProtocolReader* __r__)
{
	return requestSignupRewardOk7();
}
bool Server2ClientProxy::requestSignupRewardOk14(ProtocolReader* __r__)
{
	return requestSignupRewardOk14();
}
bool Server2ClientProxy::requestSignupRewardOk28(ProtocolReader* __r__)
{
	return requestSignupRewardOk28();
}
bool Server2ClientProxy::sycnDoubleExpTime(ProtocolReader* __r__)
{
	bool isFlag=false;
	float times=0;
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	// deserialize times
	{
		if(!__r__->readType(times)) return false;
	}
	return sycnDoubleExpTime(isFlag,times);
}
bool Server2ClientProxy::sycnStates(ProtocolReader* __r__)
{
	std::vector< COM_State > states;
	// deserialize states
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		states.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!states[i].deserialize(__r__)) return false;
		}
	}
	return sycnStates(states);
}
bool Server2ClientProxy::requestpvprankOK(ProtocolReader* __r__)
{
	std::vector< COM_ContactInfo > infos;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return requestpvprankOK(infos);
}
bool Server2ClientProxy::syncMyJJCTeamMember(ProtocolReader* __r__)
{
	return syncMyJJCTeamMember();
}
bool Server2ClientProxy::startMatchingOK(ProtocolReader* __r__)
{
	return startMatchingOK();
}
bool Server2ClientProxy::stopMatchingOK(ProtocolReader* __r__)
{
	float times=0;
	// deserialize times
	{
		if(!__r__->readType(times)) return false;
	}
	return stopMatchingOK(times);
}
bool Server2ClientProxy::updatePvpJJCinfo(ProtocolReader* __r__)
{
	COM_PlayerVsPlayer info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return updatePvpJJCinfo(info);
}
bool Server2ClientProxy::exitPvpJJCOk(ProtocolReader* __r__)
{
	return exitPvpJJCOk();
}
bool Server2ClientProxy::syncEnemyPvpJJCPlayerInfo(ProtocolReader* __r__)
{
	COM_SimpleInformation info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return syncEnemyPvpJJCPlayerInfo(info);
}
bool Server2ClientProxy::syncEnemyPvpJJCTeamInfo(ProtocolReader* __r__)
{
	std::vector< COM_SimpleInformation > infos;
	uint32_t teamID_=0;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	// deserialize teamID_
	{
		if(!__r__->readType(teamID_)) return false;
	}
	return syncEnemyPvpJJCTeamInfo(infos,teamID_);
}
bool Server2ClientProxy::openWarriorchooseUI(ProtocolReader* __r__)
{
	return openWarriorchooseUI();
}
bool Server2ClientProxy::warriorStartOK(ProtocolReader* __r__)
{
	return warriorStartOK();
}
bool Server2ClientProxy::warriorStopOK(ProtocolReader* __r__)
{
	return warriorStopOK();
}
bool Server2ClientProxy::syncWarriorEnemyTeamInfo(ProtocolReader* __r__)
{
	std::vector< COM_SimpleInformation > infos;
	uint32_t teamID_=0;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	// deserialize teamID_
	{
		if(!__r__->readType(teamID_)) return false;
	}
	return syncWarriorEnemyTeamInfo(infos,teamID_);
}
bool Server2ClientProxy::appendMail(ProtocolReader* __r__)
{
	std::vector< COM_Mail > mails;
	// deserialize mails
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		mails.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!mails[i].deserialize(__r__)) return false;
		}
	}
	return appendMail(mails);
}
bool Server2ClientProxy::delMail(ProtocolReader* __r__)
{
	int32_t mailId=0;
	// deserialize mailId
	{
		if(!__r__->readType(mailId)) return false;
	}
	return delMail(mailId);
}
bool Server2ClientProxy::updateMailOk(ProtocolReader* __r__)
{
	COM_Mail mail;
	// deserialize mail
	{
		if(!mail.deserialize(__r__)) return false;
	}
	return updateMailOk(mail);
}
bool Server2ClientProxy::boardcastNotice(ProtocolReader* __r__)
{
	std::string content;
	bool isGm=false;
	// deserialize content
	{
		if(!__r__->readType(content, 65535)) return false;
	}
	// deserialize isGm
	{
		if(!__r__->readType(isGm)) return false;
	}
	return boardcastNotice(content,isGm);
}
bool Server2ClientProxy::createGuildOK(ProtocolReader* __r__)
{
	return createGuildOK();
}
bool Server2ClientProxy::delGuildOK(ProtocolReader* __r__)
{
	return delGuildOK();
}
bool Server2ClientProxy::leaveGuildOk(ProtocolReader* __r__)
{
	std::string who;
	bool isKick=false;
	// deserialize who
	{
		if(!__r__->readType(who, 65535)) return false;
	}
	// deserialize isKick
	{
		if(!__r__->readType(isKick)) return false;
	}
	return leaveGuildOk(who,isKick);
}
bool Server2ClientProxy::initGuildData(ProtocolReader* __r__)
{
	COM_Guild guild;
	// deserialize guild
	{
		if(!guild.deserialize(__r__)) return false;
	}
	return initGuildData(guild);
}
bool Server2ClientProxy::initGuildMemberList(ProtocolReader* __r__)
{
	std::vector< COM_GuildMember > member;
	// deserialize member
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		member.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!member[i].deserialize(__r__)) return false;
		}
	}
	return initGuildMemberList(member);
}
bool Server2ClientProxy::modifyGuildMemberList(ProtocolReader* __r__)
{
	COM_GuildMember member;
	ModifyListFlag flag=(ModifyListFlag)(0);
	// deserialize member
	{
		if(!member.deserialize(__r__)) return false;
	}
	// deserialize flag
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 9) return false;
		flag = (ModifyListFlag)__e__;
	}
	return modifyGuildMemberList(member,flag);
}
bool Server2ClientProxy::modifyGuildList(ProtocolReader* __r__)
{
	COM_GuildViewerData data;
	ModifyListFlag flag=(ModifyListFlag)(0);
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	// deserialize flag
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 9) return false;
		flag = (ModifyListFlag)__e__;
	}
	return modifyGuildList(data,flag);
}
bool Server2ClientProxy::queryGuildListResult(ProtocolReader* __r__)
{
	int16_t page=0;
	int16_t pageNum=0;
	std::vector< COM_GuildViewerData > guildList;
	// deserialize page
	{
		if(!__r__->readType(page)) return false;
	}
	// deserialize pageNum
	{
		if(!__r__->readType(pageNum)) return false;
	}
	// deserialize guildList
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		guildList.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!guildList[i].deserialize(__r__)) return false;
		}
	}
	return queryGuildListResult(page,pageNum,guildList);
}
bool Server2ClientProxy::inviteGuild(ProtocolReader* __r__)
{
	std::string sendName;
	std::string guildName;
	// deserialize sendName
	{
		if(!__r__->readType(sendName, 65535)) return false;
	}
	// deserialize guildName
	{
		if(!__r__->readType(guildName, 65535)) return false;
	}
	return inviteGuild(sendName,guildName);
}
bool Server2ClientProxy::updateGuildShopItems(ProtocolReader* __r__)
{
	std::vector< COM_GuildShopItem > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return updateGuildShopItems(items);
}
bool Server2ClientProxy::updateGuildBuilding(ProtocolReader* __r__)
{
	GuildBuildingType type=(GuildBuildingType)(0);
	COM_GuildBuilding building;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 8) return false;
		type = (GuildBuildingType)__e__;
	}
	// deserialize building
	{
		if(!building.deserialize(__r__)) return false;
	}
	return updateGuildBuilding(type,building);
}
bool Server2ClientProxy::updateGuildMyMember(ProtocolReader* __r__)
{
	COM_GuildMember member;
	// deserialize member
	{
		if(!member.deserialize(__r__)) return false;
	}
	return updateGuildMyMember(member);
}
bool Server2ClientProxy::levelupGuildSkillOk(ProtocolReader* __r__)
{
	COM_Skill skInst;
	// deserialize skInst
	{
		if(!skInst.deserialize(__r__)) return false;
	}
	return levelupGuildSkillOk(skInst);
}
bool Server2ClientProxy::presentGuildItemOk(ProtocolReader* __r__)
{
	int32_t val=0;
	// deserialize val
	{
		if(!__r__->readType(val)) return false;
	}
	return presentGuildItemOk(val);
}
bool Server2ClientProxy::progenitusAddExpOk(ProtocolReader* __r__)
{
	COM_GuildProgen mInst;
	// deserialize mInst
	{
		if(!mInst.deserialize(__r__)) return false;
	}
	return progenitusAddExpOk(mInst);
}
bool Server2ClientProxy::setProgenitusPositionOk(ProtocolReader* __r__)
{
	std::vector< int32_t > positions;
	// deserialize positions
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		positions.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(positions[i])) return false;
		}
	}
	return setProgenitusPositionOk(positions);
}
bool Server2ClientProxy::updateGuildFundz(ProtocolReader* __r__)
{
	int32_t val=0;
	// deserialize val
	{
		if(!__r__->readType(val)) return false;
	}
	return updateGuildFundz(val);
}
bool Server2ClientProxy::updateGuildMemberContribution(ProtocolReader* __r__)
{
	int32_t val=0;
	// deserialize val
	{
		if(!__r__->readType(val)) return false;
	}
	return updateGuildMemberContribution(val);
}
bool Server2ClientProxy::openGuildBattle(ProtocolReader* __r__)
{
	std::string otherName;
	int32_t playerNum=0;
	int32_t level=0;
	bool isLeft=false;
	int32_t lstime=0;
	// deserialize otherName
	{
		if(!__r__->readType(otherName, 65535)) return false;
	}
	// deserialize playerNum
	{
		if(!__r__->readType(playerNum)) return false;
	}
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	// deserialize isLeft
	{
		if(!__r__->readType(isLeft)) return false;
	}
	// deserialize lstime
	{
		if(!__r__->readType(lstime)) return false;
	}
	return openGuildBattle(otherName,playerNum,level,isLeft,lstime);
}
bool Server2ClientProxy::startGuildBattle(ProtocolReader* __r__)
{
	std::string otherName;
	int32_t otherCon=0;
	int32_t selfCon=0;
	// deserialize otherName
	{
		if(!__r__->readType(otherName, 65535)) return false;
	}
	// deserialize otherCon
	{
		if(!__r__->readType(otherCon)) return false;
	}
	// deserialize selfCon
	{
		if(!__r__->readType(selfCon)) return false;
	}
	return startGuildBattle(otherName,otherCon,selfCon);
}
bool Server2ClientProxy::closeGuildBattle(ProtocolReader* __r__)
{
	bool isWinner=false;
	// deserialize isWinner
	{
		if(!__r__->readType(isWinner)) return false;
	}
	return closeGuildBattle(isWinner);
}
bool Server2ClientProxy::syncGuildBattleWinCount(ProtocolReader* __r__)
{
	int32_t myWin=0;
	int32_t otherWin=0;
	// deserialize myWin
	{
		if(!__r__->readType(myWin)) return false;
	}
	// deserialize otherWin
	{
		if(!__r__->readType(otherWin)) return false;
	}
	return syncGuildBattleWinCount(myWin,otherWin);
}
bool Server2ClientProxy::initMySelling(ProtocolReader* __r__)
{
	std::vector< COM_SellItem > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return initMySelling(items);
}
bool Server2ClientProxy::initMySelled(ProtocolReader* __r__)
{
	std::vector< COM_SelledItem > items;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return initMySelled(items);
}
bool Server2ClientProxy::fetchSellingOk(ProtocolReader* __r__)
{
	std::vector< COM_SellItem > items;
	int32_t total=0;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	// deserialize total
	{
		if(!__r__->readType(total)) return false;
	}
	return fetchSellingOk(items,total);
}
bool Server2ClientProxy::fetchSellingOk2(ProtocolReader* __r__)
{
	std::vector< COM_SellItem > items;
	int32_t total=0;
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	// deserialize total
	{
		if(!__r__->readType(total)) return false;
	}
	return fetchSellingOk2(items,total);
}
bool Server2ClientProxy::sellingOk(ProtocolReader* __r__)
{
	COM_SellItem item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return sellingOk(item);
}
bool Server2ClientProxy::selledOk(ProtocolReader* __r__)
{
	COM_SelledItem item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return selledOk(item);
}
bool Server2ClientProxy::unsellingOk(ProtocolReader* __r__)
{
	int32_t sellid=0;
	// deserialize sellid
	{
		if(!__r__->readType(sellid)) return false;
	}
	return unsellingOk(sellid);
}
bool Server2ClientProxy::redemptionSpreeOk(ProtocolReader* __r__)
{
	return redemptionSpreeOk();
}
bool Server2ClientProxy::insertState(ProtocolReader* __r__)
{
	COM_State st;
	// deserialize st
	{
		if(!st.deserialize(__r__)) return false;
	}
	return insertState(st);
}
bool Server2ClientProxy::updattState(ProtocolReader* __r__)
{
	COM_State st;
	// deserialize st
	{
		if(!st.deserialize(__r__)) return false;
	}
	return updattState(st);
}
bool Server2ClientProxy::removeState(ProtocolReader* __r__)
{
	uint32_t stid=0;
	// deserialize stid
	{
		if(!__r__->readType(stid)) return false;
	}
	return removeState(stid);
}
bool Server2ClientProxy::requestFixItemOk(ProtocolReader* __r__)
{
	COM_Item item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return requestFixItemOk(item);
}
bool Server2ClientProxy::makeDebirsItemOK(ProtocolReader* __r__)
{
	return makeDebirsItemOK();
}
bool Server2ClientProxy::updateMagicItem(ProtocolReader* __r__)
{
	int32_t level=0;
	int32_t exp=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	// deserialize exp
	{
		if(!__r__->readType(exp)) return false;
	}
	return updateMagicItem(level,exp);
}
bool Server2ClientProxy::changeMagicJobOk(ProtocolReader* __r__)
{
	JobType job=(JobType)(0);
	// deserialize job
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 12) return false;
		job = (JobType)__e__;
	}
	return changeMagicJobOk(job);
}
bool Server2ClientProxy::magicItemTupoOk(ProtocolReader* __r__)
{
	int32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return magicItemTupoOk(level);
}
bool Server2ClientProxy::zhuanpanOK(ProtocolReader* __r__)
{
	std::vector< uint32_t > pond;
	// deserialize pond
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		pond.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(pond[i])) return false;
		}
	}
	return zhuanpanOK(pond);
}
bool Server2ClientProxy::updateZhuanpanNotice(ProtocolReader* __r__)
{
	COM_Zhuanpan zhuanp;
	// deserialize zhuanp
	{
		if(!zhuanp.deserialize(__r__)) return false;
	}
	return updateZhuanpanNotice(zhuanp);
}
bool Server2ClientProxy::sycnZhuanpanData(ProtocolReader* __r__)
{
	COM_ZhuanpanData data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return sycnZhuanpanData(data);
}
bool Server2ClientProxy::copynonum(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return copynonum(name);
}
bool Server2ClientProxy::sceneFilterOk(ProtocolReader* __r__)
{
	std::vector< SceneFilterType > sfType;
	// deserialize sfType
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		sfType.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			uint8_t __e__;
			if(!__r__->readType(__e__) || __e__ >= 6) return false;
			sfType[i] = (SceneFilterType)__e__;
		}
	}
	return sceneFilterOk(sfType);
}
bool Server2ClientProxy::wishingOK(ProtocolReader* __r__)
{
	return wishingOK();
}
bool Server2ClientProxy::shareWishOK(ProtocolReader* __r__)
{
	COM_Wish wish;
	// deserialize wish
	{
		if(!wish.deserialize(__r__)) return false;
	}
	return shareWishOK(wish);
}
bool Server2ClientProxy::leaderCloseDialogOk(ProtocolReader* __r__)
{
	return leaderCloseDialogOk();
}
bool Server2ClientProxy::startOnlineTime(ProtocolReader* __r__)
{
	return startOnlineTime();
}
bool Server2ClientProxy::requestOnlineTimeRewardOK(ProtocolReader* __r__)
{
	uint32_t index=0;
	// deserialize index
	{
		if(!__r__->readType(index)) return false;
	}
	return requestOnlineTimeRewardOK(index);
}
bool Server2ClientProxy::sycnVipflag(ProtocolReader* __r__)
{
	bool flag=false;
	// deserialize flag
	{
		if(!__r__->readType(flag)) return false;
	}
	return sycnVipflag(flag);
}
bool Server2ClientProxy::buyFundOK(ProtocolReader* __r__)
{
	bool flag=false;
	// deserialize flag
	{
		if(!__r__->readType(flag)) return false;
	}
	return buyFundOK(flag);
}
bool Server2ClientProxy::requestFundRewardOK(ProtocolReader* __r__)
{
	uint32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return requestFundRewardOK(level);
}
bool Server2ClientProxy::firstRechargeOK(ProtocolReader* __r__)
{
	bool isFlag=false;
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return firstRechargeOK(isFlag);
}
bool Server2ClientProxy::firstRechargeGiftOK(ProtocolReader* __r__)
{
	bool isFlag=false;
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return firstRechargeGiftOK(isFlag);
}
bool Server2ClientProxy::agencyActivity(ProtocolReader* __r__)
{
	ADType type=(ADType)(0);
	bool isFlag=false;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 21) return false;
		type = (ADType)__e__;
	}
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return agencyActivity(type,isFlag);
}
bool Server2ClientProxy::updateFestival(ProtocolReader* __r__)
{
	COM_ADLoginTotal festival;
	// deserialize festival
	{
		if(!festival.deserialize(__r__)) return false;
	}
	return updateFestival(festival);
}
bool Server2ClientProxy::updateSelfRecharge(ProtocolReader* __r__)
{
	COM_ADChargeTotal val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateSelfRecharge(val);
}
bool Server2ClientProxy::updateSysRecharge(ProtocolReader* __r__)
{
	COM_ADChargeTotal val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateSysRecharge(val);
}
bool Server2ClientProxy::updateSelfDiscountStore(ProtocolReader* __r__)
{
	COM_ADDiscountStore val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateSelfDiscountStore(val);
}
bool Server2ClientProxy::updateSysDiscountStore(ProtocolReader* __r__)
{
	COM_ADDiscountStore val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateSysDiscountStore(val);
}
bool Server2ClientProxy::updateSelfOnceRecharge(ProtocolReader* __r__)
{
	COM_ADChargeEvery val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateSelfOnceRecharge(val);
}
bool Server2ClientProxy::updateSysOnceRecharge(ProtocolReader* __r__)
{
	COM_ADChargeEvery val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateSysOnceRecharge(val);
}
bool Server2ClientProxy::openCardOK(ProtocolReader* __r__)
{
	COM_ADCardsContent data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return openCardOK(data);
}
bool Server2ClientProxy::resetCardOK(ProtocolReader* __r__)
{
	return resetCardOK();
}
bool Server2ClientProxy::sycnHotRole(ProtocolReader* __r__)
{
	COM_ADHotRole data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return sycnHotRole(data);
}
bool Server2ClientProxy::hotRoleBuyOk(ProtocolReader* __r__)
{
	uint16_t buyNum=0;
	// deserialize buyNum
	{
		if(!__r__->readType(buyNum)) return false;
	}
	return hotRoleBuyOk(buyNum);
}
bool Server2ClientProxy::updateSevenday(ProtocolReader* __r__)
{
	COM_Sevenday data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return updateSevenday(data);
}
bool Server2ClientProxy::updateEmployeeActivity(ProtocolReader* __r__)
{
	COM_ADEmployeeTotal data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return updateEmployeeActivity(data);
}
bool Server2ClientProxy::updateMinGiftActivity(ProtocolReader* __r__)
{
	COM_ADGiftBag data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return updateMinGiftActivity(data);
}
bool Server2ClientProxy::updateIntegralShop(ProtocolReader* __r__)
{
	COM_IntegralData data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return updateIntegralShop(data);
}
bool Server2ClientProxy::updateShowBaby(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	uint32_t showBabyTableId=0;
	std::string showBabyName;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize showBabyTableId
	{
		if(!__r__->readType(showBabyTableId)) return false;
	}
	// deserialize showBabyName
	{
		if(!__r__->readType(showBabyName, 65535)) return false;
	}
	return updateShowBaby(playerId,showBabyTableId,showBabyName);
}
bool Server2ClientProxy::updateMySelfRecharge(ProtocolReader* __r__)
{
	COM_ADChargeTotal val;
	// deserialize val
	{
		if(!val.deserialize(__r__)) return false;
	}
	return updateMySelfRecharge(val);
}
bool Server2ClientProxy::verificationSMSOk(ProtocolReader* __r__)
{
	std::string phoneNumber;
	// deserialize phoneNumber
	{
		if(!__r__->readType(phoneNumber, 65535)) return false;
	}
	return verificationSMSOk(phoneNumber);
}
bool Server2ClientProxy::requestLevelGiftOK(ProtocolReader* __r__)
{
	int32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return requestLevelGiftOK(level);
}
bool Server2ClientProxy::sycnConvertExp(ProtocolReader* __r__)
{
	int32_t val=0;
	// deserialize val
	{
		if(!__r__->readType(val)) return false;
	}
	return sycnConvertExp(val);
}
bool Server2ClientProxy::wearFuwenOk(ProtocolReader* __r__)
{
	COM_Item inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return wearFuwenOk(inst);
}
bool Server2ClientProxy::takeoffFuwenOk(ProtocolReader* __r__)
{
	int32_t slot=0;
	// deserialize slot
	{
		if(!__r__->readType(slot)) return false;
	}
	return takeoffFuwenOk(slot);
}
bool Server2ClientProxy::compFuwenOk(ProtocolReader* __r__)
{
	return compFuwenOk();
}
bool Server2ClientProxy::requestEmployeeQuestOk(ProtocolReader* __r__)
{
	std::vector< COM_EmployeeQuestInst > questList;
	// deserialize questList
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		questList.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!questList[i].deserialize(__r__)) return false;
		}
	}
	return requestEmployeeQuestOk(questList);
}
bool Server2ClientProxy::acceptEmployeeQuestOk(ProtocolReader* __r__)
{
	COM_EmployeeQuestInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return acceptEmployeeQuestOk(inst);
}
bool Server2ClientProxy::submitEmployeeQuestOk(ProtocolReader* __r__)
{
	int32_t questId=0;
	bool isSuccess=false;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	// deserialize isSuccess
	{
		if(!__r__->readType(isSuccess)) return false;
	}
	return submitEmployeeQuestOk(questId,isSuccess);
}
bool Server2ClientProxy::sycnCrystal(ProtocolReader* __r__)
{
	COM_CrystalData data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return sycnCrystal(data);
}
bool Server2ClientProxy::crystalUpLeveResult(ProtocolReader* __r__)
{
	bool isOK=false;
	// deserialize isOK
	{
		if(!__r__->readType(isOK)) return false;
	}
	return crystalUpLeveResult(isOK);
}
bool Server2ClientProxy::resetCrystalPropOK(ProtocolReader* __r__)
{
	return resetCrystalPropOK();
}
bool Server2ClientProxy::sycnCourseGift(ProtocolReader* __r__)
{
	std::vector< COM_CourseGift > data;
	// deserialize data
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		data.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!data[i].deserialize(__r__)) return false;
		}
	}
	return sycnCourseGift(data);
}
bool Server2ClientProxy::orderOk(ProtocolReader* __r__)
{
	std::string orderId;
	int32_t shopId=0;
	// deserialize orderId
	{
		if(!__r__->readType(orderId, 65535)) return false;
	}
	// deserialize shopId
	{
		if(!__r__->readType(shopId)) return false;
	}
	return orderOk(orderId,shopId);
}
bool Server2ClientProxy::updateRandSubmitQuestCount(ProtocolReader* __r__)
{
	int32_t submitCount=0;
	// deserialize submitCount
	{
		if(!__r__->readType(submitCount)) return false;
	}
	return updateRandSubmitQuestCount(submitCount);
}
bool Server2ClientProxy::updateTeamMember(ProtocolReader* __r__)
{
	int32_t playerId=0;
	bool isMember=false;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize isMember
	{
		if(!__r__->readType(isMember)) return false;
	}
	return updateTeamMember(playerId,isMember);
}
bool Server2ClientProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!pong(r)) return false;
		}
		break;
		case 1:
		{
			if(!errorno(r)) return false;
		}
		break;
		case 2:
		{
			if(!teamerrorno(r)) return false;
		}
		break;
		case 3:
		{
			if(!reconnection(r)) return false;
		}
		break;
		case 4:
		{
			if(!sessionfailed(r)) return false;
		}
		break;
		case 5:
		{
			if(!loginok(r)) return false;
		}
		break;
		case 6:
		{
			if(!logoutOk(r)) return false;
		}
		break;
		case 7:
		{
			if(!createPlayerOk(r)) return false;
		}
		break;
		case 8:
		{
			if(!deletePlayerOk(r)) return false;
		}
		break;
		case 9:
		{
			if(!enterGameOk(r)) return false;
		}
		break;
		case 10:
		{
			if(!initBabies(r)) return false;
		}
		break;
		case 11:
		{
			if(!initEmployees(r)) return false;
		}
		break;
		case 12:
		{
			if(!initEmpBattleGroup(r)) return false;
		}
		break;
		case 13:
		{
			if(!initNpc(r)) return false;
		}
		break;
		case 14:
		{
			if(!initAchievement(r)) return false;
		}
		break;
		case 15:
		{
			if(!initGather(r)) return false;
		}
		break;
		case 16:
		{
			if(!initcompound(r)) return false;
		}
		break;
		case 17:
		{
			if(!addBaby(r)) return false;
		}
		break;
		case 18:
		{
			if(!refreshBaby(r)) return false;
		}
		break;
		case 19:
		{
			if(!delBabyOK(r)) return false;
		}
		break;
		case 20:
		{
			if(!changeBabyNameOK(r)) return false;
		}
		break;
		case 21:
		{
			if(!remouldBabyOK(r)) return false;
		}
		break;
		case 22:
		{
			if(!intensifyBabyOK(r)) return false;
		}
		break;
		case 23:
		{
			if(!learnSkillOk(r)) return false;
		}
		break;
		case 24:
		{
			if(!forgetSkillOk(r)) return false;
		}
		break;
		case 25:
		{
			if(!addSkillExp(r)) return false;
		}
		break;
		case 26:
		{
			if(!babyLearnSkillOK(r)) return false;
		}
		break;
		case 27:
		{
			if(!skillLevelUp(r)) return false;
		}
		break;
		case 28:
		{
			if(!joinScene(r)) return false;
		}
		break;
		case 29:
		{
			if(!joinCopySceneOK(r)) return false;
		}
		break;
		case 30:
		{
			if(!initCopyNums(r)) return false;
		}
		break;
		case 31:
		{
			if(!addToScene(r)) return false;
		}
		break;
		case 32:
		{
			if(!delFormScene(r)) return false;
		}
		break;
		case 33:
		{
			if(!move2(r)) return false;
		}
		break;
		case 34:
		{
			if(!cantMove(r)) return false;
		}
		break;
		case 35:
		{
			if(!querySimplePlayerInstOk(r)) return false;
		}
		break;
		case 36:
		{
			if(!transfor2(r)) return false;
		}
		break;
		case 37:
		{
			if(!openScene(r)) return false;
		}
		break;
		case 38:
		{
			if(!autoBattleResult(r)) return false;
		}
		break;
		case 39:
		{
			if(!talked2Npc(r)) return false;
		}
		break;
		case 40:
		{
			if(!talked2Player(r)) return false;
		}
		break;
		case 41:
		{
			if(!useItemOk(r)) return false;
		}
		break;
		case 42:
		{
			if(!syncBattleStatus(r)) return false;
		}
		break;
		case 43:
		{
			if(!enterBattleOk(r)) return false;
		}
		break;
		case 44:
		{
			if(!exitBattleOk(r)) return false;
		}
		break;
		case 45:
		{
			if(!syncOrderOk(r)) return false;
		}
		break;
		case 46:
		{
			if(!syncOrderOkEX(r)) return false;
		}
		break;
		case 47:
		{
			if(!syncOneTurnAction(r)) return false;
		}
		break;
		case 48:
		{
			if(!syncProperties(r)) return false;
		}
		break;
		case 49:
		{
			if(!receiveChat(r)) return false;
		}
		break;
		case 50:
		{
			if(!requestAudioOk(r)) return false;
		}
		break;
		case 51:
		{
			if(!publishItemInstRes(r)) return false;
		}
		break;
		case 52:
		{
			if(!queryItemInstRes(r)) return false;
		}
		break;
		case 53:
		{
			if(!publishBabyInstRes(r)) return false;
		}
		break;
		case 54:
		{
			if(!queryBabyInstRes(r)) return false;
		}
		break;
		case 55:
		{
			if(!setNoTalkTime(r)) return false;
		}
		break;
		case 56:
		{
			if(!addNpc(r)) return false;
		}
		break;
		case 57:
		{
			if(!delNpc(r)) return false;
		}
		break;
		case 58:
		{
			if(!setTeamLeader(r)) return false;
		}
		break;
		case 59:
		{
			if(!initBag(r)) return false;
		}
		break;
		case 60:
		{
			if(!addBagItem(r)) return false;
		}
		break;
		case 61:
		{
			if(!delBagItem(r)) return false;
		}
		break;
		case 62:
		{
			if(!updateBagItem(r)) return false;
		}
		break;
		case 63:
		{
			if(!depositItemOK(r)) return false;
		}
		break;
		case 64:
		{
			if(!getoutItemOK(r)) return false;
		}
		break;
		case 65:
		{
			if(!depositBabyOK(r)) return false;
		}
		break;
		case 66:
		{
			if(!getoutBabyOK(r)) return false;
		}
		break;
		case 67:
		{
			if(!sortItemStorageOK(r)) return false;
		}
		break;
		case 68:
		{
			if(!sortBabyStorageOK(r)) return false;
		}
		break;
		case 69:
		{
			if(!initItemStorage(r)) return false;
		}
		break;
		case 70:
		{
			if(!initBabyStorage(r)) return false;
		}
		break;
		case 71:
		{
			if(!openStorageGrid(r)) return false;
		}
		break;
		case 72:
		{
			if(!delStorageBabyOK(r)) return false;
		}
		break;
		case 73:
		{
			if(!initPlayerEquips(r)) return false;
		}
		break;
		case 74:
		{
			if(!wearEquipmentOk(r)) return false;
		}
		break;
		case 75:
		{
			if(!scenePlayerWearEquipment(r)) return false;
		}
		break;
		case 76:
		{
			if(!delEquipmentOk(r)) return false;
		}
		break;
		case 77:
		{
			if(!scenePlayerDoffEquipment(r)) return false;
		}
		break;
		case 78:
		{
			if(!sortBagItemOk(r)) return false;
		}
		break;
		case 79:
		{
			if(!jointLobbyOk(r)) return false;
		}
		break;
		case 80:
		{
			if(!exitLobbyOk(r)) return false;
		}
		break;
		case 81:
		{
			if(!syncDelLobbyTeam(r)) return false;
		}
		break;
		case 82:
		{
			if(!syncUpdateLobbyTeam(r)) return false;
		}
		break;
		case 83:
		{
			if(!syncAddLobbyTeam(r)) return false;
		}
		break;
		case 84:
		{
			if(!createTeamOk(r)) return false;
		}
		break;
		case 85:
		{
			if(!changeTeamOk(r)) return false;
		}
		break;
		case 86:
		{
			if(!joinTeamOk(r)) return false;
		}
		break;
		case 87:
		{
			if(!addTeamMember(r)) return false;
		}
		break;
		case 88:
		{
			if(!delTeamMember(r)) return false;
		}
		break;
		case 89:
		{
			if(!changeTeamLeaderOk(r)) return false;
		}
		break;
		case 90:
		{
			if(!exitTeamOk(r)) return false;
		}
		break;
		case 91:
		{
			if(!updateTeam(r)) return false;
		}
		break;
		case 92:
		{
			if(!joinTeamRoomOK(r)) return false;
		}
		break;
		case 93:
		{
			if(!inviteJoinTeam(r)) return false;
		}
		break;
		case 94:
		{
			if(!syncTeamDirtyProp(r)) return false;
		}
		break;
		case 95:
		{
			if(!leaveTeamOk(r)) return false;
		}
		break;
		case 96:
		{
			if(!backTeamOK(r)) return false;
		}
		break;
		case 97:
		{
			if(!teamCallMemberBack(r)) return false;
		}
		break;
		case 98:
		{
			if(!refuseBackTeamOk(r)) return false;
		}
		break;
		case 99:
		{
			if(!requestJoinTeamTranspond(r)) return false;
		}
		break;
		case 100:
		{
			if(!drawLotteryBoxRep(r)) return false;
		}
		break;
		case 101:
		{
			if(!addEmployee(r)) return false;
		}
		break;
		case 102:
		{
			if(!battleEmployee(r)) return false;
		}
		break;
		case 103:
		{
			if(!changeEmpBattleGroupOK(r)) return false;
		}
		break;
		case 104:
		{
			if(!evolveOK(r)) return false;
		}
		break;
		case 105:
		{
			if(!upStarOK(r)) return false;
		}
		break;
		case 106:
		{
			if(!delEmployeeOK(r)) return false;
		}
		break;
		case 107:
		{
			if(!sycnEmployeeSoul(r)) return false;
		}
		break;
		case 108:
		{
			if(!initQuest(r)) return false;
		}
		break;
		case 109:
		{
			if(!acceptQuestOk(r)) return false;
		}
		break;
		case 110:
		{
			if(!submitQuestOk(r)) return false;
		}
		break;
		case 111:
		{
			if(!giveupQuestOk(r)) return false;
		}
		break;
		case 112:
		{
			if(!updateQuestInst(r)) return false;
		}
		break;
		case 113:
		{
			if(!requestContactInfoOk(r)) return false;
		}
		break;
		case 114:
		{
			if(!addFriendOK(r)) return false;
		}
		break;
		case 115:
		{
			if(!delFriendOK(r)) return false;
		}
		break;
		case 116:
		{
			if(!addBlacklistOK(r)) return false;
		}
		break;
		case 117:
		{
			if(!delBlacklistOK(r)) return false;
		}
		break;
		case 118:
		{
			if(!findFriendFail(r)) return false;
		}
		break;
		case 119:
		{
			if(!referrFriendOK(r)) return false;
		}
		break;
		case 120:
		{
			if(!requestFriendListOK(r)) return false;
		}
		break;
		case 121:
		{
			if(!lotteryOk(r)) return false;
		}
		break;
		case 122:
		{
			if(!openGatherOK(r)) return false;
		}
		break;
		case 123:
		{
			if(!miningOk(r)) return false;
		}
		break;
		case 124:
		{
			if(!openCompound(r)) return false;
		}
		break;
		case 125:
		{
			if(!compoundItemOk(r)) return false;
		}
		break;
		case 126:
		{
			if(!openBagGridOk(r)) return false;
		}
		break;
		case 127:
		{
			if(!requestChallengeOK(r)) return false;
		}
		break;
		case 128:
		{
			if(!requestMySelfJJCDataOK(r)) return false;
		}
		break;
		case 129:
		{
			if(!requestRivalOK(r)) return false;
		}
		break;
		case 130:
		{
			if(!rivalTimeOK(r)) return false;
		}
		break;
		case 131:
		{
			if(!checkMsgOK(r)) return false;
		}
		break;
		case 132:
		{
			if(!requestMyAllbattleMsgOK(r)) return false;
		}
		break;
		case 133:
		{
			if(!myBattleMsgOK(r)) return false;
		}
		break;
		case 134:
		{
			if(!requestJJCRankOK(r)) return false;
		}
		break;
		case 135:
		{
			if(!requestLevelRankOK(r)) return false;
		}
		break;
		case 136:
		{
			if(!requestBabyRankOK(r)) return false;
		}
		break;
		case 137:
		{
			if(!requestEmpRankOK(r)) return false;
		}
		break;
		case 138:
		{
			if(!requestPlayerFFRankOK(r)) return false;
		}
		break;
		case 139:
		{
			if(!queryOnlinePlayerOK(r)) return false;
		}
		break;
		case 140:
		{
			if(!queryPlayerOK(r)) return false;
		}
		break;
		case 141:
		{
			if(!queryBabyOK(r)) return false;
		}
		break;
		case 142:
		{
			if(!queryEmployeeOK(r)) return false;
		}
		break;
		case 143:
		{
			if(!initGuide(r)) return false;
		}
		break;
		case 144:
		{
			if(!buyShopItemOk(r)) return false;
		}
		break;
		case 145:
		{
			if(!addPlayerTitle(r)) return false;
		}
		break;
		case 146:
		{
			if(!delPlayerTitle(r)) return false;
		}
		break;
		case 147:
		{
			if(!requestOpenBuyBox(r)) return false;
		}
		break;
		case 148:
		{
			if(!requestGreenBoxTimeOk(r)) return false;
		}
		break;
		case 149:
		{
			if(!requestBlueBoxTimeOk(r)) return false;
		}
		break;
		case 150:
		{
			if(!updateAchievementinfo(r)) return false;
		}
		break;
		case 151:
		{
			if(!syncOpenSystemFlag(r)) return false;
		}
		break;
		case 152:
		{
			if(!requestActivityRewardOK(r)) return false;
		}
		break;
		case 153:
		{
			if(!syncActivity(r)) return false;
		}
		break;
		case 154:
		{
			if(!updateActivityStatus(r)) return false;
		}
		break;
		case 155:
		{
			if(!updateActivityCounter(r)) return false;
		}
		break;
		case 156:
		{
			if(!syncExam(r)) return false;
		}
		break;
		case 157:
		{
			if(!syncExamAnswer(r)) return false;
		}
		break;
		case 158:
		{
			if(!petActivityNoNum(r)) return false;
		}
		break;
		case 159:
		{
			if(!syncHundredInfo(r)) return false;
		}
		break;
		case 160:
		{
			if(!initSignUp(r)) return false;
		}
		break;
		case 161:
		{
			if(!signUp(r)) return false;
		}
		break;
		case 162:
		{
			if(!requestSignupRewardOk7(r)) return false;
		}
		break;
		case 163:
		{
			if(!requestSignupRewardOk14(r)) return false;
		}
		break;
		case 164:
		{
			if(!requestSignupRewardOk28(r)) return false;
		}
		break;
		case 165:
		{
			if(!sycnDoubleExpTime(r)) return false;
		}
		break;
		case 166:
		{
			if(!sycnStates(r)) return false;
		}
		break;
		case 167:
		{
			if(!requestpvprankOK(r)) return false;
		}
		break;
		case 168:
		{
			if(!syncMyJJCTeamMember(r)) return false;
		}
		break;
		case 169:
		{
			if(!startMatchingOK(r)) return false;
		}
		break;
		case 170:
		{
			if(!stopMatchingOK(r)) return false;
		}
		break;
		case 171:
		{
			if(!updatePvpJJCinfo(r)) return false;
		}
		break;
		case 172:
		{
			if(!exitPvpJJCOk(r)) return false;
		}
		break;
		case 173:
		{
			if(!syncEnemyPvpJJCPlayerInfo(r)) return false;
		}
		break;
		case 174:
		{
			if(!syncEnemyPvpJJCTeamInfo(r)) return false;
		}
		break;
		case 175:
		{
			if(!openWarriorchooseUI(r)) return false;
		}
		break;
		case 176:
		{
			if(!warriorStartOK(r)) return false;
		}
		break;
		case 177:
		{
			if(!warriorStopOK(r)) return false;
		}
		break;
		case 178:
		{
			if(!syncWarriorEnemyTeamInfo(r)) return false;
		}
		break;
		case 179:
		{
			if(!appendMail(r)) return false;
		}
		break;
		case 180:
		{
			if(!delMail(r)) return false;
		}
		break;
		case 181:
		{
			if(!updateMailOk(r)) return false;
		}
		break;
		case 182:
		{
			if(!boardcastNotice(r)) return false;
		}
		break;
		case 183:
		{
			if(!createGuildOK(r)) return false;
		}
		break;
		case 184:
		{
			if(!delGuildOK(r)) return false;
		}
		break;
		case 185:
		{
			if(!leaveGuildOk(r)) return false;
		}
		break;
		case 186:
		{
			if(!initGuildData(r)) return false;
		}
		break;
		case 187:
		{
			if(!initGuildMemberList(r)) return false;
		}
		break;
		case 188:
		{
			if(!modifyGuildMemberList(r)) return false;
		}
		break;
		case 189:
		{
			if(!modifyGuildList(r)) return false;
		}
		break;
		case 190:
		{
			if(!queryGuildListResult(r)) return false;
		}
		break;
		case 191:
		{
			if(!inviteGuild(r)) return false;
		}
		break;
		case 192:
		{
			if(!updateGuildShopItems(r)) return false;
		}
		break;
		case 193:
		{
			if(!updateGuildBuilding(r)) return false;
		}
		break;
		case 194:
		{
			if(!updateGuildMyMember(r)) return false;
		}
		break;
		case 195:
		{
			if(!levelupGuildSkillOk(r)) return false;
		}
		break;
		case 196:
		{
			if(!presentGuildItemOk(r)) return false;
		}
		break;
		case 197:
		{
			if(!progenitusAddExpOk(r)) return false;
		}
		break;
		case 198:
		{
			if(!setProgenitusPositionOk(r)) return false;
		}
		break;
		case 199:
		{
			if(!updateGuildFundz(r)) return false;
		}
		break;
		case 200:
		{
			if(!updateGuildMemberContribution(r)) return false;
		}
		break;
		case 201:
		{
			if(!openGuildBattle(r)) return false;
		}
		break;
		case 202:
		{
			if(!startGuildBattle(r)) return false;
		}
		break;
		case 203:
		{
			if(!closeGuildBattle(r)) return false;
		}
		break;
		case 204:
		{
			if(!syncGuildBattleWinCount(r)) return false;
		}
		break;
		case 205:
		{
			if(!initMySelling(r)) return false;
		}
		break;
		case 206:
		{
			if(!initMySelled(r)) return false;
		}
		break;
		case 207:
		{
			if(!fetchSellingOk(r)) return false;
		}
		break;
		case 208:
		{
			if(!fetchSellingOk2(r)) return false;
		}
		break;
		case 209:
		{
			if(!sellingOk(r)) return false;
		}
		break;
		case 210:
		{
			if(!selledOk(r)) return false;
		}
		break;
		case 211:
		{
			if(!unsellingOk(r)) return false;
		}
		break;
		case 212:
		{
			if(!redemptionSpreeOk(r)) return false;
		}
		break;
		case 213:
		{
			if(!insertState(r)) return false;
		}
		break;
		case 214:
		{
			if(!updattState(r)) return false;
		}
		break;
		case 215:
		{
			if(!removeState(r)) return false;
		}
		break;
		case 216:
		{
			if(!requestFixItemOk(r)) return false;
		}
		break;
		case 217:
		{
			if(!makeDebirsItemOK(r)) return false;
		}
		break;
		case 218:
		{
			if(!updateMagicItem(r)) return false;
		}
		break;
		case 219:
		{
			if(!changeMagicJobOk(r)) return false;
		}
		break;
		case 220:
		{
			if(!magicItemTupoOk(r)) return false;
		}
		break;
		case 221:
		{
			if(!zhuanpanOK(r)) return false;
		}
		break;
		case 222:
		{
			if(!updateZhuanpanNotice(r)) return false;
		}
		break;
		case 223:
		{
			if(!sycnZhuanpanData(r)) return false;
		}
		break;
		case 224:
		{
			if(!copynonum(r)) return false;
		}
		break;
		case 225:
		{
			if(!sceneFilterOk(r)) return false;
		}
		break;
		case 226:
		{
			if(!wishingOK(r)) return false;
		}
		break;
		case 227:
		{
			if(!shareWishOK(r)) return false;
		}
		break;
		case 228:
		{
			if(!leaderCloseDialogOk(r)) return false;
		}
		break;
		case 229:
		{
			if(!startOnlineTime(r)) return false;
		}
		break;
		case 230:
		{
			if(!requestOnlineTimeRewardOK(r)) return false;
		}
		break;
		case 231:
		{
			if(!sycnVipflag(r)) return false;
		}
		break;
		case 232:
		{
			if(!buyFundOK(r)) return false;
		}
		break;
		case 233:
		{
			if(!requestFundRewardOK(r)) return false;
		}
		break;
		case 234:
		{
			if(!firstRechargeOK(r)) return false;
		}
		break;
		case 235:
		{
			if(!firstRechargeGiftOK(r)) return false;
		}
		break;
		case 236:
		{
			if(!agencyActivity(r)) return false;
		}
		break;
		case 237:
		{
			if(!updateFestival(r)) return false;
		}
		break;
		case 238:
		{
			if(!updateSelfRecharge(r)) return false;
		}
		break;
		case 239:
		{
			if(!updateSysRecharge(r)) return false;
		}
		break;
		case 240:
		{
			if(!updateSelfDiscountStore(r)) return false;
		}
		break;
		case 241:
		{
			if(!updateSysDiscountStore(r)) return false;
		}
		break;
		case 242:
		{
			if(!updateSelfOnceRecharge(r)) return false;
		}
		break;
		case 243:
		{
			if(!updateSysOnceRecharge(r)) return false;
		}
		break;
		case 244:
		{
			if(!openCardOK(r)) return false;
		}
		break;
		case 245:
		{
			if(!resetCardOK(r)) return false;
		}
		break;
		case 246:
		{
			if(!sycnHotRole(r)) return false;
		}
		break;
		case 247:
		{
			if(!hotRoleBuyOk(r)) return false;
		}
		break;
		case 248:
		{
			if(!updateSevenday(r)) return false;
		}
		break;
		case 249:
		{
			if(!updateEmployeeActivity(r)) return false;
		}
		break;
		case 250:
		{
			if(!updateMinGiftActivity(r)) return false;
		}
		break;
		case 251:
		{
			if(!updateIntegralShop(r)) return false;
		}
		break;
		case 252:
		{
			if(!updateShowBaby(r)) return false;
		}
		break;
		case 253:
		{
			if(!updateMySelfRecharge(r)) return false;
		}
		break;
		case 254:
		{
			if(!verificationSMSOk(r)) return false;
		}
		break;
		case 255:
		{
			if(!requestLevelGiftOK(r)) return false;
		}
		break;
		case 256:
		{
			if(!sycnConvertExp(r)) return false;
		}
		break;
		case 257:
		{
			if(!wearFuwenOk(r)) return false;
		}
		break;
		case 258:
		{
			if(!takeoffFuwenOk(r)) return false;
		}
		break;
		case 259:
		{
			if(!compFuwenOk(r)) return false;
		}
		break;
		case 260:
		{
			if(!requestEmployeeQuestOk(r)) return false;
		}
		break;
		case 261:
		{
			if(!acceptEmployeeQuestOk(r)) return false;
		}
		break;
		case 262:
		{
			if(!submitEmployeeQuestOk(r)) return false;
		}
		break;
		case 263:
		{
			if(!sycnCrystal(r)) return false;
		}
		break;
		case 264:
		{
			if(!crystalUpLeveResult(r)) return false;
		}
		break;
		case 265:
		{
			if(!resetCrystalPropOK(r)) return false;
		}
		break;
		case 266:
		{
			if(!sycnCourseGift(r)) return false;
		}
		break;
		case 267:
		{
			if(!orderOk(r)) return false;
		}
		break;
		case 268:
		{
			if(!updateRandSubmitQuestCount(r)) return false;
		}
		break;
		case 269:
		{
			if(!updateTeamMember(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_World2LoginStub::queryAccount(const COM_LoginInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void SGE_World2LoginStub::setAccountSeal(const std::string& accountname,bool val)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize accountname
	{
		w->writeType(accountname);
	}
	// serialize val
	{
		w->writeType(val);
	}
	methodEnd();
}
void SGE_World2LoginStub::setPhoneNumber(const std::string& accountname,const std::string& phoneNumber)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize accountname
	{
		w->writeType(accountname);
	}
	// serialize phoneNumber
	{
		w->writeType(phoneNumber);
	}
	methodEnd();
}
bool SGE_World2LoginProxy::queryAccount(ProtocolReader* __r__)
{
	COM_LoginInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return queryAccount(info);
}
bool SGE_World2LoginProxy::setAccountSeal(ProtocolReader* __r__)
{
	std::string accountname;
	bool val=false;
	// deserialize accountname
	{
		if(!__r__->readType(accountname, 65535)) return false;
	}
	// deserialize val
	{
		if(!__r__->readType(val)) return false;
	}
	return setAccountSeal(accountname,val);
}
bool SGE_World2LoginProxy::setPhoneNumber(ProtocolReader* __r__)
{
	std::string accountname;
	std::string phoneNumber;
	// deserialize accountname
	{
		if(!__r__->readType(accountname, 65535)) return false;
	}
	// deserialize phoneNumber
	{
		if(!__r__->readType(phoneNumber, 65535)) return false;
	}
	return setPhoneNumber(accountname,phoneNumber);
}
bool SGE_World2LoginProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!queryAccount(r)) return false;
		}
		break;
		case 1:
		{
			if(!setAccountSeal(r)) return false;
		}
		break;
		case 2:
		{
			if(!setPhoneNumber(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_Login2WorldStub::queryAccountOk(const COM_AccountInfo& info,bool isNew,bool isSeal)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	// serialize isNew
	{
		w->writeType(isNew);
	}
	// serialize isSeal
	{
		w->writeType(isSeal);
	}
	methodEnd();
}
void SGE_Login2WorldStub::setAccountSealOk(const std::string& accountname)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize accountname
	{
		w->writeType(accountname);
	}
	methodEnd();
}
bool SGE_Login2WorldProxy::queryAccountOk(ProtocolReader* __r__)
{
	COM_AccountInfo info;
	bool isNew=false;
	bool isSeal=false;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	// deserialize isNew
	{
		if(!__r__->readType(isNew)) return false;
	}
	// deserialize isSeal
	{
		if(!__r__->readType(isSeal)) return false;
	}
	return queryAccountOk(info,isNew,isSeal);
}
bool SGE_Login2WorldProxy::setAccountSealOk(ProtocolReader* __r__)
{
	std::string accountname;
	// deserialize accountname
	{
		if(!__r__->readType(accountname, 65535)) return false;
	}
	return setAccountSealOk(accountname);
}
bool SGE_Login2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!queryAccountOk(r)) return false;
		}
		break;
		case 1:
		{
			if(!setAccountSealOk(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_Gateway2WorldStub::syncConnectInfo(int32_t indoor,const std::string& ip)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize indoor
	{
		w->writeType(indoor);
	}
	// serialize ip
	{
		w->writeType(ip);
	}
	methodEnd();
}
bool SGE_Gateway2WorldProxy::syncConnectInfo(ProtocolReader* __r__)
{
	int32_t indoor=0;
	std::string ip;
	// deserialize indoor
	{
		if(!__r__->readType(indoor)) return false;
	}
	// deserialize ip
	{
		if(!__r__->readType(ip, 65535)) return false;
	}
	return syncConnectInfo(indoor,ip);
}
bool SGE_Gateway2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!syncConnectInfo(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_World2DBStub::queryPlayerSimpleInformation(const std::string& username,int32_t serverId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize serverId
	{
		w->writeType(serverId);
	}
	methodEnd();
}
void SGE_World2DBStub::queryPlayer(const std::string& username,int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_World2DBStub::createPlayer(const std::string& username,const SGE_DBPlayerData& inst,int32_t serverId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	// serialize serverId
	{
		w->writeType(serverId);
	}
	methodEnd();
}
void SGE_World2DBStub::updatePlayer(const std::string& username,const SGE_DBPlayerData& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::deletePlayer(const std::string& playername)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	methodEnd();
}
void SGE_World2DBStub::queryPlayerById(const std::string& name,int32_t instId,int32_t where)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	// serialize instId
	{
		w->writeType(instId);
	}
	// serialize where
	{
		w->writeType(where);
	}
	methodEnd();
}
void SGE_World2DBStub::insertEndlessStair(int32_t rank,const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize rank
	{
		w->writeType(rank);
	}
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void SGE_World2DBStub::updateEndlessStair(int32_t rank,const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize rank
	{
		w->writeType(rank);
	}
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
void SGE_World2DBStub::createBaby(const std::string& playername,const COM_BabyInst& inst,bool isToStorage)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	// serialize isToStorage
	{
		w->writeType(isToStorage);
	}
	methodEnd();
}
void SGE_World2DBStub::deleteBaby(const std::string& playername,int32_t babyInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize babyInstId
	{
		w->writeType(babyInstId);
	}
	methodEnd();
}
void SGE_World2DBStub::updateBaby(const COM_BabyInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 10;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::updateBabys(const std::string& playername,const std::vector< COM_BabyInst >& babys)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 11;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize babys
	{
		uint32_t __len__ = (uint32_t)babys.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			babys[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_World2DBStub::queryBabyById(const std::string& name,uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 12;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void SGE_World2DBStub::createEmployee(const std::string& playername,const COM_EmployeeInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 13;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::deleteEmployee(const std::string& playername,const std::vector< uint32_t >& instIds)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 14;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize instIds
	{
		uint32_t __len__ = (uint32_t)instIds.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(instIds[i]);
		}
	}
	methodEnd();
}
void SGE_World2DBStub::updateEmployee(const COM_EmployeeInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 15;
	w->writeType(pid);
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::queryEmployeeById(const std::string& name,uint32_t instid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 16;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	// serialize instid
	{
		w->writeType(instid);
	}
	methodEnd();
}
void SGE_World2DBStub::insertMail(const COM_Mail& mail)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 17;
	w->writeType(pid);
	// serialize mail
	{
		mail.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::insertMailAll(const COM_Mail& mail)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 18;
	w->writeType(pid);
	// serialize mail
	{
		mail.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::insertMailByRecvs(const COM_Mail& mail,const std::vector< std::string >& recvs)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 19;
	w->writeType(pid);
	// serialize mail
	{
		mail.serialize(w);
	}
	// serialize recvs
	{
		uint32_t __len__ = (uint32_t)recvs.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(recvs[i]);
		}
	}
	methodEnd();
}
void SGE_World2DBStub::fatchMail(const std::string& recvName,int32_t mailId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 20;
	w->writeType(pid);
	// serialize recvName
	{
		w->writeType(recvName);
	}
	// serialize mailId
	{
		w->writeType(mailId);
	}
	methodEnd();
}
void SGE_World2DBStub::delMail(const std::string& recvName,int32_t mailId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 21;
	w->writeType(pid);
	// serialize recvName
	{
		w->writeType(recvName);
	}
	// serialize mailId
	{
		w->writeType(mailId);
	}
	methodEnd();
}
void SGE_World2DBStub::updateMail(const COM_Mail& mail)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 22;
	w->writeType(pid);
	// serialize mail
	{
		mail.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::insertGuild(const COM_Guild& guild,const COM_GuildMember& guildMember)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 23;
	w->writeType(pid);
	// serialize guild
	{
		guild.serialize(w);
	}
	// serialize guildMember
	{
		guildMember.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::updateGuildRequestList(uint32_t guildId,const std::vector< COM_GuildRequestData >& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 24;
	w->writeType(pid);
	// serialize guildId
	{
		w->writeType(guildId);
	}
	// serialize data
	{
		uint32_t __len__ = (uint32_t)data.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			data[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_World2DBStub::createGuildMember(const COM_GuildMember& guildMember)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 25;
	w->writeType(pid);
	// serialize guildMember
	{
		guildMember.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::delGuild(int32_t guildId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 26;
	w->writeType(pid);
	// serialize guildId
	{
		w->writeType(guildId);
	}
	methodEnd();
}
void SGE_World2DBStub::updateGuildNotice(uint32_t guildId,const std::string& notice)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 27;
	w->writeType(pid);
	// serialize guildId
	{
		w->writeType(guildId);
	}
	// serialize notice
	{
		w->writeType(notice);
	}
	methodEnd();
}
void SGE_World2DBStub::updateGuild(const COM_Guild& guild)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 28;
	w->writeType(pid);
	// serialize guild
	{
		guild.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::updateMemberPosition(int32_t roleId,GuildJob job)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 29;
	w->writeType(pid);
	// serialize roleId
	{
		w->writeType(roleId);
	}
	// serialize job
	{
		uint8_t __e__ = (uint8_t)job;
		w->writeType(__e__);
	}
	methodEnd();
}
void SGE_World2DBStub::updateMemberContribution(int32_t roleId,int32_t contribution)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 30;
	w->writeType(pid);
	// serialize roleId
	{
		w->writeType(roleId);
	}
	// serialize contribution
	{
		w->writeType(contribution);
	}
	methodEnd();
}
void SGE_World2DBStub::updateGuildStruction(uint32_t guildId,int8_t level,int32_t struction)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 31;
	w->writeType(pid);
	// serialize guildId
	{
		w->writeType(guildId);
	}
	// serialize level
	{
		w->writeType(level);
	}
	// serialize struction
	{
		w->writeType(struction);
	}
	methodEnd();
}
void SGE_World2DBStub::deleteGuildMember(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 32;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_World2DBStub::insertActivity(ADType adt,const SGE_SysActivity& date)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 33;
	w->writeType(pid);
	// serialize adt
	{
		uint8_t __e__ = (uint8_t)adt;
		w->writeType(__e__);
	}
	// serialize date
	{
		date.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::insertLoseCharge(int32_t playerId,const SGE_OrderInfo& order)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 34;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize order
	{
		order.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::insertEmployeeQuest(uint32_t playerId,const SGE_PlayerEmployeeQuest& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 35;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_World2DBStub::delEmployeeQuest(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 36;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_World2DBStub::deleteEndlessStair(const std::string& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 37;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	methodEnd();
}
bool SGE_World2DBProxy::queryPlayerSimpleInformation(ProtocolReader* __r__)
{
	std::string username;
	int32_t serverId=0;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize serverId
	{
		if(!__r__->readType(serverId)) return false;
	}
	return queryPlayerSimpleInformation(username,serverId);
}
bool SGE_World2DBProxy::queryPlayer(ProtocolReader* __r__)
{
	std::string username;
	int32_t playerId=0;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return queryPlayer(username,playerId);
}
bool SGE_World2DBProxy::createPlayer(ProtocolReader* __r__)
{
	std::string username;
	SGE_DBPlayerData inst;
	int32_t serverId=0;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	// deserialize serverId
	{
		if(!__r__->readType(serverId)) return false;
	}
	return createPlayer(username,inst,serverId);
}
bool SGE_World2DBProxy::updatePlayer(ProtocolReader* __r__)
{
	std::string username;
	SGE_DBPlayerData inst;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return updatePlayer(username,inst);
}
bool SGE_World2DBProxy::deletePlayer(ProtocolReader* __r__)
{
	std::string playername;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	return deletePlayer(playername);
}
bool SGE_World2DBProxy::queryPlayerById(ProtocolReader* __r__)
{
	std::string name;
	int32_t instId=0;
	int32_t where=0;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	// deserialize where
	{
		if(!__r__->readType(where)) return false;
	}
	return queryPlayerById(name,instId,where);
}
bool SGE_World2DBProxy::insertEndlessStair(ProtocolReader* __r__)
{
	int32_t rank=0;
	std::string name;
	// deserialize rank
	{
		if(!__r__->readType(rank)) return false;
	}
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return insertEndlessStair(rank,name);
}
bool SGE_World2DBProxy::updateEndlessStair(ProtocolReader* __r__)
{
	int32_t rank=0;
	std::string name;
	// deserialize rank
	{
		if(!__r__->readType(rank)) return false;
	}
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return updateEndlessStair(rank,name);
}
bool SGE_World2DBProxy::createBaby(ProtocolReader* __r__)
{
	std::string playername;
	COM_BabyInst inst;
	bool isToStorage=false;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	// deserialize isToStorage
	{
		if(!__r__->readType(isToStorage)) return false;
	}
	return createBaby(playername,inst,isToStorage);
}
bool SGE_World2DBProxy::deleteBaby(ProtocolReader* __r__)
{
	std::string playername;
	int32_t babyInstId=0;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize babyInstId
	{
		if(!__r__->readType(babyInstId)) return false;
	}
	return deleteBaby(playername,babyInstId);
}
bool SGE_World2DBProxy::updateBaby(ProtocolReader* __r__)
{
	COM_BabyInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return updateBaby(inst);
}
bool SGE_World2DBProxy::updateBabys(ProtocolReader* __r__)
{
	std::string playername;
	std::vector< COM_BabyInst > babys;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize babys
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		babys.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!babys[i].deserialize(__r__)) return false;
		}
	}
	return updateBabys(playername,babys);
}
bool SGE_World2DBProxy::queryBabyById(ProtocolReader* __r__)
{
	std::string name;
	uint32_t instid=0;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return queryBabyById(name,instid);
}
bool SGE_World2DBProxy::createEmployee(ProtocolReader* __r__)
{
	std::string playername;
	COM_EmployeeInst inst;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return createEmployee(playername,inst);
}
bool SGE_World2DBProxy::deleteEmployee(ProtocolReader* __r__)
{
	std::string playername;
	std::vector< uint32_t > instIds;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize instIds
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		instIds.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(instIds[i])) return false;
		}
	}
	return deleteEmployee(playername,instIds);
}
bool SGE_World2DBProxy::updateEmployee(ProtocolReader* __r__)
{
	COM_EmployeeInst inst;
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return updateEmployee(inst);
}
bool SGE_World2DBProxy::queryEmployeeById(ProtocolReader* __r__)
{
	std::string name;
	uint32_t instid=0;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	// deserialize instid
	{
		if(!__r__->readType(instid)) return false;
	}
	return queryEmployeeById(name,instid);
}
bool SGE_World2DBProxy::insertMail(ProtocolReader* __r__)
{
	COM_Mail mail;
	// deserialize mail
	{
		if(!mail.deserialize(__r__)) return false;
	}
	return insertMail(mail);
}
bool SGE_World2DBProxy::insertMailAll(ProtocolReader* __r__)
{
	COM_Mail mail;
	// deserialize mail
	{
		if(!mail.deserialize(__r__)) return false;
	}
	return insertMailAll(mail);
}
bool SGE_World2DBProxy::insertMailByRecvs(ProtocolReader* __r__)
{
	COM_Mail mail;
	std::vector< std::string > recvs;
	// deserialize mail
	{
		if(!mail.deserialize(__r__)) return false;
	}
	// deserialize recvs
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		recvs.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(recvs[i], 65535)) return false;
		}
	}
	return insertMailByRecvs(mail,recvs);
}
bool SGE_World2DBProxy::fatchMail(ProtocolReader* __r__)
{
	std::string recvName;
	int32_t mailId=0;
	// deserialize recvName
	{
		if(!__r__->readType(recvName, 65535)) return false;
	}
	// deserialize mailId
	{
		if(!__r__->readType(mailId)) return false;
	}
	return fatchMail(recvName,mailId);
}
bool SGE_World2DBProxy::delMail(ProtocolReader* __r__)
{
	std::string recvName;
	int32_t mailId=0;
	// deserialize recvName
	{
		if(!__r__->readType(recvName, 65535)) return false;
	}
	// deserialize mailId
	{
		if(!__r__->readType(mailId)) return false;
	}
	return delMail(recvName,mailId);
}
bool SGE_World2DBProxy::updateMail(ProtocolReader* __r__)
{
	COM_Mail mail;
	// deserialize mail
	{
		if(!mail.deserialize(__r__)) return false;
	}
	return updateMail(mail);
}
bool SGE_World2DBProxy::insertGuild(ProtocolReader* __r__)
{
	COM_Guild guild;
	COM_GuildMember guildMember;
	// deserialize guild
	{
		if(!guild.deserialize(__r__)) return false;
	}
	// deserialize guildMember
	{
		if(!guildMember.deserialize(__r__)) return false;
	}
	return insertGuild(guild,guildMember);
}
bool SGE_World2DBProxy::updateGuildRequestList(ProtocolReader* __r__)
{
	uint32_t guildId=0;
	std::vector< COM_GuildRequestData > data;
	// deserialize guildId
	{
		if(!__r__->readType(guildId)) return false;
	}
	// deserialize data
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		data.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!data[i].deserialize(__r__)) return false;
		}
	}
	return updateGuildRequestList(guildId,data);
}
bool SGE_World2DBProxy::createGuildMember(ProtocolReader* __r__)
{
	COM_GuildMember guildMember;
	// deserialize guildMember
	{
		if(!guildMember.deserialize(__r__)) return false;
	}
	return createGuildMember(guildMember);
}
bool SGE_World2DBProxy::delGuild(ProtocolReader* __r__)
{
	int32_t guildId=0;
	// deserialize guildId
	{
		if(!__r__->readType(guildId)) return false;
	}
	return delGuild(guildId);
}
bool SGE_World2DBProxy::updateGuildNotice(ProtocolReader* __r__)
{
	uint32_t guildId=0;
	std::string notice;
	// deserialize guildId
	{
		if(!__r__->readType(guildId)) return false;
	}
	// deserialize notice
	{
		if(!__r__->readType(notice, 65535)) return false;
	}
	return updateGuildNotice(guildId,notice);
}
bool SGE_World2DBProxy::updateGuild(ProtocolReader* __r__)
{
	COM_Guild guild;
	// deserialize guild
	{
		if(!guild.deserialize(__r__)) return false;
	}
	return updateGuild(guild);
}
bool SGE_World2DBProxy::updateMemberPosition(ProtocolReader* __r__)
{
	int32_t roleId=0;
	GuildJob job=(GuildJob)(0);
	// deserialize roleId
	{
		if(!__r__->readType(roleId)) return false;
	}
	// deserialize job
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 7) return false;
		job = (GuildJob)__e__;
	}
	return updateMemberPosition(roleId,job);
}
bool SGE_World2DBProxy::updateMemberContribution(ProtocolReader* __r__)
{
	int32_t roleId=0;
	int32_t contribution=0;
	// deserialize roleId
	{
		if(!__r__->readType(roleId)) return false;
	}
	// deserialize contribution
	{
		if(!__r__->readType(contribution)) return false;
	}
	return updateMemberContribution(roleId,contribution);
}
bool SGE_World2DBProxy::updateGuildStruction(ProtocolReader* __r__)
{
	uint32_t guildId=0;
	int8_t level=0;
	int32_t struction=0;
	// deserialize guildId
	{
		if(!__r__->readType(guildId)) return false;
	}
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	// deserialize struction
	{
		if(!__r__->readType(struction)) return false;
	}
	return updateGuildStruction(guildId,level,struction);
}
bool SGE_World2DBProxy::deleteGuildMember(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return deleteGuildMember(playerId);
}
bool SGE_World2DBProxy::insertActivity(ProtocolReader* __r__)
{
	ADType adt=(ADType)(0);
	SGE_SysActivity date;
	// deserialize adt
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 21) return false;
		adt = (ADType)__e__;
	}
	// deserialize date
	{
		if(!date.deserialize(__r__)) return false;
	}
	return insertActivity(adt,date);
}
bool SGE_World2DBProxy::insertLoseCharge(ProtocolReader* __r__)
{
	int32_t playerId=0;
	SGE_OrderInfo order;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize order
	{
		if(!order.deserialize(__r__)) return false;
	}
	return insertLoseCharge(playerId,order);
}
bool SGE_World2DBProxy::insertEmployeeQuest(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	SGE_PlayerEmployeeQuest data;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return insertEmployeeQuest(playerId,data);
}
bool SGE_World2DBProxy::delEmployeeQuest(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return delEmployeeQuest(playerId);
}
bool SGE_World2DBProxy::deleteEndlessStair(ProtocolReader* __r__)
{
	std::string name;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	return deleteEndlessStair(name);
}
bool SGE_World2DBProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!queryPlayerSimpleInformation(r)) return false;
		}
		break;
		case 1:
		{
			if(!queryPlayer(r)) return false;
		}
		break;
		case 2:
		{
			if(!createPlayer(r)) return false;
		}
		break;
		case 3:
		{
			if(!updatePlayer(r)) return false;
		}
		break;
		case 4:
		{
			if(!deletePlayer(r)) return false;
		}
		break;
		case 5:
		{
			if(!queryPlayerById(r)) return false;
		}
		break;
		case 6:
		{
			if(!insertEndlessStair(r)) return false;
		}
		break;
		case 7:
		{
			if(!updateEndlessStair(r)) return false;
		}
		break;
		case 8:
		{
			if(!createBaby(r)) return false;
		}
		break;
		case 9:
		{
			if(!deleteBaby(r)) return false;
		}
		break;
		case 10:
		{
			if(!updateBaby(r)) return false;
		}
		break;
		case 11:
		{
			if(!updateBabys(r)) return false;
		}
		break;
		case 12:
		{
			if(!queryBabyById(r)) return false;
		}
		break;
		case 13:
		{
			if(!createEmployee(r)) return false;
		}
		break;
		case 14:
		{
			if(!deleteEmployee(r)) return false;
		}
		break;
		case 15:
		{
			if(!updateEmployee(r)) return false;
		}
		break;
		case 16:
		{
			if(!queryEmployeeById(r)) return false;
		}
		break;
		case 17:
		{
			if(!insertMail(r)) return false;
		}
		break;
		case 18:
		{
			if(!insertMailAll(r)) return false;
		}
		break;
		case 19:
		{
			if(!insertMailByRecvs(r)) return false;
		}
		break;
		case 20:
		{
			if(!fatchMail(r)) return false;
		}
		break;
		case 21:
		{
			if(!delMail(r)) return false;
		}
		break;
		case 22:
		{
			if(!updateMail(r)) return false;
		}
		break;
		case 23:
		{
			if(!insertGuild(r)) return false;
		}
		break;
		case 24:
		{
			if(!updateGuildRequestList(r)) return false;
		}
		break;
		case 25:
		{
			if(!createGuildMember(r)) return false;
		}
		break;
		case 26:
		{
			if(!delGuild(r)) return false;
		}
		break;
		case 27:
		{
			if(!updateGuildNotice(r)) return false;
		}
		break;
		case 28:
		{
			if(!updateGuild(r)) return false;
		}
		break;
		case 29:
		{
			if(!updateMemberPosition(r)) return false;
		}
		break;
		case 30:
		{
			if(!updateMemberContribution(r)) return false;
		}
		break;
		case 31:
		{
			if(!updateGuildStruction(r)) return false;
		}
		break;
		case 32:
		{
			if(!deleteGuildMember(r)) return false;
		}
		break;
		case 33:
		{
			if(!insertActivity(r)) return false;
		}
		break;
		case 34:
		{
			if(!insertLoseCharge(r)) return false;
		}
		break;
		case 35:
		{
			if(!insertEmployeeQuest(r)) return false;
		}
		break;
		case 36:
		{
			if(!delEmployeeQuest(r)) return false;
		}
		break;
		case 37:
		{
			if(!deleteEndlessStair(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_DB2WorldStub::syncGlobalGuid(uint32_t id)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize id
	{
		w->writeType(id);
	}
	methodEnd();
}
void SGE_DB2WorldStub::syncContactInfo(const std::vector< SGE_ContactInfoExt >& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize info
	{
		uint32_t __len__ = (uint32_t)info.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			info[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryPlayerSimpleInformationOk(const std::string& username,const std::vector< COM_SimpleInformation >& insts,int32_t serverId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize insts
	{
		uint32_t __len__ = (uint32_t)insts.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			insts[i].serialize(w);
		}
	}
	// serialize serverId
	{
		w->writeType(serverId);
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryPlayerOk(const std::string& username,const SGE_DBPlayerData& player)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize player
	{
		player.serialize(w);
	}
	methodEnd();
}
void SGE_DB2WorldStub::createPlayerOk(const std::string& username,const SGE_DBPlayerData& inst,int32_t inDoorId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	// serialize inDoorId
	{
		w->writeType(inDoorId);
	}
	methodEnd();
}
void SGE_DB2WorldStub::createPlayerSameName(const std::string& username)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize username
	{
		w->writeType(username);
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryPlayerByIdOK(const std::string& playername,const SGE_DBPlayerData& inst,int32_t where)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	// serialize where
	{
		w->writeType(where);
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryEndlessStairAllDateOK(const std::vector< std::string >& name)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize name
	{
		uint32_t __len__ = (uint32_t)name.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(name[i]);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryPlayerByLevelOK(const std::vector< COM_ContactInfo >& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	// serialize info
	{
		uint32_t __len__ = (uint32_t)info.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			info[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryPlayerByFFOK(const std::vector< COM_ContactInfo >& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	// serialize info
	{
		uint32_t __len__ = (uint32_t)info.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			info[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::createBabyOK(const std::string& playername,const COM_BabyInst& inst,bool isToStorage)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 10;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	// serialize isToStorage
	{
		w->writeType(isToStorage);
	}
	methodEnd();
}
void SGE_DB2WorldStub::deleteBabyOK(const std::string& playername,int32_t babyInstId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 11;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize babyInstId
	{
		w->writeType(babyInstId);
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryBabyByFFOK(const std::vector< COM_BabyRankData >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 12;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryBabyByIdOK(const std::string& name,const COM_BabyInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 13;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_DB2WorldStub::UpdateBabysOK(const std::string& playername)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 14;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	methodEnd();
}
void SGE_DB2WorldStub::createEmployeeOK(const std::string& playername,const COM_EmployeeInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 15;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_DB2WorldStub::deleteEmployeeOK(const std::string& playername,const std::vector< uint32_t >& instIds)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 16;
	w->writeType(pid);
	// serialize playername
	{
		w->writeType(playername);
	}
	// serialize instIds
	{
		uint32_t __len__ = (uint32_t)instIds.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(instIds[i]);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryEmployeeByFFOK(const std::vector< COM_EmployeeRankData >& infos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 17;
	w->writeType(pid);
	// serialize infos
	{
		uint32_t __len__ = (uint32_t)infos.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			infos[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::queryEmployeeByIdOK(const std::string& name,const COM_EmployeeInst& inst)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 18;
	w->writeType(pid);
	// serialize name
	{
		w->writeType(name);
	}
	// serialize inst
	{
		inst.serialize(w);
	}
	methodEnd();
}
void SGE_DB2WorldStub::appendMail(const std::string& playerName,const std::vector< COM_Mail >& mails)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 19;
	w->writeType(pid);
	// serialize playerName
	{
		w->writeType(playerName);
	}
	// serialize mails
	{
		uint32_t __len__ = (uint32_t)mails.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			mails[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::insertGuildOK(const COM_Guild& guild,const COM_GuildMember& guildMember)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 20;
	w->writeType(pid);
	// serialize guild
	{
		guild.serialize(w);
	}
	// serialize guildMember
	{
		guildMember.serialize(w);
	}
	methodEnd();
}
void SGE_DB2WorldStub::updateMemberJobOk(int32_t roleId,GuildJob job)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 21;
	w->writeType(pid);
	// serialize roleId
	{
		w->writeType(roleId);
	}
	// serialize job
	{
		uint8_t __e__ = (uint8_t)job;
		w->writeType(__e__);
	}
	methodEnd();
}
void SGE_DB2WorldStub::syncGuild(const std::vector< COM_Guild >& guilds)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 22;
	w->writeType(pid);
	// serialize guilds
	{
		uint32_t __len__ = (uint32_t)guilds.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			guilds[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::syncGuildMember(const std::vector< COM_GuildMember >& guildMember)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 23;
	w->writeType(pid);
	// serialize guildMember
	{
		uint32_t __len__ = (uint32_t)guildMember.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			guildMember[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_DB2WorldStub::fatchActivity(const SGE_SysActivity& date)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 24;
	w->writeType(pid);
	// serialize date
	{
		date.serialize(w);
	}
	methodEnd();
}
void SGE_DB2WorldStub::syncEmployeeQuest(const std::vector< SGE_PlayerEmployeeQuest >& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 25;
	w->writeType(pid);
	// serialize info
	{
		uint32_t __len__ = (uint32_t)info.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			info[i].serialize(w);
		}
	}
	methodEnd();
}
bool SGE_DB2WorldProxy::syncGlobalGuid(ProtocolReader* __r__)
{
	uint32_t id=0;
	// deserialize id
	{
		if(!__r__->readType(id)) return false;
	}
	return syncGlobalGuid(id);
}
bool SGE_DB2WorldProxy::syncContactInfo(ProtocolReader* __r__)
{
	std::vector< SGE_ContactInfoExt > info;
	// deserialize info
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		info.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!info[i].deserialize(__r__)) return false;
		}
	}
	return syncContactInfo(info);
}
bool SGE_DB2WorldProxy::queryPlayerSimpleInformationOk(ProtocolReader* __r__)
{
	std::string username;
	std::vector< COM_SimpleInformation > insts;
	int32_t serverId=0;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize insts
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		insts.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!insts[i].deserialize(__r__)) return false;
		}
	}
	// deserialize serverId
	{
		if(!__r__->readType(serverId)) return false;
	}
	return queryPlayerSimpleInformationOk(username,insts,serverId);
}
bool SGE_DB2WorldProxy::queryPlayerOk(ProtocolReader* __r__)
{
	std::string username;
	SGE_DBPlayerData player;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize player
	{
		if(!player.deserialize(__r__)) return false;
	}
	return queryPlayerOk(username,player);
}
bool SGE_DB2WorldProxy::createPlayerOk(ProtocolReader* __r__)
{
	std::string username;
	SGE_DBPlayerData inst;
	int32_t inDoorId=0;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	// deserialize inDoorId
	{
		if(!__r__->readType(inDoorId)) return false;
	}
	return createPlayerOk(username,inst,inDoorId);
}
bool SGE_DB2WorldProxy::createPlayerSameName(ProtocolReader* __r__)
{
	std::string username;
	// deserialize username
	{
		if(!__r__->readType(username, 65535)) return false;
	}
	return createPlayerSameName(username);
}
bool SGE_DB2WorldProxy::queryPlayerByIdOK(ProtocolReader* __r__)
{
	std::string playername;
	SGE_DBPlayerData inst;
	int32_t where=0;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	// deserialize where
	{
		if(!__r__->readType(where)) return false;
	}
	return queryPlayerByIdOK(playername,inst,where);
}
bool SGE_DB2WorldProxy::queryEndlessStairAllDateOK(ProtocolReader* __r__)
{
	std::vector< std::string > name;
	// deserialize name
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		name.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(name[i], 65535)) return false;
		}
	}
	return queryEndlessStairAllDateOK(name);
}
bool SGE_DB2WorldProxy::queryPlayerByLevelOK(ProtocolReader* __r__)
{
	std::vector< COM_ContactInfo > info;
	// deserialize info
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		info.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!info[i].deserialize(__r__)) return false;
		}
	}
	return queryPlayerByLevelOK(info);
}
bool SGE_DB2WorldProxy::queryPlayerByFFOK(ProtocolReader* __r__)
{
	std::vector< COM_ContactInfo > info;
	// deserialize info
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		info.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!info[i].deserialize(__r__)) return false;
		}
	}
	return queryPlayerByFFOK(info);
}
bool SGE_DB2WorldProxy::createBabyOK(ProtocolReader* __r__)
{
	std::string playername;
	COM_BabyInst inst;
	bool isToStorage=false;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	// deserialize isToStorage
	{
		if(!__r__->readType(isToStorage)) return false;
	}
	return createBabyOK(playername,inst,isToStorage);
}
bool SGE_DB2WorldProxy::deleteBabyOK(ProtocolReader* __r__)
{
	std::string playername;
	int32_t babyInstId=0;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize babyInstId
	{
		if(!__r__->readType(babyInstId)) return false;
	}
	return deleteBabyOK(playername,babyInstId);
}
bool SGE_DB2WorldProxy::queryBabyByFFOK(ProtocolReader* __r__)
{
	std::vector< COM_BabyRankData > infos;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return queryBabyByFFOK(infos);
}
bool SGE_DB2WorldProxy::queryBabyByIdOK(ProtocolReader* __r__)
{
	std::string name;
	COM_BabyInst inst;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return queryBabyByIdOK(name,inst);
}
bool SGE_DB2WorldProxy::UpdateBabysOK(ProtocolReader* __r__)
{
	std::string playername;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	return UpdateBabysOK(playername);
}
bool SGE_DB2WorldProxy::createEmployeeOK(ProtocolReader* __r__)
{
	std::string playername;
	COM_EmployeeInst inst;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return createEmployeeOK(playername,inst);
}
bool SGE_DB2WorldProxy::deleteEmployeeOK(ProtocolReader* __r__)
{
	std::string playername;
	std::vector< uint32_t > instIds;
	// deserialize playername
	{
		if(!__r__->readType(playername, 65535)) return false;
	}
	// deserialize instIds
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		instIds.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(instIds[i])) return false;
		}
	}
	return deleteEmployeeOK(playername,instIds);
}
bool SGE_DB2WorldProxy::queryEmployeeByFFOK(ProtocolReader* __r__)
{
	std::vector< COM_EmployeeRankData > infos;
	// deserialize infos
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		infos.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!infos[i].deserialize(__r__)) return false;
		}
	}
	return queryEmployeeByFFOK(infos);
}
bool SGE_DB2WorldProxy::queryEmployeeByIdOK(ProtocolReader* __r__)
{
	std::string name;
	COM_EmployeeInst inst;
	// deserialize name
	{
		if(!__r__->readType(name, 65535)) return false;
	}
	// deserialize inst
	{
		if(!inst.deserialize(__r__)) return false;
	}
	return queryEmployeeByIdOK(name,inst);
}
bool SGE_DB2WorldProxy::appendMail(ProtocolReader* __r__)
{
	std::string playerName;
	std::vector< COM_Mail > mails;
	// deserialize playerName
	{
		if(!__r__->readType(playerName, 65535)) return false;
	}
	// deserialize mails
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		mails.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!mails[i].deserialize(__r__)) return false;
		}
	}
	return appendMail(playerName,mails);
}
bool SGE_DB2WorldProxy::insertGuildOK(ProtocolReader* __r__)
{
	COM_Guild guild;
	COM_GuildMember guildMember;
	// deserialize guild
	{
		if(!guild.deserialize(__r__)) return false;
	}
	// deserialize guildMember
	{
		if(!guildMember.deserialize(__r__)) return false;
	}
	return insertGuildOK(guild,guildMember);
}
bool SGE_DB2WorldProxy::updateMemberJobOk(ProtocolReader* __r__)
{
	int32_t roleId=0;
	GuildJob job=(GuildJob)(0);
	// deserialize roleId
	{
		if(!__r__->readType(roleId)) return false;
	}
	// deserialize job
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 7) return false;
		job = (GuildJob)__e__;
	}
	return updateMemberJobOk(roleId,job);
}
bool SGE_DB2WorldProxy::syncGuild(ProtocolReader* __r__)
{
	std::vector< COM_Guild > guilds;
	// deserialize guilds
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		guilds.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!guilds[i].deserialize(__r__)) return false;
		}
	}
	return syncGuild(guilds);
}
bool SGE_DB2WorldProxy::syncGuildMember(ProtocolReader* __r__)
{
	std::vector< COM_GuildMember > guildMember;
	// deserialize guildMember
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		guildMember.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!guildMember[i].deserialize(__r__)) return false;
		}
	}
	return syncGuildMember(guildMember);
}
bool SGE_DB2WorldProxy::fatchActivity(ProtocolReader* __r__)
{
	SGE_SysActivity date;
	// deserialize date
	{
		if(!date.deserialize(__r__)) return false;
	}
	return fatchActivity(date);
}
bool SGE_DB2WorldProxy::syncEmployeeQuest(ProtocolReader* __r__)
{
	std::vector< SGE_PlayerEmployeeQuest > info;
	// deserialize info
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		info.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!info[i].deserialize(__r__)) return false;
		}
	}
	return syncEmployeeQuest(info);
}
bool SGE_DB2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!syncGlobalGuid(r)) return false;
		}
		break;
		case 1:
		{
			if(!syncContactInfo(r)) return false;
		}
		break;
		case 2:
		{
			if(!queryPlayerSimpleInformationOk(r)) return false;
		}
		break;
		case 3:
		{
			if(!queryPlayerOk(r)) return false;
		}
		break;
		case 4:
		{
			if(!createPlayerOk(r)) return false;
		}
		break;
		case 5:
		{
			if(!createPlayerSameName(r)) return false;
		}
		break;
		case 6:
		{
			if(!queryPlayerByIdOK(r)) return false;
		}
		break;
		case 7:
		{
			if(!queryEndlessStairAllDateOK(r)) return false;
		}
		break;
		case 8:
		{
			if(!queryPlayerByLevelOK(r)) return false;
		}
		break;
		case 9:
		{
			if(!queryPlayerByFFOK(r)) return false;
		}
		break;
		case 10:
		{
			if(!createBabyOK(r)) return false;
		}
		break;
		case 11:
		{
			if(!deleteBabyOK(r)) return false;
		}
		break;
		case 12:
		{
			if(!queryBabyByFFOK(r)) return false;
		}
		break;
		case 13:
		{
			if(!queryBabyByIdOK(r)) return false;
		}
		break;
		case 14:
		{
			if(!UpdateBabysOK(r)) return false;
		}
		break;
		case 15:
		{
			if(!createEmployeeOK(r)) return false;
		}
		break;
		case 16:
		{
			if(!deleteEmployeeOK(r)) return false;
		}
		break;
		case 17:
		{
			if(!queryEmployeeByFFOK(r)) return false;
		}
		break;
		case 18:
		{
			if(!queryEmployeeByIdOK(r)) return false;
		}
		break;
		case 19:
		{
			if(!appendMail(r)) return false;
		}
		break;
		case 20:
		{
			if(!insertGuildOK(r)) return false;
		}
		break;
		case 21:
		{
			if(!updateMemberJobOk(r)) return false;
		}
		break;
		case 22:
		{
			if(!syncGuild(r)) return false;
		}
		break;
		case 23:
		{
			if(!syncGuildMember(r)) return false;
		}
		break;
		case 24:
		{
			if(!fatchActivity(r)) return false;
		}
		break;
		case 25:
		{
			if(!syncEmployeeQuest(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
bool SGE_Scene2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_World2SceneStub::initDynamicNpcs(NpcType type,int32_t count)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize count
	{
		w->writeType(count);
	}
	methodEnd();
}
void SGE_World2SceneStub::refreshDynamicNpcs(NpcType type,int32_t count)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	// serialize count
	{
		w->writeType(count);
	}
	methodEnd();
}
void SGE_World2SceneStub::finiDynamicNpcs(NpcType type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void SGE_World2SceneStub::addDynamicNpcs(int32_t sceneId,const std::vector< int32_t >& npcs)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	// serialize npcs
	{
		uint32_t __len__ = (uint32_t)npcs.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(npcs[i]);
		}
	}
	methodEnd();
}
void SGE_World2SceneStub::delDynamicNpc(int32_t npcId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize npcId
	{
		w->writeType(npcId);
	}
	methodEnd();
}
void SGE_World2SceneStub::delDynamicNpc2(int32_t sceneId,int32_t npcId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	// serialize npcId
	{
		w->writeType(npcId);
	}
	methodEnd();
}
void SGE_World2SceneStub::openSceneCopy(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
void SGE_World2SceneStub::closeSceneCopy(int32_t instId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize instId
	{
		w->writeType(instId);
	}
	methodEnd();
}
bool SGE_World2SceneProxy::initDynamicNpcs(ProtocolReader* __r__)
{
	NpcType type=(NpcType)(0);
	int32_t count=0;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 11) return false;
		type = (NpcType)__e__;
	}
	// deserialize count
	{
		if(!__r__->readType(count)) return false;
	}
	return initDynamicNpcs(type,count);
}
bool SGE_World2SceneProxy::refreshDynamicNpcs(ProtocolReader* __r__)
{
	NpcType type=(NpcType)(0);
	int32_t count=0;
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 11) return false;
		type = (NpcType)__e__;
	}
	// deserialize count
	{
		if(!__r__->readType(count)) return false;
	}
	return refreshDynamicNpcs(type,count);
}
bool SGE_World2SceneProxy::finiDynamicNpcs(ProtocolReader* __r__)
{
	NpcType type=(NpcType)(0);
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 11) return false;
		type = (NpcType)__e__;
	}
	return finiDynamicNpcs(type);
}
bool SGE_World2SceneProxy::addDynamicNpcs(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	std::vector< int32_t > npcs;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	// deserialize npcs
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		npcs.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(npcs[i])) return false;
		}
	}
	return addDynamicNpcs(sceneId,npcs);
}
bool SGE_World2SceneProxy::delDynamicNpc(ProtocolReader* __r__)
{
	int32_t npcId=0;
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	return delDynamicNpc(npcId);
}
bool SGE_World2SceneProxy::delDynamicNpc2(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	int32_t npcId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	return delDynamicNpc2(sceneId,npcId);
}
bool SGE_World2SceneProxy::openSceneCopy(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return openSceneCopy(instId);
}
bool SGE_World2SceneProxy::closeSceneCopy(ProtocolReader* __r__)
{
	int32_t instId=0;
	// deserialize instId
	{
		if(!__r__->readType(instId)) return false;
	}
	return closeSceneCopy(instId);
}
bool SGE_World2SceneProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!initDynamicNpcs(r)) return false;
		}
		break;
		case 1:
		{
			if(!refreshDynamicNpcs(r)) return false;
		}
		break;
		case 2:
		{
			if(!finiDynamicNpcs(r)) return false;
		}
		break;
		case 3:
		{
			if(!addDynamicNpcs(r)) return false;
		}
		break;
		case 4:
		{
			if(!delDynamicNpc(r)) return false;
		}
		break;
		case 5:
		{
			if(!delDynamicNpc2(r)) return false;
		}
		break;
		case 6:
		{
			if(!openSceneCopy(r)) return false;
		}
		break;
		case 7:
		{
			if(!closeSceneCopy(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_Player_Scene2WorldStub::joinScene(const COM_SceneInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::move2(const COM_FPosition& pos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize pos
	{
		pos.serialize(w);
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::cantMove()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_Scene2WorldStub::transfor2(const COM_FPosition& pos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize pos
	{
		pos.serialize(w);
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::autoBattleResult(bool isOk)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize isOk
	{
		w->writeType(isOk);
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::zoneJoinBattle(int32_t zoneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize zoneId
	{
		w->writeType(zoneId);
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::playerAddNpc(const std::vector< int32_t >& npcs)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize npcs
	{
		uint32_t __len__ = (uint32_t)npcs.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(npcs[i]);
		}
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::playerDelNpc(const std::vector< int32_t >& npcs)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize npcs
	{
		uint32_t __len__ = (uint32_t)npcs.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(npcs[i]);
		}
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::talkedNpc(int32_t npcid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	// serialize npcid
	{
		w->writeType(npcid);
	}
	methodEnd();
}
void SGE_Player_Scene2WorldStub::findDynamicNpcOK(int32_t npcid,bool hasnpc)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	// serialize npcid
	{
		w->writeType(npcid);
	}
	// serialize hasnpc
	{
		w->writeType(hasnpc);
	}
	methodEnd();
}
bool SGE_Player_Scene2WorldProxy::joinScene(ProtocolReader* __r__)
{
	COM_SceneInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return joinScene(info);
}
bool SGE_Player_Scene2WorldProxy::move2(ProtocolReader* __r__)
{
	COM_FPosition pos;
	// deserialize pos
	{
		if(!pos.deserialize(__r__)) return false;
	}
	return move2(pos);
}
bool SGE_Player_Scene2WorldProxy::cantMove(ProtocolReader* __r__)
{
	return cantMove();
}
bool SGE_Player_Scene2WorldProxy::transfor2(ProtocolReader* __r__)
{
	COM_FPosition pos;
	// deserialize pos
	{
		if(!pos.deserialize(__r__)) return false;
	}
	return transfor2(pos);
}
bool SGE_Player_Scene2WorldProxy::autoBattleResult(ProtocolReader* __r__)
{
	bool isOk=false;
	// deserialize isOk
	{
		if(!__r__->readType(isOk)) return false;
	}
	return autoBattleResult(isOk);
}
bool SGE_Player_Scene2WorldProxy::zoneJoinBattle(ProtocolReader* __r__)
{
	int32_t zoneId=0;
	// deserialize zoneId
	{
		if(!__r__->readType(zoneId)) return false;
	}
	return zoneJoinBattle(zoneId);
}
bool SGE_Player_Scene2WorldProxy::playerAddNpc(ProtocolReader* __r__)
{
	std::vector< int32_t > npcs;
	// deserialize npcs
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		npcs.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(npcs[i])) return false;
		}
	}
	return playerAddNpc(npcs);
}
bool SGE_Player_Scene2WorldProxy::playerDelNpc(ProtocolReader* __r__)
{
	std::vector< int32_t > npcs;
	// deserialize npcs
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		npcs.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(npcs[i])) return false;
		}
	}
	return playerDelNpc(npcs);
}
bool SGE_Player_Scene2WorldProxy::talkedNpc(ProtocolReader* __r__)
{
	int32_t npcid=0;
	// deserialize npcid
	{
		if(!__r__->readType(npcid)) return false;
	}
	return talkedNpc(npcid);
}
bool SGE_Player_Scene2WorldProxy::findDynamicNpcOK(ProtocolReader* __r__)
{
	int32_t npcid=0;
	bool hasnpc=false;
	// deserialize npcid
	{
		if(!__r__->readType(npcid)) return false;
	}
	// deserialize hasnpc
	{
		if(!__r__->readType(hasnpc)) return false;
	}
	return findDynamicNpcOK(npcid,hasnpc);
}
bool SGE_Player_Scene2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!joinScene(r)) return false;
		}
		break;
		case 1:
		{
			if(!move2(r)) return false;
		}
		break;
		case 2:
		{
			if(!cantMove(r)) return false;
		}
		break;
		case 3:
		{
			if(!transfor2(r)) return false;
		}
		break;
		case 4:
		{
			if(!autoBattleResult(r)) return false;
		}
		break;
		case 5:
		{
			if(!zoneJoinBattle(r)) return false;
		}
		break;
		case 6:
		{
			if(!playerAddNpc(r)) return false;
		}
		break;
		case 7:
		{
			if(!playerDelNpc(r)) return false;
		}
		break;
		case 8:
		{
			if(!talkedNpc(r)) return false;
		}
		break;
		case 9:
		{
			if(!findDynamicNpcOK(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_Player_World2SceneStub::initScenePlayer(const SGE_ScenePlayerInfo& info)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize info
	{
		info.serialize(w);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::scenePlayerUpLevel(int32_t level)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize level
	{
		w->writeType(level);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::scenePlayerAddCurrentQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::scenePlayerDelCurrentQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::scenePlayerAddAcceptableQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::scenePlayerDelAcceptableQuest(int32_t questId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize questId
	{
		w->writeType(questId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::openScene(int32_t sceneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::joinBattle()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::finishBattle()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::transforScene(int32_t sceneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::transforSceneByEntry(int32_t sceneId,int32_t entryId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 10;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	// serialize entryId
	{
		w->writeType(entryId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::backHomeScene()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 11;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::sceneLoaded()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 12;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::move(const COM_FPosition& pos)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 13;
	w->writeType(pid);
	// serialize pos
	{
		pos.serialize(w);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::moveToNpc(int32_t npcid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 14;
	w->writeType(pid);
	// serialize npcid
	{
		w->writeType(npcid);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::moveToNpc2(NpcType type)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 15;
	w->writeType(pid);
	// serialize type
	{
		uint8_t __e__ = (uint8_t)type;
		w->writeType(__e__);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::moveToZone(int32_t sceneId,int32_t zoneId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 16;
	w->writeType(pid);
	// serialize sceneId
	{
		w->writeType(sceneId);
	}
	// serialize zoneId
	{
		w->writeType(zoneId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::autoBattle()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 17;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::stopMove()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 18;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::addFollow(int32_t scenePlayerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 19;
	w->writeType(pid);
	// serialize scenePlayerId
	{
		w->writeType(scenePlayerId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::delFollow(int32_t scenePlayerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 20;
	w->writeType(pid);
	// serialize scenePlayerId
	{
		w->writeType(scenePlayerId);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::delFollows()
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 21;
	w->writeType(pid);
	methodEnd();
}
void SGE_Player_World2SceneStub::addFollows(const std::vector< int32_t >& scenePlayers)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 22;
	w->writeType(pid);
	// serialize scenePlayers
	{
		uint32_t __len__ = (uint32_t)scenePlayers.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			w->writeType(scenePlayers[i]);
		}
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::setEntryFlag(int32_t scenePlayerId,bool isFlag)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 23;
	w->writeType(pid);
	// serialize scenePlayerId
	{
		w->writeType(scenePlayerId);
	}
	// serialize isFlag
	{
		w->writeType(isFlag);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::addNpc(int32_t npcid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 24;
	w->writeType(pid);
	// serialize npcid
	{
		w->writeType(npcid);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::delNpc(int32_t npcid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 25;
	w->writeType(pid);
	// serialize npcid
	{
		w->writeType(npcid);
	}
	methodEnd();
}
void SGE_Player_World2SceneStub::findDynamicNpc(int32_t npcId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 26;
	w->writeType(pid);
	// serialize npcId
	{
		w->writeType(npcId);
	}
	methodEnd();
}
bool SGE_Player_World2SceneProxy::initScenePlayer(ProtocolReader* __r__)
{
	SGE_ScenePlayerInfo info;
	// deserialize info
	{
		if(!info.deserialize(__r__)) return false;
	}
	return initScenePlayer(info);
}
bool SGE_Player_World2SceneProxy::scenePlayerUpLevel(ProtocolReader* __r__)
{
	int32_t level=0;
	// deserialize level
	{
		if(!__r__->readType(level)) return false;
	}
	return scenePlayerUpLevel(level);
}
bool SGE_Player_World2SceneProxy::scenePlayerAddCurrentQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return scenePlayerAddCurrentQuest(questId);
}
bool SGE_Player_World2SceneProxy::scenePlayerDelCurrentQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return scenePlayerDelCurrentQuest(questId);
}
bool SGE_Player_World2SceneProxy::scenePlayerAddAcceptableQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return scenePlayerAddAcceptableQuest(questId);
}
bool SGE_Player_World2SceneProxy::scenePlayerDelAcceptableQuest(ProtocolReader* __r__)
{
	int32_t questId=0;
	// deserialize questId
	{
		if(!__r__->readType(questId)) return false;
	}
	return scenePlayerDelAcceptableQuest(questId);
}
bool SGE_Player_World2SceneProxy::openScene(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	return openScene(sceneId);
}
bool SGE_Player_World2SceneProxy::joinBattle(ProtocolReader* __r__)
{
	return joinBattle();
}
bool SGE_Player_World2SceneProxy::finishBattle(ProtocolReader* __r__)
{
	return finishBattle();
}
bool SGE_Player_World2SceneProxy::transforScene(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	return transforScene(sceneId);
}
bool SGE_Player_World2SceneProxy::transforSceneByEntry(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	int32_t entryId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	// deserialize entryId
	{
		if(!__r__->readType(entryId)) return false;
	}
	return transforSceneByEntry(sceneId,entryId);
}
bool SGE_Player_World2SceneProxy::backHomeScene(ProtocolReader* __r__)
{
	return backHomeScene();
}
bool SGE_Player_World2SceneProxy::sceneLoaded(ProtocolReader* __r__)
{
	return sceneLoaded();
}
bool SGE_Player_World2SceneProxy::move(ProtocolReader* __r__)
{
	COM_FPosition pos;
	// deserialize pos
	{
		if(!pos.deserialize(__r__)) return false;
	}
	return move(pos);
}
bool SGE_Player_World2SceneProxy::moveToNpc(ProtocolReader* __r__)
{
	int32_t npcid=0;
	// deserialize npcid
	{
		if(!__r__->readType(npcid)) return false;
	}
	return moveToNpc(npcid);
}
bool SGE_Player_World2SceneProxy::moveToNpc2(ProtocolReader* __r__)
{
	NpcType type=(NpcType)(0);
	// deserialize type
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 11) return false;
		type = (NpcType)__e__;
	}
	return moveToNpc2(type);
}
bool SGE_Player_World2SceneProxy::moveToZone(ProtocolReader* __r__)
{
	int32_t sceneId=0;
	int32_t zoneId=0;
	// deserialize sceneId
	{
		if(!__r__->readType(sceneId)) return false;
	}
	// deserialize zoneId
	{
		if(!__r__->readType(zoneId)) return false;
	}
	return moveToZone(sceneId,zoneId);
}
bool SGE_Player_World2SceneProxy::autoBattle(ProtocolReader* __r__)
{
	return autoBattle();
}
bool SGE_Player_World2SceneProxy::stopMove(ProtocolReader* __r__)
{
	return stopMove();
}
bool SGE_Player_World2SceneProxy::addFollow(ProtocolReader* __r__)
{
	int32_t scenePlayerId=0;
	// deserialize scenePlayerId
	{
		if(!__r__->readType(scenePlayerId)) return false;
	}
	return addFollow(scenePlayerId);
}
bool SGE_Player_World2SceneProxy::delFollow(ProtocolReader* __r__)
{
	int32_t scenePlayerId=0;
	// deserialize scenePlayerId
	{
		if(!__r__->readType(scenePlayerId)) return false;
	}
	return delFollow(scenePlayerId);
}
bool SGE_Player_World2SceneProxy::delFollows(ProtocolReader* __r__)
{
	return delFollows();
}
bool SGE_Player_World2SceneProxy::addFollows(ProtocolReader* __r__)
{
	std::vector< int32_t > scenePlayers;
	// deserialize scenePlayers
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		scenePlayers.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!__r__->readType(scenePlayers[i])) return false;
		}
	}
	return addFollows(scenePlayers);
}
bool SGE_Player_World2SceneProxy::setEntryFlag(ProtocolReader* __r__)
{
	int32_t scenePlayerId=0;
	bool isFlag=false;
	// deserialize scenePlayerId
	{
		if(!__r__->readType(scenePlayerId)) return false;
	}
	// deserialize isFlag
	{
		if(!__r__->readType(isFlag)) return false;
	}
	return setEntryFlag(scenePlayerId,isFlag);
}
bool SGE_Player_World2SceneProxy::addNpc(ProtocolReader* __r__)
{
	int32_t npcid=0;
	// deserialize npcid
	{
		if(!__r__->readType(npcid)) return false;
	}
	return addNpc(npcid);
}
bool SGE_Player_World2SceneProxy::delNpc(ProtocolReader* __r__)
{
	int32_t npcid=0;
	// deserialize npcid
	{
		if(!__r__->readType(npcid)) return false;
	}
	return delNpc(npcid);
}
bool SGE_Player_World2SceneProxy::findDynamicNpc(ProtocolReader* __r__)
{
	int32_t npcId=0;
	// deserialize npcId
	{
		if(!__r__->readType(npcId)) return false;
	}
	return findDynamicNpc(npcId);
}
bool SGE_Player_World2SceneProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!initScenePlayer(r)) return false;
		}
		break;
		case 1:
		{
			if(!scenePlayerUpLevel(r)) return false;
		}
		break;
		case 2:
		{
			if(!scenePlayerAddCurrentQuest(r)) return false;
		}
		break;
		case 3:
		{
			if(!scenePlayerDelCurrentQuest(r)) return false;
		}
		break;
		case 4:
		{
			if(!scenePlayerAddAcceptableQuest(r)) return false;
		}
		break;
		case 5:
		{
			if(!scenePlayerDelAcceptableQuest(r)) return false;
		}
		break;
		case 6:
		{
			if(!openScene(r)) return false;
		}
		break;
		case 7:
		{
			if(!joinBattle(r)) return false;
		}
		break;
		case 8:
		{
			if(!finishBattle(r)) return false;
		}
		break;
		case 9:
		{
			if(!transforScene(r)) return false;
		}
		break;
		case 10:
		{
			if(!transforSceneByEntry(r)) return false;
		}
		break;
		case 11:
		{
			if(!backHomeScene(r)) return false;
		}
		break;
		case 12:
		{
			if(!sceneLoaded(r)) return false;
		}
		break;
		case 13:
		{
			if(!move(r)) return false;
		}
		break;
		case 14:
		{
			if(!moveToNpc(r)) return false;
		}
		break;
		case 15:
		{
			if(!moveToNpc2(r)) return false;
		}
		break;
		case 16:
		{
			if(!moveToZone(r)) return false;
		}
		break;
		case 17:
		{
			if(!autoBattle(r)) return false;
		}
		break;
		case 18:
		{
			if(!stopMove(r)) return false;
		}
		break;
		case 19:
		{
			if(!addFollow(r)) return false;
		}
		break;
		case 20:
		{
			if(!delFollow(r)) return false;
		}
		break;
		case 21:
		{
			if(!delFollows(r)) return false;
		}
		break;
		case 22:
		{
			if(!addFollows(r)) return false;
		}
		break;
		case 23:
		{
			if(!setEntryFlag(r)) return false;
		}
		break;
		case 24:
		{
			if(!addNpc(r)) return false;
		}
		break;
		case 25:
		{
			if(!delNpc(r)) return false;
		}
		break;
		case 26:
		{
			if(!findDynamicNpc(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
bool SGE_World2GMTProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_GMT2WorldStub::addExp(uint32_t playerId,uint32_t exp)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize exp
	{
		w->writeType(exp);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::addMoney(uint32_t playerId,int32_t money)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize money
	{
		w->writeType(money);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::addDiamond(uint32_t playerId,int32_t diamond)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize diamond
	{
		w->writeType(diamond);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::openGM(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::closeGM(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::noTalkPlayer(uint32_t playerId,uint32_t time)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize time
	{
		w->writeType(time);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::sealPlayer(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::kickPlayer(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 7;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::openTalkPlayer(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 8;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::unsealPlayer(uint32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 9;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::sendMailAllOnline(const COM_Mail& mail,int32_t lowLevel,int32_t highLevel,int64_t lowRegTime,int64_t highRegTime)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 10;
	w->writeType(pid);
	// serialize mail
	{
		mail.serialize(w);
	}
	// serialize lowLevel
	{
		w->writeType(lowLevel);
	}
	// serialize highLevel
	{
		w->writeType(highLevel);
	}
	// serialize lowRegTime
	{
		w->writeType(lowRegTime);
	}
	// serialize highRegTime
	{
		w->writeType(highRegTime);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::gmtNotice(NoticeSendType bType,const std::string& note,uint64_t thetime,int64_t itvtime)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 11;
	w->writeType(pid);
	// serialize bType
	{
		uint8_t __e__ = (uint8_t)bType;
		w->writeType(__e__);
	}
	// serialize note
	{
		w->writeType(note);
	}
	// serialize thetime
	{
		w->writeType(thetime);
	}
	// serialize itvtime
	{
		w->writeType(itvtime);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setChargeTotal(const COM_ADChargeTotal& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 12;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setChargeEvery(const COM_ADChargeEvery& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 13;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setDiscountStore(const COM_ADDiscountStore& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 14;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setLoginTotal(const COM_ADLoginTotal& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 15;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setHotRole(const COM_ADHotRole& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 16;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setEmployeeActivity(const COM_ADEmployeeTotal& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 17;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setMinGiftBagActivity(const COM_ADGiftBag& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 18;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setZhuanpanActivity(const COM_ZhuanpanData& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 19;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::setIntegralshop(const COM_IntegralData& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 20;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::makeOrder(uint32_t playerId,const SGE_GmtOrder& order)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 21;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize order
	{
		order.serialize(w);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::doScript(const std::string& script)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 22;
	w->writeType(pid);
	// serialize script
	{
		w->writeType(script);
	}
	methodEnd();
}
void SGE_GMT2WorldStub::playerDoScript(uint32_t playerId,const std::string& script)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 23;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize script
	{
		w->writeType(script);
	}
	methodEnd();
}
bool SGE_GMT2WorldProxy::addExp(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	uint32_t exp=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize exp
	{
		if(!__r__->readType(exp)) return false;
	}
	return addExp(playerId,exp);
}
bool SGE_GMT2WorldProxy::addMoney(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	int32_t money=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize money
	{
		if(!__r__->readType(money)) return false;
	}
	return addMoney(playerId,money);
}
bool SGE_GMT2WorldProxy::addDiamond(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	int32_t diamond=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize diamond
	{
		if(!__r__->readType(diamond)) return false;
	}
	return addDiamond(playerId,diamond);
}
bool SGE_GMT2WorldProxy::openGM(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return openGM(playerId);
}
bool SGE_GMT2WorldProxy::closeGM(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return closeGM(playerId);
}
bool SGE_GMT2WorldProxy::noTalkPlayer(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	uint32_t time=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize time
	{
		if(!__r__->readType(time)) return false;
	}
	return noTalkPlayer(playerId,time);
}
bool SGE_GMT2WorldProxy::sealPlayer(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return sealPlayer(playerId);
}
bool SGE_GMT2WorldProxy::kickPlayer(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return kickPlayer(playerId);
}
bool SGE_GMT2WorldProxy::openTalkPlayer(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return openTalkPlayer(playerId);
}
bool SGE_GMT2WorldProxy::unsealPlayer(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return unsealPlayer(playerId);
}
bool SGE_GMT2WorldProxy::sendMailAllOnline(ProtocolReader* __r__)
{
	COM_Mail mail;
	int32_t lowLevel=0;
	int32_t highLevel=0;
	int64_t lowRegTime=0;
	int64_t highRegTime=0;
	// deserialize mail
	{
		if(!mail.deserialize(__r__)) return false;
	}
	// deserialize lowLevel
	{
		if(!__r__->readType(lowLevel)) return false;
	}
	// deserialize highLevel
	{
		if(!__r__->readType(highLevel)) return false;
	}
	// deserialize lowRegTime
	{
		if(!__r__->readType(lowRegTime)) return false;
	}
	// deserialize highRegTime
	{
		if(!__r__->readType(highRegTime)) return false;
	}
	return sendMailAllOnline(mail,lowLevel,highLevel,lowRegTime,highRegTime);
}
bool SGE_GMT2WorldProxy::gmtNotice(ProtocolReader* __r__)
{
	NoticeSendType bType=(NoticeSendType)(0);
	std::string note;
	uint64_t thetime=0;
	int64_t itvtime=0;
	// deserialize bType
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 3) return false;
		bType = (NoticeSendType)__e__;
	}
	// deserialize note
	{
		if(!__r__->readType(note, 65535)) return false;
	}
	// deserialize thetime
	{
		if(!__r__->readType(thetime)) return false;
	}
	// deserialize itvtime
	{
		if(!__r__->readType(itvtime)) return false;
	}
	return gmtNotice(bType,note,thetime,itvtime);
}
bool SGE_GMT2WorldProxy::setChargeTotal(ProtocolReader* __r__)
{
	COM_ADChargeTotal data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setChargeTotal(data);
}
bool SGE_GMT2WorldProxy::setChargeEvery(ProtocolReader* __r__)
{
	COM_ADChargeEvery data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setChargeEvery(data);
}
bool SGE_GMT2WorldProxy::setDiscountStore(ProtocolReader* __r__)
{
	COM_ADDiscountStore data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setDiscountStore(data);
}
bool SGE_GMT2WorldProxy::setLoginTotal(ProtocolReader* __r__)
{
	COM_ADLoginTotal data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setLoginTotal(data);
}
bool SGE_GMT2WorldProxy::setHotRole(ProtocolReader* __r__)
{
	COM_ADHotRole data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setHotRole(data);
}
bool SGE_GMT2WorldProxy::setEmployeeActivity(ProtocolReader* __r__)
{
	COM_ADEmployeeTotal data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setEmployeeActivity(data);
}
bool SGE_GMT2WorldProxy::setMinGiftBagActivity(ProtocolReader* __r__)
{
	COM_ADGiftBag data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setMinGiftBagActivity(data);
}
bool SGE_GMT2WorldProxy::setZhuanpanActivity(ProtocolReader* __r__)
{
	COM_ZhuanpanData data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setZhuanpanActivity(data);
}
bool SGE_GMT2WorldProxy::setIntegralshop(ProtocolReader* __r__)
{
	COM_IntegralData data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return setIntegralshop(data);
}
bool SGE_GMT2WorldProxy::makeOrder(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	SGE_GmtOrder order;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize order
	{
		if(!order.deserialize(__r__)) return false;
	}
	return makeOrder(playerId,order);
}
bool SGE_GMT2WorldProxy::doScript(ProtocolReader* __r__)
{
	std::string script;
	// deserialize script
	{
		if(!__r__->readType(script, 65535)) return false;
	}
	return doScript(script);
}
bool SGE_GMT2WorldProxy::playerDoScript(ProtocolReader* __r__)
{
	uint32_t playerId=0;
	std::string script;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize script
	{
		if(!__r__->readType(script, 65535)) return false;
	}
	return playerDoScript(playerId,script);
}
bool SGE_GMT2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!addExp(r)) return false;
		}
		break;
		case 1:
		{
			if(!addMoney(r)) return false;
		}
		break;
		case 2:
		{
			if(!addDiamond(r)) return false;
		}
		break;
		case 3:
		{
			if(!openGM(r)) return false;
		}
		break;
		case 4:
		{
			if(!closeGM(r)) return false;
		}
		break;
		case 5:
		{
			if(!noTalkPlayer(r)) return false;
		}
		break;
		case 6:
		{
			if(!sealPlayer(r)) return false;
		}
		break;
		case 7:
		{
			if(!kickPlayer(r)) return false;
		}
		break;
		case 8:
		{
			if(!openTalkPlayer(r)) return false;
		}
		break;
		case 9:
		{
			if(!unsealPlayer(r)) return false;
		}
		break;
		case 10:
		{
			if(!sendMailAllOnline(r)) return false;
		}
		break;
		case 11:
		{
			if(!gmtNotice(r)) return false;
		}
		break;
		case 12:
		{
			if(!setChargeTotal(r)) return false;
		}
		break;
		case 13:
		{
			if(!setChargeEvery(r)) return false;
		}
		break;
		case 14:
		{
			if(!setDiscountStore(r)) return false;
		}
		break;
		case 15:
		{
			if(!setLoginTotal(r)) return false;
		}
		break;
		case 16:
		{
			if(!setHotRole(r)) return false;
		}
		break;
		case 17:
		{
			if(!setEmployeeActivity(r)) return false;
		}
		break;
		case 18:
		{
			if(!setMinGiftBagActivity(r)) return false;
		}
		break;
		case 19:
		{
			if(!setZhuanpanActivity(r)) return false;
		}
		break;
		case 20:
		{
			if(!setIntegralshop(r)) return false;
		}
		break;
		case 21:
		{
			if(!makeOrder(r)) return false;
		}
		break;
		case 22:
		{
			if(!doScript(r)) return false;
		}
		break;
		case 23:
		{
			if(!playerDoScript(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_World2MallStub::fetchSell(int32_t playerid,const COM_SearchContext& context)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize context
	{
		context.serialize(w);
	}
	methodEnd();
}
void SGE_World2MallStub::fetchMySell(int32_t playerid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	methodEnd();
}
void SGE_World2MallStub::fetchSelledItem(int32_t playerId)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	methodEnd();
}
void SGE_World2MallStub::sell(const COM_SellItem& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void SGE_World2MallStub::unSell(int32_t playerid,int32_t sellid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize sellid
	{
		w->writeType(sellid);
	}
	methodEnd();
}
void SGE_World2MallStub::buy(const SGE_BuyContent& content)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize content
	{
		content.serialize(w);
	}
	methodEnd();
}
void SGE_World2MallStub::insertSelledItem(const COM_SelledItem& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
bool SGE_World2MallProxy::fetchSell(ProtocolReader* __r__)
{
	int32_t playerid=0;
	COM_SearchContext context;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize context
	{
		if(!context.deserialize(__r__)) return false;
	}
	return fetchSell(playerid,context);
}
bool SGE_World2MallProxy::fetchMySell(ProtocolReader* __r__)
{
	int32_t playerid=0;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	return fetchMySell(playerid);
}
bool SGE_World2MallProxy::fetchSelledItem(ProtocolReader* __r__)
{
	int32_t playerId=0;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	return fetchSelledItem(playerId);
}
bool SGE_World2MallProxy::sell(ProtocolReader* __r__)
{
	COM_SellItem item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return sell(item);
}
bool SGE_World2MallProxy::unSell(ProtocolReader* __r__)
{
	int32_t playerid=0;
	int32_t sellid=0;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize sellid
	{
		if(!__r__->readType(sellid)) return false;
	}
	return unSell(playerid,sellid);
}
bool SGE_World2MallProxy::buy(ProtocolReader* __r__)
{
	SGE_BuyContent content;
	// deserialize content
	{
		if(!content.deserialize(__r__)) return false;
	}
	return buy(content);
}
bool SGE_World2MallProxy::insertSelledItem(ProtocolReader* __r__)
{
	COM_SelledItem item;
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return insertSelledItem(item);
}
bool SGE_World2MallProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!fetchSell(r)) return false;
		}
		break;
		case 1:
		{
			if(!fetchMySell(r)) return false;
		}
		break;
		case 2:
		{
			if(!fetchSelledItem(r)) return false;
		}
		break;
		case 3:
		{
			if(!sell(r)) return false;
		}
		break;
		case 4:
		{
			if(!unSell(r)) return false;
		}
		break;
		case 5:
		{
			if(!buy(r)) return false;
		}
		break;
		case 6:
		{
			if(!insertSelledItem(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_Mall2WorldStub::fetchSellOk(int32_t playerid,const std::vector< COM_SellItem >& items,int32_t totalSize)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	// serialize totalSize
	{
		w->writeType(totalSize);
	}
	methodEnd();
}
void SGE_Mall2WorldStub::fetchMySellOk(int32_t playerid,const std::vector< COM_SellItem >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_Mall2WorldStub::fetchSelledItemOk(int32_t playerId,const std::vector< COM_SelledItem >& items)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize playerId
	{
		w->writeType(playerId);
	}
	// serialize items
	{
		uint32_t __len__ = (uint32_t)items.size();
		w->writeDynSize(__len__); 
		for(uint32_t i = 0; i < __len__; i++)
		{
			items[i].serialize(w);
		}
	}
	methodEnd();
}
void SGE_Mall2WorldStub::sellOk(int32_t playerid,const COM_SellItem& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void SGE_Mall2WorldStub::unSellOk(int32_t playerid,int32_t sellid)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize sellid
	{
		w->writeType(sellid);
	}
	methodEnd();
}
void SGE_Mall2WorldStub::buyOk(int32_t playerid,const COM_SellItem& item)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize item
	{
		item.serialize(w);
	}
	methodEnd();
}
void SGE_Mall2WorldStub::buyFail(int32_t playerid,ErrorNo errorno)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize playerid
	{
		w->writeType(playerid);
	}
	// serialize errorno
	{
		uint8_t __e__ = (uint8_t)errorno;
		w->writeType(__e__);
	}
	methodEnd();
}
bool SGE_Mall2WorldProxy::fetchSellOk(ProtocolReader* __r__)
{
	int32_t playerid=0;
	std::vector< COM_SellItem > items;
	int32_t totalSize=0;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	// deserialize totalSize
	{
		if(!__r__->readType(totalSize)) return false;
	}
	return fetchSellOk(playerid,items,totalSize);
}
bool SGE_Mall2WorldProxy::fetchMySellOk(ProtocolReader* __r__)
{
	int32_t playerid=0;
	std::vector< COM_SellItem > items;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return fetchMySellOk(playerid,items);
}
bool SGE_Mall2WorldProxy::fetchSelledItemOk(ProtocolReader* __r__)
{
	int32_t playerId=0;
	std::vector< COM_SelledItem > items;
	// deserialize playerId
	{
		if(!__r__->readType(playerId)) return false;
	}
	// deserialize items
	{
		uint32_t __len__;
		if(!__r__->readDynSize(__len__) || __len__ > 65535) return false;
		items.resize(__len__);
		for(uint32_t i = 0; i < __len__; i++)
		{
			if(!items[i].deserialize(__r__)) return false;
		}
	}
	return fetchSelledItemOk(playerId,items);
}
bool SGE_Mall2WorldProxy::sellOk(ProtocolReader* __r__)
{
	int32_t playerid=0;
	COM_SellItem item;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return sellOk(playerid,item);
}
bool SGE_Mall2WorldProxy::unSellOk(ProtocolReader* __r__)
{
	int32_t playerid=0;
	int32_t sellid=0;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize sellid
	{
		if(!__r__->readType(sellid)) return false;
	}
	return unSellOk(playerid,sellid);
}
bool SGE_Mall2WorldProxy::buyOk(ProtocolReader* __r__)
{
	int32_t playerid=0;
	COM_SellItem item;
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize item
	{
		if(!item.deserialize(__r__)) return false;
	}
	return buyOk(playerid,item);
}
bool SGE_Mall2WorldProxy::buyFail(ProtocolReader* __r__)
{
	int32_t playerid=0;
	ErrorNo errorno=(ErrorNo)(0);
	// deserialize playerid
	{
		if(!__r__->readType(playerid)) return false;
	}
	// deserialize errorno
	{
		uint8_t __e__ = 0;
		if(!__r__->readType(__e__) || __e__ >= 158) return false;
		errorno = (ErrorNo)__e__;
	}
	return buyFail(playerid,errorno);
}
bool SGE_Mall2WorldProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!fetchSellOk(r)) return false;
		}
		break;
		case 1:
		{
			if(!fetchMySellOk(r)) return false;
		}
		break;
		case 2:
		{
			if(!fetchSelledItemOk(r)) return false;
		}
		break;
		case 3:
		{
			if(!sellOk(r)) return false;
		}
		break;
		case 4:
		{
			if(!unSellOk(r)) return false;
		}
		break;
		case 5:
		{
			if(!buyOk(r)) return false;
		}
		break;
		case 6:
		{
			if(!buyFail(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void BacklogStub::log(const std::string& key,const std::string& msg,const std::string& stack,const std::string& version)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize key
	{
		w->writeType(key);
	}
	// serialize msg
	{
		w->writeType(msg);
	}
	// serialize stack
	{
		w->writeType(stack);
	}
	// serialize version
	{
		w->writeType(version);
	}
	methodEnd();
}
bool BacklogProxy::log(ProtocolReader* __r__)
{
	std::string key;
	std::string msg;
	std::string stack;
	std::string version;
	// deserialize key
	{
		if(!__r__->readType(key, 65535)) return false;
	}
	// deserialize msg
	{
		if(!__r__->readType(msg, 65535)) return false;
	}
	// deserialize stack
	{
		if(!__r__->readType(stack, 65535)) return false;
	}
	// deserialize version
	{
		if(!__r__->readType(version, 65535)) return false;
	}
	return log(key,msg,stack,version);
}
bool BacklogProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!log(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
//=============================================================
void SGE_LogStub::account(const SGE_Account& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 0;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_LogStub::login(const SGE_Login& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 1;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_LogStub::order(const SGE_Order& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 2;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_LogStub::role(const SGE_LogRole& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 3;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_LogStub::playersay(uint32_t senderId,const std::string& senderName,const COM_Chat& chat)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 4;
	w->writeType(pid);
	// serialize senderId
	{
		w->writeType(senderId);
	}
	// serialize senderName
	{
		w->writeType(senderName);
	}
	// serialize chat
	{
		chat.serialize(w);
	}
	methodEnd();
}
void SGE_LogStub::playerTrack(const SGE_LogProduceTrack& data)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 5;
	w->writeType(pid);
	// serialize data
	{
		data.serialize(w);
	}
	methodEnd();
}
void SGE_LogStub::playerUIBehavior(const SGE_LogUIBehavior& core)
{
	ProtocolWriter* w = methodBegin();
	if(!w) return;
	uint16_t pid = 6;
	w->writeType(pid);
	// serialize core
	{
		core.serialize(w);
	}
	methodEnd();
}
bool SGE_LogProxy::account(ProtocolReader* __r__)
{
	SGE_Account data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return account(data);
}
bool SGE_LogProxy::login(ProtocolReader* __r__)
{
	SGE_Login data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return login(data);
}
bool SGE_LogProxy::order(ProtocolReader* __r__)
{
	SGE_Order data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return order(data);
}
bool SGE_LogProxy::role(ProtocolReader* __r__)
{
	SGE_LogRole data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return role(data);
}
bool SGE_LogProxy::playersay(ProtocolReader* __r__)
{
	uint32_t senderId=0;
	std::string senderName;
	COM_Chat chat;
	// deserialize senderId
	{
		if(!__r__->readType(senderId)) return false;
	}
	// deserialize senderName
	{
		if(!__r__->readType(senderName, 65535)) return false;
	}
	// deserialize chat
	{
		if(!chat.deserialize(__r__)) return false;
	}
	return playersay(senderId,senderName,chat);
}
bool SGE_LogProxy::playerTrack(ProtocolReader* __r__)
{
	SGE_LogProduceTrack data;
	// deserialize data
	{
		if(!data.deserialize(__r__)) return false;
	}
	return playerTrack(data);
}
bool SGE_LogProxy::playerUIBehavior(ProtocolReader* __r__)
{
	SGE_LogUIBehavior core;
	// deserialize core
	{
		if(!core.deserialize(__r__)) return false;
	}
	return playerUIBehavior(core);
}
bool SGE_LogProxy::dispatch(ProtocolReader* r)
{
	uint16_t pid;
	if(!r->readType(pid)) return false;
	switch(pid)
	{
		case 0:
		{
			if(!account(r)) return false;
		}
		break;
		case 1:
		{
			if(!login(r)) return false;
		}
		break;
		case 2:
		{
			if(!order(r)) return false;
		}
		break;
		case 3:
		{
			if(!role(r)) return false;
		}
		break;
		case 4:
		{
			if(!playersay(r)) return false;
		}
		break;
		case 5:
		{
			if(!playerTrack(r)) return false;
		}
		break;
		case 6:
		{
			if(!playerUIBehavior(r)) return false;
		}
		break;
		default: return false;
	}
	return true;
}
