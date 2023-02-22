/* Take input from the user and ask user to choose 0 for triangular star pattern and 1 for reversed triangular star pattern
Then print the pattern accordingly
*
**
***
**** 
***** -> Triangular star pattern

*****
****
***
**
*    -> Reversed triangular star pattern */

#include <stdio.h>
int main()
{
    char choice;
    int i, j, rows;
    printf("Enter the number Choice :\nFor the triangular star Pattern:0 \nFor reversed triangular star pattern:1 \nEnter your choice:");
    scanf("%c", &choice);

    switch (choice)
    {
    case '0':
        printf("Enter the number of rows you want : ");
        scanf("%d", &rows);

        for (i = 1; i <= rows; i++)
        {
            for (j = 1; j <= i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case '1':
        printf("Enter the number of rows you want : ");
        scanf("%d", &rows);

        for (i = 1; i <= rows; i++)
        {
            for (j = 0; j <= rows - i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;

    default:
        printf("Invalid Input!!!");
        break;
    }
    return 0;
}
