include(ExternalProject)

set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/Boost)
set(BOOST_BIN_ROOT ${CMAKE_BINARY_DIR}/compile/Boost)
set(boost_CONFIGURE cd ${BOOST_ROOT} && ./bootstrap.sh --with-libraries=all --with-toolset=gcc)
set(BOOST_MAKE cd ${BOOST_ROOT} && ./b2)
set(BOOST_INSTALL_CMD cd ${BOOST_ROOT} && ./b2 install --prefix=${BOOST_BIN_ROOT})

ExternalProject_Add(
    BOOST
    PREFIX ${BOOST_ROOT}
    SOURCE_DIR ${BOOST_ROOT}
    CONFIGURE_COMMAND ${BOOST_CONFIGURE}
    BUILD_COMMAND ${BOOST_MAKE}
    INSTALL_COMMAND ${BOOST_INSTALL_CMD}
)

# set(BOOST_LIB ${BOOST_ROOT}/libBOOST_nothreads.a)
set(BOOST_INCLUDE_LIB ${BOOST_BIN_ROOT}/include)