#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString
{
  /// @brief Create a SimpleString object with a buffer of `max_size` elements
  ///
  /// @param[in] max_size The maximum size of the string
  ///
  /// The buffer is initialized to be empty (i.e. the 0th element is set to 0).
  /// If `max_size` is 0, a `std::runtime_error` is thrown.
  SimpleString (size_t max_size) : max_size{ max_size }, length{}
  {
    if (max_size == 0)
      {
        throw std::runtime_error{ "Max size must be at least 1." };
      }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  ~SimpleString () { delete[] buffer; }

  /// @brief Print the string with a specified tag
  ///
  /// This function outputs the stored string to stdout, prefixed by a
  /// user-defined tag.
  ///
  /// @param[in] tag A string to print before the stored string
  void
  print (const char *tag) const
  {
    printf ("%s: %s", tag, buffer);
  }

  /// @brief Append a line of text to the string
  ///
  /// This function appends the provided line of text to the internal buffer of
  /// the SimpleString object. If the resulting string would exceed the maximum
  /// size, the function returns false and no text is appended.
  ///
  /// @param[in] x The line of text to append
  /// @return true if the line was appended successfully, false if it would
  ///         have made the string too long
  bool
  append_line (const char *x)
  {
    const auto x_len = strlen (x);
    if (x_len + length + 2 > max_size)
      return false;
    strncpy (buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

private:
  size_t max_size;
  char *buffer;
  size_t length;
};

struct SimpleStringOwner
{
  /// @brief Create a SimpleStringOwner object with a buffer of 10 elements
  ///
  /// If the provided string cannot be appended to the internal buffer
  /// (i.e. because the string would be too long), a `std::runtime_error`
  /// exception is thrown.
  SimpleStringOwner (const char *x) : string{ 10 }
  {
    if (!string.append_line (x))
      {
        throw std::runtime_error{ "Not enough memory!" };
      }
    string.print ("Constructed");
  }
  ~SimpleStringOwner () { string.print ("About to destroy"); }

private:
  SimpleString string;
};

/// @brief Test that the SimpleStringOwner destructor is called
///
/// This tests that the destructor for SimpleStringOwner is called when
/// the object is destroyed.
int
main ()
{
  SimpleStringOwner x{ "x" };
  printf ("x is alive\n");
  return 0;
}