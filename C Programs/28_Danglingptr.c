/*
  A Pointer pointing to the freed memory or a location whose content is deleted.

  Causes: ~ Deallocation of memory block,
          ~ Returning local variables in function call,
          ~ Variable going out of scope.

  Issues due to  dangeling pointer can be avoided by initialising poinetr to  NULL.         
*/

#include <stdio.h>
#include <stdlib.h>

int *functionDangling()
{
  int a, b, sum;
  a = 34;
  b = 364;
  sum = a + b;
  return sum;
}

int main()
{
  // Case 1: De allocation of a memory block
  int *ptr = (int *)malloc(7 * sizeof(int));
  ptr[0] = 34;
  ptr[1] = 36;
  ptr[2] = 64;
  ptr[3] = 5;
  free(ptr); // ptr is now a dangling pointer

  // Case 2: Function returning local variable address
  int *dangPtr = functionDangling(); // dangPtr is now a dangling pointer

  // Case 3: If a variable goes out of scope
  int *danglingPtr3;
  {
    int a = 12;

    danglingPtr3 = &a; /* Here variable a(decleared in user def function) goes out of scope,
                          which means danglingPtr3 is pointing to a location which is freed and hence danglingPtr3 is now a dangling pointer */

    return 0;
  }
}
