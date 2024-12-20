#include <cstdio>

struct Tracer
{
  /**
   * @brief Constructs a Tracer object with the given name.
   *
   * Prints a message indicating that the object is being constructed.
   *
   * @param name The name of the Tracer object.
   */
  Tracer (const char *name) : name{ name }
  {
    printf ("%s constructor\n", name);
  }
  ~Tracer () { printf ("%s destructed\n", name); }

private:
  const char *const name;
};

/**
 * @brief The main entry point of the program.
 *
 * This function demonstrates the use of Tracer objects to trace the
 * construction and destruction of objects. It creates a Tracer object for
 * the main function, and then creates two Tracer objects each in two
 * nested blocks. The output shows the order in which the Tracer objects
 * are constructed and destructed.
 */
int
main ()
{
  Tracer main{ "main" };
  {
    printf ("block a\n");
    Tracer a1{ "a1" };
    Tracer a2{ "a2" };
  }
  {
    printf ("block b\n");
    Tracer b1{ "b1" };
    Tracer b2{ "b2" };
  }
}