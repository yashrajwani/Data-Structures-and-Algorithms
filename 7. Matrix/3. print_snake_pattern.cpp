#include <iostream>
using namespace std;

const int N = 5;

void printSnake (int mat[][N], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        if (i % 2)
            for (int j = cols-1; j >= 0; --j)  cout << mat[i][j] << " ";
        
        else
            for (int j = 0; j < cols; ++j)  cout << mat[i][j] << " ";
    }
}

int main()
{
    int mat[N][N], ctr = 1;;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mat[i][j] = ctr++;

    printSnake(mat, N, N);  //1 2 3 4 5 10 9 8 7 6 11 12 13 14 15 20 19 18 17 16 21 22 23 24 25
}