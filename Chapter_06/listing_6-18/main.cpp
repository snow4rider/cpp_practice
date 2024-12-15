#include <cstdint>
#include <cstdio>
#include <type_traits>

/// @brief Return a string representation of a boolean
///
/// This function returns either "true" or "false" as a string, depending on
/// the value of the boolean parameter.
///
/// @param[in] x The boolean value to convert
/// @returns A string representation of the boolean value
constexpr const char *
as_str (bool x)
{
  return x ? "true" : "false";
}

/// @brief Main entry point of the program
///
/// This program prints out the boolean values of various std::is_integral
/// instantiations. It shows that the std::is_integral metafunction will
/// return true for integral types, false for non-integral types, and
/// false for reference and pointer types.
///
/// @returns 0 if the program is successful
int
main ()
{
  printf ("%s\n", as_str (std::is_integral<int>::value));
  printf ("%s\n", as_str (std::is_integral<const int>::value));
  printf ("%s\n", as_str (std::is_integral<char>::value));
  printf ("%s\n", as_str (std::is_integral<uint64_t>::value));
  printf ("%s\n", as_str (std::is_integral<int &>::value));
  printf ("%s\n", as_str (std::is_integral<int *>::value));
  printf ("%s\n", as_str (std::is_integral<float>::value));
}