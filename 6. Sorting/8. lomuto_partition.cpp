#include <iostream>
using namespace std;

void printArray (int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int lomutoPartition (int arr[], int l, int h, int p)
{
    //elements before return value are < pivot
    //elements after return value are >= pivot
    
    swap(arr[p], arr[h]);   //last element is pivot
    
    int pivot = arr[h], i = l-1;
    for (int j = l; j < h; ++j)
        if (arr[j] < pivot)     swap(arr[j], arr[++i]);
    
    swap(arr[i+1], arr[h]);
    return i+1;
}

int main()
{
    int arr[] = {9,3,5,2,4,6,3,2,4,6,7,4,5,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 1;
    printArray(arr, n);
    cout << "Pivot: " << arr[p] << endl;

    lomutoPartition(arr, 0, n-1, p);
    
    printArray(arr, n); 
}