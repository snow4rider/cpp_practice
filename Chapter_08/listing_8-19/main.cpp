#include <cstdio>

enum class Color
{
  Mauve,
  Pink,
  Russet
};

struct Result
{
  const char *name;
  Color color;
};

/**
 * @brief Observe the color of a joopleberry shrub
 *
 * This function takes the name of a joopleberry shrub and returns a Result
 * object with the name of the shrub and the color of the joopleberry shrub.
 *
 * @param[in] name The name of the joopleberry shrub to observe
 * @return A Result object with the name of the shrub and the color of the
 * shrub.
 */
Result
observe_shrub (const char *name)
{
  return Result{ name, Color::Russet };
}

/**
 * @brief Main function that observes and describes the color of a joopleberry
 * shrub.
 *
 * This function observes the color of the joopleberry shrub named "Zaphod"
 * using the `observe_shrub` function. It then uses a switch statement to
 * determine a description based on the observed color and prints a formatted
 * statement describing the shrub.
 */
int
main ()
{
  const char *description;
  switch (const auto result = observe_shrub ("Zaphod"); result.color)
    {
    case Color::Mauve:
      {
        description = "mauvey shade of pinky russet";
        break;
      }
    case Color::Pink:
      {
        description = "pinky shade of mauvey russet";
        break;
      }
    case Color::Russet:
      {
        description = "russety shade of pinky mauve";
        break;
      }
    default:
      {
        description = "enigmatic shade of whitish black";
      }
    }
  printf ("The other Shaltanac's joopleberry shrub is"
          " always a more %s.",
          description);
}
