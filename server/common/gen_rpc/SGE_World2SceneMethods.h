virtual bool initDynamicNpcs(NpcType type, int32_t count);
virtual bool refreshDynamicNpcs(NpcType type, int32_t count);
virtual bool finiDynamicNpcs(NpcType type);
virtual bool addDynamicNpcs(int32_t sceneId, std::vector< int32_t >& npcs);
virtual bool delDynamicNpc(int32_t npcId);
virtual bool delDynamicNpc2(int32_t sceneId, int32_t npcId);
virtual bool openSceneCopy(int32_t instId);
virtual bool closeSceneCopy(int32_t instId);
