#include <cstdio>

/**
 * @brief Increases the power of rat things.
 *
 * @param nuclear_isotopes The amount of nuclear isotopes to add to the rat
 * things.
 *
 * This function increases the power of rat things by the given amount of
 * nuclear isotopes, and checks if the resulting power level is greater than
 * 1000. If it is, it prints a warning message.
 */
void
power_up_rat_thing (int nuclear_isotopes)
{
  static int rat_things_power = 200;
  rat_things_power = rat_things_power + nuclear_isotopes;
  const auto wate_heat = rat_things_power * 20;
  if (wate_heat > 1000)
    {
      printf ("Warning! Hot doggies!\n");
    }
  printf ("Rat things power: %d\n", rat_things_power);
}

/**
 * @brief Demonstrates the power-up process for rat things.
 *
 * This function calls `power_up_rat_thing` with different amounts of
 * nuclear isotopes to increase the power level of rat things. It
 * shows the progression of power levels and any warning messages that
 * occur if the power level exceeds safety thresholds.
 */
int
main ()
{
  power_up_rat_thing (100);
  power_up_rat_thing (500);
  return 0;
}