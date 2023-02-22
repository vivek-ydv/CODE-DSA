#include <stdio.h>
int fibr(int num)
{
    if (num<=1)  // Base condition
    {
        return num ;
    }
    else
    {
        return fibr(num - 1) + fibr(num - 2);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    int i;
    printf("Enter the number upto which you want to print fibonacci series:");
    scanf("%d", &n);
    printf("The fibonacci series is:");
    for (i = 0; i <= n; i++)
    {
        printf("%d ", fibr(i));
    }
    return 0;
}
