/*
 Print the following star pattern
    *   
   **
  ***
 ****   
*/

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j;
    int rows;
    printf("Input the number of rows you want:");
    scanf("%d", &rows);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < rows; j++)
        {
            if (i + j >= rows - 1)
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