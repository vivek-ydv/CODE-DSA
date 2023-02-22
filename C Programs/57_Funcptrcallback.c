#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b)
{
    return a + b;
}
int avg(int a, int b)
{
    return ((a + b) / 2);
}
void greetHelloAndExecute(int (*fptr)(int, int))
{
    printf("Hello User\n");
    printf("The sum of 5 and 7 is %d\n", fptr(5, 7));
}
void greetGmAndExecute(int (*fptr)(int, int))
{
    printf("Good Morning User\n");
    printf("The avg of 5 and 7 is %d\n", fptr(5, 7));
}

int main(int argc, char const *argv[])
{
    int (*ptr)(int, int);
    ptr = &sum; // 'ptr = sum' is also valid
    greetHelloAndExecute(ptr);
    ptr = &avg;
    greetGmAndExecute(ptr);
}
