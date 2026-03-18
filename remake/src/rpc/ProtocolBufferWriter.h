#ifndef __GODOT_PROTOCOL_BUFFER_WRITER_H__
#define __GODOT_PROTOCOL_BUFFER_WRITER_H__

#include "ProtocolWriter.h"
#include <godot_cpp/variant/packed_byte_array.hpp>

namespace godot {

/** 基于 PackedByteArray 的 ProtocolWriter 实现 */
class ProtocolBufferWriter : public ProtocolWriter
{
public:
	ProtocolBufferWriter() {}

	virtual void write(const void* data, size_t len) override {
		const uint8_t* ptr = static_cast<const uint8_t*>(data);
		for (size_t i = 0; i < len; ++i) {
			buffer.append(ptr[i]);
		}
	}

	PackedByteArray get_buffer() const { return buffer; }
	void clear() { buffer.clear(); }
	size_t get_length() const { return (size_t)buffer.size(); }

private:
	PackedByteArray buffer;
};

} // namespace godot

#endif
