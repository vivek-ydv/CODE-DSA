#include <bits/stdc++.h>
using namespace std;
// Approach 1 :
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
    int rows = matrix.size();
    int cols = matrix.at(0).size();

    // If only one row is given as input
    if (rows == 1)
        return binarySearch(matrix, 0, target);

    int rStart = 0;
    int rEnd = rows - 1;
    int cMid = cols / 2; // As we are checking the mid column values

    // run the loop while 2 rows are remaining
    while (rStart < (rEnd - 1))
    {
        int mid = rStart + (rEnd - rStart) / 2;
        if (matrix[mid][cMid] == target)
        {
            return true;
        }
        if (matrix[mid][cMid] < target)
        {
            rStart = mid;
        }
        else
        {
            rEnd = mid;
        }
    }

    // Now we have only two  rows remaining
    int res = binarySearch(matrix, rStart, target);
    if (res == false)
    {
        res = binarySearch(matrix, rStart + 1, target);
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    cout << (Search(arr, 8));
    return 0;
}
