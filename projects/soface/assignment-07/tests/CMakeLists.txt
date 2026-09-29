project(tests)
include_directories(include)


add_executable(test_matrix src/test_matrix.cpp)

target_link_libraries(test_matrix Mat)

add_test(test_matrix test_matrix)