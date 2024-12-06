#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

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

  /// @brief Destructor for SimpleString
  ///
  /// This destructor releases the memory allocated for the buffer.
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

  /// @brief Move constructor for SimpleString
  ///
  /// This constructor creates a new SimpleString object by "stealing" the
  /// contents of another SimpleString object. It takes ownership of the
  /// buffer of the other object and sets the other object's buffer to
  /// nullptr and its size to 0.
  SimpleString (SimpleString &&other) noexcept : max_size (other.max_size),
                                                 buffer (other.buffer),
                                                 length (other.length)
  {
    other.length = 0;
    other.buffer = nullptr;
    other.max_size = 0;
  }
  SimpleString &
  operator= (const SimpleString &other)
  {
    if (this == &other)
      return *this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    std::strncpy (buffer, other.buffer, max_size);
    return *this;
  }
  SimpleString &
  operator= (SimpleString &&other) noexcept
  {
    if (this == &other)
      return *this;
    delete[] buffer;
    buffer = other.buffer;
    length = other.length;
    max_size = other.max_size;
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
    return *this;
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

/// @brief Demonstrates the move assignment of SimpleString objects
///
/// This function creates two SimpleString objects and appends text to each.
/// It then prints their contents before and after moving the contents of one
/// object to the other using the move assignment operator, demonstrating that
/// the source object is left in a valid but unspecified state.
int
main ()
{
  SimpleString a{ 50 };
  a.append_line ("We apologise for the");
  SimpleString b{ 50 };
  b.append_line ("Last message");
  a.print ("a");
  b.print ("b");
  b = std::move (a);
  // a is "moved-from"
  b.print ("b");
}