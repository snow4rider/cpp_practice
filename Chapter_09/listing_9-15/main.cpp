#include <cstdint>
#include <cstdio>

/// @brief Apply a transformation function to each element of an input array
///
/// This function takes an input array and applies a provided transformation
/// function to each element, storing the result in an output array. The
/// transformation is defined by a callable object that takes an integer as
/// input and returns an integer.
///
/// @tparam Fn The type of the transformation function
/// @param fn The transformation function to apply
/// @param in The input array of integers
/// @param out The output array to store the transformed elements
/// @param length The number of elements in the input and output arrays
template <typename Fn>
void
transform (Fn fn, const int *in, int *out, size_t length)
{
  for (size_t i = 0; i < length; i++)
    {
      out[i] = fn (in[i]);
    }
}

/// @brief Main entry point of the program
///
/// This program demonstrates the use of the transform() function by applying
/// three different transformations to an array of integers.
///
/// The first transformation sets each element to 1.
/// The second transformation keeps each element unchanged.
/// The third transformation scales each element by 10 and adds 5.
///
/// The program prints the transformed elements to the console.
int
main ()
{
  constexpr size_t len{ 3 };
  int base[]{ 1, 2, 3 }, a[len], b[len], c[len];
  transform ([] (int x) { return 1; }, base, a, len);
  transform ([] (int x) { return x; }, base, b, len);
  transform ([] (int x) { return 10 * x + 5; }, base, c, len);
  for (size_t i{}; i < len; i++)
    {
      printf ("Element %zd: %d %d %d\n", i, a[i], b[i], c[i]);
    }
}