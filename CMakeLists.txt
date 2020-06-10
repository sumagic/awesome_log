cmake_minimum_required(VERSION 3.5.1)

project(xlog)

add_definitions(-D USE_XLOG=1)
add_definitions(-D ERROR_USE_FILENAME=1)
add_definitions(-D ERROR_USE_LINE=1)

include_directories(./include/)
add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(gflags)
include(glog)
include(grpc)
include(protobuf)
# include(boost)

# compile boost
set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/Boost)
set(BOOST_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/Boost)
set(BOOST_CONFIGURE ./bootstrap.sh --with-libraries=all --with-toolset=gcc)
set(BOOST_MAKE ./b2)
set(BOOST_INSTALL ./b2 install --prefix=${BOOST_BIN_ROOT})
# add_custom_target(BOOST ALL
#         COMMAND ${BOOST_CONFIGURE}
#         COMMAND ${BOOST_MAKE}
#         COMMAND ${BOOST_INSTALL}
#         WORKING_DIRECTORY ${BOOST_ROOT}
#         COMMENT "Original boost compile target")

# compile redis
set(REDIS_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/redis)
set(REDIS_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/redis)
add_custom_target(REDIS ALL
        COMMAND make
        COMMAND make PREFIX=${REDIS_BIN_ROOT} install
        WORKING_DIRECTORY ${REDIS_ROOT}
        COMMENT "Original redis makefile target")

# compile hiredis
set(HIREDIS_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/hiredis)
set(HIREDIS_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/hiredis)
add_custom_target(HIREDIS ALL
        COMMAND make
        COMMAND make PREFIX=${HIREDIS_BIN_ROOT} install
        WORKING_DIRECTORY ${HIREDIS_ROOT}
        COMMENT "Original hiredis makefile target")