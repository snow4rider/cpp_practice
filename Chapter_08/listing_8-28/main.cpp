#include <cstdio>

struct FibonacciIterator
{
  /// @brief Check if the current Fibonacci number is not equal to x.
  ///
  /// This function returns true if the current Fibonacci number is not equal
  /// to x, and false if it is equal to x.
  bool
  operator!= (int x) const
  {
    return x >= current;
  }

  FibonacciIterator &
  operator++ ()
  {
    const auto tmp = current;
    current += last;
    last = tmp;
    return *this;
  }

  /// @brief Return the current Fibonacci number
  ///
  /// This function returns the value of the Fibonacci number at the current
  /// position in the sequence.
  int
  operator* () const
  {
    return current;
  }

private:
  int current{ 1 }, last{ 1 };
};

struct FibonacciRange
{
  /// @brief Construct a FibonacciRange object with a given maximum value
  ///
  /// This constructor creates a FibonacciRange object, which is a range of
  /// Fibonacci numbers up to a given maximum value. The range is half-open,
  /// meaning that the maximum value is not included in the range.
  ///
  /// @param[in] max The maximum value of the Fibonacci numbers in the range
  explicit FibonacciRange (int max) : max{ max } {}
  /// @brief Get an iterator to the beginning of the Fibonacci range
  ///
  /// This function returns an iterator pointing to the first Fibonacci number
  /// in the range. The first Fibonacci number is 1.
  FibonacciIterator
  begin () const
  {
    return FibonacciIterator{};
  }
  /// @brief Return the maximum value of the Fibonacci range
  ///
  /// This function returns the maximum value of the Fibonacci range. This
  /// value is not included in the range.
  int
  end () const
  {
    return max;
  }

private:
  const int max;
};

/// @brief Main entry point of the program
///
/// This function creates a FibonacciRange object to generate Fibonacci numbers
/// up to a specified maximum value (5000 in this case). It iterates over the
/// range using a custom FibonacciIterator, printing each Fibonacci number
/// to the console. The loop continues until the end of the range is reached.
int
main ()
{
  FibonacciRange range{ 5000 };
  const auto end = range.end ();
  for (auto x = range.begin (); x != end; ++x)
    {
      const auto i = *x;
      printf ("%d ", i);
    }
}
