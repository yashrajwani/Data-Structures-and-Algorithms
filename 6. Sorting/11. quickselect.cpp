//finding kth smallest element in array

#include <iostream>
#include <algorithm>
using namespace std;


int naiveKthSmallest (int arr[], int n, int k)
{
    // O(nlogn)
    sort(arr, arr+n);
    return arr[k-1];
}


int lomutoPartition (int arr[], int l, int r, int p)
{
    swap(arr[r], arr[p]);
    int pivot = arr[r], bound = l-1;
    
    for (int i = l; i <= r; ++i)    
        if (arr[i] < pivot)    swap(arr[++bound], arr[i]);
    swap(arr[bound+1], arr[r]);
    return (bound + 1);
}

int kthSmallest (int arr[], int n, int k)
{
    //worst case O(n^2)
    //avg case theta(n)
    //also called quci select algo
    if (k > n)  return -1;
    
    int l = 0, r = n-1;
    while (l <= r)
    {
        int p = lomutoPartition(arr, l, r, rand() % (l-r) + l);

        if (p == k-1)   return p;
        else if (k-1 < p)   r = p-1;
        else    l = p+1; 
    }
}

int main()
{
    int arr[] = {5,27,33,55,647,655,38,324,5436,95675,647};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = rand() % n + 1;

    cout << k << "th smallest element: " << arr[kthSmallest(arr, n, k)] << endl;
    cout << k << "th smallest element: " << naiveKthSmallest(arr, n, k) ;
    
    return 0;
}