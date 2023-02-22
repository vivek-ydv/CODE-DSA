#include <iostream>
using namespace std;
// With the help of an Extra space O(n)
// It will be faster as compared to the previous one
// User must input the maximum value and minimum value of sequence
void Missing(int arr[], int H[], int len, int low, int max)
{
    for (int i = 0; i < len; i++)
    {
        H[arr[i]] = 1;
    }
    for (int i = low; i <= max; i++)
    {
        if (H[i] == 0)
        {
            cout << "The missing element is : " << i << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 4, 5, 10, 9, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    int low = 1,
        max = 10;

    int H[max + 1]; //  Hashtable must have size 1 more than the value of max element,
                    //  So that we can perform operation on a index value equal to the max element value.
    for (int i = 0; i <= max; i++)
    {
        H[i] = 0;
    }
    Missing(arr, H, len, low, max);
    return 0;
}