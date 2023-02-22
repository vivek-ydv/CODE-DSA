#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

    int row, col;
    int **arr; // We use double pointer as we have to store the adress of integer pointer.
               // Only double pointer is capable of storing the the adress of another pointer.

    printf("Enter the numebr of row and coloumn\n");
    scanf("%d%d", &row, &col);

    // Allocation of 2d array dynamically

    arr = (int **)malloc(row * sizeof(int *)); // It will create a row in memory, which will store the adress of element of each coloums.

    for (int i = 0; i < row; i++)
    {
        *(arr + i) = (int *)malloc(col * sizeof(int)); // *( arr + i) == arr[i]
                                                       // arr[i] : it can store the adress of integer type pointer
                                                       // We are storing the adress of colums element to the row that we have created.
    }
    // Taking the input
    printf("Enter the elmemet of array:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the elements of %d row & %d coloumn:", i, j);
            scanf("%d", (*(arr + i) + j)); //   (*(arr + i) + j) == &arr[i][j]
        }
    }
    //Printing the output
    printf("Array is: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", *(*(arr + i) + j)); //   *(*(arr + i) + j)) == arr[i][j]
        }
        printf("\n");
    }

    // Deallocating the array
    for (int i = 0; i < row; i++)
    {
        free(*(arr + i)); // *( arr + i) == arr[i]
    }
    free(arr);

    printf("After deallocating the array\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", *(*(arr + i) + j)); //   *(*(arr + i) + j)) == arr[i][j]
        }
        printf("\n");
    }

    return 0;
}
