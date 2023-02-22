#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[20];
    char str2[20];
    char str3[50] = " is good friend of ";

    printf("Enter the name of 1st friend : ");
    gets(str1);
    printf("Enter the name of 2st friend : ");
    gets(str2);

    /*  strcat(str1, str3);
        strcat(str1, str2);

        puts(str1);
    */

    puts((strcat(str1, strcat(str3, str2))));
    return 0;
}
