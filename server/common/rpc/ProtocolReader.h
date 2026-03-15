#ifndef __ProtocolReader_h__
#define __ProtocolReader_h__

#include "Common.h"

/** ARPC通讯协议读取器接口.
	ProtocolReader 为 service proxy 提供arpc通讯协议解编数据读取接口。
	一个 ProtocolReader 可以得到 一个service proxy 在反序列化rpc数据后的读取事件，
	派生类可以重载这个接口，将数据从内存或网络读取出来。
*/
class ProtocolReader
{
public:
	/** 读入rpc序列化数据. 
		proxy在rpc调用过程中通过此接口读取序列化数据.
		@param data 数据指针.
		@param len 数据长度.
	*/
	virtual bool read(void* data, size_t len) = 0;

	/** @name read basic types. */
	//@{
	bool readType(std::int64_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::uint64_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(double& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(float& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::int32_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::uint32_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::int16_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::uint16_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::int8_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(std::uint8_t& v)
	{
		return read(&v, sizeof(v));
	}
	bool readType(bool& v)
	{
		char vv;
		if(!read(&vv, sizeof(vv)))
			return false;
		v = vv?true:false;
		return true;
	}
	bool readType(std::string& v, std::uint32_t maxlen)
	{
		std::uint32_t len;
		if(!readDynSize(len) || len > maxlen)
			return false;
		v.resize(len);
		return read((void*)v.c_str(), len);
	}
	bool readDynSize(std::uint32_t& s)
	{
		s = 0;
		std::uint8_t b;
		if(!readType(b))
			return false;
		std::int32_t n = (b & 0XC0)>>6;
		s = (b & 0X3F);
		for(std::int32_t i = 0; i < n; i++)
		{
			if(!readType(b))
				return false;
			s = (s<<8)|b;
		}
		return true;
	}
	//@}
};


#endif//__ProtocolReader_h__