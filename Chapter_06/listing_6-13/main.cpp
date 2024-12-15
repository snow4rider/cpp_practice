#include <cstddef>
#include <cstdio>

/**
 * @brief Calculates the mean of a given array of values.
 *
 * @param[in] values The array of values to calculate the mean of
 * @param[in] length The length of the array
 *
 * @return The mean of the values
 */
template <typename T>
T
mean (const T *values, size_t length)
{
  T result{};
  for (size_t i{}; i < length; i++)
    {
      result += values[i];
    }
  return result / length;
}

/**
 * @brief The main entry point of the program.
 *
 * This program demonstrates the usage of the mean template function.
 * It calculates the mean of three different arrays of numbers (double, float,
 * size_t) and prints the result.
 *
 * @return 0 if successful
 */
int
main ()
{
  const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
  const auto result1 = mean (nums_d, 4);
  printf ("double: %f\n", result1);

  const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
  const auto result2 = mean (nums_f, 4);
  printf ("float: %f\n", result2);

  const size_t nums_c[]{ 1, 2, 3, 4 };
  const auto result3 = mean (nums_c, 4);
  printf ("size_t: %lu\n", result3);
}