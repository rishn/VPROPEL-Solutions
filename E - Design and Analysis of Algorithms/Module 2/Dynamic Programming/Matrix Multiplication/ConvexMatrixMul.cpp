//INPUT
/*
3
1 2 3
0 1 5
3 1 2
2 3 4
1 4 5
2 3 1
*/

//OUTPUT
/*
10 20 17 
11 19 10 
11 19 19
*/

//CODE
#include <iostream>
#include <vector>
using namespace std;
void matrixMul(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &mat3)
{
    int i, j, k, n = mat1.size();
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < n; k++)
                mat3[i][j] += mat1[i][k] * mat2[k][j];
        }
}
void readMatrix(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat.size(); j++)
            cin >> mat[i][j];
}
int main()
{
    int i, j, n;
    cin >> n;
    vector<vector<int>> mat1(n, vector<int>(n)), mat2(n, vector<int>(n)), mat3(n, vector<int>(n));
    readMatrix(mat1);
    readMatrix(mat2);
    matrixMul(mat1, mat2, mat3);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << mat3[i][j] << " ";
        cout << endl;
    }
    return 0;
}