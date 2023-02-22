#include <bits/stdc++.h>
using namespace std;
// Approach 2 :
int getcorrectRow(vector<vector<int>> matrix, int target)
{
    int rStart = 0;
    int rEnd = matrix.size() - 1;
    int last_col = matrix.at(0).size() - 1; // As we are checking the last column values
    while (rStart < rEnd)
    {
        int mid = rStart + (rEnd - rStart) / 2;
        int curr_value =matrix[mid][last_col];
        if (curr_value >= target)
        {
            rEnd = mid;  // As if last element of row is greater than the target hence it may be possible that target element may present int this row.
        }
        else
        {
            rStart = mid + 1; // As if last element of row is less than the target hence it is confirm that it will not be prsent in that row.
        }
    }
    return rEnd; // Or rStart, as both will be pointing to the same row
}

bool binarySearch(vector<vector<int>> matrix, int row, int target)
{
    int cStart = 0;
    int cEnd = matrix.at(0).size() - 1;
    while (cStart <= cEnd)
    {
        int mid = cStart + (cEnd - cStart) / 2;

        if (matrix[row][mid] == target)
        {
            return true;
        }
        if (matrix[row][mid] < target)
            cStart = mid + 1;

        else
            cEnd = mid - 1;
    }
    return false;
}

bool Search(vector<vector<int>> matrix, int target)
{
    int targetrow = getcorrectRow(matrix, target);  // Getting the correct row which will contain our target value
    return binarySearch(matrix, targetrow, target); 
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    cout << (Search(arr, 3));
    return 0;
}
