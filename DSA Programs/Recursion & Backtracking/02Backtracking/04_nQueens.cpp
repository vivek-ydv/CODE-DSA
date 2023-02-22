#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<bool>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j]) // if true
                cout << "Q ";

            else
                cout << "X ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafetoplace(vector<vector<bool>> &board, int r, int c)
{
    // Check vertical row of that particular coloumn
    for (int i = 0; i < r; i++)
    {
        if (board[i][c])
        {
            return false;
        }
    }

    // Check diagonal left
    int maxLeft = min(r, c);
    for (int i = 1; i <= maxLeft; i++)
    {
        if (board[r - i][c - i]) // if(true) means already queen is prsent hence return false
        {
            return false;
        }
    }

    // check diagonal right
    int maxRight = min(r, int(board.size() - 1 - c));
    for (int i = 1; i <= maxRight; i++)
    {
        if (board[r - i][c + i])
        {
            return false;
        }
    }
    return true; // if till no queens were found at all checked position then return true
}

int PossibleSOl = 0;
void nQueens(vector<vector<bool>> &board, int row)
{
    if (row == board.size())
    {
        display(board);
        PossibleSOl++;
        return;
    }
    for (int col = 0; col < board.size(); col++) // If you want to eliminate this for loop then you have to take extra argument "col", and "Queens" to check no of queens are remaining,
                                                 // and put an if condition in the recursive call, it is shown in next N knights problem.
    {
        // place the queen if it is safe
        if (isSafetoplace(board, row, col))
        {
            board[row][col] = true;
            nQueens(board, row + 1);
            board[row][col] = false; // After returning we will be here till now no backtracking concepts were used,
                                     // now before checking for next position, remove the change that were made, this is the backtracking concept.
        }
    }
    return; // If we were not able to place Queen at any position in a particular row,
            // it means that our position of queen in previous row was wrong hence return and try for next position in previous row.
}

int main()
{
    int n = 4;
    vector<vector<bool>> vec(n, vector<bool>(n, false));

    nQueens(vec, 0);
    cout << "Possible ways are :" << PossibleSOl;

    return 0;
}