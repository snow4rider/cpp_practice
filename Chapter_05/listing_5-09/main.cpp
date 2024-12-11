#include <cstdio>

struct BaseClass
{
};

struct DerivedClass : BaseClass
{
  DerivedClass () { printf ("DerivedClass() invoked\n"); }
  ~DerivedClass () { printf ("~DerivedClass() invoked\n"); }
};

///@brief main entry point of the program.
///
/// This function constructs a DerivedClass object x, and then deletes it as a
/// BaseClass*. The purpose of this program is to illustrate that when a
/// DerivedClass object is deleted as a BaseClass*, the DerivedClass destructor
/// is not called, which is a subtle bug in C++.
///
/// @return 0 if successful.

int
main ()
{
  printf ("Constructing DerivedClass x.\n");
  BaseClass *x{ new DerivedClass };
  printf ("Deleting x as a BaseClass*.\n");
  delete x;
}