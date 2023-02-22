#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, c, d;
    int max;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    
     max = (a > b) ? (((a > c) ? ((a > d) ? a : d) : ((c > d) ? c : d))) :

                  ((b > c) ? ((b > d) ? b : d) : ((c > d) ? c : d));
   

    /*
     max = (a > b && a > c && a > d) ? a
                                       : (b > c) ? ((b > d) ? b : d) : ((c > d) ? c : d);
    */
    printf("%d", max);

    return 0;
}
