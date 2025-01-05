#include <cstdint>
#include <cstdio>

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

private:
  const char x;
};

/**
 * @brief Demonstrates the use of the CountIf functor to count character
 * occurrences.
 *
 * This function creates instances of the CountIf functor to count the
 * occurrences of specific characters in given strings. It then prints the
 * results for each string.
 */
int
main ()
{
  CountIf s_counter{ 's' };
  auto sally = s_counter ("Sally sells seashells by the seashore.");
  printf ("Sally: %zd\n", sally);
  auto sailor = s_counter ("Sailor went to sea to see what he could see.");
  printf ("Sailor: %zd\n", sailor);
  auto buffalo = CountIf{ 'f' }("Buffalo buffalo Buffalo buffalo"
                                "buffalo buffalo buffalo buffalo");
  printf ("Buffalo: %zd\n", buffalo);
}