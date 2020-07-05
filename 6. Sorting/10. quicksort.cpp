#include <iostream>
#include <algorithm>
using namespace std;

int lomutoPartition (int arr[], int l, int r, int p)
{
    swap(arr[r], arr[p]);
    int pivot = arr[r], bound = l-1;
    
    for (int i = l; i <= r; ++i)    
        if (arr[i] < pivot)    swap(arr[++bound], arr[i]);
    swap(arr[bound+1], arr[r]);
    return (bound + 1);
}

int hoarePartition (int arr[], int l, int r, int p)
{
    swap(arr[l], arr[p]);
    int pivot = arr[l], i = l-1, j = r+1;
    while (true)
    {
        do{
            ++i;
        } while (arr[i] < pivot);
        do{
            --j;
        } while (arr[j] > pivot);
        
        if (i >= j)     return j;
        swap(arr[i], arr[j]);
    }
}

void print (int arr[], int n)
{
    for (int i = 0; i < n; ++i)     cout << arr[i] << " ";
    cout << endl;
}

void copyArray (int src[], int tar[], int n)
{
    for (int i = 0; i < n; ++i)     tar[i] = src[i];
}

void qSort1 (int arr[], int l, int r)
{
    //Using lomuto partition
    if (l < r)
    {
        int p = lomutoPartition (arr, l, r, rand() % (l-r) + l);
        qSort1(arr, l, p-1);
        qSort1 (arr, p+1, r);
    }
}

void qSort2 (int arr[], int l, int r)
{
    //Using Hoare partition
    if (l < r)
    {
        int p = hoarePartition (arr, l, r, rand() % (l-r) + l);
        qSort2(arr, l, p);
        qSort2 (arr, p+1, r);
    }
}

int main()
{
    int arr[] = {10,9,8,7,5,9,8,7,5,9,8,7,5,9,8,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[n], arr2[n], arr3[n];
    copyArray(arr, arr1, n);
    copyArray(arr, arr2, n);
    copyArray(arr, arr3, n);
    
    sort(arr1, arr1+n);
    qSort1(arr2, 0, n-1);
    qSort2(arr3, 0, n-1);
    
    cout << "Sorted array                       : "; print(arr1, n);
    cout << "Quick Sort with lomuto partitioning: "; print(arr2, n);
    cout << "Quick Sort with hoare  partitioning: "; print(arr3, n);
    return 0;
}