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
