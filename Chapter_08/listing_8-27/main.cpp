#include <cstdio>

struct FibonacciIterator
{
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

/// @brief The main entry point of the program
///
/// This function prints the sequence of Fibonacci numbers up to 5000
/// by using a range-based for loop with a FibonacciRange object. The
/// FibonacciRange object is used to generate the sequence, providing
/// a begin iterator and an end condition. The loop iterates over the
/// range and prints each number to stdout.
int
main ()
{
  for (const auto i : FibonacciRange{ 5000 })
    {
      printf ("%d ", i);
    }
}
