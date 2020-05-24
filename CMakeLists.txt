cmake_minimum_required(VERSION 3.5.1)

message("[INFO] start to cmake xLogDaemon/xLogDump/libxlog.so")
add_definitions(-D USE_XLOG=1)
add_definitions(-D ERROR_USE_FILENAME=1)
add_definitions(-D ERROR_USE_LINE=1)

include_directories(./include/)