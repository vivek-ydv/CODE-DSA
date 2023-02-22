#include <stdio.h>
void revarray(int *array, int n)
{
    int temp;
    int i = 0;
    while (i < n / 2)
    {
        temp = array[i];
        array[i] = array[(n - 1) - i];
        array[(n - 1) - i] = temp;

        i++;
    }

    printf("The reversed array is :");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", array[i]);
    }
}
int main(int argc, char const *argv[])
{
    int arr[100];
    int rows, temp;

    printf("Input the number of rows of array : ");
    scanf("%d", &rows);
    for (int i = 0; i < rows; i++)
    {
        scanf("%d", &arr[i]);
    }

    revarray(arr, rows);

    return 0;
}
