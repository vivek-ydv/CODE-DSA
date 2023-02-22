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
void nQueens(vector<vector<bool>> &board, int row, int col)
{
    if (row == board.size())
    {
        display(board);
        PossibleSOl++;
        return;
    }
    if (col == board[0].size())
    {
        // If were not able to place a queen in a particular row it means our place of queen in previous rows were wrong
        // hence return to previous row and try for next positions.
        return;
    }
    if (isSafetoplace(board, row, col))
    {
        board[row][col] = true;
        nQueens(board, row + 1, 0);  
        // how you can forget to backtrack man!!!!!!!
        board[row][col] = false;
    }
    nQueens(board, row, col + 1); // If not possible then check for next coloum postion
}

int main()
{
    int n = 5;
    vector<vector<bool>> vec(n, vector<bool>(n, false));

    nQueens(vec, 0, 0);
    cout << "Possible ways are :" << PossibleSOl;

    return 0;
}