#include <cstdio>

/**
 * @brief Output whether a given number is positive, negative, or zero.
 *
 * @details This program prints out whether the number is positive, negative, or zero.
 */
int main(){
  int x = 0;

  if (x > 0) {
    printf("Positive.");
  } else if (x < 0) {
    printf("Negative.");
  } else {
    printf("Zero");
  }
}

