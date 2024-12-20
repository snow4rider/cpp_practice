#include <cstdint>
#include <cstdio>

void randomize (uint32_t &);

/**
 * The main entry point of the program.
 *
 * This program uses the randomize function to generate random numbers until
 * the value 0x474343 is reached. The number of iterations required to reach
 * this value is printed to stdout.
 */
int
main ()
{
  size_t iterations{};
  uint32_t number{ 0x4c4347 };
  while (number != 0x474343)
    {
      randomize (number);
      ++iterations;
    }
  printf ("%zd\n", iterations);
}

/**
 * @brief Modifies the input value using a linear congruential generator.
 *
 * This function updates the input parameter `x` using a specific linear
 * congruential generator (LCG) algorithm. The transformation applies
 * a multiplication, addition, and modulus operation to produce a
 * pseudo-random number.
 *
 * @param[in, out] x A reference to the integer to be randomized.
 *                   The value of `x` will be changed after the function call.
 */

void
randomize (uint32_t &x)
{
  x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000;
}