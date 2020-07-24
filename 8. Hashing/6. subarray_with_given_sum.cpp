#include <iostream>
#include <unordered_set>
using namespace std;

//returns if theres exists subarray with given sum
bool isSum (int arr[], int n, int sum)
{
    unordered_set <int> s;
    int prefix_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)    return true;
        if (s.find(prefix_sum - sum) != s.end())     return true;
        s.insert (prefix_sum);
    }
    return false;
}


int main ()
{
    int arr1[] = {1,2,3,5,4,6,7,8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Subarray with sum 19 = " << boolalpha << isSum(arr1, n1, 19) << endl;      //Subarray with sum 19 = false
    cout << "Subarray with sum 10 = " << boolalpha << isSum(arr1, n1, 10) << endl;      //Subarray with sum 10 = true
    
    return 0;
}
