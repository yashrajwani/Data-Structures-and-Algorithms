#include <iostream>
using namespace std;

int naive_getWater(int arr[], int n)
{
    //theta n^2 time complexity
    //theta 1 aux space

    int res = 0;
    for (int i=1; i< n-1; ++i)  //bars at end can't have water on them
    {
        int lmax = arr[i];
        for (int j = 0; j < i; ++j)
            lmax = max(lmax, arr[j]);

        int rmax = arr[i];
        for (int j = i+1; j < n; ++j)
            rmax = max(rmax, arr[j]);

        //Water stored on i-th bar
        res += min(rmax, lmax) - arr[i];
    }
    return res;
}

int getWater(int arr[], int n)
{
    //theta n time complexity
    //theta n aux space

    int lmax[n], rmax[n];
    int res = 0;

    lmax[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
        lmax[i] = max(arr[i], lmax[i-1]);
    }

    rmax[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; --i)
    {
        rmax[i] = max(arr[i], rmax[i+1]);
    }

    for (int i = 1; i < n; ++i)
    {
        res += min(lmax[i], rmax[i]) - arr[i];
    }

    return res;
}

int main()
{
    int arr[] = {5,0,6,2,3};
    int n = 5;

    cout << "Rainwater [naive]    : " << naive_getWater(arr, n);
    cout << "Rainwater [efficient]: " << getWater(arr, n);
    
    return 0;
}