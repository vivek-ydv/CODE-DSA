#include <bits/stdc++.h>
using namespace std;
// Problem is same as previous there is obstacle at (1,1) but in more complicated way.
// Here we are given a boolean 2d vector having true values as well as false values as restriction

void pathrestriction(string p, int r, int c, vector<vector<bool>> &maze)
{
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        cout << p << endl;
        return;
    }
    if (!maze[r][c]) // maze[r][c] == False
    {
        return;
    }
    if (r < maze.size() - 1)
    {
        pathrestriction(p + "D", r + 1, c, maze);
    }
    if (c < maze[0].size() - 1)
    {
        pathrestriction(p + "R", r, c + 1, maze);
    }
}

int main()
{
    vector<vector<bool>> vec = {
        {true, true, true},
        {true, false, true},
        {true, true, true}};
    pathrestriction("", 0, 0, vec);
    // cout << vec.size() - 1 << endl; // Number of rows
    // cout << vec[0].size() - 1  << endl; // Number of columns
    return 0;
}