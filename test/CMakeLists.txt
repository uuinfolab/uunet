find_package(Threads REQUIRED)

include(AddGoogleTest)

file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable (run_tests ${SOURCES_TEST})
add_gtest(run_tests uunet)
