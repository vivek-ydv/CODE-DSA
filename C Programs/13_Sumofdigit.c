#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    int sum = 0;
    scanf("%d", &n);

    while (n != 0)
    {
        int rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }

    printf("%d",sum);

    return 0;
}
