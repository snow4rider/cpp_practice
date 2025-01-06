#include <cstdio>
#include <functional>

/**
 * @brief Entry point of the program.
 *
 * This program demonstrates what happens when invoking a
 * std::function that has not been assigned a function.
 *
 * @returns 0
 */
int
main ()
{
  std::function<void ()> func;
  try
    {
      func ();
    }
  catch (const std::bad_function_call &e)
    {
      printf ("Exception: %s\n", e.what ());
    }
}