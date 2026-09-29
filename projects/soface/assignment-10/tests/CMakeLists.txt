project(tests)
include_directories(include)

add_executable(test_snippets src/test_snippets.cpp)
add_test(test_snippets test_snippets)
