#include <bits/stdc++.h>
using namespace std;
// Intro to backtracking
// Consider a 3*3 matrix You have to move from points from (0,0) to (2,2).
// You can move in all direction left,right,up,down.
// Problem : Print all the possible paths.

void path(string p, int r, int c, vector<vector<bool>> &maze)
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

    // i am considering this block in my paths
    maze[r][c] = false;
    if (r < maze.size() - 1)
    {
        path(p + "D", r + 1, c, maze);
    }
    if (c < maze[0].size() - 1)
    {
        path(p + "R", r, c + 1, maze);
    }

    if (r > 0)
    {
        path(p + "U", r - 1, c, maze);
    }
    if (c > 0)
    {
        path(p + "L", r, c - 1, maze);
    }
    // This line is where the function will be over.
    // So before the function get removed, also remove the changes that were made by the function i.e. Backtracking
    maze[r][c] = true;
}

int main()
{
    vector<vector<bool>> vec = {
        {true, true, true},
        {true, true, true},
        {true, true, true}};
    path("", 0, 0, vec);
    return 0;
}