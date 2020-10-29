lcov -c --directory . -output-file main_coverage.info
genhtml main_coverage.info --output-directory out
