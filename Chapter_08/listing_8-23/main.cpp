#include <cstdio>

/**
 * @brief Prints out the value of each element in the array x, alongside its
 * index.
 *
 * This program prints the value of each element in the array x, alongside its
 * index. For example, if the array contains the values 1, 1, 2, 3, 5, and 8,
 * the program will print out the following:
 *
 * i: x[i]
 * 0: 1
 * 1: 1
 * 2: 2
 * 3: 3
 * 4: 5
 * 5: 8
 *
 * @return 0 if successful.
 */
int
main ()
{
  const int x[]{ 1, 1, 2, 3, 5, 8 };
  printf ("i: x[i]\n");
  for (int i{}; i < 6; i++)
    {
      printf ("%d: %d\n", i, x[i]);
    }
}
