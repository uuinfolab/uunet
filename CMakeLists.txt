cmake_minimum_required( VERSION 3.15...3.18 )

# Meta information about the project
include( "${CMAKE_CURRENT_LIST_DIR}/project-meta-info.in" )

#
# Preamble
#


# Include cmake modules
list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )

# Include custom cmake scripts
include( cmake/GetGitRevisionDescription.cmake )

# Get git revision
get_git_head_revision( GIT_REFSPEC GIT_SHA1 )
string( SUBSTRING "${GIT_SHA1}" 0 12 META_GIT_REVISION )
if( NOT GIT_SHA1 )
	set( META_GIT_REVISION "0" )
endif()

# Project options
option( OPTION_BUILD_EXAMPLES  "Build examples."                            ON )
option( OPTION_BUILD_DOCS      "Generate documentation."                    OFF )
option( OPTION_BUILD_TESTS     "Build tests in release."					OFF )

# Choosing Release as default building type.
set( default_build_type "Release" )
if( NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES )
	message( STATUS "Setting build type to '${default_build_type}' as none was specified." )
	set( CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE )
	
	set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo" )
endif()

message( STATUS "Compiling as: " ${CMAKE_BUILD_TYPE} )

# Choosing compiler (clang has preference).
if (CMAKE_CXX_COMPILER MATCHES ".*clang.*" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set (CMAKE_COMPILER_IS_CLANGXX 1)
endif()


#
# Project definition
#

# Declare new project
project( ${META_PROJECT_NAME}
	VERSION 		${META_PROJECT_VERSION_FULL}
	DESCRIPTION 	${META_PROJECT_DESCRIPTION}
	HOMEPAGE_URL 	${META_PROJECT_HOMEPAGE}
   	LANGUAGES 		C CXX)

# Only do these if this is the main project
if( CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME )
	# Generate compile information for IDEs
	set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
	
	# Let's nicely support folders in IDEs
	set_property( GLOBAL PROPERTY USE_FOLDERS ON )
endif()


# The compiled library
add_subdirectory(src)

# Examples using the library
add_subdirectory(examples EXCLUDE_FROM_ALL)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if( CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME )
	if( OPTION_BUILD_DOCS )
		add_subdirectory( docs )
	endif()

	if( OPTION_BUILD_TESTS OR ( CMAKE_BUILD_TYPE STREQUAL "Debug" ) )
		enable_testing()
		add_subdirectory( test )
	endif()
endif()
