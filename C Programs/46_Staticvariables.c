// DECLERATION- Telling the compiler about the variables (No Space Reserved)
// DEFINITION-  Delceration + space reservation

#include <stdio.h>
int myfunc()
{
    static int i = 27; // The value of static variable is initialised only once after that it uses 'previous allocated value/address'
    i++;               // if we donot initialise any value then automatically assign the '0 value'
    return i;
}

int main()
{
    printf("Value:%d", myfunc());
    printf("\nValue:%d", myfunc());
    printf("\nValue:%d", myfunc());

    return 0;
}