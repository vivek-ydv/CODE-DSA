#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main()
{

    int *p;
    int *q;
    int i, size = 5;

    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    q = new int[size]; // CPP Keyword
    q[0] = 2;
    q[1] = 4;
    q[2] = 6;
    q[3] = 8;
    q[4] = 10;

    for (i = 0; i < 5; i++)
        printf("%d ", p[i]);

    printf("\n");
    for (i = 0; i < 5; i++)
        printf("%d ", q[i]);

    return 0;
}