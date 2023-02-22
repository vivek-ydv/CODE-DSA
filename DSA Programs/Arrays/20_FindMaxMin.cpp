// finding the maxmimum and minimum in array in a single traversal
#include <iostream>
using namespace std;
// Time Complexity : O(n)
int main()
{
    int arr[] = {5, 7, 44, 7, 2, 6, 9, 12, 44, 32, 23};
    int length = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Max : " << max << endl
         << "Min : " << min;
    return 0;
}