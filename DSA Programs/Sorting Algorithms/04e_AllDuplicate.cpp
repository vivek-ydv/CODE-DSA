#include <bits/stdc++.h>
using namespace std;

vector<int> allduplicate(int *arr, int length)
{
    int i = 0;
    while (i < length)
    {
        int correctindex = arr[i] - 1;
        if (arr[i] != arr[correctindex])
        {
            // Swap the current index value with corrected index value
            int temp = arr[i];
            arr[i] = arr[correctindex];
            arr[correctindex] = temp;
        }
        else
            i++;
    }
    vector<int> res;
    // Search For duplicate Number
    for (int j = 0; j < length; j++)
    {
        if (j != arr[j] - 1)
            res.push_back(arr[j]);
    }
    return res;
}

int main()
{
    // Find the duplicate number in range (1-N)
    int arr[] = {4,3,2,7,8,2,3,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> res = allduplicate(arr, size);

    for (auto &&i : res)
    {
        cout << i <<" ";
    }

    return 0;
}