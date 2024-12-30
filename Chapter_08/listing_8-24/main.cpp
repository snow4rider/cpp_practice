#include <cstdio>

/**
 * @brief Prints out the elements of an array to the console.
 *
 * This program uses a range-based for loop to iterate over the array x and
 * prints out each element to the console, separated by a space.
 *
 * @return 0 if the program is successful.
 */
int
main ()
{
  const int x[]{ 1, 1, 2, 3, 5, 8 };
  for (const auto element : x)
    {
      printf ("%d ", element);
    }
}
