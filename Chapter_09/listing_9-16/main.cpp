#include <cstdio>

/**
 * @brief Demonstrates a lambda with default arguments.
 *
 * This program demonstrates how a lambda can have default arguments. A lambda
 * expression is defined with a parameter 'x' that defaults to 1. The lambda is
 * then invoked with and without the default argument.
 *
 * @return 0
 */
int
main ()
{
  auto increment = [] (auto x, int y = 1) { return x + y; };
  printf ("increment(10)    = %d\n", increment (10));
  printf ("increment(10, 5) = %d\n", increment (10, 5));
}