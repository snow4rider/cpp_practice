#include <cstdint>
#include <cstdio>

/**
 * @brief Applies a transformation function to each element of an input array
 *
 * This function takes an input array, an output array, and a transformation
 * function, and applies the transformation function to each element of the
 * input array, storing the result in the corresponding element of the output
 * array.
 *
 * @tparam Fn The type of the transformation function, which must be a callable
 *            object that takes a single argument of type `T` and returns a
 *            value of type `T`.
 * @tparam T The type of the elements of the input and output arrays.
 *
 * @param[in] fn The transformation function to apply.
 * @param[in] in The input array to transform.
 * @param[out] out The output array to store the transformed elements.
 * @param[in] len The number of elements in the input and output arrays.
 */
template <typename Fn, typename T>
void
transform (Fn fn, const T *in, T *out, size_t len)
{
  for (size_t i{}; i < len; i++)
    {
      out[i] = fn (in[i]);
    }
}

/**
 * @brief Main entry point of the program
 *
 * This program demonstrates the use of the transform() function template
 * with arrays of different types. It applies a lambda transformation that
 * scales each element by 10 and adds 5 to both integer and float arrays.
 *
 * The transformed elements are then printed to the console.
 */
int
main ()
{
  constexpr size_t l{ 3 };
  int base_int[]{ 1, 2, 3 }, a[l];
  float base_float[]{ 10.f, 20.f, 30.f }, b[l];
  auto translate = [] (auto x) { return 10 * x + 5; };
  transform (translate, base_int, a, l);
  transform (translate, base_float, b, l);

  for (size_t i{}; i < l; i++)
    {
      printf ("Element %zd: %d %f\n", i, a[i], b[i]);
    }
}