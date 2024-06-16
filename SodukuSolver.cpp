#include<iostream>
using namespace std;

bool isSafe(char board[9][9], int row, int col, int num)
{
    for(int i=0; i<9; i++)
    {
        if(board[row][i] == (char)(num + '0'))
        {
            return false;
        }
        if(board[i][col] == (char)(num + '0'))
        {
            return false;
        }
    }

    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for(int i=sr; i<sr + 3; i++)
    {
        for(int j=sc; j<sc + 3; j++)
        {
            if(board[i][j] == (char)(num + '0'))
            {
                return false;
            }
        }
    }
    return true;
}

bool helper(char board[9][9], int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    int nrow = 0;
    int ncol = 0;
    if (col != 8)
    {
        nrow = row;
        ncol = col + 1;
    }
    else
    {
        nrow = row + 1;
        ncol = 0;
    }

    if(board[row][col] != '.')
    {
        if(helper(board, nrow, ncol))
        {
            return true;
        }
    }
    else
    {
        for(int i=1; i<=9; i++)
        {
            if(isSafe(board, row, col, i))
            {
                board[row][col] = (char)(i + '0');
                if(helper(board, nrow, ncol))
                {
                    return true;
                }
                else
                {
                    board[row][col] = '.';
                }
            }
        }
    }
    return false;
}

void SolveSudoku(char board[9][9])
{
    helper(board, 0, 0);
}

int main()
{
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    SolveSudoku(board);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
