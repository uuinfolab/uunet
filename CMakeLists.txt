cmake_minimum_required (VERSION 3.15...3.23)

if (${CMAKE_VERSION} VERSION_LESS 3.15)
	cmake_policy (VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project (uunet LANGUAGES C CXX)

set (PROJECT_VENDOR 			"Matteo Magnani")
set (PROJECT_CONTACT 			"matteo.magnani@it.uu.se")
set (PROJECT_URL 			    "https://github.com/uuinfolab/uunet")

# Setting the project version
file (READ				"${CMAKE_CURRENT_LIST_DIR}/VERSION" PROJECT_VERSION_FULL)
string (REGEX REPLACE 			"[\n\r]" "" PROJECT_VERSION_FULL "${PROJECT_VERSION_FULL}")
string (REGEX REPLACE 			"^([0-9]+)\\.[0-9]+\\.[0-9]+$" "\\1" PROJECT_VERSION_MAJOR "${PROJECT_VERSION_FULL}")
string (REGEX REPLACE 			"^[0-9]+\\.([0-9]+)\\.[0-9]+$" "\\1" PROJECT_VERSION_MINOR "${PROJECT_VERSION_FULL}")
string (REGEX REPLACE 			"^[0-9]+\\.[0-9]+\\.([0-9]+)$" "\\1" PROJECT_VERSION_PATCH "${PROJECT_VERSION_FULL}")

set (PROJECT_VERSION 			"${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
math (EXPR LIBRARY_VERSION_MAJOR 	"${PROJECT_VERSION_MAJOR}")
set (LIBRARY_VERSION_MINOR 		"${PROJECT_VERSION_MINOR}")
set (LIBRARY_VERSION_PATCH 		"${PROJECT_VERSION_PATCH}")
set (LIBRARY_VERSION 			"${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}")
set (LIBRARY_VERSION_FULL 		"${LIBRARY_VERSION}.${LIBRARY_VERSION_PATCH}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add aditional cmake scripts
list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Choosing compiler (clang has preference).
if (CMAKE_CXX_COMPILER MATCHES ".*clang.*" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set (CMAKE_COMPILER_IS_CLANGXX 1)
endif()

# Choosing Release as default building type.
set (default_build_type "Release")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message (STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set (CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
	
	set_property (CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message (STATUS "Compiling as: " ${CMAKE_BUILD_TYPE})


# Adding compiler options. The non-modern style has been used for compatibility reasons with cmake < 3.8

if (MSVC)
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
else()
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O3 -ggdb -g3 -Wall -Wextra")
    
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libc++")
    else()
        # nothing special for gcc at the moment
    endif()
endif()

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)


# Generate uunet target
file (GLOB_RECURSE SOURCES ext/eclat/*.c ext/infomap/*.cpp libs/*.cpp src/*.cpp)
add_library (uunet SHARED ${SOURCES})

# Include private components
target_include_directories (uunet PUBLIC
	ext/eclat/eclat/src
	ext/eclat/tract/src
	ext/eclat/math/src
	ext/eclat/util/src
	ext/eclat/apriori/src
	ext/infomap
    ext/boost)

add_definitions(-DNS_INFOMAP -DONLY_C_LOCALE=1)

# Include public components
target_include_directories (uunet PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	$<INSTALL_INTERFACE:include>)

# Compile uunet target
if (${CMAKE_VERSION} VERSION_LESS 3.8)
	set_target_properties (uunet PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED YES
		CXX_EXTENSIONS NO)
else()
	target_compile_features (uunet PUBLIC cxx_std_17)
	set_target_properties (uunet PROPERTIES CXX_EXTENSIONS OFF)
endif()

# Disabling doxygen documentation by default.
option (DOXY "Generate DoxyGen documentation" OFF)
if (DOXY)
	find_package (Doxygen)
	
	if (DOXYGEN_FOUND)
		set (DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/uunet.doxyfile)
		set (DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
		configure_file (${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
		
		add_custom_target (doc ALL
			COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
			COMMENT "Generating API documentation with Doxygen"
			VERBATIM)
	else()
		message (FATAL_ERROR "Doxygen is needed to build the documentation.")
	endif()
endif (DOXY)

# Installing targets
install (TARGETS uunet
	EXPORT uunet-target
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin)

install(DIRECTORY "src/" # source directory
        DESTINATION "include/uunet" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.hpp" # select header files
)

install(DIRECTORY "src/" # source directory
        DESTINATION "include/uunet" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.ipp" # select header files
)

install(DIRECTORY "libs/" # source directory
        DESTINATION "include/uunet" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.hpp" # select header files
)

install(DIRECTORY "libs/" # source directory
        DESTINATION "include/uunet" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.ipp" # select header files
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

# Generate tests only during Debug.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_subdirectory(test)
endif()
