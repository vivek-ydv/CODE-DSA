/*
The compiler translate the s[i] to the ASCII table,
For example, number '1' (translates to 49) and '0' (translates to 48),  
Cause in the ASCII table the numbers ranks between 48-57,)
Let's say it was the letter F (70 on the ASCII table) it would do 70+48 = 118(Not Between 48-57)
*/

// HACKER RANK PROBLEM(Frequency) - Optimised solution i.e. a way to remove if elseif ladder or switch case in such problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char s[1000];
    int count;
    scanf("%s", s);
    for (int i = 0; i < 10; i++)
    {
        count= 0;

        for (int j = 0; j < strlen(s); j++)
        {
            if (s[j] == 48 + i)
            {
                count++;
            }
            else
            {
                continue;
            }
            
        }
        printf("%d ",count);
    }

    return 0;
}
