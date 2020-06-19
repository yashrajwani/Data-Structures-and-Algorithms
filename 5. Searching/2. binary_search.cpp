#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x > arr[mid])   low = mid + 1;
        else if (x < arr[mid])  high = mid - 1;
        else    return mid;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << binarySearch(arr, n, 6);
    return 0;
}