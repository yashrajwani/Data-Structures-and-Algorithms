//Given an array of size n has numbers from 1 to n + 1 every number appearing atmost 1 time
//Find missing numebr
#include <iostream>
using namespace std;

int missingElement(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = res ^ arr[i];

    for (int i = 1; i < n + 2; ++i)
        res = res ^ i;

    return res;
}

int main()
{
    int N;
    cout << "Array Size: "; cin >> N;
    int arr[N];

    cout << "Enter array elements separated by space.\n";
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << "Missing Element: " << missingElement(arr, N) << endl;
}
