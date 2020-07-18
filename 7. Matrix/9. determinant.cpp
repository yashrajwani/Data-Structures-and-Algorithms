#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int N = 2;
int width = log2(N*N) + 1;

void getCofactor (int mat[N][N], int temp[N][N], int p, int q, int n)
{
    //function to get cofactor of mat[p][q] in temp array
    //n is current dimension of mat[][]
    int i = 0, j = 0;
    for (int row = 0; row < N; ++row)
        for (int col = 0; col < N; ++col)
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == n-1)
                {
                    j = 0;
                    i++;
                }
            }
}

int determinant (int mat[N][N], int n)
{
    int D = 0; //initialize result
    if (n==1)   return mat[0][0];   //base case

    int temp[N][N];   //for storing cofactors
    int sign = 1;     //multiplier

    for (int f = 0; f < N; ++f)
    {
        getCofactor (mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant (temp, n-1);
        sign *= -1;
    }
    return D;
}

void print (int mat[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)     cout << setw(width) << mat[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    int mat[N][N], ctr = 1;;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mat[i][j] = ctr++;
    
    print (mat);
    cout << "Determinant: " << determinant(mat, N);     //-2
    
}
