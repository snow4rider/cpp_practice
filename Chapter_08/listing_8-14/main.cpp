#include <cstdio>

/**
 * @brief Determines the sign of a given number.
 *
 * This function returns a string indicating whether the input number
 * is positive, negative, or zero.
 *
 * @tparam T The type of the input number, which must support comparison
 *           to zero.
 * @param x The input number whose sign is to be determined.
 * @return A string: "positive" if the number is greater than zero,
 *         "negative" if it is less than zero, or "zero" if it is equal
 *         to zero.
 */

template <typename T>
constexpr const char *
sign (const T &x)
{
  const char *result{};
  if (x == 0)
    {
      result = "zero";
    }
  else if (x > 0)
    {
      result = "posititve";
    }
  else
    {
      result = "negative";
    }
  return result;
}

/**
 * @brief Test driver for the sign() function.
 *
 * Prints the sign of 100 as a float, -200 as an int, and 0 as a char.
 *
 * @return 0 upon success.
 */
int
main ()
{
  printf ("float 100 is %s\n", sign (100.0f));
  printf ("int  -200 is %s\n", sign (-200));
  printf ("char    0 is %s\n", sign (char{}));
}
