cmake_minimum_required( VERSION 3.15...3.18 )

# TODO(dvladek): Fix the new include
# include( "${CMAKE_CURRENT_LIST_DIR}/project-meta-info.in" )

# Add aditional cmake scripts
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# Include custom cmake scripts
#include(cmake/GetGitRevisionDescription.cmake)

# TODO(dvladek): add/read the project configuration.

# Project options
option(OPTION_BUILD_EXAMPLES  "Build examples."                                        ON)
option(OPTION_BUILD_DOCS      "Generate documentation."                                OFF)
option(OPTION_BUILD_TESTS     "Build tests in release."                                OFF)

# Choosing Release as default building type.
set (default_build_type "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message (STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set (CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
	
	set_property (CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

message (STATUS "Compiling as: " ${CMAKE_BUILD_TYPE})

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# Generate compile information for IDEs
	set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
	
	# Let's nicely support folders in IDEs
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

project (uunet VERSION 0.6.2
	DESCRIPTION "Network analysis library"
	HOMEPAGE_URL "https://bitbucket.org/uuinfolab/uunet"
   	LANGUAGES C CXX)

# Configure health check tools
# enable_cppcheck(ON)

# The compiled library
add_subdirectory(src)

# Examples using the library
# NOTE(dvladek): Temporally disabled as the examples are out-of-date
# add_subdirectory(examples)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	if (OPTION_BUILD_DOCS)
		add_subdirectory(docs)
	endif ()

	if (OPTION_BUILD_TESTS OR (CMAKE_BUILD_TYPE STREQUAL "Debug"))
		enable_testing()
		add_subdirectory(test)
	endif ()
endif ()
		
return()





# Setting the project version
#file (READ						"${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION_FULL)
#string (REGEX REPLACE 			"[\n\r]" "" PROJECT_VERSION_FULL "${PROJECT_VERSION_FULL}")
#string (REGEX REPLACE 			"^([0-9]+)\\.[0-9]+\\.[0-9]+$" "\\1" PROJECT_VERSION_MAJOR "${PROJECT_VERSION_FULL}")
#string (REGEX REPLACE 			"^[0-9]+\\.([0-9]+)\\.[0-9]+$" "\\1" PROJECT_VERSION_MINOR "${PROJECT_VERSION_FULL}")
#string (REGEX REPLACE 			"^[0-9]+\\.[0-9]+\\.([0-9]+)$" "\\1" PROJECT_VERSION_PATCH "${PROJECT_VERSION_FULL}")

#set (PROJECT_VERSION 			"${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
#math (EXPR LIBRARY_VERSION_MAJOR 	"${PROJECT_VERSION_MAJOR}")
#set (LIBRARY_VERSION_MINOR 		"${PROJECT_VERSION_MINOR}")
#set (LIBRARY_VERSION_PATCH 		"${PROJECT_VERSION_PATCH}")
#set (LIBRARY_VERSION 			"${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}")
#set (LIBRARY_VERSION_FULL 		"${LIBRARY_VERSION}.${LIBRARY_VERSION_PATCH}")

#set (PROJECT_VENDOR 			"Matteo Magnani")
#set (PROJECT_CONTACT 			"matteo.magnani@it.uu.se")
#set (PROJECT_URL 			"https://bitbucket.org/uuinfolab/uunet")
#set (PROJECT_DESCRIPTION 		"Network analysis library")

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)


# Choosing compiler (clang has preference).
#if (CMAKE_CXX_COMPILER MATCHES ".*clang.*" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#	set (CMAKE_COMPILER_IS_CLANGXX 1)
#endif()



# Adding compiler options. The non-modern style has been used for compatibility reasons with cmake < 3.8

#if (MSVC)
#	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
#else()
#	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
#	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O3 -ggdb -g3 -Wall -Wextra")
#    
#	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#       add_compile_options("-stdlib=libc++")
#    else()
#       # nothing special for gcc at the moment
#    endif()
#endif()

add_definitions(-DNS_INFOMAP -DONLY_C_LOCALE=1)

# Installing targets

install(DIRECTORY "libs/" # source directory
DESTINATION "include/libuunet" # target directory
FILES_MATCHING # install only matched files
PATTERN "*.hpp" # select header files
)

install(DIRECTORY "libs/" # source directory
DESTINATION "include/libuunet" # target directory
FILES_MATCHING # install only matched files
PATTERN "*.ipp" # select header files
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
        PATTERN "*.h" # select header files
)

install(DIRECTORY "ext/infomap" # source directory
        DESTINATION "include/infomap" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.h" # select header files
)

