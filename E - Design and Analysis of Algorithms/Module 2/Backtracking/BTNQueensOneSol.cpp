#include <iostream>
#include <vector>
using namespace std;
int count = 1;
void printBoard(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "Completed " << count++ << endl;
}
int notAttacked(vector<vector<int>> &board, int n, int row, int col)
{
    int i, j;
    for (j = 0; j < n; j++)
        if (j != col && board[row][j])
            return 0;
    for (i = 0; i < n; i++)
        if (i != row && board[i][col])
            return 0;
    for (i = row + 1, j = col + 1; i < n && j < n; i++, j++)
        if (board[i][j])
            return 0;
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return 0;
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return 0;
    return 1;
}
void nQueens(vector<vector<int>> &board, int n, int curr_row)
{
    if (count == 2)
        return;
    if (curr_row == n)
    {
        printBoard(board, n);
        return;
    }
    for (int i = 0; i < n; i++)
        if (notAttacked(board, n, curr_row, i))
        {
            board[curr_row][i] = 1;
            nQueens(board, n, curr_row + 1);
            board[curr_row][i] = 0;
        }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueens(board, n, 0);
    return 0;
}