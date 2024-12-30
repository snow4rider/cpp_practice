#include <cstdio>

namespace BroopKipron13::Shaltanac
{
enum class Color
{
  Mauve,
  Pink,
  Russet
};
}

/**
 * @brief The main entry point of the program.
 *
 * This program evaluates the color of Shaltanac's grass.
 * If it is Russet, it prints a phrase that praises the color
 * of the other Shaltanac's joopleberry shrub.
 *
 * @return 0 if successful.
 */

int
main ()
{
  using BroopKipron13::Shaltanac::Color;
  const auto shaltanac_grass = Color::Russet;
  if (shaltanac_grass == Color::Russet)
    {
      printf ("The other Shaltanac's joopleberry shrub is always "
              "a more mauvey shade of pinky russet.");
    }
}
