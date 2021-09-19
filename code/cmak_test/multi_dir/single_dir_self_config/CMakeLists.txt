cmake_minimum_required(VERSION 2.8)
project(multi_dir_single_dir)
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
option(USE_MYMATH
    "user provided math implementation" ON)
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} funcs)
endif(USE_MYMATH)

aux_source_directory(. root_file)
message("find root files" ${root_file})
add_executable(a.out ${root_file})
target_link_libraries(a.out ${EXTRA_LIBS})