#include <iostream>
using namespace std;

void heapify (int arr[], int n, int i)
{
   int l = 2*i + 1;
   int r = 2*i + 2;
   int largest = i;

   //if left child is greater
   if (l < n && arr[l] > arr[largest])  largest = l;
   //if right child is greater
   if (r < n && arr[r] > arr[largest])  largest = r;
   if (largest != i)
   {
       swap (arr[largest], arr[i]);
       //recursively heapify affected subtree
       heapify(arr, n, largest);
   }
}

void heapSort (int arr[], int n)
{
    //build heap
    for (int i = n/2 - 1; i >= 0; --i)  heapify(arr, n, i);

    //extract elements
    for (int i = n-1; i >= 0; --i)
    {
        swap (arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {5,9,8,8,7,4,6,3,0,2,1};      
    heapSort(arr, sizeof(arr)/sizeof(arr[0]));
    for (auto x : arr)  cout << x << " ";
    
    return 0;
}