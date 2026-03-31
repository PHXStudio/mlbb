# 回合制 MMORPG 服务器构建环境
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Shanghai

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    git \
    wget \
    pkg-config \
    libboost-dev \
    libboost-system-dev \
    libboost-filesystem-dev \
    zlib1g-dev \
    libcurl4-openssl-dev \
    libace-dev \
    libmysqlcppconn-dev \
    libmysqlclient-dev \
    libsqlite3-dev \
    net-tools \
    iproute2 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /server
COPY . /server/

# 编译并安装
# 注意：cmake 配置后，make install 默认会安装到 CMAKE_INSTALL_PREFIX (在 macros.cmake 中设定为 /server/bin)
RUN mkdir -p build && cd build && cmake .. && make -j$(nproc) install

# 设置可执行文件权限
RUN chmod +x /server/bin/*

WORKDIR /server/bin
CMD ["bash", "-c", "./server_start.sh && tail -f /dev/null"]
