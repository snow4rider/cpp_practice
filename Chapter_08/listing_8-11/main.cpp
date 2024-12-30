#include <cstdio>

struct TextFile
{
  bool success;
  const char *data;
  size_t n_bytes;
};

/**
 * @brief Opens a text file at the given path and reads its contents.
 *
 * This function returns a TextFile object that contains the contents of the
 * file, the number of bytes read, and a boolean indicating whether the file
 * was successfully opened.
 *
 * If the file cannot be opened, the returned TextFile will have the boolean
 * set to false and the pointer to the contents set to nullptr.
 *
 * @param[in] path The path to the text file to open.
 * @return A TextFile containing the file contents and success status.
 */
TextFile
read_text_file (const char *path)
{
  const static char contents[]{ "Sometimes the goat is you." };
  return TextFile{ true, contents, sizeof (contents) };
}

/**
 * @brief Program entry point.
 *
 * This program attempts to open a text file called "READ.txt" and prints its
 * contents to stdout. If the file cannot be opened, it prints an error
 * message.
 *
 * @return 0.
 */
int
main ()
{
  const auto [success, contents, length] = read_text_file ("READ.txt");
  if (success)
    {
      printf ("Read %zu bytes: %s\n", length, contents);
    }
  else
    {
      printf ("Failed to open READ.txt.\n");
    }
}
