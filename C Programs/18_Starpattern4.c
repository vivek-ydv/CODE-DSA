/*
 Print the following star pattern

    *****
    *   *
    *   *
    *   *
    ***** 

*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j;
    int rows;
    printf("Enter the number of rows :");
    scanf("%d", &rows);

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < rows; j++)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == rows - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
