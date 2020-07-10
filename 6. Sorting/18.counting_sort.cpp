#include <iostream>
#include <cstring>
using namespace std;

void countSort(int arr[], int n, int k)
{
    int count[k];
    memset(count, 0, n * sizeof(int));  //initialize count arr to 0
    for (int i = 0; i < n; ++i)     count[arr[i]]++;
    for (int i = 1; i < n; ++i)     count[i] += count[i-1];      //cumulative sum

    int output[n];
    for (int i = n-1; i >= 0; --i)      //reverse traversal for stability
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; ++i)     arr[i] = output[i];
}

int main()
{
    int arr[] = {5,9,8,8,7,4,6,3,0,2,1};      //arr range 0 to 9
    countSort(arr, sizeof(arr)/sizeof(arr[0]), 10);
    for (auto x : arr)  cout << x << " ";
    return 0;
}