#include <cstdint>
#include <cstdio>

/**
 * @brief Returns true if doubling a uint8_t results in underflow.
 *
 * This function doubles the value of the uint8_t parameter, and then checks
 * if the value of the parameter is now less than the original value. If it is,
 * then the function returns true. Otherwise, it returns false.
 *
 * @param[inout] x The uint8_t to double and check for underflow
 * @return true if doubling the value of `x` results in underflow, false
 *         otherwise
 */
bool
double_return_overflow (uint8_t &x)
{
  const auto original = x;
  x *= 2;
  return original > x;
}

/**
 * @brief Demonstrates the behavior of unsigned integer overflow.
 *
 * This program initializes a uint8_t to 1 and continuously doubles it,
 * printing its value each time, until overflow occurs. The loop uses
 * double_return_overflow to detect when the doubling operation causes an
 * overflow, at which point the loop terminates.
 */
int
main ()
{
  uint8_t x{ 1 };
  printf ("uint8_t:\n===\n");
  while (!double_return_overflow (x))
    {
      printf ("%u ", x);
    }
}
