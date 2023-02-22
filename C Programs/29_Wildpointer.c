/* An uninitialised pointers are known as wild pointer */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int a = 27;
    int *ptr; // This is a wild pointer
    printf("%d\n", ptr);

    ptr = &a; // Now it is no  more wild pointer
    printf("%d", *ptr);

    return 0;
}
