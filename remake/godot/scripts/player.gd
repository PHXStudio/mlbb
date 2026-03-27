extends Node

var session_key: String

#当前使用的角色数据,这个角色数据是从服务器enterGame 获得
var current: COM_PlayerInst

var players: Array[COM_SimpleInformation]

# Baby data
var babies: Array[COM_BabyInst] = []
var baby_storage: Array[COM_BabyInst] = []
var baby_storage_grid_num: int = 0

# Employee data
var employess: Array[COM_EmployeeInst] = []
var battle_group: COM_BattleEmp = null

# Item data
var bag_items: Array[COM_Item] = []
var item_storage: Array[COM_Item] = []
var item_storage_grid_num: int = 0
var player_equips: Array[COM_Item] = []  # 6 equipment slots

# Achievement data
var achievements: Array[COM_Achievement] = []

# NPC data
var npc_list: Array[int] = []

# Quest data
var quest_list: Array[COM_QuestInst] = []
var completed_quests: Array[int] = []

# Gather data
var gathers: Array[COM_Gather] = []

# Compound data
var compounds: Array[int] = []

# Guild data
var guild: COM_Guild = null
var guild_members: Array[COM_GuildMember] = []

# Mail data
var mails: Array[COM_Mail] = []

# Other data
var guide_mask: int = 0
var titles: Array[int] = []
var states: Array[COM_State] = []
