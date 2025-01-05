#include <cstdio>

/**
 * @brief Adds an integer to a float.
 *
 * @param[in] a The float to add to.
 * @param[in] b The integer to add.
 * @return The result of the addition.
 */
float
add (float a, int b)
{
  return a + b;
}

/**
 * @brief Subtracts an integer from a float.
 *
 * @param a The float to subtract from.
 * @param b The integer to subtract.
 * @return The result of the subtraction.
 */
float
subtract (float a, int b)
{
  return a - b;
}

/**
 * @brief Demonstrates the use of a function pointer.
 *
 * This program demonstrates that a function pointer can be initialized to 0,
 * assigned the address of a function, and invoked like a regular function.
 * The program prints the result of "100 + 20" and "100 - 20".
 */
int
main ()
{
  const float first{ 100 };
  const int second{ 20 };

  float (*operation) (float, int){};
  printf ("operation initialized to 0x%p\n", operation);

  operation = &add;
  printf ("&add = 0x%p\n", operation);
  printf ("%g + %d = %g\n", first, second, operation);

  operation = subtract;
  printf ("&subtract = 0x%p\n", operation);
  printf ("%g - %d = %g\n", first, second, operation);
}
