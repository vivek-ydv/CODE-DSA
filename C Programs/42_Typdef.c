#include <stdio.h>
int main(int argc, char const *argv[])
{
    // SYNTEX:- typdef <previous_name> <alias name> 

    typedef int integer; 
    integer a = 5;
    printf("The value of a is %d", a);
    return 0;
}
