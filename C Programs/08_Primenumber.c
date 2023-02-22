#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num, i, flag = 0;
    printf("Enter the number you want to check prime\n");
    scanf("%d", &num);
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Prime");
    }
    else
    {
        printf("Not Prime");
    }

    return 0;
}
