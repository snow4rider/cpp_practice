#include <cstdio>

struct ClockOfTheLongNow 
{
  /// Construct a ClockOfTheLongNow with the given year, or 2019 if it is invalid
  ClockOfTheLongNow(int year_in) 
  {
    if(!set_year(year_in)) 
    {
      year = 2019;
    }
  }

  /// Construct a ClockOfTheLongNow with the current year (2019)
  ClockOfTheLongNow() 
  {
    year = 2019;
  }

  /// Increment the year by one.
  void add_year() 
  {
    year++;
  }

  /// Sets the year to the specified value if it is 2019 or later.
  /// @param new_year The year to set.
  /// @return true if the year was set successfully, false if the year is invalid (less than 2019).
  bool set_year(int new_year) 
  {
    if(new_year < 2019)
    {
      return false;
    }
    year = new_year;
    return true;
  }

  /// @return The current year of the clock.
  int get_year()
  {
    return year;
  }

  private:
  int year;
};

/**
 * @brief The main entry point of the program.
 *
 * This function creates a ClockOfTheLongNow object initialized to the year 2020
 * and prints the current year of the clock.
 */
int main() 
{
  ClockOfTheLongNow clock{ 2020 };
  printf("Year: %d", clock.get_year());
}
