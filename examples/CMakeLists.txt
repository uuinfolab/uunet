cmake_minimum_required (VERSION 3.0 FATAL_ERROR)
project (example LANGUAGES CXX)

# Choosing Release as default building type.
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug ... FORCE)
endif()

# Make sure you use C++14 at least
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This generates compile commands for my linter, not needed.
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Again, we need some extra things.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -fno-inline -std=c++14")

# Just in case later we want to have them.
include_directories (include)

# Subtitute the route to uunet in your computer
set(MULTINET_INCLUDES "/usr/local/include/libuunet")

# Include uunet includes.
include_directories (${MULTINET_INCLUDES})

link_directories(${CMAKE_SOURCE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

file(COPY data DESTINATION .)

ADD_EXECUTABLE(network_creation network_creation.cxx)
TARGET_LINK_LIBRARIES(network_creation uunet)

ADD_EXECUTABLE(graph_operations graph_operations.cxx)
TARGET_LINK_LIBRARIES(graph_operations uunet)
