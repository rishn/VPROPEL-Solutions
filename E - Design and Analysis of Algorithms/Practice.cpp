#include <iostream>
#include <string>
#include <vector>
using namespace std;
void prefixFunction(vector<vector<int>> &board)
{
    static int count = 1;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "Completed " << count++ << endl;
}
bool notAttacked(vector<vector<int>> &board, int row, int col)
{
    int i, j;
    for (j = 0; j < board.size(); j++)
        if (j != col && board[row][j])
            return 0;
    for (i = 0; i < board.size(); i++)
        if (i != col && board[i][col])
            return 0;
    for (i = row + 1, j = col + 1; i < board.size() && j < board.size(); i++, j++)
        if (board[i][j])
            return 0;
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row + 1, j = col - 1; i < board.size() && j >= 0; i++, j--)
        if (board[i][j])
            return 0;
    for (i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j])
            return 0;
    return 1;
}
void nQueens(vector<vector<int>> &board, int n, int curr_row)
{
    if (curr_row == n)
    {
        printBoard(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
        if (notAttacked(board, curr_row, i))
        {
            board[curr_row][i] = 1;
            nQueens(board, n, curr_row + 1);
            board[curr_row][i] = 0;
        }
}
int main()
{
    string T, P;
    cin >> T >> P;
    KMPMatcher(T, P);
}