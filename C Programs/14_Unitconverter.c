#include <stdio.h>
int main(int argc, char const *argv[])
{
    char fun;
    float value;
    char exit;

    while (1)
    {
        printf("Enter the input characters or press q to exit\n");
        printf("1:Km to Miles\n2:Pound to Kgs\n3:Inch to Feets\n");
        scanf(" %c", &fun);  // if we will not add space before char then it will repeat the program

        switch (fun)
        {
        case '1':
            printf("Enter the value\n");
            scanf("%f", &value);
            value = value * 0.621;
            printf("Value is %f Miles\n", value);
            break;
        case '2':
            printf("Enter the value\n");
            scanf("%f", &value);
            value = value * 0.454;
            printf("Value is %f Kgs\n", value);
            break;
        case '3':
            printf("Enter the value\n");
            scanf("%f", &value);
            value = value * 0.0833;
            printf("Value is %f Feets\n", value);
            break;
        case 'q':
            goto exit;
            break;

        default:
            printf("Invalid, please choose the correct option\n");
            break;
        }
    }
exit:
    printf("Thanks for using!!!!");
    return 0;
}
