#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void printBoard(vector<vector<int>> board)
{
    int n, i, j;
    n = board.size();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "Completed" << endl;
}
bool notAttacked(vector<vector<int>> &board, int row, int col)
{
    int n = board.size(), i, j;
    for (j = 0; j < n; j++)
        if ((j != col) && (board[row][j] == 1))
            return 0;
    for (i = 0; i < n; i++)
        if ((i != row) && (board[i][col] == 1))
            return 0;
    for (i = row + 1, j = col + 1; i < n && j < n; i++, j++)
        if (board[i][j] == 1)
            return 0;
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;
    for (i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return 0;
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return 0;
    return 1;
}
void nQueens(vector<vector<int>> &board, int n, int curr_row, stack<int> &pos)
{
    int i;
    if (curr_row == n)
    {
        printBoard(board);
        return;
    }
    if (pos.size() <= curr_row)
        i = 0;
    else
    {
        i = pos.top() + 1;
        board[curr_row][pos.top()] = 0;
        pos.pop();
    }
    for (; i < n; i++)
        if (notAttacked(board, curr_row, i))
        {
            pos.push(i);
            board[curr_row][i] = 1;
            nQueens(board, n, curr_row + 1, pos);
            return;
        }
    nQueens(board, n, curr_row - 1, pos);
}
int main()
{
    int n, i, j;
    cin >> n;
    vector<int> row(n, 0);
    vector<vector<int>> board(n, row);
    stack<int> pos;
    nQueens(board, n, 0, pos);
    return 0;
}