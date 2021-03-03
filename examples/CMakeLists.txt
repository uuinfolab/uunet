cmake_minimum_required (VERSION 3.15...3.18)

# Meta information about the project
include( "${PROJECT_SOURCE_DIR}/project-meta-info.in" )

# Add aditional cmake scripts
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

# Adding individual examples manually. This should be automated.

ADD_EXECUTABLE( stores ${CMAKE_SOURCE_DIR}/examples/stores.cxx)
set_target_properties( stores PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries( stores ${META_LIBRARY_NAME} )

ADD_EXECUTABLE( operations ${CMAKE_SOURCE_DIR}/examples/operations.cxx)
set_target_properties( operations PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries( operations ${META_LIBRARY_NAME} )

ADD_EXECUTABLE( creation ${CMAKE_SOURCE_DIR}/examples/creation.cxx)
set_target_properties( creation PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries( creation ${META_LIBRARY_NAME} )