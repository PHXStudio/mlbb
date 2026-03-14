#!/bin/bash
# 构建服务器部署环境并制作 Docker 镜像

set -e

# 设置基础目录
cd "$(dirname "$0")"
SERVER_DIR=$(pwd)
PROJECT_DIR=$(dirname "$SERVER_DIR")
IMAGE_DIR="${SERVER_DIR}/image"

echo "==> 准备输出目录: ${IMAGE_DIR}"
rm -rf "${IMAGE_DIR}"
mkdir -p "${IMAGE_DIR}/bin"
mkdir -p "${IMAGE_DIR}/sql"
mkdir -p "${IMAGE_DIR}/config/Tables/LuaRoot/lua"
mkdir -p "${IMAGE_DIR}/config/Tables/Scene"
mkdir -p "${IMAGE_DIR}/config/Script/AI"
mkdir -p "${IMAGE_DIR}/config/Script/EmployeeAI"

echo "==> 使用 Docker 编译可执行文件..."
# 使用临时容器从当前的构建镜像抓取二进制文件
# 我们假设 mlbb-server-build 镜像已经包含了编译好的可执行文件
docker build -t mlbb-server-build -f Dockerfile .
docker rm -f mlbb-build-extract &>/dev/null || true
docker create --name mlbb-build-extract mlbb-server-build

# 提取二进制文件
echo "==> 提取编译产物到 ${IMAGE_DIR}/bin"
for BIN in world db gateway login mall scene gmtool; do
    docker cp mlbb-build-extract:/server/bin/${BIN} "${IMAGE_DIR}/bin/" || echo "Warning: ${BIN} not found"
done
docker rm -f mlbb-build-extract

echo "==> 拷贝启动脚本和环境配置"
cp ${SERVER_DIR}/bin/server_stop.sh ${IMAGE_DIR}/bin/
cp ${SERVER_DIR}/bin/server_start.sh ${IMAGE_DIR}/bin/
cp ${SERVER_DIR}/bin/server_restart.sh ${IMAGE_DIR}/bin/
cp ${SERVER_DIR}/bin/env.lua ${IMAGE_DIR}/bin/

echo "==> 拷贝配置表"
cp -PfR ${PROJECT_DIR}/config/Tables/*.csv  ${IMAGE_DIR}/config/Tables/ || true
cp -PfR ${PROJECT_DIR}/config/Tables/*.xml  ${IMAGE_DIR}/config/Tables/ || true
cp -PfR ${PROJECT_DIR}/config/Tables/Scene/*.xml  ${IMAGE_DIR}/config/Tables/Scene/ || true
cp -PfR ${PROJECT_DIR}/config/Tables/Scene/*.obj  ${IMAGE_DIR}/config/Tables/Scene/ || true
cp -PfR ${PROJECT_DIR}/config/Tables/LuaRoot/lua/*.lua  ${IMAGE_DIR}/config/Tables/LuaRoot/lua/ || true

echo "==> 拷贝 Lua 脚本"
cp -PfR ${PROJECT_DIR}/config/Script/*.lua  ${IMAGE_DIR}/config/Script/ || true
cp -PfR ${PROJECT_DIR}/config/Script/AI/*.lua  ${IMAGE_DIR}/config/Script/AI/ || true
cp -PfR ${PROJECT_DIR}/config/Script/EmployeeAI/*.lua  ${IMAGE_DIR}/config/Script/EmployeeAI/ || true

echo "==> 拷贝 SQL 脚本"
cp -PfR ${PROJECT_DIR}/sql/*.sql ${IMAGE_DIR}/sql/ || true

echo "==> 生成运行时镜像 Dockerfile"
cat > "${IMAGE_DIR}/Dockerfile" << 'EOF'
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Shanghai

# 安装运行时必需依赖
RUN apt-get update && apt-get install -y \
    libmysqlcppconn7v5 \
    libmysqlclient21 \
    libcurl4 \
    zlib1g \
    libace-6.4.5 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /server

# 复制部署文件
COPY bin/ /server/bin/
COPY config/ /server/config/
COPY sql/ /server/sql/

RUN chmod +x /server/bin/*

WORKDIR /server/bin
CMD ["bash", "-c", "./server_start.sh && tail -f /dev/null"]
EOF

echo "==> 构建运行时 Docker 镜像: mlbb-server-runtime:latest"
cd "${IMAGE_DIR}"
docker build -t mlbb-server-runtime:latest .

echo "==> 构建完成！"
echo "部署文件已保存在: ${IMAGE_DIR}"
echo "新的运行时镜像: mlbb-server-runtime:latest"
