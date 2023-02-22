#include <iostream>
using namespace std;

void findpair(int *arr, int n, int target)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            cout << "Pair:" << arr[i] << "," << arr[j] << endl;
            i++;
            j--;
        }
        if (arr[i] + arr[j] > target)
        {
            j--;
        }
        if (arr[i] + arr[j] < target)
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 2, 4, 5, 7, 8, 10}; // Assumning that array is free of duplicate element
    int n = sizeof(arr) / sizeof(arr[0]);
    findpair(arr, n, 10);
    return 0;
}