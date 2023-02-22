void swap(int *x, int *y) /* Formal arguments , Here the adress is stored as we will do any change
                             it will  be reflected in the value of actual arguments, as here we are changing the actual adress */
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    printf("\nThe value inside the function are:");
    printf("\nValue of r: %d", *x);
    printf("\nValue of v: %d", *y);
}
void main()
{
    int r = 10, v = 20; // Actual arguments
    swap(&r, &v);       // passing value to function
    printf("\nThe value outside the  function are:");
    printf("\nValue of r: %d", r);
    printf("\nValue of v: %d", v);
}