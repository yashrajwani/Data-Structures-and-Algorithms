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
    transpose(mat);  
    cout << "\nTranspose:\n";
    print (mat);
}

//     1     2     3     4     5 
//     6     7     8     9    10 
//    11    12    13    14    15 
//    16    17    18    19    20 
//    21    22    23    24    25 

// Transpose:
//     1     6    11    16    21 
//     2     7    12    17    22 
//     3     8    13    18    23 
//     4     9    14    19    24 
//     5    10    15    20    25 