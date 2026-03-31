#!/bin/bash
#################################################################################
# platform linux SHELL                                                          #
# brief    服务器启动脚本                                                       #
# date     2013-2-27                                                            #
# version  1.0.0                                                                #
#                                                                             #
# 开启服务器待完善                                                             #
# 1) worldserver 完全启动前不能启动其他服务器但是怎么知道worldserver完全启动     #
#    目前做法是强制sleep 20 秒                                                 #
# 2) 启动相关的log只是流程输出并未检测是否已经启动                              #
#################################################################################

start() {
	./world -d
	echo "Wait for world server......"
	sleep 10
	echo "World server start"
	./scene -d
	echo "Scene server start"
	./login -d
	echo "Login server start"
	./db -d
	echo "DB server start"
	./gateway -d
	echo "Gateway server start"
	# ./mall -d
	# echo "Mall server start"
	# ./logser -d
	# echo "logser server start"
	# ./gmtool -d
	# echo "gmtool server start"
	# sleep 30
	# `pwd`/test -d
	# echo "test server start"
}

start

