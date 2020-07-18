#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 5;

void spiralTraversal (int mat[rows][cols])
{
    int left = 0, right = cols-1, top = 0, bottom = rows-1;
    while (left <= right && top <= bottom)
    {
        //left to right
        for (int i = left; i <= right; ++i)
            cout << mat[top][i] << " ";
        ++top;

        //top to bottom
        for (int i = top; i <= bottom; ++i)
            cout << mat[i][right] << " ";
        --right;

        //right to left
        for (int i = right; i >= left; --i)
            cout << mat[bottom][i] << " ";
        --bottom;

        //bottom to top
        for (int i = bottom; i >= top; --i)
            cout << mat[i][left] << " ";
        ++left;
    }
}

int main()
{
    int mat[rows][cols], ctr = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mat[i][j] = ctr++;

    spiralTraversal (mat);    //1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13  
}