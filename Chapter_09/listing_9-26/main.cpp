#include <cstdio>
#include <functional>

/**
 * @brief Prints a message to standard output.
 *
 * This is a static function that may be stored in a std::function and
 * invoked later.
 */
void
static_function ()
{
  printf ("A static function.\n");
}

/**
 * @brief Entry point of the program.
 *
 * This program demonstrates the use of a std::function to store and
 * invoke a lambda expression and a static function. It first assigns
 * a lambda that prints a message, and then reassigns the std::function
 * to a static function, printing both messages to standard output.
 *
 * @return 0
 */
int
main ()
{
  std::function<void ()> func{ [] { printf ("A lambda.\n"); } };
  func ();
  func = static_function;
  func ();
}