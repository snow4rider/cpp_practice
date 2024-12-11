struct BaseClass
{
};

struct DerivedClass : public BaseClass
{
};

/**
 * A function that takes a DerivedClass object by reference and does nothing
 * with it.  It is used to demonstrate that DerivedClass can be passed to it.
 *
 * @param[in] derived a DerivedClass object
 */
void
all_about_that (DerivedClass &derived)
{
}

/**
 * The main entry point of the program.
 *
 * Demonstrates an attempt to pass a BaseClass object to the function
 * all_about_that, which expects a DerivedClass object, illustrating
 * the issue of type mismatch in inheritance hierarchies.
 */
int
main ()
{
  BaseClass base;
  // all_about_that(base); // No! Trouble!
}