cmake_minimum_required (VERSION 3.15...3.23)

# Meta information about the project
include( "${PROJECT_SOURCE_DIR}/project-meta-info.in" )

# Add aditional cmake scripts
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

find_package( Threads REQUIRED )
include( AddGoogleTest )

file( GLOB_RECURSE SOURCES_TEST CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp" )
add_executable( run_tests ${SOURCES_TEST} )

target_compile_features( run_tests PRIVATE cxx_std_17 )

add_gtest( run_tests ${META_LIBRARY_NAME} )
