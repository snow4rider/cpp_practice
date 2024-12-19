#include <cstdio>
#include <limits>

/**
 * @brief A program that demonstrates the use of std::numeric_limits.
 *
 * This program assigns the maximum values of float, double, and long double
 * to variables of type double, long double, and float, respectively.
 * The value of long double::max() is assigned to a float, which is undefined
 * behavior.
 *
 * @note The output of this program is:
 * @code
 * x: 1.79769e+308
 * y: 1.18973e+4932
 * z: inf
 * @endcode
 */
int
main ()
{
  double x = std::numeric_limits<float>::max ();
  long double y = std::numeric_limits<double>::max ();
  float z = std::numeric_limits<long double>::max (); // Undefined Behavior
  printf ("x: %g\ny: %g\nz: %g");
}