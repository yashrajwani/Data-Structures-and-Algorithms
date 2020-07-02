#include <iostream>
using namespace std;

void printArray (int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int hoarePartition (int arr[], int l, int h, int p)
{
    //elements before return value are <= pivot
    //elements after return value are >= pivot
    
    swap(arr[p], arr[l]);   //first element is pivot
    
    int i = l-1, j = h+1, pivot = arr[l];
    while (true)
    {
        do
        {
          ++i;  
        } while (arr[i] < pivot);
        
        do
        {
          --j;
        } while (arr[j] > pivot);
        
        if (i >= j)     return j;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {9,3,5,2,4,6,3,2,4,6,7,4,5,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 1;
    printArray(arr, n);
    cout << "Pivot: " << arr[p] << endl;

    hoarePartition(arr, 0, n-1, p);
    
    printArray(arr, n); 
}