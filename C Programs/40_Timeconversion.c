/*
Sample Input 

07:05:45PM

Sample Output 

19:05:45

*/

#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char s[50];
    gets(s);
    int l = strlen(s);
    if (s[l - 2] == 'A')
    {
        if (s[0] == '1' && s[1] == '2')
        {
            s[0] = '0';
            s[1] = '0';
            for (int i = 0; i < l - 2; i++)
            {
                printf("%c", s[i]);
            }
        }
        else
        {
            for (int i = 0; i < l - 2; i++)
            {
                printf("%c", s[i]);
            }
        }
    }
    else if ((s[l - 2] == 'P'))
    {
        if (s[0] == '1' && s[1] == '2')
        {
            for (int i = 0; i < l - 2; i++)
            {
                printf("%c", s[i]);
            }
        }
        else
        {
            s[0] = s[0] + 1;
            s[1] = s[1] + 2;
            for (int i = 0; i < l - 2; i++)
            {
                printf("%c", s[i]);
            }
        }
    }

    return 0;
}
