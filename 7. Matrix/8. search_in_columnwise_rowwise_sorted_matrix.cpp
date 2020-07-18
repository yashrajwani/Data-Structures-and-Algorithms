#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 5;

void search (int arr[rows][cols], int x)
{
    int i = 0, j = cols-1;
    while (i < rows && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Found at " << i << ", " << j << endl;
            return;
        }

        else if (arr[i][j] < x)     ++i;
        else   --j;
    }
    cout << "Not found\n";
}

int main()
{
    int mat[rows][cols], ctr = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mat[i][j] = ctr++;
    int x = 23;
    search (mat, x);    //Found at 4, 2
}