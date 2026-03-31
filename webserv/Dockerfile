ARG GO_VERSION=1.22
FROM golang:${GO_VERSION}-bookworm AS builder

ARG APP_NAME=gmtools
ENV GO111MODULE=on
ENV CGO_ENABLED=1

WORKDIR /go/src
COPY src/ /go/src/

WORKDIR /go/src/${APP_NAME}
RUN test -f main.go
RUN go env -w GOPROXY=https://proxy.golang.org,direct && \
    if [ ! -f go.mod ]; then go mod init ${APP_NAME}; fi && \
    go mod tidy
RUN go build -o /out/${APP_NAME} .

# Collect optional runtime assets (some services only have conf).
RUN mkdir -p /out/runtime && \
    cp /out/${APP_NAME} /out/runtime/${APP_NAME} && \
    if [ -d "/go/src/${APP_NAME}/conf" ]; then cp -r "/go/src/${APP_NAME}/conf" /out/runtime/conf; fi && \
    if [ -d "/go/src/${APP_NAME}/static" ]; then cp -r "/go/src/${APP_NAME}/static" /out/runtime/static; fi && \
    if [ -d "/go/src/${APP_NAME}/views" ]; then cp -r "/go/src/${APP_NAME}/views" /out/runtime/views; fi

FROM debian:bookworm-slim

ARG APP_NAME=gmtools
ENV TZ=Asia/Shanghai
ENV APP_NAME=${APP_NAME}

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    tzdata \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY --from=builder /out/runtime/ /app/

EXPOSE 8980
CMD ["/bin/sh", "-c", "exec /app/${APP_NAME}"]
