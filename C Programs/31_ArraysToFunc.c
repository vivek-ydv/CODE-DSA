/*
// BY DECLEARING ARRAY AS A PARAMETER IN THE FUNCTION

#include <stdio.h>
void func1(int array[10])
{
    for (int i = 0; i < 5; i++)
    {
        printf("The value at the %d index is %d\n", i, array[i]);
    }
    array[0] = 27; // Very Imp point that if you change the any value inside fun then it will also reflect in the main function
}

int main(int argc, char const *arg[])
{
    int arr[5] = {1, 6, 5, 4, 9};

    printf("The value at the 0 index before calling the function is %d\n", arr[0]);

    func1(arr);

    printf("The value at the 0 index after calling the function is %d\n", arr[0]);

    return 0;
}
*/


// BY PASSING BASE ADDRESS TO THE FUNCTION

#include <stdio.h>
void fun2(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("The value at the %d index is %d\n", i, ptr[i]);  // *(ptr+i) can be used
    }
}
int main(int argc, char const *argv[])
{
    int arr[5] = {1, 6, 5, 4, 9};

    fun2(arr);

    return 0;
}


/*
// SIMILIARY FOR 2D ARRY

#include <stdio.h>
void fun3(int array[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("The Value at index [%d][%d] is : %d\n", i, j, array[i][j]);
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[2][2] = {{5, 6}, {1, 2}};

    fun3(arr);

    return 0;
}
*/