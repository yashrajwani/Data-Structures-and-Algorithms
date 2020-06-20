#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)      return mid;
        else if (arr[mid] >= arr[low])
        {
            //left sorted
            if (x >= arr[low] && x <= arr[mid])     high = mid - 1;
            else    low = mid  + 1;
        }
        else
        {
            //right sorted
            if (x >= arr[mid] && x <= arr[high])     low = mid  + 1;
            else    high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5,6,7,8,9,1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << search(arr, n, 6);
}