#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randgenrate(int n)
{
    srand((time(NULL)));     // To Genrate Random Number
    int number = rand() % n; // To Store the number between 0 and limit n.

    return number;
}

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter the number to genrate a random number between 0 and number:");
    scanf("%d", &num);

    int rnum = randgenrate(num);

    printf("The random number between the 0 and %d is %d", num, rnum);

    return 0;
}
