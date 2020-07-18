//rotate a matrix 90 degrees anticlockwise

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int N = 5;
int width = log2(N*N) + 1;

void transpose (int mat[N][N])
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            swap (mat[i][j], mat[j][i]);
}

void rotate1 (int mat[N][N])
{
    transpose (mat);

    //reverse columns
    for (int k = 0; k < N; ++k)
    {
        int i = 0, j = N-1;
        while (i < j)   swap(mat[i++][k], mat[j--][k]);
    }
}

void rotate2 (int mat[N][N])
{
    for (int i = 0; i < N/2; ++i)           //consider all sqrs
        for (int j = i; j < N-i-1; ++j)     //elements in grp of 4 in current sqr
        {
            int temp = mat[i][j];                   //store current in temp variable
            mat[i][j] = mat[j][N-i-1];              //move from right to top
            mat[j][N-i-1] = mat[N-i-1][N-j-1];      //bottom to right
            mat[N-i-1][N-j-1] = mat[N-j-1][i];      //left to bottom
            mat[N-j-1][i] = temp;                   //assign temp to left
        }
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
    
    rotate1 (mat);  
    cout << "\nRotated by 90:\n";
    print (mat);

    rotate2 (mat);  
    cout << "\nRotated by 90:\n";
    print (mat);
}

//     1     2     3     4     5 
//     6     7     8     9    10 
//    11    12    13    14    15 
//    16    17    18    19    20 
//    21    22    23    24    25 

// Rotated by 90:
//     5    10    15    20    25 
//     4     9    14    19    24 
//     3     8    13    18    23 
//     2     7    12    17    22 
//     1     6    11    16    21 

// Rotated by 90:
//    25    24    23    22    21 
//    20    19    18    17    16 
//    15    14    13    12    11 
//    10     9     8     7     6 
//     5     4     3     2     1 