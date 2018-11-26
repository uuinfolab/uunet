file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable (pnet-tests ${SOURCES_TEST})
add_gtest(pnet-tests uunet)
