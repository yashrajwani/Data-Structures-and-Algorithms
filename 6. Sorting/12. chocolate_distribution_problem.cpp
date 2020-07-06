//Every element of arrays is a chocolate packet with arr[i] number of chocolates
//Give m chocolate packets to m students
//minimize diff between max chocolates given to a child and min chocolates given to a child
//return min diff

#include <iostream>
#include <algorithm>
using namespace std;

int minDiff (int arr[], int n, int m)
{
    if (m > n)  return -1;
    sort(arr, arr+n);

    int res = INT32_MAX;
    for (int i = 0; (i+m-1) < n; ++i)
        res = min(res, arr[i+m-1] - arr[i]);
    return res;
}

int main()
{
    int arr1[] = {7,3,2,4,9,12,56}, arr2[] = {3,4,1,9,56,7,9,12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout<< minDiff(arr1, n1, 3) << endl
        << minDiff(arr2, n2, 5) << endl;
    return 0;   
}