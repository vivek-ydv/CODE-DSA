#include <bits/stdc++.h>
using namespace std;

int linearsearch(int *arr, int length, int target)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 5, -4, 6, -8, 9, 11};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = -8;
    cout << linearsearch(arr, length, target);
    return 0;
}