#include <cstdio>
#include <utility>

/**
 * Prints out whether the argument is an lvalue reference.
 *
 * @param x An lvalue int reference.
 */
void
ref_type (int &x)
{
  printf ("lvalue reference %d\n", x);
}

/**
 * Prints out whether the argument is an rvalue reference.
 *
 * @param x An rvalue int reference.
 */
void
ref_type (int &&x)
{
  printf ("rvalue reference %d\n", x);
}

/**
 * @brief Demonstrates the usage of ref_type function.
 *
 * This function creates an integer variable `x`, and then calls the
 * `ref_type` function with `x`, a literal value `2`, and an expression
 * `x + 2`. It showcases the different reference types handled by the
 * `ref_type` function.
 */
int
main ()
{
  auto x = 1;
  ref_type (std::move (x));
  ref_type (2);
  ref_type (x + 2);
}