//ALGORITHM
/*
Declare integer n
notAttacked(chess, r, c)
{
    i <- 0
    until (i >= c)
    {
        if (chess[r][i] == 1)
            return 0
        i += 1
   }
   i <- r, j <- c
   until (i < 0 || j < 0)
   {
        if (chess[i][j] == 1)
            return 0
        i -= 1
        j -= 1
   }
   i <- r, j <- c
    until (i >= n || j < 0)
    {
        if (chess[i][j])
            return 0
        i += 1
        j -= 1
    }
    return 1
}
NQueens(chess, int c)
{
    if (c == n)
    {
        i <- 0
        until (i >= n)
        {
            j <- 0
            until (j >= n - 1)
            {
                print(chess[i][j] + " ")
                j += 1
            }
            print(chess[i][n - 1] + "\n")
            i += 1
        }
        print("\n")
        return 1
    }
    i <- 0
    until (i >= n)
    {
        if (notAttacked(chess, i, c))
        {
            chess[i][c] <- 1;
            if (NQueens(chess, c + 1))
            {
                return 1
            }
            chess[i][c] <- 0
        }
        i += 1
    }
    return 0
}
Solve_NQueens()
{
    Read n
    chess <- 2D array of size n * n
    if (! NQueens(chess, 0))
    {
        print(false)
    }
}
*/

//CODE
#include <iostream>
#include <vector>
using namespace std;
int n;
int notAttacked(vector<vector<int>>& chess, int r, int c)
{
    int i, j;
    for (i = 0; i < c; i++)
        if (chess[r][i])
            return 0;
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (chess[i][j])
            return 0;
    for (i = r, j = c; i < n && j >= 0; i++, j--)
        if (chess[i][j])
            return 0;
    return 1;
}
int nQueens(vector<vector<int>>& chess, int c)
{
    int i, j;
    if (c == n)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++)
                cout << chess[i][j] << " ";
            cout << chess[i][n - 1] << "\n";
        }
        cout << "\n";
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (notAttacked(chess, i, c))
        {
            chess[i][c] = 1;
            if (nQueens(chess, c + 1))
                return 1;
            chess[i][c] = 0;
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    if (! nQueens(chess, 0))
        cout << false;
    else
        cout << "Completed";
    return 0;
}
