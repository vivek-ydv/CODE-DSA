#include <bits/stdc++.h>
using namespace std;
// Print the  matrix of path
/*
1. Take a step(count) variable
2. Update the path arry
3. Print the path array in base condition
4. Backtrack tha path array
*/
void displayPath(vector<vector<bool>> &maze, int path[10][10])
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

void printpath(string p, int r, int c, vector<vector<bool>> &maze, int path[10][10], int step)
{
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        path[r][c] = step; // As we had reched the base condition then this last step (destination[2][2]) will be also included as the step
        displayPath(maze, path);
        cout << p << endl
             << endl;
        return;
    }

    if (!maze[r][c]) // maze[r][c] == False
    {
        return;
    }

    maze[r][c] = false;
    path[r][c] = step;

    if (r < maze.size() - 1)
    {
        printpath(p + "D", r + 1, c, maze, path, step + 1);
    }
    if (c < maze[0].size() - 1)
    {
        printpath(p + "R", r, c + 1, maze, path, step + 1);
    }

    if (r > 0)
    {
        printpath(p + "U", r - 1, c, maze, path, step + 1);
    }
    if (c > 0)
    {
        printpath(p + "L", r, c - 1, maze, path, step + 1);
    }

    maze[r][c] = true;
    path[r][c] = 0;
}

int main()
{
    vector<vector<bool>> vec = {
        {true, true, true},
        {true, true, true},
        {true, true, true}};

    int path[10][10] = {{0}, {0}};

    printpath("", 0, 0, vec, path, 1);
    return 0;
}