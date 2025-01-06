#include <cstdint>
#include <cstdio>
#include <functional>

struct CountIf
{
  CountIf (char x) : x{ x } {}
  /// @brief Count the number of times a character appears in a string
  ///
  /// This function takes a null-terminated string and counts the number of
  /// times the character `x` appears in it. The count is returned at the end.
  size_t
  operator() (const char *str) const
  {
    size_t index{}, result{};
    while (str[index])
      {
        if (str[index] == x)
          result++;
        index++;
      }
    return result;
  }

private:
  const char x;
};

/// @brief Count the number of spaces in a string
///
/// This function takes a null-terminated string and counts the number of
/// spaces that appear in it. The count is returned at the end.
size_t
count_spaces (const char *str)
{
  size_t index{}, result{};
  while (str[index])
    {
      if (str[index] == ' ')
        result++;
      index++;
    }
  return result;
}

std::function<size_t (const char *)> funcs[]{ count_spaces, CountIf{ 'e' },
                                              [] (const char *str) {
                                                size_t index{};
                                                while (str[index])
                                                  index++;
                                                return index;
                                              } };

auto text = "Sailor went to sea to see what he could see.";

/// @brief Main entry point of the program
///
/// This function demonstrates the use of a std::function array to store and
/// invoke different functions. It first defines a few functions, including a
/// lambda, and then stores them in an array. It then iterates over the array
/// and invokes each function, storing the result in a variable and printing it
/// to standard output.
int
main ()
{
  size_t index{};
  for (const auto &func : funcs)
    {
      printf ("func #%zd: %zd\n", index++, func (text));
    }
}