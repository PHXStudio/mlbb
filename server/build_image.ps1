# 构建服务器部署环境并制作 Docker 镜像
# PowerShell 等价于 build_image.sh（在 Windows 上需已安装 Docker Desktop）
#
# Docker Desktop + BuildKit 偶发: parent snapshot ... does not exist。默认使用经典构建器规避；
# 若仍失败可先执行: docker builder prune -f ，或重启 Docker Desktop。
param(
    [switch]$UseBuildKit
)

$ErrorActionPreference = 'Stop'

if ($UseBuildKit) {
    $env:DOCKER_BUILDKIT = '1'
} else {
    $env:DOCKER_BUILDKIT = '0'
}

# 与 bash 中 `docker rm -f ... 2>/dev/null || true` 一致：不存在容器时不报错（避免 stderr 触发 Stop）
function Invoke-DockerRmForceQuiet([string]$ContainerName) {
    $prev = $ErrorActionPreference
    $ErrorActionPreference = 'SilentlyContinue'
    docker rm -f $ContainerName 2>&1 | Out-Null
    $ErrorActionPreference = $prev
}

Set-Location $PSScriptRoot
$SERVER_DIR = (Get-Location).Path
$PROJECT_DIR = Split-Path -Parent $SERVER_DIR
$IMAGE_DIR = Join-Path $SERVER_DIR 'image'

Write-Host "==> 准备输出目录: $IMAGE_DIR"
if (Test-Path $IMAGE_DIR) {
    Remove-Item -LiteralPath $IMAGE_DIR -Recurse -Force
}
New-Item -ItemType Directory -Path (Join-Path $IMAGE_DIR 'bin') -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $IMAGE_DIR 'sql') -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $IMAGE_DIR 'config/Tables/LuaRoot/lua') -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $IMAGE_DIR 'config/Tables/Scene') -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $IMAGE_DIR 'config/Script/AI') -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $IMAGE_DIR 'config/Script/EmployeeAI') -Force | Out-Null

Write-Host "==> 使用 Docker 编译可执行文件..."
docker build -t mlbb-server-build -f Dockerfile $SERVER_DIR
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Invoke-DockerRmForceQuiet 'mlbb-build-extract'
docker create --name mlbb-build-extract mlbb-server-build
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> 提取编译产物到 $IMAGE_DIR/bin"
$bins = @('world', 'db', 'gateway', 'login', 'mall', 'scene', 'gmtool')
foreach ($BIN in $bins) {
    docker cp "mlbb-build-extract:/server/bin/$BIN" (Join-Path $IMAGE_DIR 'bin')
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Warning: $BIN not found"
    }
}
docker rm -f mlbb-build-extract
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> 拷贝启动脚本和环境配置"
Copy-Item (Join-Path $SERVER_DIR 'bin/server_stop.sh') (Join-Path $IMAGE_DIR 'bin/') -Force
Copy-Item (Join-Path $SERVER_DIR 'bin/server_start.sh') (Join-Path $IMAGE_DIR 'bin/') -Force
Copy-Item (Join-Path $SERVER_DIR 'bin/server_restart.sh') (Join-Path $IMAGE_DIR 'bin/') -Force
Copy-Item (Join-Path $SERVER_DIR 'bin/env.lua') (Join-Path $IMAGE_DIR 'bin/') -Force

Write-Host "==> 拷贝配置表"
$tablesDir = Join-Path $PROJECT_DIR 'config/Tables'
Copy-Item (Join-Path $tablesDir '*.csv') (Join-Path $IMAGE_DIR 'config/Tables/') -Force -ErrorAction SilentlyContinue
Copy-Item (Join-Path $tablesDir '*.xml') (Join-Path $IMAGE_DIR 'config/Tables/') -Force -ErrorAction SilentlyContinue
$sceneDir = Join-Path $tablesDir 'Scene'
Copy-Item (Join-Path $sceneDir '*.xml') (Join-Path $IMAGE_DIR 'config/Tables/Scene/') -Force -ErrorAction SilentlyContinue
Copy-Item (Join-Path $sceneDir '*.obj') (Join-Path $IMAGE_DIR 'config/Tables/Scene/') -Force -ErrorAction SilentlyContinue
$luaRoot = Join-Path $tablesDir 'LuaRoot/lua'
Copy-Item (Join-Path $luaRoot '*.lua') (Join-Path $IMAGE_DIR 'config/Tables/LuaRoot/lua/') -Force -ErrorAction SilentlyContinue

Write-Host "==> 拷贝 Lua 脚本"
$scriptDir = Join-Path $PROJECT_DIR 'config/Script'
Copy-Item (Join-Path $scriptDir '*.lua') (Join-Path $IMAGE_DIR 'config/Script/') -Force -ErrorAction SilentlyContinue
Copy-Item (Join-Path $scriptDir 'AI/*.lua') (Join-Path $IMAGE_DIR 'config/Script/AI/') -Force -ErrorAction SilentlyContinue
Copy-Item (Join-Path $scriptDir 'EmployeeAI/*.lua') (Join-Path $IMAGE_DIR 'config/Script/EmployeeAI/') -Force -ErrorAction SilentlyContinue

Write-Host "==> 拷贝 SQL 脚本（仅 DDL.sql）"
$ddlSql = Join-Path $PROJECT_DIR 'sql/DDL.sql'
if (Test-Path -LiteralPath $ddlSql) {
    Copy-Item -LiteralPath $ddlSql (Join-Path $IMAGE_DIR 'sql/') -Force
}

Write-Host "==> 生成运行时镜像 Dockerfile"
$dockerfileContent = @'
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
    net-tools \
    iproute2 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /server

# 复制部署文件
COPY bin/ /server/bin/
COPY config/ /server/config/
COPY sql/ /server/sql/

RUN chmod +x /server/bin/*

WORKDIR /server/bin
CMD ["bash", "-c", "./server_start.sh && tail -f /dev/null"]
'@
$dfPath = Join-Path $IMAGE_DIR 'Dockerfile'
[System.IO.File]::WriteAllText($dfPath, $dockerfileContent.TrimEnd() + "`n", [System.Text.UTF8Encoding]::new($false))

Write-Host "==> 构建运行时 Docker 镜像: mlbb-server-runtime:latest"
Set-Location $IMAGE_DIR
docker build -t mlbb-server-runtime:latest .
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> 构建完成！"
Write-Host "部署文件已保存在: $IMAGE_DIR"
Write-Host "新的运行时镜像: mlbb-server-runtime:latest"
