#include <stdio.h>
#include <string.h>

void parser(char *string)
{
    int in = 0;
    int index = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            in = 0;
            continue;
        }
        else if (string[i] == '>')
        {
            in = 1;
            continue;
        }
        if (in == 1)
        {
            string[index] = string[i];
            index++;
        }
    }
    string[index] = '\0';

    // Removing the trailing spaces before the start of string
    while (string[0] == ' ')
    {
        for (int i = 0; i < strlen(string); i++)
        {
            string[i] = string[i + 1];
        }
    }
    // Removing the trailing spaces after the end of string
    while (string[strlen(string) - 1] == ' ')
    {
        string[strlen(string) - 1] = '\0';
    }
}

int main(int argc, char const *argv[])
{
    char string[] = "<h1>  Welcome to Coding World! </h1> ";
    parser(string);
    printf("The parsed string is ~%s~ ", string);
    return 0;
}