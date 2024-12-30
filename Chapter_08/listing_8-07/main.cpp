#include <cstdio>

namespace BroopKipron13::Shaltanac
{
enum class Color
{
  Mauve,
  Pink,
  Russet
};

struct JoopleberryShrub
{
  const char *name;
  Color shade;
};

/// @brief Check if a joopleberry shrub is more mauvey
///
/// This function takes a joopleberry shrub and checks if it is more mauvey,
/// i.e., if its shade is equal to Color::Mauve.
///
/// @param shrub The joopleberry shrub to check.
/// @return true if the shrub is more mauvey, false otherwise.
bool
is_more_mauvey (const JoopleberryShrub &shrub)
{
  return shrub.shade == Color::Mauve;
}
}

using namespace BroopKipron13::Shaltanac;

/**
 * @brief The main entry point of the program.
 *
 * This program checks if the other Shaltanac's joopleberry shrub is more
 * mauvey and prints a phrase that praises the beauty of the joopleberry shrub.
 *
 * @return 0 if successful.
 */
int
main ()
{
  const JoopleberryShrub yours{ "The other Shaltanac", Color::Mauve };

  if (is_more_mauvey (yours))
    {
      printf ("%s's joopleberry shrub is always a more mauvey shade of pinky "
              "russet.",
              yours.name);
    }
}
