//Given sorted array and a number 
//return if there exists a pair in array whose 
//sum equals number

#include <iostream>
using namespace std;

int isPair(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int sum = arr[low] + arr[high];
        if (sum == x)   return true;
        else if (sum > x)    high--;
        else    low++;
    }
    return false;
}

int main()
{
    int arr[] = {6,7,8,9,10,110};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha << isPair(arr, n, 120);
    return 0;
}