#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    FILE *ptr = NULL;

    char string[100] = "This content is produced by vivek.";

    // Reading a FILE
    
    ptr = fopen("52_Filebasic.txt", "r");
    fscanf(ptr, "%s", string);
    printf("The Content of thid file is : %s", string);
    

    // Writing a FILE
    /*
    ptr = fopen("52_Filebasic.txt", "w");
    fprintf(ptr, "%s", string);       
    */
   fclose(ptr);
    return 0;
}
 