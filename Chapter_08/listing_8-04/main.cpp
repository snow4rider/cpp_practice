#include <cstdint>
#include <cstdio>

struct RandomNumberGenerator
{
  /// Construct a RandomNumberGenerator with a given seed value.
  ///
  /// This constructor initializes the state of the random number generator
  /// with the given seed value. The seed can be any 32-bit unsigned integer.
  /// The generator will produce a well-distributed sequence of random numbers
  /// based on this value.
  ///
  /// @param seed The seed value used to initialize the random number
  ///              generator.
  explicit RandomNumberGenerator (uint32_t seed) : iterations{}, number{ seed }
  {
  }
  uint32_t next ();
  size_t get_iterations () const;

private:
  size_t iterations;
  uint32_t number;
};

/**
 * The main entry point of the program.
 *
 * This program demonstrates the usage of the RandomNumberGenerator
 * class. It creates an instance of the class with a given seed value,
 * generates random numbers with the next() function until a certain
 * value is reached, and prints the number of iterations required to
 * reach that value.
 */
int
main ()
{
  RandomNumberGenerator rng{ 0x4c4347 };
  while (rng.next () != 0x474343)
    {
      // Do nothing...
    }
  printf ("%zd", rng.get_iterations ());
}

/**
 * Generates a new random number.
 *
 * This function generates a new random 32-bit unsigned integer using a
 * linear congruential generator. The generator is seeded by the
 * RandomNumberGenerator constructor, and will produce a well-distributed
 * sequence of random numbers.
 *
 * @return A new random 32-bit unsigned integer.
 */
uint32_t
RandomNumberGenerator::next ()
{
  ++iterations;
  number = 0x3FFFFFFF & (0x41C64E6D * number + 12345) % 0x80000000;
  return number;
}

/**
 * Returns the number of times the next() function has been called.
 *
 * This function returns the number of times the next() function has been
 * called since the construction of the RandomNumberGenerator. This can be used
 * to measure the performance of the random number generator.
 *
 * @return The number of times next() has been called.
 */
size_t
RandomNumberGenerator::get_iterations () const
{
  return iterations;
}