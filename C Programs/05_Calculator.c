#include <stdio.h>
int main(int argc, char const *argv[])
{
    char fun;
    int a, b, res;

    printf("Enter the Operation you want:\n");
    scanf("%c", &fun);
    printf("Enter the variables:\n");
    scanf("%d %d", &a, &b);
    switch (fun)
    {
    case '+':
        res = a + b;
        printf("%d", res);
        break;
    case '-':
        res = a - b;
        printf("%d", res);
        break;

    default:
        printf("Invalid");
        break;
    }

    return 0;
}
