cmake_minimum_required (VERSION 3.15...3.18)


# TODO(dvladek): move to use BUILD_SHARED_LIBS		
# TODO(dvladek): use proper name
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.hpp")
file (GLOB_RECURSE HEADERS_IMP CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.ipp")
file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

#file (GLOB_RECURSE SOURCES ext/eclat/*.c ext/infomap/*.cpp libs/*.cpp src/*.cpp)

add_library(uunet SHARED
	${SOURCES}
	${HEADERS}
	${HEADERS_IMP})

include(GNUInstallDirs)

message (STATUS "INFO: '${CMAKE_SOURCE_DIR}'.")

target_include_directories (uunet
	PRIVATE
		${CMAKE_SOURCE_DIR}/ext/spectra
		${CMAKE_SOURCE_DIR}/ext/eclat/eclat/src
		${CMAKE_SOURCE_DIR}/ext/eclat/tract/src
		${CMAKE_SOURCE_DIR}/ext/eclat/math/src
		${CMAKE_SOURCE_DIR}/ext/eclat/util/src
		${CMAKE_SOURCE_DIR}/ext/eclat/apriori/src
		${CMAKE_SOURCE_DIR}/ext/infomap
	
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/ext/eigen3>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties (uunet PROPERTIES 
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

set_target_properties (uunet PROPERTIES 
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS OFF
) 

if (MSVC)
	set (UUNET_DEBUG_OPTIONS /W4 /WX)
else ()
	set (UUNET_DEBUG_OPTIONS -Wall -Wextra -Wpedantic)
endif ()

target_compile_features (uunet PUBLIC cxx_std_14)
target_compile_options (uunet PUBLIC "$<$<CONFIG:DEBUG>:${UUNET_DEBUG_OPTIONS}>")

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})

install(
	TARGETS uunet
	EXPORT
		uunet-config
		COMPONENT uunet_dev
	RUNTIME
		DESTINATION ${CAMKE_INSTALL_BINDIR}
		COMPONENT uunet_rt
	LIBRARY
		DESTINATION ${CMAKE_INSTALL_LIBDIR}
		COMPONENT uunet_rt
		NAMELINK_COMPONENT uunet_dev 
	ARCHIVE
		DESTINATION ${CMAKE_INSTALL_LIBDIR}
		COMPONENT uunet_dev
)

message (STATUS "INFO: '${CMAKE_CURRENT_LIST_DIR}'.")

install(
	DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/				# source directory
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/uunet		# target directory
	FILES_MATCHING 										# install only matched files
	PATTERN "*.hpp" 									# select header files
	PATTERN "*.ipp" 									# select header files
)

install(
    EXPORT uunet-config
    NAMESPACE uunet::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uunet
	COMPONENT uunet_dev)
