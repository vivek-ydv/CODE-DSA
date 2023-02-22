#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{

    int (*fptr)(int, int); // Declearing a function pointer
    fptr = &sum;           // Creatinng a function pointer
    int s = (*fptr)(2, 3); // Derefrencing a function pointer
    printf("The value of s is %d", s);
    return 0;
}
 