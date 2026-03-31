param(
    [string]$AppName = "gmtools",
    [string]$GoVersion = "1.22",
    [string]$AppPort = "8980",
    [string]$DbName = "gmtools",
    [string]$DbUser = "xysk",
    [string]$DbPass = "123456",
    [string]$DbHost = "mysql-db",
    [string]$DbPort = "3306",
    [string]$MysqlRootPassword = "root",
    [string]$InitSqlFile = "./src/gmtools/static/gmtools.sql"
)

$ErrorActionPreference = "Stop"

$env:APP_NAME = $AppName
$env:GO_VERSION = $GoVersion
$env:APP_PORT = $AppPort
$env:DB_NAME = $DbName
$env:DB_USER = $DbUser
$env:DB_PASS = $DbPass
$env:DB_HOST = $DbHost
$env:DB_PORT = $DbPort
$env:MYSQL_ROOT_PASSWORD = $MysqlRootPassword
$env:MYSQL_USER = $DbUser
$env:MYSQL_PASSWORD = $DbPass
$env:MYSQL_DATABASE = $DbName
$env:INIT_SQL_FILE = $InitSqlFile

Write-Host "Building and starting webserv stack..."
Write-Host "APP_NAME=$AppName GO_VERSION=$GoVersion APP_PORT=$AppPort"

docker compose down
docker compose up -d --build

Write-Host ""
Write-Host "Stack is starting. Current status:"
docker compose ps
Write-Host ""
Write-Host "Follow logs with:"
Write-Host "docker compose logs -f webserv"
