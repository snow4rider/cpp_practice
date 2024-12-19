#include <cstdio>

/**
 * @brief Causes undefined behavior by attempting to modify a read-only string.
 *
 * This function receives a pointer to a read-only string and attempts to
 * change its first character. Doing so leads to undefined behavior, which
 * typically results in a program crash.
 *
 * @param[in] read_only A pointer to the read-only string to modify
 */
void
trainwreck (const char *read_only)
{
  // auto as_unsigned = reinterpret_cast<unsigned char*>(read_only);
  //*as_unsigned = 'b'; // Crashes
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