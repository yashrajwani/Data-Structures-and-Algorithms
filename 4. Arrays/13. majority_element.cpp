//majority element -> element that occurs more than n/2 times in an array of size n

#include <iostream>
using namespace std;

int naive_majorityElement(int arr[], int n)
{
    //Theta n^2 time complexity
    //Theta 1 aux space

    for (int i = 0; i < n; ++i)
    {
        int count = 0;
       for (int j = i; j < n; ++j)
       {
           if (arr[j] == arr[i])      ++count;
       }
       if (count > n / 2)   return i;
    }
}

int majorityElement(int arr[], int n)
{
    //Moore's Voting Algorithm
    //Theta n time complexity
    //Theta 1 aux space
    
    //Finding candidate
    int res = 0, count = 1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[res])     ++count;
        else    --count;

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    //Verifying candidate
    count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[res] == arr[i])     ++count;

    if (count <= n / 2)     return -1;
    
    return res;
}

int main()
{
  int arr[] = {3,3,4,4,5,4,4,4};
  int n = 8;
  cout << "majority element index [naive]    : " << naive_majorityElement(arr, n) << endl;
  cout << "majority element index [efficient]: " << naive_majorityElement(arr, n);
}