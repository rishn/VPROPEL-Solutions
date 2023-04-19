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
2 3 1
4 11 0 
1 4 0 
0 0 0 
*/

//CODE
#include <iostream>
#include <vector>
using namespace std;
void recMul(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &mat3, int top1, int left1, int top2, int left2, int size)
{
    if (size == 1)
        mat3[top1][left2] += mat1[top1][left1] * mat2[top2][left2];
    else
    {
        /*
        M(11) - top, left
        M(12) - top, left + n / 2
        M(21) - top + n / 2, left
        M(22) - top + n / 2, left + n / 2
        */
        recMul(mat1, mat2, mat3, top1, left1, top2, left2, size / 2); //M1(11) * M2 (11)
        recMul(mat1, mat2, mat3, top1, left1, top2, left2 + size / 2, size / 2); //M1(11) * M2(12)
        recMul(mat1, mat2, mat3, top1, left1 + size / 2, top2 + size / 2, left2, size / 2); //M1(12) *M2(21)
        recMul(mat1, mat2, mat3, top1, left1 + size / 2, top2 + size / 2, left2 + size / 2, size / 2); //M1(12) * M2(22)
        recMul(mat1, mat2, mat3, top1 + size / 2, left1, top2, left2, size / 2); //M1(21) * M2(11)
        recMul(mat1, mat2, mat3, top1 + size / 2, left1, top2, left2 + size / 2, size / 2); //M1(21) * M2(12)
        recMul(mat1, mat2, mat3, top1 + size / 2, left1 + size / 2, top2 + size / 2, left2, size / 2); //M1(22) * M2(21)
        recMul(mat1, mat2, mat3, top1 + size / 2, left1 + size / 2, top2 + size / 2, left2 + size / 2, size / 2); //M1(22) *M2(22)
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
    recMul(mat1, mat2, mat3, 0, 0, 0, 0, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << mat3[i][j] << " ";
        cout << endl;
    }
    return 0;
}