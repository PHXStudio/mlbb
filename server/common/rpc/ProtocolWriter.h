#ifndef __ProtocolWriter_h__
#define __ProtocolWriter_h__

#include "Common.h"

/** ARPC通讯协议写入器接口.
	ProtocolWriter 为生成的service stub提供arpc协议整编数据写入接口。
	一个 ProtocolWriter 可以得到 一个service stub 在序列化rpc数据后的写入事件，
	派生类可以重载这个接口，将数据写入到内存或直接写入网络。
*/
class ProtocolWriter
{
public:
	/** 写入rpc序列化数据. 
		stub在rpc调用过程中通过此接口写入序列化数据.
		@param data 数据指针.
		@param len 数据长度.
	*/
	virtual void write(const void* data, size_t len) = 0;

	/** @name write basic types. */
	//@{
	void writeType(std::int64_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::uint64_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(double v)
	{
		write(&v, sizeof(v));
	}
	void writeType(float v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::int32_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::uint32_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::int16_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::uint16_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::int8_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(std::uint8_t v)
	{
		write(&v, sizeof(v));
	}
	void writeType(bool v)
	{
		char vv = v?1:0;
		write(&vv, sizeof(vv));
	}
	void writeType(const std::string& v)
	{
		std::uint32_t len = static_cast<std::uint32_t>(v.length());
		writeDynSize(len);
		write(v.c_str(), v.length());
	}
	void writeDynSize(std::uint32_t s)
	{
		std::uint8_t* p = reinterpret_cast<std::uint8_t*>(&s);
		std::uint8_t n = 0;
		if(s <= 0X3F)
			n = 0;
		else if(s <= 0X3FFF)
			n = 1;
		else if(s <= 0X3FFFFF)
			n = 2;
		else if(s <= 0X3FFFFFFF)
			n = 3;
		p[n] |= (n<<6);
		for(std::int32_t i = static_cast<std::int32_t>(n); i >= 0; i--)
			writeType(p[i]);
	}
	//@}
};



#endif//__ProtocolWriter_h__