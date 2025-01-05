#include <cstdint>
#include <cstdio>

/// @brief Count the number of times a character appears in a string
///
/// This function takes a null-terminated string and counts the number of
/// times the character `x` appears in it. The count is returned at the end.
size_t
const_if (char x, const char *str)
{
  size_t index{}, results{};
  while (str[index])
    {
      if (str[index] == x)
        {
          results++;
        }
      index++;
    }
  return results;
}

/// @brief Main entry point of the program
///
/// This function creates instances of the CountIf functor to count the
/// occurrences of specific characters in given strings. It then prints the
/// results for each string.
int
main ()
{
  auto sally = const_if ('s', "Sally sells seashells by the seashore.");
  printf ("Sally: %zd\n", sally);
  auto sailor = const_if ('s', "Sailor went to sea to see what he could see.");
  printf ("Sailor: %zd\n", sailor);
  auto buffalo = const_if ('f', "Buffalo buffalo Buffalo buffalo"
                                "buffalo buffalo buffalo buffalo");
  printf ("Buffalo: %zd\n", buffalo);
}