cmake_minimum_required (VERSION 3.15...3.18)

# Meta information about the project
include( "${PROJECT_SOURCE_DIR}/project-meta-info.in" )

# Add aditional cmake scripts
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

# Adding individual examples

set(example_list "")

file( GLOB EXAMPLES *.cxx )
foreach( example_cxxfile ${EXAMPLES} )
	get_filename_component(example_exec ${example_cxxfile} NAME_WE)
	add_executable( ${example_exec} ${example_cxxfile} )
	list(APPEND example_list ${example_exec})
	set_target_properties( ${example_exec} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
	target_link_libraries( ${example_exec} ${META_LIBRARY_NAME} )
endforeach( example_cxxfile ${EXAMPLES} )

add_custom_target(examples)
add_dependencies(examples ${example_list})