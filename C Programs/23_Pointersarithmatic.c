#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 5;
    char b = 3;
    int *ptra = &a;
    char *ptrb = &b;
    printf("%d\n", ptra);
    printf("%d\n", ptra + 1); // Adding the size of int
    printf("%d\n", ptrb);
    printf("%d\n", ptrb + 1); // Adding thr size of char
    printf("%d\n", ptrb - 1); // Subtracting thr size of char

    ptra++;
    printf("%d\n", ptra); // Adding the size of int
    ptrb--;
    printf("%d\n", ptrb); // Subtracting thr size of char

    return 0;
}
