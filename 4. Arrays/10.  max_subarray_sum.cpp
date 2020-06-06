#include <iostream>
using namespace std;

int naive_maxSum(int arr[], int n)
{
    //theta n^2 time complexity
    //theta 1 aux space

    int res = 0, curr = 0;
    for (int i =0; i < n; ++i)
    {
        curr = 0;
        for (int j = i; j < n; ++j)
        {
            curr += arr[j];
            res = max(curr, res);
        }
    }
    return res;
}

int maxSum(int arr[], int n)
{
    //theta n time complexity
    //theta 1 aux space
    //Kadane's Algorithm

    int res = arr[0], maxEnding = arr[0];
    for (int i = 1; i < n; ++i)  
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(maxEnding, res); 
    }
    return res;
}

int main()
{
    int arr[] = {10,11,-14,8,9,6,3,-11,7};
    int n = 9;

    cout << "Max Subarray Sum [naive]    : " << naive_maxSum(arr, n) << endl;
    cout << "Max Subarray Sum [efficient]: " << maxSum(arr, n);
    
    return 0;
}