# test
## Simple test utility written in C.
The goal of the project is to provide a simple test utility for C projects.
## Features
### Macro helper for ease of use
The CTEST() macro automates the process of setting the global variables.
### Color coded results
Easily distinguishable result values are printed at the end of the test program's run.
## Dependencies
### For compilation
- gcc
## Installation
```bash
git clone https://gitlab.com/broskobandi/test.git &&
make &&
sudo make install
```
## Uninstallation
```bash
cd test &&
sudo make uninstall
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
Compile the program using this library with -L/usr/local/lib -lctest flags.
## Documentation
Make sure doxygen is installed.
```bash
cd test &&
make doc
```
