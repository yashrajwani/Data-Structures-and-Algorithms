#include <iostream>
using namespace std;

int naive_maxEvenOdd(int arr[], int n)
{
    //theta n^2 time complexity
    //theta 1 aux space

    int res = 1, curr = 1;
    for (int i =0; i < n; ++i)
    {
        curr = 1;
        for (int j = i+1; j < n; ++j)
        {
            //Even+Even = Even
            //Odd+Odd = Even
            //Even+Odd = Odd    ----> This condition gives us if two numbers are alternate EvenOdd
            if (((arr[j-1] + arr[j]) % 2) != 0)    ++curr;
            else break;
        }
        res = max(res, curr);
    }
    return res;
}

int maxEvenOdd(int arr[], int n)
{
    //theta n time complexity
    //theta 1 aux space

    int res = 1, curr = 1;
    for (int i = 1; i < n; ++i)  
    {
        if ((arr[i-1] + arr[i]) % 2 != 0)
        {
            ++curr;
            res = max(res, curr);
        }
        else    curr = 1;
    }
    return res;
}

int main()
{
    int arr[] = {1,2,3,4,5,5,4,3,2,1,0};
    int n = 11;

    cout << "Max length odd even seq [naive]    : " << naive_maxEvenOdd(arr, n) << endl;
    cout << "Max length odd even seq [efficient]: " << maxEvenOdd(arr, n);
    
    return 0;
}