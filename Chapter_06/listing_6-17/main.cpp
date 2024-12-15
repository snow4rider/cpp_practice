/**
 * @brief Computes the square of the given value.
 *
 * This template function takes a value of an arbitrary type `T` and
 * computes its square by multiplying it by itself. This function can be used
 * with any type `T` that supports multiplication.
 *
 * @tparam T The type of the value to be squared.
 * @param value The value to be squared.
 * @return The square of the given value.
 */
template <typename T>
T
square (T value)
{
  return value * value;
}

/*************  ✨ Codeium Command ⭐  *************/
/**
 * @brief A test program that demonstrates the usage of the `square` template
 *        function.
 *
 * This program showcases the `square` template function. It creates a `char`
 * variable `my_char` and attempts to call the `square` function with its
 * address. This results in a compile error, because the `square` function
 * cannot be called with a pointer argument.
 *
 * @return 0
 */
/******  c18673a7-9a9b-4fd4-8fcf-fcb0bb07de54  *******/
int
main ()
{
  char my_char{ 'Q' };
  // auto result = square(&my_char); // compile error
}