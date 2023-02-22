#include <iostream>
using namespace std;
// Condition : The array must be sorted
// Time complexity log(n)

int binsearch(int a[], int length, int element)
{
    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high) // If donot apply equal sign then the corner element will not be chcecked
    {
        mid = (high + low) / 2;

        if (a[mid] == element)
        {
            return 1;
        }
        else if (element > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 4, 5, 8, 9, 11, 14, 19, 22, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int check = binsearch(arr, size, 11);
    if (check == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Found";
    }

    return 0;
}