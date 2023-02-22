#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("The value of argc is %d\n", argc); // argc will always have initial value 1, as it is the filename

    for (int i = 0; i < argc; i++)
    {
        printf("The argument at the index %d have a value %s\n",i,argv[i]);
    }

    return 0;
}
