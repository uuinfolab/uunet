file (GLOB_RECURSE SOURCES_TEST
	*.cpp
)

add_executable (net-tests ${SOURCES_TEST})

set_target_properties(net-tests 
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}
)

target_link_libraries (net-tests
	uunet
	libgtest
	libgmock
	${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET net-tests
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:net-tests>
	COMMENT "Copying testing datasets"
	VERBATIM
)
