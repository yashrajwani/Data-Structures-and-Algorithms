#include <iostream>
using namespace std;

void iSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key)      
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {5,4,3,4,98,8,4,6,5,21,3,5,74};
    int n = sizeof(arr) / sizeof(arr[0]);

    iSort(arr, n);
    for (auto x : arr)  cout << x << " ";

    return 0;
}