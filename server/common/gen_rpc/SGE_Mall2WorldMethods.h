virtual bool fetchSellOk(int32_t playerid, std::vector< COM_SellItem >& items, int32_t totalSize);
virtual bool fetchMySellOk(int32_t playerid, std::vector< COM_SellItem >& items);
virtual bool fetchSelledItemOk(int32_t playerId, std::vector< COM_SelledItem >& items);
virtual bool sellOk(int32_t playerid, COM_SellItem& item);
virtual bool unSellOk(int32_t playerid, int32_t sellid);
virtual bool buyOk(int32_t playerid, COM_SellItem& item);
virtual bool buyFail(int32_t playerid, ErrorNo errorno);
