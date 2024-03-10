#include <iostream>

#include "triangle.hpp"

/**
 * The main function of the program.
 */
int main()
{
  triangle t;

  t.set_angle_A(90);
  t.set_angle_B(30);
  t.set_angle_C(60);

  std::cout << "Is the triangle valid? " << t.isTriangle() << std::endl;
}

