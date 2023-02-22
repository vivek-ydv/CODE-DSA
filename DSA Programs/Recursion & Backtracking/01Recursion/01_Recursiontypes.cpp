#include <stdio.h>
//Tail Recursion
//If the recursive call is the last statement of in body of recursive function then it is tail recursion.

void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
    }
    printf("\n");
}
//Head Recursion
//If the recursive call is the first statement of in body of recursive function then it is head recursion.

void fun2(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        printf("%d ", n);
    }
}
int main()
{
    int x = 3;
    fun(x);

    fun2(x);
    return 0;
}