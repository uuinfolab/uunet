file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable (wnet-tests ${SOURCES_TEST})
add_gtest(wnet-tests uunet)
