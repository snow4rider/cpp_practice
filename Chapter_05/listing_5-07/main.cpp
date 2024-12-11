#include <cstdio>

struct BaseClass
{
  /// @brief Get the final message of the base class
  ///
  /// This function returns a pointer to a string that is the final message
  /// of the base class. The message is "We apologise for the incontnence.".
  virtual const char *
  final_message () const
  {
    return "We apologise for the incontnence.";
  }
};

struct DerivedClass : BaseClass
{
  /// @brief Get the final message of the derived class
  ///
  /// This function returns a pointer to a string that is the final message
  /// of the derived class. The message is "We apologise for the
  /// inconvenience.".
  const char *
  final_message () const override
  {
    return "We apologise for the inconvenience.";
  }
};

/**
 * The main entry point of the program.
 *
 * This function prints the final message of BaseClass, DerivedClass, and a
 * reference to DerivedClass that is treated as a BaseClass. The first two
 * print the final message of their respective classes, and the third prints
 * the final message of the derived class, showing that the reference is
 * treated polymorphically.
 *
 * @return 0 if successful.
 */
int
main ()
{
  BaseClass base;
  DerivedClass derived;
  BaseClass &ref = derived;
  printf ("BaseClass:    %s\n", base.final_message ());
  printf ("DerivedClass: %s\n", derived.final_message ());
  printf ("BaseClass&:   %s\n", ref.final_message ());
}