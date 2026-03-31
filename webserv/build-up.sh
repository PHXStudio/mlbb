#!/usr/bin/env bash
set -euo pipefail

APP_NAME="${APP_NAME:-gmtools}"
GO_VERSION="${GO_VERSION:-1.22}"
APP_PORT="${APP_PORT:-8980}"
DB_NAME="${DB_NAME:-gmtools}"
DB_USER="${DB_USER:-xysk}"
DB_PASS="${DB_PASS:-123456}"
DB_HOST="${DB_HOST:-mysql-db}"
DB_PORT="${DB_PORT:-3306}"
MYSQL_ROOT_PASSWORD="${MYSQL_ROOT_PASSWORD:-root}"
INIT_SQL_FILE="${INIT_SQL_FILE:-./src/gmtools/static/gmtools.sql}"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --app-name) APP_NAME="$2"; shift 2 ;;
    --go-version) GO_VERSION="$2"; shift 2 ;;
    --app-port) APP_PORT="$2"; shift 2 ;;
    --db-name) DB_NAME="$2"; shift 2 ;;
    --db-user) DB_USER="$2"; shift 2 ;;
    --db-pass) DB_PASS="$2"; shift 2 ;;
    --db-host) DB_HOST="$2"; shift 2 ;;
    --db-port) DB_PORT="$2"; shift 2 ;;
    --mysql-root-password) MYSQL_ROOT_PASSWORD="$2"; shift 2 ;;
    --init-sql-file) INIT_SQL_FILE="$2"; shift 2 ;;
    -h|--help)
      cat <<'EOF'
Usage:
  ./build-up.sh [options]

Options:
  --app-name <name>              default: gmtools
  --go-version <version>         default: 1.22
  --app-port <port>              default: 8980
  --db-name <name>               default: gmtools
  --db-user <user>               default: xysk
  --db-pass <pass>               default: 123456
  --db-host <host>               default: mysql-db
  --db-port <port>               default: 3306
  --mysql-root-password <pass>   default: root
  --init-sql-file <path>         default: ./src/gmtools/static/gmtools.sql
EOF
      exit 0
      ;;
    *)
      echo "Unknown option: $1"
      echo "Use --help for usage."
      exit 1
      ;;
  esac
done

export APP_NAME GO_VERSION APP_PORT
export DB_NAME DB_USER DB_PASS DB_HOST DB_PORT
export MYSQL_ROOT_PASSWORD
export INIT_SQL_FILE
export MYSQL_USER="$DB_USER"
export MYSQL_PASSWORD="$DB_PASS"
export MYSQL_DATABASE="$DB_NAME"

echo "Building and starting webserv stack..."
echo "APP_NAME=${APP_NAME} GO_VERSION=${GO_VERSION} APP_PORT=${APP_PORT}"

docker compose down
docker compose up -d --build

echo
echo "Stack is starting. Current status:"
docker compose ps
echo
echo "Follow logs with:"
echo "docker compose logs -f webserv"
