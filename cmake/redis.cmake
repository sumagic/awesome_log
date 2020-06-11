include(ExternalProject)

set(REDIS_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/redis)
set(REDIS_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/redis)
# set(REDIS_CONFIGURE cd ${REDIS_ROOT} && ./autogen.sh && ./configure --prefix=${REDIS_BIN_ROOT})
set(REDIS_MAKE cd ${REDIS_ROOT} && make)
set(REDIS_INSTALL_CMD cd ${REDIS_ROOT} && make install)

ExternalProject_Add(
    REDIS
    PREFIX ${REDIS_ROOT}
    SOURCE_DIR ${REDIS_ROOT}
    # GIT_REPOSITORY ${REDIS_GIT_URL}
    # CONFIGURE_COMMAND ${REDIS_CONFIGURE}
    BUILD_COMMAND ${REDIS_MAKE}
    INSTALL_COMMAND ${REDIS_INSTALL_CMD}
)

# set(REDIS_LIB ${REDIS_BIN_ROOT}/libgflags_nothreads.a)
set(REDIS_INCLUDE_LIB ${REDIS_BIN_ROOT}/include)