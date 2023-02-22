// HACKERRANK PROBLEM

#include <stdio.h>
#include <stdlib.h>

void diagdiff(int n, int arr[50][50])
{
    int sum1 = 0,
        sum2 = 0,
        diff = 0;

    // DIAGONAL ELEMENT

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum1 = sum1 + arr[i][j];
            }
        }
    }

    // GETTING OPPOSITE DIAGONAL ELEMENT
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1 - i; j >= 0; j--)
        {
            sum2 = sum2 + arr[i][j];
            break;
        }
    }

    diff = abs(sum1 - sum2);

    printf("The absolute diff of both diagonals of array is %d", diff);
}

int main(int argc, char const *argv[])
{
    int n;
    int array[50][50]; // DECLERATION OF 2D ARRAY

    printf("Enter the number of rows or coloumn of square matrix:");
    scanf("%d", &n);

    printf("Enter the elememts of array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    diagdiff(n, array);

    return 0;
}
