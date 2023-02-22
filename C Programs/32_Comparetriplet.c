// HACKERRANK PROBLEM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compareTriplets(int *a, int *b)
{
    int alice = 0;
    int bob = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        else if (a[i] > b[i])
        {
            alice++;
        }
        else
        {
            bob++;
        }
    }
    int result[] = {alice, bob};

    for (int i = 0; i < 2; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}

int main()
{
    int a[10];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }

    int b[10];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &b[i]);
    }

    compareTriplets(a, b);

    return 0;
}
