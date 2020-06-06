#include <iostream>
using namespace std;

int naive_maxOnes(int arr[], int n)
{
    //theta n^2 time complexity
    //theta 1 aux space

    int res = 0;
    for (int i=0; i < n; ++i)  
    {
        int curr = 0;
        for (int j = i; i < n; ++j)
        {
            if (arr[j] == 0)  break;
            curr++;
        }
        res = max(curr, res);
    }
    return res;
}

int maxOnes(int arr[], int n)
{
    //theta n time complexity
    //theta 1 aux space

    int res = 0, curr = 0;
    for (int i=0; i < n; ++i)  
    {
        if (arr[i] == 0)    curr = 0;
        else
        {
            ++curr;
            res = max(curr, res);
        } 
    }
    return res;
}

int main()
{
    int arr[] = {1, 0, 1, 0, 1, 1, 1, 1, 0};
    int n = 9;

    cout << "Consecutive ones [naive]    : " << naive_maxOnes(arr, n) << endl;
    cout << "Consecutive ones [efficient]: " << maxOnes(arr, n);
    
    return 0;
}