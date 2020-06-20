#include <iostream>
using namespace std;

int findPeak(int arr[], int n)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n-1 || arr[mid] >= arr[mid + 1]))   return arr[mid];
        else if (arr[mid - 1] >= arr[mid])  high = mid - 1;
        else    low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPeak(arr, n);
    return 0;
}