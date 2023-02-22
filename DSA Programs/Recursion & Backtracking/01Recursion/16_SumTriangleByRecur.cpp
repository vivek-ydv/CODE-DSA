#include <iostream>
using namespace std;

void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void printTriangle(int *arr, int n)
{
    if (n < 1)
    {
        return;
    }

    int temp[n - 1]; // As after each loop size will decrese by 1
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i] + arr[i + 1];
    }
    //  Display(arr, n); // Printing the array in the calling time of each recursive call
    printTriangle(temp, n - 1);

    Display(arr, n); // Printing the array in the returning time of each recursive call
}

int main()
{

    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printTriangle(A, n);
    return 0;
}