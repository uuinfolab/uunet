file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable(core-tests ${SOURCES_TEST})
add_gtest(core-tests uunet)
