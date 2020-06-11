include(ExternalProject)

set(GRPC_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/grpc)
set(GRPC_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/grpc)
set(GRPC_CONFIGURE cd ${GRPC_ROOT} && cmake -D CMAKE_INSTALL_PREFIX=${GRPC_BIN_ROOT} .)
set(GRPC_MAKE cd ${GRPC_ROOT} && make)
set(GRPC_INSTALL_CMD cd ${GRPC_ROOT} && make install)

ExternalProject_Add(
    GRPC
    PREFIX ${GRPC_ROOT}
    SOURCE_DIR ${GRPC_ROOT}
    CONFIGURE_COMMAND ${GRPC_CONFIGURE}
    BUILD_COMMAND ${GRPC_MAKE}
    INSTALL_COMMAND ${GRPC_INSTALL_CMD}
)

# set(GRPC_LIB ${GRPC_BIN_ROOT}/libgflags_nothreads.a)
set(GRPC_INCLUDE_LIB ${GRPC_BIN_ROOT}/include)