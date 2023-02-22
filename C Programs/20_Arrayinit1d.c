#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[5];
    int i;
    printf("Enter the elements of the array :\n");

    for (i = 0; i < 5; i++) // initialisation of array
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 5; i++) // printing the output of the array
    {
        printf("Output of a[%d] elements array is %d.\n", i, a[i]);
    }

    return 0;
}
