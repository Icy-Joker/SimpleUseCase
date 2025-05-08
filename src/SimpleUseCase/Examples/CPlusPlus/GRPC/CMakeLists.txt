#add_subdirectory("")#
add_subdirectory("SimpleGRPC")#
add_subdirectory("SimpleGRPCServer")#
add_dependencies("SimpleGRPCServer" "SimpleGRPC")#
add_subdirectory("SimpleGRPCProxy")#
add_dependencies("SimpleGRPCProxy" "SimpleGRPC")#
