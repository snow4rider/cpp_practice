#include <cstdio>
#include <stdexcept>

/**
 * @brief Safely cast a value from one type to another with narrowing check
 *
 * This template function attempts to cast a value of type `From` to type `To`
 * using static_cast. It then casts the result back to the original type to
 * verify that no data was lost in the conversion. If the value changes during
 * this process, an exception is thrown, indicating a narrowing conversion
 * error.
 *
 * @tparam To The target type to cast to.
 * @tparam From The source type of the value.
 * @param value The value to be casted.
 * @return The value casted to the target type.
 * @throws std::runtime_error if the conversion is narrowing.
 */

template <typename To, typename From>
To
narrow_cast (From value)
{
  const auto converted = static_cast<To> (value);
  const auto backwards = static_cast<From> (converted);
  if (backwards != value)
    {
      throw std::runtime_error{ "Narrowed!" };
    }
  return converted;
}

/**
 * @brief The main entry point of the program.
 *
 * This program demonstrates the narrow_cast template function. It creates two
 * integers, perfect and cyclic, and attempts to narrow cast them to shorts.
 * The first succeeds, but the second fails and throws a std::runtime_error.
 *
 * @return 0
 */
int
main ()
{
  int perfect{ 496 };
  const auto perfect_short = narrow_cast<short> (perfect);
  printf ("perfect_short: %d\n", perfect_short);
  try
    {
      int cyclic{ 142857 };
      const auto cyclic_short = narrow_cast<short> (cyclic);
      printf ("cyclic_short: %d\n", cyclic_short);
    }
  catch (const std::exception &e)
    {
      printf ("Exception: %s\n", e.what ());
    }
}
