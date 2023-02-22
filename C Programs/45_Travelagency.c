/*
You manage a travel agency and you want your n drivers to input their following details:
1. Name
2. Driving License No
3. Route 
4. Kms
Your program should be able to take n as input(or you can take n=3 for simplicity) and your drivers will start inputting their details one by one.

Your program should print details of the drivers in a beautiful fashion.
*/

#include <stdio.h>
#include <string.h>

struct driver
{
    char name[25];
    int dl;
    char route[25];
};
int main(int argc, char const *argv[])
{

    struct driver d[3]; /* Taking like as an 'array of structures' of 'size 3 element in array of structures',
                           NOTE: It(driver) is a new data type we had created by using structure, taking the location in memory like an array */
    int n;
    printf("Enter the number of driver:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Please enter the following details for driver %d\n", i + 1);
        printf("Name:");
        scanf("%s", &d[i].name);
        printf("Driving Licence Number(Numbers only):");
        scanf("%d", &d[i].dl);
        printf("Route:");
        scanf("%s", &d[i].route);
    }

    printf("*************** THE DETAILS OF INPUTTED EMPLOYEES ***************\n");

    for (int i = 0; i < n; i++)
    {
        printf("Details of Driver %d are:\n", i + 1);
        printf("Name:%s \nDLid:%d \nRoute:%s\n", d[i].name, d[i].dl, d[i].route);
        printf("\n");
    }

    return 0;
}
