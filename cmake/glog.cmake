include(ExternalProject)

set(GLOG_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/glog)
set(GLOG_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/glog)
set(GLOG_CONFIGURE cd ${GLOG_ROOT} && cmake -D CMAKE_INSTALL_PREFIX=${GLOG_BIN_ROOT} .)
set(GLOG_MAKE cd ${GLOG_ROOT} && make)
set(GLOG_INSTALL_CMD cd ${GLOG_ROOT} && make install)

ExternalProject_Add(
    GLOG
    PREFIX ${GLOG_ROOT}
    SOURCE_DIR ${GLOG_ROOT}
    CONFIGURE_COMMAND ${GLOG_CONFIGURE}
    BUILD_COMMAND ${GLOG_MAKE}
    INSTALL_COMMAND ${GLOG_INSTALL_CMD}
)

# set(GLOG_LIB ${GLOG_ROOT}/libGLOG_nothreads.a)
set(GLOG_INCLUDE_LIB ${GLOG_BIN_ROOT}/include)