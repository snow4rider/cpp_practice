#include <cstdint>
#include <cstdio>

/**
 * @brief Doubles the value of a uint8_t and checks for overflow.
 *
 * This function takes a uint8_t by reference, doubles its value, and then
 * checks if the value of the parameter is now less than the original value.
 * If it is, then the function returns true. Otherwise, it returns false.
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
 * @brief Main entry point of the program.
 *
 * This program prints out the results of successively doubling a uint8_t,
 * starting with 1 and stopping when the doubling operation causes an
 * underflow.
 *
 * @return 0 if successful.
 */
int
main ()
{
  uint8_t x{ 1 };
  printf ("uint8_t:\n===\n");
  do
    {
      printf ("%u ", x);
    }
  while (!double_return_overflow (x));
}
