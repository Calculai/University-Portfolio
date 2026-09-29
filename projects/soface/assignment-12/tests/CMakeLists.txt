project(tests)
include_directories(include)


add_executable(test_wargame src/test_wargame.cpp)
target_link_libraries(test_wargame wargame)

add_test(test_wargame test_wargame)