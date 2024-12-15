#include <cstdio>

/// @brief Increment the short pointed to by target
///
/// This function takes a void pointer to a short and increments the value
/// stored at that location. The incremented value is then returned.
///
/// @param[in] target A pointer to the short to be incremented
/// @return The incremented value of the short
short
incremt_as_short (void *target)
{
  auto as_short = static_cast<short *> (target);
  *as_short = *as_short + 1;
  return *as_short;
}

/// @brief Demonstrate the usage of the incremt_as_short function
///
/// This program creates a short with the value 665, increments it using the
/// incremt_as_short function and prints the result.
int
main ()
{
  short beast{ 665 };
  auto mark_of_the_beast = incremt_as_short (&beast);
  printf ("%d is the mark of the beast\n", mark_of_the_beast);
}