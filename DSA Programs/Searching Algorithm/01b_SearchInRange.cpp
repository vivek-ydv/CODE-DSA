#include <bits/stdc++.h>
using namespace std;

int linearsearch(int *arr, int start, int end, int target)
{
    for (int i = start; i <= end; i++)
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
    int target = 5;
    cout << linearsearch(arr, 2, 6, target);
    return 0;
}