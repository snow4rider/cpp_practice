#include <cstdio>

/**
 * @brief Main entry point for the program
 *
 * Prints out "Yabba d7a5b520!" followed by "There are 69,53 leaves here."
 *
 * @return 0
 */
int main(){
  unsigned int a = 3669732608;
  printf("Yabba %x!\n", a);

  unsigned int b = 69;
  printf("There are %u,%o leaves here.\n", b, b);
}
