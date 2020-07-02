#include <iostream>
using namespace std;

void printArray (int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void naivePartition (int arr[], int l, int h, int p)
{
    int pivot = arr[p], temp[h-l+1], idx = 0;
    for (int i = l; i <= h; ++i)
        if (arr[i] <= pivot)   temp[idx++] = arr[i];
    
    for (int i = l; i <= h; ++i)
        if (arr[i] > pivot)   temp[idx++] = arr[i];
    
    for (int i = l; i <= h; ++i)
        arr[i] = temp[i-l];
}

int main()
{
    int arr[] = {9,3,5,2,4,6,3,2,4,6,7,4,5,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 1;
    printArray(arr, n);
    cout << "Pivot: " << arr[p] << endl;

    naivePartition(arr, 0, n-1, p);
    
    printArray(arr, n); 
}