file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable (net-tests $ {SOURCES_TEST})
add_gtest(net-tests uunet)
