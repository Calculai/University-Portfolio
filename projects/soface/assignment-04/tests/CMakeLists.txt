project(tests)
include_directories(include)


add_executable(animals_test src/test_animals.cpp)
add_executable(observer_test src/test_observer.cpp)


target_link_libraries(animals_test zoo)
target_link_libraries(observer_test zoo)

add_test(animals_test animals_test)
add_test(observer_test observer_test)