#include <cstdio>

static int rat_things_power = 200;

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
  rat_things_power = rat_things_power + nuclear_isotopes;
  const auto waste_heat = rat_things_power * 20;
  if (waste_heat > 1000)
    {
      printf ("Warning! Hot doggies!\n");
    }
}

/**
 * @brief Shows off the power of rat things.
 *
 * This program increases the power of rat things by adding nuclear isotopes to
 * them. It prints a message after each power up, indicating the new power
 * level. If the power level gets too high, it prints a warning message.
 */
int
main ()
{
  printf ("Rat things power: %d\n", rat_things_power);
  power_up_rat_thing (100);
  printf ("Rat things power: %d\n", rat_things_power);
  power_up_rat_thing (500);
  printf ("Rat things power: %d\n", rat_things_power);
  return 0;
}