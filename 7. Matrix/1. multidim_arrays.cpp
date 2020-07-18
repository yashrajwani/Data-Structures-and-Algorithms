#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m = 10, n = 10;
    //Native array
    int arr[m][n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)     arr[i][j] = 0;
    
    //Double Ptr Approach
    int **arr2;
    arr2 = new int *[m];
    for (int i = 0; i < m; ++i)
    {
        arr2[i] = new int [n];
        for (int j = 0; j < n; ++j)     arr2[i][j] = 0;
    }

    //Array of Ptr
    int *arr3[m];
    for (int i = 0; i < m; ++i)
    {
        arr3[i] = new int [n];
        for (int j = 0; j < n; ++j)     arr3[i][j] = 0;
    }
    
    //Vector array
    vector <int> arr4[m];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)     arr4[i].push_back(0);

    //Vector of Vectors
    vector <vector <int>> arr5;
    for (int i = 0; i < m; ++i)
    {
        vector <int> vec;
        for (int j = 0; j < n; ++j)     vec.push_back(0);
        arr5.push_back(vec);
    }

    return 0;
}