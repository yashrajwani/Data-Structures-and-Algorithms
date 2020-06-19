#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; ++i)
        if (arr[i] == x)    return i;
    return -1;
}

int main()
{
    int arr[] = {5,6,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << linearSearch(arr, n, 1);
    return 0;
}