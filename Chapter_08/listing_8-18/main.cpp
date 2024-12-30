#include <cstdio>
#include <stdexcept>
#include <type_traits>

/**
 * @brief Returns the value of the input, dereferencing if it's a pointer.
 *
 * This function checks if the input is a pointer type. If it is, it
 * dereferences the pointer and returns the value it points to. If the
 * pointer is null, it throws a runtime error. If the input is not a
 * pointer, it simply returns the input value itself.
 *
 * @tparam T The type of the input, which can be a pointer or a non-pointer.
 * @param x The input value, which may be a pointer or a non-pointer.
 * @return The dereferenced value if the input is a pointer, otherwise
 *         the input value itself.
 * @throws std::runtime_error if the input is a null pointer.
 */

template <typename T>
auto
value_of (T x)
{
  if constexpr (std::is_pointer<T>::value)
    {
      if (!x)
        {
          throw std::runtime_error{ "Null pointer dereference." };
        }
      return *x;
    }
  else
    {
      return x;
    }
}

/**
 * @brief The main entry point of the program.
 *
 * This function demonstrates the use of the `value_of` function by
 * creating a local variable `level` and taking its address and reference.
 * It then uses `value_of` to print the value of the variable through
 * a pointer and a reference, incrementing the value each time. After
 * that, it sets the pointer to null and attempts to use `value_of` on it,
 * which throws an exception. The exception is then caught and its
 * message is printed.
 *
 * @return 0 if successful.
 */
int
main ()
{
  unsigned long level{ 8998 };
  auto level_ptr = &level;
  auto &level_ref = level;
  printf ("Power level = %lu\n", value_of (level_ptr));
  ++*level_ptr;
  printf ("Power level = %lu\n", value_of (level_ref));
  ++level_ref;
  printf ("It's over %lu!\n", value_of (level++));
  try
    {
      level_ptr = nullptr;
      value_of (level_ptr);
    }
  catch (const std::exception &e)
    {
      printf ("Exception: %s\n", e.what ());
    }
}
