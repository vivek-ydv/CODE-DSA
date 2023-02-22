#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    int a = 0;
    int b = 1;
    int i, c;
    printf("Enter the number upto which you want to print fibonacci series:");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("%d", a);
    }
    else
    {
        printf("%d", a);
        printf(" %d", b);
        for (i = 2; i < num; i++)
        {
            c = a + b;
            printf(" %d", c);
            a = b; 
            b = c;
        }
    }

    return 0;
}
