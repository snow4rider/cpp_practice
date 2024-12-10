struct BaseClass
{
};
struct DerivedClass : public BaseClass
{
};
/**
 * This function takes a BaseClass object by reference and does not do anything
 * with it.  It is used to demonstrate that DerivedClass can be passed to it.
 *
 * @param[in] base a BaseClass object
 */
void
are_belong_to_us (BaseClass &base)
{
}

/**
 * The main entry point of the program.
 *
 * Demonstrates that DerivedClass can be passed to are_belong_to_us, since
 * it is a subclass of BaseClass.
 */
int
main ()
{
  DerivedClass derived;
  are_belong_to_us (derived);
}