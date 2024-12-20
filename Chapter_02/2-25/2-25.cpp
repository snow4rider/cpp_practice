/**
 * @brief An example of arrays in C++.
 *
 * This program shows how arrays in C++ can be initialized in different ways.
 * It also shows how to create an uninitialized array.
 */
int main() {
  int array_1[]{ 1, 2, 3 };  // Array of length 3; 1, 2, 3
  int array_2[5]{};          // Array of length 5; 0, 0, 0, 0, 0
  int array_3[5]{ 1, 2, 3 }; // Array of length 5; 1, 2, 3, 0, 0
  int array_4[5];            // Array of length 5; uninitialized values
}
