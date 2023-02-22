#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("***Lets learn About pointers***\n");

    int a = 27;
    int *ptra = &a;
    int *b = NULL;

    printf("The adress of pointer to a is : %p\n", &ptra);
    printf("The adress of NULL pointer is : %p\n", b);
    printf("The adress of a is : %p\n", ptra);
    printf("The adress of a is : %d\n", ptra);
    printf("The adress of a is : %d\n", &a);
    printf("The value  of a is : %d\n", *ptra);
    printf("The value  of a is : %d\n", a);
    return 0;
}
