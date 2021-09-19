cmake_minimum_required(VERSION 2.8)
set(app_VERSION_MAJOR 1)
set(app_VERSION_MINOR 0)
project(multi_dir_single_dir)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
message("env:" $ENV{CXXFLAGS})
message("env:" ${CXXFLAGS})
message("env:" ${CMAKE_CXX_FLAGS_DEBUG})

include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(pow HIVE_POW)

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
install(TARGETS a.out DESTINATION bin)
install(FILES config.h DESTINATION include)

enable_testing()
add_test(test_run a.out)

add_test(test_hello a.out)
set_tests_properties(test_hello
    PROPERTIES PASS_REGULAR_EXPRESSION "hello")

add_test(test_world a.out)
set_tests_properties(test_world
    PROPERTIES PASS_REGULAR_EXPRESSION "world")

add_test(test_err a.out)
set_tests_properties(test_err
    PROPERTIES PASS_REGULAR_EXPRESSION "ERROR")

macro(do_test arg result)
    add_test(do_test_${arg} a.out)
    set_tests_properties(do_test_${arg}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

do_test(hello "hello")
do_test(world "world")
do_test(error "error")

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
    "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${app_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${app_VERSION_MINOR}")
include(CPack)

