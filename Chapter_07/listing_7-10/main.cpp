#include <cstdio>

/// @brief Print the address of a void pointer
///
/// This function takes a void pointer and prints its address in hexadecimal
/// format to the standard output.
void
print_addr (void *x)
{
  printf ("0x%p\n", x);
}

/**
 * @brief Main entry point of the program.
 *
 * This function demonstrates the use of the print_addr function by printing
 * the address of an integer variable and a null pointer in hexadecimal format.
 */
int
main ()
{
  int x{};
  print_addr (&x);
  print_addr (nullptr);
}