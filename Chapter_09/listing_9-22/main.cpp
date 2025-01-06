#include <cstdint>
#include <cstdio>

/**
 * @brief Program entry point.
 *
 * This program demonstrates the use of a mutable lambda to maintain a running
 * total of character counts. It creates a lambda to count occurrences of a
 * character in a string, and uses a captured variable to accumulate the total
 * of counts from multiple strings. It then prints out the total count after
 * each string.
 *
 * @return 0.
 */
int
main ()
{
  char to_count{ 's' };
  size_t tally{};
  auto s_counter = [=] (const char *str) mutable {
    size_t index{}, result{};
    while (str[index])
      {
        if (str[index] == to_count)
          result++;
        index++;
      }
    tally += result;
    return result;
  };
  auto sally = s_counter ("Sally sells seashells by the seashore.");
  printf ("Tally: %zd\n", tally);
  printf ("Sally: %zd\n", sally);
  printf ("Tally: %zd\n", tally);
  auto sailor = s_counter ("Sailor went to sea to see what he could see.");
  printf ("Sailor: %zd\n", sailor);
  printf ("Tally: %zd\n", tally);
}