# Webserv Docker Quick Start

This directory provides one-click Docker build/start scripts for services under `webserv/src/`.

## Included files

- `Dockerfile`: Multi-stage build, default Go `1.22`, supports dynamic service selection.
- `docker-compose.yml`: Starts `webserv` + `mysql-db`.
- `build-up.ps1`: One-click start script for PowerShell.
- `build-up.sh`: One-click start script for Linux / Git Bash.

## Prerequisites

- Docker Desktop (or Docker Engine + Compose plugin)
- Run commands in `D:/mlbb/webserv`

## One-click start (PowerShell)

```powershell
cd D:\mlbb\webserv
.\build-up.ps1
```

Example (build/start `carriers`):

```powershell
.\build-up.ps1 -AppName carriers -GoVersion 1.22 -AppPort 18080 -DbName carriers -InitSqlFile "./src/carriers/static/servs.sql"
```

## One-click start (Linux / Git Bash)

```bash
cd /d/mlbb/webserv
chmod +x ./build-up.sh
./build-up.sh
```

Example:

```bash
./build-up.sh --app-name carriers --go-version 1.22 --app-port 18080 --db-name carriers --init-sql-file ./src/carriers/static/servs.sql
```

## Common operations

```bash
# show status
docker compose ps

# web logs
docker compose logs -f webserv

# mysql logs
docker compose logs -f mysql-db

# stop and remove containers/network
docker compose down
```

## Supported environment variables

- `APP_NAME` (default: `gmtools`)
- `GO_VERSION` (default: `1.22`)
- `APP_PORT` (default: `8980`)
- `DB_HOST` (default: `mysql-db`)
- `DB_PORT` (default: `3306`)
- `DB_USER` (default: `xysk`)
- `DB_PASS` (default: `123456`)
- `DB_NAME` (default: `gmtools`)
- `MYSQL_ROOT_PASSWORD` (default: `root`)
- `INIT_SQL_FILE` (default: `./src/gmtools/static/gmtools.sql`)

## Notes

- Compose will wait for MySQL health check before starting `webserv`.
- `webserv` startup command patches `/app/conf/app.conf` DB fields from env vars at runtime.
- Compose auto-mounts SQL into `/docker-entrypoint-initdb.d/01-init.sql` for first-time MySQL initialization.
- The mounted MySQL data directory is `./mysql_data`.
- MySQL init scripts run only when `./mysql_data` is empty. If you need re-init, remove `./mysql_data` first.
- MySQL is internal-only (no host port published). `webserv` connects via `mysql-db:3306`.
