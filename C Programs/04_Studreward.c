#include <stdio.h>
int main()
{
    int code;
    printf("Enter the number code according you have passed in subject\n Maths or Science : 1 \n Maths & Science : 2 ");
    printf("\n Please Enter the code here : ");
    scanf("%d", &code);

    if (code == 1)
    {
        printf("You will get a gift of 15 rupees ");
    }

    else if (code == 2)
    {
        printf("You will get a gift of 45 rupees");
    }
    else
    {
        printf("invalid Input");
    }
    return 0;
}