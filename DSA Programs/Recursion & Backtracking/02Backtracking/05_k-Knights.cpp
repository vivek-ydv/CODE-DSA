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
void nKnights(vector<vector<bool>> &board, int r, int c, int n)
{
    if (n == 0)
    {
        display(board);
        PossibleSOl++;
        return;
    }
    if (r == board.size()) // It means that we had checked all the possibilites in (traversed) in all rows,now next row is out of bound.
    {
        return;
    }
    if (c == board[0].size()) // It means that we had checked all the possible col of a row and now next col value is out of bound hence move to next row.
    {
        nKnights(board, r + 1, 0, n);
        return; 
    }
    if (isSafe(board, r, c))
    {
        board[r][c] = true;
        nKnights(board, r, c + 1, n - 1);
        board[r][c] = false;
        // display(board);  //YOU CAN SEE HERE HOW BOARD GONNA LOOK LIKE AFTER EACH BACKTRACKING STEP FOR BETTER UNDERSTANDINGS
    }
    nKnights(board, r, c + 1, n); // If a position is not safe then we have to also move ahead in that col.
                                  // Since, we are not using for loop hence we have to write this condition also for moving to next col position.
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