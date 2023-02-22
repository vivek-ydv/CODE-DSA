#include <iostream>
using namespace std;
// Condition : Sorted Array, Else if not sorted then apply an algorithm to get largest ele and according to that decleare the size of hash table
// Time Complexity : O(n)
// Space Complexity : O(n)
void duplicate(int a[], int h[], int len, int max)
{
    for (int i = 0; i < len; i++)
    {
        h[a[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if (h[i] > 1)
        {
            cout << "Duplicate element : " << i << " freq : " << h[i] << endl;
        }
    }
}
int main()
{
    int arr[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20, 20, 20, 20, 24};
    int len = sizeof(arr) / sizeof(arr[0]);
    int max = arr[len - 1];
    int H[max + 1]; //  Hashtable must have size 1 more than the value of max element,
                    //  So that we can perform operation on a index value equal to the max element value.
    for (int i = 0; i <= max; i++)
    {
        H[i] = 0;
    }
    duplicate(arr, H, len, max);
    return 0;
}