#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort (int arr[], int n, int k)
{
    //implemetation assumption min val in arr is 0

    int max_val = arr[0];
    for (int i = 0; i < n; ++i)  max_val  = max(arr[i], max_val);
    ++max_val;  //so that max(arr) / max_val is less than 1

    vector <int> bkt[k];        //array of vectors of size k
    for (int i = 0; i < n; ++i)
    {
        int bi = (k * arr[i]) / max_val;
        bkt[bi].push_back(arr[i]);
    }

    //sorting individual buckets
    for (int i = 0; i < k; ++i)     sort(bkt[i].begin(), bkt[i].end());

    //merging sorted buckets
    int idx = 0;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < bkt[i].size(); ++j)     arr[idx++] = bkt[i][j];
}

int main()
{
    int arr[] = {5,9,8,8,7,4,6,3,0,2,1};      
    bucketSort(arr, sizeof(arr)/sizeof(arr[0]), 10);
    for (auto x : arr)  cout << x << " ";
    return 0;
}