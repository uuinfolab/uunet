file (GLOB_RECURSE SOURCES_TEST 
	../core/*.cpp
	*.cpp)

add_executable (mnet-tests ${SOURCES_TEST})

set_target_properties(mnet-tests 
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}
)

target_link_libraries (mnet-tests
	uunet
	libgtest
	libgmock
	${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET mnet-tests
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:mnet-tests>
	COMMENT "Copying testing datasets"
	VERBATIM
)
