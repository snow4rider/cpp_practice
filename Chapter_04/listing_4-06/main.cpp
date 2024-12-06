#include <cstdio>

struct Tracer
{
  /**
   * Constructs a Tracer object with the given name.
   *
   * Prints a message showing that the object is being constructed.
   *
   * @param name the name of the Tracer object
   */
  Tracer (const char *name) : name{ name }
  {
    printf ("%s constructor\n", name);
  }
  ~Tracer () { printf ("%s destructor\n", name); }

private:
  const char *const name;
};

static Tracer t1{ "Static variable" };
thread_local Tracer t2{ "Thread-local variable" };

/**
 * The main entry point of the program.
 *
 * Prints a series of messages before and after constructing local and
 * dynamically allocated objects.
 */
int
main ()
{
  printf ("A\n");
  Tracer t3{ "Local variable" };
  printf ("B\n");
  const auto *t4 = new Tracer{ "Dynamic variable" };
  printf ("C\n");
  return 0;
}