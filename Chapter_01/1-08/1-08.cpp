#include <cstdio>

/**
 * Computes the step function of a given integer.
 * 
 * The step function returns:
 *  - -1 if the input is negative
 *  -  1 if the input is positive
 *  -  0 if the input is zero
 *
 * @param x the input integer value
 * @returns the step value corresponding to the input
 */
int step_function(int x) {
  int result = 0;

  if (x < 0) {
    result = -1;
  } else if (x > 0) {
    result = 1;
  }
  return result;
}

/**
 * A simple test driver for the step_function.
 *
 * This program exercises the step_function by calling it with three
 * different values, and prints the input and corresponding step value
 * to the console.
 */
int main () {
  int num1 = 42;
  int result1 = step_function(num1);

  int num2 = 0;
  int result2 = step_function(num2);

  int num3 = -32767;
  int result3 = step_function(num3);

  printf("Num1: %d, Step: %d\n", num1, result1);
  printf("Num2: %d, Step: %d\n", num2, result2);
  printf("Num3: %d, Step: %d\n", num3, result3);
  return 0;
}
