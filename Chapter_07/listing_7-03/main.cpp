#include <cstdio>
#include <limits>
#include <stdexcept>

struct CheckedInterger
{
  CheckedInterger (unsigned int value) : value{ value } {}

  /// @brief Add the specified unsigned int to the stored value.
  ///
  /// Performs a checked addition of the specified unsigned int to the stored
  /// value. If the result would overflow, throws a std::overflow_error.
  ///
  /// @param other the unsigned int to add to the stored value.
  /// @return a new CheckedInteger containing the result of the addition.
  CheckedInterger
  operator+ (unsigned int other) const
  {
    CheckedInterger result{ value + other };
    if (result.value < value)
      {
        throw std::overflow_error{ "Overflow" };
      }
    return result;
  }

  const unsigned int value;
};

/// @brief Main entry point of the program.
///
/// This function demonstrates the usage of the CheckedInterger struct,
/// performing a checked addition operation. It adds 200 to a CheckedInterger
/// initialized with 100 and prints the result. It also attempts to add the
/// maximum unsigned int value to the same CheckedInterger and catches any
/// overflow error, printing the exception message.
int
main ()
{
  CheckedInterger a{ 100 };
  auto b = a + 200;
  printf ("a + 200 = %u\n", b.value);
  try
    {
      auto c = a + std::numeric_limits<unsigned int>::max ();
    }
  catch (const std::overflow_error &e)
    {
      printf ("(a + max) Exception: %s\n", e.what ());
    }
}