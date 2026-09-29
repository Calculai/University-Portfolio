project(tests)
include_directories(include)


add_executable(test_dict src/test_dict.cpp)

add_test(test_dict test_dict)