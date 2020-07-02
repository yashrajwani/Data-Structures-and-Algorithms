#include <iostream>
using namespace std;

int naiveCountInversions (int arr[], int n)
{
    //inversions condition
    //i < j
    //arr[j] < arr[i]
    int res = 0;
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (arr[j] < arr[i])    ++res;
    return res;
}

int countMerge (int arr[], int l, int m, int r)
{
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; ++i)    left[i] = arr[l+i];
    for (int i = 0; i < n2; ++i)    right[i] = arr[m+1+i];
    
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])    arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            res += n1-i;
        }
    }
    while (i < n1)  arr[k++] = left[i++];
    while (j < n2)  arr[k++] = right[j++];
    
    return res;
}

int countInversions (int arr[], int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r-l)/2;
        res += countInversions(arr, l, m);        
        res += countInversions(arr, m+1, r);        
        res += countMerge(arr, l, m, r);        
    }
    return res;
}

int main()
{
    int arr[] = {8,56,7,5,3,5,7,9,5,34,3,36,8,8,5,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inversions [naive]    : " << naiveCountInversions(arr, n);
    cout << "\nInversions [efficient]: " << countInversions(arr, 0, n-1);
    
    return 0;
}