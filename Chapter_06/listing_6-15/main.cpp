#include <cstdio>
#include <utility>

template <typename T> struct SimpleUniquePointer
{
  SimpleUniquePointer () = default;
  SimpleUniquePointer (T *pointer) : pointer{ pointer } {}

  /// @brief Destructor for SimpleUniquePointer
  ///
  /// This destructor deletes the owned pointer if it is not null, releasing
  /// the memory and ensuring proper cleanup of the managed object.
  ~SimpleUniquePointer ()
  {
    if (pointer)
      delete pointer;
  }
  SimpleUniquePointer (const SimpleUniquePointer &) = delete;
  SimpleUniquePointer &operator= (const SimpleUniquePointer &) = delete;

  /// @brief Move constructor for SimpleUniquePointer
  ///
  /// This constructor takes ownership of the object managed by the other
  /// SimpleUniquePointer object, and sets the other object's pointer to
  /// nullptr.
  SimpleUniquePointer (SimpleUniquePointer &&other) noexcept
      : pointer{ other.pointer }
  {
    other.pointer = nullptr;
  }
  SimpleUniquePointer &
  operator= (SimpleUniquePointer &&other) noexcept
  {
    if (pointer)
      delete pointer;
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }

  /// @brief Get the managed pointer
  ///
  /// This function returns the managed pointer. If the SimpleUniquePointer
  /// object does not own an object, this function returns nullptr.
  T *
  get ()
  {
    return pointer;
  }

private:
  T *pointer;
};

struct Tracer
{
  /**
   * @brief Constructs a Tracer object with the given name.
   *
   * This constructor initializes the Tracer object with a specified name
   * and prints a message indicating that the object has been constructed.
   *
   * @param name The name of the Tracer object.
   */
  Tracer (const char *name) : name{ name }
  {
    printf ("%s constructed.\n", name);
  }
  ~Tracer () { printf ("%s destructed.\n", name); }

private:
  const char *const name;
};

/// @brief Consumes a SimpleUniquePointer object.
///
/// This function takes a SimpleUniquePointer object as an argument and prints
/// a message indicating the address of the managed object.
void
consumer (SimpleUniquePointer<Tracer> consumer_ptr)
{
  printf ("(cons) consumer_ptr: 0x%p\n", consumer_ptr.get ());
}

/**
 * @brief The main entry point of the program.
 *
 * This function demonstrates the use of a SimpleUniquePointer to manage
 * a Tracer object. It creates a SimpleUniquePointer, prints the address
 * of the managed Tracer object, passes the pointer to a consumer function
 * using move semantics, and prints the address again to show that the
 * SimpleUniquePointer no longer owns the object.
 */
int
main ()
{
  auto ptr_a = SimpleUniquePointer<Tracer> (new Tracer{ "ptr_a" });
  printf ("(main) ptr_a: 0x%p\n", ptr_a.get ());
  consumer (std::move (ptr_a));
  printf ("(main) ptr_a: 0x%p\n", ptr_a.get ());
}