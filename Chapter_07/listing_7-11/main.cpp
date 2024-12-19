#include <cstdint>
#include <cstdio>

/**
 * @brief Demonstrates conversion between integer types.
 *
 * This program initializes an int32_t variable and assigns it to an int64_t
 * variable using non-narrowing conversion. It then checks if the values are
 * equal and prints a message if the conversion was successful. A commented
 * line illustrates a narrowing conversion attempt, which would cause an error.
 */
int
main ()
{
  int32_t a = 100;
  int64_t b{ a };
  if (a == b)
    {
      printf ("Non-narrowing conversion\n");
      // int32_t c{ b }; // Error: narrowing conversion
    }
}