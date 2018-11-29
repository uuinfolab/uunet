file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable (tnet-tests ${SOURCES_TEST})
add_gtest(tnet-tests uunet)
