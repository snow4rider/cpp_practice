#include <cstdio>
#include <stdexcept>

/**
 * @brief Simulates a pitcher throwing a knuckleball.
 *
 * This function is marked `[[noreturn]]` because it always throws an exception
 * and never returns normally. It is intended to be used as a demonstration
 * of how to propagate an exception up the call stack.
 */
[[noreturn]] void
pitcher ()
{
  throw std::runtime_error{ "Knuckleball." };
}

/**
 * @brief The main entry point of the program.
 *
 * This function calls the @c pitcher() function and catches any
 * exceptions that are thrown. If an exception is caught, it prints
 * the exception's message to the console.
 */
int
main ()
{
  try
    {
      pitcher ();
    }
  catch (const std::exception &e)
    {
      printf ("exception: %s\n", e.what ());
    }
}
