#include <cstdio>

struct ClockOfTheLongNow
{
  /// Increment the year by one.
  void
  add_year ()
  {
    year++;
  }
  /// Sets the year to the specified value if it is 2019 or later.
  /// @param new_year The year to set.
  /// @return true if the year was set successfully, false if the year is invalid (less than 2019).
  bool
  set_year (int new_year)
  {
    if (new_year < 2019)
      return false;
    year = new_year;
    return true;
  }
  /// @return The current year of the clock.
  int
  get_year ()
  {
    return year;
  }

private:
  int year;
};

/**
 * @brief The main entry point of the program.
 *
 * This function creates a ClockOfTheLongNow object, attempts to set its year
 * to 2018, and then increments its year by one.
 *
 * @return 0
 */
int
main ()
{
  ClockOfTheLongNow clock;
  if (!clock.set_year (2018))
    {
      // will fail; 2018 < 2019
      clock.set_year (2019);
    }
  clock.add_year ();
  printf ("Year: %d", clock.get_year ());
}
