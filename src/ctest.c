/*
MIT License

Copyright (c) 2025 broskobandi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/** \file src/ctest.c
 * \brief Implementation for the test library.
 * \details This file contains the definitions of the public functions 
 * and the global variables for the test library. */

#include "../include/ctest.h"
#include <stddef.h> /* For size_t */
#include <stdio.h>

size_t g_tests;
size_t g_passed;
size_t g_failed;

/** Evaluates whether 'expr' is true or false and
 * updates the corresponding internal global varriables.
 * \param expr The expression to be evaluated. */
void ctest(bool expr, const char *name, const char *file, int line) {
	if (!expr) {
		printf("\033[31m[TEST FAILED]:\033[0m %s\n\tFile: %s\n\tLine: %d\n",
		name, file, line);
		g_failed++;
	} else {
		g_passed++;
	}
	g_tests++;
}

/** Prints the test results based. */
void ctest_print_results() {
	if (!g_failed) {
		printf("\033[32m[ALL %lu TESTS PASSED]\033[0m\n", g_tests);
	} else {
		printf("\033[32m[%lu TESTS PASSED]\033[0m\n", g_passed);
		printf("\033[31m[%lu TESTS FAILED]\033[0m\n", g_failed);
	}
}
