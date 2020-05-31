#include <iostream>
using namespace std;

int remove_dup(int arr[], int n)
{
    //removes duplicates from a sorted array
    //returns index upto which array has unique elements 
    int res = 1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[res - 1] == arr[i])     continue;
        arr[res] = arr[i];
        ++res;
    }
    return res;
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n = 10;
    int arr[n] = {0,0,0,0, 10, 10, 10, 100, 1000, 10000};
    cout << "original array:            "; print_arr(arr, n);
    n = remove_dup(arr, n);
    cout << "after removing duplicates: "; print_arr(arr, n);
    

    return 0;
}