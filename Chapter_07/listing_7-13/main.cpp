#include <cstdio>

/**
 * @brief Crashes the program by trying to write to a read-only string
 *
 * This function takes a pointer to a read-only string and attempts to modify
 * the first character of the string. This is undefined behavior and will
 * cause the program to crash.
 *
 * @param[in] read_only The read-only string to attempt to write to
 */
void
trainwreck (const char *read_only)
{
  auto as_unsigned = (unsigned char *)read_only;
  *as_unsigned = 'b'; // Crashes
}

/**
 * @brief Demonstrates the effect of modifying a read-only string.
 *
 * This program initializes a read-only string and prints its value before
 * and after passing it to the `trainwreck` function, which attempts to
 * modify the string. This operation results in undefined behavior.
 */
int
main ()
{
  auto ezra = "Ezra";
  printf ("Before trainwreck: %s\n", ezra);
  trainwreck (ezra);
  printf ("After trainwreck: %s\n", ezra);
}