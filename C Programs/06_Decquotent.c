#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 4;
    int b = 10;
    float c = ((float)a) / b; // We have to typecast the one of the values to the double or float

    printf("%.3f", c);
 
    return 0;
}
