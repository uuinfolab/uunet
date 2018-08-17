file (GLOB_RECURSE SOURCES_TEST
	../core/*.cpp
	*.cpp
)

add_executable (wnet-tests ${SOURCES_TEST})

set_target_properties(wnet-tests 
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}
)

target_link_libraries (wnet-tests
	uunet
	libgtest
	libgmock
	${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET wnet-tests
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:net-tests>
	COMMENT "Copying testing datasets"
	VERBATIM
)
