#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 27;
    float b = 19.27;
    void *ptr;

    ptr = &a;
    printf("The value of the a is %d\n", *((int *)ptr)); // We can not dereference the void pointer directly first we have to typecast it.

    ptr = &b;
    printf("The value of the b is %.3f\n", *((float *)ptr)); // We can not dereference the void pointer directly first we have to typecast it.

    return 0;
}
