#include <iostream>
#include <vector>
using namespace std;

//Getting sum of an array from  index l to index r
int naive_getSum(int l, int r, int arr[])
{
    //time O(n)
    int sum = 0;
    for (int i = l; i <= r; ++i)
        sum += arr[i];

    return sum;
}

int getSum(int l, int r, int prefix_sum[])
{
    //time O(1)
    if (l == 0) return prefix_sum[r];
    return -prefix_sum[l-1] + prefix_sum[r];
}

//Given an array of integers find if it has equilibrium pt.(sum of all elemtnts to left = sum of all elements to right)
bool naive_isEqui(int arr[],int n)
{
    //time theta(n^2)
    for (int i = 0; i < n; ++i)
    {
        int lsum = 0, rsum = 0;
        
        //Counting left sum
        for (int j = 0; j < i; ++j)     lsum += arr[j];

        //Counting right sum
        for (int j = i+1; j < n; ++j)     rsum += arr[j];

        if (rsum == lsum)   return true;
    }
    return false;
}

bool isEqui(int arr[], int n)
{
    //time theta(n)
    int arr_sum = 0, lsum = 0;
    for (int i =0; i < n; ++i)
        arr_sum += arr[i];

    for (int i = 0; i <= n; ++i)
    {
        int rsum = arr_sum - arr[i] - lsum;
        if (rsum == lsum)   return true;
        if (i < n)  lsum += arr[i];
    }
    return false;
}

//Given n ranges find maximum appearing element in these ranges


int maxOcc(int L[], int R[], int n)
{
    //time theta(n)

    //Trick to build element freq table
    vector <int> arr (1000);     //as it's given that 0<=L[i],R[i]<1000 
    for (int i = 0; i < n; ++i)
    {
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }

    int res = 0, maxm = arr[0];
    for (int i = 1; i < 1000; ++i)
    {
        //Building prefix table
        arr[i] += arr[i-1];

        if (maxm < arr[i])  
        {
            maxm = arr[i];
            res = i;
        }
    }
    return res;
}

int main()
{
    //Max Occuring 
    int L[] = {1,2,3}, R[] = {3,5,7}, n = 3;
    cout  << "Max Occuring element in given ranges: " << maxOcc(L, R, n) << endl;

    //if Equilibrium pt. exists
    int arr[] = {3,4,8,-9,20,6}; n = 6;
    cout << "Equilibrium pt. exists [naive]    : " << boolalpha << naive_isEqui(arr, n) << endl;
    cout << "Equilibrium pt. exists [efficient]: " << boolalpha << isEqui(arr, n) << endl;

    //Getting sum of an array from  index l to index r
    int arr2[] = {3,4,8,-9,20,6}; n = 6;
    int l = 4;
    int r = 5;
    cout << "Sum of given subarray [naive]    : " << naive_getSum(l, r, arr2) << endl;

    //Converting array to prefix sum array
    for (int  i = 1; i < n; ++i)    arr2[i] += arr2[i-1];
    cout << "Sum of given subarray [efficient]: " << getSum(l, r, arr2);
    
    return 0;
}

