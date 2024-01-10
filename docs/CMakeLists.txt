cmake_minimum_required( VERSION 3.15...3.23 )

# Add aditional cmake scripts
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

find_package( Doxygen )
if ( NOT Doxygen_FOUND )
	message ( FATAL_ERROR "Doxygen is needed to build the documentation." )
endif()

set ( DOXYGEN_IN ${CMAKE_CURRENT_LIST_DIR}/uunet.doxyfile )
set ( DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs )
configure_file ( ${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY )
		
add_custom_target( doc ALL
	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating API documentation with Doxygen"
)
