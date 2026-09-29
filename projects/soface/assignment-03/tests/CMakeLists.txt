project(tests)
include_directories(include)


add_executable(calc_bad_test src/test_int_calculator_bad.cpp)
add_executable(calc_test src/test_int_calculator.cpp)
add_executable(tcalc_test src/test_template_calculator.cpp)
add_executable(logger_test src/test_logger.cpp)


target_link_libraries(calc_bad_test calc)
target_link_libraries(calc_test calc)
target_link_libraries(tcalc_test calc)
target_link_libraries(logger_test calc)

add_test(calc_bad_test calc_bad_test)
add_test(calc_test calc_test)
add_test(tcalc_test tcalc_test)
add_test(logger_test logger_test)