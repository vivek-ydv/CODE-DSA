#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *arr; // *arr is an array pointer
    int n;

    // USE OF MALLOC

    printf("Input the size of array :");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));  // Malloc returns void pointer so we typecasted it to the int pointer.
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of %d index of array:", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d index of array:%d\n", i, arr[i]);
    }

    //  USE OF FREE
    free(arr);
    
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d index of array after using free:%d\n", i, arr[i]);
    }

    // USE oF CALLOC
    //"NOTE: It initialises all the values at 0, i.e. if donot take any value as input then the it automatically assign it at 0"
    //"NOTE: Malloc is faster than the Calloc "
    /*
    printf("Input the size of array :");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of %d index of array:", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d index of array:%d\n", i, arr[i]);
    }

    // USE OF REALLOC
    
    printf("Input the size of new array you want to create :");
    scanf("%d", &n);

    arr = (int *)realloc(arr, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of %d index of array:", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d index of array:%d\n", i, arr[i]);
    }
   */

    return 0;
}
