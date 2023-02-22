#include <iostream>
using namespace std;

int BinSearch(int target, int *arr, int s, int e)
{
    if (s > e)
    {
        return -1;
    }

    int m = (s + e) / 2;

    if (target == arr[m])
    {
        return m;
    }

    if (target < arr[m])
    {
        return BinSearch(target, arr, s, m - 1);
    }

    return BinSearch(target, arr, m + 1, e);
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 15, 20};
    int size = sizeof(A) / sizeof(A[0]);

    int s = 0;
    int e = size - 1;
    int target = 11;

    cout << BinSearch(target, A, s, e);
    return 0;
}