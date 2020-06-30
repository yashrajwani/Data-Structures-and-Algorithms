#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {5,6,7,4,23,3,54,5,6,7,8,89,8,6,4,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    for (auto x : arr)  cout << x << " ";
    cout << endl;
    
    sort(arr, arr + n, greater <int> ());
    for (auto x : arr)  cout << x << " ";
    cout << endl;
    
    vector <int> v = {3,5,67,8,6,4,2,4,56,7,8,9,6,4,2,2};
    sort(v.begin(), v.end());
    for (auto x: v)     cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end(), greater <int> ());
    for (auto x: v)     cout << x << " ";
    cout << endl;

    return 0;
}