
Install lcov
============
$ sudo apt-get install -y lcov

To Generate Coverage Report , Be in Project Root Directory
===========================================================

$ lcov -c -d . -o main_coverage.info --no-external
$ genhtml -o res main_coverage.info

To Generate from CMake, Be in Project Root Directory
======================================================

$ mkdir build

$ cd build

$ cmake ..

$ make 

$ make test // to run test cases

$ make coverage // to run coverage 

$ make launch-coverage-report // to launch firefox and show coveragae report


TO DO :
======
(1) Figure out , way to remove un ncessary stuff in coverage report
