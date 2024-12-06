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

  /// @brief Print the string to stdout
  ///
  /// @param[in] tag A string to print before the string
  void
  print (const char *tag) const
  {
    printf ("%s: %s", tag, buffer);
  }

  /// @brief Append a line of text to the string
  ///
  /// @param[in] x The line of text to append
  /// @return true if the line was appended successfully, false if it would
  ///         have made the string too long
  bool
  append_line (const char *x)
  {
    const auto x_len = strlen (x);
    if (x_len + length + 2 > max_size)
      {
        return false;
      }
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

/**
 * @brief Tests the SimpleString class
 *
 * This program tests the SimpleString class by appending strings to it and
 * printing the result. It also tests that the SimpleString class won't allow
 * appending a string that is too big.
 */
int
main ()
{
  SimpleString string{ 115 };
  string.append_line ("Starbuck, whaddya hear?");
  string.append_line ("Nothin' but the rain.");
  string.print ("A");
  string.append_line ("Grab your gun and bring the cat in.");
  string.append_line ("Aye-aye sir, coming home.");
  string.print ("B");
  if (!string.append_line ("Galactica!"))
    {
      printf ("String was not big enough to append another message.");
    }
}