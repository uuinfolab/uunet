file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable (xnet-tests ${SOURCES_TEST})
add_gtest(xnet-tests uunet)
