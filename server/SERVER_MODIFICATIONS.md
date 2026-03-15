# Server 修改说明（参考文档）

本文档总结对 `server/` 目录下代码的修改，便于后续查阅与维护。

---

## 1. 类型系统统一（核心改动）

- **RPC 与协议层**（`common/rpc/`）改为使用 C++ 标准固定宽度类型，不再依赖项目内自定义别名：
  - `S64/U64, S32/U32, S16/U16, S8/U8` → `std::int64_t` / `std::uint64_t`、`std::int32_t` / `std::uint32_t` 等
  - `F64/F32` → `double` / `float`
  - `B8` → `bool`
  - `STRING` → `std::string`
- **生成代码**（`common/gen_rpc/`）里所有接口和结构体参数的类型做了同样替换（如 `Client2ServerMethods.h`、`Server2ClientMethods.h`、`com.h`、`proto.*`、`struct.*` 等），例如：
  - `U32 playerInstId` → `uint32_t playerInstId`
  - `S32 npcid` → `int32_t npcid`
  - `std::vector<U32>` → `std::vector<uint32_t>`

这样协议读写和生成代码都统一到 `<cstdint>` / 标准类型，便于跨平台和与其它代码对接。

---

## 2. 公共类型定义集中到 config.h

- **`common/config.h`**
  - 增加 `#include <stdint.h>`。
  - 在公共头里集中定义项目内使用的整数别名和宏，例如：
    - `typedef int64_t int64;` 等
    - `#define S64 int64`、`#define U32 uint32` 等（S64/U64/S32/U32/S16/U16/S8/U8、F64/F32、B8、STRING）
  - 这样其它仍用 `S32`、`U32` 等的代码（如 world、gateway）继续用这些宏，而 RPC 层单独用标准类型。
- **`common/rpc/Common.h`**
  - 删除了原先在 Common.h 里对 `int64/uint64/int32/uint32/...` 和 `S64/U64/...` 的重复定义，避免与 config.h 冲突；保留注释和 `#include <cstdint>` 等必要头文件。

---

## 3. SQLite 封装与 config 保持一致

- **`common/CppSQLite3.cpp`**
  - `getInt64Field`、`lastRowId` 等原先使用 `sqlite_int64` 的接口，改为使用项目类型 `S64`（即通过 config.h 的 `S64` 定义与 `int64_t` 一致），与其它模块的类型风格统一。

---

## 4. config.h 的代码风格与头文件顺序

- 宏和模板的格式整理（多行展开、缩进统一），例如：
  - `DB_EXEC_GUARD` / `DB_EXEC_UNGUARD_RETURN`
  - `ACE_REACTOR_MAKE`
  - `ACE_MSG_SET` / `ACE_MSG_GET`
  - `GET_BIT_BOOL` / `SET_BIT_BOOL` / `COMPARE_BIT_BOOL`
  - `XML_GET_ATTRIBUTE_*`、`FUNCTION_PROBE`、`CHUNK_PROBE_*`、`NEW_MEM` / `DEL_MEM`
- Include 顺序调整：先 `Common.h` + `predef.h`，再标准库与 ace、com、proto、struct 等，避免隐式依赖。

---

## 5. 涉及的文件与规模

| 类别           | 文件 |
|----------------|------|
| 类型/配置      | `config.h`, `common/rpc/Common.h` |
| SQLite         | `CppSQLite3.cpp` |
| 协议读写       | `ProtocolMemReader.h`, `ProtocolMemWriter.h`, `ProtocolReader.h`, `ProtocolWriter.h` |
| 生成 RPC/结构  | `gen_rpc/*.h`, `gen_rpc/*.cpp`（Client2Server、Server2Client、SGE_*、com、proto、struct 等） |

统计上约 **28 个文件**，**+5007 / -4984 行**，其中大量是 `gen_rpc` 里把 `U32`/`S32` 等批量替换成 `uint32_t`/`int32_t` 等带来的行变化。

---

## 总结

Server 的修改主要是：把协议和生成代码里的整数/字符串类型统一成 C++ 标准类型（`stdint` + `std::string`/`bool`），把项目内用的 S64/U32 等定义集中到 `config.h`，并顺带整理了 `config.h` 的格式和头文件顺序，以及让 CppSQLite3 使用统一的 `S64` 类型。
