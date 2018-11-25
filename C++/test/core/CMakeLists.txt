file (GLOB_RECURSE SOURCES_TEST *.cpp)

add_executable(core-tests ${SOURCES_TEST})
#add_gtest(core-tests)


set_target_properties(core-tests 
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}
)

target_link_libraries (core-tests
	uunet
	gtest
	gmock
	${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET core-tests
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:core-tests>
	COMMENT "Copying testing datasets"
	VERBATIM
)
