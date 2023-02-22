#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[2][3];
    int i, j;

    for (i = 0; i < 2; i++) // initialisation of array
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter the elements of %d row & %d coloumn:", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("The Output array is :\n"); // printing the output of array
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
