/*
Print the num pattern:

   4 4 4 4 4 4 4
   4 3 3 3 3 3 4
   4 3 2 2 2 3 4
   4 3 2 1 2 3 4
   4 3 2 2 2 3 4
   4 3 3 3 3 3 4
   4 4 4 4 4 4 4
   
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{

    int num, rows, max;
    printf("Enter the number:");
    scanf("%d", &num);
    rows = (2 * num) - 1;

    for (int i = (num - 1); i >= -(num - 1); i--)      // We have interchanged cartesian point in order to work like as loop
    {
        for (int j = -(num - 1); j <= (num - 1); j++)
        {
            max = (abs(i) > abs(j)) ? abs(i) : abs(j);
            printf("%d", (max) + 1);
            max = 0;
        }
        printf("\n");
    }

    return 0;
}