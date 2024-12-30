#include <cstdio>

namespace BroopKidron13::Shaltanac
{
enum class Color
{
  Mauve,
  Pink,
  Russet
};
}

using String = const char[260];
using ShaltanacColor = BroopKidron13::Shaltanac::Color;

/**
 * @brief Main entry point for the program.
 *
 * This program checks if the user's preferred color of joopleberry shrub is
 * equal to Russet, and if so, prints out a phrase praising the beauty of
 * the shrub.
 *
 * @return 0 if successful.
 */
int
main ()
{
  const auto my_color{ ShaltanacColor::Russet };
  String saying{ "The other Shaltanc's joopleberry shrub is "
                 "always a more mauvey shade" };
  if (my_color == ShaltanacColor::Russet)
    {
      printf ("%s", saying);
    }
}
