/*
 ~ Null pointer is a defined value while void pointer is a type.
 ~ NULL macro is defined as((void*)0) in header files.
*/

#include <stdio.h>
int main(int argc, char const *argv[])
{
  int a=27;
  int *ptr;
  ptr=NULL;

  if (ptr!=NULL)
  {
    printf("The adress of a is %d",ptr);
  }
  else
  {
    printf("The pointer is a null pointer, it can not be dereferenced");
  }
  
  
  return 0;
}
