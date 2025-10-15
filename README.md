# test
## Simple test utility written in C.
The goal of the project is to provide a simple test utility for C projects.
## Features
### Macro helper for ease of use
The CTEST() macro automates the process of setting the global variables.
### Color coded results
Easily distinguishable result values are printed at the end of the test program's run.
## Prerequisites
- cmake (for building the library)
## Installation
```bash
git clone https://github.com/broskobandi/ctest.git &&
cd ctest &&
mkdir build &&
cd build &&
cmake .. &&
make &&
sudo make install
```
## Usage
```c
/* Include the library. */
#include <ctest.h>

/* A function to test. */
int add_numbers(int a, int b) {
	return a + b;
}

int main(void) {
	/* Test for different cases. */
	CTEST(add_numbers(1, 2) == 3);
	CTEST(add_numbers(1, 3) == 3);

	/* Print the results. */
	ctest_print_results();
	return 0;
}

/* This produces the following output:
[TEST FAILED]: add_numbers(1, 3) == 3
        File: example/example.c
        Line: 9
[1 TESTS PASSED]
[1 TESTS FAILED]
 * */
```
