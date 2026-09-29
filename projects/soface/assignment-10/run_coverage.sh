lcov --capture --directory build/ --output-file coverage.info
genhtml coverage.info --output-directory coverage_info