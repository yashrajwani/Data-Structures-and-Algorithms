#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x < arr[mid])   high = mid - 1;
        else if(x > arr[mid])   low = mid + 1;
        else
        {
            if ((mid == 0) || (arr[mid] != arr[mid-1]))     return mid;
            high = mid - 1;
        }
    }
    return -1;
}

int lastOcc(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (x < arr[mid])   high = mid - 1;
        else if (x > arr[mid])  low = mid + 1;
        else
        {
            if ((mid == n-1) || (arr[mid] != arr[mid+1]))   return mid;
            low = mid + 1;
        }
    }
    return -1;
}

int countOcc(int arr[], int n, int x)
{
    int first = firstOcc(arr, n, x);
    if (first == -1)    return -1;
    return (lastOcc(arr, n, x) - first + 1);
}

int main()
{
    int arr[] = {0,0,0,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << firstOcc(arr, n, 3) << endl;
    cout << lastOcc(arr, n, 2) << endl;
    cout << countOcc(arr, n, 3) << endl;
    return 0;
}