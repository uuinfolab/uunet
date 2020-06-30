cmake_minimum_required (VERSION 3.15...3.18)

# TODO(dvladek): move to use BUILD_SHARED_LIBS		
# TODO(dvladek): use proper name
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.hpp")
file (GLOB_RECURSE HEADERS_IMP CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.ipp")
file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

#file (GLOB_RECURSE SOURCES ext/eclat/*.c ext/infomap/*.cpp libs/*.cpp src/*.cpp)

add_library(uunet SHARED ${SOURCES} ${HEADERS} ${HEADERS_IMP})

# Include private components
target_include_directories (uunet PUBLIC
	${CMAKE_SOURCE_DIR}/ext/eigen3 
	${CMAKE_SOURCE_DIR}/ext/spectra
	${CMAKE_SOURCE_DIR}/ext/eclat/eclat/src
	${CMAKE_SOURCE_DIR}/ext/eclat/tract/src
	${CMAKE_SOURCE_DIR}/ext/eclat/math/src
	${CMAKE_SOURCE_DIR}/ext/eclat/util/src
	${CMAKE_SOURCE_DIR}/ext/eclat/apriori/src
	${CMAKE_SOURCE_DIR}/ext/infomap)

target_include_directories (uunet PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
	$<INSTALL_INTERFACE:include>)

set_target_properties (uunet PROPERTIES CXX_STANDARD 14)
target_compile_features (uunet PUBLIC cxx_std_14)

set (UUNET_DEBUG_OPTIONS -Wall -Wextra -Wpedantic)
target_compile_options (uunet PUBLIC "$<$<CONFIG:DEBUG>:${UUNET_DEBUG_OPTIONS}>")

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})

#if (MSVC)
    # warning level 4 and all warnings as errors
#    add_compile_options(/W4 /WX)
#else()
    # lots of warnings and all warnings as errors
#    add_compile_options(-Wall -Wextra -pedantic -Werror)
#endif()
