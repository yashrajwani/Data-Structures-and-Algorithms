#include <iostream>
using namespace std;

int _binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == arr[mid])  return mid;
        else if (x < arr[mid])   high = mid - 1;
        else   low = mid + 1;
    }
    return -1;
}

int naive_search(int arr[], int x)
{
    int i = 0;
    while (true)
    {
        if (arr[i] == x)    return i;
        if (arr[i] > x)    return -1;
        i++;
    }
}

int search(int arr[], int x)
{
    if (arr[0] == x)    return 0;
    int i = 1;
    while (arr[i] < x)
        i *= 2;
    return _binarySearch(arr, i/2 + 1, i, x);
}

int main()
{
    int arr[] = {1,2,3,7,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
    cout << naive_search(arr, 3) << endl;
    cout << search(arr, 3) << endl;
    return 0;
}