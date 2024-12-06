#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800
{
  /// \brief Constructor for CyberdyneSeries800.
  ///
  /// This constructor will print a message "I'm a friend of Sarah Connor.".
  CyberdyneSeries800 () { printf ("I'm a friend of Sarah Connor."); }
  /// \brief Destructor for CyberdyneSeries800.
  ///
  /// This destructor will throw std::runtime_error with the message "I'll be
  /// back.".
  ~CyberdyneSeries800 () { throw std::runtime_error{ "I'll be back." }; }
};

/// \brief Main entry point of the program.
///
/// This function demonstrates a simple try/catch block.
/// It will print "I'm a friend of Sarah Connor." and then
/// throw an exception with the message "Come with me if you want to live.".
/// The exception will be caught and the message "Caught exception: Come with
/// me if you want to live." will be printed to the console.
int
main ()
{
  try
    {
      CyberdyneSeries800 t800;
      throw std::runtime_error{ "Come with me if you want to live." };
    }
  catch (const std::exception &e)
    {
      printf ("Caught exception: %s\n", e.what ());
    }
}