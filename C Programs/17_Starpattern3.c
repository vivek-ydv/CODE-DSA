/*
 Print the following star pattern

    *   
   ***
  *****
 *******

*/
#include<stdio.h>
int main(int argc, char const *argv[])
{

    int i, j;
    int rows;
    printf("Input the number of rows you want:");
    scanf("%d", &rows);
    for ( i = 0; i < rows; i++)
    {
        for (j = 0; j < 2 * rows - 1; j++)
        {
            if (j >= rows - 1 - i && j <= rows - 1 + i) // Here rows-1 is the centre of the pattern
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