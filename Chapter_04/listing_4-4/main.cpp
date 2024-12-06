#include <cstdio>

struct RatThing
{
  static int rat_things_power;
  /**
   * @brief Increases the power of rat things.
   *
   * @param nuclear_isotopes The amount of nuclear isotopes to add to the rat
   * things.
   *
   * This function increases the power of rat things by the given amount of
   * nuclear isotopes, and checks if the resulting power level is greater than
   * 10000. If it is, it prints a warning message.
   */
  static void
  power_up_rat_thing (int nuclear_isotopes)
  {
    rat_things_power = rat_things_power + nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if (waste_heat > 10000)
      {
        printf ("Warning! Hot doggie!\n");
      }
    printf ("Rat-thing power: %d\n", rat_things_power);
  }
};

int RatThing::rat_things_power = 200;

/**
 * @brief Show off the power of rat things.
 *
 * This function calls `power_up_rat_thing` with different amounts of
 * nuclear isotopes to increase the power level of rat things. It
 * shows the progression of power levels and any warning messages that
 * occur if the power level exceeds safety thresholds.
 */
int
main ()
{
  RatThing::power_up_rat_thing (100);
  RatThing::power_up_rat_thing (500);
}