#include <stdio.h>
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 6};

    printf("The address of first element of the array is: %d \n", &arr[0]);
    printf("The address of first element of the array is: %d \n", arr);
    printf("The address of secon element of the array is: %d \n", &arr[1]);
    printf("The address of secon element of the array is: %d \n", arr + 1);
    printf("The address of third element of the array is: %d \n", &arr[2]);
    printf("The address of third element of the array is: %d \n", arr + 2);

    printf("The value at adress of first element of the array is : %d \n", arr[0]);
    printf("The value at adress of first element of the array is : %d \n", *(arr));
    printf("The value at adress of first element of the array is : %d \n", *(&arr[0]));
    printf("The value at adress of secon element of the array is : %d \n", arr[1]);
    printf("The value at adress of secon element of the array is : %d \n", *(arr + 1));
    printf("The value at adress of secon element of the array is : %d \n", *(&arr[1]));

    /*  arr--;  This line will throw an error as it contain a constant value as a adress of first element,
    so we can't change it */

    return 0;
}
