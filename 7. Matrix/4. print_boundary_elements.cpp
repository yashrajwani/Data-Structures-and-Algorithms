#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 5;

void boundaryTraversal (int mat[rows][cols])
{
    if (rows == 1)  
        for (int i = 0; i < cols; ++i)  cout << mat[0][i] << " ";
    
    else if (cols == 1)  
        for (int i = 0; i < cols; ++i)  cout << mat[i][0] << " ";
    
    else
    {
        for (int i = 0; i < cols; ++i)  cout << mat[0][i] << " ";           //top row left to right
        for (int i = 1; i < rows; ++i)  cout << mat[i][cols-1] << " ";      //last column top to bottom
        for (int i = cols-2; i >= 0; --i)  cout << mat[rows-1][i] << " ";   //last row right to left
        for (int i = rows-2; i >= 1; --i)  cout << mat[i][0] << " ";        //last column top to bottom
    }
    cout << endl;
}

int main()
{
    int mat[rows][cols], ctr = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mat[i][j] = ctr++;

    boundaryTraversal (mat);    //1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 
}