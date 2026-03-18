#ifndef __GODOT_PROTOCOL_BUFFER_READER_H__
#define __GODOT_PROTOCOL_BUFFER_READER_H__

#include "ProtocolReader.h"
#include <godot_cpp/variant/packed_byte_array.hpp>

namespace godot {

/** 基于 PackedByteArray 的 ProtocolReader 实现 */
class ProtocolBufferReader : public ProtocolReader
{
public:
	ProtocolBufferReader(const PackedByteArray& p_buffer) : 
		buffer(p_buffer), 
		cursor(0) 
	{}

	virtual bool read(void* data, size_t len) override {
		if (cursor + len > (size_t)buffer.size()) {
			return false;
		}
		const uint8_t* ptr = buffer.ptr();
		memcpy(data, ptr + cursor, len);
		cursor += len;
		return true;
	}

	size_t get_cursor() const { return cursor; }
	void set_cursor(size_t p_pos) { cursor = p_pos; }
	size_t get_length() const { return (size_t)buffer.size(); }

private:
	PackedByteArray buffer;
	size_t cursor;
};

} // namespace godot

#endif
