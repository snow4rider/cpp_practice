#include <cstdio>

struct Taxonomist 
{
// Default constructor for Taxonomist that prints "(no argument)".
  Taxonomist() 
  {
    printf("(no argument)\n");
  }
  /**
   * Construct a Taxonomist from a char.
   * 
   * This constructor will print "char: <value of x>".
   */
  Taxonomist(char x)
  {
    printf("char: %c\n", x);
  }
  /**
   * Construct a Taxonomist from an int.
   * 
   * This constructor will print "int: <value of x>".
   */
  Taxonomist(int x) 
  {
    printf("int: %d\n", x);
  }
  /**
   * Construct a Taxonomist from a float.
   * 
   * This constructor will print "float: <value of x>".
   */
  Taxonomist(float x) 
  {
    printf("float: %f\n", x);
  }
};

/**
 * This function tests the different constructors of the Taxonomist class.
 * It creates eight different Taxonomists with different constructor
 * arguments, and prints out the different types.
 */
int main() {
  Taxonomist t1;
  Taxonomist t2{ 'c' };
  Taxonomist t3{ 65537 };
  Taxonomist t4{ 6.02e23f };
  Taxonomist t5('g');
  Taxonomist t6 = { 'l' };
  Taxonomist t7{};
  Taxonomist t8();
}
