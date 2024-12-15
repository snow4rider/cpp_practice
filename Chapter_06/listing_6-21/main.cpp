#include <cstddef>
#include <cstdio>
#include <type_traits>

template <typename T>
concept bool
Averageable ()
{
  return std::is_default_constructible<T>::value
         && std::is_copy_constructible<T>::value && requires (T a, T b)
  {
    {
      a + b
    } -> T;
    {
      a / b
    } -> T;
  };
}

/**
 * @brief Calculates the mean of a given array of values.
 *
 * This function computes the average of an array of values of type T, where T
 * satisfies the Averageable concept. It iterates through the array, summing
 * all the values, and then divides the total by the length of the array to
 * obtain the mean.
 *
 * @tparam T A type that satisfies the Averageable concept.
 * @param[in] values The array of values to calculate the mean of.
 * @param[in] length The number of elements in the array.
 * @return The mean of the values in the array.
 */
template <Averageable T>
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
 * char) and prints the result.
 *
 * @return 0 if successful
 */
int
main ()
{
  const double nums_d[]{ 1.0f, 2.0f, 3.0f, 4.0f };
  const auto result1 = mean (nums_d, 4);
  printf ("double: %f\n", result1);

  const float nums_f[]{ 1.0, 2.0, 3.0, 4.0 };
  const auto result2 = mean (nums_f, 4);
  printf ("float: %f\n", result2);

  const char nums_c[]{ 1, 2, 3, 4 };
  const auto result3 = mean (nums_c, 4);
  printf ("char: %d\n", result3);
}