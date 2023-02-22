#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int k = 0; k < board[0].size(); k++)
        {
            if (board[i][k])
                cout << "K ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isvalid(vector<vector<bool>> &board, int r, int c) // To check wheather the partcular row and coloumn is in the bound or not
{
    if (r >= 0 && r < board.size() && c >= 0 && c < board.size())
    {
        return true;
    }
    return false;
}
bool isSafe(vector<vector<bool>> &board, int r, int c)
{
    if (isvalid(board, r - 2, c - 1))
    {
        if (board[r - 2][c - 1])
        {
            return false;
        }
    }
    if (isvalid(board, r - 2, c + 1))
    {
        if (board[r - 2][c + 1])
        {
            return false;
        }
    }
    if (isvalid(board, r - 1, c - 2))
    {
        if (board[r - 1][c - 2])
        {
            return false;
        }
    }
    if (isvalid(board, r - 1, c + 2))
    {
        if (board[r - 1][c + 2])
        {
            return false;
        }
    }
    return true;
}

int PossibleSOl = 0;
void nKnights(vector<vector<bool>> &board, int row, int col, int n)
{
    if (n == 0)
    {
        display(board);
        PossibleSOl++;
        return;
    }
    if (row == board.size()) // It means that we had checked all the possibilites in (traversed) in all rows, now next row is out of bound
    {
        return;
    }
    /****** When you have to traverse the whole 2d matrix then you can use such approach for giving values in the recursive calls ******/
    int nrow = 0;
    int ncol = 0;
    if (col == board[0].size() - 1)
    {
        nrow = row + 1;
        ncol = 0;
    }
    else
    {
        nrow = row;
        ncol = col + 1;
    }

    if (isSafe(board, row, col))
    {
        board[row][col] = true;
        nKnights(board, nrow, ncol, n - 1);
        board[row][col] = false;
        // display(board); // YOU CAN SEE HERE HOW BOARD GONNA LOOK LIKE AFTER EACH BACKTRACKING STEP FOR BETTER UNDERSTANDINGS
    }
    nKnights(board, nrow, ncol, n);
}
int main()
{
    int n = 3;
    int knigts = 5;
    vector<vector<bool>> vec(n, vector<bool>(n, false));
    nKnights(vec, 0, 0, knigts);
    cout << "Possible ways are :" << PossibleSOl;

    return 0;
}