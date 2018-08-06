find_package (Threads REQUIRED)

include (ExternalProject)

ExternalProject_Add(
	gtest
	GIT_REPOSITORY		https://github.com/google/googletest.git
	GIT_TAG 			master
	PREFIX 				${CMAKE_SOURCE_DIR}/ext/gtest
	CMAKE_ARGS 			-Dgtest_force_shared_crt=ON
						-DBUILD_GTEST=ON
	INSTALL_COMMAND   	""
	TEST_COMMAND      	""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set_target_properties(libgtest PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set_target_properties(libgmock PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

include_directories(
	"${source_dir}/googletest/include"
	"${source_dir}/googlemock/include"
)

add_subdirectory (core)
add_subdirectory (net)


