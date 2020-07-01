#include <iostream>
using namespace std;

void merge (int arr[], int l, int m, int r)
{
    //elements from index l to m are sorted
    //elements from index m+1 to r are sorted

    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];
    
    for (int i = 0; i < n1; ++i)    left[i] = arr[l + i];
    for (int i = 0; i < n2; ++i)    right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])    arr[k++] = left[i++];       //sign "<=" is used to preserve stability while sorting
        else    arr[k++] = right[j++];
    }
    while (i < n1)  arr[k++] = left[i++];
    while (j < n2)  arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)      //ensuring there's atleast two elements in array
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)     cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1,2,30,402,3,4,5,100};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    print_arr(arr, n);
    return 0;
}