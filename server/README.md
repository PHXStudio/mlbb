# 回合制 MMORPG 服务器


## 架构概览

```
客户端 ──→ Gateway（网关）──→ World（核心逻辑）──→ DB（数据库服务）
                                    ├──→ Scene（寻路/导航）
                                    ├──→ Login（登录认证）
                                    └──→ Mall（商城）
```

| 模块 | 说明 |
|------|------|
| `common/` | 公共库（RPC框架、Lua脚本引擎、网络层、配置解析、JSON、SQLite等） |
| `world/` | 核心游戏逻辑（玩家、战斗、宠物、伙伴、帮派、任务、活动等） |
| `scene/` | 场景寻路服务（集成 Detour/Recast NavMesh） |
| `gateway/` | 客户端连接网关 |
| `login/` | 登录认证服务 |
| `db/` | 数据库存储服务 |
| `mall/` | 商城服务 |
| `gmtool/` | GM管理工具 |
| `tables/` | 配置表加载 |
| `robot/` | 压力测试机器人 |

## 依赖

| 依赖 | 版本 | 说明 |
|------|------|------|
| [ACE](https://www.dre.vanderbilt.edu/~schmidt/ACE.html) | 6.3+ | 网络框架 |
| [MySQL Connector/C++](https://dev.mysql.com/downloads/connector/cpp/) | 1.1.x | 数据库连接 |
| libcurl | - | HTTP 客户端 |
| zlib | - | 数据压缩 |
| CMake | 3.0+ | 构建系统 |
| Clang / GCC | C++11 | 编译器 |

## 快速开始（Docker，推荐）

最简单的构建与部署方式，无需手动在宿主机安装依赖：

### 1. 编译服务器

利用 Docker 容器化编译，不污染宿主机环境：

```bash
# 构建包含所有编译依赖的镜像（第一次需下载较多组件）
docker build -t mlbb-server-build .

# [可选] 进入容器交互式调试编译
docker run --rm -it -m 8g mlbb-server-build bash
cmake .. && make -j2
```

> **注意**：Docker Desktop 需要分配至少 6GB 内存（Settings → Resources），否则编译可能由于内存不足（OOM）被终止。

### 2. 构建生产环境镜像

运行我们提供的自动化打包脚本。该脚本会自动从刚才编译好的 `mlbb-server-build` 镜像提取出所有可执行文件，并把宿主机上的配置表、Lua脚本、SQL 整理到 `server/image/` 目录下，最后打包出一个非常轻量、仅包含基础运行环库的新镜像：

```bash
chmod +x ./build_image.sh
./build_image.sh
```

一旦构建完成，会生成一个新的生产环境镜像：**`mlbb-server-runtime:latest`**。

### 3. 一键启动（通过 Compose 和 Runtime 镜像）

（如果你希望自行搭建数据库，请在 `bin/env.lua` 中调整您的 `V_MysqlHost` 等参数。）

```bash
# 一键启动所有服务 (MySQL + 游戏服务器)
# 编排会自动等待数据库处于健康状态后再启动游戏服务器，并自动映射 21000 端口
docker-compose up -d

# 检查服务状态
docker-compose ps

# 查看服务器启动实时日志
docker-compose logs -f mlbb-server
```

### 4. MySQL 容器操作与检查（常用）

如果遇到数据库连接问题，可以使用以下命令进行操作：

```bash
# 查看 MySQL 容器状态
docker ps | grep mysql

# 查看数据库实时日志
docker logs -f mlbb-mysql

# 手动进入数据库导入 SQL (如果自动导入失败)
# 先拷贝 DDL 到容器内，再执行 mysql 命令导入
docker cp ../sql/DDL.sql mlbb-mysql:/tmp/DDL.sql
docker exec -it mlbb-mysql mysql -uroot -proot -e "USE \`8000_game\`; source /tmp/DDL.sql;"

# 验证表结构是否正确（特别是 RankId 字段）
docker exec -it mlbb-mysql mysql -uxysk -pxysk_password -e "USE 8000_game; DESC EndlessStair;"

# 重启数据库服务
docker restart mlbb-mysql
```

### 5. 停止服务

当需要关闭服务器或数据库容器时：

```bash
# 停止游戏服务器容器，但不删除（可通过 docker start 再次启动）
docker stop mlbb-server-runner

# 如果需要彻底删除服务器容器
docker rm -f mlbb-server-runner

# 停止并清理 MySQL 数据库容器
docker-compose down
```
