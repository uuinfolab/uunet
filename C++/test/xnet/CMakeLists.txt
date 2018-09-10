file (GLOB_RECURSE SOURCES_TEST
	*.cpp
)

add_executable (xnet-tests ${SOURCES_TEST})

set_target_properties(xnet-tests 
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}
)

target_link_libraries (xnet-tests
	uunet
	libgtest
	libgmock
	${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET xnet-tests
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:xnet-tests>
	COMMENT "Copying testing datasets"
	VERBATIM
)
