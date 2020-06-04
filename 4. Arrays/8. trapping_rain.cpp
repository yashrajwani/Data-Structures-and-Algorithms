#include <iostream>
using namespace std;


int rainwater(int arr[], int n)
{
    //time-> theta(n)
    //aux space -> theta(1)

    int left = 0, right = n - 1;
    int ctr = left + 1;
    while (arr[ctr] > arr[left])    //find local max from left
    {
        left = ctr++;   
    }
    
    ctr = right - 1;
    while (arr[ctr] > arr[right])   //find local max from right
    {
        right = ctr--;
    }
    
    int volume = (right - left - 1) * min(arr[right], arr[left]);
    if (volume <= 0)    return 0;
    
    for (int i = left + 1; i < right; ++i)
        volume -= min(arr[i], min(arr[right], arr[left]));
    
    return volume;
}

