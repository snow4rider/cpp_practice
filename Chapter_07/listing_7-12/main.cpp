#include <cstdint>
#include <cstdio>
#include <limits>

/**
 * @brief A program that demonstrates that narrowing conversions are allowed
 * for built-in types.
 *
 * This program assigns the maximum value of int64_t to an int32_t variable and
 * checks if the values are equal. If the values are not equal, it prints a
 * message indicating that the conversion was narrowing.
 *
 * @return 0
 */
int
main ()
{
  int64_t b = std::numeric_limits<int64_t>::max ();
  int32_t c (b); // The compiler abides.
  if (c != b)
    {
      printf ("Narrowing conversion\n");
    }
}