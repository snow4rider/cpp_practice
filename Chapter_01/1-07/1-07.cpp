/**
 * Compute the step function of x, which is defined as:
 *  -1 if x is negative
 *   1 if x is positive
 *   0 if x is zero
 *
 * @param x the input value
 * @returns the step function of x
 */
int step_function(int x) 
{
  int result = 0;
  if (x < 0) 
  {
    result = -1;
  } 
  else if (x > 0)
  {
    result = 1;
  }
  return result;
}

/**
 * Example code that calls the step_function with different values and prints their results
 */
int main()
{
  int value1 = step_function(100);
  int value2 = step_function(0);
  int value3 = step_function(-10);
}
