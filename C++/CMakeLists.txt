cmake_minimum_required (VERSION 3.1...3.12)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project (uunet LANGUAGES C CXX)

set (PROJECT_VENDOR 			"Matteo Magnani")
set (PROJECT_CONTACT 			"matteo.magnani@it.uu.se")
set (PROJECT_URL 				"https://bitbucket.org/uuinfolab/uunet")
set (PROJECT_DESCRIPTION 		"Network analysis library")

# Setting the project version
file (READ						"${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION_FULL)
string (REGEX REPLACE 			"[\n\r]" "" PROJECT_VERSION_FULL "${PROJECT_VERSION_FULL}")
string (REGEX REPLACE 			"^([0-9]+)\\.[0-9]+\\.[0-9]+$" "\\1" PROJECT_VERSION_MAJOR "${PROJECT_VERSION_FULL}")
string (REGEX REPLACE 			"^[0-9]+\\.([0-9]+)\\.[0-9]+$" "\\1" PROJECT_VERSION_MINOR "${PROJECT_VERSION_FULL}")
string (REGEX REPLACE 			"^[0-9]+\\.[0-9]+\\.([0-9]+)$" "\\1" PROJECT_VERSION_PATCH "${PROJECT_VERSION_FULL}")

set (PROJECT_VERSION 			"${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
math (EXPR LIBRARY_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set (LIBRARY_VERSION_MINOR 		"${PROJECT_VERSION_MINOR}")
set (LIBRARY_VERSION_PATCH 		"${PROJECT_VERSION_PATCH}")
set (LIBRARY_VERSION 			"${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}")
set (LIBRARY_VERSION_FULL 		"${LIBRARY_VERSION}.${LIBRARY_VERSION_PATCH}")

# Add aditional cmake scripts
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
enable_testing()

# Choosing compiler (clang has preference).
if (CMAKE_CXX_COMPILER MATCHES ".*clang.*" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set (CMAKE_COMPILER_IS_CLANGXX 1)
endif()

# Choosing Debug as default building type.
set(default_build_type "Release")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
	
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message (STATUS "Compiling as: " ${CMAKE_BUILD_TYPE})

if(MSVC)
    add_compile_options("/W4" "$<$<CONFIG:RELEASE>:/O2>")
else()
	add_compile_options("$<$<CONFIG:RELEASE>:-O2>" "$<$<CONFIG:DEBUG>:-O3 -ggdb -g3 -Wall -Wextra -Werror>")
    
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libc++")
    else()
        # nothing special for gcc at the moment
    endif()
endif()






set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
#set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

# Setting flags.
#if (CMAKE_COMPILER_IS_GNUCXX)
#  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O3 -ggdb -g3 -Wall -Wextra -fmessage-length=0 -funroll-loops -fno-omit-frame-pointer -DNDEBUG")
#else()
#	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O3 -ggdb -g3 -Wall -Wall -fmessage-length=0 -funroll-loops -fno-omit-frame-pointer -D__extern_always_inline=\"extern __always_inline\" -DNDEBUG")
#endif()



# Include external libraries.
include_directories (
    ext/cpptoml
	ext/eigen3 
	ext/spectra
	ext/eclat/eclat/src
	ext/eclat/tract/src
	ext/eclat/math/src
	ext/eclat/util/src
	ext/eclat/apriori/src)

# Check BLAS package. TODO(dvladek): check if really needed.
find_package(BLAS REQUIRED)

file (GLOB_RECURSE SOURCES ext/eclat/*.c src/*.cpp)

# Disabling doxygen documentation by default.
option (DOXY "Generate DoxyGen documentation" OFF)
if (DOXY)
	find_package (Doxygen)
	if (DOXYGEN_FOUND)
		set (DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/uunet.doxyfile)
		set (DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
		configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
		add_custom_target(doc ALL
			COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
			COMMENT "Generating API documentation with Doxygen"
			VERBATIM)
	else()
		message (FATAL_ERROR "Doxygen is needed to build the documentation.")
	endif()
endif(DOXY)

# Generate and install libraries
add_library (uunet SHARED ${SOURCES} ${PROBE_PATH})
target_include_directories (uunet PUBLIC include)
target_compile_features(uunet PUBLIC cxx_std_14)

set_target_properties(uunet PROPERTIES CXX_EXTENSIONS OFF)

TARGET_LINK_LIBRARIES(uunet ${META_FILES})

install(DIRECTORY "include/" # source directory
        DESTINATION "include/libuunet" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.h" # select header files
)

install(DIRECTORY "ext/eigen3/" # source directory
        DESTINATION "include/eigen3" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*" # select header files
)

install(DIRECTORY "ext/spectra" # source directory
        DESTINATION "include/spectra" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.h" # select header files
)

install(DIRECTORY "ext/eclat/" # source directory
        DESTINATION "include/eclat" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*" # select header files
)

install (TARGETS uunet
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include)

# Generate tests only during Debug.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_subdirectory(test)
endif()
