// Problem Statement:-
// Dynamic Memory Allocation
// ABC Pvt Ltd. manages employee records of other companies.
// Employee Id can be of any length and it can contain any character.
// For 3 employees, you have to take 'length of employee id' as input in a length integer variable.
// Then, you have to take employee id as an input and display it on screen.
// Store the employee id in a character array which is allocated dynamically.
// You have to create only one character array dynamically

/*EXAMPLE*/
// Employee 1:
// Enter no of characters in your eId
// 45
// Dynamically allocate the character array.
// take input from user

// Employee 2:
// Enter no of characters in your eId
// 4
// Dynamically allocate the character array.
// take input from user

// Employee 3:
// Enter no of characters in your eId
// 9
// Dynamically allocate the character array.
// take input from user

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
    char *id;

    for (int i = 0; i < 3; i++)
    {
        printf("\nEmploye:%d\n", i + 1);
        printf("Enter the number of characters in your id:");
        scanf("%d", &n);
        getchar(); /* If we donot use this then we will be not able to input the string,
                      A s gets will take pressing "enter" key as a valid input for gets */

        id = (char *)malloc((n + 1) * sizeof(char)); // As in string one extra character is req for null character.
        printf("Enter the id:");
        gets(id);
        printf("The id of emoplyee %d is %s.\n", i + 1, id);
        free(id);
    }

    return 0;
}
