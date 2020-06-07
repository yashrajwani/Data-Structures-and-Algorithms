#include <iostream>
using namespace std;

int naive_circularMaxSum(int arr[], int n)
{
    //Theta n^2 time complexity
    //Theta 1 aux space
    int res = arr[n-1];     //temp value assignment
    for (int i = 0; i < n; ++i)
    {
        int curr = arr[i];
        for (int j = 1; j < n; ++j)
        {
            res = max(res, curr);
            curr += arr[(i+j)%n];
        }
    }
    return res;
}

int maxSumSubarray(int arr[], int n)
{
    //Theta n time complexity
    //Theta 1 aux space

    int maxEnding = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; ++i)
    {
        maxEnding = max(arr[i], arr[i] + maxEnding);
        res = max(res, maxEnding);
    }
    return res;
}

int circularMaxSum(int arr[], int n)
{
    //Theta n time complexity
    //Theta 1 aux space

    int normal_max = maxSumSubarray(arr, n);
    
    if (normal_max < 0)     return normal_max;      //this implies all elements are -ve and circular_max would always return 0 which is wrong ans [check notes]
    
    int arr_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int circular_max = arr_sum + maxSumSubarray(arr, n);    //here maxSumSubarray returns -ve minSumSubarray by array inversion trick
    
    return max(normal_max, circular_max);
}

int main()
{
  int arr[] = {3,-4,5,6,-8,7};
  int n = 6;
  cout << "circular max sum [naive]    : " << naive_circularMaxSum(arr, n) << endl;
  cout << "circular max sum [efficient]: " << circularMaxSum(arr, n);
}