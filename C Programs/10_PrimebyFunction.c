#include <stdio.h>
void checkprime(int num); // Decleration of function
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number you want to check prime\n");
    scanf("%d", &n);
    checkprime(n); // Calling of function
}

void checkprime(int num)
{

    int i, flag = 0;

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
}