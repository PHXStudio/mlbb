virtual bool fetchSell(int32_t playerid, COM_SearchContext& context);
virtual bool fetchMySell(int32_t playerid);
virtual bool fetchSelledItem(int32_t playerId);
virtual bool sell(COM_SellItem& item);
virtual bool unSell(int32_t playerid, int32_t sellid);
virtual bool buy(SGE_BuyContent& content);
virtual bool insertSelledItem(COM_SelledItem& item);
