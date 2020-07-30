#include <iostream>
#include <unordered_map>
using namespace std;

//returns longest subarray with given sum
int longestSub (int arr[], int n, int sum)
{
    unordered_map <int, int> m;
    int presum = 0, res = 0;
    for (int i = 0; i < n; ++i)
    {
        presum += arr[i];
        if (presum == sum)      res = i+1;                                          //sequence starts from idx 0
        if (m.find(presum) == m.end())     m.insert({presum, i});              //if value of presum repeats retain earlier or dismiss latter
        if (m.find(presum-sum) != m.end())  res = max(res, i-m[presum-sum]);   //desired sequence found then update res if needed
    }
    return res;
}

//longest subarray with equal number of 0s and 1s
//{1,0,1,1,1,0,0} --> 6
//this problem can be reduced to finding longest subarray with sum=0
//by replacing 0 by -1
int maxlen0sAnd1s(bool arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; ++i)     temp[i] = (arr[i]) ? 1 : -1;
    return longestSub (temp, n, 0);
}

int main ()
{
    int arr1[] = {3,1,0,1,8,2,3,6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Longest subarray with sum 5 = " << longestSub(arr1, n1, 5) << endl;      //Longest subarray with sum 5 = 4
    cout << "Longest subarray with sum 9 = " << longestSub(arr1, n1, 9) << endl;      //Longest subarray with sum 9 = 2
    cout << endl;
    
    bool arr2[] = {1,0,1,1,1,0,0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Longest subarray with equal number of 0s and 1s: " << maxlen0sAnd1s(arr2, n2) << endl;     //Longest subarray with equal number of 0s and 1s: 6

    return 0;
}
