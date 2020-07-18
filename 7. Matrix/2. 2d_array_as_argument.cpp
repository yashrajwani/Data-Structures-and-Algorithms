#include <iostream>
#include <vector>
using namespace std;

const int m = 2, n = 2;

void printNative (int mat[][n], int rows)
{
    //for printing native arrays we need to know number of columns in advance
    //we can have arbitrary number of rows
    //if i wanted implementation for fixed size of matrices
    //the decalrator would have been
    //printNative (int mat[m][n])

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < n; ++j)     cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printNative_v2 (int mat[m][n])
{
    //for fixed size arrays of size (m,n)

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)     cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printMatrix (int **mat, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)     cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printVectorMatrix (vector < vector<int> > &mat)
{
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[i].size(); ++j)     cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


int main()
{
    int ctr = 1;

    //Native 2d array
    int arr[m][n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) arr[i][j] = ctr++;

    printNative (arr, m);
    printNative_v2 (arr);


    //for Double ptr array or for array of pointers
    int *arr1[m];
    for (int i = 0; i < m; ++i)
    {
        arr1[i] = new int [n];
        for (int j = 0; j < n; ++j)     arr1[i][j] = ctr++;
    }
    printMatrix (arr1, m, n);

    //for vector of vectors
    vector <vector <int>> arr2;
    for (int i = 0; i < m; ++i)
    {
        vector <int> vec;
        for (int j = 0; j < n; ++j)     vec.push_back(ctr++);
        arr2.push_back(vec);
    }

    printVectorMatrix (arr2);
    
    return 0;
}