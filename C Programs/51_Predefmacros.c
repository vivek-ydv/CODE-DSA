#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    printf("File name is: %s\n",__FILE__);
    printf("Today's date is: %s\n",__DATE__);
    printf("Current time is: %s\n",__TIME__);
    printf("All about today is: %s\n",__TIMESTAMP__);
    printf("Line number is: %d\n",__LINE__);
    printf("ANSI: %d\n",__STDC__);

    return 0;
}