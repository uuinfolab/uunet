find_package(Threads REQUIRED)

include(AddGoogleTest)

add_subdirectory (core)
add_subdirectory (net)
add_subdirectory (wnet)
add_subdirectory (tnet)
add_subdirectory (mnet)
#add_subdirectory (pnet)
add_subdirectory (xnet)
