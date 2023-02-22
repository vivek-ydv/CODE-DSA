#include <stdio.h>

void printStr(char str[100])
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    // char str[] = {'v', 'i', 'v', 'e', 'k', '\0'};
    // char str[6] = "vivek";                        "We can take input in above two ways while declearing the strings"

    char str[100];
    printf("Input the string: ");
    gets(str);

    printf("Using custom function: ");
    printStr(str); // calling the funfunction
    printf("Using printf: %s\n", str);
    printf("using puts: ");
    puts(str);
    return 0;
}
