#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString
{
  /// @brief Create a SimpleString object with a buffer of `max_size` elements
  ///
  /// @param[in] max_size The maximum size of the string
  ///
  /// The buffer is initialized to be empty (i.e., the 0th element is set to
  /// 0). If `max_size` is 0, a `std::runtime_error` is thrown.
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
  /// @brief Copy constructor for SimpleString
  ///
  /// This constructor creates a new SimpleString object by copying the
  /// contents of another SimpleString object. It allocates a new buffer
  /// of the same size and copies the data from the other buffer.
  ///
  /// @param[in] other The SimpleString object to copy from
  SimpleString (const SimpleString &other)
      : max_size{ other.max_size }, buffer{ new char[other.max_size] },
        length{ other.length }
  {
    std::strncpy (buffer, other.buffer, max_size);
  }
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
    std::strncpy (buffer + length, x, max_size - length);
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

/// @brief Append a line to the string and discard the change
///
/// This function is an example of how passing a SimpleString object by value
/// can result in lost changes. The change is made to the local copy of the
/// object, which is destroyed when the function returns.
void
foo (SimpleString x)
{
  x.append_line ("This change is lost.");
}

/// @brief Main entry point for the program
///
/// This function demonstrates how passing a SimpleString object by value
/// results in the loss of changes. The object is created, a change is made
/// to the local copy of the object, but the original object is unchanged.
int
main ()
{
  SimpleString a{ 20 };
  foo (a); // Invokes copy constructor
  a.print ("Still empty");
}