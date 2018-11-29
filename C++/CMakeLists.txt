cmake_minimum_required (VERSION 3.0 FATAL_ERROR)
project (uunet LANGUAGES C CXX)

set (PROJECT_VENDOR 			"Matteo Magnani")
set (PROJECT_CONTACT 			"matteo.magnani@it.uu.se")
set (PROJECT_URL			"https://bitbucket.org/uuinfolab/net")
set (PROJECT_DESCRIPTION 		"Network analysis library")
set (CMAKE_BUILD_TYPE 			"Debug")

# Setting the project version
file (READ				"${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION_FULL)
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

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Choosing compiler (clang has preference).
if (CMAKE_CXX_COMPILER MATCHES ".*clang.*" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set (CMAKE_COMPILER_IS_CLANGXX 1)
endif()

# Setting flags.
if (CMAKE_COMPILER_IS_GNUCXX)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -march=native -mavx -std=c++14")
  set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O3 -ggdb -g3 -Wall -Wextra -fmessage-length=0 -funroll-loops -fno-omit-frame-pointer -DNDEBUG")
else()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O3 -ggdb -g3 -Wall -Wall -fmessage-length=0 -funroll-loops -fno-omit-frame-pointer -D__extern_always_inline=\"extern __always_inline\" -DNDEBUG")
endif()

# Choosing Release as default building type.
if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Release ... FORCE)
endif()

message (STATUS "Compiling as: " ${CMAKE_BUILD_TYPE} )

# Include uunet library.
include_directories (include)

# Include external libraries.
include_directories (
    	ext/cpptoml
	ext/eigen3 
	ext/spectra
	ext/eclat/eclat/src
	ext/eclat/tract/src
	ext/eclat/math/src
	ext/eclat/util/src
	ext/eclat/apriori/src
	ext/infomap)

add_definitions(-DNS_INFOMAP -DONLY_C_LOCALE=1)

# Check BLAS package. TODO(dvladek): check if really needed.
find_package(BLAS REQUIRED)

file (GLOB_RECURSE SOURCES ext/eclat/*.c ext/infomap/*.cpp src/*.cpp)

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

install(DIRECTORY "ext/infomap" # source directory
        DESTINATION "include/infomap" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.h" # select header files
)

install (TARGETS uunet
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include)

# Generate tests only during Debug.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_subdirectory(test)
endif()
