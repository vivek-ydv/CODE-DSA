#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    char a[10][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (n >= 1 && n <= 9)
    {
        printf("%s", a[n - 1]);
    }
    else
    {
        printf("Greater than 9");
    }
}
