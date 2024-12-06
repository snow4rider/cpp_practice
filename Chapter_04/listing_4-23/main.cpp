#include <cstdio>

/**
 * @brief Increments the given integer by one.
 *
 * @param x The integer to be incremented.
 * @return The incremented integer.
 */
int
add_one_to (int x)
{
  x++;
  return x;
}

/**
 * @brief Demonstrates the usage of the add_one_to function by incrementing an
 * integer and printing the result.
 */
int
main ()
{
  auto original = 1;
  auto result = add_one_to (original);
  printf ("Original: %d; Result: %d\n", original, result);
  return 0;
}