#include <bits/stdc++.h>
using namespace std;

vector<int> allmissing(int *arr, int length)
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

    // Search For Missing Number
    vector<int> res;
    for (int j = 0; j < length; j++)
    {
        if (j != arr[j] - 1)
            res.push_back(j + 1);
    }
    return res;
    
}

int main()
{
    // Find the missing number in range (1-N)
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> res = allmissing(arr, size);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}