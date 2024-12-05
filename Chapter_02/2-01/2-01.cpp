#include <cstdio>

/**
 * @brief Demonstrate integer literals.
 *
 * This program prints out the following:
 * - The decimal value of a unsigned short integer represented by the
 *   binary literal 0b10101010.
 * - The decimal value of an integer represented by the octal literal 0123.
 * - The decimal value of an unsigned long long integer represented by the
 *   hexadecimal literal 0xFFFFFFFFFFFFFFFF.
 */
int main() {
  unsigned short a = 0b10101010;
  printf("%hu\n", a);

  int b = 0123;
  printf("%d\n",b);

  unsigned long long d = 0xFFFFFFFFFFFFFFFF;
  printf("%llu\n", d);
}
