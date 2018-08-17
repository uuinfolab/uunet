file (GLOB_RECURSE SOURCES_TEST
	../core/*.cpp
	*.cpp
)

add_executable (tnet-tests ${SOURCES_TEST})

set_target_properties(tnet-tests 
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}
)

target_link_libraries (tnet-tests
	uunet
	libgtest
	libgmock
	${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET tnet-tests
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:tnet-tests>
	COMMENT "Copying testing datasets"
	VERBATIM
)
