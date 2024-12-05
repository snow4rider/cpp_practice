#include <cstdio>


/**
 * @brief Demonstrate printf() specifiers
 *
 * This program shows how to use various printf() specifiers to print
 * out different types of data.
 *
 * @note The output of this program will be:
 * @code
 * Avogadro's Number: 6.022141e+23 6.022141 6.022141
 * Hogwars's Platform: 9.750000e+00 9.750000 9.75
 * @endcode
 */
int main() {
  double an = 6.0221409e23;
  printf("Avogadro's Number: %le %lf %lg\n", an, an, an);

  float hp = 9.75;
  printf("Hogwars's Platform: %e %f %g\n", hp, hp, hp);

}
