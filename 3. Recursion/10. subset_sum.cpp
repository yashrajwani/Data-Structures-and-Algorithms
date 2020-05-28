#include <iostream>
using namespace std;

int subset_sum(int arr[], int n, int sum, int idx = 0, int running_sum = 0)
{
    if (idx == n)
    {
        return ((running_sum == sum) ? 1 : 0);
    }
    ++idx;
    return (subset_sum(arr, n, sum, idx, running_sum) + subset_sum(arr, n, sum, idx, running_sum + arr[idx - 1]));
}

int subset_sum_v2(int arr[], int n, int sum)
{
    if (n == 0)
    {
        return ((0 == sum) ? 1 : 0);
    }
    return (subset_sum(arr, n - 1, sum) + subset_sum(arr, n - 1, sum - arr[n - 1]));
}

int main()
{
    int n, sum;
    cout << "input array size, required sum [separated by space]: "; cin >> n >> sum;
    int arr[n];
    cout << "Input array elements separted by space: \n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Total desired subsets: " << subset_sum(arr, n, sum);
    cout << "Total desired subsets: " << subset_sum_v2(arr, n, sum);
    
    return 0;
}