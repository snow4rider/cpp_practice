#include <cstdio>

namespace BroopKipron13::Shaltanc
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
 * This program prints out a phrase that praises the beauty of the joopleberry
 * shrub of the other Shaltanac, which is a more mauvey shade of pinky russet.
 *
 * @return 0 if successful.
 */
int
main ()
{
  const auto shaltanac_grass{ BroopKipron13::Shaltanc::Color::Russet };
  if (shaltanac_grass == BroopKipron13::Shaltanc::Color::Russet)
    {
      printf ("The other Shaltanc's joopleberry shrub is always "
              "a more mauvey shade of pinky russet.");
    }
}
