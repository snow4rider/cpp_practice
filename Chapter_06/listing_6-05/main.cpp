#include <cstdio>

/// @brief Print the current value of the timer at memory address 0x1000.
///
/// This function prints the value stored at memory address 0x1000 to the
/// console. This value is expected to be a timer.
///
/// @note This function assumes that the value stored at memory address 0x1000
/// is a valid unsigned long.
int
main ()
{
  auto timer = reinterpret_cast<const unsigned long *> (0x1000);
  printf ("Timer is %lu.", *timer);
}
