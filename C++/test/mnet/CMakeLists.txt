file (GLOB_RECURSE SOURCES_TEST
	*.cpp)

add_executable (mnet-tests ${SOURCES_TEST})
add_gtest(mnet-tests uunet)
