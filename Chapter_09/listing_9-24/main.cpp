#include <cstdint>
#include <cstdio>

struct LambdaFactory
{
  LambdaFactory (char in) : to_count{ in }, tally{} {}
  /// @brief Create a lambda that counts the occurrences of a character in a
  /// string. The lambda will accumulate the total of counts from multiple
  /// strings in the "tally" member of the LambdaFactory.
  ///
  /// The lambda takes a null-terminated string as its argument and returns
  /// the number of times the character appears in the string. The total of
  /// all counts from multiple strings is stored in the "tally" member of the
  /// LambdaFactory.
  auto
  make_lambda ()
  {
    return [this] (const char *str) {
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
  }
  const char to_count;
  size_t tally;
};

/**
 * @brief Main entry point of the program.
 *
 * This function demonstrates the use of a lambda created by the LambdaFactory
 * to count occurrences of a character in various strings. It initializes a
 * LambdaFactory with the character to count, generates the lambda, and then
 * uses it to process multiple strings. The results and the running tally are
 * printed after processing each string.
 */
int
main ()
{
  LambdaFactory factory{ 's' };
  auto lambda = factory.make_lambda ();
  printf ("Tally: %zd\n", factory.tally);
  printf ("Sally: %zd\n", lambda ("Sally sells seashells by the seashore."));
  printf ("Tally: %zd\n", factory.tally);
  printf ("Sailor: %zd\n",
          lambda ("Sailor went to sea to see what he could see."));
  printf ("Tally: %zd\n", factory.tally);
}