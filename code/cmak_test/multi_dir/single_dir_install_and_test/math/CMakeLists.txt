cmake_minimum_required(VERSION 2.8)

aux_source_directory(. root_files)
message("subdir files:" ${root_files})
add_library(funcs ${root_files})
install(FILES funcs.h DESTINATION include)
install(TARGETS funcs DESTINATION bin)
