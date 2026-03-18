#include "proto_godot.h"

void SGE_OrderInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_productId_"), &SGE_OrderInfo::get_productId_);
	ClassDB::bind_method(D_METHOD("set_productId_", "p_val"), &SGE_OrderInfo::set_productId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "productId_"), "set_productId_", "get_productId_");
	ClassDB::bind_method(D_METHOD("get_productCount_"), &SGE_OrderInfo::get_productCount_);
	ClassDB::bind_method(D_METHOD("set_productCount_", "p_val"), &SGE_OrderInfo::set_productCount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "productCount_"), "set_productCount_", "get_productCount_");
	ClassDB::bind_method(D_METHOD("get_amount_"), &SGE_OrderInfo::get_amount_);
	ClassDB::bind_method(D_METHOD("set_amount_", "p_val"), &SGE_OrderInfo::set_amount_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amount_"), "set_amount_", "get_amount_");
	ClassDB::bind_method(D_METHOD("get_orderId_"), &SGE_OrderInfo::get_orderId_);
	ClassDB::bind_method(D_METHOD("set_orderId_", "p_val"), &SGE_OrderInfo::set_orderId_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "orderId_"), "set_orderId_", "get_orderId_");
	ClassDB::bind_method(D_METHOD("get_payTime_"), &SGE_OrderInfo::get_payTime_);
	ClassDB::bind_method(D_METHOD("set_payTime_", "p_val"), &SGE_OrderInfo::set_payTime_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "payTime_"), "set_payTime_", "get_payTime_");
}

void SGE_OrderInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((productId_==0)?false:true);
	__fm__.writeBit((productCount_==0)?false:true);
	__fm__.writeBit((amount_==0.0)?false:true);
	__fm__.writeBit(orderId_.length()?true:false);
	__fm__.writeBit(payTime_.length()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(productId_);
	}
	if(__fm__.readBit()){
		s->writeType(productCount_);
	}
	if(__fm__.readBit()){
		s->writeType(amount_);
	}
	if(__fm__.readBit()){
		s->writeType(orderId_);
	}
	if(__fm__.readBit()){
		s->writeType(payTime_);
	}
}

bool SGE_OrderInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(productId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(productCount_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(amount_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(orderId_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(payTime_, 65535)) return false;
	}
	return true;
}

void COM_ADLoginTotalContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_totalDays_"), &COM_ADLoginTotalContent::get_totalDays_);
	ClassDB::bind_method(D_METHOD("set_totalDays_", "p_val"), &COM_ADLoginTotalContent::set_totalDays_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "totalDays_"), "set_totalDays_", "get_totalDays_");
	ClassDB::bind_method(D_METHOD("get_itemIds_"), &COM_ADLoginTotalContent::get_itemIds_);
	ClassDB::bind_method(D_METHOD("set_itemIds_", "p_val"), &COM_ADLoginTotalContent::set_itemIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemIds_"), "set_itemIds_", "get_itemIds_");
	ClassDB::bind_method(D_METHOD("get_itemStacks_"), &COM_ADLoginTotalContent::get_itemStacks_);
	ClassDB::bind_method(D_METHOD("set_itemStacks_", "p_val"), &COM_ADLoginTotalContent::set_itemStacks_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemStacks_"), "set_itemStacks_", "get_itemStacks_");
	ClassDB::bind_method(D_METHOD("get_status_"), &COM_ADLoginTotalContent::get_status_);
	ClassDB::bind_method(D_METHOD("set_status_", "p_val"), &COM_ADLoginTotalContent::set_status_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "status_"), "set_status_", "get_status_");
}

void COM_ADLoginTotalContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((totalDays_==0)?false:true);
	__fm__.writeBit(itemIds_.size()?true:false);
	__fm__.writeBit(itemStacks_.size()?true:false);
	__fm__.writeBit((status_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(totalDays_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemIds_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemStacks_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemStacks_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(status_);
	}
}

bool COM_ADLoginTotalContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(totalDays_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemIds_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemStacks_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemStacks_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(status_)) return false;
	}
	return true;
}

void COM_ADLoginTotal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_loginDays_"), &COM_ADLoginTotal::get_loginDays_);
	ClassDB::bind_method(D_METHOD("set_loginDays_", "p_val"), &COM_ADLoginTotal::set_loginDays_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "loginDays_"), "set_loginDays_", "get_loginDays_");
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADLoginTotal::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADLoginTotal::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADLoginTotal::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADLoginTotal::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADLoginTotal::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADLoginTotal::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADLoginTotal::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((loginDays_==0)?false:true);
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(loginDays_);
	}
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADLoginTotalContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADLoginTotalContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADLoginTotal::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(loginDays_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADLoginTotalContent> __elem = memnew(COM_ADLoginTotalContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ADChargeTotalContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_currencyCount_"), &COM_ADChargeTotalContent::get_currencyCount_);
	ClassDB::bind_method(D_METHOD("set_currencyCount_", "p_val"), &COM_ADChargeTotalContent::set_currencyCount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "currencyCount_"), "set_currencyCount_", "get_currencyCount_");
	ClassDB::bind_method(D_METHOD("get_itemIds_"), &COM_ADChargeTotalContent::get_itemIds_);
	ClassDB::bind_method(D_METHOD("set_itemIds_", "p_val"), &COM_ADChargeTotalContent::set_itemIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemIds_"), "set_itemIds_", "get_itemIds_");
	ClassDB::bind_method(D_METHOD("get_itemStacks_"), &COM_ADChargeTotalContent::get_itemStacks_);
	ClassDB::bind_method(D_METHOD("set_itemStacks_", "p_val"), &COM_ADChargeTotalContent::set_itemStacks_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemStacks_"), "set_itemStacks_", "get_itemStacks_");
	ClassDB::bind_method(D_METHOD("get_status_"), &COM_ADChargeTotalContent::get_status_);
	ClassDB::bind_method(D_METHOD("set_status_", "p_val"), &COM_ADChargeTotalContent::set_status_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "status_"), "set_status_", "get_status_");
}

void COM_ADChargeTotalContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((currencyCount_==0)?false:true);
	__fm__.writeBit(itemIds_.size()?true:false);
	__fm__.writeBit(itemStacks_.size()?true:false);
	__fm__.writeBit((status_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(currencyCount_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemIds_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemStacks_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemStacks_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(status_);
	}
}

bool COM_ADChargeTotalContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(currencyCount_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemIds_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemStacks_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemStacks_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(status_)) return false;
	}
	return true;
}

void COM_ADChargeTotal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_recharge_"), &COM_ADChargeTotal::get_recharge_);
	ClassDB::bind_method(D_METHOD("set_recharge_", "p_val"), &COM_ADChargeTotal::set_recharge_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "recharge_"), "set_recharge_", "get_recharge_");
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADChargeTotal::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADChargeTotal::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADChargeTotal::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADChargeTotal::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADChargeTotal::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADChargeTotal::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADChargeTotal::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((recharge_==0)?false:true);
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(recharge_);
	}
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADChargeTotalContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADChargeTotalContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADChargeTotal::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(recharge_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADChargeTotalContent> __elem = memnew(COM_ADChargeTotalContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ADDiscountStoreContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_price_"), &COM_ADDiscountStoreContent::get_price_);
	ClassDB::bind_method(D_METHOD("set_price_", "p_val"), &COM_ADDiscountStoreContent::set_price_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "price_"), "set_price_", "get_price_");
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_ADDiscountStoreContent::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_ADDiscountStoreContent::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_discount_"), &COM_ADDiscountStoreContent::get_discount_);
	ClassDB::bind_method(D_METHOD("set_discount_", "p_val"), &COM_ADDiscountStoreContent::set_discount_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "discount_"), "set_discount_", "get_discount_");
	ClassDB::bind_method(D_METHOD("get_buyLimit_"), &COM_ADDiscountStoreContent::get_buyLimit_);
	ClassDB::bind_method(D_METHOD("set_buyLimit_", "p_val"), &COM_ADDiscountStoreContent::set_buyLimit_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "buyLimit_"), "set_buyLimit_", "get_buyLimit_");
}

void COM_ADDiscountStoreContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((price_==0)?false:true);
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((discount_==0.0)?false:true);
	__fm__.writeBit((buyLimit_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(price_);
	}
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(discount_);
	}
	if(__fm__.readBit()){
		s->writeType(buyLimit_);
	}
}

bool COM_ADDiscountStoreContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(price_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(discount_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(buyLimit_)) return false;
	}
	return true;
}

void COM_ADDiscountStore::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADDiscountStore::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADDiscountStore::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADDiscountStore::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADDiscountStore::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADDiscountStore::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADDiscountStore::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADDiscountStore::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADDiscountStoreContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADDiscountStoreContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADDiscountStore::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADDiscountStoreContent> __elem = memnew(COM_ADDiscountStoreContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ADChargeEveryContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_currencyCount_"), &COM_ADChargeEveryContent::get_currencyCount_);
	ClassDB::bind_method(D_METHOD("set_currencyCount_", "p_val"), &COM_ADChargeEveryContent::set_currencyCount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "currencyCount_"), "set_currencyCount_", "get_currencyCount_");
	ClassDB::bind_method(D_METHOD("get_itemIds_"), &COM_ADChargeEveryContent::get_itemIds_);
	ClassDB::bind_method(D_METHOD("set_itemIds_", "p_val"), &COM_ADChargeEveryContent::set_itemIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemIds_"), "set_itemIds_", "get_itemIds_");
	ClassDB::bind_method(D_METHOD("get_itemStacks_"), &COM_ADChargeEveryContent::get_itemStacks_);
	ClassDB::bind_method(D_METHOD("set_itemStacks_", "p_val"), &COM_ADChargeEveryContent::set_itemStacks_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemStacks_"), "set_itemStacks_", "get_itemStacks_");
	ClassDB::bind_method(D_METHOD("get_status_"), &COM_ADChargeEveryContent::get_status_);
	ClassDB::bind_method(D_METHOD("set_status_", "p_val"), &COM_ADChargeEveryContent::set_status_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "status_"), "set_status_", "get_status_");
	ClassDB::bind_method(D_METHOD("get_count_"), &COM_ADChargeEveryContent::get_count_);
	ClassDB::bind_method(D_METHOD("set_count_", "p_val"), &COM_ADChargeEveryContent::set_count_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "count_"), "set_count_", "get_count_");
}

void COM_ADChargeEveryContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((currencyCount_==0)?false:true);
	__fm__.writeBit(itemIds_.size()?true:false);
	__fm__.writeBit(itemStacks_.size()?true:false);
	__fm__.writeBit((status_==0)?false:true);
	__fm__.writeBit((count_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(currencyCount_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemIds_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemStacks_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemStacks_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(status_);
	}
	if(__fm__.readBit()){
		s->writeType(count_);
	}
}

bool COM_ADChargeEveryContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(currencyCount_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemIds_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemStacks_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemStacks_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(status_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(count_)) return false;
	}
	return true;
}

void COM_ADChargeEvery::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_currentCount_"), &COM_ADChargeEvery::get_currentCount_);
	ClassDB::bind_method(D_METHOD("set_currentCount_", "p_val"), &COM_ADChargeEvery::set_currentCount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "currentCount_"), "set_currentCount_", "get_currentCount_");
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADChargeEvery::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADChargeEvery::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADChargeEvery::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADChargeEvery::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADChargeEvery::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADChargeEvery::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADChargeEvery::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((currentCount_==0)?false:true);
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(currentCount_);
	}
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADChargeEveryContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADChargeEveryContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADChargeEvery::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(currentCount_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADChargeEveryContent> __elem = memnew(COM_ADChargeEveryContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ADCardsContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_count_"), &COM_ADCardsContent::get_count_);
	ClassDB::bind_method(D_METHOD("set_count_", "p_val"), &COM_ADCardsContent::set_count_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "count_"), "set_count_", "get_count_");
	ClassDB::bind_method(D_METHOD("get_rewardId_"), &COM_ADCardsContent::get_rewardId_);
	ClassDB::bind_method(D_METHOD("set_rewardId_", "p_val"), &COM_ADCardsContent::set_rewardId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rewardId_"), "set_rewardId_", "get_rewardId_");
}

void COM_ADCardsContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((count_==0)?false:true);
	__fm__.writeBit((rewardId_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(count_);
	}
	if(__fm__.readBit()){
		s->writeType(rewardId_);
	}
}

bool COM_ADCardsContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(count_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rewardId_)) return false;
	}
	return true;
}

void COM_ADCards::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADCards::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADCards::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADCards::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADCards::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADCards::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADCards::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADCards::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADCardsContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADCardsContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADCards::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADCardsContent> __elem = memnew(COM_ADCardsContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ADHotRoleContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_ADHotRoleContent::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_ADHotRoleContent::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_buyNum_"), &COM_ADHotRoleContent::get_buyNum_);
	ClassDB::bind_method(D_METHOD("set_buyNum_", "p_val"), &COM_ADHotRoleContent::set_buyNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "buyNum_"), "set_buyNum_", "get_buyNum_");
	ClassDB::bind_method(D_METHOD("get_roleId_"), &COM_ADHotRoleContent::get_roleId_);
	ClassDB::bind_method(D_METHOD("set_roleId_", "p_val"), &COM_ADHotRoleContent::set_roleId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roleId_"), "set_roleId_", "get_roleId_");
	ClassDB::bind_method(D_METHOD("get_price_"), &COM_ADHotRoleContent::get_price_);
	ClassDB::bind_method(D_METHOD("set_price_", "p_val"), &COM_ADHotRoleContent::set_price_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "price_"), "set_price_", "get_price_");
}

void COM_ADHotRoleContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit((buyNum_==0)?false:true);
	__fm__.writeBit((roleId_==0)?false:true);
	__fm__.writeBit((price_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(buyNum_);
	}
	if(__fm__.readBit()){
		s->writeType(roleId_);
	}
	if(__fm__.readBit()){
		s->writeType(price_);
	}
}

bool COM_ADHotRoleContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 7) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(buyNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(price_)) return false;
	}
	return true;
}

void COM_ADHotRole::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADHotRole::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADHotRole::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADHotRole::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADHotRole::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADHotRole::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADHotRole::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADHotRole::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADHotRoleContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADHotRoleContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADHotRole::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADHotRoleContent> __elem = memnew(COM_ADHotRoleContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ADEmployeeTotalContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_outputCount_"), &COM_ADEmployeeTotalContent::get_outputCount_);
	ClassDB::bind_method(D_METHOD("set_outputCount_", "p_val"), &COM_ADEmployeeTotalContent::set_outputCount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "outputCount_"), "set_outputCount_", "get_outputCount_");
	ClassDB::bind_method(D_METHOD("get_itemIds_"), &COM_ADEmployeeTotalContent::get_itemIds_);
	ClassDB::bind_method(D_METHOD("set_itemIds_", "p_val"), &COM_ADEmployeeTotalContent::set_itemIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemIds_"), "set_itemIds_", "get_itemIds_");
	ClassDB::bind_method(D_METHOD("get_itemStacks_"), &COM_ADEmployeeTotalContent::get_itemStacks_);
	ClassDB::bind_method(D_METHOD("set_itemStacks_", "p_val"), &COM_ADEmployeeTotalContent::set_itemStacks_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemStacks_"), "set_itemStacks_", "get_itemStacks_");
	ClassDB::bind_method(D_METHOD("get_status_"), &COM_ADEmployeeTotalContent::get_status_);
	ClassDB::bind_method(D_METHOD("set_status_", "p_val"), &COM_ADEmployeeTotalContent::set_status_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "status_"), "set_status_", "get_status_");
}

void COM_ADEmployeeTotalContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((outputCount_==0)?false:true);
	__fm__.writeBit(itemIds_.size()?true:false);
	__fm__.writeBit(itemStacks_.size()?true:false);
	__fm__.writeBit((status_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(outputCount_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemIds_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemStacks_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = itemStacks_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(status_);
	}
}

bool COM_ADEmployeeTotalContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(outputCount_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemIds_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemStacks_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				itemStacks_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(status_)) return false;
	}
	return true;
}

void COM_ADEmployeeTotal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_outputNum_"), &COM_ADEmployeeTotal::get_outputNum_);
	ClassDB::bind_method(D_METHOD("set_outputNum_", "p_val"), &COM_ADEmployeeTotal::set_outputNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "outputNum_"), "set_outputNum_", "get_outputNum_");
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADEmployeeTotal::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADEmployeeTotal::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADEmployeeTotal::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADEmployeeTotal::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ADEmployeeTotal::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ADEmployeeTotal::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_ADEmployeeTotal::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((outputNum_==0)?false:true);
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(outputNum_);
	}
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ADEmployeeTotalContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ADEmployeeTotalContent);
			__elem->serialize(s);
		}
	}
}

bool COM_ADEmployeeTotal::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(outputNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ADEmployeeTotalContent> __elem = memnew(COM_ADEmployeeTotalContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_GiftItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_GiftItem::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_GiftItem::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_itemNum_"), &COM_GiftItem::get_itemNum_);
	ClassDB::bind_method(D_METHOD("set_itemNum_", "p_val"), &COM_GiftItem::set_itemNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemNum_"), "set_itemNum_", "get_itemNum_");
}

void COM_GiftItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((itemNum_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(itemNum_);
	}
}

bool COM_GiftItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemNum_)) return false;
	}
	return true;
}

void COM_ADGiftBag::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ADGiftBag::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ADGiftBag::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ADGiftBag::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ADGiftBag::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_isflag_"), &COM_ADGiftBag::get_isflag_);
	ClassDB::bind_method(D_METHOD("set_isflag_", "p_val"), &COM_ADGiftBag::set_isflag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isflag_"), "set_isflag_", "get_isflag_");
	ClassDB::bind_method(D_METHOD("get_price_"), &COM_ADGiftBag::get_price_);
	ClassDB::bind_method(D_METHOD("set_price_", "p_val"), &COM_ADGiftBag::set_price_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "price_"), "set_price_", "get_price_");
	ClassDB::bind_method(D_METHOD("get_oldprice_"), &COM_ADGiftBag::get_oldprice_);
	ClassDB::bind_method(D_METHOD("set_oldprice_", "p_val"), &COM_ADGiftBag::set_oldprice_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "oldprice_"), "set_oldprice_", "get_oldprice_");
	ClassDB::bind_method(D_METHOD("get_itemdata_"), &COM_ADGiftBag::get_itemdata_);
	ClassDB::bind_method(D_METHOD("set_itemdata_", "p_val"), &COM_ADGiftBag::set_itemdata_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemdata_"), "set_itemdata_", "get_itemdata_");
}

void COM_ADGiftBag::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(isflag_);
	__fm__.writeBit((price_==0)?false:true);
	__fm__.writeBit((oldprice_==0)?false:true);
	__fm__.writeBit(itemdata_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(isflag_);
	}
	if(__fm__.readBit()){
		s->writeType(price_);
	}
	if(__fm__.readBit()){
		s->writeType(oldprice_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemdata_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_GiftItem> __elem = itemdata_[i];
			if (__elem.is_null()) __elem = memnew(COM_GiftItem);
			__elem->serialize(s);
		}
	}
}

bool COM_ADGiftBag::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		isflag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(price_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(oldprice_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemdata_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GiftItem> __elem = memnew(COM_GiftItem);
				if(!__elem->deserialize(r)) return false;
				itemdata_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_Sevenday::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_quest_"), &COM_Sevenday::get_quest_);
	ClassDB::bind_method(D_METHOD("set_quest_", "p_val"), &COM_Sevenday::set_quest_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "quest_"), "set_quest_", "get_quest_");
	ClassDB::bind_method(D_METHOD("get_stype_"), &COM_Sevenday::get_stype_);
	ClassDB::bind_method(D_METHOD("set_stype_", "p_val"), &COM_Sevenday::set_stype_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "stype_"), "set_stype_", "get_stype_");
	ClassDB::bind_method(D_METHOD("get_qvalue_"), &COM_Sevenday::get_qvalue_);
	ClassDB::bind_method(D_METHOD("set_qvalue_", "p_val"), &COM_Sevenday::set_qvalue_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "qvalue_"), "set_qvalue_", "get_qvalue_");
	ClassDB::bind_method(D_METHOD("get_isfinish_"), &COM_Sevenday::get_isfinish_);
	ClassDB::bind_method(D_METHOD("set_isfinish_", "p_val"), &COM_Sevenday::set_isfinish_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isfinish_"), "set_isfinish_", "get_isfinish_");
	ClassDB::bind_method(D_METHOD("get_isreward_"), &COM_Sevenday::get_isreward_);
	ClassDB::bind_method(D_METHOD("set_isreward_", "p_val"), &COM_Sevenday::set_isreward_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isreward_"), "set_isreward_", "get_isreward_");
}

void COM_Sevenday::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((quest_==0)?false:true);
	__fm__.writeBit(stype_?true:false);
	__fm__.writeBit((qvalue_==0)?false:true);
	__fm__.writeBit(isfinish_);
	__fm__.writeBit(isreward_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(quest_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)stype_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(qvalue_);
	}
	if(__fm__.readBit()){
		s->writeType(isfinish_);
	}
	if(__fm__.readBit()){
		s->writeType(isreward_);
	}
}

bool COM_Sevenday::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(quest_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 60) return false;
		stype_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(qvalue_)) return false;
	}
	if(__fm__.readBit()){
		isfinish_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isreward_ = __fm__.readBit();
	}
	return true;
}

void COM_ZhuanpanContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_id_"), &COM_ZhuanpanContent::get_id_);
	ClassDB::bind_method(D_METHOD("set_id_", "p_val"), &COM_ZhuanpanContent::set_id_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "id_"), "set_id_", "get_id_");
	ClassDB::bind_method(D_METHOD("get_item_"), &COM_ZhuanpanContent::get_item_);
	ClassDB::bind_method(D_METHOD("set_item_", "p_val"), &COM_ZhuanpanContent::set_item_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "item_"), "set_item_", "get_item_");
	ClassDB::bind_method(D_METHOD("get_itemNum_"), &COM_ZhuanpanContent::get_itemNum_);
	ClassDB::bind_method(D_METHOD("set_itemNum_", "p_val"), &COM_ZhuanpanContent::set_itemNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemNum_"), "set_itemNum_", "get_itemNum_");
	ClassDB::bind_method(D_METHOD("get_rate_"), &COM_ZhuanpanContent::get_rate_);
	ClassDB::bind_method(D_METHOD("set_rate_", "p_val"), &COM_ZhuanpanContent::set_rate_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rate_"), "set_rate_", "get_rate_");
	ClassDB::bind_method(D_METHOD("get_maxdrop_"), &COM_ZhuanpanContent::get_maxdrop_);
	ClassDB::bind_method(D_METHOD("set_maxdrop_", "p_val"), &COM_ZhuanpanContent::set_maxdrop_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "maxdrop_"), "set_maxdrop_", "get_maxdrop_");
}

void COM_ZhuanpanContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((id_==0)?false:true);
	__fm__.writeBit((item_==0)?false:true);
	__fm__.writeBit((itemNum_==0)?false:true);
	__fm__.writeBit((rate_==0)?false:true);
	__fm__.writeBit((maxdrop_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(id_);
	}
	if(__fm__.readBit()){
		s->writeType(item_);
	}
	if(__fm__.readBit()){
		s->writeType(itemNum_);
	}
	if(__fm__.readBit()){
		s->writeType(rate_);
	}
	if(__fm__.readBit()){
		s->writeType(maxdrop_);
	}
}

bool COM_ZhuanpanContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(id_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(item_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rate_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(maxdrop_)) return false;
	}
	return true;
}

void COM_Zhuanpan::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_Zhuanpan::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_Zhuanpan::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_zhuanpanId_"), &COM_Zhuanpan::get_zhuanpanId_);
	ClassDB::bind_method(D_METHOD("set_zhuanpanId_", "p_val"), &COM_Zhuanpan::set_zhuanpanId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "zhuanpanId_"), "set_zhuanpanId_", "get_zhuanpanId_");
}

void COM_Zhuanpan::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit((zhuanpanId_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(zhuanpanId_);
	}
}

bool COM_Zhuanpan::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(zhuanpanId_)) return false;
	}
	return true;
}

void COM_ZhuanpanData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_ZhuanpanData::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_ZhuanpanData::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_ZhuanpanData::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_ZhuanpanData::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_ZhuanpanData::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_ZhuanpanData::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
	ClassDB::bind_method(D_METHOD("get_rarity_"), &COM_ZhuanpanData::get_rarity_);
	ClassDB::bind_method(D_METHOD("set_rarity_", "p_val"), &COM_ZhuanpanData::set_rarity_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "rarity_"), "set_rarity_", "get_rarity_");
}

void COM_ZhuanpanData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit(contents_.size()?true:false);
	__fm__.writeBit(rarity_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ZhuanpanContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_ZhuanpanContent);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)rarity_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Zhuanpan> __elem = rarity_[i];
			if (__elem.is_null()) __elem = memnew(COM_Zhuanpan);
			__elem->serialize(s);
		}
	}
}

bool COM_ZhuanpanData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ZhuanpanContent> __elem = memnew(COM_ZhuanpanContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			rarity_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Zhuanpan> __elem = memnew(COM_Zhuanpan);
				if(!__elem->deserialize(r)) return false;
				rarity_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_IntegralContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_id_"), &COM_IntegralContent::get_id_);
	ClassDB::bind_method(D_METHOD("set_id_", "p_val"), &COM_IntegralContent::set_id_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "id_"), "set_id_", "get_id_");
	ClassDB::bind_method(D_METHOD("get_itemid_"), &COM_IntegralContent::get_itemid_);
	ClassDB::bind_method(D_METHOD("set_itemid_", "p_val"), &COM_IntegralContent::set_itemid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemid_"), "set_itemid_", "get_itemid_");
	ClassDB::bind_method(D_METHOD("get_times_"), &COM_IntegralContent::get_times_);
	ClassDB::bind_method(D_METHOD("set_times_", "p_val"), &COM_IntegralContent::set_times_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "times_"), "set_times_", "get_times_");
	ClassDB::bind_method(D_METHOD("get_cost_"), &COM_IntegralContent::get_cost_);
	ClassDB::bind_method(D_METHOD("set_cost_", "p_val"), &COM_IntegralContent::set_cost_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "cost_"), "set_cost_", "get_cost_");
}

void COM_IntegralContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((id_==0)?false:true);
	__fm__.writeBit((itemid_==0)?false:true);
	__fm__.writeBit((times_==0)?false:true);
	__fm__.writeBit((cost_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(id_);
	}
	if(__fm__.readBit()){
		s->writeType(itemid_);
	}
	if(__fm__.readBit()){
		s->writeType(times_);
	}
	if(__fm__.readBit()){
		s->writeType(cost_);
	}
}

bool COM_IntegralContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(id_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(times_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(cost_)) return false;
	}
	return true;
}

void COM_IntegralData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sinceStamp_"), &COM_IntegralData::get_sinceStamp_);
	ClassDB::bind_method(D_METHOD("set_sinceStamp_", "p_val"), &COM_IntegralData::set_sinceStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sinceStamp_"), "set_sinceStamp_", "get_sinceStamp_");
	ClassDB::bind_method(D_METHOD("get_endStamp_"), &COM_IntegralData::get_endStamp_);
	ClassDB::bind_method(D_METHOD("set_endStamp_", "p_val"), &COM_IntegralData::set_endStamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "endStamp_"), "set_endStamp_", "get_endStamp_");
	ClassDB::bind_method(D_METHOD("get_integral_"), &COM_IntegralData::get_integral_);
	ClassDB::bind_method(D_METHOD("set_integral_", "p_val"), &COM_IntegralData::set_integral_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "integral_"), "set_integral_", "get_integral_");
	ClassDB::bind_method(D_METHOD("get_isflag_"), &COM_IntegralData::get_isflag_);
	ClassDB::bind_method(D_METHOD("set_isflag_", "p_val"), &COM_IntegralData::set_isflag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isflag_"), "set_isflag_", "get_isflag_");
	ClassDB::bind_method(D_METHOD("get_contents_"), &COM_IntegralData::get_contents_);
	ClassDB::bind_method(D_METHOD("set_contents_", "p_val"), &COM_IntegralData::set_contents_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "contents_"), "set_contents_", "get_contents_");
}

void COM_IntegralData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sinceStamp_==0)?false:true);
	__fm__.writeBit((endStamp_==0)?false:true);
	__fm__.writeBit((integral_==0)?false:true);
	__fm__.writeBit(isflag_);
	__fm__.writeBit(contents_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sinceStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(endStamp_);
	}
	if(__fm__.readBit()){
		s->writeType(integral_);
	}
	if(__fm__.readBit()){
		s->writeType(isflag_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)contents_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_IntegralContent> __elem = contents_[i];
			if (__elem.is_null()) __elem = memnew(COM_IntegralContent);
			__elem->serialize(s);
		}
	}
}

bool COM_IntegralData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sinceStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(endStamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(integral_)) return false;
	}
	if(__fm__.readBit()){
		isflag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			contents_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_IntegralContent> __elem = memnew(COM_IntegralContent);
				if(!__elem->deserialize(r)) return false;
				contents_[i] = __elem;
			}
		}
	}
	return true;
}

void SGE_SysActivity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_loginData_"), &SGE_SysActivity::get_loginData_);
	ClassDB::bind_method(D_METHOD("set_loginData_", "p_val"), &SGE_SysActivity::set_loginData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "loginData_"), "set_loginData_", "get_loginData_");
	ClassDB::bind_method(D_METHOD("get_chData_"), &SGE_SysActivity::get_chData_);
	ClassDB::bind_method(D_METHOD("set_chData_", "p_val"), &SGE_SysActivity::set_chData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "chData_"), "set_chData_", "get_chData_");
	ClassDB::bind_method(D_METHOD("get_stData_"), &SGE_SysActivity::get_stData_);
	ClassDB::bind_method(D_METHOD("set_stData_", "p_val"), &SGE_SysActivity::set_stData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "stData_"), "set_stData_", "get_stData_");
	ClassDB::bind_method(D_METHOD("get_ceData_"), &SGE_SysActivity::get_ceData_);
	ClassDB::bind_method(D_METHOD("set_ceData_", "p_val"), &SGE_SysActivity::set_ceData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "ceData_"), "set_ceData_", "get_ceData_");
	ClassDB::bind_method(D_METHOD("get_acData_"), &SGE_SysActivity::get_acData_);
	ClassDB::bind_method(D_METHOD("set_acData_", "p_val"), &SGE_SysActivity::set_acData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "acData_"), "set_acData_", "get_acData_");
	ClassDB::bind_method(D_METHOD("get_hrData_"), &SGE_SysActivity::get_hrData_);
	ClassDB::bind_method(D_METHOD("set_hrData_", "p_val"), &SGE_SysActivity::set_hrData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "hrData_"), "set_hrData_", "get_hrData_");
	ClassDB::bind_method(D_METHOD("get_etdata_"), &SGE_SysActivity::get_etdata_);
	ClassDB::bind_method(D_METHOD("set_etdata_", "p_val"), &SGE_SysActivity::set_etdata_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "etdata_"), "set_etdata_", "get_etdata_");
	ClassDB::bind_method(D_METHOD("get_gbdata_"), &SGE_SysActivity::get_gbdata_);
	ClassDB::bind_method(D_METHOD("set_gbdata_", "p_val"), &SGE_SysActivity::set_gbdata_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "gbdata_"), "set_gbdata_", "get_gbdata_");
	ClassDB::bind_method(D_METHOD("get_zpdata_"), &SGE_SysActivity::get_zpdata_);
	ClassDB::bind_method(D_METHOD("set_zpdata_", "p_val"), &SGE_SysActivity::set_zpdata_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "zpdata_"), "set_zpdata_", "get_zpdata_");
	ClassDB::bind_method(D_METHOD("get_icdata_"), &SGE_SysActivity::get_icdata_);
	ClassDB::bind_method(D_METHOD("set_icdata_", "p_val"), &SGE_SysActivity::set_icdata_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "icdata_"), "set_icdata_", "get_icdata_");
}

void SGE_SysActivity::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		if (loginData_.is_null()) const_cast<Ref<COM_ADLoginTotal>&>(loginData_) = memnew(COM_ADLoginTotal);
		loginData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (chData_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(chData_) = memnew(COM_ADChargeTotal);
		chData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (stData_.is_null()) const_cast<Ref<COM_ADDiscountStore>&>(stData_) = memnew(COM_ADDiscountStore);
		stData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (ceData_.is_null()) const_cast<Ref<COM_ADChargeEvery>&>(ceData_) = memnew(COM_ADChargeEvery);
		ceData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (acData_.is_null()) const_cast<Ref<COM_ADCards>&>(acData_) = memnew(COM_ADCards);
		acData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (hrData_.is_null()) const_cast<Ref<COM_ADHotRole>&>(hrData_) = memnew(COM_ADHotRole);
		hrData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (etdata_.is_null()) const_cast<Ref<COM_ADEmployeeTotal>&>(etdata_) = memnew(COM_ADEmployeeTotal);
		etdata_->serialize(s);
	}
	if(__fm__.readBit()){
		if (gbdata_.is_null()) const_cast<Ref<COM_ADGiftBag>&>(gbdata_) = memnew(COM_ADGiftBag);
		gbdata_->serialize(s);
	}
	if(__fm__.readBit()){
		if (zpdata_.is_null()) const_cast<Ref<COM_ZhuanpanData>&>(zpdata_) = memnew(COM_ZhuanpanData);
		zpdata_->serialize(s);
	}
	if(__fm__.readBit()){
		if (icdata_.is_null()) const_cast<Ref<COM_IntegralData>&>(icdata_) = memnew(COM_IntegralData);
		icdata_->serialize(s);
	}
}

bool SGE_SysActivity::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if (loginData_.is_null()) const_cast<Ref<COM_ADLoginTotal>&>(loginData_) = memnew(COM_ADLoginTotal);
		if(!loginData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (chData_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(chData_) = memnew(COM_ADChargeTotal);
		if(!chData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (stData_.is_null()) const_cast<Ref<COM_ADDiscountStore>&>(stData_) = memnew(COM_ADDiscountStore);
		if(!stData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (ceData_.is_null()) const_cast<Ref<COM_ADChargeEvery>&>(ceData_) = memnew(COM_ADChargeEvery);
		if(!ceData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (acData_.is_null()) const_cast<Ref<COM_ADCards>&>(acData_) = memnew(COM_ADCards);
		if(!acData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (hrData_.is_null()) const_cast<Ref<COM_ADHotRole>&>(hrData_) = memnew(COM_ADHotRole);
		if(!hrData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (etdata_.is_null()) const_cast<Ref<COM_ADEmployeeTotal>&>(etdata_) = memnew(COM_ADEmployeeTotal);
		if(!etdata_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (gbdata_.is_null()) const_cast<Ref<COM_ADGiftBag>&>(gbdata_) = memnew(COM_ADGiftBag);
		if(!gbdata_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (zpdata_.is_null()) const_cast<Ref<COM_ZhuanpanData>&>(zpdata_) = memnew(COM_ZhuanpanData);
		if(!zpdata_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (icdata_.is_null()) const_cast<Ref<COM_IntegralData>&>(icdata_) = memnew(COM_IntegralData);
		if(!icdata_->deserialize(r)) return false;
	}
	return true;
}

void COM_LoginInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_username_"), &COM_LoginInfo::get_username_);
	ClassDB::bind_method(D_METHOD("set_username_", "p_val"), &COM_LoginInfo::set_username_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "username_"), "set_username_", "get_username_");
	ClassDB::bind_method(D_METHOD("get_password_"), &COM_LoginInfo::get_password_);
	ClassDB::bind_method(D_METHOD("set_password_", "p_val"), &COM_LoginInfo::set_password_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "password_"), "set_password_", "get_password_");
	ClassDB::bind_method(D_METHOD("get_version_"), &COM_LoginInfo::get_version_);
	ClassDB::bind_method(D_METHOD("set_version_", "p_val"), &COM_LoginInfo::set_version_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "version_"), "set_version_", "get_version_");
	ClassDB::bind_method(D_METHOD("get_sessionkey_"), &COM_LoginInfo::get_sessionkey_);
	ClassDB::bind_method(D_METHOD("set_sessionkey_", "p_val"), &COM_LoginInfo::set_sessionkey_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "sessionkey_"), "set_sessionkey_", "get_sessionkey_");
	ClassDB::bind_method(D_METHOD("get_mac_"), &COM_LoginInfo::get_mac_);
	ClassDB::bind_method(D_METHOD("set_mac_", "p_val"), &COM_LoginInfo::set_mac_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "mac_"), "set_mac_", "get_mac_");
	ClassDB::bind_method(D_METHOD("get_idfa_"), &COM_LoginInfo::get_idfa_);
	ClassDB::bind_method(D_METHOD("set_idfa_", "p_val"), &COM_LoginInfo::set_idfa_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "idfa_"), "set_idfa_", "get_idfa_");
	ClassDB::bind_method(D_METHOD("get_devicetype_"), &COM_LoginInfo::get_devicetype_);
	ClassDB::bind_method(D_METHOD("set_devicetype_", "p_val"), &COM_LoginInfo::set_devicetype_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "devicetype_"), "set_devicetype_", "get_devicetype_");
}

void COM_LoginInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(username_.length()?true:false);
	__fm__.writeBit(password_.length()?true:false);
	__fm__.writeBit((version_==0)?false:true);
	__fm__.writeBit(sessionkey_.length()?true:false);
	__fm__.writeBit(mac_.length()?true:false);
	__fm__.writeBit(idfa_.length()?true:false);
	__fm__.writeBit(devicetype_.length()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(username_);
	}
	if(__fm__.readBit()){
		s->writeType(password_);
	}
	if(__fm__.readBit()){
		s->writeType(version_);
	}
	if(__fm__.readBit()){
		s->writeType(sessionkey_);
	}
	if(__fm__.readBit()){
		s->writeType(mac_);
	}
	if(__fm__.readBit()){
		s->writeType(idfa_);
	}
	if(__fm__.readBit()){
		s->writeType(devicetype_);
	}
}

bool COM_LoginInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(username_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(password_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(version_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sessionkey_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mac_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(idfa_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(devicetype_, 65535)) return false;
	}
	return true;
}

void COM_FPosition::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_x_"), &COM_FPosition::get_x_);
	ClassDB::bind_method(D_METHOD("set_x_", "p_val"), &COM_FPosition::set_x_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x_"), "set_x_", "get_x_");
	ClassDB::bind_method(D_METHOD("get_z_"), &COM_FPosition::get_z_);
	ClassDB::bind_method(D_METHOD("set_z_", "p_val"), &COM_FPosition::set_z_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "z_"), "set_z_", "get_z_");
	ClassDB::bind_method(D_METHOD("get_isLast_"), &COM_FPosition::get_isLast_);
	ClassDB::bind_method(D_METHOD("set_isLast_", "p_val"), &COM_FPosition::set_isLast_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLast_"), "set_isLast_", "get_isLast_");
}

void COM_FPosition::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((x_==0.0)?false:true);
	__fm__.writeBit((z_==0.0)?false:true);
	__fm__.writeBit(isLast_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(x_);
	}
	if(__fm__.readBit()){
		s->writeType(z_);
	}
	if(__fm__.readBit()){
		s->writeType(isLast_);
	}
}

bool COM_FPosition::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(x_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(z_)) return false;
	}
	if(__fm__.readBit()){
		isLast_ = __fm__.readBit();
	}
	return true;
}

void COM_ScenePlayerInformation::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_isLeader_"), &COM_ScenePlayerInformation::get_isLeader_);
	ClassDB::bind_method(D_METHOD("set_isLeader_", "p_val"), &COM_ScenePlayerInformation::set_isLeader_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLeader_"), "set_isLeader_", "get_isLeader_");
	ClassDB::bind_method(D_METHOD("get_isTeamMember_"), &COM_ScenePlayerInformation::get_isTeamMember_);
	ClassDB::bind_method(D_METHOD("set_isTeamMember_", "p_val"), &COM_ScenePlayerInformation::set_isTeamMember_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isTeamMember_"), "set_isTeamMember_", "get_isTeamMember_");
	ClassDB::bind_method(D_METHOD("get_isInBattle_"), &COM_ScenePlayerInformation::get_isInBattle_);
	ClassDB::bind_method(D_METHOD("set_isInBattle_", "p_val"), &COM_ScenePlayerInformation::set_isInBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isInBattle_"), "set_isInBattle_", "get_isInBattle_");
	ClassDB::bind_method(D_METHOD("get_vip_"), &COM_ScenePlayerInformation::get_vip_);
	ClassDB::bind_method(D_METHOD("set_vip_", "p_val"), &COM_ScenePlayerInformation::set_vip_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "vip_"), "set_vip_", "get_vip_");
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_ScenePlayerInformation::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_ScenePlayerInformation::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_assetId_"), &COM_ScenePlayerInformation::get_assetId_);
	ClassDB::bind_method(D_METHOD("set_assetId_", "p_val"), &COM_ScenePlayerInformation::set_assetId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "assetId_"), "set_assetId_", "get_assetId_");
	ClassDB::bind_method(D_METHOD("get_weaponItemId_"), &COM_ScenePlayerInformation::get_weaponItemId_);
	ClassDB::bind_method(D_METHOD("set_weaponItemId_", "p_val"), &COM_ScenePlayerInformation::set_weaponItemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "weaponItemId_"), "set_weaponItemId_", "get_weaponItemId_");
	ClassDB::bind_method(D_METHOD("get_fashionId_"), &COM_ScenePlayerInformation::get_fashionId_);
	ClassDB::bind_method(D_METHOD("set_fashionId_", "p_val"), &COM_ScenePlayerInformation::set_fashionId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "fashionId_"), "set_fashionId_", "get_fashionId_");
	ClassDB::bind_method(D_METHOD("get_hpMax_"), &COM_ScenePlayerInformation::get_hpMax_);
	ClassDB::bind_method(D_METHOD("set_hpMax_", "p_val"), &COM_ScenePlayerInformation::set_hpMax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "hpMax_"), "set_hpMax_", "get_hpMax_");
	ClassDB::bind_method(D_METHOD("get_hpCrt_"), &COM_ScenePlayerInformation::get_hpCrt_);
	ClassDB::bind_method(D_METHOD("set_hpCrt_", "p_val"), &COM_ScenePlayerInformation::set_hpCrt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "hpCrt_"), "set_hpCrt_", "get_hpCrt_");
	ClassDB::bind_method(D_METHOD("get_mpMax_"), &COM_ScenePlayerInformation::get_mpMax_);
	ClassDB::bind_method(D_METHOD("set_mpMax_", "p_val"), &COM_ScenePlayerInformation::set_mpMax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mpMax_"), "set_mpMax_", "get_mpMax_");
	ClassDB::bind_method(D_METHOD("get_mpCrt_"), &COM_ScenePlayerInformation::get_mpCrt_);
	ClassDB::bind_method(D_METHOD("set_mpCrt_", "p_val"), &COM_ScenePlayerInformation::set_mpCrt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mpCrt_"), "set_mpCrt_", "get_mpCrt_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_ScenePlayerInformation::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_ScenePlayerInformation::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_battlePower_"), &COM_ScenePlayerInformation::get_battlePower_);
	ClassDB::bind_method(D_METHOD("set_battlePower_", "p_val"), &COM_ScenePlayerInformation::set_battlePower_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "battlePower_"), "set_battlePower_", "get_battlePower_");
	ClassDB::bind_method(D_METHOD("get_jl_"), &COM_ScenePlayerInformation::get_jl_);
	ClassDB::bind_method(D_METHOD("set_jl_", "p_val"), &COM_ScenePlayerInformation::set_jl_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "jl_"), "set_jl_", "get_jl_");
	ClassDB::bind_method(D_METHOD("get_magicLv_"), &COM_ScenePlayerInformation::get_magicLv_);
	ClassDB::bind_method(D_METHOD("set_magicLv_", "p_val"), &COM_ScenePlayerInformation::set_magicLv_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicLv_"), "set_magicLv_", "get_magicLv_");
	ClassDB::bind_method(D_METHOD("get_openSubSystemFlag_"), &COM_ScenePlayerInformation::get_openSubSystemFlag_);
	ClassDB::bind_method(D_METHOD("set_openSubSystemFlag_", "p_val"), &COM_ScenePlayerInformation::set_openSubSystemFlag_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "openSubSystemFlag_"), "set_openSubSystemFlag_", "get_openSubSystemFlag_");
	ClassDB::bind_method(D_METHOD("get_title_"), &COM_ScenePlayerInformation::get_title_);
	ClassDB::bind_method(D_METHOD("set_title_", "p_val"), &COM_ScenePlayerInformation::set_title_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "title_"), "set_title_", "get_title_");
	ClassDB::bind_method(D_METHOD("get_instName_"), &COM_ScenePlayerInformation::get_instName_);
	ClassDB::bind_method(D_METHOD("set_instName_", "p_val"), &COM_ScenePlayerInformation::set_instName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "instName_"), "set_instName_", "get_instName_");
	ClassDB::bind_method(D_METHOD("get_guildeName_"), &COM_ScenePlayerInformation::get_guildeName_);
	ClassDB::bind_method(D_METHOD("set_guildeName_", "p_val"), &COM_ScenePlayerInformation::set_guildeName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "guildeName_"), "set_guildeName_", "get_guildeName_");
	ClassDB::bind_method(D_METHOD("get_jt_"), &COM_ScenePlayerInformation::get_jt_);
	ClassDB::bind_method(D_METHOD("set_jt_", "p_val"), &COM_ScenePlayerInformation::set_jt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "jt_"), "set_jt_", "get_jt_");
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_ScenePlayerInformation::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_ScenePlayerInformation::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_originPos_"), &COM_ScenePlayerInformation::get_originPos_);
	ClassDB::bind_method(D_METHOD("set_originPos_", "p_val"), &COM_ScenePlayerInformation::set_originPos_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "originPos_"), "set_originPos_", "get_originPos_");
	ClassDB::bind_method(D_METHOD("get_showBabyTableId_"), &COM_ScenePlayerInformation::get_showBabyTableId_);
	ClassDB::bind_method(D_METHOD("set_showBabyTableId_", "p_val"), &COM_ScenePlayerInformation::set_showBabyTableId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "showBabyTableId_"), "set_showBabyTableId_", "get_showBabyTableId_");
	ClassDB::bind_method(D_METHOD("get_showBabyName_"), &COM_ScenePlayerInformation::get_showBabyName_);
	ClassDB::bind_method(D_METHOD("set_showBabyName_", "p_val"), &COM_ScenePlayerInformation::set_showBabyName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "showBabyName_"), "set_showBabyName_", "get_showBabyName_");
}

void COM_ScenePlayerInformation::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<4> __fm__;
	__fm__.writeBit(isLeader_);
	__fm__.writeBit(isTeamMember_);
	__fm__.writeBit(isInBattle_);
	__fm__.writeBit((vip_==0)?false:true);
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit((assetId_==0)?false:true);
	__fm__.writeBit((weaponItemId_==0)?false:true);
	__fm__.writeBit((fashionId_==0)?false:true);
	__fm__.writeBit((hpMax_==0)?false:true);
	__fm__.writeBit((hpCrt_==0)?false:true);
	__fm__.writeBit((mpMax_==0)?false:true);
	__fm__.writeBit((mpCrt_==0)?false:true);
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((battlePower_==0)?false:true);
	__fm__.writeBit((jl_==0)?false:true);
	__fm__.writeBit((magicLv_==0)?false:true);
	__fm__.writeBit((openSubSystemFlag_==0)?false:true);
	__fm__.writeBit((title_==0)?false:true);
	__fm__.writeBit(instName_.length()?true:false);
	__fm__.writeBit(guildeName_.length()?true:false);
	__fm__.writeBit(jt_?true:false);
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit((showBabyTableId_==0)?false:true);
	__fm__.writeBit(showBabyName_.length()?true:false);
	s->write((const void*)__fm__.masks_, 4);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(isLeader_);
	}
	if(__fm__.readBit()){
		s->writeType(isTeamMember_);
	}
	if(__fm__.readBit()){
		s->writeType(isInBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(vip_);
	}
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(assetId_);
	}
	if(__fm__.readBit()){
		s->writeType(weaponItemId_);
	}
	if(__fm__.readBit()){
		s->writeType(fashionId_);
	}
	if(__fm__.readBit()){
		s->writeType(hpMax_);
	}
	if(__fm__.readBit()){
		s->writeType(hpCrt_);
	}
	if(__fm__.readBit()){
		s->writeType(mpMax_);
	}
	if(__fm__.readBit()){
		s->writeType(mpCrt_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(battlePower_);
	}
	if(__fm__.readBit()){
		s->writeType(jl_);
	}
	if(__fm__.readBit()){
		s->writeType(magicLv_);
	}
	if(__fm__.readBit()){
		s->writeType(openSubSystemFlag_);
	}
	if(__fm__.readBit()){
		s->writeType(title_);
	}
	if(__fm__.readBit()){
		s->writeType(instName_);
	}
	if(__fm__.readBit()){
		s->writeType(guildeName_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)jt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		if (originPos_.is_null()) const_cast<Ref<COM_FPosition>&>(originPos_) = memnew(COM_FPosition);
		originPos_->serialize(s);
	}
	if(__fm__.readBit()){
		s->writeType(showBabyTableId_);
	}
	if(__fm__.readBit()){
		s->writeType(showBabyName_);
	}
}

bool COM_ScenePlayerInformation::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<4> __fm__;
	if(!r->read((void*)__fm__.masks_, 4)) return false;
	if(__fm__.readBit()){
		isLeader_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isTeamMember_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isInBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(vip_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(assetId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(weaponItemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(fashionId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(hpMax_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(hpCrt_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mpMax_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mpCrt_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(battlePower_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(jl_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(magicLv_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(openSubSystemFlag_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(title_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildeName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		jt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 7) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if (originPos_.is_null()) const_cast<Ref<COM_FPosition>&>(originPos_) = memnew(COM_FPosition);
		if(!originPos_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(showBabyTableId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(showBabyName_, 65535)) return false;
	}
	return true;
}

void COM_BattleEntityInformation::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_BattleEntityInformation::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_BattleEntityInformation::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_instName_"), &COM_BattleEntityInformation::get_instName_);
	ClassDB::bind_method(D_METHOD("set_instName_", "p_val"), &COM_BattleEntityInformation::set_instName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "instName_"), "set_instName_", "get_instName_");
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_BattleEntityInformation::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_BattleEntityInformation::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_tableId_"), &COM_BattleEntityInformation::get_tableId_);
	ClassDB::bind_method(D_METHOD("set_tableId_", "p_val"), &COM_BattleEntityInformation::set_tableId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "tableId_"), "set_tableId_", "get_tableId_");
	ClassDB::bind_method(D_METHOD("get_assetId_"), &COM_BattleEntityInformation::get_assetId_);
	ClassDB::bind_method(D_METHOD("set_assetId_", "p_val"), &COM_BattleEntityInformation::set_assetId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "assetId_"), "set_assetId_", "get_assetId_");
	ClassDB::bind_method(D_METHOD("get_jt_"), &COM_BattleEntityInformation::get_jt_);
	ClassDB::bind_method(D_METHOD("set_jt_", "p_val"), &COM_BattleEntityInformation::set_jt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "jt_"), "set_jt_", "get_jt_");
	ClassDB::bind_method(D_METHOD("get_battlePosition_"), &COM_BattleEntityInformation::get_battlePosition_);
	ClassDB::bind_method(D_METHOD("set_battlePosition_", "p_val"), &COM_BattleEntityInformation::set_battlePosition_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "battlePosition_"), "set_battlePosition_", "get_battlePosition_");
	ClassDB::bind_method(D_METHOD("get_weaponItemId_"), &COM_BattleEntityInformation::get_weaponItemId_);
	ClassDB::bind_method(D_METHOD("set_weaponItemId_", "p_val"), &COM_BattleEntityInformation::set_weaponItemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "weaponItemId_"), "set_weaponItemId_", "get_weaponItemId_");
	ClassDB::bind_method(D_METHOD("get_fashionId_"), &COM_BattleEntityInformation::get_fashionId_);
	ClassDB::bind_method(D_METHOD("set_fashionId_", "p_val"), &COM_BattleEntityInformation::set_fashionId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "fashionId_"), "set_fashionId_", "get_fashionId_");
	ClassDB::bind_method(D_METHOD("get_hpMax_"), &COM_BattleEntityInformation::get_hpMax_);
	ClassDB::bind_method(D_METHOD("set_hpMax_", "p_val"), &COM_BattleEntityInformation::set_hpMax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "hpMax_"), "set_hpMax_", "get_hpMax_");
	ClassDB::bind_method(D_METHOD("get_hpCrt_"), &COM_BattleEntityInformation::get_hpCrt_);
	ClassDB::bind_method(D_METHOD("set_hpCrt_", "p_val"), &COM_BattleEntityInformation::set_hpCrt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "hpCrt_"), "set_hpCrt_", "get_hpCrt_");
	ClassDB::bind_method(D_METHOD("get_mpMax_"), &COM_BattleEntityInformation::get_mpMax_);
	ClassDB::bind_method(D_METHOD("set_mpMax_", "p_val"), &COM_BattleEntityInformation::set_mpMax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mpMax_"), "set_mpMax_", "get_mpMax_");
	ClassDB::bind_method(D_METHOD("get_mpCrt_"), &COM_BattleEntityInformation::get_mpCrt_);
	ClassDB::bind_method(D_METHOD("set_mpCrt_", "p_val"), &COM_BattleEntityInformation::set_mpCrt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mpCrt_"), "set_mpCrt_", "get_mpCrt_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_BattleEntityInformation::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_BattleEntityInformation::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
}

void COM_BattleEntityInformation::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit(instName_.length()?true:false);
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit((tableId_==0)?false:true);
	__fm__.writeBit((assetId_==0)?false:true);
	__fm__.writeBit(jt_?true:false);
	__fm__.writeBit(battlePosition_?true:false);
	__fm__.writeBit((weaponItemId_==0)?false:true);
	__fm__.writeBit((fashionId_==0)?false:true);
	__fm__.writeBit((hpMax_==0)?false:true);
	__fm__.writeBit((hpCrt_==0)?false:true);
	__fm__.writeBit((mpMax_==0)?false:true);
	__fm__.writeBit((mpCrt_==0)?false:true);
	__fm__.writeBit((level_==0)?false:true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(instName_);
	}
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(tableId_);
	}
	if(__fm__.readBit()){
		s->writeType(assetId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)jt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)battlePosition_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(weaponItemId_);
	}
	if(__fm__.readBit()){
		s->writeType(fashionId_);
	}
	if(__fm__.readBit()){
		s->writeType(hpMax_);
	}
	if(__fm__.readBit()){
		s->writeType(hpCrt_);
	}
	if(__fm__.readBit()){
		s->writeType(mpMax_);
	}
	if(__fm__.readBit()){
		s->writeType(mpCrt_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
}

bool COM_BattleEntityInformation::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 7) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(instName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(tableId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(assetId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		jt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 22) return false;
		battlePosition_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(weaponItemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(fashionId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(hpMax_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(hpCrt_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mpMax_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mpCrt_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	return true;
}

void COM_SimpleInformation::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_SimpleInformation::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_SimpleInformation::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_SimpleInformation::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_SimpleInformation::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_asset_id_"), &COM_SimpleInformation::get_asset_id_);
	ClassDB::bind_method(D_METHOD("set_asset_id_", "p_val"), &COM_SimpleInformation::set_asset_id_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "asset_id_"), "set_asset_id_", "get_asset_id_");
	ClassDB::bind_method(D_METHOD("get_instName_"), &COM_SimpleInformation::get_instName_);
	ClassDB::bind_method(D_METHOD("set_instName_", "p_val"), &COM_SimpleInformation::set_instName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "instName_"), "set_instName_", "get_instName_");
	ClassDB::bind_method(D_METHOD("get_weaponItemId_"), &COM_SimpleInformation::get_weaponItemId_);
	ClassDB::bind_method(D_METHOD("set_weaponItemId_", "p_val"), &COM_SimpleInformation::set_weaponItemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "weaponItemId_"), "set_weaponItemId_", "get_weaponItemId_");
	ClassDB::bind_method(D_METHOD("get_fashionId_"), &COM_SimpleInformation::get_fashionId_);
	ClassDB::bind_method(D_METHOD("set_fashionId_", "p_val"), &COM_SimpleInformation::set_fashionId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "fashionId_"), "set_fashionId_", "get_fashionId_");
	ClassDB::bind_method(D_METHOD("get_section_"), &COM_SimpleInformation::get_section_);
	ClassDB::bind_method(D_METHOD("set_section_", "p_val"), &COM_SimpleInformation::set_section_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "section_"), "set_section_", "get_section_");
	ClassDB::bind_method(D_METHOD("get_jt_"), &COM_SimpleInformation::get_jt_);
	ClassDB::bind_method(D_METHOD("set_jt_", "p_val"), &COM_SimpleInformation::set_jt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "jt_"), "set_jt_", "get_jt_");
	ClassDB::bind_method(D_METHOD("get_jl_"), &COM_SimpleInformation::get_jl_);
	ClassDB::bind_method(D_METHOD("set_jl_", "p_val"), &COM_SimpleInformation::set_jl_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "jl_"), "set_jl_", "get_jl_");
}

void COM_SimpleInformation::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((asset_id_==0)?false:true);
	__fm__.writeBit(instName_.length()?true:false);
	__fm__.writeBit((weaponItemId_==0)?false:true);
	__fm__.writeBit((fashionId_==0)?false:true);
	__fm__.writeBit((section_==0)?false:true);
	__fm__.writeBit(jt_?true:false);
	__fm__.writeBit((jl_==0)?false:true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(asset_id_);
	}
	if(__fm__.readBit()){
		s->writeType(instName_);
	}
	if(__fm__.readBit()){
		s->writeType(weaponItemId_);
	}
	if(__fm__.readBit()){
		s->writeType(fashionId_);
	}
	if(__fm__.readBit()){
		s->writeType(section_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)jt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(jl_);
	}
}

bool COM_SimpleInformation::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(asset_id_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(weaponItemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(fashionId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(section_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		jt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(jl_)) return false;
	}
	return true;
}

void COM_AccountInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_guid_"), &COM_AccountInfo::get_guid_);
	ClassDB::bind_method(D_METHOD("set_guid_", "p_val"), &COM_AccountInfo::set_guid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guid_"), "set_guid_", "get_guid_");
	ClassDB::bind_method(D_METHOD("get_username_"), &COM_AccountInfo::get_username_);
	ClassDB::bind_method(D_METHOD("set_username_", "p_val"), &COM_AccountInfo::set_username_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "username_"), "set_username_", "get_username_");
	ClassDB::bind_method(D_METHOD("get_password_"), &COM_AccountInfo::get_password_);
	ClassDB::bind_method(D_METHOD("set_password_", "p_val"), &COM_AccountInfo::set_password_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "password_"), "set_password_", "get_password_");
	ClassDB::bind_method(D_METHOD("get_createtime_"), &COM_AccountInfo::get_createtime_);
	ClassDB::bind_method(D_METHOD("set_createtime_", "p_val"), &COM_AccountInfo::set_createtime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "createtime_"), "set_createtime_", "get_createtime_");
	ClassDB::bind_method(D_METHOD("get_phoneNumber_"), &COM_AccountInfo::get_phoneNumber_);
	ClassDB::bind_method(D_METHOD("set_phoneNumber_", "p_val"), &COM_AccountInfo::set_phoneNumber_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "phoneNumber_"), "set_phoneNumber_", "get_phoneNumber_");
}

void COM_AccountInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((guid_==0)?false:true);
	__fm__.writeBit(username_.length()?true:false);
	__fm__.writeBit(password_.length()?true:false);
	__fm__.writeBit((createtime_==0)?false:true);
	__fm__.writeBit(phoneNumber_.length()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(guid_);
	}
	if(__fm__.readBit()){
		s->writeType(username_);
	}
	if(__fm__.readBit()){
		s->writeType(password_);
	}
	if(__fm__.readBit()){
		s->writeType(createtime_);
	}
	if(__fm__.readBit()){
		s->writeType(phoneNumber_);
	}
}

bool COM_AccountInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(guid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(username_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(password_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(createtime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(phoneNumber_, 65535)) return false;
	}
	return true;
}

void COM_PropValue::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_PropValue::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_PropValue::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_value_"), &COM_PropValue::get_value_);
	ClassDB::bind_method(D_METHOD("set_value_", "p_val"), &COM_PropValue::set_value_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "value_"), "set_value_", "get_value_");
}

void COM_PropValue::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit((value_==0.0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(value_);
	}
}

bool COM_PropValue::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 63) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(value_)) return false;
	}
	return true;
}

void COM_Item::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_Item::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_Item::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_Item::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_Item::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_stack_"), &COM_Item::get_stack_);
	ClassDB::bind_method(D_METHOD("set_stack_", "p_val"), &COM_Item::set_stack_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "stack_"), "set_stack_", "get_stack_");
	ClassDB::bind_method(D_METHOD("get_isBind_"), &COM_Item::get_isBind_);
	ClassDB::bind_method(D_METHOD("set_isBind_", "p_val"), &COM_Item::set_isBind_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBind_"), "set_isBind_", "get_isBind_");
	ClassDB::bind_method(D_METHOD("get_isLock_"), &COM_Item::get_isLock_);
	ClassDB::bind_method(D_METHOD("set_isLock_", "p_val"), &COM_Item::set_isLock_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLock_"), "set_isLock_", "get_isLock_");
	ClassDB::bind_method(D_METHOD("get_strLevel_"), &COM_Item::get_strLevel_);
	ClassDB::bind_method(D_METHOD("set_strLevel_", "p_val"), &COM_Item::set_strLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "strLevel_"), "set_strLevel_", "get_strLevel_");
	ClassDB::bind_method(D_METHOD("get_slot_"), &COM_Item::get_slot_);
	ClassDB::bind_method(D_METHOD("set_slot_", "p_val"), &COM_Item::set_slot_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "slot_"), "set_slot_", "get_slot_");
	ClassDB::bind_method(D_METHOD("get_skillID_"), &COM_Item::get_skillID_);
	ClassDB::bind_method(D_METHOD("set_skillID_", "p_val"), &COM_Item::set_skillID_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skillID_"), "set_skillID_", "get_skillID_");
	ClassDB::bind_method(D_METHOD("get_durability_"), &COM_Item::get_durability_);
	ClassDB::bind_method(D_METHOD("set_durability_", "p_val"), &COM_Item::set_durability_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "durability_"), "set_durability_", "get_durability_");
	ClassDB::bind_method(D_METHOD("get_durabilityMax_"), &COM_Item::get_durabilityMax_);
	ClassDB::bind_method(D_METHOD("set_durabilityMax_", "p_val"), &COM_Item::set_durabilityMax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "durabilityMax_"), "set_durabilityMax_", "get_durabilityMax_");
	ClassDB::bind_method(D_METHOD("get_usedTimeout_"), &COM_Item::get_usedTimeout_);
	ClassDB::bind_method(D_METHOD("set_usedTimeout_", "p_val"), &COM_Item::set_usedTimeout_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "usedTimeout_"), "set_usedTimeout_", "get_usedTimeout_");
	ClassDB::bind_method(D_METHOD("get_lastSellTime_"), &COM_Item::get_lastSellTime_);
	ClassDB::bind_method(D_METHOD("set_lastSellTime_", "p_val"), &COM_Item::set_lastSellTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "lastSellTime_"), "set_lastSellTime_", "get_lastSellTime_");
	ClassDB::bind_method(D_METHOD("get_propArr"), &COM_Item::get_propArr);
	ClassDB::bind_method(D_METHOD("set_propArr", "p_val"), &COM_Item::set_propArr);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "propArr"), "set_propArr", "get_propArr");
}

void COM_Item::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit((stack_==0)?false:true);
	__fm__.writeBit(isBind_);
	__fm__.writeBit(isLock_);
	__fm__.writeBit((strLevel_==0)?false:true);
	__fm__.writeBit((slot_==0)?false:true);
	__fm__.writeBit((skillID_==0)?false:true);
	__fm__.writeBit((durability_==0)?false:true);
	__fm__.writeBit((durabilityMax_==0)?false:true);
	__fm__.writeBit((usedTimeout_==0)?false:true);
	__fm__.writeBit((lastSellTime_==0)?false:true);
	__fm__.writeBit(propArr.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(stack_);
	}
	if(__fm__.readBit()){
		s->writeType(isBind_);
	}
	if(__fm__.readBit()){
		s->writeType(isLock_);
	}
	if(__fm__.readBit()){
		s->writeType(strLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(slot_);
	}
	if(__fm__.readBit()){
		s->writeType(skillID_);
	}
	if(__fm__.readBit()){
		s->writeType(durability_);
	}
	if(__fm__.readBit()){
		s->writeType(durabilityMax_);
	}
	if(__fm__.readBit()){
		s->writeType(usedTimeout_);
	}
	if(__fm__.readBit()){
		s->writeType(lastSellTime_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)propArr.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_PropValue> __elem = propArr[i];
			if (__elem.is_null()) __elem = memnew(COM_PropValue);
			__elem->serialize(s);
		}
	}
}

bool COM_Item::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(stack_)) return false;
	}
	if(__fm__.readBit()){
		isBind_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isLock_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(strLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(slot_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(skillID_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(durability_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(durabilityMax_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(usedTimeout_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(lastSellTime_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			propArr.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_PropValue> __elem = memnew(COM_PropValue);
				if(!__elem->deserialize(r)) return false;
				propArr[i] = __elem;
			}
		}
	}
	return true;
}

void COM_DropItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_DropItem::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_DropItem::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_itemNum_"), &COM_DropItem::get_itemNum_);
	ClassDB::bind_method(D_METHOD("set_itemNum_", "p_val"), &COM_DropItem::set_itemNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemNum_"), "set_itemNum_", "get_itemNum_");
}

void COM_DropItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((itemNum_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(itemNum_);
	}
}

bool COM_DropItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemNum_)) return false;
	}
	return true;
}

void COM_CrystalProp::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_CrystalProp::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_CrystalProp::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_CrystalProp::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_CrystalProp::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_val_"), &COM_CrystalProp::get_val_);
	ClassDB::bind_method(D_METHOD("set_val_", "p_val"), &COM_CrystalProp::set_val_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "val_"), "set_val_", "get_val_");
}

void COM_CrystalProp::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit((val_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(val_);
	}
}

bool COM_CrystalProp::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 63) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(val_)) return false;
	}
	return true;
}

void COM_CrystalData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_CrystalData::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_CrystalData::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_props_"), &COM_CrystalData::get_props_);
	ClassDB::bind_method(D_METHOD("set_props_", "p_val"), &COM_CrystalData::set_props_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "props_"), "set_props_", "get_props_");
}

void COM_CrystalData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit(props_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)props_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_CrystalProp> __elem = props_[i];
			if (__elem.is_null()) __elem = memnew(COM_CrystalProp);
			__elem->serialize(s);
		}
	}
}

bool COM_CrystalData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			props_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_CrystalProp> __elem = memnew(COM_CrystalProp);
				if(!__elem->deserialize(r)) return false;
				props_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_QuestTarget::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_targetId_"), &COM_QuestTarget::get_targetId_);
	ClassDB::bind_method(D_METHOD("set_targetId_", "p_val"), &COM_QuestTarget::set_targetId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "targetId_"), "set_targetId_", "get_targetId_");
	ClassDB::bind_method(D_METHOD("get_targetNum_"), &COM_QuestTarget::get_targetNum_);
	ClassDB::bind_method(D_METHOD("set_targetNum_", "p_val"), &COM_QuestTarget::set_targetNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "targetNum_"), "set_targetNum_", "get_targetNum_");
}

void COM_QuestTarget::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((targetId_==0)?false:true);
	__fm__.writeBit((targetNum_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(targetId_);
	}
	if(__fm__.readBit()){
		s->writeType(targetNum_);
	}
}

bool COM_QuestTarget::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(targetId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(targetNum_)) return false;
	}
	return true;
}

void COM_Skill::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_skillID_"), &COM_Skill::get_skillID_);
	ClassDB::bind_method(D_METHOD("set_skillID_", "p_val"), &COM_Skill::set_skillID_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skillID_"), "set_skillID_", "get_skillID_");
	ClassDB::bind_method(D_METHOD("get_skillExp_"), &COM_Skill::get_skillExp_);
	ClassDB::bind_method(D_METHOD("set_skillExp_", "p_val"), &COM_Skill::set_skillExp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skillExp_"), "set_skillExp_", "get_skillExp_");
	ClassDB::bind_method(D_METHOD("get_skillLevel_"), &COM_Skill::get_skillLevel_);
	ClassDB::bind_method(D_METHOD("set_skillLevel_", "p_val"), &COM_Skill::set_skillLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skillLevel_"), "set_skillLevel_", "get_skillLevel_");
}

void COM_Skill::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((skillID_==0)?false:true);
	__fm__.writeBit((skillExp_==0)?false:true);
	__fm__.writeBit((skillLevel_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(skillID_);
	}
	if(__fm__.readBit()){
		s->writeType(skillExp_);
	}
	if(__fm__.readBit()){
		s->writeType(skillLevel_);
	}
}

bool COM_Skill::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(skillID_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(skillExp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(skillLevel_)) return false;
	}
	return true;
}

void COM_QuestInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_questId_"), &COM_QuestInst::get_questId_);
	ClassDB::bind_method(D_METHOD("set_questId_", "p_val"), &COM_QuestInst::set_questId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "questId_"), "set_questId_", "get_questId_");
	ClassDB::bind_method(D_METHOD("get_targets_"), &COM_QuestInst::get_targets_);
	ClassDB::bind_method(D_METHOD("set_targets_", "p_val"), &COM_QuestInst::set_targets_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "targets_"), "set_targets_", "get_targets_");
}

void COM_QuestInst::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((questId_==0)?false:true);
	__fm__.writeBit(targets_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(questId_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)targets_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_QuestTarget> __elem = targets_[i];
			if (__elem.is_null()) __elem = memnew(COM_QuestTarget);
			__elem->serialize(s);
		}
	}
}

bool COM_QuestInst::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(questId_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			targets_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_QuestTarget> __elem = memnew(COM_QuestTarget);
				if(!__elem->deserialize(r)) return false;
				targets_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_State::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_stateId_"), &COM_State::get_stateId_);
	ClassDB::bind_method(D_METHOD("set_stateId_", "p_val"), &COM_State::set_stateId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "stateId_"), "set_stateId_", "get_stateId_");
	ClassDB::bind_method(D_METHOD("get_turn_"), &COM_State::get_turn_);
	ClassDB::bind_method(D_METHOD("set_turn_", "p_val"), &COM_State::set_turn_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "turn_"), "set_turn_", "get_turn_");
	ClassDB::bind_method(D_METHOD("get_tick_"), &COM_State::get_tick_);
	ClassDB::bind_method(D_METHOD("set_tick_", "p_val"), &COM_State::set_tick_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "tick_"), "set_tick_", "get_tick_");
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_State::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_State::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_value0_"), &COM_State::get_value0_);
	ClassDB::bind_method(D_METHOD("set_value0_", "p_val"), &COM_State::set_value0_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "value0_"), "set_value0_", "get_value0_");
	ClassDB::bind_method(D_METHOD("get_value1_"), &COM_State::get_value1_);
	ClassDB::bind_method(D_METHOD("set_value1_", "p_val"), &COM_State::set_value1_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "value1_"), "set_value1_", "get_value1_");
}

void COM_State::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((stateId_==0)?false:true);
	__fm__.writeBit((turn_==0)?false:true);
	__fm__.writeBit((tick_==0)?false:true);
	__fm__.writeBit((type_==0)?false:true);
	__fm__.writeBit((value0_==0)?false:true);
	__fm__.writeBit((value1_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(stateId_);
	}
	if(__fm__.readBit()){
		s->writeType(turn_);
	}
	if(__fm__.readBit()){
		s->writeType(tick_);
	}
	if(__fm__.readBit()){
		s->writeType(type_);
	}
	if(__fm__.readBit()){
		s->writeType(value0_);
	}
	if(__fm__.readBit()){
		s->writeType(value1_);
	}
}

bool COM_State::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(stateId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(turn_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(tick_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(type_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(value0_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(value1_)) return false;
	}
	return true;
}

void COM_Entity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_Entity::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_Entity::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_instName_"), &COM_Entity::get_instName_);
	ClassDB::bind_method(D_METHOD("set_instName_", "p_val"), &COM_Entity::set_instName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "instName_"), "set_instName_", "get_instName_");
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_Entity::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_Entity::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_battlePosition_"), &COM_Entity::get_battlePosition_);
	ClassDB::bind_method(D_METHOD("set_battlePosition_", "p_val"), &COM_Entity::set_battlePosition_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "battlePosition_"), "set_battlePosition_", "get_battlePosition_");
	ClassDB::bind_method(D_METHOD("get_properties_"), &COM_Entity::get_properties_);
	ClassDB::bind_method(D_METHOD("set_properties_", "p_val"), &COM_Entity::set_properties_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "properties_"), "set_properties_", "get_properties_");
	ClassDB::bind_method(D_METHOD("get_skill_"), &COM_Entity::get_skill_);
	ClassDB::bind_method(D_METHOD("set_skill_", "p_val"), &COM_Entity::set_skill_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "skill_"), "set_skill_", "get_skill_");
	ClassDB::bind_method(D_METHOD("get_equips_"), &COM_Entity::get_equips_);
	ClassDB::bind_method(D_METHOD("set_equips_", "p_val"), &COM_Entity::set_equips_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "equips_"), "set_equips_", "get_equips_");
	ClassDB::bind_method(D_METHOD("get_states_"), &COM_Entity::get_states_);
	ClassDB::bind_method(D_METHOD("set_states_", "p_val"), &COM_Entity::set_states_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "states_"), "set_states_", "get_states_");
}

void COM_Entity::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit(instName_.length()?true:false);
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit(battlePosition_?true:false);
	__fm__.writeBit(properties_.size()?true:false);
	__fm__.writeBit(skill_.size()?true:false);
	__fm__.writeBit(equips_.size()?true:false);
	__fm__.writeBit(states_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(instName_);
	}
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)battlePosition_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)properties_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			float __tmp = properties_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)skill_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Skill> __elem = skill_[i];
			if (__elem.is_null()) __elem = memnew(COM_Skill);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)equips_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Item> __elem = equips_[i];
			if (__elem.is_null()) __elem = memnew(COM_Item);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)states_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_State> __elem = states_[i];
			if (__elem.is_null()) __elem = memnew(COM_State);
			__elem->serialize(s);
		}
	}
}

bool COM_Entity::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 7) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(instName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 22) return false;
		battlePosition_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			properties_.resize(__len);
			for(int i=0; i<__len; ++i) {
				float __tmp;
				if(!r->readType(__tmp)) return false;
				properties_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			skill_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Skill> __elem = memnew(COM_Skill);
				if(!__elem->deserialize(r)) return false;
				skill_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			equips_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				equips_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			states_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_State> __elem = memnew(COM_State);
				if(!__elem->deserialize(r)) return false;
				states_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_BabyInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_ownerName_"), &COM_BabyInst::get_ownerName_);
	ClassDB::bind_method(D_METHOD("set_ownerName_", "p_val"), &COM_BabyInst::set_ownerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "ownerName_"), "set_ownerName_", "get_ownerName_");
	ClassDB::bind_method(D_METHOD("get_isShow_"), &COM_BabyInst::get_isShow_);
	ClassDB::bind_method(D_METHOD("set_isShow_", "p_val"), &COM_BabyInst::set_isShow_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isShow_"), "set_isShow_", "get_isShow_");
	ClassDB::bind_method(D_METHOD("get_isBattle_"), &COM_BabyInst::get_isBattle_);
	ClassDB::bind_method(D_METHOD("set_isBattle_", "p_val"), &COM_BabyInst::set_isBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBattle_"), "set_isBattle_", "get_isBattle_");
	ClassDB::bind_method(D_METHOD("get_isBind_"), &COM_BabyInst::get_isBind_);
	ClassDB::bind_method(D_METHOD("set_isBind_", "p_val"), &COM_BabyInst::set_isBind_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBind_"), "set_isBind_", "get_isBind_");
	ClassDB::bind_method(D_METHOD("get_isLock_"), &COM_BabyInst::get_isLock_);
	ClassDB::bind_method(D_METHOD("set_isLock_", "p_val"), &COM_BabyInst::set_isLock_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLock_"), "set_isLock_", "get_isLock_");
	ClassDB::bind_method(D_METHOD("get_tableId_"), &COM_BabyInst::get_tableId_);
	ClassDB::bind_method(D_METHOD("set_tableId_", "p_val"), &COM_BabyInst::set_tableId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "tableId_"), "set_tableId_", "get_tableId_");
	ClassDB::bind_method(D_METHOD("get_slot_"), &COM_BabyInst::get_slot_);
	ClassDB::bind_method(D_METHOD("set_slot_", "p_val"), &COM_BabyInst::set_slot_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "slot_"), "set_slot_", "get_slot_");
	ClassDB::bind_method(D_METHOD("get_intensifyLevel_"), &COM_BabyInst::get_intensifyLevel_);
	ClassDB::bind_method(D_METHOD("set_intensifyLevel_", "p_val"), &COM_BabyInst::set_intensifyLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "intensifyLevel_"), "set_intensifyLevel_", "get_intensifyLevel_");
	ClassDB::bind_method(D_METHOD("get_intensifynum_"), &COM_BabyInst::get_intensifynum_);
	ClassDB::bind_method(D_METHOD("set_intensifynum_", "p_val"), &COM_BabyInst::set_intensifynum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "intensifynum_"), "set_intensifynum_", "get_intensifynum_");
	ClassDB::bind_method(D_METHOD("get_lastSellTime_"), &COM_BabyInst::get_lastSellTime_);
	ClassDB::bind_method(D_METHOD("set_lastSellTime_", "p_val"), &COM_BabyInst::set_lastSellTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "lastSellTime_"), "set_lastSellTime_", "get_lastSellTime_");
	ClassDB::bind_method(D_METHOD("get_gear_"), &COM_BabyInst::get_gear_);
	ClassDB::bind_method(D_METHOD("set_gear_", "p_val"), &COM_BabyInst::set_gear_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "gear_"), "set_gear_", "get_gear_");
	ClassDB::bind_method(D_METHOD("get_addprop_"), &COM_BabyInst::get_addprop_);
	ClassDB::bind_method(D_METHOD("set_addprop_", "p_val"), &COM_BabyInst::set_addprop_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "addprop_"), "set_addprop_", "get_addprop_");
}

void COM_BabyInst::serialize(ProtocolWriter* s) const {
	COM_Entity::serialize(s);
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(ownerName_.length()?true:false);
	__fm__.writeBit(isShow_);
	__fm__.writeBit(isBattle_);
	__fm__.writeBit(isBind_);
	__fm__.writeBit(isLock_);
	__fm__.writeBit((tableId_==0)?false:true);
	__fm__.writeBit((slot_==0)?false:true);
	__fm__.writeBit((intensifyLevel_==0)?false:true);
	__fm__.writeBit((intensifynum_==0)?false:true);
	__fm__.writeBit((lastSellTime_==0)?false:true);
	__fm__.writeBit(gear_.size()?true:false);
	__fm__.writeBit(addprop_.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(ownerName_);
	}
	if(__fm__.readBit()){
		s->writeType(isShow_);
	}
	if(__fm__.readBit()){
		s->writeType(isBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(isBind_);
	}
	if(__fm__.readBit()){
		s->writeType(isLock_);
	}
	if(__fm__.readBit()){
		s->writeType(tableId_);
	}
	if(__fm__.readBit()){
		s->writeType(slot_);
	}
	if(__fm__.readBit()){
		s->writeType(intensifyLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(intensifynum_);
	}
	if(__fm__.readBit()){
		s->writeType(lastSellTime_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)gear_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = gear_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)addprop_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			float __tmp = addprop_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_BabyInst::deserialize(ProtocolReader* r) {
	if(!COM_Entity::deserialize(r)) return false;
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(ownerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		isShow_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isBind_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isLock_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(tableId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(slot_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(intensifyLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(intensifynum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(lastSellTime_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			gear_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				gear_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			addprop_.resize(__len);
			for(int i=0; i<__len; ++i) {
				float __tmp;
				if(!r->readType(__tmp)) return false;
				addprop_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_EmployeeInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_ownerName_"), &COM_EmployeeInst::get_ownerName_);
	ClassDB::bind_method(D_METHOD("set_ownerName_", "p_val"), &COM_EmployeeInst::set_ownerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "ownerName_"), "set_ownerName_", "get_ownerName_");
	ClassDB::bind_method(D_METHOD("get_isBattle_"), &COM_EmployeeInst::get_isBattle_);
	ClassDB::bind_method(D_METHOD("set_isBattle_", "p_val"), &COM_EmployeeInst::set_isBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBattle_"), "set_isBattle_", "get_isBattle_");
	ClassDB::bind_method(D_METHOD("get_weaponId_"), &COM_EmployeeInst::get_weaponId_);
	ClassDB::bind_method(D_METHOD("set_weaponId_", "p_val"), &COM_EmployeeInst::set_weaponId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "weaponId_"), "set_weaponId_", "get_weaponId_");
	ClassDB::bind_method(D_METHOD("get_quality_"), &COM_EmployeeInst::get_quality_);
	ClassDB::bind_method(D_METHOD("set_quality_", "p_val"), &COM_EmployeeInst::set_quality_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "quality_"), "set_quality_", "get_quality_");
	ClassDB::bind_method(D_METHOD("get_star_"), &COM_EmployeeInst::get_star_);
	ClassDB::bind_method(D_METHOD("set_star_", "p_val"), &COM_EmployeeInst::set_star_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "star_"), "set_star_", "get_star_");
	ClassDB::bind_method(D_METHOD("get_soul_"), &COM_EmployeeInst::get_soul_);
	ClassDB::bind_method(D_METHOD("set_soul_", "p_val"), &COM_EmployeeInst::set_soul_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "soul_"), "set_soul_", "get_soul_");
}

void COM_EmployeeInst::serialize(ProtocolWriter* s) const {
	COM_Entity::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(ownerName_.length()?true:false);
	__fm__.writeBit(isBattle_);
	__fm__.writeBit((weaponId_==0)?false:true);
	__fm__.writeBit(quality_?true:false);
	__fm__.writeBit((star_==0)?false:true);
	__fm__.writeBit((soul_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(ownerName_);
	}
	if(__fm__.readBit()){
		s->writeType(isBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(weaponId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)quality_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(star_);
	}
	if(__fm__.readBit()){
		s->writeType(soul_);
	}
}

bool COM_EmployeeInst::deserialize(ProtocolReader* r) {
	if(!COM_Entity::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(ownerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		isBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(weaponId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 16) return false;
		quality_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(star_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(soul_)) return false;
	}
	return true;
}

void COM_ContactInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_ContactInfo::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_ContactInfo::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_name_"), &COM_ContactInfo::get_name_);
	ClassDB::bind_method(D_METHOD("set_name_", "p_val"), &COM_ContactInfo::set_name_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name_"), "set_name_", "get_name_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_ContactInfo::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_ContactInfo::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_exp_"), &COM_ContactInfo::get_exp_);
	ClassDB::bind_method(D_METHOD("set_exp_", "p_val"), &COM_ContactInfo::set_exp_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "exp_"), "set_exp_", "get_exp_");
	ClassDB::bind_method(D_METHOD("get_job_"), &COM_ContactInfo::get_job_);
	ClassDB::bind_method(D_METHOD("set_job_", "p_val"), &COM_ContactInfo::set_job_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "job_"), "set_job_", "get_job_");
	ClassDB::bind_method(D_METHOD("get_assetId_"), &COM_ContactInfo::get_assetId_);
	ClassDB::bind_method(D_METHOD("set_assetId_", "p_val"), &COM_ContactInfo::set_assetId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "assetId_"), "set_assetId_", "get_assetId_");
	ClassDB::bind_method(D_METHOD("get_jobLevel_"), &COM_ContactInfo::get_jobLevel_);
	ClassDB::bind_method(D_METHOD("set_jobLevel_", "p_val"), &COM_ContactInfo::set_jobLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "jobLevel_"), "set_jobLevel_", "get_jobLevel_");
	ClassDB::bind_method(D_METHOD("get_vip_"), &COM_ContactInfo::get_vip_);
	ClassDB::bind_method(D_METHOD("set_vip_", "p_val"), &COM_ContactInfo::set_vip_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "vip_"), "set_vip_", "get_vip_");
	ClassDB::bind_method(D_METHOD("get_ff_"), &COM_ContactInfo::get_ff_);
	ClassDB::bind_method(D_METHOD("set_ff_", "p_val"), &COM_ContactInfo::set_ff_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ff_"), "set_ff_", "get_ff_");
	ClassDB::bind_method(D_METHOD("get_rank_"), &COM_ContactInfo::get_rank_);
	ClassDB::bind_method(D_METHOD("set_rank_", "p_val"), &COM_ContactInfo::set_rank_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rank_"), "set_rank_", "get_rank_");
	ClassDB::bind_method(D_METHOD("get_section_"), &COM_ContactInfo::get_section_);
	ClassDB::bind_method(D_METHOD("set_section_", "p_val"), &COM_ContactInfo::set_section_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "section_"), "set_section_", "get_section_");
	ClassDB::bind_method(D_METHOD("get_value_"), &COM_ContactInfo::get_value_);
	ClassDB::bind_method(D_METHOD("set_value_", "p_val"), &COM_ContactInfo::set_value_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "value_"), "set_value_", "get_value_");
	ClassDB::bind_method(D_METHOD("get_isLine_"), &COM_ContactInfo::get_isLine_);
	ClassDB::bind_method(D_METHOD("set_isLine_", "p_val"), &COM_ContactInfo::set_isLine_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLine_"), "set_isLine_", "get_isLine_");
}

void COM_ContactInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit(name_.length()?true:false);
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((exp_==0.0)?false:true);
	__fm__.writeBit(job_?true:false);
	__fm__.writeBit((assetId_==0)?false:true);
	__fm__.writeBit((jobLevel_==0)?false:true);
	__fm__.writeBit(vip_?true:false);
	__fm__.writeBit((ff_==0)?false:true);
	__fm__.writeBit((rank_==0)?false:true);
	__fm__.writeBit((section_==0)?false:true);
	__fm__.writeBit((value_==0)?false:true);
	__fm__.writeBit(isLine_);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(name_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(exp_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)job_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(assetId_);
	}
	if(__fm__.readBit()){
		s->writeType(jobLevel_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)vip_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(ff_);
	}
	if(__fm__.readBit()){
		s->writeType(rank_);
	}
	if(__fm__.readBit()){
		s->writeType(section_);
	}
	if(__fm__.readBit()){
		s->writeType(value_);
	}
	if(__fm__.readBit()){
		s->writeType(isLine_);
	}
}

bool COM_ContactInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(name_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(exp_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		job_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(assetId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(jobLevel_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 4) return false;
		vip_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(ff_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rank_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(section_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(value_)) return false;
	}
	if(__fm__.readBit()){
		isLine_ = __fm__.readBit();
	}
	return true;
}

void SGE_ContactInfoExt::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_rolefirst_"), &SGE_ContactInfoExt::get_rolefirst_);
	ClassDB::bind_method(D_METHOD("set_rolefirst_", "p_val"), &SGE_ContactInfoExt::set_rolefirst_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolefirst_"), "set_rolefirst_", "get_rolefirst_");
	ClassDB::bind_method(D_METHOD("get_rolelast_"), &SGE_ContactInfoExt::get_rolelast_);
	ClassDB::bind_method(D_METHOD("set_rolelast_", "p_val"), &SGE_ContactInfoExt::set_rolelast_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolelast_"), "set_rolelast_", "get_rolelast_");
	ClassDB::bind_method(D_METHOD("get_logoutTime_"), &SGE_ContactInfoExt::get_logoutTime_);
	ClassDB::bind_method(D_METHOD("set_logoutTime_", "p_val"), &SGE_ContactInfoExt::set_logoutTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "logoutTime_"), "set_logoutTime_", "get_logoutTime_");
	ClassDB::bind_method(D_METHOD("get_gold_"), &SGE_ContactInfoExt::get_gold_);
	ClassDB::bind_method(D_METHOD("set_gold_", "p_val"), &SGE_ContactInfoExt::set_gold_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "gold_"), "set_gold_", "get_gold_");
	ClassDB::bind_method(D_METHOD("get_diamond_"), &SGE_ContactInfoExt::get_diamond_);
	ClassDB::bind_method(D_METHOD("set_diamond_", "p_val"), &SGE_ContactInfoExt::set_diamond_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "diamond_"), "set_diamond_", "get_diamond_");
	ClassDB::bind_method(D_METHOD("get_magicgold_"), &SGE_ContactInfoExt::get_magicgold_);
	ClassDB::bind_method(D_METHOD("set_magicgold_", "p_val"), &SGE_ContactInfoExt::set_magicgold_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicgold_"), "set_magicgold_", "get_magicgold_");
	ClassDB::bind_method(D_METHOD("get_guildContribute_"), &SGE_ContactInfoExt::get_guildContribute_);
	ClassDB::bind_method(D_METHOD("set_guildContribute_", "p_val"), &SGE_ContactInfoExt::set_guildContribute_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildContribute_"), "set_guildContribute_", "get_guildContribute_");
	ClassDB::bind_method(D_METHOD("get_accName_"), &SGE_ContactInfoExt::get_accName_);
	ClassDB::bind_method(D_METHOD("set_accName_", "p_val"), &SGE_ContactInfoExt::set_accName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "accName_"), "set_accName_", "get_accName_");
	ClassDB::bind_method(D_METHOD("get_userid_"), &SGE_ContactInfoExt::get_userid_);
	ClassDB::bind_method(D_METHOD("set_userid_", "p_val"), &SGE_ContactInfoExt::set_userid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "userid_"), "set_userid_", "get_userid_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &SGE_ContactInfoExt::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &SGE_ContactInfoExt::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_pfname_"), &SGE_ContactInfoExt::get_pfname_);
	ClassDB::bind_method(D_METHOD("set_pfname_", "p_val"), &SGE_ContactInfoExt::set_pfname_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfname_"), "set_pfname_", "get_pfname_");
	ClassDB::bind_method(D_METHOD("get_serverid_"), &SGE_ContactInfoExt::get_serverid_);
	ClassDB::bind_method(D_METHOD("set_serverid_", "p_val"), &SGE_ContactInfoExt::set_serverid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "serverid_"), "set_serverid_", "get_serverid_");
}

void SGE_ContactInfoExt::serialize(ProtocolWriter* s) const {
	COM_ContactInfo::serialize(s);
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((rolefirst_==0)?false:true);
	__fm__.writeBit((rolelast_==0)?false:true);
	__fm__.writeBit((logoutTime_==0)?false:true);
	__fm__.writeBit((gold_==0)?false:true);
	__fm__.writeBit((diamond_==0)?false:true);
	__fm__.writeBit((magicgold_==0)?false:true);
	__fm__.writeBit((guildContribute_==0)?false:true);
	__fm__.writeBit(accName_.length()?true:false);
	__fm__.writeBit(userid_.length()?true:false);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit(pfname_.length()?true:false);
	__fm__.writeBit((serverid_==0)?false:true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(rolefirst_);
	}
	if(__fm__.readBit()){
		s->writeType(rolelast_);
	}
	if(__fm__.readBit()){
		s->writeType(logoutTime_);
	}
	if(__fm__.readBit()){
		s->writeType(gold_);
	}
	if(__fm__.readBit()){
		s->writeType(diamond_);
	}
	if(__fm__.readBit()){
		s->writeType(magicgold_);
	}
	if(__fm__.readBit()){
		s->writeType(guildContribute_);
	}
	if(__fm__.readBit()){
		s->writeType(accName_);
	}
	if(__fm__.readBit()){
		s->writeType(userid_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(pfname_);
	}
	if(__fm__.readBit()){
		s->writeType(serverid_);
	}
}

bool SGE_ContactInfoExt::deserialize(ProtocolReader* r) {
	if(!COM_ContactInfo::deserialize(r)) return false;
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(rolefirst_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rolelast_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(logoutTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(gold_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(diamond_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(magicgold_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildContribute_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(userid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfname_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(serverid_)) return false;
	}
	return true;
}

void COM_Achievement::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_achId_"), &COM_Achievement::get_achId_);
	ClassDB::bind_method(D_METHOD("set_achId_", "p_val"), &COM_Achievement::set_achId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "achId_"), "set_achId_", "get_achId_");
	ClassDB::bind_method(D_METHOD("get_achType_"), &COM_Achievement::get_achType_);
	ClassDB::bind_method(D_METHOD("set_achType_", "p_val"), &COM_Achievement::set_achType_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "achType_"), "set_achType_", "get_achType_");
	ClassDB::bind_method(D_METHOD("get_achValue_"), &COM_Achievement::get_achValue_);
	ClassDB::bind_method(D_METHOD("set_achValue_", "p_val"), &COM_Achievement::set_achValue_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "achValue_"), "set_achValue_", "get_achValue_");
	ClassDB::bind_method(D_METHOD("get_isAch_"), &COM_Achievement::get_isAch_);
	ClassDB::bind_method(D_METHOD("set_isAch_", "p_val"), &COM_Achievement::set_isAch_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isAch_"), "set_isAch_", "get_isAch_");
	ClassDB::bind_method(D_METHOD("get_isAward_"), &COM_Achievement::get_isAward_);
	ClassDB::bind_method(D_METHOD("set_isAward_", "p_val"), &COM_Achievement::set_isAward_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isAward_"), "set_isAward_", "get_isAward_");
}

void COM_Achievement::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((achId_==0)?false:true);
	__fm__.writeBit(achType_?true:false);
	__fm__.writeBit((achValue_==0)?false:true);
	__fm__.writeBit(isAch_);
	__fm__.writeBit(isAward_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(achId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)achType_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(achValue_);
	}
	if(__fm__.readBit()){
		s->writeType(isAch_);
	}
	if(__fm__.readBit()){
		s->writeType(isAward_);
	}
}

bool COM_Achievement::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(achId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 60) return false;
		achType_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(achValue_)) return false;
	}
	if(__fm__.readBit()){
		isAch_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isAward_ = __fm__.readBit();
	}
	return true;
}

void COM_HundredBattle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerId_"), &COM_HundredBattle::get_playerId_);
	ClassDB::bind_method(D_METHOD("set_playerId_", "p_val"), &COM_HundredBattle::set_playerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerId_"), "set_playerId_", "get_playerId_");
	ClassDB::bind_method(D_METHOD("get_tier_"), &COM_HundredBattle::get_tier_);
	ClassDB::bind_method(D_METHOD("set_tier_", "p_val"), &COM_HundredBattle::set_tier_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "tier_"), "set_tier_", "get_tier_");
	ClassDB::bind_method(D_METHOD("get_curTier_"), &COM_HundredBattle::get_curTier_);
	ClassDB::bind_method(D_METHOD("set_curTier_", "p_val"), &COM_HundredBattle::set_curTier_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "curTier_"), "set_curTier_", "get_curTier_");
	ClassDB::bind_method(D_METHOD("get_surplus_"), &COM_HundredBattle::get_surplus_);
	ClassDB::bind_method(D_METHOD("set_surplus_", "p_val"), &COM_HundredBattle::set_surplus_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "surplus_"), "set_surplus_", "get_surplus_");
	ClassDB::bind_method(D_METHOD("get_resetNum_"), &COM_HundredBattle::get_resetNum_);
	ClassDB::bind_method(D_METHOD("set_resetNum_", "p_val"), &COM_HundredBattle::set_resetNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "resetNum_"), "set_resetNum_", "get_resetNum_");
}

void COM_HundredBattle::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((playerId_==0)?false:true);
	__fm__.writeBit((tier_==0)?false:true);
	__fm__.writeBit((curTier_==0)?false:true);
	__fm__.writeBit((surplus_==0)?false:true);
	__fm__.writeBit((resetNum_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerId_);
	}
	if(__fm__.readBit()){
		s->writeType(tier_);
	}
	if(__fm__.readBit()){
		s->writeType(curTier_);
	}
	if(__fm__.readBit()){
		s->writeType(surplus_);
	}
	if(__fm__.readBit()){
		s->writeType(resetNum_);
	}
}

bool COM_HundredBattle::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(tier_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(curTier_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(surplus_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(resetNum_)) return false;
	}
	return true;
}

void COM_PlayerVsPlayer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerInst_"), &COM_PlayerVsPlayer::get_playerInst_);
	ClassDB::bind_method(D_METHOD("set_playerInst_", "p_val"), &COM_PlayerVsPlayer::set_playerInst_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerInst_"), "set_playerInst_", "get_playerInst_");
	ClassDB::bind_method(D_METHOD("get_section_"), &COM_PlayerVsPlayer::get_section_);
	ClassDB::bind_method(D_METHOD("set_section_", "p_val"), &COM_PlayerVsPlayer::set_section_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "section_"), "set_section_", "get_section_");
	ClassDB::bind_method(D_METHOD("get_value_"), &COM_PlayerVsPlayer::get_value_);
	ClassDB::bind_method(D_METHOD("set_value_", "p_val"), &COM_PlayerVsPlayer::set_value_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "value_"), "set_value_", "get_value_");
	ClassDB::bind_method(D_METHOD("get_winNum_"), &COM_PlayerVsPlayer::get_winNum_);
	ClassDB::bind_method(D_METHOD("set_winNum_", "p_val"), &COM_PlayerVsPlayer::set_winNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "winNum_"), "set_winNum_", "get_winNum_");
	ClassDB::bind_method(D_METHOD("get_battleNum_"), &COM_PlayerVsPlayer::get_battleNum_);
	ClassDB::bind_method(D_METHOD("set_battleNum_", "p_val"), &COM_PlayerVsPlayer::set_battleNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "battleNum_"), "set_battleNum_", "get_battleNum_");
	ClassDB::bind_method(D_METHOD("get_winValue_"), &COM_PlayerVsPlayer::get_winValue_);
	ClassDB::bind_method(D_METHOD("set_winValue_", "p_val"), &COM_PlayerVsPlayer::set_winValue_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "winValue_"), "set_winValue_", "get_winValue_");
	ClassDB::bind_method(D_METHOD("get_contWin_"), &COM_PlayerVsPlayer::get_contWin_);
	ClassDB::bind_method(D_METHOD("set_contWin_", "p_val"), &COM_PlayerVsPlayer::set_contWin_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "contWin_"), "set_contWin_", "get_contWin_");
	ClassDB::bind_method(D_METHOD("get_isCont_"), &COM_PlayerVsPlayer::get_isCont_);
	ClassDB::bind_method(D_METHOD("set_isCont_", "p_val"), &COM_PlayerVsPlayer::set_isCont_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isCont_"), "set_isCont_", "get_isCont_");
}

void COM_PlayerVsPlayer::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((playerInst_==0)?false:true);
	__fm__.writeBit((section_==0)?false:true);
	__fm__.writeBit((value_==0)?false:true);
	__fm__.writeBit((winNum_==0)?false:true);
	__fm__.writeBit((battleNum_==0)?false:true);
	__fm__.writeBit((winValue_==0.0)?false:true);
	__fm__.writeBit((contWin_==0)?false:true);
	__fm__.writeBit(isCont_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerInst_);
	}
	if(__fm__.readBit()){
		s->writeType(section_);
	}
	if(__fm__.readBit()){
		s->writeType(value_);
	}
	if(__fm__.readBit()){
		s->writeType(winNum_);
	}
	if(__fm__.readBit()){
		s->writeType(battleNum_);
	}
	if(__fm__.readBit()){
		s->writeType(winValue_);
	}
	if(__fm__.readBit()){
		s->writeType(contWin_);
	}
	if(__fm__.readBit()){
		s->writeType(isCont_);
	}
}

bool COM_PlayerVsPlayer::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerInst_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(section_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(value_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(winNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(battleNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(winValue_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(contWin_)) return false;
	}
	if(__fm__.readBit()){
		isCont_ = __fm__.readBit();
	}
	return true;
}

void COM_Activity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_actId_"), &COM_Activity::get_actId_);
	ClassDB::bind_method(D_METHOD("set_actId_", "p_val"), &COM_Activity::set_actId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "actId_"), "set_actId_", "get_actId_");
	ClassDB::bind_method(D_METHOD("get_counter_"), &COM_Activity::get_counter_);
	ClassDB::bind_method(D_METHOD("set_counter_", "p_val"), &COM_Activity::set_counter_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "counter_"), "set_counter_", "get_counter_");
}

void COM_Activity::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((actId_==0)?false:true);
	__fm__.writeBit((counter_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(actId_);
	}
	if(__fm__.readBit()){
		s->writeType(counter_);
	}
}

bool COM_Activity::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(actId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(counter_)) return false;
	}
	return true;
}

void COM_ActivityTable::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_activities_"), &COM_ActivityTable::get_activities_);
	ClassDB::bind_method(D_METHOD("set_activities_", "p_val"), &COM_ActivityTable::set_activities_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "activities_"), "set_activities_", "get_activities_");
	ClassDB::bind_method(D_METHOD("get_flag_"), &COM_ActivityTable::get_flag_);
	ClassDB::bind_method(D_METHOD("set_flag_", "p_val"), &COM_ActivityTable::set_flag_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "flag_"), "set_flag_", "get_flag_");
	ClassDB::bind_method(D_METHOD("get_reward_"), &COM_ActivityTable::get_reward_);
	ClassDB::bind_method(D_METHOD("set_reward_", "p_val"), &COM_ActivityTable::set_reward_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "reward_"), "set_reward_", "get_reward_");
}

void COM_ActivityTable::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(activities_.size()?true:false);
	__fm__.writeBit(flag_.size()?true:false);
	__fm__.writeBit((reward_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)activities_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Activity> __elem = activities_[i];
			if (__elem.is_null()) __elem = memnew(COM_Activity);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)flag_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = flag_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(reward_);
	}
}

bool COM_ActivityTable::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			activities_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Activity> __elem = memnew(COM_Activity);
				if(!__elem->deserialize(r)) return false;
				activities_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			flag_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				flag_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(reward_)) return false;
	}
	return true;
}

void COM_CourseGift::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_id_"), &COM_CourseGift::get_id_);
	ClassDB::bind_method(D_METHOD("set_id_", "p_val"), &COM_CourseGift::set_id_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "id_"), "set_id_", "get_id_");
	ClassDB::bind_method(D_METHOD("get_timeout_"), &COM_CourseGift::get_timeout_);
	ClassDB::bind_method(D_METHOD("set_timeout_", "p_val"), &COM_CourseGift::set_timeout_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "timeout_"), "set_timeout_", "get_timeout_");
}

void COM_CourseGift::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((id_==0)?false:true);
	__fm__.writeBit((timeout_==0.0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(id_);
	}
	if(__fm__.readBit()){
		s->writeType(timeout_);
	}
}

bool COM_CourseGift::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(id_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(timeout_)) return false;
	}
	return true;
}

void COM_SimplePlayerInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_isLeavingTeam_"), &COM_SimplePlayerInst::get_isLeavingTeam_);
	ClassDB::bind_method(D_METHOD("set_isLeavingTeam_", "p_val"), &COM_SimplePlayerInst::set_isLeavingTeam_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLeavingTeam_"), "set_isLeavingTeam_", "get_isLeavingTeam_");
	ClassDB::bind_method(D_METHOD("get_isBattle_"), &COM_SimplePlayerInst::get_isBattle_);
	ClassDB::bind_method(D_METHOD("set_isBattle_", "p_val"), &COM_SimplePlayerInst::set_isBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBattle_"), "set_isBattle_", "get_isBattle_");
	ClassDB::bind_method(D_METHOD("get_autoBattle_"), &COM_SimplePlayerInst::get_autoBattle_);
	ClassDB::bind_method(D_METHOD("set_autoBattle_", "p_val"), &COM_SimplePlayerInst::set_autoBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "autoBattle_"), "set_autoBattle_", "get_autoBattle_");
	ClassDB::bind_method(D_METHOD("get_isTeamLeader_"), &COM_SimplePlayerInst::get_isTeamLeader_);
	ClassDB::bind_method(D_METHOD("set_isTeamLeader_", "p_val"), &COM_SimplePlayerInst::set_isTeamLeader_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isTeamLeader_"), "set_isTeamLeader_", "get_isTeamLeader_");
	ClassDB::bind_method(D_METHOD("get_sceneId_"), &COM_SimplePlayerInst::get_sceneId_);
	ClassDB::bind_method(D_METHOD("set_sceneId_", "p_val"), &COM_SimplePlayerInst::set_sceneId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sceneId_"), "set_sceneId_", "get_sceneId_");
	ClassDB::bind_method(D_METHOD("get_openSubSystemFlag_"), &COM_SimplePlayerInst::get_openSubSystemFlag_);
	ClassDB::bind_method(D_METHOD("set_openSubSystemFlag_", "p_val"), &COM_SimplePlayerInst::set_openSubSystemFlag_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "openSubSystemFlag_"), "set_openSubSystemFlag_", "get_openSubSystemFlag_");
	ClassDB::bind_method(D_METHOD("get_createTime_"), &COM_SimplePlayerInst::get_createTime_);
	ClassDB::bind_method(D_METHOD("set_createTime_", "p_val"), &COM_SimplePlayerInst::set_createTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "createTime_"), "set_createTime_", "get_createTime_");
	ClassDB::bind_method(D_METHOD("get_guildName_"), &COM_SimplePlayerInst::get_guildName_);
	ClassDB::bind_method(D_METHOD("set_guildName_", "p_val"), &COM_SimplePlayerInst::set_guildName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "guildName_"), "set_guildName_", "get_guildName_");
	ClassDB::bind_method(D_METHOD("get_scenePos_"), &COM_SimplePlayerInst::get_scenePos_);
	ClassDB::bind_method(D_METHOD("set_scenePos_", "p_val"), &COM_SimplePlayerInst::set_scenePos_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "scenePos_"), "set_scenePos_", "get_scenePos_");
	ClassDB::bind_method(D_METHOD("get_pvpInfo_"), &COM_SimplePlayerInst::get_pvpInfo_);
	ClassDB::bind_method(D_METHOD("set_pvpInfo_", "p_val"), &COM_SimplePlayerInst::set_pvpInfo_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "pvpInfo_"), "set_pvpInfo_", "get_pvpInfo_");
	ClassDB::bind_method(D_METHOD("get_babies1_"), &COM_SimplePlayerInst::get_babies1_);
	ClassDB::bind_method(D_METHOD("set_babies1_", "p_val"), &COM_SimplePlayerInst::set_babies1_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "babies1_"), "set_babies1_", "get_babies1_");
	ClassDB::bind_method(D_METHOD("get_battleEmps_"), &COM_SimplePlayerInst::get_battleEmps_);
	ClassDB::bind_method(D_METHOD("set_battleEmps_", "p_val"), &COM_SimplePlayerInst::set_battleEmps_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "battleEmps_"), "set_battleEmps_", "get_battleEmps_");
}

void COM_SimplePlayerInst::serialize(ProtocolWriter* s) const {
	COM_Entity::serialize(s);
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(isLeavingTeam_);
	__fm__.writeBit(isBattle_);
	__fm__.writeBit(autoBattle_);
	__fm__.writeBit(isTeamLeader_);
	__fm__.writeBit((sceneId_==0)?false:true);
	__fm__.writeBit((openSubSystemFlag_==0)?false:true);
	__fm__.writeBit((createTime_==0)?false:true);
	__fm__.writeBit(guildName_.length()?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(babies1_.size()?true:false);
	__fm__.writeBit(battleEmps_.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(isLeavingTeam_);
	}
	if(__fm__.readBit()){
		s->writeType(isBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(autoBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(isTeamLeader_);
	}
	if(__fm__.readBit()){
		s->writeType(sceneId_);
	}
	if(__fm__.readBit()){
		s->writeType(openSubSystemFlag_);
	}
	if(__fm__.readBit()){
		s->writeType(createTime_);
	}
	if(__fm__.readBit()){
		s->writeType(guildName_);
	}
	if(__fm__.readBit()){
		if (scenePos_.is_null()) const_cast<Ref<COM_FPosition>&>(scenePos_) = memnew(COM_FPosition);
		scenePos_->serialize(s);
	}
	if(__fm__.readBit()){
		if (pvpInfo_.is_null()) const_cast<Ref<COM_PlayerVsPlayer>&>(pvpInfo_) = memnew(COM_PlayerVsPlayer);
		pvpInfo_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)babies1_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_BabyInst> __elem = babies1_[i];
			if (__elem.is_null()) __elem = memnew(COM_BabyInst);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)battleEmps_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_EmployeeInst> __elem = battleEmps_[i];
			if (__elem.is_null()) __elem = memnew(COM_EmployeeInst);
			__elem->serialize(s);
		}
	}
}

bool COM_SimplePlayerInst::deserialize(ProtocolReader* r) {
	if(!COM_Entity::deserialize(r)) return false;
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		isLeavingTeam_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		autoBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isTeamLeader_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(sceneId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(openSubSystemFlag_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(createTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if (scenePos_.is_null()) const_cast<Ref<COM_FPosition>&>(scenePos_) = memnew(COM_FPosition);
		if(!scenePos_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (pvpInfo_.is_null()) const_cast<Ref<COM_PlayerVsPlayer>&>(pvpInfo_) = memnew(COM_PlayerVsPlayer);
		if(!pvpInfo_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			babies1_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyInst> __elem = memnew(COM_BabyInst);
				if(!__elem->deserialize(r)) return false;
				babies1_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			battleEmps_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EmployeeInst> __elem = memnew(COM_EmployeeInst);
				if(!__elem->deserialize(r)) return false;
				battleEmps_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_PlayerInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_isLeavingTeam_"), &COM_PlayerInst::get_isLeavingTeam_);
	ClassDB::bind_method(D_METHOD("set_isLeavingTeam_", "p_val"), &COM_PlayerInst::set_isLeavingTeam_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isLeavingTeam_"), "set_isLeavingTeam_", "get_isLeavingTeam_");
	ClassDB::bind_method(D_METHOD("get_isBattle_"), &COM_PlayerInst::get_isBattle_);
	ClassDB::bind_method(D_METHOD("set_isBattle_", "p_val"), &COM_PlayerInst::set_isBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBattle_"), "set_isBattle_", "get_isBattle_");
	ClassDB::bind_method(D_METHOD("get_autoBattle_"), &COM_PlayerInst::get_autoBattle_);
	ClassDB::bind_method(D_METHOD("set_autoBattle_", "p_val"), &COM_PlayerInst::set_autoBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "autoBattle_"), "set_autoBattle_", "get_autoBattle_");
	ClassDB::bind_method(D_METHOD("get_isTeamLeader_"), &COM_PlayerInst::get_isTeamLeader_);
	ClassDB::bind_method(D_METHOD("set_isTeamLeader_", "p_val"), &COM_PlayerInst::set_isTeamLeader_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isTeamLeader_"), "set_isTeamLeader_", "get_isTeamLeader_");
	ClassDB::bind_method(D_METHOD("get_sceneId_"), &COM_PlayerInst::get_sceneId_);
	ClassDB::bind_method(D_METHOD("set_sceneId_", "p_val"), &COM_PlayerInst::set_sceneId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sceneId_"), "set_sceneId_", "get_sceneId_");
	ClassDB::bind_method(D_METHOD("get_openSubSystemFlag_"), &COM_PlayerInst::get_openSubSystemFlag_);
	ClassDB::bind_method(D_METHOD("set_openSubSystemFlag_", "p_val"), &COM_PlayerInst::set_openSubSystemFlag_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "openSubSystemFlag_"), "set_openSubSystemFlag_", "get_openSubSystemFlag_");
	ClassDB::bind_method(D_METHOD("get_createTime_"), &COM_PlayerInst::get_createTime_);
	ClassDB::bind_method(D_METHOD("set_createTime_", "p_val"), &COM_PlayerInst::set_createTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "createTime_"), "set_createTime_", "get_createTime_");
	ClassDB::bind_method(D_METHOD("get_guildName_"), &COM_PlayerInst::get_guildName_);
	ClassDB::bind_method(D_METHOD("set_guildName_", "p_val"), &COM_PlayerInst::set_guildName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "guildName_"), "set_guildName_", "get_guildName_");
	ClassDB::bind_method(D_METHOD("get_scenePos_"), &COM_PlayerInst::get_scenePos_);
	ClassDB::bind_method(D_METHOD("set_scenePos_", "p_val"), &COM_PlayerInst::set_scenePos_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "scenePos_"), "set_scenePos_", "get_scenePos_");
	ClassDB::bind_method(D_METHOD("get_pvpInfo_"), &COM_PlayerInst::get_pvpInfo_);
	ClassDB::bind_method(D_METHOD("set_pvpInfo_", "p_val"), &COM_PlayerInst::set_pvpInfo_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "pvpInfo_"), "set_pvpInfo_", "get_pvpInfo_");
	ClassDB::bind_method(D_METHOD("get_onlineTimeFlag_"), &COM_PlayerInst::get_onlineTimeFlag_);
	ClassDB::bind_method(D_METHOD("set_onlineTimeFlag_", "p_val"), &COM_PlayerInst::set_onlineTimeFlag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "onlineTimeFlag_"), "set_onlineTimeFlag_", "get_onlineTimeFlag_");
	ClassDB::bind_method(D_METHOD("get_onlineTime_"), &COM_PlayerInst::get_onlineTime_);
	ClassDB::bind_method(D_METHOD("set_onlineTime_", "p_val"), &COM_PlayerInst::set_onlineTime_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "onlineTime_"), "set_onlineTime_", "get_onlineTime_");
	ClassDB::bind_method(D_METHOD("get_onlineTimeReward_"), &COM_PlayerInst::get_onlineTimeReward_);
	ClassDB::bind_method(D_METHOD("set_onlineTimeReward_", "p_val"), &COM_PlayerInst::set_onlineTimeReward_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "onlineTimeReward_"), "set_onlineTimeReward_", "get_onlineTimeReward_");
	ClassDB::bind_method(D_METHOD("get_isFund_"), &COM_PlayerInst::get_isFund_);
	ClassDB::bind_method(D_METHOD("set_isFund_", "p_val"), &COM_PlayerInst::set_isFund_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isFund_"), "set_isFund_", "get_isFund_");
	ClassDB::bind_method(D_METHOD("get_fundtags_"), &COM_PlayerInst::get_fundtags_);
	ClassDB::bind_method(D_METHOD("set_fundtags_", "p_val"), &COM_PlayerInst::set_fundtags_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "fundtags_"), "set_fundtags_", "get_fundtags_");
	ClassDB::bind_method(D_METHOD("get_openDoubleTimeFlag_"), &COM_PlayerInst::get_openDoubleTimeFlag_);
	ClassDB::bind_method(D_METHOD("set_openDoubleTimeFlag_", "p_val"), &COM_PlayerInst::set_openDoubleTimeFlag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "openDoubleTimeFlag_"), "set_openDoubleTimeFlag_", "get_openDoubleTimeFlag_");
	ClassDB::bind_method(D_METHOD("get_isFirstLogin_"), &COM_PlayerInst::get_isFirstLogin_);
	ClassDB::bind_method(D_METHOD("set_isFirstLogin_", "p_val"), &COM_PlayerInst::set_isFirstLogin_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isFirstLogin_"), "set_isFirstLogin_", "get_isFirstLogin_");
	ClassDB::bind_method(D_METHOD("get_firstRechargeDiamond_"), &COM_PlayerInst::get_firstRechargeDiamond_);
	ClassDB::bind_method(D_METHOD("set_firstRechargeDiamond_", "p_val"), &COM_PlayerInst::set_firstRechargeDiamond_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "firstRechargeDiamond_"), "set_firstRechargeDiamond_", "get_firstRechargeDiamond_");
	ClassDB::bind_method(D_METHOD("get_isFirstRechargeGift_"), &COM_PlayerInst::get_isFirstRechargeGift_);
	ClassDB::bind_method(D_METHOD("set_isFirstRechargeGift_", "p_val"), &COM_PlayerInst::set_isFirstRechargeGift_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isFirstRechargeGift_"), "set_isFirstRechargeGift_", "get_isFirstRechargeGift_");
	ClassDB::bind_method(D_METHOD("get_offlineExp_"), &COM_PlayerInst::get_offlineExp_);
	ClassDB::bind_method(D_METHOD("set_offlineExp_", "p_val"), &COM_PlayerInst::set_offlineExp_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offlineExp_"), "set_offlineExp_", "get_offlineExp_");
	ClassDB::bind_method(D_METHOD("get_rivalTime_"), &COM_PlayerInst::get_rivalTime_);
	ClassDB::bind_method(D_METHOD("set_rivalTime_", "p_val"), &COM_PlayerInst::set_rivalTime_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "rivalTime_"), "set_rivalTime_", "get_rivalTime_");
	ClassDB::bind_method(D_METHOD("get_rivalNum_"), &COM_PlayerInst::get_rivalNum_);
	ClassDB::bind_method(D_METHOD("set_rivalNum_", "p_val"), &COM_PlayerInst::set_rivalNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rivalNum_"), "set_rivalNum_", "get_rivalNum_");
	ClassDB::bind_method(D_METHOD("get_promoteAward_"), &COM_PlayerInst::get_promoteAward_);
	ClassDB::bind_method(D_METHOD("set_promoteAward_", "p_val"), &COM_PlayerInst::set_promoteAward_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "promoteAward_"), "set_promoteAward_", "get_promoteAward_");
	ClassDB::bind_method(D_METHOD("get_guideIdx_"), &COM_PlayerInst::get_guideIdx_);
	ClassDB::bind_method(D_METHOD("set_guideIdx_", "p_val"), &COM_PlayerInst::set_guideIdx_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guideIdx_"), "set_guideIdx_", "get_guideIdx_");
	ClassDB::bind_method(D_METHOD("get_noTalkTime_"), &COM_PlayerInst::get_noTalkTime_);
	ClassDB::bind_method(D_METHOD("set_noTalkTime_", "p_val"), &COM_PlayerInst::set_noTalkTime_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "noTalkTime_"), "set_noTalkTime_", "get_noTalkTime_");
	ClassDB::bind_method(D_METHOD("get_wishShareNum_"), &COM_PlayerInst::get_wishShareNum_);
	ClassDB::bind_method(D_METHOD("set_wishShareNum_", "p_val"), &COM_PlayerInst::set_wishShareNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "wishShareNum_"), "set_wishShareNum_", "get_wishShareNum_");
	ClassDB::bind_method(D_METHOD("get_warriortrophyNum_"), &COM_PlayerInst::get_warriortrophyNum_);
	ClassDB::bind_method(D_METHOD("set_warriortrophyNum_", "p_val"), &COM_PlayerInst::set_warriortrophyNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "warriortrophyNum_"), "set_warriortrophyNum_", "get_warriortrophyNum_");
	ClassDB::bind_method(D_METHOD("get_employeelasttime_"), &COM_PlayerInst::get_employeelasttime_);
	ClassDB::bind_method(D_METHOD("set_employeelasttime_", "p_val"), &COM_PlayerInst::set_employeelasttime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "employeelasttime_"), "set_employeelasttime_", "get_employeelasttime_");
	ClassDB::bind_method(D_METHOD("get_employeeonecount_"), &COM_PlayerInst::get_employeeonecount_);
	ClassDB::bind_method(D_METHOD("set_employeeonecount_", "p_val"), &COM_PlayerInst::set_employeeonecount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "employeeonecount_"), "set_employeeonecount_", "get_employeeonecount_");
	ClassDB::bind_method(D_METHOD("get_employeetencount_"), &COM_PlayerInst::get_employeetencount_);
	ClassDB::bind_method(D_METHOD("set_employeetencount_", "p_val"), &COM_PlayerInst::set_employeetencount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "employeetencount_"), "set_employeetencount_", "get_employeetencount_");
	ClassDB::bind_method(D_METHOD("get_greenBoxTimes_"), &COM_PlayerInst::get_greenBoxTimes_);
	ClassDB::bind_method(D_METHOD("set_greenBoxTimes_", "p_val"), &COM_PlayerInst::set_greenBoxTimes_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "greenBoxTimes_"), "set_greenBoxTimes_", "get_greenBoxTimes_");
	ClassDB::bind_method(D_METHOD("get_blueBoxTimes_"), &COM_PlayerInst::get_blueBoxTimes_);
	ClassDB::bind_method(D_METHOD("set_blueBoxTimes_", "p_val"), &COM_PlayerInst::set_blueBoxTimes_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "blueBoxTimes_"), "set_blueBoxTimes_", "get_blueBoxTimes_");
	ClassDB::bind_method(D_METHOD("get_greenBoxFreeNum_"), &COM_PlayerInst::get_greenBoxFreeNum_);
	ClassDB::bind_method(D_METHOD("set_greenBoxFreeNum_", "p_val"), &COM_PlayerInst::set_greenBoxFreeNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "greenBoxFreeNum_"), "set_greenBoxFreeNum_", "get_greenBoxFreeNum_");
	ClassDB::bind_method(D_METHOD("get_hbInfo_"), &COM_PlayerInst::get_hbInfo_);
	ClassDB::bind_method(D_METHOD("set_hbInfo_", "p_val"), &COM_PlayerInst::set_hbInfo_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "hbInfo_"), "set_hbInfo_", "get_hbInfo_");
	ClassDB::bind_method(D_METHOD("get_openScenes_"), &COM_PlayerInst::get_openScenes_);
	ClassDB::bind_method(D_METHOD("set_openScenes_", "p_val"), &COM_PlayerInst::set_openScenes_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "openScenes_"), "set_openScenes_", "get_openScenes_");
	ClassDB::bind_method(D_METHOD("get_copyNum_"), &COM_PlayerInst::get_copyNum_);
	ClassDB::bind_method(D_METHOD("set_copyNum_", "p_val"), &COM_PlayerInst::set_copyNum_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "copyNum_"), "set_copyNum_", "get_copyNum_");
	ClassDB::bind_method(D_METHOD("get_magicItemLevel_"), &COM_PlayerInst::get_magicItemLevel_);
	ClassDB::bind_method(D_METHOD("set_magicItemLevel_", "p_val"), &COM_PlayerInst::set_magicItemLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicItemLevel_"), "set_magicItemLevel_", "get_magicItemLevel_");
	ClassDB::bind_method(D_METHOD("get_magicItemeExp_"), &COM_PlayerInst::get_magicItemeExp_);
	ClassDB::bind_method(D_METHOD("set_magicItemeExp_", "p_val"), &COM_PlayerInst::set_magicItemeExp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicItemeExp_"), "set_magicItemeExp_", "get_magicItemeExp_");
	ClassDB::bind_method(D_METHOD("get_magicItemeJob_"), &COM_PlayerInst::get_magicItemeJob_);
	ClassDB::bind_method(D_METHOD("set_magicItemeJob_", "p_val"), &COM_PlayerInst::set_magicItemeJob_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicItemeJob_"), "set_magicItemeJob_", "get_magicItemeJob_");
	ClassDB::bind_method(D_METHOD("get_magicTupoLevel_"), &COM_PlayerInst::get_magicTupoLevel_);
	ClassDB::bind_method(D_METHOD("set_magicTupoLevel_", "p_val"), &COM_PlayerInst::set_magicTupoLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicTupoLevel_"), "set_magicTupoLevel_", "get_magicTupoLevel_");
	ClassDB::bind_method(D_METHOD("get_cachedNpcs_"), &COM_PlayerInst::get_cachedNpcs_);
	ClassDB::bind_method(D_METHOD("set_cachedNpcs_", "p_val"), &COM_PlayerInst::set_cachedNpcs_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "cachedNpcs_"), "set_cachedNpcs_", "get_cachedNpcs_");
	ClassDB::bind_method(D_METHOD("get_gft_"), &COM_PlayerInst::get_gft_);
	ClassDB::bind_method(D_METHOD("set_gft_", "p_val"), &COM_PlayerInst::set_gft_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "gft_"), "set_gft_", "get_gft_");
	ClassDB::bind_method(D_METHOD("get_babycache_"), &COM_PlayerInst::get_babycache_);
	ClassDB::bind_method(D_METHOD("set_babycache_", "p_val"), &COM_PlayerInst::set_babycache_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "babycache_"), "set_babycache_", "get_babycache_");
	ClassDB::bind_method(D_METHOD("get_titles_"), &COM_PlayerInst::get_titles_);
	ClassDB::bind_method(D_METHOD("set_titles_", "p_val"), &COM_PlayerInst::set_titles_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "titles_"), "set_titles_", "get_titles_");
	ClassDB::bind_method(D_METHOD("get_guildContribution_"), &COM_PlayerInst::get_guildContribution_);
	ClassDB::bind_method(D_METHOD("set_guildContribution_", "p_val"), &COM_PlayerInst::set_guildContribution_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildContribution_"), "set_guildContribution_", "get_guildContribution_");
	ClassDB::bind_method(D_METHOD("get_exitGuildTime_"), &COM_PlayerInst::get_exitGuildTime_);
	ClassDB::bind_method(D_METHOD("set_exitGuildTime_", "p_val"), &COM_PlayerInst::set_exitGuildTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "exitGuildTime_"), "set_exitGuildTime_", "get_exitGuildTime_");
	ClassDB::bind_method(D_METHOD("get_guildSkills_"), &COM_PlayerInst::get_guildSkills_);
	ClassDB::bind_method(D_METHOD("set_guildSkills_", "p_val"), &COM_PlayerInst::set_guildSkills_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "guildSkills_"), "set_guildSkills_", "get_guildSkills_");
	ClassDB::bind_method(D_METHOD("get_gmActivities_"), &COM_PlayerInst::get_gmActivities_);
	ClassDB::bind_method(D_METHOD("set_gmActivities_", "p_val"), &COM_PlayerInst::set_gmActivities_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "gmActivities_"), "set_gmActivities_", "get_gmActivities_");
	ClassDB::bind_method(D_METHOD("get_festival_"), &COM_PlayerInst::get_festival_);
	ClassDB::bind_method(D_METHOD("set_festival_", "p_val"), &COM_PlayerInst::set_festival_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "festival_"), "set_festival_", "get_festival_");
	ClassDB::bind_method(D_METHOD("get_selfRecharge_"), &COM_PlayerInst::get_selfRecharge_);
	ClassDB::bind_method(D_METHOD("set_selfRecharge_", "p_val"), &COM_PlayerInst::set_selfRecharge_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "selfRecharge_"), "set_selfRecharge_", "get_selfRecharge_");
	ClassDB::bind_method(D_METHOD("get_sysRecharge_"), &COM_PlayerInst::get_sysRecharge_);
	ClassDB::bind_method(D_METHOD("set_sysRecharge_", "p_val"), &COM_PlayerInst::set_sysRecharge_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "sysRecharge_"), "set_sysRecharge_", "get_sysRecharge_");
	ClassDB::bind_method(D_METHOD("get_selfDiscountStore_"), &COM_PlayerInst::get_selfDiscountStore_);
	ClassDB::bind_method(D_METHOD("set_selfDiscountStore_", "p_val"), &COM_PlayerInst::set_selfDiscountStore_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "selfDiscountStore_"), "set_selfDiscountStore_", "get_selfDiscountStore_");
	ClassDB::bind_method(D_METHOD("get_sysDiscountStore_"), &COM_PlayerInst::get_sysDiscountStore_);
	ClassDB::bind_method(D_METHOD("set_sysDiscountStore_", "p_val"), &COM_PlayerInst::set_sysDiscountStore_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "sysDiscountStore_"), "set_sysDiscountStore_", "get_sysDiscountStore_");
	ClassDB::bind_method(D_METHOD("get_selfOnceRecharge_"), &COM_PlayerInst::get_selfOnceRecharge_);
	ClassDB::bind_method(D_METHOD("set_selfOnceRecharge_", "p_val"), &COM_PlayerInst::set_selfOnceRecharge_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "selfOnceRecharge_"), "set_selfOnceRecharge_", "get_selfOnceRecharge_");
	ClassDB::bind_method(D_METHOD("get_sysOnceRecharge_"), &COM_PlayerInst::get_sysOnceRecharge_);
	ClassDB::bind_method(D_METHOD("set_sysOnceRecharge_", "p_val"), &COM_PlayerInst::set_sysOnceRecharge_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "sysOnceRecharge_"), "set_sysOnceRecharge_", "get_sysOnceRecharge_");
	ClassDB::bind_method(D_METHOD("get_empact_"), &COM_PlayerInst::get_empact_);
	ClassDB::bind_method(D_METHOD("set_empact_", "p_val"), &COM_PlayerInst::set_empact_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "empact_"), "set_empact_", "get_empact_");
	ClassDB::bind_method(D_METHOD("get_selfCards_"), &COM_PlayerInst::get_selfCards_);
	ClassDB::bind_method(D_METHOD("set_selfCards_", "p_val"), &COM_PlayerInst::set_selfCards_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "selfCards_"), "set_selfCards_", "get_selfCards_");
	ClassDB::bind_method(D_METHOD("get_myselfRecharge_"), &COM_PlayerInst::get_myselfRecharge_);
	ClassDB::bind_method(D_METHOD("set_myselfRecharge_", "p_val"), &COM_PlayerInst::set_myselfRecharge_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "myselfRecharge_"), "set_myselfRecharge_", "get_myselfRecharge_");
	ClassDB::bind_method(D_METHOD("get_hotdata_"), &COM_PlayerInst::get_hotdata_);
	ClassDB::bind_method(D_METHOD("set_hotdata_", "p_val"), &COM_PlayerInst::set_hotdata_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "hotdata_"), "set_hotdata_", "get_hotdata_");
	ClassDB::bind_method(D_METHOD("get_gbdata_"), &COM_PlayerInst::get_gbdata_);
	ClassDB::bind_method(D_METHOD("set_gbdata_", "p_val"), &COM_PlayerInst::set_gbdata_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "gbdata_"), "set_gbdata_", "get_gbdata_");
	ClassDB::bind_method(D_METHOD("get_sevenflag_"), &COM_PlayerInst::get_sevenflag_);
	ClassDB::bind_method(D_METHOD("set_sevenflag_", "p_val"), &COM_PlayerInst::set_sevenflag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "sevenflag_"), "set_sevenflag_", "get_sevenflag_");
	ClassDB::bind_method(D_METHOD("get_signFlag_"), &COM_PlayerInst::get_signFlag_);
	ClassDB::bind_method(D_METHOD("set_signFlag_", "p_val"), &COM_PlayerInst::set_signFlag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "signFlag_"), "set_signFlag_", "get_signFlag_");
	ClassDB::bind_method(D_METHOD("get_sevendata_"), &COM_PlayerInst::get_sevendata_);
	ClassDB::bind_method(D_METHOD("set_sevendata_", "p_val"), &COM_PlayerInst::set_sevendata_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "sevendata_"), "set_sevendata_", "get_sevendata_");
	ClassDB::bind_method(D_METHOD("get_viprewardflag_"), &COM_PlayerInst::get_viprewardflag_);
	ClassDB::bind_method(D_METHOD("set_viprewardflag_", "p_val"), &COM_PlayerInst::set_viprewardflag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "viprewardflag_"), "set_viprewardflag_", "get_viprewardflag_");
	ClassDB::bind_method(D_METHOD("get_phoneNumber_"), &COM_PlayerInst::get_phoneNumber_);
	ClassDB::bind_method(D_METHOD("set_phoneNumber_", "p_val"), &COM_PlayerInst::set_phoneNumber_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "phoneNumber_"), "set_phoneNumber_", "get_phoneNumber_");
	ClassDB::bind_method(D_METHOD("get_levelgift_"), &COM_PlayerInst::get_levelgift_);
	ClassDB::bind_method(D_METHOD("set_levelgift_", "p_val"), &COM_PlayerInst::set_levelgift_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "levelgift_"), "set_levelgift_", "get_levelgift_");
	ClassDB::bind_method(D_METHOD("get_activity_"), &COM_PlayerInst::get_activity_);
	ClassDB::bind_method(D_METHOD("set_activity_", "p_val"), &COM_PlayerInst::set_activity_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "activity_"), "set_activity_", "get_activity_");
	ClassDB::bind_method(D_METHOD("get_fuwen_"), &COM_PlayerInst::get_fuwen_);
	ClassDB::bind_method(D_METHOD("set_fuwen_", "p_val"), &COM_PlayerInst::set_fuwen_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "fuwen_"), "set_fuwen_", "get_fuwen_");
	ClassDB::bind_method(D_METHOD("get_crystalData_"), &COM_PlayerInst::get_crystalData_);
	ClassDB::bind_method(D_METHOD("set_crystalData_", "p_val"), &COM_PlayerInst::set_crystalData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "crystalData_"), "set_crystalData_", "get_crystalData_");
	ClassDB::bind_method(D_METHOD("get_integralData_"), &COM_PlayerInst::get_integralData_);
	ClassDB::bind_method(D_METHOD("set_integralData_", "p_val"), &COM_PlayerInst::set_integralData_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "integralData_"), "set_integralData_", "get_integralData_");
	ClassDB::bind_method(D_METHOD("get_coursegift_"), &COM_PlayerInst::get_coursegift_);
	ClassDB::bind_method(D_METHOD("set_coursegift_", "p_val"), &COM_PlayerInst::set_coursegift_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "coursegift_"), "set_coursegift_", "get_coursegift_");
}

void COM_PlayerInst::serialize(ProtocolWriter* s) const {
	COM_Entity::serialize(s);
	//field mask
	FieldMask<9> __fm__;
	__fm__.writeBit(isLeavingTeam_);
	__fm__.writeBit(isBattle_);
	__fm__.writeBit(autoBattle_);
	__fm__.writeBit(isTeamLeader_);
	__fm__.writeBit((sceneId_==0)?false:true);
	__fm__.writeBit((openSubSystemFlag_==0)?false:true);
	__fm__.writeBit((createTime_==0)?false:true);
	__fm__.writeBit(guildName_.length()?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(onlineTimeFlag_);
	__fm__.writeBit((onlineTime_==0.0)?false:true);
	__fm__.writeBit(onlineTimeReward_.size()?true:false);
	__fm__.writeBit(isFund_);
	__fm__.writeBit(fundtags_.size()?true:false);
	__fm__.writeBit(openDoubleTimeFlag_);
	__fm__.writeBit(isFirstLogin_);
	__fm__.writeBit(firstRechargeDiamond_);
	__fm__.writeBit(isFirstRechargeGift_);
	__fm__.writeBit((offlineExp_==0.0)?false:true);
	__fm__.writeBit((rivalTime_==0.0)?false:true);
	__fm__.writeBit((rivalNum_==0)?false:true);
	__fm__.writeBit((promoteAward_==0)?false:true);
	__fm__.writeBit((guideIdx_==0)?false:true);
	__fm__.writeBit((noTalkTime_==0.0)?false:true);
	__fm__.writeBit((wishShareNum_==0)?false:true);
	__fm__.writeBit((warriortrophyNum_==0)?false:true);
	__fm__.writeBit((employeelasttime_==0)?false:true);
	__fm__.writeBit((employeeonecount_==0)?false:true);
	__fm__.writeBit((employeetencount_==0)?false:true);
	__fm__.writeBit((greenBoxTimes_==0.0)?false:true);
	__fm__.writeBit((blueBoxTimes_==0.0)?false:true);
	__fm__.writeBit((greenBoxFreeNum_==0)?false:true);
	__fm__.writeBit(true);
	__fm__.writeBit(openScenes_.size()?true:false);
	__fm__.writeBit(copyNum_.size()?true:false);
	__fm__.writeBit((magicItemLevel_==0)?false:true);
	__fm__.writeBit((magicItemeExp_==0)?false:true);
	__fm__.writeBit(magicItemeJob_?true:false);
	__fm__.writeBit((magicTupoLevel_==0)?false:true);
	__fm__.writeBit(cachedNpcs_.size()?true:false);
	__fm__.writeBit(gft_.size()?true:false);
	__fm__.writeBit(babycache_.size()?true:false);
	__fm__.writeBit(titles_.size()?true:false);
	__fm__.writeBit((guildContribution_==0)?false:true);
	__fm__.writeBit((exitGuildTime_==0)?false:true);
	__fm__.writeBit(guildSkills_.size()?true:false);
	__fm__.writeBit(gmActivities_.size()?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(sevenflag_);
	__fm__.writeBit(signFlag_);
	__fm__.writeBit(sevendata_.size()?true:false);
	__fm__.writeBit(viprewardflag_);
	__fm__.writeBit(phoneNumber_.length()?true:false);
	__fm__.writeBit(levelgift_.size()?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(fuwen_.size()?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(coursegift_.size()?true:false);
	s->write((const void*)__fm__.masks_, 9);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(isLeavingTeam_);
	}
	if(__fm__.readBit()){
		s->writeType(isBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(autoBattle_);
	}
	if(__fm__.readBit()){
		s->writeType(isTeamLeader_);
	}
	if(__fm__.readBit()){
		s->writeType(sceneId_);
	}
	if(__fm__.readBit()){
		s->writeType(openSubSystemFlag_);
	}
	if(__fm__.readBit()){
		s->writeType(createTime_);
	}
	if(__fm__.readBit()){
		s->writeType(guildName_);
	}
	if(__fm__.readBit()){
		if (scenePos_.is_null()) const_cast<Ref<COM_FPosition>&>(scenePos_) = memnew(COM_FPosition);
		scenePos_->serialize(s);
	}
	if(__fm__.readBit()){
		if (pvpInfo_.is_null()) const_cast<Ref<COM_PlayerVsPlayer>&>(pvpInfo_) = memnew(COM_PlayerVsPlayer);
		pvpInfo_->serialize(s);
	}
	if(__fm__.readBit()){
		s->writeType(onlineTimeFlag_);
	}
	if(__fm__.readBit()){
		s->writeType(onlineTime_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)onlineTimeReward_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = onlineTimeReward_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(isFund_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)fundtags_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = fundtags_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(openDoubleTimeFlag_);
	}
	if(__fm__.readBit()){
		s->writeType(isFirstLogin_);
	}
	if(__fm__.readBit()){
		s->writeType(firstRechargeDiamond_);
	}
	if(__fm__.readBit()){
		s->writeType(isFirstRechargeGift_);
	}
	if(__fm__.readBit()){
		s->writeType(offlineExp_);
	}
	if(__fm__.readBit()){
		s->writeType(rivalTime_);
	}
	if(__fm__.readBit()){
		s->writeType(rivalNum_);
	}
	if(__fm__.readBit()){
		s->writeType(promoteAward_);
	}
	if(__fm__.readBit()){
		s->writeType(guideIdx_);
	}
	if(__fm__.readBit()){
		s->writeType(noTalkTime_);
	}
	if(__fm__.readBit()){
		s->writeType(wishShareNum_);
	}
	if(__fm__.readBit()){
		s->writeType(warriortrophyNum_);
	}
	if(__fm__.readBit()){
		s->writeType(employeelasttime_);
	}
	if(__fm__.readBit()){
		s->writeType(employeeonecount_);
	}
	if(__fm__.readBit()){
		s->writeType(employeetencount_);
	}
	if(__fm__.readBit()){
		s->writeType(greenBoxTimes_);
	}
	if(__fm__.readBit()){
		s->writeType(blueBoxTimes_);
	}
	if(__fm__.readBit()){
		s->writeType(greenBoxFreeNum_);
	}
	if(__fm__.readBit()){
		if (hbInfo_.is_null()) const_cast<Ref<COM_HundredBattle>&>(hbInfo_) = memnew(COM_HundredBattle);
		hbInfo_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)openScenes_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = openScenes_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)copyNum_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = copyNum_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(magicItemLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(magicItemeExp_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)magicItemeJob_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(magicTupoLevel_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)cachedNpcs_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = cachedNpcs_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)gft_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			String __tmp = gft_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)babycache_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = babycache_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)titles_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = titles_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(guildContribution_);
	}
	if(__fm__.readBit()){
		s->writeType(exitGuildTime_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)guildSkills_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Skill> __elem = guildSkills_[i];
			if (__elem.is_null()) __elem = memnew(COM_Skill);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)gmActivities_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint16_t __tmp = (uint16_t)gmActivities_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		if (festival_.is_null()) const_cast<Ref<COM_ADLoginTotal>&>(festival_) = memnew(COM_ADLoginTotal);
		festival_->serialize(s);
	}
	if(__fm__.readBit()){
		if (selfRecharge_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(selfRecharge_) = memnew(COM_ADChargeTotal);
		selfRecharge_->serialize(s);
	}
	if(__fm__.readBit()){
		if (sysRecharge_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(sysRecharge_) = memnew(COM_ADChargeTotal);
		sysRecharge_->serialize(s);
	}
	if(__fm__.readBit()){
		if (selfDiscountStore_.is_null()) const_cast<Ref<COM_ADDiscountStore>&>(selfDiscountStore_) = memnew(COM_ADDiscountStore);
		selfDiscountStore_->serialize(s);
	}
	if(__fm__.readBit()){
		if (sysDiscountStore_.is_null()) const_cast<Ref<COM_ADDiscountStore>&>(sysDiscountStore_) = memnew(COM_ADDiscountStore);
		sysDiscountStore_->serialize(s);
	}
	if(__fm__.readBit()){
		if (selfOnceRecharge_.is_null()) const_cast<Ref<COM_ADChargeEvery>&>(selfOnceRecharge_) = memnew(COM_ADChargeEvery);
		selfOnceRecharge_->serialize(s);
	}
	if(__fm__.readBit()){
		if (sysOnceRecharge_.is_null()) const_cast<Ref<COM_ADChargeEvery>&>(sysOnceRecharge_) = memnew(COM_ADChargeEvery);
		sysOnceRecharge_->serialize(s);
	}
	if(__fm__.readBit()){
		if (empact_.is_null()) const_cast<Ref<COM_ADEmployeeTotal>&>(empact_) = memnew(COM_ADEmployeeTotal);
		empact_->serialize(s);
	}
	if(__fm__.readBit()){
		if (selfCards_.is_null()) const_cast<Ref<COM_ADCards>&>(selfCards_) = memnew(COM_ADCards);
		selfCards_->serialize(s);
	}
	if(__fm__.readBit()){
		if (myselfRecharge_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(myselfRecharge_) = memnew(COM_ADChargeTotal);
		myselfRecharge_->serialize(s);
	}
	if(__fm__.readBit()){
		if (hotdata_.is_null()) const_cast<Ref<COM_ADHotRole>&>(hotdata_) = memnew(COM_ADHotRole);
		hotdata_->serialize(s);
	}
	if(__fm__.readBit()){
		if (gbdata_.is_null()) const_cast<Ref<COM_ADGiftBag>&>(gbdata_) = memnew(COM_ADGiftBag);
		gbdata_->serialize(s);
	}
	if(__fm__.readBit()){
		s->writeType(sevenflag_);
	}
	if(__fm__.readBit()){
		s->writeType(signFlag_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)sevendata_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Sevenday> __elem = sevendata_[i];
			if (__elem.is_null()) __elem = memnew(COM_Sevenday);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		s->writeType(viprewardflag_);
	}
	if(__fm__.readBit()){
		s->writeType(phoneNumber_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)levelgift_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = levelgift_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		if (activity_.is_null()) const_cast<Ref<COM_ActivityTable>&>(activity_) = memnew(COM_ActivityTable);
		activity_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)fuwen_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Item> __elem = fuwen_[i];
			if (__elem.is_null()) __elem = memnew(COM_Item);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		if (crystalData_.is_null()) const_cast<Ref<COM_CrystalData>&>(crystalData_) = memnew(COM_CrystalData);
		crystalData_->serialize(s);
	}
	if(__fm__.readBit()){
		if (integralData_.is_null()) const_cast<Ref<COM_IntegralData>&>(integralData_) = memnew(COM_IntegralData);
		integralData_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)coursegift_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_CourseGift> __elem = coursegift_[i];
			if (__elem.is_null()) __elem = memnew(COM_CourseGift);
			__elem->serialize(s);
		}
	}
}

bool COM_PlayerInst::deserialize(ProtocolReader* r) {
	if(!COM_Entity::deserialize(r)) return false;
	//field mask
	FieldMask<9> __fm__;
	if(!r->read((void*)__fm__.masks_, 9)) return false;
	if(__fm__.readBit()){
		isLeavingTeam_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		autoBattle_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isTeamLeader_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(sceneId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(openSubSystemFlag_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(createTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if (scenePos_.is_null()) const_cast<Ref<COM_FPosition>&>(scenePos_) = memnew(COM_FPosition);
		if(!scenePos_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (pvpInfo_.is_null()) const_cast<Ref<COM_PlayerVsPlayer>&>(pvpInfo_) = memnew(COM_PlayerVsPlayer);
		if(!pvpInfo_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		onlineTimeFlag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(onlineTime_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			onlineTimeReward_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				onlineTimeReward_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		isFund_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			fundtags_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				fundtags_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		openDoubleTimeFlag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isFirstLogin_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		firstRechargeDiamond_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isFirstRechargeGift_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(offlineExp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rivalTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rivalNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(promoteAward_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guideIdx_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(noTalkTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(wishShareNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(warriortrophyNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(employeelasttime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(employeeonecount_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(employeetencount_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(greenBoxTimes_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(blueBoxTimes_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(greenBoxFreeNum_)) return false;
	}
	if(__fm__.readBit()){
		if (hbInfo_.is_null()) const_cast<Ref<COM_HundredBattle>&>(hbInfo_) = memnew(COM_HundredBattle);
		if(!hbInfo_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			openScenes_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				openScenes_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			copyNum_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				copyNum_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(magicItemLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(magicItemeExp_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		magicItemeJob_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(magicTupoLevel_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			cachedNpcs_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				cachedNpcs_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			gft_.resize(__len);
			for(int i=0; i<__len; ++i) {
				String __tmp;
				if(!r->readType(__tmp, 65535)) return false;
				gft_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			babycache_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				babycache_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			titles_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				titles_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(guildContribution_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(exitGuildTime_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			guildSkills_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Skill> __elem = memnew(COM_Skill);
				if(!__elem->deserialize(r)) return false;
				guildSkills_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			gmActivities_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint16_t __tmp; if(!r->readType(__tmp)) return false;
				gmActivities_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if (festival_.is_null()) const_cast<Ref<COM_ADLoginTotal>&>(festival_) = memnew(COM_ADLoginTotal);
		if(!festival_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (selfRecharge_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(selfRecharge_) = memnew(COM_ADChargeTotal);
		if(!selfRecharge_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (sysRecharge_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(sysRecharge_) = memnew(COM_ADChargeTotal);
		if(!sysRecharge_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (selfDiscountStore_.is_null()) const_cast<Ref<COM_ADDiscountStore>&>(selfDiscountStore_) = memnew(COM_ADDiscountStore);
		if(!selfDiscountStore_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (sysDiscountStore_.is_null()) const_cast<Ref<COM_ADDiscountStore>&>(sysDiscountStore_) = memnew(COM_ADDiscountStore);
		if(!sysDiscountStore_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (selfOnceRecharge_.is_null()) const_cast<Ref<COM_ADChargeEvery>&>(selfOnceRecharge_) = memnew(COM_ADChargeEvery);
		if(!selfOnceRecharge_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (sysOnceRecharge_.is_null()) const_cast<Ref<COM_ADChargeEvery>&>(sysOnceRecharge_) = memnew(COM_ADChargeEvery);
		if(!sysOnceRecharge_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (empact_.is_null()) const_cast<Ref<COM_ADEmployeeTotal>&>(empact_) = memnew(COM_ADEmployeeTotal);
		if(!empact_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (selfCards_.is_null()) const_cast<Ref<COM_ADCards>&>(selfCards_) = memnew(COM_ADCards);
		if(!selfCards_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (myselfRecharge_.is_null()) const_cast<Ref<COM_ADChargeTotal>&>(myselfRecharge_) = memnew(COM_ADChargeTotal);
		if(!myselfRecharge_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (hotdata_.is_null()) const_cast<Ref<COM_ADHotRole>&>(hotdata_) = memnew(COM_ADHotRole);
		if(!hotdata_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (gbdata_.is_null()) const_cast<Ref<COM_ADGiftBag>&>(gbdata_) = memnew(COM_ADGiftBag);
		if(!gbdata_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		sevenflag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		signFlag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			sevendata_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Sevenday> __elem = memnew(COM_Sevenday);
				if(!__elem->deserialize(r)) return false;
				sevendata_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		viprewardflag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(phoneNumber_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			levelgift_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				levelgift_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		if (activity_.is_null()) const_cast<Ref<COM_ActivityTable>&>(activity_) = memnew(COM_ActivityTable);
		if(!activity_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			fuwen_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				fuwen_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		if (crystalData_.is_null()) const_cast<Ref<COM_CrystalData>&>(crystalData_) = memnew(COM_CrystalData);
		if(!crystalData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (integralData_.is_null()) const_cast<Ref<COM_IntegralData>&>(integralData_) = memnew(COM_IntegralData);
		if(!integralData_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			coursegift_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_CourseGift> __elem = memnew(COM_CourseGift);
				if(!__elem->deserialize(r)) return false;
				coursegift_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_MonsterInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_gear_"), &COM_MonsterInst::get_gear_);
	ClassDB::bind_method(D_METHOD("set_gear_", "p_val"), &COM_MonsterInst::set_gear_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "gear_"), "set_gear_", "get_gear_");
}

void COM_MonsterInst::serialize(ProtocolWriter* s) const {
	COM_Entity::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(gear_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)gear_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = gear_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_MonsterInst::deserialize(ProtocolReader* r) {
	if(!COM_Entity::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			gear_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				gear_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_ReportState::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_add_"), &COM_ReportState::get_add_);
	ClassDB::bind_method(D_METHOD("set_add_", "p_val"), &COM_ReportState::set_add_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "add_"), "set_add_", "get_add_");
	ClassDB::bind_method(D_METHOD("get_ownerId_"), &COM_ReportState::get_ownerId_);
	ClassDB::bind_method(D_METHOD("set_ownerId_", "p_val"), &COM_ReportState::set_ownerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ownerId_"), "set_ownerId_", "get_ownerId_");
	ClassDB::bind_method(D_METHOD("get_addQueue_"), &COM_ReportState::get_addQueue_);
	ClassDB::bind_method(D_METHOD("set_addQueue_", "p_val"), &COM_ReportState::set_addQueue_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "addQueue_"), "set_addQueue_", "get_addQueue_");
}

void COM_ReportState::serialize(ProtocolWriter* s) const {
	COM_State::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(add_);
	__fm__.writeBit((ownerId_==0)?false:true);
	__fm__.writeBit((addQueue_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(add_);
	}
	if(__fm__.readBit()){
		s->writeType(ownerId_);
	}
	if(__fm__.readBit()){
		s->writeType(addQueue_);
	}
}

bool COM_ReportState::deserialize(ProtocolReader* r) {
	if(!COM_State::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		add_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(ownerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(addQueue_)) return false;
	}
	return true;
}

void COM_ReportTargetBase::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_position_"), &COM_ReportTargetBase::get_position_);
	ClassDB::bind_method(D_METHOD("set_position_", "p_val"), &COM_ReportTargetBase::set_position_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "position_"), "set_position_", "get_position_");
	ClassDB::bind_method(D_METHOD("get_prop_"), &COM_ReportTargetBase::get_prop_);
	ClassDB::bind_method(D_METHOD("set_prop_", "p_val"), &COM_ReportTargetBase::set_prop_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "prop_"), "set_prop_", "get_prop_");
	ClassDB::bind_method(D_METHOD("get_bao_"), &COM_ReportTargetBase::get_bao_);
	ClassDB::bind_method(D_METHOD("set_bao_", "p_val"), &COM_ReportTargetBase::set_bao_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "bao_"), "set_bao_", "get_bao_");
	ClassDB::bind_method(D_METHOD("get_fly_"), &COM_ReportTargetBase::get_fly_);
	ClassDB::bind_method(D_METHOD("set_fly_", "p_val"), &COM_ReportTargetBase::set_fly_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "fly_"), "set_fly_", "get_fly_");
}

void COM_ReportTargetBase::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(position_?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(bao_);
	__fm__.writeBit(fly_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)position_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		if (prop_.is_null()) const_cast<Ref<COM_PropValue>&>(prop_) = memnew(COM_PropValue);
		prop_->serialize(s);
	}
	if(__fm__.readBit()){
		s->writeType(bao_);
	}
	if(__fm__.readBit()){
		s->writeType(fly_);
	}
}

bool COM_ReportTargetBase::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 22) return false;
		position_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if (prop_.is_null()) const_cast<Ref<COM_PropValue>&>(prop_) = memnew(COM_PropValue);
		if(!prop_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		bao_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		fly_ = __fm__.readBit();
	}
	return true;
}

void COM_ReportTarget::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_prop2_"), &COM_ReportTarget::get_prop2_);
	ClassDB::bind_method(D_METHOD("set_prop2_", "p_val"), &COM_ReportTarget::set_prop2_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "prop2_"), "set_prop2_", "get_prop2_");
}

void COM_ReportTarget::serialize(ProtocolWriter* s) const {
	COM_ReportTargetBase::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(prop2_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)prop2_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportTargetBase> __elem = prop2_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportTargetBase);
			__elem->serialize(s);
		}
	}
}

bool COM_ReportTarget::deserialize(ProtocolReader* r) {
	if(!COM_ReportTargetBase::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			prop2_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportTargetBase> __elem = memnew(COM_ReportTargetBase);
				if(!__elem->deserialize(r)) return false;
				prop2_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_Order::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_status_"), &COM_Order::get_status_);
	ClassDB::bind_method(D_METHOD("set_status_", "p_val"), &COM_Order::set_status_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "status_"), "set_status_", "get_status_");
	ClassDB::bind_method(D_METHOD("get_casterId_"), &COM_Order::get_casterId_);
	ClassDB::bind_method(D_METHOD("set_casterId_", "p_val"), &COM_Order::set_casterId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "casterId_"), "set_casterId_", "get_casterId_");
	ClassDB::bind_method(D_METHOD("get_target_"), &COM_Order::get_target_);
	ClassDB::bind_method(D_METHOD("set_target_", "p_val"), &COM_Order::set_target_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "target_"), "set_target_", "get_target_");
	ClassDB::bind_method(D_METHOD("get_skill_"), &COM_Order::get_skill_);
	ClassDB::bind_method(D_METHOD("set_skill_", "p_val"), &COM_Order::set_skill_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skill_"), "set_skill_", "get_skill_");
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_Order::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_Order::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_weaponInstId_"), &COM_Order::get_weaponInstId_);
	ClassDB::bind_method(D_METHOD("set_weaponInstId_", "p_val"), &COM_Order::set_weaponInstId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "weaponInstId_"), "set_weaponInstId_", "get_weaponInstId_");
	ClassDB::bind_method(D_METHOD("get_babyId_"), &COM_Order::get_babyId_);
	ClassDB::bind_method(D_METHOD("set_babyId_", "p_val"), &COM_Order::set_babyId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyId_"), "set_babyId_", "get_babyId_");
	ClassDB::bind_method(D_METHOD("get_isSec_"), &COM_Order::get_isSec_);
	ClassDB::bind_method(D_METHOD("set_isSec_", "p_val"), &COM_Order::set_isSec_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "isSec_"), "set_isSec_", "get_isSec_");
	ClassDB::bind_method(D_METHOD("get_uinteGroup_"), &COM_Order::get_uinteGroup_);
	ClassDB::bind_method(D_METHOD("set_uinteGroup_", "p_val"), &COM_Order::set_uinteGroup_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "uinteGroup_"), "set_uinteGroup_", "get_uinteGroup_");
	ClassDB::bind_method(D_METHOD("get_uniteNum_"), &COM_Order::get_uniteNum_);
	ClassDB::bind_method(D_METHOD("set_uniteNum_", "p_val"), &COM_Order::set_uniteNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "uniteNum_"), "set_uniteNum_", "get_uniteNum_");
	ClassDB::bind_method(D_METHOD("get_isNo_"), &COM_Order::get_isNo_);
	ClassDB::bind_method(D_METHOD("set_isNo_", "p_val"), &COM_Order::set_isNo_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isNo_"), "set_isNo_", "get_isNo_");
}

void COM_Order::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(status_?true:false);
	__fm__.writeBit((casterId_==0)?false:true);
	__fm__.writeBit((target_==0)?false:true);
	__fm__.writeBit((skill_==0)?false:true);
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((weaponInstId_==0)?false:true);
	__fm__.writeBit((babyId_==0)?false:true);
	__fm__.writeBit((isSec_==0)?false:true);
	__fm__.writeBit((uinteGroup_==0)?false:true);
	__fm__.writeBit((uniteNum_==0)?false:true);
	__fm__.writeBit(isNo_);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)status_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(casterId_);
	}
	if(__fm__.readBit()){
		s->writeType(target_);
	}
	if(__fm__.readBit()){
		s->writeType(skill_);
	}
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(weaponInstId_);
	}
	if(__fm__.readBit()){
		s->writeType(babyId_);
	}
	if(__fm__.readBit()){
		s->writeType(isSec_);
	}
	if(__fm__.readBit()){
		s->writeType(uinteGroup_);
	}
	if(__fm__.readBit()){
		s->writeType(uniteNum_);
	}
	if(__fm__.readBit()){
		s->writeType(isNo_);
	}
}

bool COM_Order::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 9) return false;
		status_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(casterId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(target_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(skill_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(weaponInstId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(isSec_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(uinteGroup_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(uniteNum_)) return false;
	}
	if(__fm__.readBit()){
		isNo_ = __fm__.readBit();
	}
	return true;
}

void COM_ReportActionCounter::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_casterId_"), &COM_ReportActionCounter::get_casterId_);
	ClassDB::bind_method(D_METHOD("set_casterId_", "p_val"), &COM_ReportActionCounter::set_casterId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "casterId_"), "set_casterId_", "get_casterId_");
	ClassDB::bind_method(D_METHOD("get_targetPosition_"), &COM_ReportActionCounter::get_targetPosition_);
	ClassDB::bind_method(D_METHOD("set_targetPosition_", "p_val"), &COM_ReportActionCounter::set_targetPosition_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "targetPosition_"), "set_targetPosition_", "get_targetPosition_");
	ClassDB::bind_method(D_METHOD("get_props_"), &COM_ReportActionCounter::get_props_);
	ClassDB::bind_method(D_METHOD("set_props_", "p_val"), &COM_ReportActionCounter::set_props_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "props_"), "set_props_", "get_props_");
	ClassDB::bind_method(D_METHOD("get_states_"), &COM_ReportActionCounter::get_states_);
	ClassDB::bind_method(D_METHOD("set_states_", "p_val"), &COM_ReportActionCounter::set_states_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "states_"), "set_states_", "get_states_");
}

void COM_ReportActionCounter::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((casterId_==0)?false:true);
	__fm__.writeBit((targetPosition_==0)?false:true);
	__fm__.writeBit(true);
	__fm__.writeBit(states_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(casterId_);
	}
	if(__fm__.readBit()){
		s->writeType(targetPosition_);
	}
	if(__fm__.readBit()){
		if (props_.is_null()) const_cast<Ref<COM_ReportTarget>&>(props_) = memnew(COM_ReportTarget);
		props_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)states_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportState> __elem = states_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportState);
			__elem->serialize(s);
		}
	}
}

bool COM_ReportActionCounter::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(casterId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(targetPosition_)) return false;
	}
	if(__fm__.readBit()){
		if (props_.is_null()) const_cast<Ref<COM_ReportTarget>&>(props_) = memnew(COM_ReportTarget);
		if(!props_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			states_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportState> __elem = memnew(COM_ReportState);
				if(!__elem->deserialize(r)) return false;
				states_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_ReportAction::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_zhuachongOk_"), &COM_ReportAction::get_zhuachongOk_);
	ClassDB::bind_method(D_METHOD("set_zhuachongOk_", "p_val"), &COM_ReportAction::set_zhuachongOk_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "zhuachongOk_"), "set_zhuachongOk_", "get_zhuachongOk_");
	ClassDB::bind_method(D_METHOD("get_skillLevel_"), &COM_ReportAction::get_skillLevel_);
	ClassDB::bind_method(D_METHOD("set_skillLevel_", "p_val"), &COM_ReportAction::set_skillLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skillLevel_"), "set_skillLevel_", "get_skillLevel_");
	ClassDB::bind_method(D_METHOD("get_huweiPosition_"), &COM_ReportAction::get_huweiPosition_);
	ClassDB::bind_method(D_METHOD("set_huweiPosition_", "p_val"), &COM_ReportAction::set_huweiPosition_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "huweiPosition_"), "set_huweiPosition_", "get_huweiPosition_");
	ClassDB::bind_method(D_METHOD("get_bp0_"), &COM_ReportAction::get_bp0_);
	ClassDB::bind_method(D_METHOD("set_bp0_", "p_val"), &COM_ReportAction::set_bp0_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "bp0_"), "set_bp0_", "get_bp0_");
	ClassDB::bind_method(D_METHOD("get_bp1_"), &COM_ReportAction::get_bp1_);
	ClassDB::bind_method(D_METHOD("set_bp1_", "p_val"), &COM_ReportAction::set_bp1_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "bp1_"), "set_bp1_", "get_bp1_");
	ClassDB::bind_method(D_METHOD("get_baby_"), &COM_ReportAction::get_baby_);
	ClassDB::bind_method(D_METHOD("set_baby_", "p_val"), &COM_ReportAction::set_baby_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "baby_"), "set_baby_", "get_baby_");
	ClassDB::bind_method(D_METHOD("get_eraseEntities_"), &COM_ReportAction::get_eraseEntities_);
	ClassDB::bind_method(D_METHOD("set_eraseEntities_", "p_val"), &COM_ReportAction::set_eraseEntities_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "eraseEntities_"), "set_eraseEntities_", "get_eraseEntities_");
	ClassDB::bind_method(D_METHOD("get_targets_"), &COM_ReportAction::get_targets_);
	ClassDB::bind_method(D_METHOD("set_targets_", "p_val"), &COM_ReportAction::set_targets_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "targets_"), "set_targets_", "get_targets_");
	ClassDB::bind_method(D_METHOD("get_stateIds_"), &COM_ReportAction::get_stateIds_);
	ClassDB::bind_method(D_METHOD("set_stateIds_", "p_val"), &COM_ReportAction::set_stateIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "stateIds_"), "set_stateIds_", "get_stateIds_");
	ClassDB::bind_method(D_METHOD("get_counters_"), &COM_ReportAction::get_counters_);
	ClassDB::bind_method(D_METHOD("set_counters_", "p_val"), &COM_ReportAction::set_counters_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "counters_"), "set_counters_", "get_counters_");
	ClassDB::bind_method(D_METHOD("get_dynamicEntities_"), &COM_ReportAction::get_dynamicEntities_);
	ClassDB::bind_method(D_METHOD("set_dynamicEntities_", "p_val"), &COM_ReportAction::set_dynamicEntities_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dynamicEntities_"), "set_dynamicEntities_", "get_dynamicEntities_");
}

void COM_ReportAction::serialize(ProtocolWriter* s) const {
	COM_Order::serialize(s);
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(zhuachongOk_);
	__fm__.writeBit((skillLevel_==0)?false:true);
	__fm__.writeBit((huweiPosition_==0)?false:true);
	__fm__.writeBit(bp0_?true:false);
	__fm__.writeBit(bp1_?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(eraseEntities_.size()?true:false);
	__fm__.writeBit(targets_.size()?true:false);
	__fm__.writeBit(stateIds_.size()?true:false);
	__fm__.writeBit(counters_.size()?true:false);
	__fm__.writeBit(dynamicEntities_.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(zhuachongOk_);
	}
	if(__fm__.readBit()){
		s->writeType(skillLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(huweiPosition_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)bp0_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)bp1_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		if (baby_.is_null()) const_cast<Ref<COM_BattleEntityInformation>&>(baby_) = memnew(COM_BattleEntityInformation);
		baby_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)eraseEntities_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = eraseEntities_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)targets_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportTarget> __elem = targets_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportTarget);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)stateIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportState> __elem = stateIds_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportState);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)counters_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportActionCounter> __elem = counters_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportActionCounter);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)dynamicEntities_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_BattleEntityInformation> __elem = dynamicEntities_[i];
			if (__elem.is_null()) __elem = memnew(COM_BattleEntityInformation);
			__elem->serialize(s);
		}
	}
}

bool COM_ReportAction::deserialize(ProtocolReader* r) {
	if(!COM_Order::deserialize(r)) return false;
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		zhuachongOk_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(skillLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(huweiPosition_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 22) return false;
		bp0_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 22) return false;
		bp1_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if (baby_.is_null()) const_cast<Ref<COM_BattleEntityInformation>&>(baby_) = memnew(COM_BattleEntityInformation);
		if(!baby_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			eraseEntities_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				eraseEntities_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			targets_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportTarget> __elem = memnew(COM_ReportTarget);
				if(!__elem->deserialize(r)) return false;
				targets_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			stateIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportState> __elem = memnew(COM_ReportState);
				if(!__elem->deserialize(r)) return false;
				stateIds_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			counters_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportActionCounter> __elem = memnew(COM_ReportActionCounter);
				if(!__elem->deserialize(r)) return false;
				counters_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			dynamicEntities_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BattleEntityInformation> __elem = memnew(COM_BattleEntityInformation);
				if(!__elem->deserialize(r)) return false;
				dynamicEntities_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_BattleReport::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_stateIds_"), &COM_BattleReport::get_stateIds_);
	ClassDB::bind_method(D_METHOD("set_stateIds_", "p_val"), &COM_BattleReport::set_stateIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "stateIds_"), "set_stateIds_", "get_stateIds_");
	ClassDB::bind_method(D_METHOD("get_actionResults_"), &COM_BattleReport::get_actionResults_);
	ClassDB::bind_method(D_METHOD("set_actionResults_", "p_val"), &COM_BattleReport::set_actionResults_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "actionResults_"), "set_actionResults_", "get_actionResults_");
	ClassDB::bind_method(D_METHOD("get_targets_"), &COM_BattleReport::get_targets_);
	ClassDB::bind_method(D_METHOD("set_targets_", "p_val"), &COM_BattleReport::set_targets_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "targets_"), "set_targets_", "get_targets_");
	ClassDB::bind_method(D_METHOD("get_waveEntities_"), &COM_BattleReport::get_waveEntities_);
	ClassDB::bind_method(D_METHOD("set_waveEntities_", "p_val"), &COM_BattleReport::set_waveEntities_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "waveEntities_"), "set_waveEntities_", "get_waveEntities_");
}

void COM_BattleReport::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(stateIds_.size()?true:false);
	__fm__.writeBit(actionResults_.size()?true:false);
	__fm__.writeBit(targets_.size()?true:false);
	__fm__.writeBit(waveEntities_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)stateIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportState> __elem = stateIds_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportState);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)actionResults_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportAction> __elem = actionResults_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportAction);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)targets_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ReportTarget> __elem = targets_[i];
			if (__elem.is_null()) __elem = memnew(COM_ReportTarget);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)waveEntities_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_BattleEntityInformation> __elem = waveEntities_[i];
			if (__elem.is_null()) __elem = memnew(COM_BattleEntityInformation);
			__elem->serialize(s);
		}
	}
}

bool COM_BattleReport::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			stateIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportState> __elem = memnew(COM_ReportState);
				if(!__elem->deserialize(r)) return false;
				stateIds_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			actionResults_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportAction> __elem = memnew(COM_ReportAction);
				if(!__elem->deserialize(r)) return false;
				actionResults_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			targets_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ReportTarget> __elem = memnew(COM_ReportTarget);
				if(!__elem->deserialize(r)) return false;
				targets_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			waveEntities_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BattleEntityInformation> __elem = memnew(COM_BattleEntityInformation);
				if(!__elem->deserialize(r)) return false;
				waveEntities_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_InitBattle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_battleId_"), &COM_InitBattle::get_battleId_);
	ClassDB::bind_method(D_METHOD("set_battleId_", "p_val"), &COM_InitBattle::set_battleId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "battleId_"), "set_battleId_", "get_battleId_");
	ClassDB::bind_method(D_METHOD("get_bt_"), &COM_InitBattle::get_bt_);
	ClassDB::bind_method(D_METHOD("set_bt_", "p_val"), &COM_InitBattle::set_bt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "bt_"), "set_bt_", "get_bt_");
	ClassDB::bind_method(D_METHOD("get_roundCount_"), &COM_InitBattle::get_roundCount_);
	ClassDB::bind_method(D_METHOD("set_roundCount_", "p_val"), &COM_InitBattle::set_roundCount_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roundCount_"), "set_roundCount_", "get_roundCount_");
	ClassDB::bind_method(D_METHOD("get_opType_"), &COM_InitBattle::get_opType_);
	ClassDB::bind_method(D_METHOD("set_opType_", "p_val"), &COM_InitBattle::set_opType_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "opType_"), "set_opType_", "get_opType_");
	ClassDB::bind_method(D_METHOD("get_sneakAttack_"), &COM_InitBattle::get_sneakAttack_);
	ClassDB::bind_method(D_METHOD("set_sneakAttack_", "p_val"), &COM_InitBattle::set_sneakAttack_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sneakAttack_"), "set_sneakAttack_", "get_sneakAttack_");
	ClassDB::bind_method(D_METHOD("get_actors_"), &COM_InitBattle::get_actors_);
	ClassDB::bind_method(D_METHOD("set_actors_", "p_val"), &COM_InitBattle::set_actors_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "actors_"), "set_actors_", "get_actors_");
}

void COM_InitBattle::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((battleId_==0)?false:true);
	__fm__.writeBit(bt_?true:false);
	__fm__.writeBit((roundCount_==0)?false:true);
	__fm__.writeBit(opType_?true:false);
	__fm__.writeBit(sneakAttack_?true:false);
	__fm__.writeBit(actors_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(battleId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)bt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(roundCount_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)opType_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)sneakAttack_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)actors_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_BattleEntityInformation> __elem = actors_[i];
			if (__elem.is_null()) __elem = memnew(COM_BattleEntityInformation);
			__elem->serialize(s);
		}
	}
}

bool COM_InitBattle::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(battleId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 10) return false;
		bt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(roundCount_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 4) return false;
		opType_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 4) return false;
		sneakAttack_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			actors_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BattleEntityInformation> __elem = memnew(COM_BattleEntityInformation);
				if(!__elem->deserialize(r)) return false;
				actors_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_CreateTeamInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_CreateTeamInfo::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_CreateTeamInfo::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_maxMemberSize_"), &COM_CreateTeamInfo::get_maxMemberSize_);
	ClassDB::bind_method(D_METHOD("set_maxMemberSize_", "p_val"), &COM_CreateTeamInfo::set_maxMemberSize_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "maxMemberSize_"), "set_maxMemberSize_", "get_maxMemberSize_");
	ClassDB::bind_method(D_METHOD("get_name_"), &COM_CreateTeamInfo::get_name_);
	ClassDB::bind_method(D_METHOD("set_name_", "p_val"), &COM_CreateTeamInfo::set_name_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name_"), "set_name_", "get_name_");
	ClassDB::bind_method(D_METHOD("get_pwd_"), &COM_CreateTeamInfo::get_pwd_);
	ClassDB::bind_method(D_METHOD("set_pwd_", "p_val"), &COM_CreateTeamInfo::set_pwd_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pwd_"), "set_pwd_", "get_pwd_");
	ClassDB::bind_method(D_METHOD("get_minLevel_"), &COM_CreateTeamInfo::get_minLevel_);
	ClassDB::bind_method(D_METHOD("set_minLevel_", "p_val"), &COM_CreateTeamInfo::set_minLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "minLevel_"), "set_minLevel_", "get_minLevel_");
	ClassDB::bind_method(D_METHOD("get_maxLevel_"), &COM_CreateTeamInfo::get_maxLevel_);
	ClassDB::bind_method(D_METHOD("set_maxLevel_", "p_val"), &COM_CreateTeamInfo::set_maxLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "maxLevel_"), "set_maxLevel_", "get_maxLevel_");
}

void COM_CreateTeamInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit((maxMemberSize_==0)?false:true);
	__fm__.writeBit(name_.length()?true:false);
	__fm__.writeBit(pwd_.length()?true:false);
	__fm__.writeBit((minLevel_==0)?false:true);
	__fm__.writeBit((maxLevel_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(maxMemberSize_);
	}
	if(__fm__.readBit()){
		s->writeType(name_);
	}
	if(__fm__.readBit()){
		s->writeType(pwd_);
	}
	if(__fm__.readBit()){
		s->writeType(minLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(maxLevel_);
	}
}

bool COM_CreateTeamInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(maxMemberSize_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(name_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pwd_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(minLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(maxLevel_)) return false;
	}
	return true;
}

void COM_SimpleTeamInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_teamId_"), &COM_SimpleTeamInfo::get_teamId_);
	ClassDB::bind_method(D_METHOD("set_teamId_", "p_val"), &COM_SimpleTeamInfo::set_teamId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "teamId_"), "set_teamId_", "get_teamId_");
	ClassDB::bind_method(D_METHOD("get_curMemberSize_"), &COM_SimpleTeamInfo::get_curMemberSize_);
	ClassDB::bind_method(D_METHOD("set_curMemberSize_", "p_val"), &COM_SimpleTeamInfo::set_curMemberSize_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "curMemberSize_"), "set_curMemberSize_", "get_curMemberSize_");
	ClassDB::bind_method(D_METHOD("get_leaderName_"), &COM_SimpleTeamInfo::get_leaderName_);
	ClassDB::bind_method(D_METHOD("set_leaderName_", "p_val"), &COM_SimpleTeamInfo::set_leaderName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "leaderName_"), "set_leaderName_", "get_leaderName_");
	ClassDB::bind_method(D_METHOD("get_job_"), &COM_SimpleTeamInfo::get_job_);
	ClassDB::bind_method(D_METHOD("set_job_", "p_val"), &COM_SimpleTeamInfo::set_job_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "job_"), "set_job_", "get_job_");
	ClassDB::bind_method(D_METHOD("get_joblevel_"), &COM_SimpleTeamInfo::get_joblevel_);
	ClassDB::bind_method(D_METHOD("set_joblevel_", "p_val"), &COM_SimpleTeamInfo::set_joblevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "joblevel_"), "set_joblevel_", "get_joblevel_");
	ClassDB::bind_method(D_METHOD("get_needPassword_"), &COM_SimpleTeamInfo::get_needPassword_);
	ClassDB::bind_method(D_METHOD("set_needPassword_", "p_val"), &COM_SimpleTeamInfo::set_needPassword_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "needPassword_"), "set_needPassword_", "get_needPassword_");
	ClassDB::bind_method(D_METHOD("get_isRunning_"), &COM_SimpleTeamInfo::get_isRunning_);
	ClassDB::bind_method(D_METHOD("set_isRunning_", "p_val"), &COM_SimpleTeamInfo::set_isRunning_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isRunning_"), "set_isRunning_", "get_isRunning_");
	ClassDB::bind_method(D_METHOD("get_isWelcome_"), &COM_SimpleTeamInfo::get_isWelcome_);
	ClassDB::bind_method(D_METHOD("set_isWelcome_", "p_val"), &COM_SimpleTeamInfo::set_isWelcome_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isWelcome_"), "set_isWelcome_", "get_isWelcome_");
}

void COM_SimpleTeamInfo::serialize(ProtocolWriter* s) const {
	COM_CreateTeamInfo::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((teamId_==0)?false:true);
	__fm__.writeBit((curMemberSize_==0)?false:true);
	__fm__.writeBit(leaderName_.length()?true:false);
	__fm__.writeBit(job_?true:false);
	__fm__.writeBit((joblevel_==0)?false:true);
	__fm__.writeBit(needPassword_);
	__fm__.writeBit(isRunning_);
	__fm__.writeBit(isWelcome_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(teamId_);
	}
	if(__fm__.readBit()){
		s->writeType(curMemberSize_);
	}
	if(__fm__.readBit()){
		s->writeType(leaderName_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)job_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(joblevel_);
	}
	if(__fm__.readBit()){
		s->writeType(needPassword_);
	}
	if(__fm__.readBit()){
		s->writeType(isRunning_);
	}
	if(__fm__.readBit()){
		s->writeType(isWelcome_);
	}
}

bool COM_SimpleTeamInfo::deserialize(ProtocolReader* r) {
	if(!COM_CreateTeamInfo::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(teamId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(curMemberSize_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(leaderName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		job_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(joblevel_)) return false;
	}
	if(__fm__.readBit()){
		needPassword_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isRunning_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isWelcome_ = __fm__.readBit();
	}
	return true;
}

void COM_TeamInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_members_"), &COM_TeamInfo::get_members_);
	ClassDB::bind_method(D_METHOD("set_members_", "p_val"), &COM_TeamInfo::set_members_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "members_"), "set_members_", "get_members_");
}

void COM_TeamInfo::serialize(ProtocolWriter* s) const {
	COM_SimpleTeamInfo::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(members_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)members_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_SimplePlayerInst> __elem = members_[i];
			if (__elem.is_null()) __elem = memnew(COM_SimplePlayerInst);
			__elem->serialize(s);
		}
	}
}

bool COM_TeamInfo::deserialize(ProtocolReader* r) {
	if(!COM_SimpleTeamInfo::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			members_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimplePlayerInst> __elem = memnew(COM_SimplePlayerInst);
				if(!__elem->deserialize(r)) return false;
				members_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_JJCBattleMsg::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_defier_"), &COM_JJCBattleMsg::get_defier_);
	ClassDB::bind_method(D_METHOD("set_defier_", "p_val"), &COM_JJCBattleMsg::set_defier_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "defier_"), "set_defier_", "get_defier_");
	ClassDB::bind_method(D_METHOD("get_bydefier_"), &COM_JJCBattleMsg::get_bydefier_);
	ClassDB::bind_method(D_METHOD("set_bydefier_", "p_val"), &COM_JJCBattleMsg::set_bydefier_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "bydefier_"), "set_bydefier_", "get_bydefier_");
	ClassDB::bind_method(D_METHOD("get_rank_"), &COM_JJCBattleMsg::get_rank_);
	ClassDB::bind_method(D_METHOD("set_rank_", "p_val"), &COM_JJCBattleMsg::set_rank_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rank_"), "set_rank_", "get_rank_");
	ClassDB::bind_method(D_METHOD("get_isWin_"), &COM_JJCBattleMsg::get_isWin_);
	ClassDB::bind_method(D_METHOD("set_isWin_", "p_val"), &COM_JJCBattleMsg::set_isWin_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isWin_"), "set_isWin_", "get_isWin_");
	ClassDB::bind_method(D_METHOD("get_curTime_"), &COM_JJCBattleMsg::get_curTime_);
	ClassDB::bind_method(D_METHOD("set_curTime_", "p_val"), &COM_JJCBattleMsg::set_curTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "curTime_"), "set_curTime_", "get_curTime_");
}

void COM_JJCBattleMsg::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(defier_.length()?true:false);
	__fm__.writeBit(bydefier_.length()?true:false);
	__fm__.writeBit((rank_==0)?false:true);
	__fm__.writeBit(isWin_);
	__fm__.writeBit((curTime_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(defier_);
	}
	if(__fm__.readBit()){
		s->writeType(bydefier_);
	}
	if(__fm__.readBit()){
		s->writeType(rank_);
	}
	if(__fm__.readBit()){
		s->writeType(isWin_);
	}
	if(__fm__.readBit()){
		s->writeType(curTime_);
	}
}

bool COM_JJCBattleMsg::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(defier_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(bydefier_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rank_)) return false;
	}
	if(__fm__.readBit()){
		isWin_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(curTime_)) return false;
	}
	return true;
}

void COM_BattleEmp::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_empBattleGroup_"), &COM_BattleEmp::get_empBattleGroup_);
	ClassDB::bind_method(D_METHOD("set_empBattleGroup_", "p_val"), &COM_BattleEmp::set_empBattleGroup_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "empBattleGroup_"), "set_empBattleGroup_", "get_empBattleGroup_");
	ClassDB::bind_method(D_METHOD("get_employeeGroup1_"), &COM_BattleEmp::get_employeeGroup1_);
	ClassDB::bind_method(D_METHOD("set_employeeGroup1_", "p_val"), &COM_BattleEmp::set_employeeGroup1_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "employeeGroup1_"), "set_employeeGroup1_", "get_employeeGroup1_");
	ClassDB::bind_method(D_METHOD("get_employeeGroup2_"), &COM_BattleEmp::get_employeeGroup2_);
	ClassDB::bind_method(D_METHOD("set_employeeGroup2_", "p_val"), &COM_BattleEmp::set_employeeGroup2_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "employeeGroup2_"), "set_employeeGroup2_", "get_employeeGroup2_");
}

void COM_BattleEmp::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(empBattleGroup_?true:false);
	__fm__.writeBit(employeeGroup1_.size()?true:false);
	__fm__.writeBit(employeeGroup2_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)empBattleGroup_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)employeeGroup1_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = employeeGroup1_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)employeeGroup2_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = employeeGroup2_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_BattleEmp::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 5) return false;
		empBattleGroup_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			employeeGroup1_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				employeeGroup1_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			employeeGroup2_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				employeeGroup2_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_Gather::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_gatherId_"), &COM_Gather::get_gatherId_);
	ClassDB::bind_method(D_METHOD("set_gatherId_", "p_val"), &COM_Gather::set_gatherId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "gatherId_"), "set_gatherId_", "get_gatherId_");
	ClassDB::bind_method(D_METHOD("get_flag_"), &COM_Gather::get_flag_);
	ClassDB::bind_method(D_METHOD("set_flag_", "p_val"), &COM_Gather::set_flag_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "flag_"), "set_flag_", "get_flag_");
	ClassDB::bind_method(D_METHOD("get_num_"), &COM_Gather::get_num_);
	ClassDB::bind_method(D_METHOD("set_num_", "p_val"), &COM_Gather::set_num_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "num_"), "set_num_", "get_num_");
}

void COM_Gather::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((gatherId_==0)?false:true);
	__fm__.writeBit(flag_?true:false);
	__fm__.writeBit((num_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(gatherId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)flag_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(num_);
	}
}

bool COM_Gather::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(gatherId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 4) return false;
		flag_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(num_)) return false;
	}
	return true;
}

void SGE_DBPlayerData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_versionNumber_"), &SGE_DBPlayerData::get_versionNumber_);
	ClassDB::bind_method(D_METHOD("set_versionNumber_", "p_val"), &SGE_DBPlayerData::set_versionNumber_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "versionNumber_"), "set_versionNumber_", "get_versionNumber_");
	ClassDB::bind_method(D_METHOD("get_freeze_"), &SGE_DBPlayerData::get_freeze_);
	ClassDB::bind_method(D_METHOD("set_freeze_", "p_val"), &SGE_DBPlayerData::set_freeze_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "freeze_"), "set_freeze_", "get_freeze_");
	ClassDB::bind_method(D_METHOD("get_seal_"), &SGE_DBPlayerData::get_seal_);
	ClassDB::bind_method(D_METHOD("set_seal_", "p_val"), &SGE_DBPlayerData::set_seal_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "seal_"), "set_seal_", "get_seal_");
	ClassDB::bind_method(D_METHOD("get_signs_"), &SGE_DBPlayerData::get_signs_);
	ClassDB::bind_method(D_METHOD("set_signs_", "p_val"), &SGE_DBPlayerData::set_signs_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "signs_"), "set_signs_", "get_signs_");
	ClassDB::bind_method(D_METHOD("get_sellIdMax_"), &SGE_DBPlayerData::get_sellIdMax_);
	ClassDB::bind_method(D_METHOD("set_sellIdMax_", "p_val"), &SGE_DBPlayerData::set_sellIdMax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sellIdMax_"), "set_sellIdMax_", "get_sellIdMax_");
	ClassDB::bind_method(D_METHOD("get_push_"), &SGE_DBPlayerData::get_push_);
	ClassDB::bind_method(D_METHOD("set_push_", "p_val"), &SGE_DBPlayerData::set_push_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "push_"), "set_push_", "get_push_");
	ClassDB::bind_method(D_METHOD("get_acceptRandQuestCounter_"), &SGE_DBPlayerData::get_acceptRandQuestCounter_);
	ClassDB::bind_method(D_METHOD("set_acceptRandQuestCounter_", "p_val"), &SGE_DBPlayerData::set_acceptRandQuestCounter_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "acceptRandQuestCounter_"), "set_acceptRandQuestCounter_", "get_acceptRandQuestCounter_");
	ClassDB::bind_method(D_METHOD("get_submitRandQuestCounter_"), &SGE_DBPlayerData::get_submitRandQuestCounter_);
	ClassDB::bind_method(D_METHOD("set_submitRandQuestCounter_", "p_val"), &SGE_DBPlayerData::set_submitRandQuestCounter_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "submitRandQuestCounter_"), "set_submitRandQuestCounter_", "get_submitRandQuestCounter_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &SGE_DBPlayerData::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &SGE_DBPlayerData::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_itemStoreSize_"), &SGE_DBPlayerData::get_itemStoreSize_);
	ClassDB::bind_method(D_METHOD("set_itemStoreSize_", "p_val"), &SGE_DBPlayerData::set_itemStoreSize_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemStoreSize_"), "set_itemStoreSize_", "get_itemStoreSize_");
	ClassDB::bind_method(D_METHOD("get_babyStoreSize_"), &SGE_DBPlayerData::get_babyStoreSize_);
	ClassDB::bind_method(D_METHOD("set_babyStoreSize_", "p_val"), &SGE_DBPlayerData::set_babyStoreSize_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyStoreSize_"), "set_babyStoreSize_", "get_babyStoreSize_");
	ClassDB::bind_method(D_METHOD("get_orders_"), &SGE_DBPlayerData::get_orders_);
	ClassDB::bind_method(D_METHOD("set_orders_", "p_val"), &SGE_DBPlayerData::set_orders_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "orders_"), "set_orders_", "get_orders_");
	ClassDB::bind_method(D_METHOD("get_loginTime_"), &SGE_DBPlayerData::get_loginTime_);
	ClassDB::bind_method(D_METHOD("set_loginTime_", "p_val"), &SGE_DBPlayerData::set_loginTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "loginTime_"), "set_loginTime_", "get_loginTime_");
	ClassDB::bind_method(D_METHOD("get_logoutTime_"), &SGE_DBPlayerData::get_logoutTime_);
	ClassDB::bind_method(D_METHOD("set_logoutTime_", "p_val"), &SGE_DBPlayerData::set_logoutTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "logoutTime_"), "set_logoutTime_", "get_logoutTime_");
	ClassDB::bind_method(D_METHOD("get_genItemMaxGuid_"), &SGE_DBPlayerData::get_genItemMaxGuid_);
	ClassDB::bind_method(D_METHOD("set_genItemMaxGuid_", "p_val"), &SGE_DBPlayerData::set_genItemMaxGuid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "genItemMaxGuid_"), "set_genItemMaxGuid_", "get_genItemMaxGuid_");
	ClassDB::bind_method(D_METHOD("get_gaterMaxNum_"), &SGE_DBPlayerData::get_gaterMaxNum_);
	ClassDB::bind_method(D_METHOD("set_gaterMaxNum_", "p_val"), &SGE_DBPlayerData::set_gaterMaxNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "gaterMaxNum_"), "set_gaterMaxNum_", "get_gaterMaxNum_");
	ClassDB::bind_method(D_METHOD("get_firstRollEmployeeCon_"), &SGE_DBPlayerData::get_firstRollEmployeeCon_);
	ClassDB::bind_method(D_METHOD("set_firstRollEmployeeCon_", "p_val"), &SGE_DBPlayerData::set_firstRollEmployeeCon_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "firstRollEmployeeCon_"), "set_firstRollEmployeeCon_", "get_firstRollEmployeeCon_");
	ClassDB::bind_method(D_METHOD("get_firstRollEmployeeDia_"), &SGE_DBPlayerData::get_firstRollEmployeeDia_);
	ClassDB::bind_method(D_METHOD("set_firstRollEmployeeDia_", "p_val"), &SGE_DBPlayerData::set_firstRollEmployeeDia_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "firstRollEmployeeDia_"), "set_firstRollEmployeeDia_", "get_firstRollEmployeeDia_");
	ClassDB::bind_method(D_METHOD("get_employees_"), &SGE_DBPlayerData::get_employees_);
	ClassDB::bind_method(D_METHOD("set_employees_", "p_val"), &SGE_DBPlayerData::set_employees_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "employees_"), "set_employees_", "get_employees_");
	ClassDB::bind_method(D_METHOD("get_itemStorage_"), &SGE_DBPlayerData::get_itemStorage_);
	ClassDB::bind_method(D_METHOD("set_itemStorage_", "p_val"), &SGE_DBPlayerData::set_itemStorage_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "itemStorage_"), "set_itemStorage_", "get_itemStorage_");
	ClassDB::bind_method(D_METHOD("get_babyStorage_"), &SGE_DBPlayerData::get_babyStorage_);
	ClassDB::bind_method(D_METHOD("set_babyStorage_", "p_val"), &SGE_DBPlayerData::set_babyStorage_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "babyStorage_"), "set_babyStorage_", "get_babyStorage_");
	ClassDB::bind_method(D_METHOD("get_babies_"), &SGE_DBPlayerData::get_babies_);
	ClassDB::bind_method(D_METHOD("set_babies_", "p_val"), &SGE_DBPlayerData::set_babies_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "babies_"), "set_babies_", "get_babies_");
	ClassDB::bind_method(D_METHOD("get_bagItems_"), &SGE_DBPlayerData::get_bagItems_);
	ClassDB::bind_method(D_METHOD("set_bagItems_", "p_val"), &SGE_DBPlayerData::set_bagItems_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "bagItems_"), "set_bagItems_", "get_bagItems_");
	ClassDB::bind_method(D_METHOD("get_quests_"), &SGE_DBPlayerData::get_quests_);
	ClassDB::bind_method(D_METHOD("set_quests_", "p_val"), &SGE_DBPlayerData::set_quests_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "quests_"), "set_quests_", "get_quests_");
	ClassDB::bind_method(D_METHOD("get_completeQuests_"), &SGE_DBPlayerData::get_completeQuests_);
	ClassDB::bind_method(D_METHOD("set_completeQuests_", "p_val"), &SGE_DBPlayerData::set_completeQuests_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "completeQuests_"), "set_completeQuests_", "get_completeQuests_");
	ClassDB::bind_method(D_METHOD("get_mineReward_"), &SGE_DBPlayerData::get_mineReward_);
	ClassDB::bind_method(D_METHOD("set_mineReward_", "p_val"), &SGE_DBPlayerData::set_mineReward_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "mineReward_"), "set_mineReward_", "get_mineReward_");
	ClassDB::bind_method(D_METHOD("get_jjcBattleMsg_"), &SGE_DBPlayerData::get_jjcBattleMsg_);
	ClassDB::bind_method(D_METHOD("set_jjcBattleMsg_", "p_val"), &SGE_DBPlayerData::set_jjcBattleMsg_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "jjcBattleMsg_"), "set_jjcBattleMsg_", "get_jjcBattleMsg_");
	ClassDB::bind_method(D_METHOD("get_friend_"), &SGE_DBPlayerData::get_friend_);
	ClassDB::bind_method(D_METHOD("set_friend_", "p_val"), &SGE_DBPlayerData::set_friend_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "friend_"), "set_friend_", "get_friend_");
	ClassDB::bind_method(D_METHOD("get_blacklist_"), &SGE_DBPlayerData::get_blacklist_);
	ClassDB::bind_method(D_METHOD("set_blacklist_", "p_val"), &SGE_DBPlayerData::set_blacklist_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "blacklist_"), "set_blacklist_", "get_blacklist_");
	ClassDB::bind_method(D_METHOD("get_achValues_"), &SGE_DBPlayerData::get_achValues_);
	ClassDB::bind_method(D_METHOD("set_achValues_", "p_val"), &SGE_DBPlayerData::set_achValues_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "achValues_"), "set_achValues_", "get_achValues_");
	ClassDB::bind_method(D_METHOD("get_achievement_"), &SGE_DBPlayerData::get_achievement_);
	ClassDB::bind_method(D_METHOD("set_achievement_", "p_val"), &SGE_DBPlayerData::set_achievement_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "achievement_"), "set_achievement_", "get_achievement_");
	ClassDB::bind_method(D_METHOD("get_empBattleGroup_"), &SGE_DBPlayerData::get_empBattleGroup_);
	ClassDB::bind_method(D_METHOD("set_empBattleGroup_", "p_val"), &SGE_DBPlayerData::set_empBattleGroup_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "empBattleGroup_"), "set_empBattleGroup_", "get_empBattleGroup_");
	ClassDB::bind_method(D_METHOD("get_employeeGroup1_"), &SGE_DBPlayerData::get_employeeGroup1_);
	ClassDB::bind_method(D_METHOD("set_employeeGroup1_", "p_val"), &SGE_DBPlayerData::set_employeeGroup1_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "employeeGroup1_"), "set_employeeGroup1_", "get_employeeGroup1_");
	ClassDB::bind_method(D_METHOD("get_employeeGroup2_"), &SGE_DBPlayerData::get_employeeGroup2_);
	ClassDB::bind_method(D_METHOD("set_employeeGroup2_", "p_val"), &SGE_DBPlayerData::set_employeeGroup2_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "employeeGroup2_"), "set_employeeGroup2_", "get_employeeGroup2_");
	ClassDB::bind_method(D_METHOD("get_gatherData_"), &SGE_DBPlayerData::get_gatherData_);
	ClassDB::bind_method(D_METHOD("set_gatherData_", "p_val"), &SGE_DBPlayerData::set_gatherData_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "gatherData_"), "set_gatherData_", "get_gatherData_");
	ClassDB::bind_method(D_METHOD("get_compoundList_"), &SGE_DBPlayerData::get_compoundList_);
	ClassDB::bind_method(D_METHOD("set_compoundList_", "p_val"), &SGE_DBPlayerData::set_compoundList_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "compoundList_"), "set_compoundList_", "get_compoundList_");
}

void SGE_DBPlayerData::serialize(ProtocolWriter* s) const {
	COM_PlayerInst::serialize(s);
	//field mask
	FieldMask<5> __fm__;
	__fm__.writeBit((versionNumber_==0)?false:true);
	__fm__.writeBit(freeze_);
	__fm__.writeBit(seal_);
	__fm__.writeBit((signs_==0)?false:true);
	__fm__.writeBit((sellIdMax_==0)?false:true);
	__fm__.writeBit((push_==0)?false:true);
	__fm__.writeBit((acceptRandQuestCounter_==0)?false:true);
	__fm__.writeBit((submitRandQuestCounter_==0)?false:true);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit((itemStoreSize_==0)?false:true);
	__fm__.writeBit((babyStoreSize_==0)?false:true);
	__fm__.writeBit(orders_.size()?true:false);
	__fm__.writeBit((loginTime_==0)?false:true);
	__fm__.writeBit((logoutTime_==0)?false:true);
	__fm__.writeBit((genItemMaxGuid_==0)?false:true);
	__fm__.writeBit((gaterMaxNum_==0)?false:true);
	__fm__.writeBit(firstRollEmployeeCon_);
	__fm__.writeBit(firstRollEmployeeDia_);
	__fm__.writeBit(employees_.size()?true:false);
	__fm__.writeBit(itemStorage_.size()?true:false);
	__fm__.writeBit(babyStorage_.size()?true:false);
	__fm__.writeBit(babies_.size()?true:false);
	__fm__.writeBit(bagItems_.size()?true:false);
	__fm__.writeBit(quests_.size()?true:false);
	__fm__.writeBit(completeQuests_.size()?true:false);
	__fm__.writeBit(mineReward_.size()?true:false);
	__fm__.writeBit(jjcBattleMsg_.size()?true:false);
	__fm__.writeBit(friend_.size()?true:false);
	__fm__.writeBit(blacklist_.size()?true:false);
	__fm__.writeBit(achValues_.size()?true:false);
	__fm__.writeBit(achievement_.size()?true:false);
	__fm__.writeBit(empBattleGroup_?true:false);
	__fm__.writeBit(employeeGroup1_.size()?true:false);
	__fm__.writeBit(employeeGroup2_.size()?true:false);
	__fm__.writeBit(gatherData_.size()?true:false);
	__fm__.writeBit(compoundList_.size()?true:false);
	s->write((const void*)__fm__.masks_, 5);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(versionNumber_);
	}
	if(__fm__.readBit()){
		s->writeType(freeze_);
	}
	if(__fm__.readBit()){
		s->writeType(seal_);
	}
	if(__fm__.readBit()){
		s->writeType(signs_);
	}
	if(__fm__.readBit()){
		s->writeType(sellIdMax_);
	}
	if(__fm__.readBit()){
		s->writeType(push_);
	}
	if(__fm__.readBit()){
		s->writeType(acceptRandQuestCounter_);
	}
	if(__fm__.readBit()){
		s->writeType(submitRandQuestCounter_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(itemStoreSize_);
	}
	if(__fm__.readBit()){
		s->writeType(babyStoreSize_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)orders_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<SGE_OrderInfo> __elem = orders_[i];
			if (__elem.is_null()) __elem = memnew(SGE_OrderInfo);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		s->writeType(loginTime_);
	}
	if(__fm__.readBit()){
		s->writeType(logoutTime_);
	}
	if(__fm__.readBit()){
		s->writeType(genItemMaxGuid_);
	}
	if(__fm__.readBit()){
		s->writeType(gaterMaxNum_);
	}
	if(__fm__.readBit()){
		s->writeType(firstRollEmployeeCon_);
	}
	if(__fm__.readBit()){
		s->writeType(firstRollEmployeeDia_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)employees_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_EmployeeInst> __elem = employees_[i];
			if (__elem.is_null()) __elem = memnew(COM_EmployeeInst);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)itemStorage_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Item> __elem = itemStorage_[i];
			if (__elem.is_null()) __elem = memnew(COM_Item);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)babyStorage_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_BabyInst> __elem = babyStorage_[i];
			if (__elem.is_null()) __elem = memnew(COM_BabyInst);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)babies_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_BabyInst> __elem = babies_[i];
			if (__elem.is_null()) __elem = memnew(COM_BabyInst);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)bagItems_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Item> __elem = bagItems_[i];
			if (__elem.is_null()) __elem = memnew(COM_Item);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)quests_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_QuestInst> __elem = quests_[i];
			if (__elem.is_null()) __elem = memnew(COM_QuestInst);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)completeQuests_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = completeQuests_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)mineReward_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Item> __elem = mineReward_[i];
			if (__elem.is_null()) __elem = memnew(COM_Item);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)jjcBattleMsg_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_JJCBattleMsg> __elem = jjcBattleMsg_[i];
			if (__elem.is_null()) __elem = memnew(COM_JJCBattleMsg);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)friend_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ContactInfo> __elem = friend_[i];
			if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)blacklist_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ContactInfo> __elem = blacklist_[i];
			if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)achValues_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = achValues_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)achievement_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Achievement> __elem = achievement_[i];
			if (__elem.is_null()) __elem = memnew(COM_Achievement);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)empBattleGroup_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)employeeGroup1_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = employeeGroup1_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)employeeGroup2_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = employeeGroup2_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)gatherData_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Gather> __elem = gatherData_[i];
			if (__elem.is_null()) __elem = memnew(COM_Gather);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)compoundList_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = compoundList_[i];
			s->writeType(__tmp);
		}
	}
}

bool SGE_DBPlayerData::deserialize(ProtocolReader* r) {
	if(!COM_PlayerInst::deserialize(r)) return false;
	//field mask
	FieldMask<5> __fm__;
	if(!r->read((void*)__fm__.masks_, 5)) return false;
	if(__fm__.readBit()){
		if(!r->readType(versionNumber_)) return false;
	}
	if(__fm__.readBit()){
		freeze_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		seal_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(signs_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sellIdMax_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(push_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(acceptRandQuestCounter_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(submitRandQuestCounter_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemStoreSize_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyStoreSize_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			orders_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<SGE_OrderInfo> __elem = memnew(SGE_OrderInfo);
				if(!__elem->deserialize(r)) return false;
				orders_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(loginTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(logoutTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(genItemMaxGuid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(gaterMaxNum_)) return false;
	}
	if(__fm__.readBit()){
		firstRollEmployeeCon_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		firstRollEmployeeDia_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			employees_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EmployeeInst> __elem = memnew(COM_EmployeeInst);
				if(!__elem->deserialize(r)) return false;
				employees_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			itemStorage_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				itemStorage_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			babyStorage_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyInst> __elem = memnew(COM_BabyInst);
				if(!__elem->deserialize(r)) return false;
				babyStorage_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			babies_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyInst> __elem = memnew(COM_BabyInst);
				if(!__elem->deserialize(r)) return false;
				babies_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			bagItems_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				bagItems_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			quests_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_QuestInst> __elem = memnew(COM_QuestInst);
				if(!__elem->deserialize(r)) return false;
				quests_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			completeQuests_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				completeQuests_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			mineReward_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				mineReward_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			jjcBattleMsg_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_JJCBattleMsg> __elem = memnew(COM_JJCBattleMsg);
				if(!__elem->deserialize(r)) return false;
				jjcBattleMsg_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			friend_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				friend_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			blacklist_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				blacklist_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			achValues_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				achValues_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			achievement_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Achievement> __elem = memnew(COM_Achievement);
				if(!__elem->deserialize(r)) return false;
				achievement_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 5) return false;
		empBattleGroup_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			employeeGroup1_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				employeeGroup1_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			employeeGroup2_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				employeeGroup2_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			gatherData_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Gather> __elem = memnew(COM_Gather);
				if(!__elem->deserialize(r)) return false;
				gatherData_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			compoundList_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				compoundList_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_BattleOverClearing::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_isFly_"), &COM_BattleOverClearing::get_isFly_);
	ClassDB::bind_method(D_METHOD("set_isFly_", "p_val"), &COM_BattleOverClearing::set_isFly_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isFly_"), "set_isFly_", "get_isFly_");
	ClassDB::bind_method(D_METHOD("get_playExp_"), &COM_BattleOverClearing::get_playExp_);
	ClassDB::bind_method(D_METHOD("set_playExp_", "p_val"), &COM_BattleOverClearing::set_playExp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playExp_"), "set_playExp_", "get_playExp_");
	ClassDB::bind_method(D_METHOD("get_playLevel_"), &COM_BattleOverClearing::get_playLevel_);
	ClassDB::bind_method(D_METHOD("set_playLevel_", "p_val"), &COM_BattleOverClearing::set_playLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playLevel_"), "set_playLevel_", "get_playLevel_");
	ClassDB::bind_method(D_METHOD("get_playFree_"), &COM_BattleOverClearing::get_playFree_);
	ClassDB::bind_method(D_METHOD("set_playFree_", "p_val"), &COM_BattleOverClearing::set_playFree_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playFree_"), "set_playFree_", "get_playFree_");
	ClassDB::bind_method(D_METHOD("get_pvpJJCGrade_"), &COM_BattleOverClearing::get_pvpJJCGrade_);
	ClassDB::bind_method(D_METHOD("set_pvpJJCGrade_", "p_val"), &COM_BattleOverClearing::set_pvpJJCGrade_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "pvpJJCGrade_"), "set_pvpJJCGrade_", "get_pvpJJCGrade_");
	ClassDB::bind_method(D_METHOD("get_money_"), &COM_BattleOverClearing::get_money_);
	ClassDB::bind_method(D_METHOD("set_money_", "p_val"), &COM_BattleOverClearing::set_money_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "money_"), "set_money_", "get_money_");
	ClassDB::bind_method(D_METHOD("get_babyExp_"), &COM_BattleOverClearing::get_babyExp_);
	ClassDB::bind_method(D_METHOD("set_babyExp_", "p_val"), &COM_BattleOverClearing::set_babyExp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyExp_"), "set_babyExp_", "get_babyExp_");
	ClassDB::bind_method(D_METHOD("get_babyLevel_"), &COM_BattleOverClearing::get_babyLevel_);
	ClassDB::bind_method(D_METHOD("set_babyLevel_", "p_val"), &COM_BattleOverClearing::set_babyLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyLevel_"), "set_babyLevel_", "get_babyLevel_");
	ClassDB::bind_method(D_METHOD("get_items_"), &COM_BattleOverClearing::get_items_);
	ClassDB::bind_method(D_METHOD("set_items_", "p_val"), &COM_BattleOverClearing::set_items_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "items_"), "set_items_", "get_items_");
	ClassDB::bind_method(D_METHOD("get_skills_"), &COM_BattleOverClearing::get_skills_);
	ClassDB::bind_method(D_METHOD("set_skills_", "p_val"), &COM_BattleOverClearing::set_skills_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "skills_"), "set_skills_", "get_skills_");
}

void COM_BattleOverClearing::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(isFly_);
	__fm__.writeBit((playExp_==0)?false:true);
	__fm__.writeBit((playLevel_==0)?false:true);
	__fm__.writeBit((playFree_==0)?false:true);
	__fm__.writeBit((pvpJJCGrade_==0)?false:true);
	__fm__.writeBit((money_==0)?false:true);
	__fm__.writeBit((babyExp_==0)?false:true);
	__fm__.writeBit((babyLevel_==0)?false:true);
	__fm__.writeBit(items_.size()?true:false);
	__fm__.writeBit(skills_.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(isFly_);
	}
	if(__fm__.readBit()){
		s->writeType(playExp_);
	}
	if(__fm__.readBit()){
		s->writeType(playLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(playFree_);
	}
	if(__fm__.readBit()){
		s->writeType(pvpJJCGrade_);
	}
	if(__fm__.readBit()){
		s->writeType(money_);
	}
	if(__fm__.readBit()){
		s->writeType(babyExp_);
	}
	if(__fm__.readBit()){
		s->writeType(babyLevel_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)items_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_DropItem> __elem = items_[i];
			if (__elem.is_null()) __elem = memnew(COM_DropItem);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)skills_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_Skill> __elem = skills_[i];
			if (__elem.is_null()) __elem = memnew(COM_Skill);
			__elem->serialize(s);
		}
	}
}

bool COM_BattleOverClearing::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		isFly_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(playExp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playFree_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pvpJJCGrade_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(money_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyExp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyLevel_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			items_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_DropItem> __elem = memnew(COM_DropItem);
				if(!__elem->deserialize(r)) return false;
				items_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			skills_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Skill> __elem = memnew(COM_Skill);
				if(!__elem->deserialize(r)) return false;
				skills_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_Addprop::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_"), &COM_Addprop::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &COM_Addprop::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
	ClassDB::bind_method(D_METHOD("get_uVal_"), &COM_Addprop::get_uVal_);
	ClassDB::bind_method(D_METHOD("set_uVal_", "p_val"), &COM_Addprop::set_uVal_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "uVal_"), "set_uVal_", "get_uVal_");
}

void COM_Addprop::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(type_?true:false);
	__fm__.writeBit((uVal_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(uVal_);
	}
}

bool COM_Addprop::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 63) return false;
		type_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(uVal_)) return false;
	}
	return true;
}

void COM_ExpendItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_itemInstId_"), &COM_ExpendItem::get_itemInstId_);
	ClassDB::bind_method(D_METHOD("set_itemInstId_", "p_val"), &COM_ExpendItem::set_itemInstId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemInstId_"), "set_itemInstId_", "get_itemInstId_");
	ClassDB::bind_method(D_METHOD("get_num_"), &COM_ExpendItem::get_num_);
	ClassDB::bind_method(D_METHOD("set_num_", "p_val"), &COM_ExpendItem::set_num_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "num_"), "set_num_", "get_num_");
}

void COM_ExpendItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((itemInstId_==0)?false:true);
	__fm__.writeBit((num_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(itemInstId_);
	}
	if(__fm__.readBit()){
		s->writeType(num_);
	}
}

bool COM_ExpendItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(itemInstId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(num_)) return false;
	}
	return true;
}

void COM_Chat::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_ck_"), &COM_Chat::get_ck_);
	ClassDB::bind_method(D_METHOD("set_ck_", "p_val"), &COM_Chat::set_ck_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ck_"), "set_ck_", "get_ck_");
	ClassDB::bind_method(D_METHOD("get_isAudio_"), &COM_Chat::get_isAudio_);
	ClassDB::bind_method(D_METHOD("set_isAudio_", "p_val"), &COM_Chat::set_isAudio_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isAudio_"), "set_isAudio_", "get_isAudio_");
	ClassDB::bind_method(D_METHOD("get_content_"), &COM_Chat::get_content_);
	ClassDB::bind_method(D_METHOD("set_content_", "p_val"), &COM_Chat::set_content_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "content_"), "set_content_", "get_content_");
	ClassDB::bind_method(D_METHOD("get_audioTime_"), &COM_Chat::get_audioTime_);
	ClassDB::bind_method(D_METHOD("set_audioTime_", "p_val"), &COM_Chat::set_audioTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "audioTime_"), "set_audioTime_", "get_audioTime_");
	ClassDB::bind_method(D_METHOD("get_audio_"), &COM_Chat::get_audio_);
	ClassDB::bind_method(D_METHOD("set_audio_", "p_val"), &COM_Chat::set_audio_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "audio_"), "set_audio_", "get_audio_");
	ClassDB::bind_method(D_METHOD("get_isMe"), &COM_Chat::get_isMe);
	ClassDB::bind_method(D_METHOD("set_isMe", "p_val"), &COM_Chat::set_isMe);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isMe"), "set_isMe", "get_isMe");
	ClassDB::bind_method(D_METHOD("get_teamId_"), &COM_Chat::get_teamId_);
	ClassDB::bind_method(D_METHOD("set_teamId_", "p_val"), &COM_Chat::set_teamId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "teamId_"), "set_teamId_", "get_teamId_");
	ClassDB::bind_method(D_METHOD("get_teamType_"), &COM_Chat::get_teamType_);
	ClassDB::bind_method(D_METHOD("set_teamType_", "p_val"), &COM_Chat::set_teamType_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "teamType_"), "set_teamType_", "get_teamType_");
	ClassDB::bind_method(D_METHOD("get_teamMinLevel_"), &COM_Chat::get_teamMinLevel_);
	ClassDB::bind_method(D_METHOD("set_teamMinLevel_", "p_val"), &COM_Chat::set_teamMinLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "teamMinLevel_"), "set_teamMinLevel_", "get_teamMinLevel_");
	ClassDB::bind_method(D_METHOD("get_teamMaxLevel_"), &COM_Chat::get_teamMaxLevel_);
	ClassDB::bind_method(D_METHOD("set_teamMaxLevel_", "p_val"), &COM_Chat::set_teamMaxLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "teamMaxLevel_"), "set_teamMaxLevel_", "get_teamMaxLevel_");
	ClassDB::bind_method(D_METHOD("get_teamName_"), &COM_Chat::get_teamName_);
	ClassDB::bind_method(D_METHOD("set_teamName_", "p_val"), &COM_Chat::set_teamName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "teamName_"), "set_teamName_", "get_teamName_");
}

void COM_Chat::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(ck_?true:false);
	__fm__.writeBit(isAudio_);
	__fm__.writeBit(content_.length()?true:false);
	__fm__.writeBit((audioTime_==0)?false:true);
	__fm__.writeBit(audio_.size()?true:false);
	__fm__.writeBit(isMe);
	__fm__.writeBit((teamId_==0)?false:true);
	__fm__.writeBit(teamType_?true:false);
	__fm__.writeBit((teamMinLevel_==0)?false:true);
	__fm__.writeBit((teamMaxLevel_==0)?false:true);
	__fm__.writeBit(teamName_.length()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)ck_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(isAudio_);
	}
	if(__fm__.readBit()){
		s->writeType(content_);
	}
	if(__fm__.readBit()){
		s->writeType(audioTime_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)audio_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint8_t __tmp = audio_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		s->writeType(isMe);
	}
	if(__fm__.readBit()){
		s->writeType(teamId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)teamType_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(teamMinLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(teamMaxLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(teamName_);
	}
}

bool COM_Chat::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 8) return false;
		ck_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		isAudio_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(content_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(audioTime_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			audio_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint8_t __tmp;
				if(!r->readType(__tmp)) return false;
				audio_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		isMe = __fm__.readBit();
	}
	if(__fm__.readBit()){
		if(!r->readType(teamId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		teamType_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(teamMinLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(teamMaxLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(teamName_, 65535)) return false;
	}
	return true;
}

void COM_ChatInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_audioId_"), &COM_ChatInfo::get_audioId_);
	ClassDB::bind_method(D_METHOD("set_audioId_", "p_val"), &COM_ChatInfo::set_audioId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "audioId_"), "set_audioId_", "get_audioId_");
	ClassDB::bind_method(D_METHOD("get_assetId_"), &COM_ChatInfo::get_assetId_);
	ClassDB::bind_method(D_METHOD("set_assetId_", "p_val"), &COM_ChatInfo::set_assetId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "assetId_"), "set_assetId_", "get_assetId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_ChatInfo::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_ChatInfo::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_guildName_"), &COM_ChatInfo::get_guildName_);
	ClassDB::bind_method(D_METHOD("set_guildName_", "p_val"), &COM_ChatInfo::set_guildName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "guildName_"), "set_guildName_", "get_guildName_");
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_ChatInfo::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_ChatInfo::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
}

void COM_ChatInfo::serialize(ProtocolWriter* s) const {
	COM_Chat::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((audioId_==0)?false:true);
	__fm__.writeBit((assetId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit(guildName_.length()?true:false);
	__fm__.writeBit((instId_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(audioId_);
	}
	if(__fm__.readBit()){
		s->writeType(assetId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(guildName_);
	}
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
}

bool COM_ChatInfo::deserialize(ProtocolReader* r) {
	if(!COM_Chat::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(audioId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(assetId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	return true;
}

void COM_EndlessStair::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_rank_"), &COM_EndlessStair::get_rank_);
	ClassDB::bind_method(D_METHOD("set_rank_", "p_val"), &COM_EndlessStair::set_rank_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rank_"), "set_rank_", "get_rank_");
	ClassDB::bind_method(D_METHOD("get_name_"), &COM_EndlessStair::get_name_);
	ClassDB::bind_method(D_METHOD("set_name_", "p_val"), &COM_EndlessStair::set_name_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name_"), "set_name_", "get_name_");
	ClassDB::bind_method(D_METHOD("get_job_"), &COM_EndlessStair::get_job_);
	ClassDB::bind_method(D_METHOD("set_job_", "p_val"), &COM_EndlessStair::set_job_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "job_"), "set_job_", "get_job_");
	ClassDB::bind_method(D_METHOD("get_joblevel_"), &COM_EndlessStair::get_joblevel_);
	ClassDB::bind_method(D_METHOD("set_joblevel_", "p_val"), &COM_EndlessStair::set_joblevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "joblevel_"), "set_joblevel_", "get_joblevel_");
	ClassDB::bind_method(D_METHOD("get_assetId_"), &COM_EndlessStair::get_assetId_);
	ClassDB::bind_method(D_METHOD("set_assetId_", "p_val"), &COM_EndlessStair::set_assetId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "assetId_"), "set_assetId_", "get_assetId_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_EndlessStair::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_EndlessStair::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_rivalTime_"), &COM_EndlessStair::get_rivalTime_);
	ClassDB::bind_method(D_METHOD("set_rivalTime_", "p_val"), &COM_EndlessStair::set_rivalTime_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "rivalTime_"), "set_rivalTime_", "get_rivalTime_");
	ClassDB::bind_method(D_METHOD("get_rivalNum_"), &COM_EndlessStair::get_rivalNum_);
	ClassDB::bind_method(D_METHOD("set_rivalNum_", "p_val"), &COM_EndlessStair::set_rivalNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rivalNum_"), "set_rivalNum_", "get_rivalNum_");
}

void COM_EndlessStair::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((rank_==0)?false:true);
	__fm__.writeBit(name_.length()?true:false);
	__fm__.writeBit(job_?true:false);
	__fm__.writeBit((joblevel_==0)?false:true);
	__fm__.writeBit((assetId_==0)?false:true);
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((rivalTime_==0.0)?false:true);
	__fm__.writeBit((rivalNum_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(rank_);
	}
	if(__fm__.readBit()){
		s->writeType(name_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)job_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(joblevel_);
	}
	if(__fm__.readBit()){
		s->writeType(assetId_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(rivalTime_);
	}
	if(__fm__.readBit()){
		s->writeType(rivalNum_);
	}
}

bool COM_EndlessStair::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(rank_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(name_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 12) return false;
		job_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(joblevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(assetId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rivalTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rivalNum_)) return false;
	}
	return true;
}

void COM_BabyRankData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_BabyRankData::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_BabyRankData::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_rank_"), &COM_BabyRankData::get_rank_);
	ClassDB::bind_method(D_METHOD("set_rank_", "p_val"), &COM_BabyRankData::set_rank_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rank_"), "set_rank_", "get_rank_");
	ClassDB::bind_method(D_METHOD("get_name_"), &COM_BabyRankData::get_name_);
	ClassDB::bind_method(D_METHOD("set_name_", "p_val"), &COM_BabyRankData::set_name_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name_"), "set_name_", "get_name_");
	ClassDB::bind_method(D_METHOD("get_ownerName_"), &COM_BabyRankData::get_ownerName_);
	ClassDB::bind_method(D_METHOD("set_ownerName_", "p_val"), &COM_BabyRankData::set_ownerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "ownerName_"), "set_ownerName_", "get_ownerName_");
	ClassDB::bind_method(D_METHOD("get_ff_"), &COM_BabyRankData::get_ff_);
	ClassDB::bind_method(D_METHOD("set_ff_", "p_val"), &COM_BabyRankData::set_ff_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ff_"), "set_ff_", "get_ff_");
}

void COM_BabyRankData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit((rank_==0)?false:true);
	__fm__.writeBit(name_.length()?true:false);
	__fm__.writeBit(ownerName_.length()?true:false);
	__fm__.writeBit((ff_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(rank_);
	}
	if(__fm__.readBit()){
		s->writeType(name_);
	}
	if(__fm__.readBit()){
		s->writeType(ownerName_);
	}
	if(__fm__.readBit()){
		s->writeType(ff_);
	}
}

bool COM_BabyRankData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rank_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(name_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ownerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ff_)) return false;
	}
	return true;
}

void COM_EmployeeRankData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_instId_"), &COM_EmployeeRankData::get_instId_);
	ClassDB::bind_method(D_METHOD("set_instId_", "p_val"), &COM_EmployeeRankData::set_instId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "instId_"), "set_instId_", "get_instId_");
	ClassDB::bind_method(D_METHOD("get_rank_"), &COM_EmployeeRankData::get_rank_);
	ClassDB::bind_method(D_METHOD("set_rank_", "p_val"), &COM_EmployeeRankData::set_rank_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rank_"), "set_rank_", "get_rank_");
	ClassDB::bind_method(D_METHOD("get_name_"), &COM_EmployeeRankData::get_name_);
	ClassDB::bind_method(D_METHOD("set_name_", "p_val"), &COM_EmployeeRankData::set_name_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name_"), "set_name_", "get_name_");
	ClassDB::bind_method(D_METHOD("get_ownerName_"), &COM_EmployeeRankData::get_ownerName_);
	ClassDB::bind_method(D_METHOD("set_ownerName_", "p_val"), &COM_EmployeeRankData::set_ownerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "ownerName_"), "set_ownerName_", "get_ownerName_");
	ClassDB::bind_method(D_METHOD("get_ff_"), &COM_EmployeeRankData::get_ff_);
	ClassDB::bind_method(D_METHOD("set_ff_", "p_val"), &COM_EmployeeRankData::set_ff_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ff_"), "set_ff_", "get_ff_");
}

void COM_EmployeeRankData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((instId_==0)?false:true);
	__fm__.writeBit((rank_==0)?false:true);
	__fm__.writeBit(name_.length()?true:false);
	__fm__.writeBit(ownerName_.length()?true:false);
	__fm__.writeBit((ff_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(instId_);
	}
	if(__fm__.readBit()){
		s->writeType(rank_);
	}
	if(__fm__.readBit()){
		s->writeType(name_);
	}
	if(__fm__.readBit()){
		s->writeType(ownerName_);
	}
	if(__fm__.readBit()){
		s->writeType(ff_);
	}
}

bool COM_EmployeeRankData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(instId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rank_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(name_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ownerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ff_)) return false;
	}
	return true;
}

void COM_MailItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_MailItem::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_MailItem::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_itemStack_"), &COM_MailItem::get_itemStack_);
	ClassDB::bind_method(D_METHOD("set_itemStack_", "p_val"), &COM_MailItem::set_itemStack_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemStack_"), "set_itemStack_", "get_itemStack_");
}

void COM_MailItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((itemStack_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(itemStack_);
	}
}

bool COM_MailItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemStack_)) return false;
	}
	return true;
}

void COM_Mail::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_mailId_"), &COM_Mail::get_mailId_);
	ClassDB::bind_method(D_METHOD("set_mailId_", "p_val"), &COM_Mail::set_mailId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mailId_"), "set_mailId_", "get_mailId_");
	ClassDB::bind_method(D_METHOD("get_mailType_"), &COM_Mail::get_mailType_);
	ClassDB::bind_method(D_METHOD("set_mailType_", "p_val"), &COM_Mail::set_mailType_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mailType_"), "set_mailType_", "get_mailType_");
	ClassDB::bind_method(D_METHOD("get_timestamp_"), &COM_Mail::get_timestamp_);
	ClassDB::bind_method(D_METHOD("set_timestamp_", "p_val"), &COM_Mail::set_timestamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "timestamp_"), "set_timestamp_", "get_timestamp_");
	ClassDB::bind_method(D_METHOD("get_sendPlayerName_"), &COM_Mail::get_sendPlayerName_);
	ClassDB::bind_method(D_METHOD("set_sendPlayerName_", "p_val"), &COM_Mail::set_sendPlayerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "sendPlayerName_"), "set_sendPlayerName_", "get_sendPlayerName_");
	ClassDB::bind_method(D_METHOD("get_recvPlayerName_"), &COM_Mail::get_recvPlayerName_);
	ClassDB::bind_method(D_METHOD("set_recvPlayerName_", "p_val"), &COM_Mail::set_recvPlayerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "recvPlayerName_"), "set_recvPlayerName_", "get_recvPlayerName_");
	ClassDB::bind_method(D_METHOD("get_title_"), &COM_Mail::get_title_);
	ClassDB::bind_method(D_METHOD("set_title_", "p_val"), &COM_Mail::set_title_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "title_"), "set_title_", "get_title_");
	ClassDB::bind_method(D_METHOD("get_content_"), &COM_Mail::get_content_);
	ClassDB::bind_method(D_METHOD("set_content_", "p_val"), &COM_Mail::set_content_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "content_"), "set_content_", "get_content_");
	ClassDB::bind_method(D_METHOD("get_money_"), &COM_Mail::get_money_);
	ClassDB::bind_method(D_METHOD("set_money_", "p_val"), &COM_Mail::set_money_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "money_"), "set_money_", "get_money_");
	ClassDB::bind_method(D_METHOD("get_diamond_"), &COM_Mail::get_diamond_);
	ClassDB::bind_method(D_METHOD("set_diamond_", "p_val"), &COM_Mail::set_diamond_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "diamond_"), "set_diamond_", "get_diamond_");
	ClassDB::bind_method(D_METHOD("get_items_"), &COM_Mail::get_items_);
	ClassDB::bind_method(D_METHOD("set_items_", "p_val"), &COM_Mail::set_items_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "items_"), "set_items_", "get_items_");
	ClassDB::bind_method(D_METHOD("get_isRead_"), &COM_Mail::get_isRead_);
	ClassDB::bind_method(D_METHOD("set_isRead_", "p_val"), &COM_Mail::set_isRead_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isRead_"), "set_isRead_", "get_isRead_");
}

void COM_Mail::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((mailId_==0)?false:true);
	__fm__.writeBit(mailType_?true:false);
	__fm__.writeBit((timestamp_==0)?false:true);
	__fm__.writeBit(sendPlayerName_.length()?true:false);
	__fm__.writeBit(recvPlayerName_.length()?true:false);
	__fm__.writeBit(title_.length()?true:false);
	__fm__.writeBit(content_.length()?true:false);
	__fm__.writeBit((money_==0)?false:true);
	__fm__.writeBit((diamond_==0)?false:true);
	__fm__.writeBit(items_.size()?true:false);
	__fm__.writeBit(isRead_);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(mailId_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)mailType_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(timestamp_);
	}
	if(__fm__.readBit()){
		s->writeType(sendPlayerName_);
	}
	if(__fm__.readBit()){
		s->writeType(recvPlayerName_);
	}
	if(__fm__.readBit()){
		s->writeType(title_);
	}
	if(__fm__.readBit()){
		s->writeType(content_);
	}
	if(__fm__.readBit()){
		s->writeType(money_);
	}
	if(__fm__.readBit()){
		s->writeType(diamond_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)items_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_MailItem> __elem = items_[i];
			if (__elem.is_null()) __elem = memnew(COM_MailItem);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		s->writeType(isRead_);
	}
}

bool COM_Mail::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(mailId_)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 2) return false;
		mailType_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(timestamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sendPlayerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(recvPlayerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(title_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(content_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(money_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(diamond_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			items_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_MailItem> __elem = memnew(COM_MailItem);
				if(!__elem->deserialize(r)) return false;
				items_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		isRead_ = __fm__.readBit();
	}
	return true;
}

void COM_GuildBuilding::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_GuildBuilding::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_GuildBuilding::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_struction_"), &COM_GuildBuilding::get_struction_);
	ClassDB::bind_method(D_METHOD("set_struction_", "p_val"), &COM_GuildBuilding::set_struction_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "struction_"), "set_struction_", "get_struction_");
}

void COM_GuildBuilding::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((struction_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(struction_);
	}
}

bool COM_GuildBuilding::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(struction_)) return false;
	}
	return true;
}

void COM_GuildRequestData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_roleId_"), &COM_GuildRequestData::get_roleId_);
	ClassDB::bind_method(D_METHOD("set_roleId_", "p_val"), &COM_GuildRequestData::set_roleId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roleId_"), "set_roleId_", "get_roleId_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_GuildRequestData::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_GuildRequestData::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_roleName_"), &COM_GuildRequestData::get_roleName_);
	ClassDB::bind_method(D_METHOD("set_roleName_", "p_val"), &COM_GuildRequestData::set_roleName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "roleName_"), "set_roleName_", "get_roleName_");
	ClassDB::bind_method(D_METHOD("get_time_"), &COM_GuildRequestData::get_time_);
	ClassDB::bind_method(D_METHOD("set_time_", "p_val"), &COM_GuildRequestData::set_time_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "time_"), "set_time_", "get_time_");
	ClassDB::bind_method(D_METHOD("get_prof_"), &COM_GuildRequestData::get_prof_);
	ClassDB::bind_method(D_METHOD("set_prof_", "p_val"), &COM_GuildRequestData::set_prof_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "prof_"), "set_prof_", "get_prof_");
	ClassDB::bind_method(D_METHOD("get_profLevel_"), &COM_GuildRequestData::get_profLevel_);
	ClassDB::bind_method(D_METHOD("set_profLevel_", "p_val"), &COM_GuildRequestData::set_profLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "profLevel_"), "set_profLevel_", "get_profLevel_");
}

void COM_GuildRequestData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((roleId_==0)?false:true);
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit(roleName_.length()?true:false);
	__fm__.writeBit((time_==0)?false:true);
	__fm__.writeBit((prof_==0)?false:true);
	__fm__.writeBit((profLevel_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(roleId_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(roleName_);
	}
	if(__fm__.readBit()){
		s->writeType(time_);
	}
	if(__fm__.readBit()){
		s->writeType(prof_);
	}
	if(__fm__.readBit()){
		s->writeType(profLevel_);
	}
}

bool COM_GuildRequestData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(roleId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(time_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(prof_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(profLevel_)) return false;
	}
	return true;
}

void COM_GuildProgen::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_mId_"), &COM_GuildProgen::get_mId_);
	ClassDB::bind_method(D_METHOD("set_mId_", "p_val"), &COM_GuildProgen::set_mId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mId_"), "set_mId_", "get_mId_");
	ClassDB::bind_method(D_METHOD("get_lev_"), &COM_GuildProgen::get_lev_);
	ClassDB::bind_method(D_METHOD("set_lev_", "p_val"), &COM_GuildProgen::set_lev_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "lev_"), "set_lev_", "get_lev_");
	ClassDB::bind_method(D_METHOD("get_exp_"), &COM_GuildProgen::get_exp_);
	ClassDB::bind_method(D_METHOD("set_exp_", "p_val"), &COM_GuildProgen::set_exp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "exp_"), "set_exp_", "get_exp_");
}

void COM_GuildProgen::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((mId_==0)?false:true);
	__fm__.writeBit((lev_==0)?false:true);
	__fm__.writeBit((exp_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(mId_);
	}
	if(__fm__.readBit()){
		s->writeType(lev_);
	}
	if(__fm__.readBit()){
		s->writeType(exp_);
	}
}

bool COM_GuildProgen::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(mId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(lev_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(exp_)) return false;
	}
	return true;
}

void COM_Guild::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_guildLevel_"), &COM_Guild::get_guildLevel_);
	ClassDB::bind_method(D_METHOD("set_guildLevel_", "p_val"), &COM_Guild::set_guildLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildLevel_"), "set_guildLevel_", "get_guildLevel_");
	ClassDB::bind_method(D_METHOD("get_createTime_"), &COM_Guild::get_createTime_);
	ClassDB::bind_method(D_METHOD("set_createTime_", "p_val"), &COM_Guild::set_createTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "createTime_"), "set_createTime_", "get_createTime_");
	ClassDB::bind_method(D_METHOD("get_guildId_"), &COM_Guild::get_guildId_);
	ClassDB::bind_method(D_METHOD("set_guildId_", "p_val"), &COM_Guild::set_guildId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildId_"), "set_guildId_", "get_guildId_");
	ClassDB::bind_method(D_METHOD("get_guildContribution_"), &COM_Guild::get_guildContribution_);
	ClassDB::bind_method(D_METHOD("set_guildContribution_", "p_val"), &COM_Guild::set_guildContribution_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildContribution_"), "set_guildContribution_", "get_guildContribution_");
	ClassDB::bind_method(D_METHOD("get_fundz_"), &COM_Guild::get_fundz_);
	ClassDB::bind_method(D_METHOD("set_fundz_", "p_val"), &COM_Guild::set_fundz_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "fundz_"), "set_fundz_", "get_fundz_");
	ClassDB::bind_method(D_METHOD("get_presentNum_"), &COM_Guild::get_presentNum_);
	ClassDB::bind_method(D_METHOD("set_presentNum_", "p_val"), &COM_Guild::set_presentNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "presentNum_"), "set_presentNum_", "get_presentNum_");
	ClassDB::bind_method(D_METHOD("get_master_"), &COM_Guild::get_master_);
	ClassDB::bind_method(D_METHOD("set_master_", "p_val"), &COM_Guild::set_master_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "master_"), "set_master_", "get_master_");
	ClassDB::bind_method(D_METHOD("get_masterName_"), &COM_Guild::get_masterName_);
	ClassDB::bind_method(D_METHOD("set_masterName_", "p_val"), &COM_Guild::set_masterName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "masterName_"), "set_masterName_", "get_masterName_");
	ClassDB::bind_method(D_METHOD("get_guildName_"), &COM_Guild::get_guildName_);
	ClassDB::bind_method(D_METHOD("set_guildName_", "p_val"), &COM_Guild::set_guildName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "guildName_"), "set_guildName_", "get_guildName_");
	ClassDB::bind_method(D_METHOD("get_notice_"), &COM_Guild::get_notice_);
	ClassDB::bind_method(D_METHOD("set_notice_", "p_val"), &COM_Guild::set_notice_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "notice_"), "set_notice_", "get_notice_");
	ClassDB::bind_method(D_METHOD("get_requestList_"), &COM_Guild::get_requestList_);
	ClassDB::bind_method(D_METHOD("set_requestList_", "p_val"), &COM_Guild::set_requestList_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "requestList_"), "set_requestList_", "get_requestList_");
	ClassDB::bind_method(D_METHOD("get_noFundzDays_"), &COM_Guild::get_noFundzDays_);
	ClassDB::bind_method(D_METHOD("set_noFundzDays_", "p_val"), &COM_Guild::set_noFundzDays_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "noFundzDays_"), "set_noFundzDays_", "get_noFundzDays_");
	ClassDB::bind_method(D_METHOD("get_buildings_"), &COM_Guild::get_buildings_);
	ClassDB::bind_method(D_METHOD("set_buildings_", "p_val"), &COM_Guild::set_buildings_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "buildings_"), "set_buildings_", "get_buildings_");
	ClassDB::bind_method(D_METHOD("get_progenitus_"), &COM_Guild::get_progenitus_);
	ClassDB::bind_method(D_METHOD("set_progenitus_", "p_val"), &COM_Guild::set_progenitus_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "progenitus_"), "set_progenitus_", "get_progenitus_");
	ClassDB::bind_method(D_METHOD("get_progenitusPositions_"), &COM_Guild::get_progenitusPositions_);
	ClassDB::bind_method(D_METHOD("set_progenitusPositions_", "p_val"), &COM_Guild::set_progenitusPositions_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "progenitusPositions_"), "set_progenitusPositions_", "get_progenitusPositions_");
}

void COM_Guild::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((guildLevel_==0)?false:true);
	__fm__.writeBit((createTime_==0)?false:true);
	__fm__.writeBit((guildId_==0)?false:true);
	__fm__.writeBit((guildContribution_==0)?false:true);
	__fm__.writeBit((fundz_==0)?false:true);
	__fm__.writeBit((presentNum_==0)?false:true);
	__fm__.writeBit((master_==0)?false:true);
	__fm__.writeBit(masterName_.length()?true:false);
	__fm__.writeBit(guildName_.length()?true:false);
	__fm__.writeBit(notice_.length()?true:false);
	__fm__.writeBit(requestList_.size()?true:false);
	__fm__.writeBit((noFundzDays_==0)?false:true);
	__fm__.writeBit(buildings_.size()?true:false);
	__fm__.writeBit(progenitus_.size()?true:false);
	__fm__.writeBit(progenitusPositions_.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(guildLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(createTime_);
	}
	if(__fm__.readBit()){
		s->writeType(guildId_);
	}
	if(__fm__.readBit()){
		s->writeType(guildContribution_);
	}
	if(__fm__.readBit()){
		s->writeType(fundz_);
	}
	if(__fm__.readBit()){
		s->writeType(presentNum_);
	}
	if(__fm__.readBit()){
		s->writeType(master_);
	}
	if(__fm__.readBit()){
		s->writeType(masterName_);
	}
	if(__fm__.readBit()){
		s->writeType(guildName_);
	}
	if(__fm__.readBit()){
		s->writeType(notice_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)requestList_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_GuildRequestData> __elem = requestList_[i];
			if (__elem.is_null()) __elem = memnew(COM_GuildRequestData);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		s->writeType(noFundzDays_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)buildings_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_GuildBuilding> __elem = buildings_[i];
			if (__elem.is_null()) __elem = memnew(COM_GuildBuilding);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)progenitus_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_GuildProgen> __elem = progenitus_[i];
			if (__elem.is_null()) __elem = memnew(COM_GuildProgen);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)progenitusPositions_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = progenitusPositions_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_Guild::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(guildLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(createTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildContribution_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(fundz_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(presentNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(master_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(masterName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(notice_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			requestList_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildRequestData> __elem = memnew(COM_GuildRequestData);
				if(!__elem->deserialize(r)) return false;
				requestList_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		if(!r->readType(noFundzDays_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			buildings_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildBuilding> __elem = memnew(COM_GuildBuilding);
				if(!__elem->deserialize(r)) return false;
				buildings_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			progenitus_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildProgen> __elem = memnew(COM_GuildProgen);
				if(!__elem->deserialize(r)) return false;
				progenitus_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			progenitusPositions_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				progenitusPositions_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_GuildShopItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_shopId_"), &COM_GuildShopItem::get_shopId_);
	ClassDB::bind_method(D_METHOD("set_shopId_", "p_val"), &COM_GuildShopItem::set_shopId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "shopId_"), "set_shopId_", "get_shopId_");
	ClassDB::bind_method(D_METHOD("get_buyLimit_"), &COM_GuildShopItem::get_buyLimit_);
	ClassDB::bind_method(D_METHOD("set_buyLimit_", "p_val"), &COM_GuildShopItem::set_buyLimit_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "buyLimit_"), "set_buyLimit_", "get_buyLimit_");
}

void COM_GuildShopItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((shopId_==0)?false:true);
	__fm__.writeBit((buyLimit_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(shopId_);
	}
	if(__fm__.readBit()){
		s->writeType(buyLimit_);
	}
}

bool COM_GuildShopItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(shopId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(buyLimit_)) return false;
	}
	return true;
}

void COM_GuildMember::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_GuildMember::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_GuildMember::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_shopRefreshTimes_"), &COM_GuildMember::get_shopRefreshTimes_);
	ClassDB::bind_method(D_METHOD("set_shopRefreshTimes_", "p_val"), &COM_GuildMember::set_shopRefreshTimes_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "shopRefreshTimes_"), "set_shopRefreshTimes_", "get_shopRefreshTimes_");
	ClassDB::bind_method(D_METHOD("get_guildId_"), &COM_GuildMember::get_guildId_);
	ClassDB::bind_method(D_METHOD("set_guildId_", "p_val"), &COM_GuildMember::set_guildId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildId_"), "set_guildId_", "get_guildId_");
	ClassDB::bind_method(D_METHOD("get_profType_"), &COM_GuildMember::get_profType_);
	ClassDB::bind_method(D_METHOD("set_profType_", "p_val"), &COM_GuildMember::set_profType_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "profType_"), "set_profType_", "get_profType_");
	ClassDB::bind_method(D_METHOD("get_profLevel_"), &COM_GuildMember::get_profLevel_);
	ClassDB::bind_method(D_METHOD("set_profLevel_", "p_val"), &COM_GuildMember::set_profLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "profLevel_"), "set_profLevel_", "get_profLevel_");
	ClassDB::bind_method(D_METHOD("get_contribution_"), &COM_GuildMember::get_contribution_);
	ClassDB::bind_method(D_METHOD("set_contribution_", "p_val"), &COM_GuildMember::set_contribution_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "contribution_"), "set_contribution_", "get_contribution_");
	ClassDB::bind_method(D_METHOD("get_job_"), &COM_GuildMember::get_job_);
	ClassDB::bind_method(D_METHOD("set_job_", "p_val"), &COM_GuildMember::set_job_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "job_"), "set_job_", "get_job_");
	ClassDB::bind_method(D_METHOD("get_roleId_"), &COM_GuildMember::get_roleId_);
	ClassDB::bind_method(D_METHOD("set_roleId_", "p_val"), &COM_GuildMember::set_roleId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roleId_"), "set_roleId_", "get_roleId_");
	ClassDB::bind_method(D_METHOD("get_offlineTime_"), &COM_GuildMember::get_offlineTime_);
	ClassDB::bind_method(D_METHOD("set_offlineTime_", "p_val"), &COM_GuildMember::set_offlineTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "offlineTime_"), "set_offlineTime_", "get_offlineTime_");
	ClassDB::bind_method(D_METHOD("get_roleName_"), &COM_GuildMember::get_roleName_);
	ClassDB::bind_method(D_METHOD("set_roleName_", "p_val"), &COM_GuildMember::set_roleName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "roleName_"), "set_roleName_", "get_roleName_");
	ClassDB::bind_method(D_METHOD("get_joinTime_"), &COM_GuildMember::get_joinTime_);
	ClassDB::bind_method(D_METHOD("set_joinTime_", "p_val"), &COM_GuildMember::set_joinTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "joinTime_"), "set_joinTime_", "get_joinTime_");
	ClassDB::bind_method(D_METHOD("get_signflag_"), &COM_GuildMember::get_signflag_);
	ClassDB::bind_method(D_METHOD("set_signflag_", "p_val"), &COM_GuildMember::set_signflag_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "signflag_"), "set_signflag_", "get_signflag_");
	ClassDB::bind_method(D_METHOD("get_shopItems_"), &COM_GuildMember::get_shopItems_);
	ClassDB::bind_method(D_METHOD("set_shopItems_", "p_val"), &COM_GuildMember::set_shopItems_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "shopItems_"), "set_shopItems_", "get_shopItems_");
}

void COM_GuildMember::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((shopRefreshTimes_==0)?false:true);
	__fm__.writeBit((guildId_==0)?false:true);
	__fm__.writeBit((profType_==0)?false:true);
	__fm__.writeBit((profLevel_==0)?false:true);
	__fm__.writeBit((contribution_==0)?false:true);
	__fm__.writeBit((job_==0)?false:true);
	__fm__.writeBit((roleId_==0)?false:true);
	__fm__.writeBit((offlineTime_==0)?false:true);
	__fm__.writeBit(roleName_.length()?true:false);
	__fm__.writeBit((joinTime_==0)?false:true);
	__fm__.writeBit(signflag_);
	__fm__.writeBit(shopItems_.size()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(shopRefreshTimes_);
	}
	if(__fm__.readBit()){
		s->writeType(guildId_);
	}
	if(__fm__.readBit()){
		s->writeType(profType_);
	}
	if(__fm__.readBit()){
		s->writeType(profLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(contribution_);
	}
	if(__fm__.readBit()){
		s->writeType(job_);
	}
	if(__fm__.readBit()){
		s->writeType(roleId_);
	}
	if(__fm__.readBit()){
		s->writeType(offlineTime_);
	}
	if(__fm__.readBit()){
		s->writeType(roleName_);
	}
	if(__fm__.readBit()){
		s->writeType(joinTime_);
	}
	if(__fm__.readBit()){
		s->writeType(signflag_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)shopItems_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_GuildShopItem> __elem = shopItems_[i];
			if (__elem.is_null()) __elem = memnew(COM_GuildShopItem);
			__elem->serialize(s);
		}
	}
}

bool COM_GuildMember::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(shopRefreshTimes_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(profType_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(profLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(contribution_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(job_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(offlineTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(joinTime_)) return false;
	}
	if(__fm__.readBit()){
		signflag_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			shopItems_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildShopItem> __elem = memnew(COM_GuildShopItem);
				if(!__elem->deserialize(r)) return false;
				shopItems_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_GuildViewerData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_guid_"), &COM_GuildViewerData::get_guid_);
	ClassDB::bind_method(D_METHOD("set_guid_", "p_val"), &COM_GuildViewerData::set_guid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guid_"), "set_guid_", "get_guid_");
	ClassDB::bind_method(D_METHOD("get_guildName_"), &COM_GuildViewerData::get_guildName_);
	ClassDB::bind_method(D_METHOD("set_guildName_", "p_val"), &COM_GuildViewerData::set_guildName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "guildName_"), "set_guildName_", "get_guildName_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_GuildViewerData::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_GuildViewerData::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_notice_"), &COM_GuildViewerData::get_notice_);
	ClassDB::bind_method(D_METHOD("set_notice_", "p_val"), &COM_GuildViewerData::set_notice_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "notice_"), "set_notice_", "get_notice_");
	ClassDB::bind_method(D_METHOD("get_level_"), &COM_GuildViewerData::get_level_);
	ClassDB::bind_method(D_METHOD("set_level_", "p_val"), &COM_GuildViewerData::set_level_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "level_"), "set_level_", "get_level_");
	ClassDB::bind_method(D_METHOD("get_memberNum_"), &COM_GuildViewerData::get_memberNum_);
	ClassDB::bind_method(D_METHOD("set_memberNum_", "p_val"), &COM_GuildViewerData::set_memberNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "memberNum_"), "set_memberNum_", "get_memberNum_");
	ClassDB::bind_method(D_METHOD("get_memberTotal_"), &COM_GuildViewerData::get_memberTotal_);
	ClassDB::bind_method(D_METHOD("set_memberTotal_", "p_val"), &COM_GuildViewerData::set_memberTotal_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "memberTotal_"), "set_memberTotal_", "get_memberTotal_");
	ClassDB::bind_method(D_METHOD("get_guildRank_"), &COM_GuildViewerData::get_guildRank_);
	ClassDB::bind_method(D_METHOD("set_guildRank_", "p_val"), &COM_GuildViewerData::set_guildRank_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guildRank_"), "set_guildRank_", "get_guildRank_");
}

void COM_GuildViewerData::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((guid_==0)?false:true);
	__fm__.writeBit(guildName_.length()?true:false);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit(notice_.length()?true:false);
	__fm__.writeBit((level_==0)?false:true);
	__fm__.writeBit((memberNum_==0)?false:true);
	__fm__.writeBit((memberTotal_==0)?false:true);
	__fm__.writeBit((guildRank_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(guid_);
	}
	if(__fm__.readBit()){
		s->writeType(guildName_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(notice_);
	}
	if(__fm__.readBit()){
		s->writeType(level_);
	}
	if(__fm__.readBit()){
		s->writeType(memberNum_);
	}
	if(__fm__.readBit()){
		s->writeType(memberTotal_);
	}
	if(__fm__.readBit()){
		s->writeType(guildRank_);
	}
}

bool COM_GuildViewerData::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(guid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(notice_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(level_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(memberNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(memberTotal_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guildRank_)) return false;
	}
	return true;
}

void COM_SearchContext::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_title_"), &COM_SearchContext::get_title_);
	ClassDB::bind_method(D_METHOD("set_title_", "p_val"), &COM_SearchContext::set_title_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "title_"), "set_title_", "get_title_");
	ClassDB::bind_method(D_METHOD("get_ist_"), &COM_SearchContext::get_ist_);
	ClassDB::bind_method(D_METHOD("set_ist_", "p_val"), &COM_SearchContext::set_ist_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ist_"), "set_ist_", "get_ist_");
	ClassDB::bind_method(D_METHOD("get_rt_"), &COM_SearchContext::get_rt_);
	ClassDB::bind_method(D_METHOD("set_rt_", "p_val"), &COM_SearchContext::set_rt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rt_"), "set_rt_", "get_rt_");
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_SearchContext::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_SearchContext::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_babyId_"), &COM_SearchContext::get_babyId_);
	ClassDB::bind_method(D_METHOD("set_babyId_", "p_val"), &COM_SearchContext::set_babyId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyId_"), "set_babyId_", "get_babyId_");
	ClassDB::bind_method(D_METHOD("get_begin_"), &COM_SearchContext::get_begin_);
	ClassDB::bind_method(D_METHOD("set_begin_", "p_val"), &COM_SearchContext::set_begin_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "begin_"), "set_begin_", "get_begin_");
	ClassDB::bind_method(D_METHOD("get_limit_"), &COM_SearchContext::get_limit_);
	ClassDB::bind_method(D_METHOD("set_limit_", "p_val"), &COM_SearchContext::set_limit_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "limit_"), "set_limit_", "get_limit_");
}

void COM_SearchContext::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(title_.length()?true:false);
	__fm__.writeBit(ist_?true:false);
	__fm__.writeBit(rt_?true:false);
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((babyId_==0)?false:true);
	__fm__.writeBit((begin_==0)?false:true);
	__fm__.writeBit((limit_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(title_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)ist_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)rt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(babyId_);
	}
	if(__fm__.readBit()){
		s->writeType(begin_);
	}
	if(__fm__.readBit()){
		s->writeType(limit_);
	}
}

bool COM_SearchContext::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(title_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 48) return false;
		ist_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 11) return false;
		rt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(begin_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(limit_)) return false;
	}
	return true;
}

void COM_SellItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_guid_"), &COM_SellItem::get_guid_);
	ClassDB::bind_method(D_METHOD("set_guid_", "p_val"), &COM_SellItem::set_guid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guid_"), "set_guid_", "get_guid_");
	ClassDB::bind_method(D_METHOD("get_sellPlayerId_"), &COM_SellItem::get_sellPlayerId_);
	ClassDB::bind_method(D_METHOD("set_sellPlayerId_", "p_val"), &COM_SellItem::set_sellPlayerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sellPlayerId_"), "set_sellPlayerId_", "get_sellPlayerId_");
	ClassDB::bind_method(D_METHOD("get_sellPrice"), &COM_SellItem::get_sellPrice);
	ClassDB::bind_method(D_METHOD("set_sellPrice", "p_val"), &COM_SellItem::set_sellPrice);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sellPrice"), "set_sellPrice", "get_sellPrice");
	ClassDB::bind_method(D_METHOD("get_title_"), &COM_SellItem::get_title_);
	ClassDB::bind_method(D_METHOD("set_title_", "p_val"), &COM_SellItem::set_title_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "title_"), "set_title_", "get_title_");
	ClassDB::bind_method(D_METHOD("get_ist_"), &COM_SellItem::get_ist_);
	ClassDB::bind_method(D_METHOD("set_ist_", "p_val"), &COM_SellItem::set_ist_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ist_"), "set_ist_", "get_ist_");
	ClassDB::bind_method(D_METHOD("get_rt_"), &COM_SellItem::get_rt_);
	ClassDB::bind_method(D_METHOD("set_rt_", "p_val"), &COM_SellItem::set_rt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rt_"), "set_rt_", "get_rt_");
	ClassDB::bind_method(D_METHOD("get_item_"), &COM_SellItem::get_item_);
	ClassDB::bind_method(D_METHOD("set_item_", "p_val"), &COM_SellItem::set_item_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "item_"), "set_item_", "get_item_");
	ClassDB::bind_method(D_METHOD("get_baby_"), &COM_SellItem::get_baby_);
	ClassDB::bind_method(D_METHOD("set_baby_", "p_val"), &COM_SellItem::set_baby_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "baby_"), "set_baby_", "get_baby_");
	ClassDB::bind_method(D_METHOD("get_time_"), &COM_SellItem::get_time_);
	ClassDB::bind_method(D_METHOD("set_time_", "p_val"), &COM_SellItem::set_time_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "time_"), "set_time_", "get_time_");
}

void COM_SellItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((guid_==0)?false:true);
	__fm__.writeBit((sellPlayerId_==0)?false:true);
	__fm__.writeBit((sellPrice==0)?false:true);
	__fm__.writeBit(title_.length()?true:false);
	__fm__.writeBit(ist_?true:false);
	__fm__.writeBit(rt_?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit((time_==0)?false:true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(guid_);
	}
	if(__fm__.readBit()){
		s->writeType(sellPlayerId_);
	}
	if(__fm__.readBit()){
		s->writeType(sellPrice);
	}
	if(__fm__.readBit()){
		s->writeType(title_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)ist_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)rt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		if (item_.is_null()) const_cast<Ref<COM_Item>&>(item_) = memnew(COM_Item);
		item_->serialize(s);
	}
	if(__fm__.readBit()){
		if (baby_.is_null()) const_cast<Ref<COM_BabyInst>&>(baby_) = memnew(COM_BabyInst);
		baby_->serialize(s);
	}
	if(__fm__.readBit()){
		s->writeType(time_);
	}
}

bool COM_SellItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(guid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sellPlayerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sellPrice)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(title_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 48) return false;
		ist_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 11) return false;
		rt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if (item_.is_null()) const_cast<Ref<COM_Item>&>(item_) = memnew(COM_Item);
		if(!item_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (baby_.is_null()) const_cast<Ref<COM_BabyInst>&>(baby_) = memnew(COM_BabyInst);
		if(!baby_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(time_)) return false;
	}
	return true;
}

void COM_SelledItem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_guid_"), &COM_SelledItem::get_guid_);
	ClassDB::bind_method(D_METHOD("set_guid_", "p_val"), &COM_SelledItem::set_guid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guid_"), "set_guid_", "get_guid_");
	ClassDB::bind_method(D_METHOD("get_sellPlayerId_"), &COM_SelledItem::get_sellPlayerId_);
	ClassDB::bind_method(D_METHOD("set_sellPlayerId_", "p_val"), &COM_SelledItem::set_sellPlayerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sellPlayerId_"), "set_sellPlayerId_", "get_sellPlayerId_");
	ClassDB::bind_method(D_METHOD("get_sellTime_"), &COM_SelledItem::get_sellTime_);
	ClassDB::bind_method(D_METHOD("set_sellTime_", "p_val"), &COM_SelledItem::set_sellTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sellTime_"), "set_sellTime_", "get_sellTime_");
	ClassDB::bind_method(D_METHOD("get_selledTime_"), &COM_SelledItem::get_selledTime_);
	ClassDB::bind_method(D_METHOD("set_selledTime_", "p_val"), &COM_SelledItem::set_selledTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "selledTime_"), "set_selledTime_", "get_selledTime_");
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_SelledItem::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_SelledItem::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_babyId_"), &COM_SelledItem::get_babyId_);
	ClassDB::bind_method(D_METHOD("set_babyId_", "p_val"), &COM_SelledItem::set_babyId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyId_"), "set_babyId_", "get_babyId_");
	ClassDB::bind_method(D_METHOD("get_itemStack_"), &COM_SelledItem::get_itemStack_);
	ClassDB::bind_method(D_METHOD("set_itemStack_", "p_val"), &COM_SelledItem::set_itemStack_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemStack_"), "set_itemStack_", "get_itemStack_");
	ClassDB::bind_method(D_METHOD("get_price_"), &COM_SelledItem::get_price_);
	ClassDB::bind_method(D_METHOD("set_price_", "p_val"), &COM_SelledItem::set_price_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "price_"), "set_price_", "get_price_");
	ClassDB::bind_method(D_METHOD("get_tax_"), &COM_SelledItem::get_tax_);
	ClassDB::bind_method(D_METHOD("set_tax_", "p_val"), &COM_SelledItem::set_tax_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "tax_"), "set_tax_", "get_tax_");
}

void COM_SelledItem::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((guid_==0)?false:true);
	__fm__.writeBit((sellPlayerId_==0)?false:true);
	__fm__.writeBit((sellTime_==0)?false:true);
	__fm__.writeBit((selledTime_==0)?false:true);
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((babyId_==0)?false:true);
	__fm__.writeBit((itemStack_==0)?false:true);
	__fm__.writeBit((price_==0)?false:true);
	__fm__.writeBit((tax_==0)?false:true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(guid_);
	}
	if(__fm__.readBit()){
		s->writeType(sellPlayerId_);
	}
	if(__fm__.readBit()){
		s->writeType(sellTime_);
	}
	if(__fm__.readBit()){
		s->writeType(selledTime_);
	}
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(babyId_);
	}
	if(__fm__.readBit()){
		s->writeType(itemStack_);
	}
	if(__fm__.readBit()){
		s->writeType(price_);
	}
	if(__fm__.readBit()){
		s->writeType(tax_);
	}
}

bool COM_SelledItem::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(guid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sellPlayerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sellTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(selledTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemStack_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(price_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(tax_)) return false;
	}
	return true;
}

void SGE_BuyContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerId_"), &SGE_BuyContent::get_playerId_);
	ClassDB::bind_method(D_METHOD("set_playerId_", "p_val"), &SGE_BuyContent::set_playerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerId_"), "set_playerId_", "get_playerId_");
	ClassDB::bind_method(D_METHOD("get_guid_"), &SGE_BuyContent::get_guid_);
	ClassDB::bind_method(D_METHOD("set_guid_", "p_val"), &SGE_BuyContent::set_guid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "guid_"), "set_guid_", "get_guid_");
	ClassDB::bind_method(D_METHOD("get_diamond_"), &SGE_BuyContent::get_diamond_);
	ClassDB::bind_method(D_METHOD("set_diamond_", "p_val"), &SGE_BuyContent::set_diamond_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "diamond_"), "set_diamond_", "get_diamond_");
	ClassDB::bind_method(D_METHOD("get_magic_"), &SGE_BuyContent::get_magic_);
	ClassDB::bind_method(D_METHOD("set_magic_", "p_val"), &SGE_BuyContent::set_magic_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magic_"), "set_magic_", "get_magic_");
	ClassDB::bind_method(D_METHOD("get_isBabyFull_"), &SGE_BuyContent::get_isBabyFull_);
	ClassDB::bind_method(D_METHOD("set_isBabyFull_", "p_val"), &SGE_BuyContent::set_isBabyFull_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBabyFull_"), "set_isBabyFull_", "get_isBabyFull_");
	ClassDB::bind_method(D_METHOD("get_isBagFull_"), &SGE_BuyContent::get_isBagFull_);
	ClassDB::bind_method(D_METHOD("set_isBagFull_", "p_val"), &SGE_BuyContent::set_isBagFull_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isBagFull_"), "set_isBagFull_", "get_isBagFull_");
}

void SGE_BuyContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((playerId_==0)?false:true);
	__fm__.writeBit((guid_==0)?false:true);
	__fm__.writeBit((diamond_==0)?false:true);
	__fm__.writeBit((magic_==0)?false:true);
	__fm__.writeBit(isBabyFull_);
	__fm__.writeBit(isBagFull_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerId_);
	}
	if(__fm__.readBit()){
		s->writeType(guid_);
	}
	if(__fm__.readBit()){
		s->writeType(diamond_);
	}
	if(__fm__.readBit()){
		s->writeType(magic_);
	}
	if(__fm__.readBit()){
		s->writeType(isBabyFull_);
	}
	if(__fm__.readBit()){
		s->writeType(isBagFull_);
	}
}

bool SGE_BuyContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(guid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(diamond_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(magic_)) return false;
	}
	if(__fm__.readBit()){
		isBabyFull_ = __fm__.readBit();
	}
	if(__fm__.readBit()){
		isBagFull_ = __fm__.readBit();
	}
	return true;
}

void SGE_ScenePlayerInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerId_"), &SGE_ScenePlayerInfo::get_playerId_);
	ClassDB::bind_method(D_METHOD("set_playerId_", "p_val"), &SGE_ScenePlayerInfo::set_playerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerId_"), "set_playerId_", "get_playerId_");
	ClassDB::bind_method(D_METHOD("get_playerLevel_"), &SGE_ScenePlayerInfo::get_playerLevel_);
	ClassDB::bind_method(D_METHOD("set_playerLevel_", "p_val"), &SGE_ScenePlayerInfo::set_playerLevel_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerLevel_"), "set_playerLevel_", "get_playerLevel_");
	ClassDB::bind_method(D_METHOD("get_sceneId_"), &SGE_ScenePlayerInfo::get_sceneId_);
	ClassDB::bind_method(D_METHOD("set_sceneId_", "p_val"), &SGE_ScenePlayerInfo::set_sceneId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sceneId_"), "set_sceneId_", "get_sceneId_");
	ClassDB::bind_method(D_METHOD("get_entryId_"), &SGE_ScenePlayerInfo::get_entryId_);
	ClassDB::bind_method(D_METHOD("set_entryId_", "p_val"), &SGE_ScenePlayerInfo::set_entryId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "entryId_"), "set_entryId_", "get_entryId_");
	ClassDB::bind_method(D_METHOD("get_currentQuestIds_"), &SGE_ScenePlayerInfo::get_currentQuestIds_);
	ClassDB::bind_method(D_METHOD("set_currentQuestIds_", "p_val"), &SGE_ScenePlayerInfo::set_currentQuestIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "currentQuestIds_"), "set_currentQuestIds_", "get_currentQuestIds_");
	ClassDB::bind_method(D_METHOD("get_accecptQuestIds_"), &SGE_ScenePlayerInfo::get_accecptQuestIds_);
	ClassDB::bind_method(D_METHOD("set_accecptQuestIds_", "p_val"), &SGE_ScenePlayerInfo::set_accecptQuestIds_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "accecptQuestIds_"), "set_accecptQuestIds_", "get_accecptQuestIds_");
	ClassDB::bind_method(D_METHOD("get_openScenes_"), &SGE_ScenePlayerInfo::get_openScenes_);
	ClassDB::bind_method(D_METHOD("set_openScenes_", "p_val"), &SGE_ScenePlayerInfo::set_openScenes_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "openScenes_"), "set_openScenes_", "get_openScenes_");
}

void SGE_ScenePlayerInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((playerId_==0)?false:true);
	__fm__.writeBit((playerLevel_==0)?false:true);
	__fm__.writeBit((sceneId_==0)?false:true);
	__fm__.writeBit((entryId_==0)?false:true);
	__fm__.writeBit(currentQuestIds_.size()?true:false);
	__fm__.writeBit(accecptQuestIds_.size()?true:false);
	__fm__.writeBit(openScenes_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerLevel_);
	}
	if(__fm__.readBit()){
		s->writeType(sceneId_);
	}
	if(__fm__.readBit()){
		s->writeType(entryId_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)currentQuestIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = currentQuestIds_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)accecptQuestIds_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = accecptQuestIds_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)openScenes_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = openScenes_[i];
			s->writeType(__tmp);
		}
	}
}

bool SGE_ScenePlayerInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerLevel_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(sceneId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(entryId_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			currentQuestIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				currentQuestIds_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			accecptQuestIds_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				accecptQuestIds_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			openScenes_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				openScenes_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_SceneInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_sceneId_"), &COM_SceneInfo::get_sceneId_);
	ClassDB::bind_method(D_METHOD("set_sceneId_", "p_val"), &COM_SceneInfo::set_sceneId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sceneId_"), "set_sceneId_", "get_sceneId_");
	ClassDB::bind_method(D_METHOD("get_position_"), &COM_SceneInfo::get_position_);
	ClassDB::bind_method(D_METHOD("set_position_", "p_val"), &COM_SceneInfo::set_position_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position_"), "set_position_", "get_position_");
	ClassDB::bind_method(D_METHOD("get_players_"), &COM_SceneInfo::get_players_);
	ClassDB::bind_method(D_METHOD("set_players_", "p_val"), &COM_SceneInfo::set_players_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "players_"), "set_players_", "get_players_");
	ClassDB::bind_method(D_METHOD("get_npcs_"), &COM_SceneInfo::get_npcs_);
	ClassDB::bind_method(D_METHOD("set_npcs_", "p_val"), &COM_SceneInfo::set_npcs_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "npcs_"), "set_npcs_", "get_npcs_");
}

void COM_SceneInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((sceneId_==0)?false:true);
	__fm__.writeBit(true);
	__fm__.writeBit(players_.size()?true:false);
	__fm__.writeBit(npcs_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(sceneId_);
	}
	if(__fm__.readBit()){
		if (position_.is_null()) const_cast<Ref<COM_FPosition>&>(position_) = memnew(COM_FPosition);
		position_->serialize(s);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)players_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_ScenePlayerInformation> __elem = players_[i];
			if (__elem.is_null()) __elem = memnew(COM_ScenePlayerInformation);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)npcs_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = npcs_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_SceneInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(sceneId_)) return false;
	}
	if(__fm__.readBit()){
		if (position_.is_null()) const_cast<Ref<COM_FPosition>&>(position_) = memnew(COM_FPosition);
		if(!position_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			players_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ScenePlayerInformation> __elem = memnew(COM_ScenePlayerInformation);
				if(!__elem->deserialize(r)) return false;
				players_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			npcs_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				npcs_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_ReconnectInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_reconnectProcess_"), &COM_ReconnectInfo::get_reconnectProcess_);
	ClassDB::bind_method(D_METHOD("set_reconnectProcess_", "p_val"), &COM_ReconnectInfo::set_reconnectProcess_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "reconnectProcess_"), "set_reconnectProcess_", "get_reconnectProcess_");
	ClassDB::bind_method(D_METHOD("get_sessionKey_"), &COM_ReconnectInfo::get_sessionKey_);
	ClassDB::bind_method(D_METHOD("set_sessionKey_", "p_val"), &COM_ReconnectInfo::set_sessionKey_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "sessionKey_"), "set_sessionKey_", "get_sessionKey_");
	ClassDB::bind_method(D_METHOD("get_roles_"), &COM_ReconnectInfo::get_roles_);
	ClassDB::bind_method(D_METHOD("set_roles_", "p_val"), &COM_ReconnectInfo::set_roles_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "roles_"), "set_roles_", "get_roles_");
	ClassDB::bind_method(D_METHOD("get_playerInst_"), &COM_ReconnectInfo::get_playerInst_);
	ClassDB::bind_method(D_METHOD("set_playerInst_", "p_val"), &COM_ReconnectInfo::set_playerInst_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "playerInst_"), "set_playerInst_", "get_playerInst_");
	ClassDB::bind_method(D_METHOD("get_sceneInfo_"), &COM_ReconnectInfo::get_sceneInfo_);
	ClassDB::bind_method(D_METHOD("set_sceneInfo_", "p_val"), &COM_ReconnectInfo::set_sceneInfo_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "sceneInfo_"), "set_sceneInfo_", "get_sceneInfo_");
	ClassDB::bind_method(D_METHOD("get_team_"), &COM_ReconnectInfo::get_team_);
	ClassDB::bind_method(D_METHOD("set_team_", "p_val"), &COM_ReconnectInfo::set_team_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "team_"), "set_team_", "get_team_");
	ClassDB::bind_method(D_METHOD("get_initBattle_"), &COM_ReconnectInfo::get_initBattle_);
	ClassDB::bind_method(D_METHOD("set_initBattle_", "p_val"), &COM_ReconnectInfo::set_initBattle_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "initBattle_"), "set_initBattle_", "get_initBattle_");
}

void COM_ReconnectInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(reconnectProcess_?true:false);
	__fm__.writeBit(sessionKey_.length()?true:false);
	__fm__.writeBit(roles_.size()?true:false);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	__fm__.writeBit(true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)reconnectProcess_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(sessionKey_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)roles_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_SimpleInformation> __elem = roles_[i];
			if (__elem.is_null()) __elem = memnew(COM_SimpleInformation);
			__elem->serialize(s);
		}
	}
	if(__fm__.readBit()){
		if (playerInst_.is_null()) const_cast<Ref<COM_PlayerInst>&>(playerInst_) = memnew(COM_PlayerInst);
		playerInst_->serialize(s);
	}
	if(__fm__.readBit()){
		if (sceneInfo_.is_null()) const_cast<Ref<COM_SceneInfo>&>(sceneInfo_) = memnew(COM_SceneInfo);
		sceneInfo_->serialize(s);
	}
	if(__fm__.readBit()){
		if (team_.is_null()) const_cast<Ref<COM_TeamInfo>&>(team_) = memnew(COM_TeamInfo);
		team_->serialize(s);
	}
	if(__fm__.readBit()){
		if (initBattle_.is_null()) const_cast<Ref<COM_InitBattle>&>(initBattle_) = memnew(COM_InitBattle);
		initBattle_->serialize(s);
	}
}

bool COM_ReconnectInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 7) return false;
		reconnectProcess_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(sessionKey_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			roles_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimpleInformation> __elem = memnew(COM_SimpleInformation);
				if(!__elem->deserialize(r)) return false;
				roles_[i] = __elem;
			}
		}
	}
	if(__fm__.readBit()){
		if (playerInst_.is_null()) const_cast<Ref<COM_PlayerInst>&>(playerInst_) = memnew(COM_PlayerInst);
		if(!playerInst_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (sceneInfo_.is_null()) const_cast<Ref<COM_SceneInfo>&>(sceneInfo_) = memnew(COM_SceneInfo);
		if(!sceneInfo_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (team_.is_null()) const_cast<Ref<COM_TeamInfo>&>(team_) = memnew(COM_TeamInfo);
		if(!team_->deserialize(r)) return false;
	}
	if(__fm__.readBit()){
		if (initBattle_.is_null()) const_cast<Ref<COM_InitBattle>&>(initBattle_) = memnew(COM_InitBattle);
		if(!initBattle_->deserialize(r)) return false;
	}
	return true;
}

void COM_Notice::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_SendType_"), &COM_Notice::get_SendType_);
	ClassDB::bind_method(D_METHOD("set_SendType_", "p_val"), &COM_Notice::set_SendType_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "SendType_"), "set_SendType_", "get_SendType_");
	ClassDB::bind_method(D_METHOD("get_note_"), &COM_Notice::get_note_);
	ClassDB::bind_method(D_METHOD("set_note_", "p_val"), &COM_Notice::set_note_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "note_"), "set_note_", "get_note_");
	ClassDB::bind_method(D_METHOD("get_accumulate_"), &COM_Notice::get_accumulate_);
	ClassDB::bind_method(D_METHOD("set_accumulate_", "p_val"), &COM_Notice::set_accumulate_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "accumulate_"), "set_accumulate_", "get_accumulate_");
	ClassDB::bind_method(D_METHOD("get_startTime_"), &COM_Notice::get_startTime_);
	ClassDB::bind_method(D_METHOD("set_startTime_", "p_val"), &COM_Notice::set_startTime_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "startTime_"), "set_startTime_", "get_startTime_");
	ClassDB::bind_method(D_METHOD("get_stopTime_"), &COM_Notice::get_stopTime_);
	ClassDB::bind_method(D_METHOD("set_stopTime_", "p_val"), &COM_Notice::set_stopTime_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "stopTime_"), "set_stopTime_", "get_stopTime_");
	ClassDB::bind_method(D_METHOD("get_interval_"), &COM_Notice::get_interval_);
	ClassDB::bind_method(D_METHOD("set_interval_", "p_val"), &COM_Notice::set_interval_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "interval_"), "set_interval_", "get_interval_");
	ClassDB::bind_method(D_METHOD("get_validate_"), &COM_Notice::get_validate_);
	ClassDB::bind_method(D_METHOD("set_validate_", "p_val"), &COM_Notice::set_validate_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "validate_"), "set_validate_", "get_validate_");
}

void COM_Notice::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(SendType_?true:false);
	__fm__.writeBit(note_.length()?true:false);
	__fm__.writeBit((accumulate_==0.0)?false:true);
	__fm__.writeBit((startTime_==0.0)?false:true);
	__fm__.writeBit((stopTime_==0.0)?false:true);
	__fm__.writeBit((interval_==0.0)?false:true);
	__fm__.writeBit(validate_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)SendType_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(note_);
	}
	if(__fm__.readBit()){
		s->writeType(accumulate_);
	}
	if(__fm__.readBit()){
		s->writeType(startTime_);
	}
	if(__fm__.readBit()){
		s->writeType(stopTime_);
	}
	if(__fm__.readBit()){
		s->writeType(interval_);
	}
	if(__fm__.readBit()){
		s->writeType(validate_);
	}
}

bool COM_Notice::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 3) return false;
		SendType_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(note_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accumulate_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(startTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(stopTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(interval_)) return false;
	}
	if(__fm__.readBit()){
		validate_ = __fm__.readBit();
	}
	return true;
}

void COM_ShowItemInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_showId_"), &COM_ShowItemInst::get_showId_);
	ClassDB::bind_method(D_METHOD("set_showId_", "p_val"), &COM_ShowItemInst::set_showId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "showId_"), "set_showId_", "get_showId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_ShowItemInst::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_ShowItemInst::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_itemInst_"), &COM_ShowItemInst::get_itemInst_);
	ClassDB::bind_method(D_METHOD("set_itemInst_", "p_val"), &COM_ShowItemInst::set_itemInst_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "itemInst_"), "set_itemInst_", "get_itemInst_");
}

void COM_ShowItemInst::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((showId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit(true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(showId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		if (itemInst_.is_null()) const_cast<Ref<COM_Item>&>(itemInst_) = memnew(COM_Item);
		itemInst_->serialize(s);
	}
}

bool COM_ShowItemInst::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(showId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if (itemInst_.is_null()) const_cast<Ref<COM_Item>&>(itemInst_) = memnew(COM_Item);
		if(!itemInst_->deserialize(r)) return false;
	}
	return true;
}

void COM_ShowItemInstInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_showId_"), &COM_ShowItemInstInfo::get_showId_);
	ClassDB::bind_method(D_METHOD("set_showId_", "p_val"), &COM_ShowItemInstInfo::set_showId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "showId_"), "set_showId_", "get_showId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_ShowItemInstInfo::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_ShowItemInstInfo::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_itemId_"), &COM_ShowItemInstInfo::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &COM_ShowItemInstInfo::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
}

void COM_ShowItemInstInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((showId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit((itemId_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(showId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
}

bool COM_ShowItemInstInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(showId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	return true;
}

void COM_ShowbabyInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_showId_"), &COM_ShowbabyInst::get_showId_);
	ClassDB::bind_method(D_METHOD("set_showId_", "p_val"), &COM_ShowbabyInst::set_showId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "showId_"), "set_showId_", "get_showId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_ShowbabyInst::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_ShowbabyInst::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_babyInst_"), &COM_ShowbabyInst::get_babyInst_);
	ClassDB::bind_method(D_METHOD("set_babyInst_", "p_val"), &COM_ShowbabyInst::set_babyInst_);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "babyInst_"), "set_babyInst_", "get_babyInst_");
}

void COM_ShowbabyInst::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((showId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit(true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(showId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		if (babyInst_.is_null()) const_cast<Ref<COM_BabyInst>&>(babyInst_) = memnew(COM_BabyInst);
		babyInst_->serialize(s);
	}
}

bool COM_ShowbabyInst::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(showId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if (babyInst_.is_null()) const_cast<Ref<COM_BabyInst>&>(babyInst_) = memnew(COM_BabyInst);
		if(!babyInst_->deserialize(r)) return false;
	}
	return true;
}

void COM_ShowbabyInstInfo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_showId_"), &COM_ShowbabyInstInfo::get_showId_);
	ClassDB::bind_method(D_METHOD("set_showId_", "p_val"), &COM_ShowbabyInstInfo::set_showId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "showId_"), "set_showId_", "get_showId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_ShowbabyInstInfo::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_ShowbabyInstInfo::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_babyId_"), &COM_ShowbabyInstInfo::get_babyId_);
	ClassDB::bind_method(D_METHOD("set_babyId_", "p_val"), &COM_ShowbabyInstInfo::set_babyId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "babyId_"), "set_babyId_", "get_babyId_");
}

void COM_ShowbabyInstInfo::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((showId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit((babyId_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(showId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(babyId_);
	}
}

bool COM_ShowbabyInstInfo::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(showId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(babyId_)) return false;
	}
	return true;
}

void SGE_Account::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_gamename_"), &SGE_Account::get_gamename_);
	ClassDB::bind_method(D_METHOD("set_gamename_", "p_val"), &SGE_Account::set_gamename_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "gamename_"), "set_gamename_", "get_gamename_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &SGE_Account::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &SGE_Account::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_pfname_"), &SGE_Account::get_pfname_);
	ClassDB::bind_method(D_METHOD("set_pfname_", "p_val"), &SGE_Account::set_pfname_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfname_"), "set_pfname_", "get_pfname_");
	ClassDB::bind_method(D_METHOD("get_accountid_"), &SGE_Account::get_accountid_);
	ClassDB::bind_method(D_METHOD("set_accountid_", "p_val"), &SGE_Account::set_accountid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "accountid_"), "set_accountid_", "get_accountid_");
	ClassDB::bind_method(D_METHOD("get_createtime_"), &SGE_Account::get_createtime_);
	ClassDB::bind_method(D_METHOD("set_createtime_", "p_val"), &SGE_Account::set_createtime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "createtime_"), "set_createtime_", "get_createtime_");
	ClassDB::bind_method(D_METHOD("get_mac_"), &SGE_Account::get_mac_);
	ClassDB::bind_method(D_METHOD("set_mac_", "p_val"), &SGE_Account::set_mac_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "mac_"), "set_mac_", "get_mac_");
	ClassDB::bind_method(D_METHOD("get_idfa_"), &SGE_Account::get_idfa_);
	ClassDB::bind_method(D_METHOD("set_idfa_", "p_val"), &SGE_Account::set_idfa_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "idfa_"), "set_idfa_", "get_idfa_");
	ClassDB::bind_method(D_METHOD("get_ip_"), &SGE_Account::get_ip_);
	ClassDB::bind_method(D_METHOD("set_ip_", "p_val"), &SGE_Account::set_ip_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "ip_"), "set_ip_", "get_ip_");
	ClassDB::bind_method(D_METHOD("get_devicetype_"), &SGE_Account::get_devicetype_);
	ClassDB::bind_method(D_METHOD("set_devicetype_", "p_val"), &SGE_Account::set_devicetype_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "devicetype_"), "set_devicetype_", "get_devicetype_");
}

void SGE_Account::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(gamename_.length()?true:false);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit(pfname_.length()?true:false);
	__fm__.writeBit(accountid_.length()?true:false);
	__fm__.writeBit((createtime_==0)?false:true);
	__fm__.writeBit(mac_.length()?true:false);
	__fm__.writeBit(idfa_.length()?true:false);
	__fm__.writeBit(ip_.length()?true:false);
	__fm__.writeBit(devicetype_.length()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(gamename_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(pfname_);
	}
	if(__fm__.readBit()){
		s->writeType(accountid_);
	}
	if(__fm__.readBit()){
		s->writeType(createtime_);
	}
	if(__fm__.readBit()){
		s->writeType(mac_);
	}
	if(__fm__.readBit()){
		s->writeType(idfa_);
	}
	if(__fm__.readBit()){
		s->writeType(ip_);
	}
	if(__fm__.readBit()){
		s->writeType(devicetype_);
	}
}

bool SGE_Account::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(gamename_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfname_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accountid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(createtime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mac_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(idfa_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ip_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(devicetype_, 65535)) return false;
	}
	return true;
}

void SGE_Login::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_gamename_"), &SGE_Login::get_gamename_);
	ClassDB::bind_method(D_METHOD("set_gamename_", "p_val"), &SGE_Login::set_gamename_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "gamename_"), "set_gamename_", "get_gamename_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &SGE_Login::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &SGE_Login::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_pfname_"), &SGE_Login::get_pfname_);
	ClassDB::bind_method(D_METHOD("set_pfname_", "p_val"), &SGE_Login::set_pfname_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfname_"), "set_pfname_", "get_pfname_");
	ClassDB::bind_method(D_METHOD("get_accountid_"), &SGE_Login::get_accountid_);
	ClassDB::bind_method(D_METHOD("set_accountid_", "p_val"), &SGE_Login::set_accountid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "accountid_"), "set_accountid_", "get_accountid_");
	ClassDB::bind_method(D_METHOD("get_roleId_"), &SGE_Login::get_roleId_);
	ClassDB::bind_method(D_METHOD("set_roleId_", "p_val"), &SGE_Login::set_roleId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roleId_"), "set_roleId_", "get_roleId_");
	ClassDB::bind_method(D_METHOD("get_logintime_"), &SGE_Login::get_logintime_);
	ClassDB::bind_method(D_METHOD("set_logintime_", "p_val"), &SGE_Login::set_logintime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "logintime_"), "set_logintime_", "get_logintime_");
	ClassDB::bind_method(D_METHOD("get_logouttime_"), &SGE_Login::get_logouttime_);
	ClassDB::bind_method(D_METHOD("set_logouttime_", "p_val"), &SGE_Login::set_logouttime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "logouttime_"), "set_logouttime_", "get_logouttime_");
	ClassDB::bind_method(D_METHOD("get_firsttime_"), &SGE_Login::get_firsttime_);
	ClassDB::bind_method(D_METHOD("set_firsttime_", "p_val"), &SGE_Login::set_firsttime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "firsttime_"), "set_firsttime_", "get_firsttime_");
	ClassDB::bind_method(D_METHOD("get_rolefirsttime_"), &SGE_Login::get_rolefirsttime_);
	ClassDB::bind_method(D_METHOD("set_rolefirsttime_", "p_val"), &SGE_Login::set_rolefirsttime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolefirsttime_"), "set_rolefirsttime_", "get_rolefirsttime_");
	ClassDB::bind_method(D_METHOD("get_firstserid_"), &SGE_Login::get_firstserid_);
	ClassDB::bind_method(D_METHOD("set_firstserid_", "p_val"), &SGE_Login::set_firstserid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "firstserid_"), "set_firstserid_", "get_firstserid_");
	ClassDB::bind_method(D_METHOD("get_serverid_"), &SGE_Login::get_serverid_);
	ClassDB::bind_method(D_METHOD("set_serverid_", "p_val"), &SGE_Login::set_serverid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "serverid_"), "set_serverid_", "get_serverid_");
	ClassDB::bind_method(D_METHOD("get_mac_"), &SGE_Login::get_mac_);
	ClassDB::bind_method(D_METHOD("set_mac_", "p_val"), &SGE_Login::set_mac_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "mac_"), "set_mac_", "get_mac_");
	ClassDB::bind_method(D_METHOD("get_idfa_"), &SGE_Login::get_idfa_);
	ClassDB::bind_method(D_METHOD("set_idfa_", "p_val"), &SGE_Login::set_idfa_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "idfa_"), "set_idfa_", "get_idfa_");
	ClassDB::bind_method(D_METHOD("get_ip_"), &SGE_Login::get_ip_);
	ClassDB::bind_method(D_METHOD("set_ip_", "p_val"), &SGE_Login::set_ip_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "ip_"), "set_ip_", "get_ip_");
	ClassDB::bind_method(D_METHOD("get_devicetype_"), &SGE_Login::get_devicetype_);
	ClassDB::bind_method(D_METHOD("set_devicetype_", "p_val"), &SGE_Login::set_devicetype_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "devicetype_"), "set_devicetype_", "get_devicetype_");
}

void SGE_Login::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(gamename_.length()?true:false);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit(pfname_.length()?true:false);
	__fm__.writeBit(accountid_.length()?true:false);
	__fm__.writeBit((roleId_==0)?false:true);
	__fm__.writeBit((logintime_==0)?false:true);
	__fm__.writeBit((logouttime_==0)?false:true);
	__fm__.writeBit((firsttime_==0)?false:true);
	__fm__.writeBit((rolefirsttime_==0)?false:true);
	__fm__.writeBit((firstserid_==0)?false:true);
	__fm__.writeBit((serverid_==0)?false:true);
	__fm__.writeBit(mac_.length()?true:false);
	__fm__.writeBit(idfa_.length()?true:false);
	__fm__.writeBit(ip_.length()?true:false);
	__fm__.writeBit(devicetype_.length()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(gamename_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(pfname_);
	}
	if(__fm__.readBit()){
		s->writeType(accountid_);
	}
	if(__fm__.readBit()){
		s->writeType(roleId_);
	}
	if(__fm__.readBit()){
		s->writeType(logintime_);
	}
	if(__fm__.readBit()){
		s->writeType(logouttime_);
	}
	if(__fm__.readBit()){
		s->writeType(firsttime_);
	}
	if(__fm__.readBit()){
		s->writeType(rolefirsttime_);
	}
	if(__fm__.readBit()){
		s->writeType(firstserid_);
	}
	if(__fm__.readBit()){
		s->writeType(serverid_);
	}
	if(__fm__.readBit()){
		s->writeType(mac_);
	}
	if(__fm__.readBit()){
		s->writeType(idfa_);
	}
	if(__fm__.readBit()){
		s->writeType(ip_);
	}
	if(__fm__.readBit()){
		s->writeType(devicetype_);
	}
}

bool SGE_Login::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(gamename_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfname_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accountid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(logintime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(logouttime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(firsttime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rolefirsttime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(firstserid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(serverid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(mac_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(idfa_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ip_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(devicetype_, 65535)) return false;
	}
	return true;
}

void SGE_Order::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_gamename_"), &SGE_Order::get_gamename_);
	ClassDB::bind_method(D_METHOD("set_gamename_", "p_val"), &SGE_Order::set_gamename_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "gamename_"), "set_gamename_", "get_gamename_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &SGE_Order::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &SGE_Order::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_pfname_"), &SGE_Order::get_pfname_);
	ClassDB::bind_method(D_METHOD("set_pfname_", "p_val"), &SGE_Order::set_pfname_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfname_"), "set_pfname_", "get_pfname_");
	ClassDB::bind_method(D_METHOD("get_orderid_"), &SGE_Order::get_orderid_);
	ClassDB::bind_method(D_METHOD("set_orderid_", "p_val"), &SGE_Order::set_orderid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "orderid_"), "set_orderid_", "get_orderid_");
	ClassDB::bind_method(D_METHOD("get_roleId_"), &SGE_Order::get_roleId_);
	ClassDB::bind_method(D_METHOD("set_roleId_", "p_val"), &SGE_Order::set_roleId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roleId_"), "set_roleId_", "get_roleId_");
	ClassDB::bind_method(D_METHOD("get_rolelv_"), &SGE_Order::get_rolelv_);
	ClassDB::bind_method(D_METHOD("set_rolelv_", "p_val"), &SGE_Order::set_rolelv_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolelv_"), "set_rolelv_", "get_rolelv_");
	ClassDB::bind_method(D_METHOD("get_accountid_"), &SGE_Order::get_accountid_);
	ClassDB::bind_method(D_METHOD("set_accountid_", "p_val"), &SGE_Order::set_accountid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "accountid_"), "set_accountid_", "get_accountid_");
	ClassDB::bind_method(D_METHOD("get_payment_"), &SGE_Order::get_payment_);
	ClassDB::bind_method(D_METHOD("set_payment_", "p_val"), &SGE_Order::set_payment_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "payment_"), "set_payment_", "get_payment_");
	ClassDB::bind_method(D_METHOD("get_paytime_"), &SGE_Order::get_paytime_);
	ClassDB::bind_method(D_METHOD("set_paytime_", "p_val"), &SGE_Order::set_paytime_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "paytime_"), "set_paytime_", "get_paytime_");
}

void SGE_Order::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit(gamename_.length()?true:false);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit(pfname_.length()?true:false);
	__fm__.writeBit(orderid_.length()?true:false);
	__fm__.writeBit((roleId_==0)?false:true);
	__fm__.writeBit((rolelv_==0)?false:true);
	__fm__.writeBit(accountid_.length()?true:false);
	__fm__.writeBit((payment_==0.0)?false:true);
	__fm__.writeBit(paytime_.length()?true:false);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(gamename_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(pfname_);
	}
	if(__fm__.readBit()){
		s->writeType(orderid_);
	}
	if(__fm__.readBit()){
		s->writeType(roleId_);
	}
	if(__fm__.readBit()){
		s->writeType(rolelv_);
	}
	if(__fm__.readBit()){
		s->writeType(accountid_);
	}
	if(__fm__.readBit()){
		s->writeType(payment_);
	}
	if(__fm__.readBit()){
		s->writeType(paytime_);
	}
}

bool SGE_Order::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(gamename_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfname_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(orderid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rolelv_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accountid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(payment_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(paytime_, 65535)) return false;
	}
	return true;
}

void SGE_LogUIBehavior::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_accountGuid_"), &SGE_LogUIBehavior::get_accountGuid_);
	ClassDB::bind_method(D_METHOD("set_accountGuid_", "p_val"), &SGE_LogUIBehavior::set_accountGuid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "accountGuid_"), "set_accountGuid_", "get_accountGuid_");
	ClassDB::bind_method(D_METHOD("get_accountName_"), &SGE_LogUIBehavior::get_accountName_);
	ClassDB::bind_method(D_METHOD("set_accountName_", "p_val"), &SGE_LogUIBehavior::set_accountName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "accountName_"), "set_accountName_", "get_accountName_");
	ClassDB::bind_method(D_METHOD("get_playerGuid_"), &SGE_LogUIBehavior::get_playerGuid_);
	ClassDB::bind_method(D_METHOD("set_playerGuid_", "p_val"), &SGE_LogUIBehavior::set_playerGuid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerGuid_"), "set_playerGuid_", "get_playerGuid_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &SGE_LogUIBehavior::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &SGE_LogUIBehavior::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_clientIp_"), &SGE_LogUIBehavior::get_clientIp_);
	ClassDB::bind_method(D_METHOD("set_clientIp_", "p_val"), &SGE_LogUIBehavior::set_clientIp_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "clientIp_"), "set_clientIp_", "get_clientIp_");
	ClassDB::bind_method(D_METHOD("get_type_"), &SGE_LogUIBehavior::get_type_);
	ClassDB::bind_method(D_METHOD("set_type_", "p_val"), &SGE_LogUIBehavior::set_type_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_"), "set_type_", "get_type_");
}

void SGE_LogUIBehavior::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((accountGuid_==0)?false:true);
	__fm__.writeBit(accountName_.length()?true:false);
	__fm__.writeBit((playerGuid_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit(clientIp_.length()?true:false);
	__fm__.writeBit(type_?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(accountGuid_);
	}
	if(__fm__.readBit()){
		s->writeType(accountName_);
	}
	if(__fm__.readBit()){
		s->writeType(playerGuid_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(clientIp_);
	}
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)type_;
		s->writeType(__e__);
	}
}

bool SGE_LogUIBehavior::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(accountGuid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accountName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerGuid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(clientIp_, 65535)) return false;
	}
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 22) return false;
		type_ = (uint16_t)__e__; }
	}
	return true;
}

void SGE_LogRole::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_gamename_"), &SGE_LogRole::get_gamename_);
	ClassDB::bind_method(D_METHOD("set_gamename_", "p_val"), &SGE_LogRole::set_gamename_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "gamename_"), "set_gamename_", "get_gamename_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &SGE_LogRole::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &SGE_LogRole::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_pfname_"), &SGE_LogRole::get_pfname_);
	ClassDB::bind_method(D_METHOD("set_pfname_", "p_val"), &SGE_LogRole::set_pfname_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfname_"), "set_pfname_", "get_pfname_");
	ClassDB::bind_method(D_METHOD("get_roleid_"), &SGE_LogRole::get_roleid_);
	ClassDB::bind_method(D_METHOD("set_roleid_", "p_val"), &SGE_LogRole::set_roleid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "roleid_"), "set_roleid_", "get_roleid_");
	ClassDB::bind_method(D_METHOD("get_cachetime_"), &SGE_LogRole::get_cachetime_);
	ClassDB::bind_method(D_METHOD("set_cachetime_", "p_val"), &SGE_LogRole::set_cachetime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "cachetime_"), "set_cachetime_", "get_cachetime_");
	ClassDB::bind_method(D_METHOD("get_accountid_"), &SGE_LogRole::get_accountid_);
	ClassDB::bind_method(D_METHOD("set_accountid_", "p_val"), &SGE_LogRole::set_accountid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "accountid_"), "set_accountid_", "get_accountid_");
	ClassDB::bind_method(D_METHOD("get_serverid_"), &SGE_LogRole::get_serverid_);
	ClassDB::bind_method(D_METHOD("set_serverid_", "p_val"), &SGE_LogRole::set_serverid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "serverid_"), "set_serverid_", "get_serverid_");
	ClassDB::bind_method(D_METHOD("get_servername_"), &SGE_LogRole::get_servername_);
	ClassDB::bind_method(D_METHOD("set_servername_", "p_val"), &SGE_LogRole::set_servername_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "servername_"), "set_servername_", "get_servername_");
	ClassDB::bind_method(D_METHOD("get_firstserid_"), &SGE_LogRole::get_firstserid_);
	ClassDB::bind_method(D_METHOD("set_firstserid_", "p_val"), &SGE_LogRole::set_firstserid_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "firstserid_"), "set_firstserid_", "get_firstserid_");
	ClassDB::bind_method(D_METHOD("get_rolefirsttime_"), &SGE_LogRole::get_rolefirsttime_);
	ClassDB::bind_method(D_METHOD("set_rolefirsttime_", "p_val"), &SGE_LogRole::set_rolefirsttime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolefirsttime_"), "set_rolefirsttime_", "get_rolefirsttime_");
	ClassDB::bind_method(D_METHOD("get_rolelasttime_"), &SGE_LogRole::get_rolelasttime_);
	ClassDB::bind_method(D_METHOD("set_rolelasttime_", "p_val"), &SGE_LogRole::set_rolelasttime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolelasttime_"), "set_rolelasttime_", "get_rolelasttime_");
	ClassDB::bind_method(D_METHOD("get_rolelv_"), &SGE_LogRole::get_rolelv_);
	ClassDB::bind_method(D_METHOD("set_rolelv_", "p_val"), &SGE_LogRole::set_rolelv_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rolelv_"), "set_rolelv_", "get_rolelv_");
	ClassDB::bind_method(D_METHOD("get_gold_"), &SGE_LogRole::get_gold_);
	ClassDB::bind_method(D_METHOD("set_gold_", "p_val"), &SGE_LogRole::set_gold_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "gold_"), "set_gold_", "get_gold_");
	ClassDB::bind_method(D_METHOD("get_diamond_"), &SGE_LogRole::get_diamond_);
	ClassDB::bind_method(D_METHOD("set_diamond_", "p_val"), &SGE_LogRole::set_diamond_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "diamond_"), "set_diamond_", "get_diamond_");
	ClassDB::bind_method(D_METHOD("get_magicgold_"), &SGE_LogRole::get_magicgold_);
	ClassDB::bind_method(D_METHOD("set_magicgold_", "p_val"), &SGE_LogRole::set_magicgold_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magicgold_"), "set_magicgold_", "get_magicgold_");
	ClassDB::bind_method(D_METHOD("get_vip_"), &SGE_LogRole::get_vip_);
	ClassDB::bind_method(D_METHOD("set_vip_", "p_val"), &SGE_LogRole::set_vip_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "vip_"), "set_vip_", "get_vip_");
	ClassDB::bind_method(D_METHOD("get_ce_"), &SGE_LogRole::get_ce_);
	ClassDB::bind_method(D_METHOD("set_ce_", "p_val"), &SGE_LogRole::set_ce_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "ce_"), "set_ce_", "get_ce_");
}

void SGE_LogRole::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<3> __fm__;
	__fm__.writeBit(gamename_.length()?true:false);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit(pfname_.length()?true:false);
	__fm__.writeBit((roleid_==0)?false:true);
	__fm__.writeBit((cachetime_==0)?false:true);
	__fm__.writeBit(accountid_.length()?true:false);
	__fm__.writeBit((serverid_==0)?false:true);
	__fm__.writeBit(servername_.length()?true:false);
	__fm__.writeBit((firstserid_==0)?false:true);
	__fm__.writeBit((rolefirsttime_==0)?false:true);
	__fm__.writeBit((rolelasttime_==0)?false:true);
	__fm__.writeBit((rolelv_==0)?false:true);
	__fm__.writeBit((gold_==0)?false:true);
	__fm__.writeBit((diamond_==0)?false:true);
	__fm__.writeBit((magicgold_==0)?false:true);
	__fm__.writeBit((vip_==0)?false:true);
	__fm__.writeBit((ce_==0)?false:true);
	s->write((const void*)__fm__.masks_, 3);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(gamename_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(pfname_);
	}
	if(__fm__.readBit()){
		s->writeType(roleid_);
	}
	if(__fm__.readBit()){
		s->writeType(cachetime_);
	}
	if(__fm__.readBit()){
		s->writeType(accountid_);
	}
	if(__fm__.readBit()){
		s->writeType(serverid_);
	}
	if(__fm__.readBit()){
		s->writeType(servername_);
	}
	if(__fm__.readBit()){
		s->writeType(firstserid_);
	}
	if(__fm__.readBit()){
		s->writeType(rolefirsttime_);
	}
	if(__fm__.readBit()){
		s->writeType(rolelasttime_);
	}
	if(__fm__.readBit()){
		s->writeType(rolelv_);
	}
	if(__fm__.readBit()){
		s->writeType(gold_);
	}
	if(__fm__.readBit()){
		s->writeType(diamond_);
	}
	if(__fm__.readBit()){
		s->writeType(magicgold_);
	}
	if(__fm__.readBit()){
		s->writeType(vip_);
	}
	if(__fm__.readBit()){
		s->writeType(ce_);
	}
}

bool SGE_LogRole::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<3> __fm__;
	if(!r->read((void*)__fm__.masks_, 3)) return false;
	if(__fm__.readBit()){
		if(!r->readType(gamename_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfname_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(roleid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(cachetime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(accountid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(serverid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(servername_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(firstserid_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rolefirsttime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rolelasttime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rolelv_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(gold_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(diamond_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(magicgold_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(vip_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(ce_)) return false;
	}
	return true;
}

void SGE_LogProduceTrack::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_timestamp_"), &SGE_LogProduceTrack::get_timestamp_);
	ClassDB::bind_method(D_METHOD("set_timestamp_", "p_val"), &SGE_LogProduceTrack::set_timestamp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "timestamp_"), "set_timestamp_", "get_timestamp_");
	ClassDB::bind_method(D_METHOD("get_from_"), &SGE_LogProduceTrack::get_from_);
	ClassDB::bind_method(D_METHOD("set_from_", "p_val"), &SGE_LogProduceTrack::set_from_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "from_"), "set_from_", "get_from_");
	ClassDB::bind_method(D_METHOD("get_playerId_"), &SGE_LogProduceTrack::get_playerId_);
	ClassDB::bind_method(D_METHOD("set_playerId_", "p_val"), &SGE_LogProduceTrack::set_playerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerId_"), "set_playerId_", "get_playerId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &SGE_LogProduceTrack::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &SGE_LogProduceTrack::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_itemId_"), &SGE_LogProduceTrack::get_itemId_);
	ClassDB::bind_method(D_METHOD("set_itemId_", "p_val"), &SGE_LogProduceTrack::set_itemId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemId_"), "set_itemId_", "get_itemId_");
	ClassDB::bind_method(D_METHOD("get_itemInstId_"), &SGE_LogProduceTrack::get_itemInstId_);
	ClassDB::bind_method(D_METHOD("set_itemInstId_", "p_val"), &SGE_LogProduceTrack::set_itemInstId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemInstId_"), "set_itemInstId_", "get_itemInstId_");
	ClassDB::bind_method(D_METHOD("get_itemStack_"), &SGE_LogProduceTrack::get_itemStack_);
	ClassDB::bind_method(D_METHOD("set_itemStack_", "p_val"), &SGE_LogProduceTrack::set_itemStack_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "itemStack_"), "set_itemStack_", "get_itemStack_");
	ClassDB::bind_method(D_METHOD("get_diamond_"), &SGE_LogProduceTrack::get_diamond_);
	ClassDB::bind_method(D_METHOD("set_diamond_", "p_val"), &SGE_LogProduceTrack::set_diamond_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "diamond_"), "set_diamond_", "get_diamond_");
	ClassDB::bind_method(D_METHOD("get_money_"), &SGE_LogProduceTrack::get_money_);
	ClassDB::bind_method(D_METHOD("set_money_", "p_val"), &SGE_LogProduceTrack::set_money_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "money_"), "set_money_", "get_money_");
	ClassDB::bind_method(D_METHOD("get_exp_"), &SGE_LogProduceTrack::get_exp_);
	ClassDB::bind_method(D_METHOD("set_exp_", "p_val"), &SGE_LogProduceTrack::set_exp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "exp_"), "set_exp_", "get_exp_");
	ClassDB::bind_method(D_METHOD("get_magic_"), &SGE_LogProduceTrack::get_magic_);
	ClassDB::bind_method(D_METHOD("set_magic_", "p_val"), &SGE_LogProduceTrack::set_magic_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "magic_"), "set_magic_", "get_magic_");
}

void SGE_LogProduceTrack::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<2> __fm__;
	__fm__.writeBit((timestamp_==0)?false:true);
	__fm__.writeBit((from_==0)?false:true);
	__fm__.writeBit((playerId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit((itemId_==0)?false:true);
	__fm__.writeBit((itemInstId_==0)?false:true);
	__fm__.writeBit((itemStack_==0)?false:true);
	__fm__.writeBit((diamond_==0)?false:true);
	__fm__.writeBit((money_==0)?false:true);
	__fm__.writeBit((exp_==0)?false:true);
	__fm__.writeBit((magic_==0)?false:true);
	s->write((const void*)__fm__.masks_, 2);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(timestamp_);
	}
	if(__fm__.readBit()){
		s->writeType(from_);
	}
	if(__fm__.readBit()){
		s->writeType(playerId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(itemId_);
	}
	if(__fm__.readBit()){
		s->writeType(itemInstId_);
	}
	if(__fm__.readBit()){
		s->writeType(itemStack_);
	}
	if(__fm__.readBit()){
		s->writeType(diamond_);
	}
	if(__fm__.readBit()){
		s->writeType(money_);
	}
	if(__fm__.readBit()){
		s->writeType(exp_);
	}
	if(__fm__.readBit()){
		s->writeType(magic_);
	}
}

bool SGE_LogProduceTrack::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<2> __fm__;
	if(!r->read((void*)__fm__.masks_, 2)) return false;
	if(__fm__.readBit()){
		if(!r->readType(timestamp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(from_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemInstId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(itemStack_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(diamond_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(money_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(exp_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(magic_)) return false;
	}
	return true;
}

void COM_Exam::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_questionIndex_"), &COM_Exam::get_questionIndex_);
	ClassDB::bind_method(D_METHOD("set_questionIndex_", "p_val"), &COM_Exam::set_questionIndex_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "questionIndex_"), "set_questionIndex_", "get_questionIndex_");
	ClassDB::bind_method(D_METHOD("get_rightNum_"), &COM_Exam::get_rightNum_);
	ClassDB::bind_method(D_METHOD("set_rightNum_", "p_val"), &COM_Exam::set_rightNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rightNum_"), "set_rightNum_", "get_rightNum_");
	ClassDB::bind_method(D_METHOD("get_errorNum_"), &COM_Exam::get_errorNum_);
	ClassDB::bind_method(D_METHOD("set_errorNum_", "p_val"), &COM_Exam::set_errorNum_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "errorNum_"), "set_errorNum_", "get_errorNum_");
	ClassDB::bind_method(D_METHOD("get_money_"), &COM_Exam::get_money_);
	ClassDB::bind_method(D_METHOD("set_money_", "p_val"), &COM_Exam::set_money_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "money_"), "set_money_", "get_money_");
	ClassDB::bind_method(D_METHOD("get_exp_"), &COM_Exam::get_exp_);
	ClassDB::bind_method(D_METHOD("set_exp_", "p_val"), &COM_Exam::set_exp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "exp_"), "set_exp_", "get_exp_");
	ClassDB::bind_method(D_METHOD("get_questions_"), &COM_Exam::get_questions_);
	ClassDB::bind_method(D_METHOD("set_questions_", "p_val"), &COM_Exam::set_questions_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "questions_"), "set_questions_", "get_questions_");
}

void COM_Exam::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((questionIndex_==0)?false:true);
	__fm__.writeBit((rightNum_==0)?false:true);
	__fm__.writeBit((errorNum_==0)?false:true);
	__fm__.writeBit((money_==0)?false:true);
	__fm__.writeBit((exp_==0)?false:true);
	__fm__.writeBit(questions_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(questionIndex_);
	}
	if(__fm__.readBit()){
		s->writeType(rightNum_);
	}
	if(__fm__.readBit()){
		s->writeType(errorNum_);
	}
	if(__fm__.readBit()){
		s->writeType(money_);
	}
	if(__fm__.readBit()){
		s->writeType(exp_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)questions_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			uint32_t __tmp = questions_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_Exam::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(questionIndex_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(rightNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(errorNum_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(money_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(exp_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			questions_.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				questions_[i] = __tmp;
			}
		}
	}
	return true;
}

void COM_Answer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_questionIndex_"), &COM_Answer::get_questionIndex_);
	ClassDB::bind_method(D_METHOD("set_questionIndex_", "p_val"), &COM_Answer::set_questionIndex_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "questionIndex_"), "set_questionIndex_", "get_questionIndex_");
	ClassDB::bind_method(D_METHOD("get_money_"), &COM_Answer::get_money_);
	ClassDB::bind_method(D_METHOD("set_money_", "p_val"), &COM_Answer::set_money_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "money_"), "set_money_", "get_money_");
	ClassDB::bind_method(D_METHOD("get_exp_"), &COM_Answer::get_exp_);
	ClassDB::bind_method(D_METHOD("set_exp_", "p_val"), &COM_Answer::set_exp_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "exp_"), "set_exp_", "get_exp_");
	ClassDB::bind_method(D_METHOD("get_isRigth_"), &COM_Answer::get_isRigth_);
	ClassDB::bind_method(D_METHOD("set_isRigth_", "p_val"), &COM_Answer::set_isRigth_);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "isRigth_"), "set_isRigth_", "get_isRigth_");
}

void COM_Answer::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((questionIndex_==0)?false:true);
	__fm__.writeBit((money_==0)?false:true);
	__fm__.writeBit((exp_==0)?false:true);
	__fm__.writeBit(isRigth_);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(questionIndex_);
	}
	if(__fm__.readBit()){
		s->writeType(money_);
	}
	if(__fm__.readBit()){
		s->writeType(exp_);
	}
	if(__fm__.readBit()){
		s->writeType(isRigth_);
	}
}

bool COM_Answer::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(questionIndex_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(money_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(exp_)) return false;
	}
	if(__fm__.readBit()){
		isRigth_ = __fm__.readBit();
	}
	return true;
}

void COM_Wishing::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_wt_"), &COM_Wishing::get_wt_);
	ClassDB::bind_method(D_METHOD("set_wt_", "p_val"), &COM_Wishing::set_wt_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "wt_"), "set_wt_", "get_wt_");
	ClassDB::bind_method(D_METHOD("get_wish_"), &COM_Wishing::get_wish_);
	ClassDB::bind_method(D_METHOD("set_wish_", "p_val"), &COM_Wishing::set_wish_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "wish_"), "set_wish_", "get_wish_");
}

void COM_Wishing::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(wt_?true:false);
	__fm__.writeBit(wish_.length()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)wt_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(wish_);
	}
}

bool COM_Wishing::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 6) return false;
		wt_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(wish_, 65535)) return false;
	}
	return true;
}

void COM_Wish::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerInstId_"), &COM_Wish::get_playerInstId_);
	ClassDB::bind_method(D_METHOD("set_playerInstId_", "p_val"), &COM_Wish::set_playerInstId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerInstId_"), "set_playerInstId_", "get_playerInstId_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_Wish::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_Wish::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_wish_"), &COM_Wish::get_wish_);
	ClassDB::bind_method(D_METHOD("set_wish_", "p_val"), &COM_Wish::set_wish_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "wish_"), "set_wish_", "get_wish_");
}

void COM_Wish::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((playerInstId_==0)?false:true);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit(wish_.length()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerInstId_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(wish_);
	}
}

bool COM_Wish::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerInstId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(wish_, 65535)) return false;
	}
	return true;
}

void SGE_GmtOrder::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_shopId_"), &SGE_GmtOrder::get_shopId_);
	ClassDB::bind_method(D_METHOD("set_shopId_", "p_val"), &SGE_GmtOrder::set_shopId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "shopId_"), "set_shopId_", "get_shopId_");
	ClassDB::bind_method(D_METHOD("get_orderId_"), &SGE_GmtOrder::get_orderId_);
	ClassDB::bind_method(D_METHOD("set_orderId_", "p_val"), &SGE_GmtOrder::set_orderId_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "orderId_"), "set_orderId_", "get_orderId_");
	ClassDB::bind_method(D_METHOD("get_payment_"), &SGE_GmtOrder::get_payment_);
	ClassDB::bind_method(D_METHOD("set_payment_", "p_val"), &SGE_GmtOrder::set_payment_);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "payment_"), "set_payment_", "get_payment_");
}

void SGE_GmtOrder::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((shopId_==0)?false:true);
	__fm__.writeBit(orderId_.length()?true:false);
	__fm__.writeBit((payment_==0.0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(shopId_);
	}
	if(__fm__.readBit()){
		s->writeType(orderId_);
	}
	if(__fm__.readBit()){
		s->writeType(payment_);
	}
}

bool SGE_GmtOrder::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(shopId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(orderId_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(payment_)) return false;
	}
	return true;
}

void COM_KeyContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_giftname_"), &COM_KeyContent::get_giftname_);
	ClassDB::bind_method(D_METHOD("set_giftname_", "p_val"), &COM_KeyContent::set_giftname_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "giftname_"), "set_giftname_", "get_giftname_");
	ClassDB::bind_method(D_METHOD("get_pfid_"), &COM_KeyContent::get_pfid_);
	ClassDB::bind_method(D_METHOD("set_pfid_", "p_val"), &COM_KeyContent::set_pfid_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "pfid_"), "set_pfid_", "get_pfid_");
	ClassDB::bind_method(D_METHOD("get_key_"), &COM_KeyContent::get_key_);
	ClassDB::bind_method(D_METHOD("set_key_", "p_val"), &COM_KeyContent::set_key_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "key_"), "set_key_", "get_key_");
	ClassDB::bind_method(D_METHOD("get_playerName_"), &COM_KeyContent::get_playerName_);
	ClassDB::bind_method(D_METHOD("set_playerName_", "p_val"), &COM_KeyContent::set_playerName_);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "playerName_"), "set_playerName_", "get_playerName_");
	ClassDB::bind_method(D_METHOD("get_usetime_"), &COM_KeyContent::get_usetime_);
	ClassDB::bind_method(D_METHOD("set_usetime_", "p_val"), &COM_KeyContent::set_usetime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "usetime_"), "set_usetime_", "get_usetime_");
	ClassDB::bind_method(D_METHOD("get_items_"), &COM_KeyContent::get_items_);
	ClassDB::bind_method(D_METHOD("set_items_", "p_val"), &COM_KeyContent::set_items_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "items_"), "set_items_", "get_items_");
}

void COM_KeyContent::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(giftname_.length()?true:false);
	__fm__.writeBit(pfid_.length()?true:false);
	__fm__.writeBit(key_.length()?true:false);
	__fm__.writeBit(playerName_.length()?true:false);
	__fm__.writeBit((usetime_==0)?false:true);
	__fm__.writeBit(items_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(giftname_);
	}
	if(__fm__.readBit()){
		s->writeType(pfid_);
	}
	if(__fm__.readBit()){
		s->writeType(key_);
	}
	if(__fm__.readBit()){
		s->writeType(playerName_);
	}
	if(__fm__.readBit()){
		s->writeType(usetime_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)items_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<COM_GiftItem> __elem = items_[i];
			if (__elem.is_null()) __elem = memnew(COM_GiftItem);
			__elem->serialize(s);
		}
	}
}

bool COM_KeyContent::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(giftname_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(pfid_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(key_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(playerName_, 65535)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(usetime_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			items_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GiftItem> __elem = memnew(COM_GiftItem);
				if(!__elem->deserialize(r)) return false;
				items_[i] = __elem;
			}
		}
	}
	return true;
}

void COM_EmployeeQuestInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_status_"), &COM_EmployeeQuestInst::get_status_);
	ClassDB::bind_method(D_METHOD("set_status_", "p_val"), &COM_EmployeeQuestInst::set_status_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "status_"), "set_status_", "get_status_");
	ClassDB::bind_method(D_METHOD("get_questId_"), &COM_EmployeeQuestInst::get_questId_);
	ClassDB::bind_method(D_METHOD("set_questId_", "p_val"), &COM_EmployeeQuestInst::set_questId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "questId_"), "set_questId_", "get_questId_");
	ClassDB::bind_method(D_METHOD("get_timeout_"), &COM_EmployeeQuestInst::get_timeout_);
	ClassDB::bind_method(D_METHOD("set_timeout_", "p_val"), &COM_EmployeeQuestInst::set_timeout_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "timeout_"), "set_timeout_", "get_timeout_");
	ClassDB::bind_method(D_METHOD("get_usedEmployees_"), &COM_EmployeeQuestInst::get_usedEmployees_);
	ClassDB::bind_method(D_METHOD("set_usedEmployees_", "p_val"), &COM_EmployeeQuestInst::set_usedEmployees_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "usedEmployees_"), "set_usedEmployees_", "get_usedEmployees_");
}

void COM_EmployeeQuestInst::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(status_?true:false);
	__fm__.writeBit((questId_==0)?false:true);
	__fm__.writeBit((timeout_==0)?false:true);
	__fm__.writeBit(usedEmployees_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint16_t __e__ = (uint16_t)status_;
		s->writeType(__e__);
	}
	if(__fm__.readBit()){
		s->writeType(questId_);
	}
	if(__fm__.readBit()){
		s->writeType(timeout_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)usedEmployees_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = usedEmployees_[i];
			s->writeType(__tmp);
		}
	}
}

bool COM_EmployeeQuestInst::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{ uint16_t __e__ = 0;
		if(!r->readType(__e__) || __e__ >= 3) return false;
		status_ = (uint16_t)__e__; }
	}
	if(__fm__.readBit()){
		if(!r->readType(questId_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(timeout_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			usedEmployees_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				usedEmployees_[i] = __tmp;
			}
		}
	}
	return true;
}

void SGE_EmployeeQuestInst::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_doTime_"), &SGE_EmployeeQuestInst::get_doTime_);
	ClassDB::bind_method(D_METHOD("set_doTime_", "p_val"), &SGE_EmployeeQuestInst::set_doTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "doTime_"), "set_doTime_", "get_doTime_");
	ClassDB::bind_method(D_METHOD("get_refreshTime_"), &SGE_EmployeeQuestInst::get_refreshTime_);
	ClassDB::bind_method(D_METHOD("set_refreshTime_", "p_val"), &SGE_EmployeeQuestInst::set_refreshTime_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "refreshTime_"), "set_refreshTime_", "get_refreshTime_");
}

void SGE_EmployeeQuestInst::serialize(ProtocolWriter* s) const {
	COM_EmployeeQuestInst::serialize(s);
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((doTime_==0)?false:true);
	__fm__.writeBit((refreshTime_==0)?false:true);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(doTime_);
	}
	if(__fm__.readBit()){
		s->writeType(refreshTime_);
	}
}

bool SGE_EmployeeQuestInst::deserialize(ProtocolReader* r) {
	if(!COM_EmployeeQuestInst::deserialize(r)) return false;
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(doTime_)) return false;
	}
	if(__fm__.readBit()){
		if(!r->readType(refreshTime_)) return false;
	}
	return true;
}

void SGE_PlayerEmployeeQuestArray::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_value_"), &SGE_PlayerEmployeeQuestArray::get_value_);
	ClassDB::bind_method(D_METHOD("set_value_", "p_val"), &SGE_PlayerEmployeeQuestArray::set_value_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "value_"), "set_value_", "get_value_");
}

void SGE_PlayerEmployeeQuestArray::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit(value_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)value_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<SGE_EmployeeQuestInst> __elem = value_[i];
			if (__elem.is_null()) __elem = memnew(SGE_EmployeeQuestInst);
			__elem->serialize(s);
		}
	}
}

bool SGE_PlayerEmployeeQuestArray::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			value_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<SGE_EmployeeQuestInst> __elem = memnew(SGE_EmployeeQuestInst);
				if(!__elem->deserialize(r)) return false;
				value_[i] = __elem;
			}
		}
	}
	return true;
}

void SGE_PlayerEmployeeQuest::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_playerId_"), &SGE_PlayerEmployeeQuest::get_playerId_);
	ClassDB::bind_method(D_METHOD("set_playerId_", "p_val"), &SGE_PlayerEmployeeQuest::set_playerId_);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerId_"), "set_playerId_", "get_playerId_");
	ClassDB::bind_method(D_METHOD("get_usedEmployees_"), &SGE_PlayerEmployeeQuest::get_usedEmployees_);
	ClassDB::bind_method(D_METHOD("set_usedEmployees_", "p_val"), &SGE_PlayerEmployeeQuest::set_usedEmployees_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "usedEmployees_"), "set_usedEmployees_", "get_usedEmployees_");
	ClassDB::bind_method(D_METHOD("get_quests_"), &SGE_PlayerEmployeeQuest::get_quests_);
	ClassDB::bind_method(D_METHOD("set_quests_", "p_val"), &SGE_PlayerEmployeeQuest::set_quests_);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "quests_"), "set_quests_", "get_quests_");
}

void SGE_PlayerEmployeeQuest::serialize(ProtocolWriter* s) const {
	//field mask
	FieldMask<1> __fm__;
	__fm__.writeBit((playerId_==0)?false:true);
	__fm__.writeBit(usedEmployees_.size()?true:false);
	__fm__.writeBit(quests_.size()?true:false);
	s->write((const void*)__fm__.masks_, 1);
	__fm__.pos_ = 0 ; 
	if(__fm__.readBit()){
		s->writeType(playerId_);
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)usedEmployees_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			int32_t __tmp = usedEmployees_[i];
			s->writeType(__tmp);
		}
	}
	if(__fm__.readBit()){
		uint32_t __len__ = (uint32_t)quests_.size();
		s->writeDynSize(__len__);
		for(int i=0; i<__len__; ++i) {
			Ref<SGE_PlayerEmployeeQuestArray> __elem = quests_[i];
			if (__elem.is_null()) __elem = memnew(SGE_PlayerEmployeeQuestArray);
			__elem->serialize(s);
		}
	}
}

bool SGE_PlayerEmployeeQuest::deserialize(ProtocolReader* r) {
	//field mask
	FieldMask<1> __fm__;
	if(!r->read((void*)__fm__.masks_, 1)) return false;
	if(__fm__.readBit()){
		if(!r->readType(playerId_)) return false;
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			usedEmployees_.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				usedEmployees_[i] = __tmp;
			}
		}
	}
	if(__fm__.readBit()){
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			quests_.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<SGE_PlayerEmployeeQuestArray> __elem = memnew(SGE_PlayerEmployeeQuestArray);
				if(!__elem->deserialize(r)) return false;
				quests_[i] = __elem;
			}
		}
	}
	return true;
}

void Client2Server_Stub::openvip(uint16_t vl) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)vl);
	methodEnd();
}

void Client2Server_Stub::requestPhoto() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::ping() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::sessionlogin(Ref<COM_LoginInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_LoginInfo);
	info->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::login(Ref<COM_LoginInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_LoginInfo);
	info->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::createPlayer(String playername, uint8_t playerTmpId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeType(playerTmpId);
	methodEnd();
}

void Client2Server_Stub::deletePlayer(String playername) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	methodEnd();
}

void Client2Server_Stub::enterGame(uint32_t playerInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	__writer->writeType(playerInstId);
	methodEnd();
}

void Client2Server_Stub::requestBag() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestEmployees() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestStorage(uint16_t tp) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 10;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)tp);
	methodEnd();
}

void Client2Server_Stub::requestAchievement() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 11;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::initminig() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 12;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestCompound() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 13;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::move(float x, float z) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 14;
	__writer->writeType(__pid);
	__writer->writeType(x);
	__writer->writeType(z);
	methodEnd();
}

void Client2Server_Stub::moveToNpc(int32_t npcid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 15;
	__writer->writeType(__pid);
	__writer->writeType(npcid);
	methodEnd();
}

void Client2Server_Stub::moveToNpc2(uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 16;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void Client2Server_Stub::moveToZone(int32_t sceneId, int32_t zoneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 17;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	__writer->writeType(zoneId);
	methodEnd();
}

void Client2Server_Stub::autoBattle() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 18;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::stopAutoBattle() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 19;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::stopMove() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 20;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::exitCopy() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 21;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::transforScene(int32_t sceneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 22;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	methodEnd();
}

void Client2Server_Stub::sceneLoaded() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 23;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::querySimplePlayerInst(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 24;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::logout() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 25;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::changProp(uint32_t guid, TypedArray<COM_Addprop> props) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 26;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	__writer->writeDynSize(props.size());
	for(int i=0; i<props.size(); ++i) {
		Ref<COM_Addprop> __elem = props[i];
		if (__elem.is_null()) __elem = memnew(COM_Addprop);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Client2Server_Stub::learnSkill(uint32_t skid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 27;
	__writer->writeType(__pid);
	__writer->writeType(skid);
	methodEnd();
}

void Client2Server_Stub::babyLearnSkill(uint32_t instId, uint32_t oldSkId, uint32_t newSkId, uint32_t newSkLv) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 28;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(oldSkId);
	__writer->writeType(newSkId);
	__writer->writeType(newSkLv);
	methodEnd();
}

void Client2Server_Stub::forgetSkill(uint32_t skid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 29;
	__writer->writeType(__pid);
	__writer->writeType(skid);
	methodEnd();
}

void Client2Server_Stub::syncOrder(Ref<COM_Order> order) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 30;
	__writer->writeType(__pid);
	if (order.is_null()) order = memnew(COM_Order);
	order->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::syncOrderTimeout() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 31;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::sendChat(Ref<COM_Chat> content, String targetName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 32;
	__writer->writeType(__pid);
	if (content.is_null()) content = memnew(COM_Chat);
	content->serialize(__writer);
	__writer->writeType(targetName);
	methodEnd();
}

void Client2Server_Stub::requestAudio(int32_t audioId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 33;
	__writer->writeType(__pid);
	__writer->writeType(audioId);
	methodEnd();
}

void Client2Server_Stub::publishItemInst(uint16_t type, uint32_t itemInstId, uint16_t chatType, String playerName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 34;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(itemInstId);
	__writer->writeType((uint16_t)chatType);
	__writer->writeType(playerName);
	methodEnd();
}

void Client2Server_Stub::queryItemInst(int32_t showId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 35;
	__writer->writeType(__pid);
	__writer->writeType(showId);
	methodEnd();
}

void Client2Server_Stub::publishbabyInst(uint16_t type, uint32_t babyInstId, String playerName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 36;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(babyInstId);
	__writer->writeType(playerName);
	methodEnd();
}

void Client2Server_Stub::querybabyInst(int32_t showId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 37;
	__writer->writeType(__pid);
	__writer->writeType(showId);
	methodEnd();
}

void Client2Server_Stub::useItem(uint32_t slot, uint32_t target, uint32_t stack) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 38;
	__writer->writeType(__pid);
	__writer->writeType(slot);
	__writer->writeType(target);
	__writer->writeType(stack);
	methodEnd();
}

void Client2Server_Stub::wearEquipment(uint32_t target, uint32_t itemInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 39;
	__writer->writeType(__pid);
	__writer->writeType(target);
	__writer->writeType(itemInstId);
	methodEnd();
}

void Client2Server_Stub::delEquipment(uint32_t target, uint32_t itemInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 40;
	__writer->writeType(__pid);
	__writer->writeType(target);
	__writer->writeType(itemInstId);
	methodEnd();
}

void Client2Server_Stub::setPlayerFront(bool isFront) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 41;
	__writer->writeType(__pid);
	__writer->writeType(isFront);
	methodEnd();
}

void Client2Server_Stub::setBattlebaby(uint32_t babyID, bool isBattle) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 42;
	__writer->writeType(__pid);
	__writer->writeType(babyID);
	__writer->writeType(isBattle);
	methodEnd();
}

void Client2Server_Stub::changeBabyName(uint32_t babyID, String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 43;
	__writer->writeType(__pid);
	__writer->writeType(babyID);
	__writer->writeType(name);
	methodEnd();
}

void Client2Server_Stub::intensifyBaby(uint32_t babyid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 44;
	__writer->writeType(__pid);
	__writer->writeType(babyid);
	methodEnd();
}

void Client2Server_Stub::setBattleEmp(uint32_t empID, uint16_t group, bool isBattle) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 45;
	__writer->writeType(__pid);
	__writer->writeType(empID);
	__writer->writeType((uint16_t)group);
	__writer->writeType(isBattle);
	methodEnd();
}

void Client2Server_Stub::changeEmpBattleGroup(uint16_t group) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 46;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)group);
	methodEnd();
}

void Client2Server_Stub::requestEvolve(uint32_t empInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 47;
	__writer->writeType(__pid);
	__writer->writeType(empInstId);
	methodEnd();
}

void Client2Server_Stub::requestUpStar(uint32_t empInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 48;
	__writer->writeType(__pid);
	__writer->writeType(empInstId);
	methodEnd();
}

void Client2Server_Stub::requestDelEmp(uint32_t empInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 49;
	__writer->writeType(__pid);
	__writer->writeType(empInstId);
	methodEnd();
}

void Client2Server_Stub::delEmployee(TypedArray<uint32_t> emps) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 50;
	__writer->writeType(__pid);
	__writer->writeDynSize(emps.size());
	for(int i=0; i<emps.size(); ++i) {
		uint32_t __tmp = emps[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Client2Server_Stub::onekeyDelEmp() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 51;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::delEmployeeSoul(uint32_t instid, uint32_t soulNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 52;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	__writer->writeType(soulNum);
	methodEnd();
}

void Client2Server_Stub::sortBagItem() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 53;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::sellBagItem(uint32_t instId, uint32_t stack) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 54;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(stack);
	methodEnd();
}

void Client2Server_Stub::depositItemToStorage(uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 55;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Client2Server_Stub::depositBabyToStorage(uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 56;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Client2Server_Stub::storageItemToBag(uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 57;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Client2Server_Stub::storageBabyToPlayer(uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 58;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Client2Server_Stub::sortStorage(uint16_t tp) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 59;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)tp);
	methodEnd();
}

void Client2Server_Stub::delStorageBaby(uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 60;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Client2Server_Stub::jointLobby() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 61;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::exitLobby() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 62;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::createTeam(Ref<COM_CreateTeamInfo> cti) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 63;
	__writer->writeType(__pid);
	if (cti.is_null()) cti = memnew(COM_CreateTeamInfo);
	cti->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::changeTeam(Ref<COM_CreateTeamInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 64;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_CreateTeamInfo);
	info->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::kickTeamMember(uint32_t uuid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 65;
	__writer->writeType(__pid);
	__writer->writeType(uuid);
	methodEnd();
}

void Client2Server_Stub::changeTeamLeader(uint32_t uuid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 66;
	__writer->writeType(__pid);
	__writer->writeType(uuid);
	methodEnd();
}

void Client2Server_Stub::joinTeam(uint32_t teamId, String pwd) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 67;
	__writer->writeType(__pid);
	__writer->writeType(teamId);
	__writer->writeType(pwd);
	methodEnd();
}

void Client2Server_Stub::exitTeam() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 68;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::changeTeamPassword(String pwd) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 69;
	__writer->writeType(__pid);
	__writer->writeType(pwd);
	methodEnd();
}

void Client2Server_Stub::joinTeamRoom() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 70;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::inviteTeamMember(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 71;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Client2Server_Stub::isjoinTeam(uint32_t teamId, bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 72;
	__writer->writeType(__pid);
	__writer->writeType(teamId);
	__writer->writeType(isFlag);
	methodEnd();
}

void Client2Server_Stub::leaveTeam() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 73;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::backTeam() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 74;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::refuseBackTeam() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 75;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::teamCallMember(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 76;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Client2Server_Stub::requestJoinTeam(String targetName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 77;
	__writer->writeType(__pid);
	__writer->writeType(targetName);
	methodEnd();
}

void Client2Server_Stub::ratifyJoinTeam(String sendName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 78;
	__writer->writeType(__pid);
	__writer->writeType(sendName);
	methodEnd();
}

void Client2Server_Stub::drawLotteryBox(uint16_t type, bool isFree) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 79;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(isFree);
	methodEnd();
}

void Client2Server_Stub::acceptQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 80;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void Client2Server_Stub::submitQuest(int32_t npcId, int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 81;
	__writer->writeType(__pid);
	__writer->writeType(npcId);
	__writer->writeType(questId);
	methodEnd();
}

void Client2Server_Stub::giveupQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 82;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void Client2Server_Stub::requestContactInfoById(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 83;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::requestContactInfoByName(String instName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 84;
	__writer->writeType(__pid);
	__writer->writeType(instName);
	methodEnd();
}

void Client2Server_Stub::requestFriendList() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 85;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::addFriend(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 86;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::delFriend(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 87;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::addBlacklist(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 88;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::delBlacklist(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 89;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::requestReferrFriend() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 90;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::mining(int32_t gatherId, int32_t times) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 91;
	__writer->writeType(__pid);
	__writer->writeType(gatherId);
	__writer->writeType(times);
	methodEnd();
}

void Client2Server_Stub::compoundItem(int32_t itemId, int32_t gemId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 92;
	__writer->writeType(__pid);
	__writer->writeType(itemId);
	__writer->writeType(gemId);
	methodEnd();
}

void Client2Server_Stub::bagItemSplit(int32_t instId, int32_t splitNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 93;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(splitNum);
	methodEnd();
}

void Client2Server_Stub::requestChallenge(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 94;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Client2Server_Stub::requestRival() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 95;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestMySelfJJCData() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 96;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestCheckMsg(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 97;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Client2Server_Stub::requestMyAllbattleMsg() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 98;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestJJCRank() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 99;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestLevelRank() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 100;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestBabyRank() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 101;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestEmpRank() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 102;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestPlayerFFRank() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 103;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::queryOnlinePlayerbyName(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 104;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Client2Server_Stub::queryPlayerbyName(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 105;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Client2Server_Stub::queryBaby(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 106;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::queryEmployee(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 107;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::guideFinish(uint64_t guideIdx) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 108;
	__writer->writeType(__pid);
	__writer->writeType(guideIdx);
	methodEnd();
}

void Client2Server_Stub::enterBattle(int32_t battleId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 109;
	__writer->writeType(__pid);
	__writer->writeType(battleId);
	methodEnd();
}

void Client2Server_Stub::shopBuyItem(int32_t id, int32_t num) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 110;
	__writer->writeType(__pid);
	__writer->writeType(id);
	__writer->writeType(num);
	methodEnd();
}

void Client2Server_Stub::getFirstRechargeItem() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 111;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestLevelGift(int32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 112;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Client2Server_Stub::setCurrentTitle(int32_t title) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 113;
	__writer->writeType(__pid);
	__writer->writeType(title);
	methodEnd();
}

void Client2Server_Stub::openBuyBox() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 114;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestAchaward(int32_t achId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 115;
	__writer->writeType(__pid);
	__writer->writeType(achId);
	methodEnd();
}

void Client2Server_Stub::sign(int32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 116;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestSignupReward7() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 117;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestSignupReward14() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 118;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestSignupReward28() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 119;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestActivityReward(int32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 120;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::resetHundredTier() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 121;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::enterHundredScene(int32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 122;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Client2Server_Stub::delBaby(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 123;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::resetBaby(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 124;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::resetBabyProp(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 125;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::remouldBaby(int32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 126;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Client2Server_Stub::empSkillLevelUp(uint32_t empId, int32_t skillId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 127;
	__writer->writeType(__pid);
	__writer->writeType(empId);
	__writer->writeType(skillId);
	methodEnd();
}

void Client2Server_Stub::setOpenDoubleTimeFlag(bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 128;
	__writer->writeType(__pid);
	__writer->writeType(isFlag);
	methodEnd();
}

void Client2Server_Stub::talkedNpc(int32_t npcId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 129;
	__writer->writeType(__pid);
	__writer->writeType(npcId);
	methodEnd();
}

void Client2Server_Stub::jjcBattleGo(uint32_t id) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 130;
	__writer->writeType(__pid);
	__writer->writeType(id);
	methodEnd();
}

void Client2Server_Stub::requestMyJJCTeamMsg() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 131;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::startMatching() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 132;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::stopMatching() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 133;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::exitPvpJJC() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 134;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::joinPvpLobby() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 135;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::exitPvpLobby() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 136;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestpvprank() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 137;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::joinWarriorchoose() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 138;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::warriorStart() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 139;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::warriorStop() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 140;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::sendMail(String playername, String title, String content) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 141;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeType(title);
	__writer->writeType(content);
	methodEnd();
}

void Client2Server_Stub::readMail(int32_t mailId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 142;
	__writer->writeType(__pid);
	__writer->writeType(mailId);
	methodEnd();
}

void Client2Server_Stub::delMail(int32_t mailId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 143;
	__writer->writeType(__pid);
	__writer->writeType(mailId);
	methodEnd();
}

void Client2Server_Stub::getMailItem(int32_t mailId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 144;
	__writer->writeType(__pid);
	__writer->writeType(mailId);
	methodEnd();
}

void Client2Server_Stub::requestState() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 145;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::createGuild(String guildName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 146;
	__writer->writeType(__pid);
	__writer->writeType(guildName);
	methodEnd();
}

void Client2Server_Stub::delGuild(uint32_t guildId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 147;
	__writer->writeType(__pid);
	__writer->writeType(guildId);
	methodEnd();
}

void Client2Server_Stub::requestJoinGuild(uint32_t guid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 148;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	methodEnd();
}

void Client2Server_Stub::leaveGuild() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 149;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::kickOut(int32_t guid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 150;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	methodEnd();
}

void Client2Server_Stub::acceptRequestGuild(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 151;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Client2Server_Stub::refuseRequestGuild(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 152;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Client2Server_Stub::changeMemberPosition(int32_t targetId, uint16_t job) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 153;
	__writer->writeType(__pid);
	__writer->writeType(targetId);
	__writer->writeType((uint16_t)job);
	methodEnd();
}

void Client2Server_Stub::transferPremier(int32_t targetId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 154;
	__writer->writeType(__pid);
	__writer->writeType(targetId);
	methodEnd();
}

void Client2Server_Stub::changeGuildNotice(String notice) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 155;
	__writer->writeType(__pid);
	__writer->writeType(notice);
	methodEnd();
}

void Client2Server_Stub::queryGuildList(int16_t page) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 156;
	__writer->writeType(__pid);
	__writer->writeType(page);
	methodEnd();
}

void Client2Server_Stub::inviteJoinGuild(String playerName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 157;
	__writer->writeType(__pid);
	__writer->writeType(playerName);
	methodEnd();
}

void Client2Server_Stub::respondInviteJoinGuild(String sendName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 158;
	__writer->writeType(__pid);
	__writer->writeType(sendName);
	methodEnd();
}

void Client2Server_Stub::buyGuildItem(int32_t tableId, int32_t times) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 159;
	__writer->writeType(__pid);
	__writer->writeType(tableId);
	__writer->writeType(times);
	methodEnd();
}

void Client2Server_Stub::entryGuildBattle() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 160;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::transforGuildBattleScene() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 161;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::addGuildMoney(int32_t money) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 162;
	__writer->writeType(__pid);
	__writer->writeType(money);
	methodEnd();
}

void Client2Server_Stub::updateGuildBuiling(uint16_t gbt) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 163;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)gbt);
	methodEnd();
}

void Client2Server_Stub::refreshGuildShop() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 164;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::levelupGuildSkill(int32_t skId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 165;
	__writer->writeType(__pid);
	__writer->writeType(skId);
	methodEnd();
}

void Client2Server_Stub::presentGuildItem(int32_t num) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 166;
	__writer->writeType(__pid);
	__writer->writeType(num);
	methodEnd();
}

void Client2Server_Stub::progenitusAddExp(int32_t monsterId, bool isSuper) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 167;
	__writer->writeType(__pid);
	__writer->writeType(monsterId);
	__writer->writeType(isSuper);
	methodEnd();
}

void Client2Server_Stub::setProgenitusPosition(int32_t mId, int32_t pos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 168;
	__writer->writeType(__pid);
	__writer->writeType(mId);
	__writer->writeType(pos);
	methodEnd();
}

void Client2Server_Stub::guildsign() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 169;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::fetchSelling(Ref<COM_SearchContext> context) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 170;
	__writer->writeType(__pid);
	if (context.is_null()) context = memnew(COM_SearchContext);
	context->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::fetchSelling2(Ref<COM_SearchContext> context) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 171;
	__writer->writeType(__pid);
	if (context.is_null()) context = memnew(COM_SearchContext);
	context->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::selling(int32_t iteminstid, int32_t babyinstid, int32_t price) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 172;
	__writer->writeType(__pid);
	__writer->writeType(iteminstid);
	__writer->writeType(babyinstid);
	__writer->writeType(price);
	methodEnd();
}

void Client2Server_Stub::unselling(int32_t sellid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 173;
	__writer->writeType(__pid);
	__writer->writeType(sellid);
	methodEnd();
}

void Client2Server_Stub::buy(int32_t sellid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 174;
	__writer->writeType(__pid);
	__writer->writeType(sellid);
	methodEnd();
}

void Client2Server_Stub::fixItem(int32_t instId, uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 175;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void Client2Server_Stub::fixAllItem(TypedArray<uint32_t> items, uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 176;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		uint32_t __tmp = items[i];
		__writer->writeType(__tmp);
	}
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void Client2Server_Stub::makeDebirsItem(int32_t instId, int32_t num) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 177;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(num);
	methodEnd();
}

void Client2Server_Stub::levelUpMagicItem(TypedArray<uint32_t> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 178;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		uint32_t __tmp = items[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Client2Server_Stub::tupoMagicItem(int32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 179;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Client2Server_Stub::changeMagicJob(uint16_t job) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 180;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)job);
	methodEnd();
}

void Client2Server_Stub::requestPk(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 181;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Client2Server_Stub::uiBehavior(uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 182;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void Client2Server_Stub::openZhuanpan() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 183;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::zhuanpanGo(uint32_t counter) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 184;
	__writer->writeType(__pid);
	__writer->writeType(counter);
	methodEnd();
}

void Client2Server_Stub::redemptionSpree(String code) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 185;
	__writer->writeType(__pid);
	__writer->writeType(code);
	methodEnd();
}

void Client2Server_Stub::sceneFilter(TypedArray<uint16_t> sfType) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 186;
	__writer->writeType(__pid);
	__writer->writeDynSize(sfType.size());
	for(int i=0; i<sfType.size(); ++i) {
		__writer->writeType((uint16_t)sfType[i]);
	}
	methodEnd();
}

void Client2Server_Stub::sendExamAnswer(uint32_t questionId, uint8_t answer) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 187;
	__writer->writeType(__pid);
	__writer->writeType(questionId);
	__writer->writeType(answer);
	methodEnd();
}

void Client2Server_Stub::sendwishing(Ref<COM_Wishing> wish) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 188;
	__writer->writeType(__pid);
	if (wish.is_null()) wish = memnew(COM_Wishing);
	wish->serialize(__writer);
	methodEnd();
}

void Client2Server_Stub::requestWish() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 189;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::leaderCloseDialog() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 190;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestOnlineReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 191;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestFundReward(uint32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 192;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Client2Server_Stub::openCard(uint16_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 193;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::resetCard() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 194;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::hotRoleBuy() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 195;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestSevenReward(uint32_t qid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 196;
	__writer->writeType(__pid);
	__writer->writeType(qid);
	methodEnd();
}

void Client2Server_Stub::vipreward() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 197;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::requestChargeTotalSingleReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 198;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestChargeTotalReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 199;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestChargeEverySingleReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 200;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestChargeEveryReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 201;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestLoginTotal(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 202;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::buyDiscountStoreSingle(int32_t itemId, int32_t itemStack) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 203;
	__writer->writeType(__pid);
	__writer->writeType(itemId);
	__writer->writeType(itemStack);
	methodEnd();
}

void Client2Server_Stub::buyDiscountStore(int32_t itemId, int32_t itemStack) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 204;
	__writer->writeType(__pid);
	__writer->writeType(itemId);
	__writer->writeType(itemStack);
	methodEnd();
}

void Client2Server_Stub::requestEmployeeActivityReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 205;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestmyselfrechargeleReward(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 206;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Client2Server_Stub::requestEverydayIntegral() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 207;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::buyIntegralItem(uint32_t id, uint32_t num) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 208;
	__writer->writeType(__pid);
	__writer->writeType(id);
	__writer->writeType(num);
	methodEnd();
}

void Client2Server_Stub::familyLoseLeader() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 209;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::verificationSMS(String phoneNumber, String code) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 210;
	__writer->writeType(__pid);
	__writer->writeType(phoneNumber);
	__writer->writeType(code);
	methodEnd();
}

void Client2Server_Stub::lockItem(int32_t instId, bool isLock) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 211;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(isLock);
	methodEnd();
}

void Client2Server_Stub::lockBaby(int32_t instId, bool isLock) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 212;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(isLock);
	methodEnd();
}

void Client2Server_Stub::showBaby(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 213;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Client2Server_Stub::wearFuwen(int32_t itemInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 214;
	__writer->writeType(__pid);
	__writer->writeType(itemInstId);
	methodEnd();
}

void Client2Server_Stub::takeoffFuwen(int32_t slotId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 215;
	__writer->writeType(__pid);
	__writer->writeType(slotId);
	methodEnd();
}

void Client2Server_Stub::compFuwen(int32_t itemInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 216;
	__writer->writeType(__pid);
	__writer->writeType(itemInstId);
	methodEnd();
}

void Client2Server_Stub::requestEmployeeQuest() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 217;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::acceptEmployeeQuest(int32_t questId, TypedArray<int32_t> employees) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 218;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	__writer->writeDynSize(employees.size());
	for(int i=0; i<employees.size(); ++i) {
		int32_t __tmp = employees[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Client2Server_Stub::submitEmployeeQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 219;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void Client2Server_Stub::crystalUpLevel() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 220;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::resetCrystalProp(TypedArray<int32_t> locklist) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 221;
	__writer->writeType(__pid);
	__writer->writeDynSize(locklist.size());
	for(int i=0; i<locklist.size(); ++i) {
		int32_t __tmp = locklist[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Client2Server_Stub::magicItemOneKeyLevel() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 222;
	__writer->writeType(__pid);
	methodEnd();
}

void Client2Server_Stub::submitQuest2(int32_t npcId, int32_t questId, int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 223;
	__writer->writeType(__pid);
	__writer->writeType(npcId);
	__writer->writeType(questId);
	__writer->writeType(instId);
	methodEnd();
}

bool Client2Server_Dispatcher::dispatch(ProtocolReader* r, Client2Server_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		uint16_t __vl = (VipLevel)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 4) return false; __vl = (uint16_t)__e; }
		proxy->openvip(__vl);
		return true;
	}
	case 1: {
		proxy->requestPhoto();
		return true;
	}
	case 2: {
		proxy->ping();
		return true;
	}
	case 3: {
		Ref<COM_LoginInfo> __info = memnew(COM_LoginInfo);
		if (!__info->deserialize(r)) return false;
		proxy->sessionlogin(__info);
		return true;
	}
	case 4: {
		Ref<COM_LoginInfo> __info = memnew(COM_LoginInfo);
		if (!__info->deserialize(r)) return false;
		proxy->login(__info);
		return true;
	}
	case 5: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		uint8_t __playerTmpId = 0;
		if (!r->readType(__playerTmpId)) return false;
		proxy->createPlayer(__playername, __playerTmpId);
		return true;
	}
	case 6: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		proxy->deletePlayer(__playername);
		return true;
	}
	case 7: {
		uint32_t __playerInstId = 0;
		if (!r->readType(__playerInstId)) return false;
		proxy->enterGame(__playerInstId);
		return true;
	}
	case 8: {
		proxy->requestBag();
		return true;
	}
	case 9: {
		proxy->requestEmployees();
		return true;
	}
	case 10: {
		uint16_t __tp = (StorageType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 2) return false; __tp = (uint16_t)__e; }
		proxy->requestStorage(__tp);
		return true;
	}
	case 11: {
		proxy->requestAchievement();
		return true;
	}
	case 12: {
		proxy->initminig();
		return true;
	}
	case 13: {
		proxy->requestCompound();
		return true;
	}
	case 14: {
		float __x = 0.0;
		if (!r->readType(__x)) return false;
		float __z = 0.0;
		if (!r->readType(__z)) return false;
		proxy->move(__x, __z);
		return true;
	}
	case 15: {
		int32_t __npcid = 0;
		if (!r->readType(__npcid)) return false;
		proxy->moveToNpc(__npcid);
		return true;
	}
	case 16: {
		uint16_t __type = (NpcType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 11) return false; __type = (uint16_t)__e; }
		proxy->moveToNpc2(__type);
		return true;
	}
	case 17: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		int32_t __zoneId = 0;
		if (!r->readType(__zoneId)) return false;
		proxy->moveToZone(__sceneId, __zoneId);
		return true;
	}
	case 18: {
		proxy->autoBattle();
		return true;
	}
	case 19: {
		proxy->stopAutoBattle();
		return true;
	}
	case 20: {
		proxy->stopMove();
		return true;
	}
	case 21: {
		proxy->exitCopy();
		return true;
	}
	case 22: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		proxy->transforScene(__sceneId);
		return true;
	}
	case 23: {
		proxy->sceneLoaded();
		return true;
	}
	case 24: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->querySimplePlayerInst(__instId);
		return true;
	}
	case 25: {
		proxy->logout();
		return true;
	}
	case 26: {
		uint32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		TypedArray<COM_Addprop> __props;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__props.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Addprop> __elem = memnew(COM_Addprop);
				if(!__elem->deserialize(r)) return false;
				__props[i] = __elem;
			}
		}
		proxy->changProp(__guid, __props);
		return true;
	}
	case 27: {
		uint32_t __skid = 0;
		if (!r->readType(__skid)) return false;
		proxy->learnSkill(__skid);
		return true;
	}
	case 28: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		uint32_t __oldSkId = 0;
		if (!r->readType(__oldSkId)) return false;
		uint32_t __newSkId = 0;
		if (!r->readType(__newSkId)) return false;
		uint32_t __newSkLv = 0;
		if (!r->readType(__newSkLv)) return false;
		proxy->babyLearnSkill(__instId, __oldSkId, __newSkId, __newSkLv);
		return true;
	}
	case 29: {
		uint32_t __skid = 0;
		if (!r->readType(__skid)) return false;
		proxy->forgetSkill(__skid);
		return true;
	}
	case 30: {
		Ref<COM_Order> __order = memnew(COM_Order);
		if (!__order->deserialize(r)) return false;
		proxy->syncOrder(__order);
		return true;
	}
	case 31: {
		proxy->syncOrderTimeout();
		return true;
	}
	case 32: {
		Ref<COM_Chat> __content = memnew(COM_Chat);
		if (!__content->deserialize(r)) return false;
		String __targetName = "";
		if (!r->readType(__targetName, 65535)) return false;
		proxy->sendChat(__content, __targetName);
		return true;
	}
	case 33: {
		int32_t __audioId = 0;
		if (!r->readType(__audioId)) return false;
		proxy->requestAudio(__audioId);
		return true;
	}
	case 34: {
		uint16_t __type = (ItemContainerType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 2) return false; __type = (uint16_t)__e; }
		uint32_t __itemInstId = 0;
		if (!r->readType(__itemInstId)) return false;
		uint16_t __chatType = (ChatKind)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 8) return false; __chatType = (uint16_t)__e; }
		String __playerName = "";
		if (!r->readType(__playerName, 65535)) return false;
		proxy->publishItemInst(__type, __itemInstId, __chatType, __playerName);
		return true;
	}
	case 35: {
		int32_t __showId = 0;
		if (!r->readType(__showId)) return false;
		proxy->queryItemInst(__showId);
		return true;
	}
	case 36: {
		uint16_t __type = (ChatKind)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 8) return false; __type = (uint16_t)__e; }
		uint32_t __babyInstId = 0;
		if (!r->readType(__babyInstId)) return false;
		String __playerName = "";
		if (!r->readType(__playerName, 65535)) return false;
		proxy->publishbabyInst(__type, __babyInstId, __playerName);
		return true;
	}
	case 37: {
		int32_t __showId = 0;
		if (!r->readType(__showId)) return false;
		proxy->querybabyInst(__showId);
		return true;
	}
	case 38: {
		uint32_t __slot = 0;
		if (!r->readType(__slot)) return false;
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		uint32_t __stack = 0;
		if (!r->readType(__stack)) return false;
		proxy->useItem(__slot, __target, __stack);
		return true;
	}
	case 39: {
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		uint32_t __itemInstId = 0;
		if (!r->readType(__itemInstId)) return false;
		proxy->wearEquipment(__target, __itemInstId);
		return true;
	}
	case 40: {
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		uint32_t __itemInstId = 0;
		if (!r->readType(__itemInstId)) return false;
		proxy->delEquipment(__target, __itemInstId);
		return true;
	}
	case 41: {
		bool __isFront = false;
		if (!r->readType(__isFront)) return false;
		proxy->setPlayerFront(__isFront);
		return true;
	}
	case 42: {
		uint32_t __babyID = 0;
		if (!r->readType(__babyID)) return false;
		bool __isBattle = false;
		if (!r->readType(__isBattle)) return false;
		proxy->setBattlebaby(__babyID, __isBattle);
		return true;
	}
	case 43: {
		uint32_t __babyID = 0;
		if (!r->readType(__babyID)) return false;
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->changeBabyName(__babyID, __name);
		return true;
	}
	case 44: {
		uint32_t __babyid = 0;
		if (!r->readType(__babyid)) return false;
		proxy->intensifyBaby(__babyid);
		return true;
	}
	case 45: {
		uint32_t __empID = 0;
		if (!r->readType(__empID)) return false;
		uint16_t __group = (EmployeesBattleGroup)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 5) return false; __group = (uint16_t)__e; }
		bool __isBattle = false;
		if (!r->readType(__isBattle)) return false;
		proxy->setBattleEmp(__empID, __group, __isBattle);
		return true;
	}
	case 46: {
		uint16_t __group = (EmployeesBattleGroup)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 5) return false; __group = (uint16_t)__e; }
		proxy->changeEmpBattleGroup(__group);
		return true;
	}
	case 47: {
		uint32_t __empInstId = 0;
		if (!r->readType(__empInstId)) return false;
		proxy->requestEvolve(__empInstId);
		return true;
	}
	case 48: {
		uint32_t __empInstId = 0;
		if (!r->readType(__empInstId)) return false;
		proxy->requestUpStar(__empInstId);
		return true;
	}
	case 49: {
		uint32_t __empInstId = 0;
		if (!r->readType(__empInstId)) return false;
		proxy->requestDelEmp(__empInstId);
		return true;
	}
	case 50: {
		TypedArray<uint32_t> __emps;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__emps.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__emps[i] = __tmp;
			}
		}
		proxy->delEmployee(__emps);
		return true;
	}
	case 51: {
		proxy->onekeyDelEmp();
		return true;
	}
	case 52: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		uint32_t __soulNum = 0;
		if (!r->readType(__soulNum)) return false;
		proxy->delEmployeeSoul(__instid, __soulNum);
		return true;
	}
	case 53: {
		proxy->sortBagItem();
		return true;
	}
	case 54: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		uint32_t __stack = 0;
		if (!r->readType(__stack)) return false;
		proxy->sellBagItem(__instId, __stack);
		return true;
	}
	case 55: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->depositItemToStorage(__instid);
		return true;
	}
	case 56: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->depositBabyToStorage(__instid);
		return true;
	}
	case 57: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->storageItemToBag(__instid);
		return true;
	}
	case 58: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->storageBabyToPlayer(__instid);
		return true;
	}
	case 59: {
		uint16_t __tp = (StorageType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 2) return false; __tp = (uint16_t)__e; }
		proxy->sortStorage(__tp);
		return true;
	}
	case 60: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->delStorageBaby(__instid);
		return true;
	}
	case 61: {
		proxy->jointLobby();
		return true;
	}
	case 62: {
		proxy->exitLobby();
		return true;
	}
	case 63: {
		Ref<COM_CreateTeamInfo> __cti = memnew(COM_CreateTeamInfo);
		if (!__cti->deserialize(r)) return false;
		proxy->createTeam(__cti);
		return true;
	}
	case 64: {
		Ref<COM_CreateTeamInfo> __info = memnew(COM_CreateTeamInfo);
		if (!__info->deserialize(r)) return false;
		proxy->changeTeam(__info);
		return true;
	}
	case 65: {
		uint32_t __uuid = 0;
		if (!r->readType(__uuid)) return false;
		proxy->kickTeamMember(__uuid);
		return true;
	}
	case 66: {
		uint32_t __uuid = 0;
		if (!r->readType(__uuid)) return false;
		proxy->changeTeamLeader(__uuid);
		return true;
	}
	case 67: {
		uint32_t __teamId = 0;
		if (!r->readType(__teamId)) return false;
		String __pwd = "";
		if (!r->readType(__pwd, 65535)) return false;
		proxy->joinTeam(__teamId, __pwd);
		return true;
	}
	case 68: {
		proxy->exitTeam();
		return true;
	}
	case 69: {
		String __pwd = "";
		if (!r->readType(__pwd, 65535)) return false;
		proxy->changeTeamPassword(__pwd);
		return true;
	}
	case 70: {
		proxy->joinTeamRoom();
		return true;
	}
	case 71: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->inviteTeamMember(__name);
		return true;
	}
	case 72: {
		uint32_t __teamId = 0;
		if (!r->readType(__teamId)) return false;
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->isjoinTeam(__teamId, __isFlag);
		return true;
	}
	case 73: {
		proxy->leaveTeam();
		return true;
	}
	case 74: {
		proxy->backTeam();
		return true;
	}
	case 75: {
		proxy->refuseBackTeam();
		return true;
	}
	case 76: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->teamCallMember(__playerId);
		return true;
	}
	case 77: {
		String __targetName = "";
		if (!r->readType(__targetName, 65535)) return false;
		proxy->requestJoinTeam(__targetName);
		return true;
	}
	case 78: {
		String __sendName = "";
		if (!r->readType(__sendName, 65535)) return false;
		proxy->ratifyJoinTeam(__sendName);
		return true;
	}
	case 79: {
		uint16_t __type = (BoxType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 4) return false; __type = (uint16_t)__e; }
		bool __isFree = false;
		if (!r->readType(__isFree)) return false;
		proxy->drawLotteryBox(__type, __isFree);
		return true;
	}
	case 80: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->acceptQuest(__questId);
		return true;
	}
	case 81: {
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->submitQuest(__npcId, __questId);
		return true;
	}
	case 82: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->giveupQuest(__questId);
		return true;
	}
	case 83: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->requestContactInfoById(__instId);
		return true;
	}
	case 84: {
		String __instName = "";
		if (!r->readType(__instName, 65535)) return false;
		proxy->requestContactInfoByName(__instName);
		return true;
	}
	case 85: {
		proxy->requestFriendList();
		return true;
	}
	case 86: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->addFriend(__instId);
		return true;
	}
	case 87: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delFriend(__instId);
		return true;
	}
	case 88: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->addBlacklist(__instId);
		return true;
	}
	case 89: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delBlacklist(__instId);
		return true;
	}
	case 90: {
		proxy->requestReferrFriend();
		return true;
	}
	case 91: {
		int32_t __gatherId = 0;
		if (!r->readType(__gatherId)) return false;
		int32_t __times = 0;
		if (!r->readType(__times)) return false;
		proxy->mining(__gatherId, __times);
		return true;
	}
	case 92: {
		int32_t __itemId = 0;
		if (!r->readType(__itemId)) return false;
		int32_t __gemId = 0;
		if (!r->readType(__gemId)) return false;
		proxy->compoundItem(__itemId, __gemId);
		return true;
	}
	case 93: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		int32_t __splitNum = 0;
		if (!r->readType(__splitNum)) return false;
		proxy->bagItemSplit(__instId, __splitNum);
		return true;
	}
	case 94: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->requestChallenge(__name);
		return true;
	}
	case 95: {
		proxy->requestRival();
		return true;
	}
	case 96: {
		proxy->requestMySelfJJCData();
		return true;
	}
	case 97: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->requestCheckMsg(__name);
		return true;
	}
	case 98: {
		proxy->requestMyAllbattleMsg();
		return true;
	}
	case 99: {
		proxy->requestJJCRank();
		return true;
	}
	case 100: {
		proxy->requestLevelRank();
		return true;
	}
	case 101: {
		proxy->requestBabyRank();
		return true;
	}
	case 102: {
		proxy->requestEmpRank();
		return true;
	}
	case 103: {
		proxy->requestPlayerFFRank();
		return true;
	}
	case 104: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->queryOnlinePlayerbyName(__name);
		return true;
	}
	case 105: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->queryPlayerbyName(__name);
		return true;
	}
	case 106: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->queryBaby(__instId);
		return true;
	}
	case 107: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->queryEmployee(__instId);
		return true;
	}
	case 108: {
		uint64_t __guideIdx = 0;
		if (!r->readType(__guideIdx)) return false;
		proxy->guideFinish(__guideIdx);
		return true;
	}
	case 109: {
		int32_t __battleId = 0;
		if (!r->readType(__battleId)) return false;
		proxy->enterBattle(__battleId);
		return true;
	}
	case 110: {
		int32_t __id = 0;
		if (!r->readType(__id)) return false;
		int32_t __num = 0;
		if (!r->readType(__num)) return false;
		proxy->shopBuyItem(__id, __num);
		return true;
	}
	case 111: {
		proxy->getFirstRechargeItem();
		return true;
	}
	case 112: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->requestLevelGift(__level);
		return true;
	}
	case 113: {
		int32_t __title = 0;
		if (!r->readType(__title)) return false;
		proxy->setCurrentTitle(__title);
		return true;
	}
	case 114: {
		proxy->openBuyBox();
		return true;
	}
	case 115: {
		int32_t __achId = 0;
		if (!r->readType(__achId)) return false;
		proxy->requestAchaward(__achId);
		return true;
	}
	case 116: {
		int32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->sign(__index);
		return true;
	}
	case 117: {
		proxy->requestSignupReward7();
		return true;
	}
	case 118: {
		proxy->requestSignupReward14();
		return true;
	}
	case 119: {
		proxy->requestSignupReward28();
		return true;
	}
	case 120: {
		int32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestActivityReward(__index);
		return true;
	}
	case 121: {
		proxy->resetHundredTier();
		return true;
	}
	case 122: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->enterHundredScene(__level);
		return true;
	}
	case 123: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delBaby(__instId);
		return true;
	}
	case 124: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->resetBaby(__instId);
		return true;
	}
	case 125: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->resetBabyProp(__instId);
		return true;
	}
	case 126: {
		int32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->remouldBaby(__instid);
		return true;
	}
	case 127: {
		uint32_t __empId = 0;
		if (!r->readType(__empId)) return false;
		int32_t __skillId = 0;
		if (!r->readType(__skillId)) return false;
		proxy->empSkillLevelUp(__empId, __skillId);
		return true;
	}
	case 128: {
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->setOpenDoubleTimeFlag(__isFlag);
		return true;
	}
	case 129: {
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		proxy->talkedNpc(__npcId);
		return true;
	}
	case 130: {
		uint32_t __id = 0;
		if (!r->readType(__id)) return false;
		proxy->jjcBattleGo(__id);
		return true;
	}
	case 131: {
		proxy->requestMyJJCTeamMsg();
		return true;
	}
	case 132: {
		proxy->startMatching();
		return true;
	}
	case 133: {
		proxy->stopMatching();
		return true;
	}
	case 134: {
		proxy->exitPvpJJC();
		return true;
	}
	case 135: {
		proxy->joinPvpLobby();
		return true;
	}
	case 136: {
		proxy->exitPvpLobby();
		return true;
	}
	case 137: {
		proxy->requestpvprank();
		return true;
	}
	case 138: {
		proxy->joinWarriorchoose();
		return true;
	}
	case 139: {
		proxy->warriorStart();
		return true;
	}
	case 140: {
		proxy->warriorStop();
		return true;
	}
	case 141: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		String __title = "";
		if (!r->readType(__title, 65535)) return false;
		String __content = "";
		if (!r->readType(__content, 65535)) return false;
		proxy->sendMail(__playername, __title, __content);
		return true;
	}
	case 142: {
		int32_t __mailId = 0;
		if (!r->readType(__mailId)) return false;
		proxy->readMail(__mailId);
		return true;
	}
	case 143: {
		int32_t __mailId = 0;
		if (!r->readType(__mailId)) return false;
		proxy->delMail(__mailId);
		return true;
	}
	case 144: {
		int32_t __mailId = 0;
		if (!r->readType(__mailId)) return false;
		proxy->getMailItem(__mailId);
		return true;
	}
	case 145: {
		proxy->requestState();
		return true;
	}
	case 146: {
		String __guildName = "";
		if (!r->readType(__guildName, 65535)) return false;
		proxy->createGuild(__guildName);
		return true;
	}
	case 147: {
		uint32_t __guildId = 0;
		if (!r->readType(__guildId)) return false;
		proxy->delGuild(__guildId);
		return true;
	}
	case 148: {
		uint32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		proxy->requestJoinGuild(__guid);
		return true;
	}
	case 149: {
		proxy->leaveGuild();
		return true;
	}
	case 150: {
		int32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		proxy->kickOut(__guid);
		return true;
	}
	case 151: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->acceptRequestGuild(__playerId);
		return true;
	}
	case 152: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->refuseRequestGuild(__playerId);
		return true;
	}
	case 153: {
		int32_t __targetId = 0;
		if (!r->readType(__targetId)) return false;
		uint16_t __job = (GuildJob)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 7) return false; __job = (uint16_t)__e; }
		proxy->changeMemberPosition(__targetId, __job);
		return true;
	}
	case 154: {
		int32_t __targetId = 0;
		if (!r->readType(__targetId)) return false;
		proxy->transferPremier(__targetId);
		return true;
	}
	case 155: {
		String __notice = "";
		if (!r->readType(__notice, 65535)) return false;
		proxy->changeGuildNotice(__notice);
		return true;
	}
	case 156: {
		int16_t __page = 0;
		if (!r->readType(__page)) return false;
		proxy->queryGuildList(__page);
		return true;
	}
	case 157: {
		String __playerName = "";
		if (!r->readType(__playerName, 65535)) return false;
		proxy->inviteJoinGuild(__playerName);
		return true;
	}
	case 158: {
		String __sendName = "";
		if (!r->readType(__sendName, 65535)) return false;
		proxy->respondInviteJoinGuild(__sendName);
		return true;
	}
	case 159: {
		int32_t __tableId = 0;
		if (!r->readType(__tableId)) return false;
		int32_t __times = 0;
		if (!r->readType(__times)) return false;
		proxy->buyGuildItem(__tableId, __times);
		return true;
	}
	case 160: {
		proxy->entryGuildBattle();
		return true;
	}
	case 161: {
		proxy->transforGuildBattleScene();
		return true;
	}
	case 162: {
		int32_t __money = 0;
		if (!r->readType(__money)) return false;
		proxy->addGuildMoney(__money);
		return true;
	}
	case 163: {
		uint16_t __gbt = (GuildBuildingType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 8) return false; __gbt = (uint16_t)__e; }
		proxy->updateGuildBuiling(__gbt);
		return true;
	}
	case 164: {
		proxy->refreshGuildShop();
		return true;
	}
	case 165: {
		int32_t __skId = 0;
		if (!r->readType(__skId)) return false;
		proxy->levelupGuildSkill(__skId);
		return true;
	}
	case 166: {
		int32_t __num = 0;
		if (!r->readType(__num)) return false;
		proxy->presentGuildItem(__num);
		return true;
	}
	case 167: {
		int32_t __monsterId = 0;
		if (!r->readType(__monsterId)) return false;
		bool __isSuper = false;
		if (!r->readType(__isSuper)) return false;
		proxy->progenitusAddExp(__monsterId, __isSuper);
		return true;
	}
	case 168: {
		int32_t __mId = 0;
		if (!r->readType(__mId)) return false;
		int32_t __pos = 0;
		if (!r->readType(__pos)) return false;
		proxy->setProgenitusPosition(__mId, __pos);
		return true;
	}
	case 169: {
		proxy->guildsign();
		return true;
	}
	case 170: {
		Ref<COM_SearchContext> __context = memnew(COM_SearchContext);
		if (!__context->deserialize(r)) return false;
		proxy->fetchSelling(__context);
		return true;
	}
	case 171: {
		Ref<COM_SearchContext> __context = memnew(COM_SearchContext);
		if (!__context->deserialize(r)) return false;
		proxy->fetchSelling2(__context);
		return true;
	}
	case 172: {
		int32_t __iteminstid = 0;
		if (!r->readType(__iteminstid)) return false;
		int32_t __babyinstid = 0;
		if (!r->readType(__babyinstid)) return false;
		int32_t __price = 0;
		if (!r->readType(__price)) return false;
		proxy->selling(__iteminstid, __babyinstid, __price);
		return true;
	}
	case 173: {
		int32_t __sellid = 0;
		if (!r->readType(__sellid)) return false;
		proxy->unselling(__sellid);
		return true;
	}
	case 174: {
		int32_t __sellid = 0;
		if (!r->readType(__sellid)) return false;
		proxy->buy(__sellid);
		return true;
	}
	case 175: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		uint16_t __type = (FixType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 4) return false; __type = (uint16_t)__e; }
		proxy->fixItem(__instId, __type);
		return true;
	}
	case 176: {
		TypedArray<uint32_t> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__items[i] = __tmp;
			}
		}
		uint16_t __type = (FixType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 4) return false; __type = (uint16_t)__e; }
		proxy->fixAllItem(__items, __type);
		return true;
	}
	case 177: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		int32_t __num = 0;
		if (!r->readType(__num)) return false;
		proxy->makeDebirsItem(__instId, __num);
		return true;
	}
	case 178: {
		TypedArray<uint32_t> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__items[i] = __tmp;
			}
		}
		proxy->levelUpMagicItem(__items);
		return true;
	}
	case 179: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->tupoMagicItem(__level);
		return true;
	}
	case 180: {
		uint16_t __job = (JobType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 12) return false; __job = (uint16_t)__e; }
		proxy->changeMagicJob(__job);
		return true;
	}
	case 181: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->requestPk(__playerId);
		return true;
	}
	case 182: {
		uint16_t __type = (UIBehaviorType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 22) return false; __type = (uint16_t)__e; }
		proxy->uiBehavior(__type);
		return true;
	}
	case 183: {
		proxy->openZhuanpan();
		return true;
	}
	case 184: {
		uint32_t __counter = 0;
		if (!r->readType(__counter)) return false;
		proxy->zhuanpanGo(__counter);
		return true;
	}
	case 185: {
		String __code = "";
		if (!r->readType(__code, 65535)) return false;
		proxy->redemptionSpree(__code);
		return true;
	}
	case 186: {
		TypedArray<uint16_t> __sfType;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__sfType.resize(__len);
			for(int i=0; i<__len; ++i) {
				{ uint16_t __e; if(!r->readType(__e) || __e >= 6) return false; __sfType[i] = (uint16_t)__e; }
			}
		}
		proxy->sceneFilter(__sfType);
		return true;
	}
	case 187: {
		uint32_t __questionId = 0;
		if (!r->readType(__questionId)) return false;
		uint8_t __answer = 0;
		if (!r->readType(__answer)) return false;
		proxy->sendExamAnswer(__questionId, __answer);
		return true;
	}
	case 188: {
		Ref<COM_Wishing> __wish = memnew(COM_Wishing);
		if (!__wish->deserialize(r)) return false;
		proxy->sendwishing(__wish);
		return true;
	}
	case 189: {
		proxy->requestWish();
		return true;
	}
	case 190: {
		proxy->leaderCloseDialog();
		return true;
	}
	case 191: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestOnlineReward(__index);
		return true;
	}
	case 192: {
		uint32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->requestFundReward(__level);
		return true;
	}
	case 193: {
		uint16_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->openCard(__index);
		return true;
	}
	case 194: {
		proxy->resetCard();
		return true;
	}
	case 195: {
		proxy->hotRoleBuy();
		return true;
	}
	case 196: {
		uint32_t __qid = 0;
		if (!r->readType(__qid)) return false;
		proxy->requestSevenReward(__qid);
		return true;
	}
	case 197: {
		proxy->vipreward();
		return true;
	}
	case 198: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestChargeTotalSingleReward(__index);
		return true;
	}
	case 199: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestChargeTotalReward(__index);
		return true;
	}
	case 200: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestChargeEverySingleReward(__index);
		return true;
	}
	case 201: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestChargeEveryReward(__index);
		return true;
	}
	case 202: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestLoginTotal(__index);
		return true;
	}
	case 203: {
		int32_t __itemId = 0;
		if (!r->readType(__itemId)) return false;
		int32_t __itemStack = 0;
		if (!r->readType(__itemStack)) return false;
		proxy->buyDiscountStoreSingle(__itemId, __itemStack);
		return true;
	}
	case 204: {
		int32_t __itemId = 0;
		if (!r->readType(__itemId)) return false;
		int32_t __itemStack = 0;
		if (!r->readType(__itemStack)) return false;
		proxy->buyDiscountStore(__itemId, __itemStack);
		return true;
	}
	case 205: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestEmployeeActivityReward(__index);
		return true;
	}
	case 206: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestmyselfrechargeleReward(__index);
		return true;
	}
	case 207: {
		proxy->requestEverydayIntegral();
		return true;
	}
	case 208: {
		uint32_t __id = 0;
		if (!r->readType(__id)) return false;
		uint32_t __num = 0;
		if (!r->readType(__num)) return false;
		proxy->buyIntegralItem(__id, __num);
		return true;
	}
	case 209: {
		proxy->familyLoseLeader();
		return true;
	}
	case 210: {
		String __phoneNumber = "";
		if (!r->readType(__phoneNumber, 65535)) return false;
		String __code = "";
		if (!r->readType(__code, 65535)) return false;
		proxy->verificationSMS(__phoneNumber, __code);
		return true;
	}
	case 211: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		bool __isLock = false;
		if (!r->readType(__isLock)) return false;
		proxy->lockItem(__instId, __isLock);
		return true;
	}
	case 212: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		bool __isLock = false;
		if (!r->readType(__isLock)) return false;
		proxy->lockBaby(__instId, __isLock);
		return true;
	}
	case 213: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->showBaby(__instId);
		return true;
	}
	case 214: {
		int32_t __itemInstId = 0;
		if (!r->readType(__itemInstId)) return false;
		proxy->wearFuwen(__itemInstId);
		return true;
	}
	case 215: {
		int32_t __slotId = 0;
		if (!r->readType(__slotId)) return false;
		proxy->takeoffFuwen(__slotId);
		return true;
	}
	case 216: {
		int32_t __itemInstId = 0;
		if (!r->readType(__itemInstId)) return false;
		proxy->compFuwen(__itemInstId);
		return true;
	}
	case 217: {
		proxy->requestEmployeeQuest();
		return true;
	}
	case 218: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		TypedArray<int32_t> __employees;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__employees.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__employees[i] = __tmp;
			}
		}
		proxy->acceptEmployeeQuest(__questId, __employees);
		return true;
	}
	case 219: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->submitEmployeeQuest(__questId);
		return true;
	}
	case 220: {
		proxy->crystalUpLevel();
		return true;
	}
	case 221: {
		TypedArray<int32_t> __locklist;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__locklist.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__locklist[i] = __tmp;
			}
		}
		proxy->resetCrystalProp(__locklist);
		return true;
	}
	case 222: {
		proxy->magicItemOneKeyLevel();
		return true;
	}
	case 223: {
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->submitQuest2(__npcId, __questId, __instId);
		return true;
	}
	}
	return false;
}

void Server2Client_Stub::pong() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::errorno(uint16_t e) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)e);
	methodEnd();
}

void Server2Client_Stub::teamerrorno(String name, uint16_t e) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(name);
	__writer->writeType((uint16_t)e);
	methodEnd();
}

void Server2Client_Stub::reconnection(Ref<COM_ReconnectInfo> recInfo) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	if (recInfo.is_null()) recInfo = memnew(COM_ReconnectInfo);
	recInfo->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::sessionfailed() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::loginok(String sessionkey, TypedArray<COM_SimpleInformation> players) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(sessionkey);
	__writer->writeDynSize(players.size());
	for(int i=0; i<players.size(); ++i) {
		Ref<COM_SimpleInformation> __elem = players[i];
		if (__elem.is_null()) __elem = memnew(COM_SimpleInformation);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::logoutOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::createPlayerOk(Ref<COM_SimpleInformation> player) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	if (player.is_null()) player = memnew(COM_SimpleInformation);
	player->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::deletePlayerOk(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Server2Client_Stub::enterGameOk(Ref<COM_PlayerInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_PlayerInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::initBabies(TypedArray<COM_BabyInst> insts) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 10;
	__writer->writeType(__pid);
	__writer->writeDynSize(insts.size());
	for(int i=0; i<insts.size(); ++i) {
		Ref<COM_BabyInst> __elem = insts[i];
		if (__elem.is_null()) __elem = memnew(COM_BabyInst);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::initEmployees(TypedArray<COM_EmployeeInst> insts, bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 11;
	__writer->writeType(__pid);
	__writer->writeDynSize(insts.size());
	for(int i=0; i<insts.size(); ++i) {
		Ref<COM_EmployeeInst> __elem = insts[i];
		if (__elem.is_null()) __elem = memnew(COM_EmployeeInst);
		__elem->serialize(__writer);
	}
	__writer->writeType(isFlag);
	methodEnd();
}

void Server2Client_Stub::initEmpBattleGroup(Ref<COM_BattleEmp> bep) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 12;
	__writer->writeType(__pid);
	if (bep.is_null()) bep = memnew(COM_BattleEmp);
	bep->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::initNpc(TypedArray<int32_t> npcList) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 13;
	__writer->writeType(__pid);
	__writer->writeDynSize(npcList.size());
	for(int i=0; i<npcList.size(); ++i) {
		int32_t __tmp = npcList[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::initAchievement(TypedArray<COM_Achievement> actlist) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 14;
	__writer->writeType(__pid);
	__writer->writeDynSize(actlist.size());
	for(int i=0; i<actlist.size(); ++i) {
		Ref<COM_Achievement> __elem = actlist[i];
		if (__elem.is_null()) __elem = memnew(COM_Achievement);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::initGather(uint32_t allnum, TypedArray<COM_Gather> gathers) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 15;
	__writer->writeType(__pid);
	__writer->writeType(allnum);
	__writer->writeDynSize(gathers.size());
	for(int i=0; i<gathers.size(); ++i) {
		Ref<COM_Gather> __elem = gathers[i];
		if (__elem.is_null()) __elem = memnew(COM_Gather);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::initcompound(TypedArray<uint32_t> compounds) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 16;
	__writer->writeType(__pid);
	__writer->writeDynSize(compounds.size());
	for(int i=0; i<compounds.size(); ++i) {
		uint32_t __tmp = compounds[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::addBaby(Ref<COM_BabyInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 17;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::refreshBaby(Ref<COM_BabyInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 18;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delBabyOK(uint32_t babyInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 19;
	__writer->writeType(__pid);
	__writer->writeType(babyInstId);
	methodEnd();
}

void Server2Client_Stub::changeBabyNameOK(uint32_t babyId, String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 20;
	__writer->writeType(__pid);
	__writer->writeType(babyId);
	__writer->writeType(name);
	methodEnd();
}

void Server2Client_Stub::remouldBabyOK(uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 21;
	__writer->writeType(__pid);
	__writer->writeType(instid);
	methodEnd();
}

void Server2Client_Stub::intensifyBabyOK(uint32_t babyid, uint32_t intensifyLevel) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 22;
	__writer->writeType(__pid);
	__writer->writeType(babyid);
	__writer->writeType(intensifyLevel);
	methodEnd();
}

void Server2Client_Stub::learnSkillOk(Ref<COM_Skill> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 23;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_Skill);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::forgetSkillOk(uint32_t skid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 24;
	__writer->writeType(__pid);
	__writer->writeType(skid);
	methodEnd();
}

void Server2Client_Stub::addSkillExp(uint32_t skid, uint32_t uExp, uint16_t flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 25;
	__writer->writeType(__pid);
	__writer->writeType(skid);
	__writer->writeType(uExp);
	__writer->writeType((uint16_t)flag);
	methodEnd();
}

void Server2Client_Stub::babyLearnSkillOK(uint32_t instId, uint32_t newSkId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 26;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	__writer->writeType(newSkId);
	methodEnd();
}

void Server2Client_Stub::skillLevelUp(uint32_t instId, Ref<COM_Skill> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 27;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	if (inst.is_null()) inst = memnew(COM_Skill);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::joinScene(Ref<COM_SceneInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 28;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_SceneInfo);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::joinCopySceneOK(int32_t secneid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 29;
	__writer->writeType(__pid);
	__writer->writeType(secneid);
	methodEnd();
}

void Server2Client_Stub::initCopyNums() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 30;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::addToScene(Ref<COM_ScenePlayerInformation> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 31;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_ScenePlayerInformation);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delFormScene(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 32;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Server2Client_Stub::move2(int32_t instId, Ref<COM_FPosition> pos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 33;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	if (pos.is_null()) pos = memnew(COM_FPosition);
	pos->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::cantMove() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 34;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::querySimplePlayerInstOk(Ref<COM_SimplePlayerInst> player) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 35;
	__writer->writeType(__pid);
	if (player.is_null()) player = memnew(COM_SimplePlayerInst);
	player->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::transfor2(int32_t instId, Ref<COM_FPosition> pos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 36;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	if (pos.is_null()) pos = memnew(COM_FPosition);
	pos->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::openScene(int32_t sceneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 37;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	methodEnd();
}

void Server2Client_Stub::autoBattleResult(bool isOk) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 38;
	__writer->writeType(__pid);
	__writer->writeType(isOk);
	methodEnd();
}

void Server2Client_Stub::talked2Npc(int32_t npcId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 39;
	__writer->writeType(__pid);
	__writer->writeType(npcId);
	methodEnd();
}

void Server2Client_Stub::talked2Player(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 40;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Server2Client_Stub::useItemOk(int32_t itemId, int32_t stack) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 41;
	__writer->writeType(__pid);
	__writer->writeType(itemId);
	__writer->writeType(stack);
	methodEnd();
}

void Server2Client_Stub::syncBattleStatus(int32_t playerId, bool inBattle) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 42;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(inBattle);
	methodEnd();
}

void Server2Client_Stub::enterBattleOk(Ref<COM_InitBattle> initBattle) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 43;
	__writer->writeType(__pid);
	if (initBattle.is_null()) initBattle = memnew(COM_InitBattle);
	initBattle->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::exitBattleOk(uint16_t bjt, Ref<COM_BattleOverClearing> init) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 44;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)bjt);
	if (init.is_null()) init = memnew(COM_BattleOverClearing);
	init->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::syncOrderOk(uint32_t uid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 45;
	__writer->writeType(__pid);
	__writer->writeType(uid);
	methodEnd();
}

void Server2Client_Stub::syncOrderOkEX() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 46;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::syncOneTurnAction(Ref<COM_BattleReport> reports) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 47;
	__writer->writeType(__pid);
	if (reports.is_null()) reports = memnew(COM_BattleReport);
	reports->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::syncProperties(uint32_t guid, TypedArray<COM_PropValue> props) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 48;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	__writer->writeDynSize(props.size());
	for(int i=0; i<props.size(); ++i) {
		Ref<COM_PropValue> __elem = props[i];
		if (__elem.is_null()) __elem = memnew(COM_PropValue);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::receiveChat(Ref<COM_ChatInfo> info, Ref<COM_ContactInfo> myinfo) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 49;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_ChatInfo);
	info->serialize(__writer);
	if (myinfo.is_null()) myinfo = memnew(COM_ContactInfo);
	myinfo->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::requestAudioOk(int32_t audioId, TypedArray<uint8_t> content) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 50;
	__writer->writeType(__pid);
	__writer->writeType(audioId);
	__writer->writeDynSize(content.size());
	for(int i=0; i<content.size(); ++i) {
		uint8_t __tmp = content[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::publishItemInstRes(Ref<COM_ShowItemInstInfo> info, uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 51;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_ShowItemInstInfo);
	info->serialize(__writer);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void Server2Client_Stub::queryItemInstRes(Ref<COM_ShowItemInst> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 52;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_ShowItemInst);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::publishBabyInstRes(Ref<COM_ShowbabyInstInfo> info, uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 53;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_ShowbabyInstInfo);
	info->serialize(__writer);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void Server2Client_Stub::queryBabyInstRes(Ref<COM_ShowbabyInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 54;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_ShowbabyInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::setNoTalkTime(float t) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 55;
	__writer->writeType(__pid);
	__writer->writeType(t);
	methodEnd();
}

void Server2Client_Stub::addNpc(TypedArray<int32_t> npcList) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 56;
	__writer->writeType(__pid);
	__writer->writeDynSize(npcList.size());
	for(int i=0; i<npcList.size(); ++i) {
		int32_t __tmp = npcList[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::delNpc(TypedArray<int32_t> npcList) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 57;
	__writer->writeType(__pid);
	__writer->writeDynSize(npcList.size());
	for(int i=0; i<npcList.size(); ++i) {
		int32_t __tmp = npcList[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::setTeamLeader(int32_t playerId, bool isLeader) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 58;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(isLeader);
	methodEnd();
}

void Server2Client_Stub::initBag(TypedArray<COM_Item> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 59;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_Item> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_Item);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::addBagItem(Ref<COM_Item> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 60;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_Item);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delBagItem(uint16_t slot) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 61;
	__writer->writeType(__pid);
	__writer->writeType(slot);
	methodEnd();
}

void Server2Client_Stub::updateBagItem(Ref<COM_Item> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 62;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_Item);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::depositItemOK(Ref<COM_Item> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 63;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_Item);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::getoutItemOK(uint16_t slot) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 64;
	__writer->writeType(__pid);
	__writer->writeType(slot);
	methodEnd();
}

void Server2Client_Stub::depositBabyOK(Ref<COM_BabyInst> baby) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 65;
	__writer->writeType(__pid);
	if (baby.is_null()) baby = memnew(COM_BabyInst);
	baby->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::getoutBabyOK(uint16_t slot) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 66;
	__writer->writeType(__pid);
	__writer->writeType(slot);
	methodEnd();
}

void Server2Client_Stub::sortItemStorageOK(TypedArray<COM_Item> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 67;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_Item> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_Item);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::sortBabyStorageOK(TypedArray<uint32_t> babys) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 68;
	__writer->writeType(__pid);
	__writer->writeDynSize(babys.size());
	for(int i=0; i<babys.size(); ++i) {
		uint32_t __tmp = babys[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::initItemStorage(uint16_t gridNum, TypedArray<COM_Item> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 69;
	__writer->writeType(__pid);
	__writer->writeType(gridNum);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_Item> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_Item);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::initBabyStorage(uint16_t gridNum, TypedArray<COM_BabyInst> babys) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 70;
	__writer->writeType(__pid);
	__writer->writeType(gridNum);
	__writer->writeDynSize(babys.size());
	for(int i=0; i<babys.size(); ++i) {
		Ref<COM_BabyInst> __elem = babys[i];
		if (__elem.is_null()) __elem = memnew(COM_BabyInst);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::openStorageGrid(uint16_t tp, uint16_t gridNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 71;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)tp);
	__writer->writeType(gridNum);
	methodEnd();
}

void Server2Client_Stub::delStorageBabyOK(uint16_t slot) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 72;
	__writer->writeType(__pid);
	__writer->writeType(slot);
	methodEnd();
}

void Server2Client_Stub::initPlayerEquips(TypedArray<COM_Item> equips) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 73;
	__writer->writeType(__pid);
	__writer->writeDynSize(equips.size());
	for(int i=0; i<equips.size(); ++i) {
		Ref<COM_Item> __elem = equips[i];
		if (__elem.is_null()) __elem = memnew(COM_Item);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::wearEquipmentOk(uint32_t target, Ref<COM_Item> equip) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 74;
	__writer->writeType(__pid);
	__writer->writeType(target);
	if (equip.is_null()) equip = memnew(COM_Item);
	equip->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::scenePlayerWearEquipment(uint32_t target, uint32_t itemId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 75;
	__writer->writeType(__pid);
	__writer->writeType(target);
	__writer->writeType(itemId);
	methodEnd();
}

void Server2Client_Stub::delEquipmentOk(uint32_t target, uint32_t itemInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 76;
	__writer->writeType(__pid);
	__writer->writeType(target);
	__writer->writeType(itemInstId);
	methodEnd();
}

void Server2Client_Stub::scenePlayerDoffEquipment(uint32_t target, uint32_t itemId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 77;
	__writer->writeType(__pid);
	__writer->writeType(target);
	__writer->writeType(itemId);
	methodEnd();
}

void Server2Client_Stub::sortBagItemOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 78;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::jointLobbyOk(TypedArray<COM_SimpleTeamInfo> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 79;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_SimpleTeamInfo> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_SimpleTeamInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::exitLobbyOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 80;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::syncDelLobbyTeam(uint32_t teamId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 81;
	__writer->writeType(__pid);
	__writer->writeType(teamId);
	methodEnd();
}

void Server2Client_Stub::syncUpdateLobbyTeam(Ref<COM_SimpleTeamInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 82;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_SimpleTeamInfo);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::syncAddLobbyTeam(Ref<COM_SimpleTeamInfo> team) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 83;
	__writer->writeType(__pid);
	if (team.is_null()) team = memnew(COM_SimpleTeamInfo);
	team->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::createTeamOk(Ref<COM_TeamInfo> team) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 84;
	__writer->writeType(__pid);
	if (team.is_null()) team = memnew(COM_TeamInfo);
	team->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::changeTeamOk(Ref<COM_TeamInfo> team) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 85;
	__writer->writeType(__pid);
	if (team.is_null()) team = memnew(COM_TeamInfo);
	team->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::joinTeamOk(Ref<COM_TeamInfo> team) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 86;
	__writer->writeType(__pid);
	if (team.is_null()) team = memnew(COM_TeamInfo);
	team->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::addTeamMember(Ref<COM_SimplePlayerInst> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 87;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_SimplePlayerInst);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delTeamMember(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 88;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Server2Client_Stub::changeTeamLeaderOk(int32_t uuid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 89;
	__writer->writeType(__pid);
	__writer->writeType(uuid);
	methodEnd();
}

void Server2Client_Stub::exitTeamOk(bool iskick) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 90;
	__writer->writeType(__pid);
	__writer->writeType(iskick);
	methodEnd();
}

void Server2Client_Stub::updateTeam(Ref<COM_TeamInfo> team) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 91;
	__writer->writeType(__pid);
	if (team.is_null()) team = memnew(COM_TeamInfo);
	team->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::joinTeamRoomOK(Ref<COM_TeamInfo> team) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 92;
	__writer->writeType(__pid);
	if (team.is_null()) team = memnew(COM_TeamInfo);
	team->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::inviteJoinTeam(uint32_t teamId, String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 93;
	__writer->writeType(__pid);
	__writer->writeType(teamId);
	__writer->writeType(name);
	methodEnd();
}

void Server2Client_Stub::syncTeamDirtyProp(int32_t guid, TypedArray<COM_PropValue> props) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 94;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	__writer->writeDynSize(props.size());
	for(int i=0; i<props.size(); ++i) {
		Ref<COM_PropValue> __elem = props[i];
		if (__elem.is_null()) __elem = memnew(COM_PropValue);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::leaveTeamOk(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 95;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Server2Client_Stub::backTeamOK(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 96;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Server2Client_Stub::teamCallMemberBack() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 97;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::refuseBackTeamOk(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 98;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void Server2Client_Stub::requestJoinTeamTranspond(String reqName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 99;
	__writer->writeType(__pid);
	__writer->writeType(reqName);
	methodEnd();
}

void Server2Client_Stub::drawLotteryBoxRep(TypedArray<COM_Item> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 100;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_Item> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_Item);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::addEmployee(Ref<COM_EmployeeInst> employee) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 101;
	__writer->writeType(__pid);
	if (employee.is_null()) employee = memnew(COM_EmployeeInst);
	employee->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::battleEmployee(int32_t empId, uint16_t group, bool forbattle) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 102;
	__writer->writeType(__pid);
	__writer->writeType(empId);
	__writer->writeType((uint16_t)group);
	__writer->writeType(forbattle);
	methodEnd();
}

void Server2Client_Stub::changeEmpBattleGroupOK(uint16_t group) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 103;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)group);
	methodEnd();
}

void Server2Client_Stub::evolveOK(int32_t guid, uint16_t qc) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 104;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	__writer->writeType((uint16_t)qc);
	methodEnd();
}

void Server2Client_Stub::upStarOK(int32_t guid, int32_t star, Ref<COM_Skill> sk) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 105;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	__writer->writeType(star);
	if (sk.is_null()) sk = memnew(COM_Skill);
	sk->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delEmployeeOK(TypedArray<uint32_t> instids) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 106;
	__writer->writeType(__pid);
	__writer->writeDynSize(instids.size());
	for(int i=0; i<instids.size(); ++i) {
		uint32_t __tmp = instids[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::sycnEmployeeSoul(int32_t guid, uint32_t soulNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 107;
	__writer->writeType(__pid);
	__writer->writeType(guid);
	__writer->writeType(soulNum);
	methodEnd();
}

void Server2Client_Stub::initQuest(TypedArray<COM_QuestInst> qlist, TypedArray<int32_t> clist) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 108;
	__writer->writeType(__pid);
	__writer->writeDynSize(qlist.size());
	for(int i=0; i<qlist.size(); ++i) {
		Ref<COM_QuestInst> __elem = qlist[i];
		if (__elem.is_null()) __elem = memnew(COM_QuestInst);
		__elem->serialize(__writer);
	}
	__writer->writeDynSize(clist.size());
	for(int i=0; i<clist.size(); ++i) {
		int32_t __tmp = clist[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::acceptQuestOk(Ref<COM_QuestInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 109;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_QuestInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::submitQuestOk(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 110;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void Server2Client_Stub::giveupQuestOk(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 111;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void Server2Client_Stub::updateQuestInst(Ref<COM_QuestInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 112;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_QuestInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::requestContactInfoOk(Ref<COM_ContactInfo> contact) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 113;
	__writer->writeType(__pid);
	if (contact.is_null()) contact = memnew(COM_ContactInfo);
	contact->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::addFriendOK(Ref<COM_ContactInfo> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 114;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_ContactInfo);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delFriendOK(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 115;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Server2Client_Stub::addBlacklistOK(Ref<COM_ContactInfo> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 116;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_ContactInfo);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::delBlacklistOK(uint32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 117;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void Server2Client_Stub::findFriendFail() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 118;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::referrFriendOK(TypedArray<COM_ContactInfo> insts) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 119;
	__writer->writeType(__pid);
	__writer->writeDynSize(insts.size());
	for(int i=0; i<insts.size(); ++i) {
		Ref<COM_ContactInfo> __elem = insts[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::requestFriendListOK(TypedArray<COM_ContactInfo> insts) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 120;
	__writer->writeType(__pid);
	__writer->writeDynSize(insts.size());
	for(int i=0; i<insts.size(); ++i) {
		Ref<COM_ContactInfo> __elem = insts[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::lotteryOk(int32_t lotteryId, TypedArray<COM_DropItem> dropItem) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 121;
	__writer->writeType(__pid);
	__writer->writeType(lotteryId);
	__writer->writeDynSize(dropItem.size());
	for(int i=0; i<dropItem.size(); ++i) {
		Ref<COM_DropItem> __elem = dropItem[i];
		if (__elem.is_null()) __elem = memnew(COM_DropItem);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::openGatherOK(Ref<COM_Gather> gather) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 122;
	__writer->writeType(__pid);
	if (gather.is_null()) gather = memnew(COM_Gather);
	gather->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::miningOk(TypedArray<COM_DropItem> items, Ref<COM_Gather> gather, uint32_t gatherNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 123;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_DropItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_DropItem);
		__elem->serialize(__writer);
	}
	if (gather.is_null()) gather = memnew(COM_Gather);
	gather->serialize(__writer);
	__writer->writeType(gatherNum);
	methodEnd();
}

void Server2Client_Stub::openCompound(uint32_t compoundId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 124;
	__writer->writeType(__pid);
	__writer->writeType(compoundId);
	methodEnd();
}

void Server2Client_Stub::compoundItemOk(Ref<COM_Item> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 125;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_Item);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::openBagGridOk(int32_t num) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 126;
	__writer->writeType(__pid);
	__writer->writeType(num);
	methodEnd();
}

void Server2Client_Stub::requestChallengeOK(bool isOK) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 127;
	__writer->writeType(__pid);
	__writer->writeType(isOK);
	methodEnd();
}

void Server2Client_Stub::requestMySelfJJCDataOK(Ref<COM_EndlessStair> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 128;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_EndlessStair);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::requestRivalOK(TypedArray<COM_EndlessStair> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 129;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_EndlessStair> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_EndlessStair);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::rivalTimeOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 130;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::checkMsgOK(Ref<COM_SimplePlayerInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 131;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_SimplePlayerInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::requestMyAllbattleMsgOK(TypedArray<COM_JJCBattleMsg> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 132;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_JJCBattleMsg> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_JJCBattleMsg);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::myBattleMsgOK(Ref<COM_JJCBattleMsg> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 133;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_JJCBattleMsg);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::requestJJCRankOK(uint32_t myRank, TypedArray<COM_EndlessStair> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 134;
	__writer->writeType(__pid);
	__writer->writeType(myRank);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_EndlessStair> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_EndlessStair);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::requestLevelRankOK(uint32_t myRank, TypedArray<COM_ContactInfo> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 135;
	__writer->writeType(__pid);
	__writer->writeType(myRank);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_ContactInfo> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::requestBabyRankOK(uint32_t myRank, TypedArray<COM_BabyRankData> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 136;
	__writer->writeType(__pid);
	__writer->writeType(myRank);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_BabyRankData> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_BabyRankData);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::requestEmpRankOK(uint32_t myRank, TypedArray<COM_EmployeeRankData> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 137;
	__writer->writeType(__pid);
	__writer->writeType(myRank);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_EmployeeRankData> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_EmployeeRankData);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::requestPlayerFFRankOK(uint32_t myRank, TypedArray<COM_ContactInfo> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 138;
	__writer->writeType(__pid);
	__writer->writeType(myRank);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_ContactInfo> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::queryOnlinePlayerOK(bool isOnline) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 139;
	__writer->writeType(__pid);
	__writer->writeType(isOnline);
	methodEnd();
}

void Server2Client_Stub::queryPlayerOK(Ref<COM_SimplePlayerInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 140;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_SimplePlayerInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::queryBabyOK(Ref<COM_BabyInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 141;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::queryEmployeeOK(Ref<COM_EmployeeInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 142;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_EmployeeInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::initGuide(uint32_t guideMask) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 143;
	__writer->writeType(__pid);
	__writer->writeType(guideMask);
	methodEnd();
}

void Server2Client_Stub::buyShopItemOk(int32_t id) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 144;
	__writer->writeType(__pid);
	__writer->writeType(id);
	methodEnd();
}

void Server2Client_Stub::addPlayerTitle(int32_t title) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 145;
	__writer->writeType(__pid);
	__writer->writeType(title);
	methodEnd();
}

void Server2Client_Stub::delPlayerTitle(int32_t title) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 146;
	__writer->writeType(__pid);
	__writer->writeType(title);
	methodEnd();
}

void Server2Client_Stub::requestOpenBuyBox(float greenTime, float blueTime, int32_t greenFreeNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 147;
	__writer->writeType(__pid);
	__writer->writeType(greenTime);
	__writer->writeType(blueTime);
	__writer->writeType(greenFreeNum);
	methodEnd();
}

void Server2Client_Stub::requestGreenBoxTimeOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 148;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::requestBlueBoxTimeOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 149;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::updateAchievementinfo(Ref<COM_Achievement> achs) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 150;
	__writer->writeType(__pid);
	if (achs.is_null()) achs = memnew(COM_Achievement);
	achs->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::syncOpenSystemFlag(uint64_t flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 151;
	__writer->writeType(__pid);
	__writer->writeType(flag);
	methodEnd();
}

void Server2Client_Stub::requestActivityRewardOK(uint32_t ar) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 152;
	__writer->writeType(__pid);
	__writer->writeType(ar);
	methodEnd();
}

void Server2Client_Stub::syncActivity(Ref<COM_ActivityTable> table) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 153;
	__writer->writeType(__pid);
	if (table.is_null()) table = memnew(COM_ActivityTable);
	table->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateActivityStatus(uint16_t type, bool open) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 154;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(open);
	methodEnd();
}

void Server2Client_Stub::updateActivityCounter(uint16_t type, int32_t counter, int32_t reward) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 155;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(counter);
	__writer->writeType(reward);
	methodEnd();
}

void Server2Client_Stub::syncExam(Ref<COM_Exam> exam) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 156;
	__writer->writeType(__pid);
	if (exam.is_null()) exam = memnew(COM_Exam);
	exam->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::syncExamAnswer(Ref<COM_Answer> answer) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 157;
	__writer->writeType(__pid);
	if (answer.is_null()) answer = memnew(COM_Answer);
	answer->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::petActivityNoNum(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 158;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Server2Client_Stub::syncHundredInfo(Ref<COM_HundredBattle> hb) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 159;
	__writer->writeType(__pid);
	if (hb.is_null()) hb = memnew(COM_HundredBattle);
	hb->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::initSignUp(TypedArray<int32_t> info, int32_t process, bool sign7, bool sign14, bool sign28) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 160;
	__writer->writeType(__pid);
	__writer->writeDynSize(info.size());
	for(int i=0; i<info.size(); ++i) {
		int32_t __tmp = info[i];
		__writer->writeType(__tmp);
	}
	__writer->writeType(process);
	__writer->writeType(sign7);
	__writer->writeType(sign14);
	__writer->writeType(sign28);
	methodEnd();
}

void Server2Client_Stub::signUp(bool flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 161;
	__writer->writeType(__pid);
	__writer->writeType(flag);
	methodEnd();
}

void Server2Client_Stub::requestSignupRewardOk7() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 162;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::requestSignupRewardOk14() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 163;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::requestSignupRewardOk28() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 164;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::sycnDoubleExpTime(bool isFlag, float times) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 165;
	__writer->writeType(__pid);
	__writer->writeType(isFlag);
	__writer->writeType(times);
	methodEnd();
}

void Server2Client_Stub::sycnStates(TypedArray<COM_State> states) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 166;
	__writer->writeType(__pid);
	__writer->writeDynSize(states.size());
	for(int i=0; i<states.size(); ++i) {
		Ref<COM_State> __elem = states[i];
		if (__elem.is_null()) __elem = memnew(COM_State);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::requestpvprankOK(TypedArray<COM_ContactInfo> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 167;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_ContactInfo> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::syncMyJJCTeamMember() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 168;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::startMatchingOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 169;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::stopMatchingOK(float times) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 170;
	__writer->writeType(__pid);
	__writer->writeType(times);
	methodEnd();
}

void Server2Client_Stub::updatePvpJJCinfo(Ref<COM_PlayerVsPlayer> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 171;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_PlayerVsPlayer);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::exitPvpJJCOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 172;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::syncEnemyPvpJJCPlayerInfo(Ref<COM_SimpleInformation> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 173;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_SimpleInformation);
	info->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::syncEnemyPvpJJCTeamInfo(TypedArray<COM_SimpleInformation> infos, uint32_t teamID_) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 174;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_SimpleInformation> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_SimpleInformation);
		__elem->serialize(__writer);
	}
	__writer->writeType(teamID_);
	methodEnd();
}

void Server2Client_Stub::openWarriorchooseUI() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 175;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::warriorStartOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 176;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::warriorStopOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 177;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::syncWarriorEnemyTeamInfo(TypedArray<COM_SimpleInformation> infos, uint32_t teamID_) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 178;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_SimpleInformation> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_SimpleInformation);
		__elem->serialize(__writer);
	}
	__writer->writeType(teamID_);
	methodEnd();
}

void Server2Client_Stub::appendMail(TypedArray<COM_Mail> mails) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 179;
	__writer->writeType(__pid);
	__writer->writeDynSize(mails.size());
	for(int i=0; i<mails.size(); ++i) {
		Ref<COM_Mail> __elem = mails[i];
		if (__elem.is_null()) __elem = memnew(COM_Mail);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::delMail(int32_t mailId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 180;
	__writer->writeType(__pid);
	__writer->writeType(mailId);
	methodEnd();
}

void Server2Client_Stub::updateMailOk(Ref<COM_Mail> mail) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 181;
	__writer->writeType(__pid);
	if (mail.is_null()) mail = memnew(COM_Mail);
	mail->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::boardcastNotice(String content, bool isGm) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 182;
	__writer->writeType(__pid);
	__writer->writeType(content);
	__writer->writeType(isGm);
	methodEnd();
}

void Server2Client_Stub::createGuildOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 183;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::delGuildOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 184;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::leaveGuildOk(String who, bool isKick) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 185;
	__writer->writeType(__pid);
	__writer->writeType(who);
	__writer->writeType(isKick);
	methodEnd();
}

void Server2Client_Stub::initGuildData(Ref<COM_Guild> guild) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 186;
	__writer->writeType(__pid);
	if (guild.is_null()) guild = memnew(COM_Guild);
	guild->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::initGuildMemberList(TypedArray<COM_GuildMember> member) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 187;
	__writer->writeType(__pid);
	__writer->writeDynSize(member.size());
	for(int i=0; i<member.size(); ++i) {
		Ref<COM_GuildMember> __elem = member[i];
		if (__elem.is_null()) __elem = memnew(COM_GuildMember);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::modifyGuildMemberList(Ref<COM_GuildMember> member, uint16_t flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 188;
	__writer->writeType(__pid);
	if (member.is_null()) member = memnew(COM_GuildMember);
	member->serialize(__writer);
	__writer->writeType((uint16_t)flag);
	methodEnd();
}

void Server2Client_Stub::modifyGuildList(Ref<COM_GuildViewerData> data, uint16_t flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 189;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_GuildViewerData);
	data->serialize(__writer);
	__writer->writeType((uint16_t)flag);
	methodEnd();
}

void Server2Client_Stub::queryGuildListResult(int16_t page, int16_t pageNum, TypedArray<COM_GuildViewerData> guildList) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 190;
	__writer->writeType(__pid);
	__writer->writeType(page);
	__writer->writeType(pageNum);
	__writer->writeDynSize(guildList.size());
	for(int i=0; i<guildList.size(); ++i) {
		Ref<COM_GuildViewerData> __elem = guildList[i];
		if (__elem.is_null()) __elem = memnew(COM_GuildViewerData);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::inviteGuild(String sendName, String guildName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 191;
	__writer->writeType(__pid);
	__writer->writeType(sendName);
	__writer->writeType(guildName);
	methodEnd();
}

void Server2Client_Stub::updateGuildShopItems(TypedArray<COM_GuildShopItem> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 192;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_GuildShopItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_GuildShopItem);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::updateGuildBuilding(uint16_t type, Ref<COM_GuildBuilding> building) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 193;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	if (building.is_null()) building = memnew(COM_GuildBuilding);
	building->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateGuildMyMember(Ref<COM_GuildMember> member) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 194;
	__writer->writeType(__pid);
	if (member.is_null()) member = memnew(COM_GuildMember);
	member->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::levelupGuildSkillOk(Ref<COM_Skill> skInst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 195;
	__writer->writeType(__pid);
	if (skInst.is_null()) skInst = memnew(COM_Skill);
	skInst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::presentGuildItemOk(int32_t val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 196;
	__writer->writeType(__pid);
	__writer->writeType(val);
	methodEnd();
}

void Server2Client_Stub::progenitusAddExpOk(Ref<COM_GuildProgen> mInst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 197;
	__writer->writeType(__pid);
	if (mInst.is_null()) mInst = memnew(COM_GuildProgen);
	mInst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::setProgenitusPositionOk(TypedArray<int32_t> positions) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 198;
	__writer->writeType(__pid);
	__writer->writeDynSize(positions.size());
	for(int i=0; i<positions.size(); ++i) {
		int32_t __tmp = positions[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::updateGuildFundz(int32_t val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 199;
	__writer->writeType(__pid);
	__writer->writeType(val);
	methodEnd();
}

void Server2Client_Stub::updateGuildMemberContribution(int32_t val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 200;
	__writer->writeType(__pid);
	__writer->writeType(val);
	methodEnd();
}

void Server2Client_Stub::openGuildBattle(String otherName, int32_t playerNum, int32_t level, bool isLeft, int32_t lstime) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 201;
	__writer->writeType(__pid);
	__writer->writeType(otherName);
	__writer->writeType(playerNum);
	__writer->writeType(level);
	__writer->writeType(isLeft);
	__writer->writeType(lstime);
	methodEnd();
}

void Server2Client_Stub::startGuildBattle(String otherName, int32_t otherCon, int32_t selfCon) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 202;
	__writer->writeType(__pid);
	__writer->writeType(otherName);
	__writer->writeType(otherCon);
	__writer->writeType(selfCon);
	methodEnd();
}

void Server2Client_Stub::closeGuildBattle(bool isWinner) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 203;
	__writer->writeType(__pid);
	__writer->writeType(isWinner);
	methodEnd();
}

void Server2Client_Stub::syncGuildBattleWinCount(int32_t myWin, int32_t otherWin) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 204;
	__writer->writeType(__pid);
	__writer->writeType(myWin);
	__writer->writeType(otherWin);
	methodEnd();
}

void Server2Client_Stub::initMySelling(TypedArray<COM_SellItem> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 205;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SellItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SellItem);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::initMySelled(TypedArray<COM_SelledItem> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 206;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SelledItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SelledItem);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::fetchSellingOk(TypedArray<COM_SellItem> items, int32_t total) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 207;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SellItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SellItem);
		__elem->serialize(__writer);
	}
	__writer->writeType(total);
	methodEnd();
}

void Server2Client_Stub::fetchSellingOk2(TypedArray<COM_SellItem> items, int32_t total) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 208;
	__writer->writeType(__pid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SellItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SellItem);
		__elem->serialize(__writer);
	}
	__writer->writeType(total);
	methodEnd();
}

void Server2Client_Stub::sellingOk(Ref<COM_SellItem> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 209;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_SellItem);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::selledOk(Ref<COM_SelledItem> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 210;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_SelledItem);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::unsellingOk(int32_t sellid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 211;
	__writer->writeType(__pid);
	__writer->writeType(sellid);
	methodEnd();
}

void Server2Client_Stub::redemptionSpreeOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 212;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::insertState(Ref<COM_State> st) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 213;
	__writer->writeType(__pid);
	if (st.is_null()) st = memnew(COM_State);
	st->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updattState(Ref<COM_State> st) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 214;
	__writer->writeType(__pid);
	if (st.is_null()) st = memnew(COM_State);
	st->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::removeState(uint32_t stid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 215;
	__writer->writeType(__pid);
	__writer->writeType(stid);
	methodEnd();
}

void Server2Client_Stub::requestFixItemOk(Ref<COM_Item> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 216;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_Item);
	item->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::makeDebirsItemOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 217;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::updateMagicItem(int32_t level, int32_t exp) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 218;
	__writer->writeType(__pid);
	__writer->writeType(level);
	__writer->writeType(exp);
	methodEnd();
}

void Server2Client_Stub::changeMagicJobOk(uint16_t job) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 219;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)job);
	methodEnd();
}

void Server2Client_Stub::magicItemTupoOk(int32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 220;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Server2Client_Stub::zhuanpanOK(TypedArray<uint32_t> pond) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 221;
	__writer->writeType(__pid);
	__writer->writeDynSize(pond.size());
	for(int i=0; i<pond.size(); ++i) {
		uint32_t __tmp = pond[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void Server2Client_Stub::updateZhuanpanNotice(Ref<COM_Zhuanpan> zhuanp) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 222;
	__writer->writeType(__pid);
	if (zhuanp.is_null()) zhuanp = memnew(COM_Zhuanpan);
	zhuanp->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::sycnZhuanpanData(Ref<COM_ZhuanpanData> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 223;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ZhuanpanData);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::copynonum(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 224;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

void Server2Client_Stub::sceneFilterOk(TypedArray<uint16_t> sfType) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 225;
	__writer->writeType(__pid);
	__writer->writeDynSize(sfType.size());
	for(int i=0; i<sfType.size(); ++i) {
		__writer->writeType((uint16_t)sfType[i]);
	}
	methodEnd();
}

void Server2Client_Stub::wishingOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 226;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::shareWishOK(Ref<COM_Wish> wish) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 227;
	__writer->writeType(__pid);
	if (wish.is_null()) wish = memnew(COM_Wish);
	wish->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::leaderCloseDialogOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 228;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::startOnlineTime() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 229;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::requestOnlineTimeRewardOK(uint32_t index) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 230;
	__writer->writeType(__pid);
	__writer->writeType(index);
	methodEnd();
}

void Server2Client_Stub::sycnVipflag(bool flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 231;
	__writer->writeType(__pid);
	__writer->writeType(flag);
	methodEnd();
}

void Server2Client_Stub::buyFundOK(bool flag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 232;
	__writer->writeType(__pid);
	__writer->writeType(flag);
	methodEnd();
}

void Server2Client_Stub::requestFundRewardOK(uint32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 233;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Server2Client_Stub::firstRechargeOK(bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 234;
	__writer->writeType(__pid);
	__writer->writeType(isFlag);
	methodEnd();
}

void Server2Client_Stub::firstRechargeGiftOK(bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 235;
	__writer->writeType(__pid);
	__writer->writeType(isFlag);
	methodEnd();
}

void Server2Client_Stub::agencyActivity(uint16_t type, bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 236;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(isFlag);
	methodEnd();
}

void Server2Client_Stub::updateFestival(Ref<COM_ADLoginTotal> festival) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 237;
	__writer->writeType(__pid);
	if (festival.is_null()) festival = memnew(COM_ADLoginTotal);
	festival->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateSelfRecharge(Ref<COM_ADChargeTotal> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 238;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADChargeTotal);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateSysRecharge(Ref<COM_ADChargeTotal> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 239;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADChargeTotal);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateSelfDiscountStore(Ref<COM_ADDiscountStore> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 240;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADDiscountStore);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateSysDiscountStore(Ref<COM_ADDiscountStore> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 241;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADDiscountStore);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateSelfOnceRecharge(Ref<COM_ADChargeEvery> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 242;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADChargeEvery);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateSysOnceRecharge(Ref<COM_ADChargeEvery> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 243;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADChargeEvery);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::openCardOK(Ref<COM_ADCardsContent> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 244;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADCardsContent);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::resetCardOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 245;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::sycnHotRole(Ref<COM_ADHotRole> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 246;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADHotRole);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::hotRoleBuyOk(uint16_t buyNum) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 247;
	__writer->writeType(__pid);
	__writer->writeType(buyNum);
	methodEnd();
}

void Server2Client_Stub::updateSevenday(Ref<COM_Sevenday> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 248;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_Sevenday);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateEmployeeActivity(Ref<COM_ADEmployeeTotal> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 249;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADEmployeeTotal);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateMinGiftActivity(Ref<COM_ADGiftBag> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 250;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADGiftBag);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateIntegralShop(Ref<COM_IntegralData> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 251;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_IntegralData);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::updateShowBaby(uint32_t playerId, uint32_t showBabyTableId, String showBabyName) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 252;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(showBabyTableId);
	__writer->writeType(showBabyName);
	methodEnd();
}

void Server2Client_Stub::updateMySelfRecharge(Ref<COM_ADChargeTotal> val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 253;
	__writer->writeType(__pid);
	if (val.is_null()) val = memnew(COM_ADChargeTotal);
	val->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::verificationSMSOk(String phoneNumber) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 254;
	__writer->writeType(__pid);
	__writer->writeType(phoneNumber);
	methodEnd();
}

void Server2Client_Stub::requestLevelGiftOK(int32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 255;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void Server2Client_Stub::sycnConvertExp(int32_t val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 256;
	__writer->writeType(__pid);
	__writer->writeType(val);
	methodEnd();
}

void Server2Client_Stub::wearFuwenOk(Ref<COM_Item> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 257;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_Item);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::takeoffFuwenOk(int32_t slot) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 258;
	__writer->writeType(__pid);
	__writer->writeType(slot);
	methodEnd();
}

void Server2Client_Stub::compFuwenOk() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 259;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::requestEmployeeQuestOk(TypedArray<COM_EmployeeQuestInst> questList) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 260;
	__writer->writeType(__pid);
	__writer->writeDynSize(questList.size());
	for(int i=0; i<questList.size(); ++i) {
		Ref<COM_EmployeeQuestInst> __elem = questList[i];
		if (__elem.is_null()) __elem = memnew(COM_EmployeeQuestInst);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::acceptEmployeeQuestOk(Ref<COM_EmployeeQuestInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 261;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_EmployeeQuestInst);
	inst->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::submitEmployeeQuestOk(int32_t questId, bool isSuccess) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 262;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	__writer->writeType(isSuccess);
	methodEnd();
}

void Server2Client_Stub::sycnCrystal(Ref<COM_CrystalData> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 263;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_CrystalData);
	data->serialize(__writer);
	methodEnd();
}

void Server2Client_Stub::crystalUpLeveResult(bool isOK) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 264;
	__writer->writeType(__pid);
	__writer->writeType(isOK);
	methodEnd();
}

void Server2Client_Stub::resetCrystalPropOK() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 265;
	__writer->writeType(__pid);
	methodEnd();
}

void Server2Client_Stub::sycnCourseGift(TypedArray<COM_CourseGift> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 266;
	__writer->writeType(__pid);
	__writer->writeDynSize(data.size());
	for(int i=0; i<data.size(); ++i) {
		Ref<COM_CourseGift> __elem = data[i];
		if (__elem.is_null()) __elem = memnew(COM_CourseGift);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void Server2Client_Stub::orderOk(String orderId, int32_t shopId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 267;
	__writer->writeType(__pid);
	__writer->writeType(orderId);
	__writer->writeType(shopId);
	methodEnd();
}

void Server2Client_Stub::updateRandSubmitQuestCount(int32_t submitCount) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 268;
	__writer->writeType(__pid);
	__writer->writeType(submitCount);
	methodEnd();
}

void Server2Client_Stub::updateTeamMember(int32_t playerId, bool isMember) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 269;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(isMember);
	methodEnd();
}

bool Server2Client_Dispatcher::dispatch(ProtocolReader* r, Server2Client_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		proxy->pong();
		return true;
	}
	case 1: {
		uint16_t __e = (ErrorNo)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 158) return false; __e = (uint16_t)__e; }
		proxy->errorno(__e);
		return true;
	}
	case 2: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		uint16_t __e = (ErrorNo)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 158) return false; __e = (uint16_t)__e; }
		proxy->teamerrorno(__name, __e);
		return true;
	}
	case 3: {
		Ref<COM_ReconnectInfo> __recInfo = memnew(COM_ReconnectInfo);
		if (!__recInfo->deserialize(r)) return false;
		proxy->reconnection(__recInfo);
		return true;
	}
	case 4: {
		proxy->sessionfailed();
		return true;
	}
	case 5: {
		String __sessionkey = "";
		if (!r->readType(__sessionkey, 65535)) return false;
		TypedArray<COM_SimpleInformation> __players;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__players.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimpleInformation> __elem = memnew(COM_SimpleInformation);
				if(!__elem->deserialize(r)) return false;
				__players[i] = __elem;
			}
		}
		proxy->loginok(__sessionkey, __players);
		return true;
	}
	case 6: {
		proxy->logoutOk();
		return true;
	}
	case 7: {
		Ref<COM_SimpleInformation> __player = memnew(COM_SimpleInformation);
		if (!__player->deserialize(r)) return false;
		proxy->createPlayerOk(__player);
		return true;
	}
	case 8: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->deletePlayerOk(__name);
		return true;
	}
	case 9: {
		Ref<COM_PlayerInst> __inst = memnew(COM_PlayerInst);
		if (!__inst->deserialize(r)) return false;
		proxy->enterGameOk(__inst);
		return true;
	}
	case 10: {
		TypedArray<COM_BabyInst> __insts;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__insts.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyInst> __elem = memnew(COM_BabyInst);
				if(!__elem->deserialize(r)) return false;
				__insts[i] = __elem;
			}
		}
		proxy->initBabies(__insts);
		return true;
	}
	case 11: {
		TypedArray<COM_EmployeeInst> __insts;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__insts.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EmployeeInst> __elem = memnew(COM_EmployeeInst);
				if(!__elem->deserialize(r)) return false;
				__insts[i] = __elem;
			}
		}
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->initEmployees(__insts, __isFlag);
		return true;
	}
	case 12: {
		Ref<COM_BattleEmp> __bep = memnew(COM_BattleEmp);
		if (!__bep->deserialize(r)) return false;
		proxy->initEmpBattleGroup(__bep);
		return true;
	}
	case 13: {
		TypedArray<int32_t> __npcList;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__npcList.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__npcList[i] = __tmp;
			}
		}
		proxy->initNpc(__npcList);
		return true;
	}
	case 14: {
		TypedArray<COM_Achievement> __actlist;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__actlist.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Achievement> __elem = memnew(COM_Achievement);
				if(!__elem->deserialize(r)) return false;
				__actlist[i] = __elem;
			}
		}
		proxy->initAchievement(__actlist);
		return true;
	}
	case 15: {
		uint32_t __allnum = 0;
		if (!r->readType(__allnum)) return false;
		TypedArray<COM_Gather> __gathers;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__gathers.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Gather> __elem = memnew(COM_Gather);
				if(!__elem->deserialize(r)) return false;
				__gathers[i] = __elem;
			}
		}
		proxy->initGather(__allnum, __gathers);
		return true;
	}
	case 16: {
		TypedArray<uint32_t> __compounds;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__compounds.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__compounds[i] = __tmp;
			}
		}
		proxy->initcompound(__compounds);
		return true;
	}
	case 17: {
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		proxy->addBaby(__inst);
		return true;
	}
	case 18: {
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		proxy->refreshBaby(__inst);
		return true;
	}
	case 19: {
		uint32_t __babyInstId = 0;
		if (!r->readType(__babyInstId)) return false;
		proxy->delBabyOK(__babyInstId);
		return true;
	}
	case 20: {
		uint32_t __babyId = 0;
		if (!r->readType(__babyId)) return false;
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->changeBabyNameOK(__babyId, __name);
		return true;
	}
	case 21: {
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->remouldBabyOK(__instid);
		return true;
	}
	case 22: {
		uint32_t __babyid = 0;
		if (!r->readType(__babyid)) return false;
		uint32_t __intensifyLevel = 0;
		if (!r->readType(__intensifyLevel)) return false;
		proxy->intensifyBabyOK(__babyid, __intensifyLevel);
		return true;
	}
	case 23: {
		Ref<COM_Skill> __inst = memnew(COM_Skill);
		if (!__inst->deserialize(r)) return false;
		proxy->learnSkillOk(__inst);
		return true;
	}
	case 24: {
		uint32_t __skid = 0;
		if (!r->readType(__skid)) return false;
		proxy->forgetSkillOk(__skid);
		return true;
	}
	case 25: {
		uint32_t __skid = 0;
		if (!r->readType(__skid)) return false;
		uint32_t __uExp = 0;
		if (!r->readType(__uExp)) return false;
		uint16_t __flag = (ItemUseFlag)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 4) return false; __flag = (uint16_t)__e; }
		proxy->addSkillExp(__skid, __uExp, __flag);
		return true;
	}
	case 26: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		uint32_t __newSkId = 0;
		if (!r->readType(__newSkId)) return false;
		proxy->babyLearnSkillOK(__instId, __newSkId);
		return true;
	}
	case 27: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		Ref<COM_Skill> __inst = memnew(COM_Skill);
		if (!__inst->deserialize(r)) return false;
		proxy->skillLevelUp(__instId, __inst);
		return true;
	}
	case 28: {
		Ref<COM_SceneInfo> __info = memnew(COM_SceneInfo);
		if (!__info->deserialize(r)) return false;
		proxy->joinScene(__info);
		return true;
	}
	case 29: {
		int32_t __secneid = 0;
		if (!r->readType(__secneid)) return false;
		proxy->joinCopySceneOK(__secneid);
		return true;
	}
	case 30: {
		proxy->initCopyNums();
		return true;
	}
	case 31: {
		Ref<COM_ScenePlayerInformation> __inst = memnew(COM_ScenePlayerInformation);
		if (!__inst->deserialize(r)) return false;
		proxy->addToScene(__inst);
		return true;
	}
	case 32: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delFormScene(__instId);
		return true;
	}
	case 33: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		Ref<COM_FPosition> __pos = memnew(COM_FPosition);
		if (!__pos->deserialize(r)) return false;
		proxy->move2(__instId, __pos);
		return true;
	}
	case 34: {
		proxy->cantMove();
		return true;
	}
	case 35: {
		Ref<COM_SimplePlayerInst> __player = memnew(COM_SimplePlayerInst);
		if (!__player->deserialize(r)) return false;
		proxy->querySimplePlayerInstOk(__player);
		return true;
	}
	case 36: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		Ref<COM_FPosition> __pos = memnew(COM_FPosition);
		if (!__pos->deserialize(r)) return false;
		proxy->transfor2(__instId, __pos);
		return true;
	}
	case 37: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		proxy->openScene(__sceneId);
		return true;
	}
	case 38: {
		bool __isOk = false;
		if (!r->readType(__isOk)) return false;
		proxy->autoBattleResult(__isOk);
		return true;
	}
	case 39: {
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		proxy->talked2Npc(__npcId);
		return true;
	}
	case 40: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->talked2Player(__playerId);
		return true;
	}
	case 41: {
		int32_t __itemId = 0;
		if (!r->readType(__itemId)) return false;
		int32_t __stack = 0;
		if (!r->readType(__stack)) return false;
		proxy->useItemOk(__itemId, __stack);
		return true;
	}
	case 42: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		bool __inBattle = false;
		if (!r->readType(__inBattle)) return false;
		proxy->syncBattleStatus(__playerId, __inBattle);
		return true;
	}
	case 43: {
		Ref<COM_InitBattle> __initBattle = memnew(COM_InitBattle);
		if (!__initBattle->deserialize(r)) return false;
		proxy->enterBattleOk(__initBattle);
		return true;
	}
	case 44: {
		uint16_t __bjt = (BattleJudgeType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 4) return false; __bjt = (uint16_t)__e; }
		Ref<COM_BattleOverClearing> __init = memnew(COM_BattleOverClearing);
		if (!__init->deserialize(r)) return false;
		proxy->exitBattleOk(__bjt, __init);
		return true;
	}
	case 45: {
		uint32_t __uid = 0;
		if (!r->readType(__uid)) return false;
		proxy->syncOrderOk(__uid);
		return true;
	}
	case 46: {
		proxy->syncOrderOkEX();
		return true;
	}
	case 47: {
		Ref<COM_BattleReport> __reports = memnew(COM_BattleReport);
		if (!__reports->deserialize(r)) return false;
		proxy->syncOneTurnAction(__reports);
		return true;
	}
	case 48: {
		uint32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		TypedArray<COM_PropValue> __props;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__props.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_PropValue> __elem = memnew(COM_PropValue);
				if(!__elem->deserialize(r)) return false;
				__props[i] = __elem;
			}
		}
		proxy->syncProperties(__guid, __props);
		return true;
	}
	case 49: {
		Ref<COM_ChatInfo> __info = memnew(COM_ChatInfo);
		if (!__info->deserialize(r)) return false;
		Ref<COM_ContactInfo> __myinfo = memnew(COM_ContactInfo);
		if (!__myinfo->deserialize(r)) return false;
		proxy->receiveChat(__info, __myinfo);
		return true;
	}
	case 50: {
		int32_t __audioId = 0;
		if (!r->readType(__audioId)) return false;
		TypedArray<uint8_t> __content;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__content.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint8_t __tmp;
				if(!r->readType(__tmp)) return false;
				__content[i] = __tmp;
			}
		}
		proxy->requestAudioOk(__audioId, __content);
		return true;
	}
	case 51: {
		Ref<COM_ShowItemInstInfo> __info = memnew(COM_ShowItemInstInfo);
		if (!__info->deserialize(r)) return false;
		uint16_t __type = (ChatKind)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 8) return false; __type = (uint16_t)__e; }
		proxy->publishItemInstRes(__info, __type);
		return true;
	}
	case 52: {
		Ref<COM_ShowItemInst> __item = memnew(COM_ShowItemInst);
		if (!__item->deserialize(r)) return false;
		proxy->queryItemInstRes(__item);
		return true;
	}
	case 53: {
		Ref<COM_ShowbabyInstInfo> __info = memnew(COM_ShowbabyInstInfo);
		if (!__info->deserialize(r)) return false;
		uint16_t __type = (ChatKind)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 8) return false; __type = (uint16_t)__e; }
		proxy->publishBabyInstRes(__info, __type);
		return true;
	}
	case 54: {
		Ref<COM_ShowbabyInst> __inst = memnew(COM_ShowbabyInst);
		if (!__inst->deserialize(r)) return false;
		proxy->queryBabyInstRes(__inst);
		return true;
	}
	case 55: {
		float __t = 0.0;
		if (!r->readType(__t)) return false;
		proxy->setNoTalkTime(__t);
		return true;
	}
	case 56: {
		TypedArray<int32_t> __npcList;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__npcList.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__npcList[i] = __tmp;
			}
		}
		proxy->addNpc(__npcList);
		return true;
	}
	case 57: {
		TypedArray<int32_t> __npcList;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__npcList.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__npcList[i] = __tmp;
			}
		}
		proxy->delNpc(__npcList);
		return true;
	}
	case 58: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		bool __isLeader = false;
		if (!r->readType(__isLeader)) return false;
		proxy->setTeamLeader(__playerId, __isLeader);
		return true;
	}
	case 59: {
		TypedArray<COM_Item> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->initBag(__items);
		return true;
	}
	case 60: {
		Ref<COM_Item> __item = memnew(COM_Item);
		if (!__item->deserialize(r)) return false;
		proxy->addBagItem(__item);
		return true;
	}
	case 61: {
		uint16_t __slot = 0;
		if (!r->readType(__slot)) return false;
		proxy->delBagItem(__slot);
		return true;
	}
	case 62: {
		Ref<COM_Item> __item = memnew(COM_Item);
		if (!__item->deserialize(r)) return false;
		proxy->updateBagItem(__item);
		return true;
	}
	case 63: {
		Ref<COM_Item> __item = memnew(COM_Item);
		if (!__item->deserialize(r)) return false;
		proxy->depositItemOK(__item);
		return true;
	}
	case 64: {
		uint16_t __slot = 0;
		if (!r->readType(__slot)) return false;
		proxy->getoutItemOK(__slot);
		return true;
	}
	case 65: {
		Ref<COM_BabyInst> __baby = memnew(COM_BabyInst);
		if (!__baby->deserialize(r)) return false;
		proxy->depositBabyOK(__baby);
		return true;
	}
	case 66: {
		uint16_t __slot = 0;
		if (!r->readType(__slot)) return false;
		proxy->getoutBabyOK(__slot);
		return true;
	}
	case 67: {
		TypedArray<COM_Item> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->sortItemStorageOK(__items);
		return true;
	}
	case 68: {
		TypedArray<uint32_t> __babys;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__babys.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__babys[i] = __tmp;
			}
		}
		proxy->sortBabyStorageOK(__babys);
		return true;
	}
	case 69: {
		uint16_t __gridNum = 0;
		if (!r->readType(__gridNum)) return false;
		TypedArray<COM_Item> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->initItemStorage(__gridNum, __items);
		return true;
	}
	case 70: {
		uint16_t __gridNum = 0;
		if (!r->readType(__gridNum)) return false;
		TypedArray<COM_BabyInst> __babys;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__babys.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyInst> __elem = memnew(COM_BabyInst);
				if(!__elem->deserialize(r)) return false;
				__babys[i] = __elem;
			}
		}
		proxy->initBabyStorage(__gridNum, __babys);
		return true;
	}
	case 71: {
		uint16_t __tp = (StorageType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 2) return false; __tp = (uint16_t)__e; }
		uint16_t __gridNum = 0;
		if (!r->readType(__gridNum)) return false;
		proxy->openStorageGrid(__tp, __gridNum);
		return true;
	}
	case 72: {
		uint16_t __slot = 0;
		if (!r->readType(__slot)) return false;
		proxy->delStorageBabyOK(__slot);
		return true;
	}
	case 73: {
		TypedArray<COM_Item> __equips;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__equips.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				__equips[i] = __elem;
			}
		}
		proxy->initPlayerEquips(__equips);
		return true;
	}
	case 74: {
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		Ref<COM_Item> __equip = memnew(COM_Item);
		if (!__equip->deserialize(r)) return false;
		proxy->wearEquipmentOk(__target, __equip);
		return true;
	}
	case 75: {
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		uint32_t __itemId = 0;
		if (!r->readType(__itemId)) return false;
		proxy->scenePlayerWearEquipment(__target, __itemId);
		return true;
	}
	case 76: {
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		uint32_t __itemInstId = 0;
		if (!r->readType(__itemInstId)) return false;
		proxy->delEquipmentOk(__target, __itemInstId);
		return true;
	}
	case 77: {
		uint32_t __target = 0;
		if (!r->readType(__target)) return false;
		uint32_t __itemId = 0;
		if (!r->readType(__itemId)) return false;
		proxy->scenePlayerDoffEquipment(__target, __itemId);
		return true;
	}
	case 78: {
		proxy->sortBagItemOk();
		return true;
	}
	case 79: {
		TypedArray<COM_SimpleTeamInfo> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimpleTeamInfo> __elem = memnew(COM_SimpleTeamInfo);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->jointLobbyOk(__infos);
		return true;
	}
	case 80: {
		proxy->exitLobbyOk();
		return true;
	}
	case 81: {
		uint32_t __teamId = 0;
		if (!r->readType(__teamId)) return false;
		proxy->syncDelLobbyTeam(__teamId);
		return true;
	}
	case 82: {
		Ref<COM_SimpleTeamInfo> __info = memnew(COM_SimpleTeamInfo);
		if (!__info->deserialize(r)) return false;
		proxy->syncUpdateLobbyTeam(__info);
		return true;
	}
	case 83: {
		Ref<COM_SimpleTeamInfo> __team = memnew(COM_SimpleTeamInfo);
		if (!__team->deserialize(r)) return false;
		proxy->syncAddLobbyTeam(__team);
		return true;
	}
	case 84: {
		Ref<COM_TeamInfo> __team = memnew(COM_TeamInfo);
		if (!__team->deserialize(r)) return false;
		proxy->createTeamOk(__team);
		return true;
	}
	case 85: {
		Ref<COM_TeamInfo> __team = memnew(COM_TeamInfo);
		if (!__team->deserialize(r)) return false;
		proxy->changeTeamOk(__team);
		return true;
	}
	case 86: {
		Ref<COM_TeamInfo> __team = memnew(COM_TeamInfo);
		if (!__team->deserialize(r)) return false;
		proxy->joinTeamOk(__team);
		return true;
	}
	case 87: {
		Ref<COM_SimplePlayerInst> __info = memnew(COM_SimplePlayerInst);
		if (!__info->deserialize(r)) return false;
		proxy->addTeamMember(__info);
		return true;
	}
	case 88: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delTeamMember(__instId);
		return true;
	}
	case 89: {
		int32_t __uuid = 0;
		if (!r->readType(__uuid)) return false;
		proxy->changeTeamLeaderOk(__uuid);
		return true;
	}
	case 90: {
		bool __iskick = false;
		if (!r->readType(__iskick)) return false;
		proxy->exitTeamOk(__iskick);
		return true;
	}
	case 91: {
		Ref<COM_TeamInfo> __team = memnew(COM_TeamInfo);
		if (!__team->deserialize(r)) return false;
		proxy->updateTeam(__team);
		return true;
	}
	case 92: {
		Ref<COM_TeamInfo> __team = memnew(COM_TeamInfo);
		if (!__team->deserialize(r)) return false;
		proxy->joinTeamRoomOK(__team);
		return true;
	}
	case 93: {
		uint32_t __teamId = 0;
		if (!r->readType(__teamId)) return false;
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->inviteJoinTeam(__teamId, __name);
		return true;
	}
	case 94: {
		int32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		TypedArray<COM_PropValue> __props;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__props.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_PropValue> __elem = memnew(COM_PropValue);
				if(!__elem->deserialize(r)) return false;
				__props[i] = __elem;
			}
		}
		proxy->syncTeamDirtyProp(__guid, __props);
		return true;
	}
	case 95: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->leaveTeamOk(__playerId);
		return true;
	}
	case 96: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->backTeamOK(__playerId);
		return true;
	}
	case 97: {
		proxy->teamCallMemberBack();
		return true;
	}
	case 98: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->refuseBackTeamOk(__playerId);
		return true;
	}
	case 99: {
		String __reqName = "";
		if (!r->readType(__reqName, 65535)) return false;
		proxy->requestJoinTeamTranspond(__reqName);
		return true;
	}
	case 100: {
		TypedArray<COM_Item> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Item> __elem = memnew(COM_Item);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->drawLotteryBoxRep(__items);
		return true;
	}
	case 101: {
		Ref<COM_EmployeeInst> __employee = memnew(COM_EmployeeInst);
		if (!__employee->deserialize(r)) return false;
		proxy->addEmployee(__employee);
		return true;
	}
	case 102: {
		int32_t __empId = 0;
		if (!r->readType(__empId)) return false;
		uint16_t __group = (EmployeesBattleGroup)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 5) return false; __group = (uint16_t)__e; }
		bool __forbattle = false;
		if (!r->readType(__forbattle)) return false;
		proxy->battleEmployee(__empId, __group, __forbattle);
		return true;
	}
	case 103: {
		uint16_t __group = (EmployeesBattleGroup)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 5) return false; __group = (uint16_t)__e; }
		proxy->changeEmpBattleGroupOK(__group);
		return true;
	}
	case 104: {
		int32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		uint16_t __qc = (QualityColor)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 16) return false; __qc = (uint16_t)__e; }
		proxy->evolveOK(__guid, __qc);
		return true;
	}
	case 105: {
		int32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		int32_t __star = 0;
		if (!r->readType(__star)) return false;
		Ref<COM_Skill> __sk = memnew(COM_Skill);
		if (!__sk->deserialize(r)) return false;
		proxy->upStarOK(__guid, __star, __sk);
		return true;
	}
	case 106: {
		TypedArray<uint32_t> __instids;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__instids.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__instids[i] = __tmp;
			}
		}
		proxy->delEmployeeOK(__instids);
		return true;
	}
	case 107: {
		int32_t __guid = 0;
		if (!r->readType(__guid)) return false;
		uint32_t __soulNum = 0;
		if (!r->readType(__soulNum)) return false;
		proxy->sycnEmployeeSoul(__guid, __soulNum);
		return true;
	}
	case 108: {
		TypedArray<COM_QuestInst> __qlist;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__qlist.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_QuestInst> __elem = memnew(COM_QuestInst);
				if(!__elem->deserialize(r)) return false;
				__qlist[i] = __elem;
			}
		}
		TypedArray<int32_t> __clist;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__clist.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__clist[i] = __tmp;
			}
		}
		proxy->initQuest(__qlist, __clist);
		return true;
	}
	case 109: {
		Ref<COM_QuestInst> __inst = memnew(COM_QuestInst);
		if (!__inst->deserialize(r)) return false;
		proxy->acceptQuestOk(__inst);
		return true;
	}
	case 110: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->submitQuestOk(__questId);
		return true;
	}
	case 111: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->giveupQuestOk(__questId);
		return true;
	}
	case 112: {
		Ref<COM_QuestInst> __inst = memnew(COM_QuestInst);
		if (!__inst->deserialize(r)) return false;
		proxy->updateQuestInst(__inst);
		return true;
	}
	case 113: {
		Ref<COM_ContactInfo> __contact = memnew(COM_ContactInfo);
		if (!__contact->deserialize(r)) return false;
		proxy->requestContactInfoOk(__contact);
		return true;
	}
	case 114: {
		Ref<COM_ContactInfo> __inst = memnew(COM_ContactInfo);
		if (!__inst->deserialize(r)) return false;
		proxy->addFriendOK(__inst);
		return true;
	}
	case 115: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delFriendOK(__instId);
		return true;
	}
	case 116: {
		Ref<COM_ContactInfo> __inst = memnew(COM_ContactInfo);
		if (!__inst->deserialize(r)) return false;
		proxy->addBlacklistOK(__inst);
		return true;
	}
	case 117: {
		uint32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->delBlacklistOK(__instId);
		return true;
	}
	case 118: {
		proxy->findFriendFail();
		return true;
	}
	case 119: {
		TypedArray<COM_ContactInfo> __insts;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__insts.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__insts[i] = __elem;
			}
		}
		proxy->referrFriendOK(__insts);
		return true;
	}
	case 120: {
		TypedArray<COM_ContactInfo> __insts;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__insts.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__insts[i] = __elem;
			}
		}
		proxy->requestFriendListOK(__insts);
		return true;
	}
	case 121: {
		int32_t __lotteryId = 0;
		if (!r->readType(__lotteryId)) return false;
		TypedArray<COM_DropItem> __dropItem;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__dropItem.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_DropItem> __elem = memnew(COM_DropItem);
				if(!__elem->deserialize(r)) return false;
				__dropItem[i] = __elem;
			}
		}
		proxy->lotteryOk(__lotteryId, __dropItem);
		return true;
	}
	case 122: {
		Ref<COM_Gather> __gather = memnew(COM_Gather);
		if (!__gather->deserialize(r)) return false;
		proxy->openGatherOK(__gather);
		return true;
	}
	case 123: {
		TypedArray<COM_DropItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_DropItem> __elem = memnew(COM_DropItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		Ref<COM_Gather> __gather = memnew(COM_Gather);
		if (!__gather->deserialize(r)) return false;
		uint32_t __gatherNum = 0;
		if (!r->readType(__gatherNum)) return false;
		proxy->miningOk(__items, __gather, __gatherNum);
		return true;
	}
	case 124: {
		uint32_t __compoundId = 0;
		if (!r->readType(__compoundId)) return false;
		proxy->openCompound(__compoundId);
		return true;
	}
	case 125: {
		Ref<COM_Item> __item = memnew(COM_Item);
		if (!__item->deserialize(r)) return false;
		proxy->compoundItemOk(__item);
		return true;
	}
	case 126: {
		int32_t __num = 0;
		if (!r->readType(__num)) return false;
		proxy->openBagGridOk(__num);
		return true;
	}
	case 127: {
		bool __isOK = false;
		if (!r->readType(__isOK)) return false;
		proxy->requestChallengeOK(__isOK);
		return true;
	}
	case 128: {
		Ref<COM_EndlessStair> __info = memnew(COM_EndlessStair);
		if (!__info->deserialize(r)) return false;
		proxy->requestMySelfJJCDataOK(__info);
		return true;
	}
	case 129: {
		TypedArray<COM_EndlessStair> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EndlessStair> __elem = memnew(COM_EndlessStair);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestRivalOK(__infos);
		return true;
	}
	case 130: {
		proxy->rivalTimeOK();
		return true;
	}
	case 131: {
		Ref<COM_SimplePlayerInst> __inst = memnew(COM_SimplePlayerInst);
		if (!__inst->deserialize(r)) return false;
		proxy->checkMsgOK(__inst);
		return true;
	}
	case 132: {
		TypedArray<COM_JJCBattleMsg> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_JJCBattleMsg> __elem = memnew(COM_JJCBattleMsg);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestMyAllbattleMsgOK(__infos);
		return true;
	}
	case 133: {
		Ref<COM_JJCBattleMsg> __info = memnew(COM_JJCBattleMsg);
		if (!__info->deserialize(r)) return false;
		proxy->myBattleMsgOK(__info);
		return true;
	}
	case 134: {
		uint32_t __myRank = 0;
		if (!r->readType(__myRank)) return false;
		TypedArray<COM_EndlessStair> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EndlessStair> __elem = memnew(COM_EndlessStair);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestJJCRankOK(__myRank, __infos);
		return true;
	}
	case 135: {
		uint32_t __myRank = 0;
		if (!r->readType(__myRank)) return false;
		TypedArray<COM_ContactInfo> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestLevelRankOK(__myRank, __infos);
		return true;
	}
	case 136: {
		uint32_t __myRank = 0;
		if (!r->readType(__myRank)) return false;
		TypedArray<COM_BabyRankData> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyRankData> __elem = memnew(COM_BabyRankData);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestBabyRankOK(__myRank, __infos);
		return true;
	}
	case 137: {
		uint32_t __myRank = 0;
		if (!r->readType(__myRank)) return false;
		TypedArray<COM_EmployeeRankData> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EmployeeRankData> __elem = memnew(COM_EmployeeRankData);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestEmpRankOK(__myRank, __infos);
		return true;
	}
	case 138: {
		uint32_t __myRank = 0;
		if (!r->readType(__myRank)) return false;
		TypedArray<COM_ContactInfo> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestPlayerFFRankOK(__myRank, __infos);
		return true;
	}
	case 139: {
		bool __isOnline = false;
		if (!r->readType(__isOnline)) return false;
		proxy->queryOnlinePlayerOK(__isOnline);
		return true;
	}
	case 140: {
		Ref<COM_SimplePlayerInst> __inst = memnew(COM_SimplePlayerInst);
		if (!__inst->deserialize(r)) return false;
		proxy->queryPlayerOK(__inst);
		return true;
	}
	case 141: {
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		proxy->queryBabyOK(__inst);
		return true;
	}
	case 142: {
		Ref<COM_EmployeeInst> __inst = memnew(COM_EmployeeInst);
		if (!__inst->deserialize(r)) return false;
		proxy->queryEmployeeOK(__inst);
		return true;
	}
	case 143: {
		uint32_t __guideMask = 0;
		if (!r->readType(__guideMask)) return false;
		proxy->initGuide(__guideMask);
		return true;
	}
	case 144: {
		int32_t __id = 0;
		if (!r->readType(__id)) return false;
		proxy->buyShopItemOk(__id);
		return true;
	}
	case 145: {
		int32_t __title = 0;
		if (!r->readType(__title)) return false;
		proxy->addPlayerTitle(__title);
		return true;
	}
	case 146: {
		int32_t __title = 0;
		if (!r->readType(__title)) return false;
		proxy->delPlayerTitle(__title);
		return true;
	}
	case 147: {
		float __greenTime = 0.0;
		if (!r->readType(__greenTime)) return false;
		float __blueTime = 0.0;
		if (!r->readType(__blueTime)) return false;
		int32_t __greenFreeNum = 0;
		if (!r->readType(__greenFreeNum)) return false;
		proxy->requestOpenBuyBox(__greenTime, __blueTime, __greenFreeNum);
		return true;
	}
	case 148: {
		proxy->requestGreenBoxTimeOk();
		return true;
	}
	case 149: {
		proxy->requestBlueBoxTimeOk();
		return true;
	}
	case 150: {
		Ref<COM_Achievement> __achs = memnew(COM_Achievement);
		if (!__achs->deserialize(r)) return false;
		proxy->updateAchievementinfo(__achs);
		return true;
	}
	case 151: {
		uint64_t __flag = 0;
		if (!r->readType(__flag)) return false;
		proxy->syncOpenSystemFlag(__flag);
		return true;
	}
	case 152: {
		uint32_t __ar = 0;
		if (!r->readType(__ar)) return false;
		proxy->requestActivityRewardOK(__ar);
		return true;
	}
	case 153: {
		Ref<COM_ActivityTable> __table = memnew(COM_ActivityTable);
		if (!__table->deserialize(r)) return false;
		proxy->syncActivity(__table);
		return true;
	}
	case 154: {
		uint16_t __type = (ActivityType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 21) return false; __type = (uint16_t)__e; }
		bool __open = false;
		if (!r->readType(__open)) return false;
		proxy->updateActivityStatus(__type, __open);
		return true;
	}
	case 155: {
		uint16_t __type = (ActivityType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 21) return false; __type = (uint16_t)__e; }
		int32_t __counter = 0;
		if (!r->readType(__counter)) return false;
		int32_t __reward = 0;
		if (!r->readType(__reward)) return false;
		proxy->updateActivityCounter(__type, __counter, __reward);
		return true;
	}
	case 156: {
		Ref<COM_Exam> __exam = memnew(COM_Exam);
		if (!__exam->deserialize(r)) return false;
		proxy->syncExam(__exam);
		return true;
	}
	case 157: {
		Ref<COM_Answer> __answer = memnew(COM_Answer);
		if (!__answer->deserialize(r)) return false;
		proxy->syncExamAnswer(__answer);
		return true;
	}
	case 158: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->petActivityNoNum(__name);
		return true;
	}
	case 159: {
		Ref<COM_HundredBattle> __hb = memnew(COM_HundredBattle);
		if (!__hb->deserialize(r)) return false;
		proxy->syncHundredInfo(__hb);
		return true;
	}
	case 160: {
		TypedArray<int32_t> __info;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__info.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__info[i] = __tmp;
			}
		}
		int32_t __process = 0;
		if (!r->readType(__process)) return false;
		bool __sign7 = false;
		if (!r->readType(__sign7)) return false;
		bool __sign14 = false;
		if (!r->readType(__sign14)) return false;
		bool __sign28 = false;
		if (!r->readType(__sign28)) return false;
		proxy->initSignUp(__info, __process, __sign7, __sign14, __sign28);
		return true;
	}
	case 161: {
		bool __flag = false;
		if (!r->readType(__flag)) return false;
		proxy->signUp(__flag);
		return true;
	}
	case 162: {
		proxy->requestSignupRewardOk7();
		return true;
	}
	case 163: {
		proxy->requestSignupRewardOk14();
		return true;
	}
	case 164: {
		proxy->requestSignupRewardOk28();
		return true;
	}
	case 165: {
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		float __times = 0.0;
		if (!r->readType(__times)) return false;
		proxy->sycnDoubleExpTime(__isFlag, __times);
		return true;
	}
	case 166: {
		TypedArray<COM_State> __states;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__states.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_State> __elem = memnew(COM_State);
				if(!__elem->deserialize(r)) return false;
				__states[i] = __elem;
			}
		}
		proxy->sycnStates(__states);
		return true;
	}
	case 167: {
		TypedArray<COM_ContactInfo> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->requestpvprankOK(__infos);
		return true;
	}
	case 168: {
		proxy->syncMyJJCTeamMember();
		return true;
	}
	case 169: {
		proxy->startMatchingOK();
		return true;
	}
	case 170: {
		float __times = 0.0;
		if (!r->readType(__times)) return false;
		proxy->stopMatchingOK(__times);
		return true;
	}
	case 171: {
		Ref<COM_PlayerVsPlayer> __info = memnew(COM_PlayerVsPlayer);
		if (!__info->deserialize(r)) return false;
		proxy->updatePvpJJCinfo(__info);
		return true;
	}
	case 172: {
		proxy->exitPvpJJCOk();
		return true;
	}
	case 173: {
		Ref<COM_SimpleInformation> __info = memnew(COM_SimpleInformation);
		if (!__info->deserialize(r)) return false;
		proxy->syncEnemyPvpJJCPlayerInfo(__info);
		return true;
	}
	case 174: {
		TypedArray<COM_SimpleInformation> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimpleInformation> __elem = memnew(COM_SimpleInformation);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		uint32_t __teamID_ = 0;
		if (!r->readType(__teamID_)) return false;
		proxy->syncEnemyPvpJJCTeamInfo(__infos, __teamID_);
		return true;
	}
	case 175: {
		proxy->openWarriorchooseUI();
		return true;
	}
	case 176: {
		proxy->warriorStartOK();
		return true;
	}
	case 177: {
		proxy->warriorStopOK();
		return true;
	}
	case 178: {
		TypedArray<COM_SimpleInformation> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimpleInformation> __elem = memnew(COM_SimpleInformation);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		uint32_t __teamID_ = 0;
		if (!r->readType(__teamID_)) return false;
		proxy->syncWarriorEnemyTeamInfo(__infos, __teamID_);
		return true;
	}
	case 179: {
		TypedArray<COM_Mail> __mails;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__mails.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Mail> __elem = memnew(COM_Mail);
				if(!__elem->deserialize(r)) return false;
				__mails[i] = __elem;
			}
		}
		proxy->appendMail(__mails);
		return true;
	}
	case 180: {
		int32_t __mailId = 0;
		if (!r->readType(__mailId)) return false;
		proxy->delMail(__mailId);
		return true;
	}
	case 181: {
		Ref<COM_Mail> __mail = memnew(COM_Mail);
		if (!__mail->deserialize(r)) return false;
		proxy->updateMailOk(__mail);
		return true;
	}
	case 182: {
		String __content = "";
		if (!r->readType(__content, 65535)) return false;
		bool __isGm = false;
		if (!r->readType(__isGm)) return false;
		proxy->boardcastNotice(__content, __isGm);
		return true;
	}
	case 183: {
		proxy->createGuildOK();
		return true;
	}
	case 184: {
		proxy->delGuildOK();
		return true;
	}
	case 185: {
		String __who = "";
		if (!r->readType(__who, 65535)) return false;
		bool __isKick = false;
		if (!r->readType(__isKick)) return false;
		proxy->leaveGuildOk(__who, __isKick);
		return true;
	}
	case 186: {
		Ref<COM_Guild> __guild = memnew(COM_Guild);
		if (!__guild->deserialize(r)) return false;
		proxy->initGuildData(__guild);
		return true;
	}
	case 187: {
		TypedArray<COM_GuildMember> __member;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__member.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildMember> __elem = memnew(COM_GuildMember);
				if(!__elem->deserialize(r)) return false;
				__member[i] = __elem;
			}
		}
		proxy->initGuildMemberList(__member);
		return true;
	}
	case 188: {
		Ref<COM_GuildMember> __member = memnew(COM_GuildMember);
		if (!__member->deserialize(r)) return false;
		uint16_t __flag = (ModifyListFlag)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 9) return false; __flag = (uint16_t)__e; }
		proxy->modifyGuildMemberList(__member, __flag);
		return true;
	}
	case 189: {
		Ref<COM_GuildViewerData> __data = memnew(COM_GuildViewerData);
		if (!__data->deserialize(r)) return false;
		uint16_t __flag = (ModifyListFlag)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 9) return false; __flag = (uint16_t)__e; }
		proxy->modifyGuildList(__data, __flag);
		return true;
	}
	case 190: {
		int16_t __page = 0;
		if (!r->readType(__page)) return false;
		int16_t __pageNum = 0;
		if (!r->readType(__pageNum)) return false;
		TypedArray<COM_GuildViewerData> __guildList;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__guildList.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildViewerData> __elem = memnew(COM_GuildViewerData);
				if(!__elem->deserialize(r)) return false;
				__guildList[i] = __elem;
			}
		}
		proxy->queryGuildListResult(__page, __pageNum, __guildList);
		return true;
	}
	case 191: {
		String __sendName = "";
		if (!r->readType(__sendName, 65535)) return false;
		String __guildName = "";
		if (!r->readType(__guildName, 65535)) return false;
		proxy->inviteGuild(__sendName, __guildName);
		return true;
	}
	case 192: {
		TypedArray<COM_GuildShopItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildShopItem> __elem = memnew(COM_GuildShopItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->updateGuildShopItems(__items);
		return true;
	}
	case 193: {
		uint16_t __type = (GuildBuildingType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 8) return false; __type = (uint16_t)__e; }
		Ref<COM_GuildBuilding> __building = memnew(COM_GuildBuilding);
		if (!__building->deserialize(r)) return false;
		proxy->updateGuildBuilding(__type, __building);
		return true;
	}
	case 194: {
		Ref<COM_GuildMember> __member = memnew(COM_GuildMember);
		if (!__member->deserialize(r)) return false;
		proxy->updateGuildMyMember(__member);
		return true;
	}
	case 195: {
		Ref<COM_Skill> __skInst = memnew(COM_Skill);
		if (!__skInst->deserialize(r)) return false;
		proxy->levelupGuildSkillOk(__skInst);
		return true;
	}
	case 196: {
		int32_t __val = 0;
		if (!r->readType(__val)) return false;
		proxy->presentGuildItemOk(__val);
		return true;
	}
	case 197: {
		Ref<COM_GuildProgen> __mInst = memnew(COM_GuildProgen);
		if (!__mInst->deserialize(r)) return false;
		proxy->progenitusAddExpOk(__mInst);
		return true;
	}
	case 198: {
		TypedArray<int32_t> __positions;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__positions.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__positions[i] = __tmp;
			}
		}
		proxy->setProgenitusPositionOk(__positions);
		return true;
	}
	case 199: {
		int32_t __val = 0;
		if (!r->readType(__val)) return false;
		proxy->updateGuildFundz(__val);
		return true;
	}
	case 200: {
		int32_t __val = 0;
		if (!r->readType(__val)) return false;
		proxy->updateGuildMemberContribution(__val);
		return true;
	}
	case 201: {
		String __otherName = "";
		if (!r->readType(__otherName, 65535)) return false;
		int32_t __playerNum = 0;
		if (!r->readType(__playerNum)) return false;
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		bool __isLeft = false;
		if (!r->readType(__isLeft)) return false;
		int32_t __lstime = 0;
		if (!r->readType(__lstime)) return false;
		proxy->openGuildBattle(__otherName, __playerNum, __level, __isLeft, __lstime);
		return true;
	}
	case 202: {
		String __otherName = "";
		if (!r->readType(__otherName, 65535)) return false;
		int32_t __otherCon = 0;
		if (!r->readType(__otherCon)) return false;
		int32_t __selfCon = 0;
		if (!r->readType(__selfCon)) return false;
		proxy->startGuildBattle(__otherName, __otherCon, __selfCon);
		return true;
	}
	case 203: {
		bool __isWinner = false;
		if (!r->readType(__isWinner)) return false;
		proxy->closeGuildBattle(__isWinner);
		return true;
	}
	case 204: {
		int32_t __myWin = 0;
		if (!r->readType(__myWin)) return false;
		int32_t __otherWin = 0;
		if (!r->readType(__otherWin)) return false;
		proxy->syncGuildBattleWinCount(__myWin, __otherWin);
		return true;
	}
	case 205: {
		TypedArray<COM_SellItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SellItem> __elem = memnew(COM_SellItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->initMySelling(__items);
		return true;
	}
	case 206: {
		TypedArray<COM_SelledItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SelledItem> __elem = memnew(COM_SelledItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->initMySelled(__items);
		return true;
	}
	case 207: {
		TypedArray<COM_SellItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SellItem> __elem = memnew(COM_SellItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		int32_t __total = 0;
		if (!r->readType(__total)) return false;
		proxy->fetchSellingOk(__items, __total);
		return true;
	}
	case 208: {
		TypedArray<COM_SellItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SellItem> __elem = memnew(COM_SellItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		int32_t __total = 0;
		if (!r->readType(__total)) return false;
		proxy->fetchSellingOk2(__items, __total);
		return true;
	}
	case 209: {
		Ref<COM_SellItem> __item = memnew(COM_SellItem);
		if (!__item->deserialize(r)) return false;
		proxy->sellingOk(__item);
		return true;
	}
	case 210: {
		Ref<COM_SelledItem> __item = memnew(COM_SelledItem);
		if (!__item->deserialize(r)) return false;
		proxy->selledOk(__item);
		return true;
	}
	case 211: {
		int32_t __sellid = 0;
		if (!r->readType(__sellid)) return false;
		proxy->unsellingOk(__sellid);
		return true;
	}
	case 212: {
		proxy->redemptionSpreeOk();
		return true;
	}
	case 213: {
		Ref<COM_State> __st = memnew(COM_State);
		if (!__st->deserialize(r)) return false;
		proxy->insertState(__st);
		return true;
	}
	case 214: {
		Ref<COM_State> __st = memnew(COM_State);
		if (!__st->deserialize(r)) return false;
		proxy->updattState(__st);
		return true;
	}
	case 215: {
		uint32_t __stid = 0;
		if (!r->readType(__stid)) return false;
		proxy->removeState(__stid);
		return true;
	}
	case 216: {
		Ref<COM_Item> __item = memnew(COM_Item);
		if (!__item->deserialize(r)) return false;
		proxy->requestFixItemOk(__item);
		return true;
	}
	case 217: {
		proxy->makeDebirsItemOK();
		return true;
	}
	case 218: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		int32_t __exp = 0;
		if (!r->readType(__exp)) return false;
		proxy->updateMagicItem(__level, __exp);
		return true;
	}
	case 219: {
		uint16_t __job = (JobType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 12) return false; __job = (uint16_t)__e; }
		proxy->changeMagicJobOk(__job);
		return true;
	}
	case 220: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->magicItemTupoOk(__level);
		return true;
	}
	case 221: {
		TypedArray<uint32_t> __pond;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__pond.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__pond[i] = __tmp;
			}
		}
		proxy->zhuanpanOK(__pond);
		return true;
	}
	case 222: {
		Ref<COM_Zhuanpan> __zhuanp = memnew(COM_Zhuanpan);
		if (!__zhuanp->deserialize(r)) return false;
		proxy->updateZhuanpanNotice(__zhuanp);
		return true;
	}
	case 223: {
		Ref<COM_ZhuanpanData> __data = memnew(COM_ZhuanpanData);
		if (!__data->deserialize(r)) return false;
		proxy->sycnZhuanpanData(__data);
		return true;
	}
	case 224: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->copynonum(__name);
		return true;
	}
	case 225: {
		TypedArray<uint16_t> __sfType;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__sfType.resize(__len);
			for(int i=0; i<__len; ++i) {
				{ uint16_t __e; if(!r->readType(__e) || __e >= 6) return false; __sfType[i] = (uint16_t)__e; }
			}
		}
		proxy->sceneFilterOk(__sfType);
		return true;
	}
	case 226: {
		proxy->wishingOK();
		return true;
	}
	case 227: {
		Ref<COM_Wish> __wish = memnew(COM_Wish);
		if (!__wish->deserialize(r)) return false;
		proxy->shareWishOK(__wish);
		return true;
	}
	case 228: {
		proxy->leaderCloseDialogOk();
		return true;
	}
	case 229: {
		proxy->startOnlineTime();
		return true;
	}
	case 230: {
		uint32_t __index = 0;
		if (!r->readType(__index)) return false;
		proxy->requestOnlineTimeRewardOK(__index);
		return true;
	}
	case 231: {
		bool __flag = false;
		if (!r->readType(__flag)) return false;
		proxy->sycnVipflag(__flag);
		return true;
	}
	case 232: {
		bool __flag = false;
		if (!r->readType(__flag)) return false;
		proxy->buyFundOK(__flag);
		return true;
	}
	case 233: {
		uint32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->requestFundRewardOK(__level);
		return true;
	}
	case 234: {
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->firstRechargeOK(__isFlag);
		return true;
	}
	case 235: {
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->firstRechargeGiftOK(__isFlag);
		return true;
	}
	case 236: {
		uint16_t __type = (ADType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 21) return false; __type = (uint16_t)__e; }
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->agencyActivity(__type, __isFlag);
		return true;
	}
	case 237: {
		Ref<COM_ADLoginTotal> __festival = memnew(COM_ADLoginTotal);
		if (!__festival->deserialize(r)) return false;
		proxy->updateFestival(__festival);
		return true;
	}
	case 238: {
		Ref<COM_ADChargeTotal> __val = memnew(COM_ADChargeTotal);
		if (!__val->deserialize(r)) return false;
		proxy->updateSelfRecharge(__val);
		return true;
	}
	case 239: {
		Ref<COM_ADChargeTotal> __val = memnew(COM_ADChargeTotal);
		if (!__val->deserialize(r)) return false;
		proxy->updateSysRecharge(__val);
		return true;
	}
	case 240: {
		Ref<COM_ADDiscountStore> __val = memnew(COM_ADDiscountStore);
		if (!__val->deserialize(r)) return false;
		proxy->updateSelfDiscountStore(__val);
		return true;
	}
	case 241: {
		Ref<COM_ADDiscountStore> __val = memnew(COM_ADDiscountStore);
		if (!__val->deserialize(r)) return false;
		proxy->updateSysDiscountStore(__val);
		return true;
	}
	case 242: {
		Ref<COM_ADChargeEvery> __val = memnew(COM_ADChargeEvery);
		if (!__val->deserialize(r)) return false;
		proxy->updateSelfOnceRecharge(__val);
		return true;
	}
	case 243: {
		Ref<COM_ADChargeEvery> __val = memnew(COM_ADChargeEvery);
		if (!__val->deserialize(r)) return false;
		proxy->updateSysOnceRecharge(__val);
		return true;
	}
	case 244: {
		Ref<COM_ADCardsContent> __data = memnew(COM_ADCardsContent);
		if (!__data->deserialize(r)) return false;
		proxy->openCardOK(__data);
		return true;
	}
	case 245: {
		proxy->resetCardOK();
		return true;
	}
	case 246: {
		Ref<COM_ADHotRole> __data = memnew(COM_ADHotRole);
		if (!__data->deserialize(r)) return false;
		proxy->sycnHotRole(__data);
		return true;
	}
	case 247: {
		uint16_t __buyNum = 0;
		if (!r->readType(__buyNum)) return false;
		proxy->hotRoleBuyOk(__buyNum);
		return true;
	}
	case 248: {
		Ref<COM_Sevenday> __data = memnew(COM_Sevenday);
		if (!__data->deserialize(r)) return false;
		proxy->updateSevenday(__data);
		return true;
	}
	case 249: {
		Ref<COM_ADEmployeeTotal> __data = memnew(COM_ADEmployeeTotal);
		if (!__data->deserialize(r)) return false;
		proxy->updateEmployeeActivity(__data);
		return true;
	}
	case 250: {
		Ref<COM_ADGiftBag> __data = memnew(COM_ADGiftBag);
		if (!__data->deserialize(r)) return false;
		proxy->updateMinGiftActivity(__data);
		return true;
	}
	case 251: {
		Ref<COM_IntegralData> __data = memnew(COM_IntegralData);
		if (!__data->deserialize(r)) return false;
		proxy->updateIntegralShop(__data);
		return true;
	}
	case 252: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		uint32_t __showBabyTableId = 0;
		if (!r->readType(__showBabyTableId)) return false;
		String __showBabyName = "";
		if (!r->readType(__showBabyName, 65535)) return false;
		proxy->updateShowBaby(__playerId, __showBabyTableId, __showBabyName);
		return true;
	}
	case 253: {
		Ref<COM_ADChargeTotal> __val = memnew(COM_ADChargeTotal);
		if (!__val->deserialize(r)) return false;
		proxy->updateMySelfRecharge(__val);
		return true;
	}
	case 254: {
		String __phoneNumber = "";
		if (!r->readType(__phoneNumber, 65535)) return false;
		proxy->verificationSMSOk(__phoneNumber);
		return true;
	}
	case 255: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->requestLevelGiftOK(__level);
		return true;
	}
	case 256: {
		int32_t __val = 0;
		if (!r->readType(__val)) return false;
		proxy->sycnConvertExp(__val);
		return true;
	}
	case 257: {
		Ref<COM_Item> __inst = memnew(COM_Item);
		if (!__inst->deserialize(r)) return false;
		proxy->wearFuwenOk(__inst);
		return true;
	}
	case 258: {
		int32_t __slot = 0;
		if (!r->readType(__slot)) return false;
		proxy->takeoffFuwenOk(__slot);
		return true;
	}
	case 259: {
		proxy->compFuwenOk();
		return true;
	}
	case 260: {
		TypedArray<COM_EmployeeQuestInst> __questList;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__questList.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EmployeeQuestInst> __elem = memnew(COM_EmployeeQuestInst);
				if(!__elem->deserialize(r)) return false;
				__questList[i] = __elem;
			}
		}
		proxy->requestEmployeeQuestOk(__questList);
		return true;
	}
	case 261: {
		Ref<COM_EmployeeQuestInst> __inst = memnew(COM_EmployeeQuestInst);
		if (!__inst->deserialize(r)) return false;
		proxy->acceptEmployeeQuestOk(__inst);
		return true;
	}
	case 262: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		bool __isSuccess = false;
		if (!r->readType(__isSuccess)) return false;
		proxy->submitEmployeeQuestOk(__questId, __isSuccess);
		return true;
	}
	case 263: {
		Ref<COM_CrystalData> __data = memnew(COM_CrystalData);
		if (!__data->deserialize(r)) return false;
		proxy->sycnCrystal(__data);
		return true;
	}
	case 264: {
		bool __isOK = false;
		if (!r->readType(__isOK)) return false;
		proxy->crystalUpLeveResult(__isOK);
		return true;
	}
	case 265: {
		proxy->resetCrystalPropOK();
		return true;
	}
	case 266: {
		TypedArray<COM_CourseGift> __data;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__data.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_CourseGift> __elem = memnew(COM_CourseGift);
				if(!__elem->deserialize(r)) return false;
				__data[i] = __elem;
			}
		}
		proxy->sycnCourseGift(__data);
		return true;
	}
	case 267: {
		String __orderId = "";
		if (!r->readType(__orderId, 65535)) return false;
		int32_t __shopId = 0;
		if (!r->readType(__shopId)) return false;
		proxy->orderOk(__orderId, __shopId);
		return true;
	}
	case 268: {
		int32_t __submitCount = 0;
		if (!r->readType(__submitCount)) return false;
		proxy->updateRandSubmitQuestCount(__submitCount);
		return true;
	}
	case 269: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		bool __isMember = false;
		if (!r->readType(__isMember)) return false;
		proxy->updateTeamMember(__playerId, __isMember);
		return true;
	}
	}
	return false;
}

void SGE_World2Login_Stub::queryAccount(Ref<COM_LoginInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_LoginInfo);
	info->serialize(__writer);
	methodEnd();
}

void SGE_World2Login_Stub::setAccountSeal(String accountname, bool val) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(accountname);
	__writer->writeType(val);
	methodEnd();
}

void SGE_World2Login_Stub::setPhoneNumber(String accountname, String phoneNumber) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(accountname);
	__writer->writeType(phoneNumber);
	methodEnd();
}

bool SGE_World2Login_Dispatcher::dispatch(ProtocolReader* r, SGE_World2Login_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		Ref<COM_LoginInfo> __info = memnew(COM_LoginInfo);
		if (!__info->deserialize(r)) return false;
		proxy->queryAccount(__info);
		return true;
	}
	case 1: {
		String __accountname = "";
		if (!r->readType(__accountname, 65535)) return false;
		bool __val = false;
		if (!r->readType(__val)) return false;
		proxy->setAccountSeal(__accountname, __val);
		return true;
	}
	case 2: {
		String __accountname = "";
		if (!r->readType(__accountname, 65535)) return false;
		String __phoneNumber = "";
		if (!r->readType(__phoneNumber, 65535)) return false;
		proxy->setPhoneNumber(__accountname, __phoneNumber);
		return true;
	}
	}
	return false;
}

void SGE_Login2World_Stub::queryAccountOk(Ref<COM_AccountInfo> info, bool isNew, bool isSeal) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_AccountInfo);
	info->serialize(__writer);
	__writer->writeType(isNew);
	__writer->writeType(isSeal);
	methodEnd();
}

void SGE_Login2World_Stub::setAccountSealOk(String accountname) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(accountname);
	methodEnd();
}

bool SGE_Login2World_Dispatcher::dispatch(ProtocolReader* r, SGE_Login2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		Ref<COM_AccountInfo> __info = memnew(COM_AccountInfo);
		if (!__info->deserialize(r)) return false;
		bool __isNew = false;
		if (!r->readType(__isNew)) return false;
		bool __isSeal = false;
		if (!r->readType(__isSeal)) return false;
		proxy->queryAccountOk(__info, __isNew, __isSeal);
		return true;
	}
	case 1: {
		String __accountname = "";
		if (!r->readType(__accountname, 65535)) return false;
		proxy->setAccountSealOk(__accountname);
		return true;
	}
	}
	return false;
}

void SGE_Gateway2World_Stub::syncConnectInfo(int32_t indoor, String ip) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(indoor);
	__writer->writeType(ip);
	methodEnd();
}

bool SGE_Gateway2World_Dispatcher::dispatch(ProtocolReader* r, SGE_Gateway2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		int32_t __indoor = 0;
		if (!r->readType(__indoor)) return false;
		String __ip = "";
		if (!r->readType(__ip, 65535)) return false;
		proxy->syncConnectInfo(__indoor, __ip);
		return true;
	}
	}
	return false;
}

void SGE_World2DB_Stub::queryPlayerSimpleInformation(String username, int32_t serverId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(username);
	__writer->writeType(serverId);
	methodEnd();
}

void SGE_World2DB_Stub::queryPlayer(String username, int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(username);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_World2DB_Stub::createPlayer(String username, Ref<SGE_DBPlayerData> inst, int32_t serverId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(username);
	if (inst.is_null()) inst = memnew(SGE_DBPlayerData);
	inst->serialize(__writer);
	__writer->writeType(serverId);
	methodEnd();
}

void SGE_World2DB_Stub::updatePlayer(String username, Ref<SGE_DBPlayerData> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	__writer->writeType(username);
	if (inst.is_null()) inst = memnew(SGE_DBPlayerData);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::deletePlayer(String playername) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	methodEnd();
}

void SGE_World2DB_Stub::queryPlayerById(String name, int32_t instId, int32_t where) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(name);
	__writer->writeType(instId);
	__writer->writeType(where);
	methodEnd();
}

void SGE_World2DB_Stub::insertEndlessStair(int32_t rank, String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(rank);
	__writer->writeType(name);
	methodEnd();
}

void SGE_World2DB_Stub::updateEndlessStair(int32_t rank, String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	__writer->writeType(rank);
	__writer->writeType(name);
	methodEnd();
}

void SGE_World2DB_Stub::createBaby(String playername, Ref<COM_BabyInst> inst, bool isToStorage) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	__writer->writeType(isToStorage);
	methodEnd();
}

void SGE_World2DB_Stub::deleteBaby(String playername, int32_t babyInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeType(babyInstId);
	methodEnd();
}

void SGE_World2DB_Stub::updateBaby(Ref<COM_BabyInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 10;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::updateBabys(String playername, TypedArray<COM_BabyInst> babys) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 11;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeDynSize(babys.size());
	for(int i=0; i<babys.size(); ++i) {
		Ref<COM_BabyInst> __elem = babys[i];
		if (__elem.is_null()) __elem = memnew(COM_BabyInst);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_World2DB_Stub::queryBabyById(String name, uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 12;
	__writer->writeType(__pid);
	__writer->writeType(name);
	__writer->writeType(instid);
	methodEnd();
}

void SGE_World2DB_Stub::createEmployee(String playername, Ref<COM_EmployeeInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 13;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	if (inst.is_null()) inst = memnew(COM_EmployeeInst);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::deleteEmployee(String playername, TypedArray<uint32_t> instIds) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 14;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeDynSize(instIds.size());
	for(int i=0; i<instIds.size(); ++i) {
		uint32_t __tmp = instIds[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_World2DB_Stub::updateEmployee(Ref<COM_EmployeeInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 15;
	__writer->writeType(__pid);
	if (inst.is_null()) inst = memnew(COM_EmployeeInst);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::queryEmployeeById(String name, uint32_t instid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 16;
	__writer->writeType(__pid);
	__writer->writeType(name);
	__writer->writeType(instid);
	methodEnd();
}

void SGE_World2DB_Stub::insertMail(Ref<COM_Mail> mail) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 17;
	__writer->writeType(__pid);
	if (mail.is_null()) mail = memnew(COM_Mail);
	mail->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::insertMailAll(Ref<COM_Mail> mail) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 18;
	__writer->writeType(__pid);
	if (mail.is_null()) mail = memnew(COM_Mail);
	mail->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::insertMailByRecvs(Ref<COM_Mail> mail, TypedArray<String> recvs) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 19;
	__writer->writeType(__pid);
	if (mail.is_null()) mail = memnew(COM_Mail);
	mail->serialize(__writer);
	__writer->writeDynSize(recvs.size());
	for(int i=0; i<recvs.size(); ++i) {
		String __tmp = recvs[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_World2DB_Stub::fatchMail(String recvName, int32_t mailId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 20;
	__writer->writeType(__pid);
	__writer->writeType(recvName);
	__writer->writeType(mailId);
	methodEnd();
}

void SGE_World2DB_Stub::delMail(String recvName, int32_t mailId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 21;
	__writer->writeType(__pid);
	__writer->writeType(recvName);
	__writer->writeType(mailId);
	methodEnd();
}

void SGE_World2DB_Stub::updateMail(Ref<COM_Mail> mail) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 22;
	__writer->writeType(__pid);
	if (mail.is_null()) mail = memnew(COM_Mail);
	mail->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::insertGuild(Ref<COM_Guild> guild, Ref<COM_GuildMember> guildMember) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 23;
	__writer->writeType(__pid);
	if (guild.is_null()) guild = memnew(COM_Guild);
	guild->serialize(__writer);
	if (guildMember.is_null()) guildMember = memnew(COM_GuildMember);
	guildMember->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::updateGuildRequestList(uint32_t guildId, TypedArray<COM_GuildRequestData> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 24;
	__writer->writeType(__pid);
	__writer->writeType(guildId);
	__writer->writeDynSize(data.size());
	for(int i=0; i<data.size(); ++i) {
		Ref<COM_GuildRequestData> __elem = data[i];
		if (__elem.is_null()) __elem = memnew(COM_GuildRequestData);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_World2DB_Stub::createGuildMember(Ref<COM_GuildMember> guildMember) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 25;
	__writer->writeType(__pid);
	if (guildMember.is_null()) guildMember = memnew(COM_GuildMember);
	guildMember->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::delGuild(int32_t guildId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 26;
	__writer->writeType(__pid);
	__writer->writeType(guildId);
	methodEnd();
}

void SGE_World2DB_Stub::updateGuildNotice(uint32_t guildId, String notice) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 27;
	__writer->writeType(__pid);
	__writer->writeType(guildId);
	__writer->writeType(notice);
	methodEnd();
}

void SGE_World2DB_Stub::updateGuild(Ref<COM_Guild> guild) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 28;
	__writer->writeType(__pid);
	if (guild.is_null()) guild = memnew(COM_Guild);
	guild->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::updateMemberPosition(int32_t roleId, uint16_t job) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 29;
	__writer->writeType(__pid);
	__writer->writeType(roleId);
	__writer->writeType((uint16_t)job);
	methodEnd();
}

void SGE_World2DB_Stub::updateMemberContribution(int32_t roleId, int32_t contribution) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 30;
	__writer->writeType(__pid);
	__writer->writeType(roleId);
	__writer->writeType(contribution);
	methodEnd();
}

void SGE_World2DB_Stub::updateGuildStruction(uint32_t guildId, int8_t level, int32_t struction) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 31;
	__writer->writeType(__pid);
	__writer->writeType(guildId);
	__writer->writeType(level);
	__writer->writeType(struction);
	methodEnd();
}

void SGE_World2DB_Stub::deleteGuildMember(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 32;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_World2DB_Stub::insertActivity(uint16_t adt, Ref<SGE_SysActivity> date) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 33;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)adt);
	if (date.is_null()) date = memnew(SGE_SysActivity);
	date->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::insertLoseCharge(int32_t playerId, Ref<SGE_OrderInfo> order) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 34;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	if (order.is_null()) order = memnew(SGE_OrderInfo);
	order->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::insertEmployeeQuest(uint32_t playerId, Ref<SGE_PlayerEmployeeQuest> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 35;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	if (data.is_null()) data = memnew(SGE_PlayerEmployeeQuest);
	data->serialize(__writer);
	methodEnd();
}

void SGE_World2DB_Stub::delEmployeeQuest(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 36;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_World2DB_Stub::deleteEndlessStair(String name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 37;
	__writer->writeType(__pid);
	__writer->writeType(name);
	methodEnd();
}

bool SGE_World2DB_Dispatcher::dispatch(ProtocolReader* r, SGE_World2DB_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		int32_t __serverId = 0;
		if (!r->readType(__serverId)) return false;
		proxy->queryPlayerSimpleInformation(__username, __serverId);
		return true;
	}
	case 1: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->queryPlayer(__username, __playerId);
		return true;
	}
	case 2: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		Ref<SGE_DBPlayerData> __inst = memnew(SGE_DBPlayerData);
		if (!__inst->deserialize(r)) return false;
		int32_t __serverId = 0;
		if (!r->readType(__serverId)) return false;
		proxy->createPlayer(__username, __inst, __serverId);
		return true;
	}
	case 3: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		Ref<SGE_DBPlayerData> __inst = memnew(SGE_DBPlayerData);
		if (!__inst->deserialize(r)) return false;
		proxy->updatePlayer(__username, __inst);
		return true;
	}
	case 4: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		proxy->deletePlayer(__playername);
		return true;
	}
	case 5: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		int32_t __where = 0;
		if (!r->readType(__where)) return false;
		proxy->queryPlayerById(__name, __instId, __where);
		return true;
	}
	case 6: {
		int32_t __rank = 0;
		if (!r->readType(__rank)) return false;
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->insertEndlessStair(__rank, __name);
		return true;
	}
	case 7: {
		int32_t __rank = 0;
		if (!r->readType(__rank)) return false;
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->updateEndlessStair(__rank, __name);
		return true;
	}
	case 8: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		bool __isToStorage = false;
		if (!r->readType(__isToStorage)) return false;
		proxy->createBaby(__playername, __inst, __isToStorage);
		return true;
	}
	case 9: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		int32_t __babyInstId = 0;
		if (!r->readType(__babyInstId)) return false;
		proxy->deleteBaby(__playername, __babyInstId);
		return true;
	}
	case 10: {
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		proxy->updateBaby(__inst);
		return true;
	}
	case 11: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		TypedArray<COM_BabyInst> __babys;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__babys.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyInst> __elem = memnew(COM_BabyInst);
				if(!__elem->deserialize(r)) return false;
				__babys[i] = __elem;
			}
		}
		proxy->updateBabys(__playername, __babys);
		return true;
	}
	case 12: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->queryBabyById(__name, __instid);
		return true;
	}
	case 13: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		Ref<COM_EmployeeInst> __inst = memnew(COM_EmployeeInst);
		if (!__inst->deserialize(r)) return false;
		proxy->createEmployee(__playername, __inst);
		return true;
	}
	case 14: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		TypedArray<uint32_t> __instIds;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__instIds.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__instIds[i] = __tmp;
			}
		}
		proxy->deleteEmployee(__playername, __instIds);
		return true;
	}
	case 15: {
		Ref<COM_EmployeeInst> __inst = memnew(COM_EmployeeInst);
		if (!__inst->deserialize(r)) return false;
		proxy->updateEmployee(__inst);
		return true;
	}
	case 16: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		uint32_t __instid = 0;
		if (!r->readType(__instid)) return false;
		proxy->queryEmployeeById(__name, __instid);
		return true;
	}
	case 17: {
		Ref<COM_Mail> __mail = memnew(COM_Mail);
		if (!__mail->deserialize(r)) return false;
		proxy->insertMail(__mail);
		return true;
	}
	case 18: {
		Ref<COM_Mail> __mail = memnew(COM_Mail);
		if (!__mail->deserialize(r)) return false;
		proxy->insertMailAll(__mail);
		return true;
	}
	case 19: {
		Ref<COM_Mail> __mail = memnew(COM_Mail);
		if (!__mail->deserialize(r)) return false;
		TypedArray<String> __recvs;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__recvs.resize(__len);
			for(int i=0; i<__len; ++i) {
				String __tmp;
				if(!r->readType(__tmp, 65535)) return false;
				__recvs[i] = __tmp;
			}
		}
		proxy->insertMailByRecvs(__mail, __recvs);
		return true;
	}
	case 20: {
		String __recvName = "";
		if (!r->readType(__recvName, 65535)) return false;
		int32_t __mailId = 0;
		if (!r->readType(__mailId)) return false;
		proxy->fatchMail(__recvName, __mailId);
		return true;
	}
	case 21: {
		String __recvName = "";
		if (!r->readType(__recvName, 65535)) return false;
		int32_t __mailId = 0;
		if (!r->readType(__mailId)) return false;
		proxy->delMail(__recvName, __mailId);
		return true;
	}
	case 22: {
		Ref<COM_Mail> __mail = memnew(COM_Mail);
		if (!__mail->deserialize(r)) return false;
		proxy->updateMail(__mail);
		return true;
	}
	case 23: {
		Ref<COM_Guild> __guild = memnew(COM_Guild);
		if (!__guild->deserialize(r)) return false;
		Ref<COM_GuildMember> __guildMember = memnew(COM_GuildMember);
		if (!__guildMember->deserialize(r)) return false;
		proxy->insertGuild(__guild, __guildMember);
		return true;
	}
	case 24: {
		uint32_t __guildId = 0;
		if (!r->readType(__guildId)) return false;
		TypedArray<COM_GuildRequestData> __data;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__data.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildRequestData> __elem = memnew(COM_GuildRequestData);
				if(!__elem->deserialize(r)) return false;
				__data[i] = __elem;
			}
		}
		proxy->updateGuildRequestList(__guildId, __data);
		return true;
	}
	case 25: {
		Ref<COM_GuildMember> __guildMember = memnew(COM_GuildMember);
		if (!__guildMember->deserialize(r)) return false;
		proxy->createGuildMember(__guildMember);
		return true;
	}
	case 26: {
		int32_t __guildId = 0;
		if (!r->readType(__guildId)) return false;
		proxy->delGuild(__guildId);
		return true;
	}
	case 27: {
		uint32_t __guildId = 0;
		if (!r->readType(__guildId)) return false;
		String __notice = "";
		if (!r->readType(__notice, 65535)) return false;
		proxy->updateGuildNotice(__guildId, __notice);
		return true;
	}
	case 28: {
		Ref<COM_Guild> __guild = memnew(COM_Guild);
		if (!__guild->deserialize(r)) return false;
		proxy->updateGuild(__guild);
		return true;
	}
	case 29: {
		int32_t __roleId = 0;
		if (!r->readType(__roleId)) return false;
		uint16_t __job = (GuildJob)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 7) return false; __job = (uint16_t)__e; }
		proxy->updateMemberPosition(__roleId, __job);
		return true;
	}
	case 30: {
		int32_t __roleId = 0;
		if (!r->readType(__roleId)) return false;
		int32_t __contribution = 0;
		if (!r->readType(__contribution)) return false;
		proxy->updateMemberContribution(__roleId, __contribution);
		return true;
	}
	case 31: {
		uint32_t __guildId = 0;
		if (!r->readType(__guildId)) return false;
		int8_t __level = 0;
		if (!r->readType(__level)) return false;
		int32_t __struction = 0;
		if (!r->readType(__struction)) return false;
		proxy->updateGuildStruction(__guildId, __level, __struction);
		return true;
	}
	case 32: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->deleteGuildMember(__playerId);
		return true;
	}
	case 33: {
		uint16_t __adt = (ADType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 21) return false; __adt = (uint16_t)__e; }
		Ref<SGE_SysActivity> __date = memnew(SGE_SysActivity);
		if (!__date->deserialize(r)) return false;
		proxy->insertActivity(__adt, __date);
		return true;
	}
	case 34: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		Ref<SGE_OrderInfo> __order = memnew(SGE_OrderInfo);
		if (!__order->deserialize(r)) return false;
		proxy->insertLoseCharge(__playerId, __order);
		return true;
	}
	case 35: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		Ref<SGE_PlayerEmployeeQuest> __data = memnew(SGE_PlayerEmployeeQuest);
		if (!__data->deserialize(r)) return false;
		proxy->insertEmployeeQuest(__playerId, __data);
		return true;
	}
	case 36: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->delEmployeeQuest(__playerId);
		return true;
	}
	case 37: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		proxy->deleteEndlessStair(__name);
		return true;
	}
	}
	return false;
}

void SGE_DB2World_Stub::syncGlobalGuid(uint32_t id) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(id);
	methodEnd();
}

void SGE_DB2World_Stub::syncContactInfo(TypedArray<SGE_ContactInfoExt> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeDynSize(info.size());
	for(int i=0; i<info.size(); ++i) {
		Ref<SGE_ContactInfoExt> __elem = info[i];
		if (__elem.is_null()) __elem = memnew(SGE_ContactInfoExt);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::queryPlayerSimpleInformationOk(String username, TypedArray<COM_SimpleInformation> insts, int32_t serverId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(username);
	__writer->writeDynSize(insts.size());
	for(int i=0; i<insts.size(); ++i) {
		Ref<COM_SimpleInformation> __elem = insts[i];
		if (__elem.is_null()) __elem = memnew(COM_SimpleInformation);
		__elem->serialize(__writer);
	}
	__writer->writeType(serverId);
	methodEnd();
}

void SGE_DB2World_Stub::queryPlayerOk(String username, Ref<SGE_DBPlayerData> player) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	__writer->writeType(username);
	if (player.is_null()) player = memnew(SGE_DBPlayerData);
	player->serialize(__writer);
	methodEnd();
}

void SGE_DB2World_Stub::createPlayerOk(String username, Ref<SGE_DBPlayerData> inst, int32_t inDoorId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(username);
	if (inst.is_null()) inst = memnew(SGE_DBPlayerData);
	inst->serialize(__writer);
	__writer->writeType(inDoorId);
	methodEnd();
}

void SGE_DB2World_Stub::createPlayerSameName(String username) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(username);
	methodEnd();
}

void SGE_DB2World_Stub::queryPlayerByIdOK(String playername, Ref<SGE_DBPlayerData> inst, int32_t where) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	if (inst.is_null()) inst = memnew(SGE_DBPlayerData);
	inst->serialize(__writer);
	__writer->writeType(where);
	methodEnd();
}

void SGE_DB2World_Stub::queryEndlessStairAllDateOK(TypedArray<String> name) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	__writer->writeDynSize(name.size());
	for(int i=0; i<name.size(); ++i) {
		String __tmp = name[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_DB2World_Stub::queryPlayerByLevelOK(TypedArray<COM_ContactInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	__writer->writeDynSize(info.size());
	for(int i=0; i<info.size(); ++i) {
		Ref<COM_ContactInfo> __elem = info[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::queryPlayerByFFOK(TypedArray<COM_ContactInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	__writer->writeDynSize(info.size());
	for(int i=0; i<info.size(); ++i) {
		Ref<COM_ContactInfo> __elem = info[i];
		if (__elem.is_null()) __elem = memnew(COM_ContactInfo);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::createBabyOK(String playername, Ref<COM_BabyInst> inst, bool isToStorage) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 10;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	__writer->writeType(isToStorage);
	methodEnd();
}

void SGE_DB2World_Stub::deleteBabyOK(String playername, int32_t babyInstId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 11;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeType(babyInstId);
	methodEnd();
}

void SGE_DB2World_Stub::queryBabyByFFOK(TypedArray<COM_BabyRankData> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 12;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_BabyRankData> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_BabyRankData);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::queryBabyByIdOK(String name, Ref<COM_BabyInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 13;
	__writer->writeType(__pid);
	__writer->writeType(name);
	if (inst.is_null()) inst = memnew(COM_BabyInst);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_DB2World_Stub::UpdateBabysOK(String playername) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 14;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	methodEnd();
}

void SGE_DB2World_Stub::createEmployeeOK(String playername, Ref<COM_EmployeeInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 15;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	if (inst.is_null()) inst = memnew(COM_EmployeeInst);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_DB2World_Stub::deleteEmployeeOK(String playername, TypedArray<uint32_t> instIds) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 16;
	__writer->writeType(__pid);
	__writer->writeType(playername);
	__writer->writeDynSize(instIds.size());
	for(int i=0; i<instIds.size(); ++i) {
		uint32_t __tmp = instIds[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_DB2World_Stub::queryEmployeeByFFOK(TypedArray<COM_EmployeeRankData> infos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 17;
	__writer->writeType(__pid);
	__writer->writeDynSize(infos.size());
	for(int i=0; i<infos.size(); ++i) {
		Ref<COM_EmployeeRankData> __elem = infos[i];
		if (__elem.is_null()) __elem = memnew(COM_EmployeeRankData);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::queryEmployeeByIdOK(String name, Ref<COM_EmployeeInst> inst) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 18;
	__writer->writeType(__pid);
	__writer->writeType(name);
	if (inst.is_null()) inst = memnew(COM_EmployeeInst);
	inst->serialize(__writer);
	methodEnd();
}

void SGE_DB2World_Stub::appendMail(String playerName, TypedArray<COM_Mail> mails) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 19;
	__writer->writeType(__pid);
	__writer->writeType(playerName);
	__writer->writeDynSize(mails.size());
	for(int i=0; i<mails.size(); ++i) {
		Ref<COM_Mail> __elem = mails[i];
		if (__elem.is_null()) __elem = memnew(COM_Mail);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::insertGuildOK(Ref<COM_Guild> guild, Ref<COM_GuildMember> guildMember) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 20;
	__writer->writeType(__pid);
	if (guild.is_null()) guild = memnew(COM_Guild);
	guild->serialize(__writer);
	if (guildMember.is_null()) guildMember = memnew(COM_GuildMember);
	guildMember->serialize(__writer);
	methodEnd();
}

void SGE_DB2World_Stub::updateMemberJobOk(int32_t roleId, uint16_t job) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 21;
	__writer->writeType(__pid);
	__writer->writeType(roleId);
	__writer->writeType((uint16_t)job);
	methodEnd();
}

void SGE_DB2World_Stub::syncGuild(TypedArray<COM_Guild> guilds) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 22;
	__writer->writeType(__pid);
	__writer->writeDynSize(guilds.size());
	for(int i=0; i<guilds.size(); ++i) {
		Ref<COM_Guild> __elem = guilds[i];
		if (__elem.is_null()) __elem = memnew(COM_Guild);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::syncGuildMember(TypedArray<COM_GuildMember> guildMember) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 23;
	__writer->writeType(__pid);
	__writer->writeDynSize(guildMember.size());
	for(int i=0; i<guildMember.size(); ++i) {
		Ref<COM_GuildMember> __elem = guildMember[i];
		if (__elem.is_null()) __elem = memnew(COM_GuildMember);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_DB2World_Stub::fatchActivity(Ref<SGE_SysActivity> date) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 24;
	__writer->writeType(__pid);
	if (date.is_null()) date = memnew(SGE_SysActivity);
	date->serialize(__writer);
	methodEnd();
}

void SGE_DB2World_Stub::syncEmployeeQuest(TypedArray<SGE_PlayerEmployeeQuest> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 25;
	__writer->writeType(__pid);
	__writer->writeDynSize(info.size());
	for(int i=0; i<info.size(); ++i) {
		Ref<SGE_PlayerEmployeeQuest> __elem = info[i];
		if (__elem.is_null()) __elem = memnew(SGE_PlayerEmployeeQuest);
		__elem->serialize(__writer);
	}
	methodEnd();
}

bool SGE_DB2World_Dispatcher::dispatch(ProtocolReader* r, SGE_DB2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		uint32_t __id = 0;
		if (!r->readType(__id)) return false;
		proxy->syncGlobalGuid(__id);
		return true;
	}
	case 1: {
		TypedArray<SGE_ContactInfoExt> __info;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__info.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<SGE_ContactInfoExt> __elem = memnew(SGE_ContactInfoExt);
				if(!__elem->deserialize(r)) return false;
				__info[i] = __elem;
			}
		}
		proxy->syncContactInfo(__info);
		return true;
	}
	case 2: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		TypedArray<COM_SimpleInformation> __insts;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__insts.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SimpleInformation> __elem = memnew(COM_SimpleInformation);
				if(!__elem->deserialize(r)) return false;
				__insts[i] = __elem;
			}
		}
		int32_t __serverId = 0;
		if (!r->readType(__serverId)) return false;
		proxy->queryPlayerSimpleInformationOk(__username, __insts, __serverId);
		return true;
	}
	case 3: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		Ref<SGE_DBPlayerData> __player = memnew(SGE_DBPlayerData);
		if (!__player->deserialize(r)) return false;
		proxy->queryPlayerOk(__username, __player);
		return true;
	}
	case 4: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		Ref<SGE_DBPlayerData> __inst = memnew(SGE_DBPlayerData);
		if (!__inst->deserialize(r)) return false;
		int32_t __inDoorId = 0;
		if (!r->readType(__inDoorId)) return false;
		proxy->createPlayerOk(__username, __inst, __inDoorId);
		return true;
	}
	case 5: {
		String __username = "";
		if (!r->readType(__username, 65535)) return false;
		proxy->createPlayerSameName(__username);
		return true;
	}
	case 6: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		Ref<SGE_DBPlayerData> __inst = memnew(SGE_DBPlayerData);
		if (!__inst->deserialize(r)) return false;
		int32_t __where = 0;
		if (!r->readType(__where)) return false;
		proxy->queryPlayerByIdOK(__playername, __inst, __where);
		return true;
	}
	case 7: {
		TypedArray<String> __name;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__name.resize(__len);
			for(int i=0; i<__len; ++i) {
				String __tmp;
				if(!r->readType(__tmp, 65535)) return false;
				__name[i] = __tmp;
			}
		}
		proxy->queryEndlessStairAllDateOK(__name);
		return true;
	}
	case 8: {
		TypedArray<COM_ContactInfo> __info;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__info.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__info[i] = __elem;
			}
		}
		proxy->queryPlayerByLevelOK(__info);
		return true;
	}
	case 9: {
		TypedArray<COM_ContactInfo> __info;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__info.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_ContactInfo> __elem = memnew(COM_ContactInfo);
				if(!__elem->deserialize(r)) return false;
				__info[i] = __elem;
			}
		}
		proxy->queryPlayerByFFOK(__info);
		return true;
	}
	case 10: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		bool __isToStorage = false;
		if (!r->readType(__isToStorage)) return false;
		proxy->createBabyOK(__playername, __inst, __isToStorage);
		return true;
	}
	case 11: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		int32_t __babyInstId = 0;
		if (!r->readType(__babyInstId)) return false;
		proxy->deleteBabyOK(__playername, __babyInstId);
		return true;
	}
	case 12: {
		TypedArray<COM_BabyRankData> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_BabyRankData> __elem = memnew(COM_BabyRankData);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->queryBabyByFFOK(__infos);
		return true;
	}
	case 13: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		Ref<COM_BabyInst> __inst = memnew(COM_BabyInst);
		if (!__inst->deserialize(r)) return false;
		proxy->queryBabyByIdOK(__name, __inst);
		return true;
	}
	case 14: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		proxy->UpdateBabysOK(__playername);
		return true;
	}
	case 15: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		Ref<COM_EmployeeInst> __inst = memnew(COM_EmployeeInst);
		if (!__inst->deserialize(r)) return false;
		proxy->createEmployeeOK(__playername, __inst);
		return true;
	}
	case 16: {
		String __playername = "";
		if (!r->readType(__playername, 65535)) return false;
		TypedArray<uint32_t> __instIds;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__instIds.resize(__len);
			for(int i=0; i<__len; ++i) {
				uint32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__instIds[i] = __tmp;
			}
		}
		proxy->deleteEmployeeOK(__playername, __instIds);
		return true;
	}
	case 17: {
		TypedArray<COM_EmployeeRankData> __infos;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__infos.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_EmployeeRankData> __elem = memnew(COM_EmployeeRankData);
				if(!__elem->deserialize(r)) return false;
				__infos[i] = __elem;
			}
		}
		proxy->queryEmployeeByFFOK(__infos);
		return true;
	}
	case 18: {
		String __name = "";
		if (!r->readType(__name, 65535)) return false;
		Ref<COM_EmployeeInst> __inst = memnew(COM_EmployeeInst);
		if (!__inst->deserialize(r)) return false;
		proxy->queryEmployeeByIdOK(__name, __inst);
		return true;
	}
	case 19: {
		String __playerName = "";
		if (!r->readType(__playerName, 65535)) return false;
		TypedArray<COM_Mail> __mails;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__mails.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Mail> __elem = memnew(COM_Mail);
				if(!__elem->deserialize(r)) return false;
				__mails[i] = __elem;
			}
		}
		proxy->appendMail(__playerName, __mails);
		return true;
	}
	case 20: {
		Ref<COM_Guild> __guild = memnew(COM_Guild);
		if (!__guild->deserialize(r)) return false;
		Ref<COM_GuildMember> __guildMember = memnew(COM_GuildMember);
		if (!__guildMember->deserialize(r)) return false;
		proxy->insertGuildOK(__guild, __guildMember);
		return true;
	}
	case 21: {
		int32_t __roleId = 0;
		if (!r->readType(__roleId)) return false;
		uint16_t __job = (GuildJob)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 7) return false; __job = (uint16_t)__e; }
		proxy->updateMemberJobOk(__roleId, __job);
		return true;
	}
	case 22: {
		TypedArray<COM_Guild> __guilds;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__guilds.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_Guild> __elem = memnew(COM_Guild);
				if(!__elem->deserialize(r)) return false;
				__guilds[i] = __elem;
			}
		}
		proxy->syncGuild(__guilds);
		return true;
	}
	case 23: {
		TypedArray<COM_GuildMember> __guildMember;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__guildMember.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_GuildMember> __elem = memnew(COM_GuildMember);
				if(!__elem->deserialize(r)) return false;
				__guildMember[i] = __elem;
			}
		}
		proxy->syncGuildMember(__guildMember);
		return true;
	}
	case 24: {
		Ref<SGE_SysActivity> __date = memnew(SGE_SysActivity);
		if (!__date->deserialize(r)) return false;
		proxy->fatchActivity(__date);
		return true;
	}
	case 25: {
		TypedArray<SGE_PlayerEmployeeQuest> __info;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__info.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<SGE_PlayerEmployeeQuest> __elem = memnew(SGE_PlayerEmployeeQuest);
				if(!__elem->deserialize(r)) return false;
				__info[i] = __elem;
			}
		}
		proxy->syncEmployeeQuest(__info);
		return true;
	}
	}
	return false;
}

bool SGE_Scene2World_Dispatcher::dispatch(ProtocolReader* r, SGE_Scene2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	}
	return false;
}

void SGE_World2Scene_Stub::initDynamicNpcs(uint16_t type, int32_t count) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(count);
	methodEnd();
}

void SGE_World2Scene_Stub::refreshDynamicNpcs(uint16_t type, int32_t count) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	__writer->writeType(count);
	methodEnd();
}

void SGE_World2Scene_Stub::finiDynamicNpcs(uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void SGE_World2Scene_Stub::addDynamicNpcs(int32_t sceneId, TypedArray<int32_t> npcs) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	__writer->writeDynSize(npcs.size());
	for(int i=0; i<npcs.size(); ++i) {
		int32_t __tmp = npcs[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_World2Scene_Stub::delDynamicNpc(int32_t npcId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(npcId);
	methodEnd();
}

void SGE_World2Scene_Stub::delDynamicNpc2(int32_t sceneId, int32_t npcId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	__writer->writeType(npcId);
	methodEnd();
}

void SGE_World2Scene_Stub::openSceneCopy(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

void SGE_World2Scene_Stub::closeSceneCopy(int32_t instId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	__writer->writeType(instId);
	methodEnd();
}

bool SGE_World2Scene_Dispatcher::dispatch(ProtocolReader* r, SGE_World2Scene_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		uint16_t __type = (NpcType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 11) return false; __type = (uint16_t)__e; }
		int32_t __count = 0;
		if (!r->readType(__count)) return false;
		proxy->initDynamicNpcs(__type, __count);
		return true;
	}
	case 1: {
		uint16_t __type = (NpcType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 11) return false; __type = (uint16_t)__e; }
		int32_t __count = 0;
		if (!r->readType(__count)) return false;
		proxy->refreshDynamicNpcs(__type, __count);
		return true;
	}
	case 2: {
		uint16_t __type = (NpcType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 11) return false; __type = (uint16_t)__e; }
		proxy->finiDynamicNpcs(__type);
		return true;
	}
	case 3: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		TypedArray<int32_t> __npcs;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__npcs.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__npcs[i] = __tmp;
			}
		}
		proxy->addDynamicNpcs(__sceneId, __npcs);
		return true;
	}
	case 4: {
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		proxy->delDynamicNpc(__npcId);
		return true;
	}
	case 5: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		proxy->delDynamicNpc2(__sceneId, __npcId);
		return true;
	}
	case 6: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->openSceneCopy(__instId);
		return true;
	}
	case 7: {
		int32_t __instId = 0;
		if (!r->readType(__instId)) return false;
		proxy->closeSceneCopy(__instId);
		return true;
	}
	}
	return false;
}

void SGE_Player_Scene2World_Stub::joinScene(Ref<COM_SceneInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(COM_SceneInfo);
	info->serialize(__writer);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::move2(Ref<COM_FPosition> pos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	if (pos.is_null()) pos = memnew(COM_FPosition);
	pos->serialize(__writer);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::cantMove() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::transfor2(Ref<COM_FPosition> pos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	if (pos.is_null()) pos = memnew(COM_FPosition);
	pos->serialize(__writer);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::autoBattleResult(bool isOk) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(isOk);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::zoneJoinBattle(int32_t zoneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(zoneId);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::playerAddNpc(TypedArray<int32_t> npcs) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeDynSize(npcs.size());
	for(int i=0; i<npcs.size(); ++i) {
		int32_t __tmp = npcs[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_Player_Scene2World_Stub::playerDelNpc(TypedArray<int32_t> npcs) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	__writer->writeDynSize(npcs.size());
	for(int i=0; i<npcs.size(); ++i) {
		int32_t __tmp = npcs[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_Player_Scene2World_Stub::talkedNpc(int32_t npcid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	__writer->writeType(npcid);
	methodEnd();
}

void SGE_Player_Scene2World_Stub::findDynamicNpcOK(int32_t npcid, bool hasnpc) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	__writer->writeType(npcid);
	__writer->writeType(hasnpc);
	methodEnd();
}

bool SGE_Player_Scene2World_Dispatcher::dispatch(ProtocolReader* r, SGE_Player_Scene2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		Ref<COM_SceneInfo> __info = memnew(COM_SceneInfo);
		if (!__info->deserialize(r)) return false;
		proxy->joinScene(__info);
		return true;
	}
	case 1: {
		Ref<COM_FPosition> __pos = memnew(COM_FPosition);
		if (!__pos->deserialize(r)) return false;
		proxy->move2(__pos);
		return true;
	}
	case 2: {
		proxy->cantMove();
		return true;
	}
	case 3: {
		Ref<COM_FPosition> __pos = memnew(COM_FPosition);
		if (!__pos->deserialize(r)) return false;
		proxy->transfor2(__pos);
		return true;
	}
	case 4: {
		bool __isOk = false;
		if (!r->readType(__isOk)) return false;
		proxy->autoBattleResult(__isOk);
		return true;
	}
	case 5: {
		int32_t __zoneId = 0;
		if (!r->readType(__zoneId)) return false;
		proxy->zoneJoinBattle(__zoneId);
		return true;
	}
	case 6: {
		TypedArray<int32_t> __npcs;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__npcs.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__npcs[i] = __tmp;
			}
		}
		proxy->playerAddNpc(__npcs);
		return true;
	}
	case 7: {
		TypedArray<int32_t> __npcs;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__npcs.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__npcs[i] = __tmp;
			}
		}
		proxy->playerDelNpc(__npcs);
		return true;
	}
	case 8: {
		int32_t __npcid = 0;
		if (!r->readType(__npcid)) return false;
		proxy->talkedNpc(__npcid);
		return true;
	}
	case 9: {
		int32_t __npcid = 0;
		if (!r->readType(__npcid)) return false;
		bool __hasnpc = false;
		if (!r->readType(__hasnpc)) return false;
		proxy->findDynamicNpcOK(__npcid, __hasnpc);
		return true;
	}
	}
	return false;
}

void SGE_Player_World2Scene_Stub::initScenePlayer(Ref<SGE_ScenePlayerInfo> info) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	if (info.is_null()) info = memnew(SGE_ScenePlayerInfo);
	info->serialize(__writer);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::scenePlayerUpLevel(int32_t level) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(level);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::scenePlayerAddCurrentQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::scenePlayerDelCurrentQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::scenePlayerAddAcceptableQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::scenePlayerDelAcceptableQuest(int32_t questId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(questId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::openScene(int32_t sceneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::joinBattle() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::finishBattle() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::transforScene(int32_t sceneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::transforSceneByEntry(int32_t sceneId, int32_t entryId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 10;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	__writer->writeType(entryId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::backHomeScene() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 11;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::sceneLoaded() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 12;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::move(Ref<COM_FPosition> pos) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 13;
	__writer->writeType(__pid);
	if (pos.is_null()) pos = memnew(COM_FPosition);
	pos->serialize(__writer);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::moveToNpc(int32_t npcid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 14;
	__writer->writeType(__pid);
	__writer->writeType(npcid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::moveToNpc2(uint16_t type) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 15;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)type);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::moveToZone(int32_t sceneId, int32_t zoneId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 16;
	__writer->writeType(__pid);
	__writer->writeType(sceneId);
	__writer->writeType(zoneId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::autoBattle() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 17;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::stopMove() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 18;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::addFollow(int32_t scenePlayerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 19;
	__writer->writeType(__pid);
	__writer->writeType(scenePlayerId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::delFollow(int32_t scenePlayerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 20;
	__writer->writeType(__pid);
	__writer->writeType(scenePlayerId);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::delFollows() {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 21;
	__writer->writeType(__pid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::addFollows(TypedArray<int32_t> scenePlayers) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 22;
	__writer->writeType(__pid);
	__writer->writeDynSize(scenePlayers.size());
	for(int i=0; i<scenePlayers.size(); ++i) {
		int32_t __tmp = scenePlayers[i];
		__writer->writeType(__tmp);
	}
	methodEnd();
}

void SGE_Player_World2Scene_Stub::setEntryFlag(int32_t scenePlayerId, bool isFlag) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 23;
	__writer->writeType(__pid);
	__writer->writeType(scenePlayerId);
	__writer->writeType(isFlag);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::addNpc(int32_t npcid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 24;
	__writer->writeType(__pid);
	__writer->writeType(npcid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::delNpc(int32_t npcid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 25;
	__writer->writeType(__pid);
	__writer->writeType(npcid);
	methodEnd();
}

void SGE_Player_World2Scene_Stub::findDynamicNpc(int32_t npcId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 26;
	__writer->writeType(__pid);
	__writer->writeType(npcId);
	methodEnd();
}

bool SGE_Player_World2Scene_Dispatcher::dispatch(ProtocolReader* r, SGE_Player_World2Scene_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		Ref<SGE_ScenePlayerInfo> __info = memnew(SGE_ScenePlayerInfo);
		if (!__info->deserialize(r)) return false;
		proxy->initScenePlayer(__info);
		return true;
	}
	case 1: {
		int32_t __level = 0;
		if (!r->readType(__level)) return false;
		proxy->scenePlayerUpLevel(__level);
		return true;
	}
	case 2: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->scenePlayerAddCurrentQuest(__questId);
		return true;
	}
	case 3: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->scenePlayerDelCurrentQuest(__questId);
		return true;
	}
	case 4: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->scenePlayerAddAcceptableQuest(__questId);
		return true;
	}
	case 5: {
		int32_t __questId = 0;
		if (!r->readType(__questId)) return false;
		proxy->scenePlayerDelAcceptableQuest(__questId);
		return true;
	}
	case 6: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		proxy->openScene(__sceneId);
		return true;
	}
	case 7: {
		proxy->joinBattle();
		return true;
	}
	case 8: {
		proxy->finishBattle();
		return true;
	}
	case 9: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		proxy->transforScene(__sceneId);
		return true;
	}
	case 10: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		int32_t __entryId = 0;
		if (!r->readType(__entryId)) return false;
		proxy->transforSceneByEntry(__sceneId, __entryId);
		return true;
	}
	case 11: {
		proxy->backHomeScene();
		return true;
	}
	case 12: {
		proxy->sceneLoaded();
		return true;
	}
	case 13: {
		Ref<COM_FPosition> __pos = memnew(COM_FPosition);
		if (!__pos->deserialize(r)) return false;
		proxy->move(__pos);
		return true;
	}
	case 14: {
		int32_t __npcid = 0;
		if (!r->readType(__npcid)) return false;
		proxy->moveToNpc(__npcid);
		return true;
	}
	case 15: {
		uint16_t __type = (NpcType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 11) return false; __type = (uint16_t)__e; }
		proxy->moveToNpc2(__type);
		return true;
	}
	case 16: {
		int32_t __sceneId = 0;
		if (!r->readType(__sceneId)) return false;
		int32_t __zoneId = 0;
		if (!r->readType(__zoneId)) return false;
		proxy->moveToZone(__sceneId, __zoneId);
		return true;
	}
	case 17: {
		proxy->autoBattle();
		return true;
	}
	case 18: {
		proxy->stopMove();
		return true;
	}
	case 19: {
		int32_t __scenePlayerId = 0;
		if (!r->readType(__scenePlayerId)) return false;
		proxy->addFollow(__scenePlayerId);
		return true;
	}
	case 20: {
		int32_t __scenePlayerId = 0;
		if (!r->readType(__scenePlayerId)) return false;
		proxy->delFollow(__scenePlayerId);
		return true;
	}
	case 21: {
		proxy->delFollows();
		return true;
	}
	case 22: {
		TypedArray<int32_t> __scenePlayers;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__scenePlayers.resize(__len);
			for(int i=0; i<__len; ++i) {
				int32_t __tmp;
				if(!r->readType(__tmp)) return false;
				__scenePlayers[i] = __tmp;
			}
		}
		proxy->addFollows(__scenePlayers);
		return true;
	}
	case 23: {
		int32_t __scenePlayerId = 0;
		if (!r->readType(__scenePlayerId)) return false;
		bool __isFlag = false;
		if (!r->readType(__isFlag)) return false;
		proxy->setEntryFlag(__scenePlayerId, __isFlag);
		return true;
	}
	case 24: {
		int32_t __npcid = 0;
		if (!r->readType(__npcid)) return false;
		proxy->addNpc(__npcid);
		return true;
	}
	case 25: {
		int32_t __npcid = 0;
		if (!r->readType(__npcid)) return false;
		proxy->delNpc(__npcid);
		return true;
	}
	case 26: {
		int32_t __npcId = 0;
		if (!r->readType(__npcId)) return false;
		proxy->findDynamicNpc(__npcId);
		return true;
	}
	}
	return false;
}

bool SGE_World2GMT_Dispatcher::dispatch(ProtocolReader* r, SGE_World2GMT_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	}
	return false;
}

void SGE_GMT2World_Stub::addExp(uint32_t playerId, uint32_t exp) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(exp);
	methodEnd();
}

void SGE_GMT2World_Stub::addMoney(uint32_t playerId, int32_t money) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(money);
	methodEnd();
}

void SGE_GMT2World_Stub::addDiamond(uint32_t playerId, int32_t diamond) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(diamond);
	methodEnd();
}

void SGE_GMT2World_Stub::openGM(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_GMT2World_Stub::closeGM(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_GMT2World_Stub::noTalkPlayer(uint32_t playerId, uint32_t time) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(time);
	methodEnd();
}

void SGE_GMT2World_Stub::sealPlayer(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_GMT2World_Stub::kickPlayer(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 7;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_GMT2World_Stub::openTalkPlayer(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 8;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_GMT2World_Stub::unsealPlayer(uint32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 9;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_GMT2World_Stub::sendMailAllOnline(Ref<COM_Mail> mail, int32_t lowLevel, int32_t highLevel, int64_t lowRegTime, int64_t highRegTime) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 10;
	__writer->writeType(__pid);
	if (mail.is_null()) mail = memnew(COM_Mail);
	mail->serialize(__writer);
	__writer->writeType(lowLevel);
	__writer->writeType(highLevel);
	__writer->writeType(lowRegTime);
	__writer->writeType(highRegTime);
	methodEnd();
}

void SGE_GMT2World_Stub::gmtNotice(uint16_t bType, String note, uint64_t thetime, int64_t itvtime) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 11;
	__writer->writeType(__pid);
	__writer->writeType((uint16_t)bType);
	__writer->writeType(note);
	__writer->writeType(thetime);
	__writer->writeType(itvtime);
	methodEnd();
}

void SGE_GMT2World_Stub::setChargeTotal(Ref<COM_ADChargeTotal> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 12;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADChargeTotal);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setChargeEvery(Ref<COM_ADChargeEvery> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 13;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADChargeEvery);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setDiscountStore(Ref<COM_ADDiscountStore> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 14;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADDiscountStore);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setLoginTotal(Ref<COM_ADLoginTotal> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 15;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADLoginTotal);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setHotRole(Ref<COM_ADHotRole> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 16;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADHotRole);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setEmployeeActivity(Ref<COM_ADEmployeeTotal> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 17;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADEmployeeTotal);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setMinGiftBagActivity(Ref<COM_ADGiftBag> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 18;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ADGiftBag);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setZhuanpanActivity(Ref<COM_ZhuanpanData> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 19;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_ZhuanpanData);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::setIntegralshop(Ref<COM_IntegralData> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 20;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(COM_IntegralData);
	data->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::makeOrder(uint32_t playerId, Ref<SGE_GmtOrder> order) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 21;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	if (order.is_null()) order = memnew(SGE_GmtOrder);
	order->serialize(__writer);
	methodEnd();
}

void SGE_GMT2World_Stub::doScript(String script) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 22;
	__writer->writeType(__pid);
	__writer->writeType(script);
	methodEnd();
}

void SGE_GMT2World_Stub::playerDoScript(uint32_t playerId, String script) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 23;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeType(script);
	methodEnd();
}

bool SGE_GMT2World_Dispatcher::dispatch(ProtocolReader* r, SGE_GMT2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		uint32_t __exp = 0;
		if (!r->readType(__exp)) return false;
		proxy->addExp(__playerId, __exp);
		return true;
	}
	case 1: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		int32_t __money = 0;
		if (!r->readType(__money)) return false;
		proxy->addMoney(__playerId, __money);
		return true;
	}
	case 2: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		int32_t __diamond = 0;
		if (!r->readType(__diamond)) return false;
		proxy->addDiamond(__playerId, __diamond);
		return true;
	}
	case 3: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->openGM(__playerId);
		return true;
	}
	case 4: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->closeGM(__playerId);
		return true;
	}
	case 5: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		uint32_t __time = 0;
		if (!r->readType(__time)) return false;
		proxy->noTalkPlayer(__playerId, __time);
		return true;
	}
	case 6: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->sealPlayer(__playerId);
		return true;
	}
	case 7: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->kickPlayer(__playerId);
		return true;
	}
	case 8: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->openTalkPlayer(__playerId);
		return true;
	}
	case 9: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->unsealPlayer(__playerId);
		return true;
	}
	case 10: {
		Ref<COM_Mail> __mail = memnew(COM_Mail);
		if (!__mail->deserialize(r)) return false;
		int32_t __lowLevel = 0;
		if (!r->readType(__lowLevel)) return false;
		int32_t __highLevel = 0;
		if (!r->readType(__highLevel)) return false;
		int64_t __lowRegTime = 0;
		if (!r->readType(__lowRegTime)) return false;
		int64_t __highRegTime = 0;
		if (!r->readType(__highRegTime)) return false;
		proxy->sendMailAllOnline(__mail, __lowLevel, __highLevel, __lowRegTime, __highRegTime);
		return true;
	}
	case 11: {
		uint16_t __bType = (NoticeSendType)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 3) return false; __bType = (uint16_t)__e; }
		String __note = "";
		if (!r->readType(__note, 65535)) return false;
		uint64_t __thetime = 0;
		if (!r->readType(__thetime)) return false;
		int64_t __itvtime = 0;
		if (!r->readType(__itvtime)) return false;
		proxy->gmtNotice(__bType, __note, __thetime, __itvtime);
		return true;
	}
	case 12: {
		Ref<COM_ADChargeTotal> __data = memnew(COM_ADChargeTotal);
		if (!__data->deserialize(r)) return false;
		proxy->setChargeTotal(__data);
		return true;
	}
	case 13: {
		Ref<COM_ADChargeEvery> __data = memnew(COM_ADChargeEvery);
		if (!__data->deserialize(r)) return false;
		proxy->setChargeEvery(__data);
		return true;
	}
	case 14: {
		Ref<COM_ADDiscountStore> __data = memnew(COM_ADDiscountStore);
		if (!__data->deserialize(r)) return false;
		proxy->setDiscountStore(__data);
		return true;
	}
	case 15: {
		Ref<COM_ADLoginTotal> __data = memnew(COM_ADLoginTotal);
		if (!__data->deserialize(r)) return false;
		proxy->setLoginTotal(__data);
		return true;
	}
	case 16: {
		Ref<COM_ADHotRole> __data = memnew(COM_ADHotRole);
		if (!__data->deserialize(r)) return false;
		proxy->setHotRole(__data);
		return true;
	}
	case 17: {
		Ref<COM_ADEmployeeTotal> __data = memnew(COM_ADEmployeeTotal);
		if (!__data->deserialize(r)) return false;
		proxy->setEmployeeActivity(__data);
		return true;
	}
	case 18: {
		Ref<COM_ADGiftBag> __data = memnew(COM_ADGiftBag);
		if (!__data->deserialize(r)) return false;
		proxy->setMinGiftBagActivity(__data);
		return true;
	}
	case 19: {
		Ref<COM_ZhuanpanData> __data = memnew(COM_ZhuanpanData);
		if (!__data->deserialize(r)) return false;
		proxy->setZhuanpanActivity(__data);
		return true;
	}
	case 20: {
		Ref<COM_IntegralData> __data = memnew(COM_IntegralData);
		if (!__data->deserialize(r)) return false;
		proxy->setIntegralshop(__data);
		return true;
	}
	case 21: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		Ref<SGE_GmtOrder> __order = memnew(SGE_GmtOrder);
		if (!__order->deserialize(r)) return false;
		proxy->makeOrder(__playerId, __order);
		return true;
	}
	case 22: {
		String __script = "";
		if (!r->readType(__script, 65535)) return false;
		proxy->doScript(__script);
		return true;
	}
	case 23: {
		uint32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		String __script = "";
		if (!r->readType(__script, 65535)) return false;
		proxy->playerDoScript(__playerId, __script);
		return true;
	}
	}
	return false;
}

void SGE_World2Mall_Stub::fetchSell(int32_t playerid, Ref<COM_SearchContext> context) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	if (context.is_null()) context = memnew(COM_SearchContext);
	context->serialize(__writer);
	methodEnd();
}

void SGE_World2Mall_Stub::fetchMySell(int32_t playerid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	methodEnd();
}

void SGE_World2Mall_Stub::fetchSelledItem(int32_t playerId) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	methodEnd();
}

void SGE_World2Mall_Stub::sell(Ref<COM_SellItem> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_SellItem);
	item->serialize(__writer);
	methodEnd();
}

void SGE_World2Mall_Stub::unSell(int32_t playerid, int32_t sellid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	__writer->writeType(sellid);
	methodEnd();
}

void SGE_World2Mall_Stub::buy(Ref<SGE_BuyContent> content) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	if (content.is_null()) content = memnew(SGE_BuyContent);
	content->serialize(__writer);
	methodEnd();
}

void SGE_World2Mall_Stub::insertSelledItem(Ref<COM_SelledItem> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	if (item.is_null()) item = memnew(COM_SelledItem);
	item->serialize(__writer);
	methodEnd();
}

bool SGE_World2Mall_Dispatcher::dispatch(ProtocolReader* r, SGE_World2Mall_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		Ref<COM_SearchContext> __context = memnew(COM_SearchContext);
		if (!__context->deserialize(r)) return false;
		proxy->fetchSell(__playerid, __context);
		return true;
	}
	case 1: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		proxy->fetchMySell(__playerid);
		return true;
	}
	case 2: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		proxy->fetchSelledItem(__playerId);
		return true;
	}
	case 3: {
		Ref<COM_SellItem> __item = memnew(COM_SellItem);
		if (!__item->deserialize(r)) return false;
		proxy->sell(__item);
		return true;
	}
	case 4: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		int32_t __sellid = 0;
		if (!r->readType(__sellid)) return false;
		proxy->unSell(__playerid, __sellid);
		return true;
	}
	case 5: {
		Ref<SGE_BuyContent> __content = memnew(SGE_BuyContent);
		if (!__content->deserialize(r)) return false;
		proxy->buy(__content);
		return true;
	}
	case 6: {
		Ref<COM_SelledItem> __item = memnew(COM_SelledItem);
		if (!__item->deserialize(r)) return false;
		proxy->insertSelledItem(__item);
		return true;
	}
	}
	return false;
}

void SGE_Mall2World_Stub::fetchSellOk(int32_t playerid, TypedArray<COM_SellItem> items, int32_t totalSize) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SellItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SellItem);
		__elem->serialize(__writer);
	}
	__writer->writeType(totalSize);
	methodEnd();
}

void SGE_Mall2World_Stub::fetchMySellOk(int32_t playerid, TypedArray<COM_SellItem> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SellItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SellItem);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_Mall2World_Stub::fetchSelledItemOk(int32_t playerId, TypedArray<COM_SelledItem> items) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	__writer->writeType(playerId);
	__writer->writeDynSize(items.size());
	for(int i=0; i<items.size(); ++i) {
		Ref<COM_SelledItem> __elem = items[i];
		if (__elem.is_null()) __elem = memnew(COM_SelledItem);
		__elem->serialize(__writer);
	}
	methodEnd();
}

void SGE_Mall2World_Stub::sellOk(int32_t playerid, Ref<COM_SellItem> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	if (item.is_null()) item = memnew(COM_SellItem);
	item->serialize(__writer);
	methodEnd();
}

void SGE_Mall2World_Stub::unSellOk(int32_t playerid, int32_t sellid) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	__writer->writeType(sellid);
	methodEnd();
}

void SGE_Mall2World_Stub::buyOk(int32_t playerid, Ref<COM_SellItem> item) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	if (item.is_null()) item = memnew(COM_SellItem);
	item->serialize(__writer);
	methodEnd();
}

void SGE_Mall2World_Stub::buyFail(int32_t playerid, uint16_t errorno) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	__writer->writeType(playerid);
	__writer->writeType((uint16_t)errorno);
	methodEnd();
}

bool SGE_Mall2World_Dispatcher::dispatch(ProtocolReader* r, SGE_Mall2World_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		TypedArray<COM_SellItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SellItem> __elem = memnew(COM_SellItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		int32_t __totalSize = 0;
		if (!r->readType(__totalSize)) return false;
		proxy->fetchSellOk(__playerid, __items, __totalSize);
		return true;
	}
	case 1: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		TypedArray<COM_SellItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SellItem> __elem = memnew(COM_SellItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->fetchMySellOk(__playerid, __items);
		return true;
	}
	case 2: {
		int32_t __playerId = 0;
		if (!r->readType(__playerId)) return false;
		TypedArray<COM_SelledItem> __items;
		{
			uint32_t __len; if(!r->readDynSize(__len)) return false;
			if(__len > 65535) return false;
			__items.resize(__len);
			for(int i=0; i<__len; ++i) {
				Ref<COM_SelledItem> __elem = memnew(COM_SelledItem);
				if(!__elem->deserialize(r)) return false;
				__items[i] = __elem;
			}
		}
		proxy->fetchSelledItemOk(__playerId, __items);
		return true;
	}
	case 3: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		Ref<COM_SellItem> __item = memnew(COM_SellItem);
		if (!__item->deserialize(r)) return false;
		proxy->sellOk(__playerid, __item);
		return true;
	}
	case 4: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		int32_t __sellid = 0;
		if (!r->readType(__sellid)) return false;
		proxy->unSellOk(__playerid, __sellid);
		return true;
	}
	case 5: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		Ref<COM_SellItem> __item = memnew(COM_SellItem);
		if (!__item->deserialize(r)) return false;
		proxy->buyOk(__playerid, __item);
		return true;
	}
	case 6: {
		int32_t __playerid = 0;
		if (!r->readType(__playerid)) return false;
		uint16_t __errorno = (ErrorNo)0;
		{ uint16_t __e; if(!r->readType(__e) || __e >= 158) return false; __errorno = (uint16_t)__e; }
		proxy->buyFail(__playerid, __errorno);
		return true;
	}
	}
	return false;
}

void Backlog_Stub::log(String key, String msg, String stack, String version) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	__writer->writeType(key);
	__writer->writeType(msg);
	__writer->writeType(stack);
	__writer->writeType(version);
	methodEnd();
}

bool Backlog_Dispatcher::dispatch(ProtocolReader* r, Backlog_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		String __key = "";
		if (!r->readType(__key, 65535)) return false;
		String __msg = "";
		if (!r->readType(__msg, 65535)) return false;
		String __stack = "";
		if (!r->readType(__stack, 65535)) return false;
		String __version = "";
		if (!r->readType(__version, 65535)) return false;
		proxy->log(__key, __msg, __stack, __version);
		return true;
	}
	}
	return false;
}

void SGE_Log_Stub::account(Ref<SGE_Account> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 0;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(SGE_Account);
	data->serialize(__writer);
	methodEnd();
}

void SGE_Log_Stub::login(Ref<SGE_Login> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 1;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(SGE_Login);
	data->serialize(__writer);
	methodEnd();
}

void SGE_Log_Stub::order(Ref<SGE_Order> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 2;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(SGE_Order);
	data->serialize(__writer);
	methodEnd();
}

void SGE_Log_Stub::role(Ref<SGE_LogRole> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 3;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(SGE_LogRole);
	data->serialize(__writer);
	methodEnd();
}

void SGE_Log_Stub::playersay(uint32_t senderId, String senderName, Ref<COM_Chat> chat) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 4;
	__writer->writeType(__pid);
	__writer->writeType(senderId);
	__writer->writeType(senderName);
	if (chat.is_null()) chat = memnew(COM_Chat);
	chat->serialize(__writer);
	methodEnd();
}

void SGE_Log_Stub::playerTrack(Ref<SGE_LogProduceTrack> data) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 5;
	__writer->writeType(__pid);
	if (data.is_null()) data = memnew(SGE_LogProduceTrack);
	data->serialize(__writer);
	methodEnd();
}

void SGE_Log_Stub::playerUIBehavior(Ref<SGE_LogUIBehavior> core) {
	ProtocolWriter* __writer = methodBegin();
	if(!__writer) return;
	uint16_t __pid = 6;
	__writer->writeType(__pid);
	if (core.is_null()) core = memnew(SGE_LogUIBehavior);
	core->serialize(__writer);
	methodEnd();
}

bool SGE_Log_Dispatcher::dispatch(ProtocolReader* r, SGE_Log_Proxy* proxy) {
	uint16_t __pid;
	if (!r->readType(__pid)) return false;
	switch (__pid) {
	case 0: {
		Ref<SGE_Account> __data = memnew(SGE_Account);
		if (!__data->deserialize(r)) return false;
		proxy->account(__data);
		return true;
	}
	case 1: {
		Ref<SGE_Login> __data = memnew(SGE_Login);
		if (!__data->deserialize(r)) return false;
		proxy->login(__data);
		return true;
	}
	case 2: {
		Ref<SGE_Order> __data = memnew(SGE_Order);
		if (!__data->deserialize(r)) return false;
		proxy->order(__data);
		return true;
	}
	case 3: {
		Ref<SGE_LogRole> __data = memnew(SGE_LogRole);
		if (!__data->deserialize(r)) return false;
		proxy->role(__data);
		return true;
	}
	case 4: {
		uint32_t __senderId = 0;
		if (!r->readType(__senderId)) return false;
		String __senderName = "";
		if (!r->readType(__senderName, 65535)) return false;
		Ref<COM_Chat> __chat = memnew(COM_Chat);
		if (!__chat->deserialize(r)) return false;
		proxy->playersay(__senderId, __senderName, __chat);
		return true;
	}
	case 5: {
		Ref<SGE_LogProduceTrack> __data = memnew(SGE_LogProduceTrack);
		if (!__data->deserialize(r)) return false;
		proxy->playerTrack(__data);
		return true;
	}
	case 6: {
		Ref<SGE_LogUIBehavior> __core = memnew(SGE_LogUIBehavior);
		if (!__core->deserialize(r)) return false;
		proxy->playerUIBehavior(__core);
		return true;
	}
	}
	return false;
}

