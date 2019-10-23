file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable(olap-tests ${SOURCES_TEST})
add_gtest(olap-tests uunet)
