cmake_minimum_required(VERSION 2.8)
project(multi_files)
aux_source_directory(. all_file)
add_executable(a.out ${all_file})