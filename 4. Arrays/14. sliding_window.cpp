#include <iostream>
using namespace std;

//Given an array of integers and a number k find max sum of k consec elements
int naive_maxSumK(int arr[], int n, int k)
{
    //time theta(n*k)

    int maxm = INT32_MIN;
    for (int i = 0; i < n-k+1; ++i)
    {
        int sum = 0;
        for (int j = 0; j < k; ++j)
            sum += arr[i + j];
        maxm = max(sum, maxm);
    }
    return maxm;
}

int maxSumK(int arr[], int n, int k)
{
    //time theta(n)
    //trick is to reuse computations using sliding window
    
    int curr_sum = 0;
    for (int i = 0; i < k; ++i)
        curr_sum += arr[i];

    int maxm = curr_sum;
    for (int i = k; i < n; ++i)
    {
        curr_sum += (arr[i] - arr[i-k]);
        maxm = max(curr_sum, maxm);
    }

    return maxm;
}

//Given an unsorted array of non negative integers.Find if there's a subarray with given sum
bool naive_isSubarray(int arr[], int n, int given_sum)
{   
    //time theta(n^2)
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            if (sum == given_sum)      return true;
        }
    }
    return false;
}

bool isSubarray(int arr[], int n, int given_sum)
{
    //time theta(n)
    int curr_sum = arr[0], start = 0;
    for (int end = 1; end <= n; ++end)
    {
        //Clean sliding window
        while ((curr_sum > given_sum) && (start < end-1))
        {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == given_sum)      return true;
        if (end < n)    curr_sum += arr[end];
    }
    return false;
}

//N-bonacci numbers 
//Given n, m print first m n-bonacci numbers
void nBonacci(int n, int m)
{
    //Assuming m>n
    int arr[m] = {0};
    arr[n-1] = 1;
    
    //Using sliding window to reuse computation
    arr[n] = 1;     //n+1 n-bonacci number is sum of first n numbers = 1 (first n-1 are 0s) (nth is 1)
    for (int i = n+1; i < m; ++i)
        arr[i] = 2*arr[i-1] - arr[i-n-1];

    //print 
    for (int i = 0; i < m; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    //Nbonacci numbers
    int n = 3, m = 10;
    cout << "First " << m << " " << n <<"-bonacci numbers:" << endl;
    nBonacci(3, 10);
    cout << endl;

    int arr[] = {12,23,34,45,56,67,78,89};
    n = sizeof(arr) / sizeof(arr[0]);

    //Max sum of kconsecutive elements
    int k = 1;
    cout << "Max sum of k-consecutive elements [naive]    : " << naive_maxSumK(arr, n, k) << endl;
    cout << "Max sum of k-consecutive elements [efficient]: " << maxSumK(arr, n, k) << endl;

    //if there's a subarray with given sum
    int given_sum = 78;
    cout << "isSubarray [naive]    : " << boolalpha << naive_isSubarray(arr, n, given_sum) << endl;
    cout << "isSubarray [efficient]: " << boolalpha << isSubarray(arr, n, given_sum) << endl;
    
    return 0;
}