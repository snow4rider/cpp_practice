#include <cstdio>
#include <stdexcept>

struct Groucho
{
  /// \brief Forget a value, unless it's 0xFACE, in which case an exception is
  /// thrown.
  ///
  /// This function is a play on words. It's a function named `forget`, which
  /// takes a value and does nothing with it. But if the value is 0xFACE, it
  /// throws an exception. This is a play on the phrase "I'd be glad to make an
  /// exception."
  void
  forget (int x)
  {
    if (x == 0xFACE)
      {
        throw std::runtime_error{ "I'd be glad to make an exception." };
      }
    printf ("Forgot 0x%x\n", x);
  }
};

/// \brief Test the Groucho class.
///
/// This main function tests the Groucho class. It creates an instance of the
/// class and calls the forget function on it three times, with values 0xC0DE,
/// 0xFACE, and 0xC0FFEE. The forget function throws an exception for 0xFACE,
/// and we catch the exception here.
int
main ()
{
  Groucho groucho;
  try
    {
      groucho.forget (0xC0DE);
      groucho.forget (0xFACE);
      groucho.forget (0xC0FFEE);
    }
  catch (std::runtime_error &e)
    {
      printf ("exception caught with message: %s\n", e.what ());
    }
}