file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable(lnet-tests ${SOURCES_TEST})
add_gtest(lnet-tests uunet)
