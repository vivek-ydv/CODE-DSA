#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *ptr = NULL;

    /*

    ptr = fopen("53_Filemodes.txt", "r");
    char c = fgetc(ptr);
    printf("The character i read was:%c\n", c);
    c = fgetc(ptr);
    printf("The character i read was:%c", c);
    
   */

    /*

    ptr = fopen("53_Filemodes.txt", "r");
    char str[50];
    fgets(str,25,ptr);
    printf("The string i read was:%s",str);

   */

    ptr = fopen("53_Filemodes.txt", "w");  // use diffrent mode such as 'r+''w+''a''a+' and see the chanegs in the main file

    fputc('o', ptr);
    fputs("this is vivek", ptr);

    fclose(ptr);
    return 0;
}
