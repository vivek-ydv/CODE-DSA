/* 
CPREPROCESSORS : 
                #define
                #include
                #undef
                #ifdef
                #ifndef
                #if
                #else
                #elif
                #Pragma - To issue some special commands to compiler
*/

#include <stdio.h>
#define PI 3.14        // Defining of preprocessor
#define SQUARE(r) r *r // Defing the macros

int main(int argc, char const *argv[])
{
    float var;
    var = PI;
    int r = 5;
    printf("The value of PI is %f \n", var);
    printf("The area of circle is %f\n", PI * SQUARE(r));

    return 0;
}
