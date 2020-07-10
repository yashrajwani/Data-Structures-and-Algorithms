#include <iostream>
#include <cstring>
using namespace std;

void _countingSort(int arr[], int n, int exp)
{
    int count[10];
    memset(count, 0, n * sizeof(int));  //initialize count arr to 0
    for (int i = 0; i < n; ++i)     count[(arr[i]/exp) % 10]++;
    for (int i = 1; i < n; ++i)     count[i] += count[i-1];      //cumulative sum

    int output[n];
    for (int i = n-1; i >= 0; --i)      //reverse traversal for stability
    {
        output[--count[(arr[i]/exp) % 10]] = arr[i];
    }

    for (int i = 0; i < n; ++i)     arr[i] = output[i];
}

void radixSort (int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; ++i)     mx = max(mx, arr[i]);
    for (int exp = 1; mx/exp > 0; exp *= 10)    _countingSort (arr, n, exp);
}

int main()
{
    int arr[] = {5,9,8,8,7,4,6,3,0,2,1};    
    radixSort(arr, sizeof(arr)/sizeof(arr[0]));
    for (auto x : arr)  cout << x << " ";
    return 0;
}