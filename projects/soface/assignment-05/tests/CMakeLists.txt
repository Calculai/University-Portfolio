project(tests)
include_directories(include)


add_executable(filter_tests src/test_filters.cpp)

target_link_libraries(filter_tests zoo)

add_test(filter_tests filter_tests)