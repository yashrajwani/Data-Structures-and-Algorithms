#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    // uses linear search to find element 'x' 
    //returns idx if element is present else returns -1
    for (int i = 0; i < n; ++i)
        if (arr[i] == x)    return i;

    return -1;
}

int insert(int arr[], int n, int cap, int x, int idx)
{
    //inserts element 'x' at index 'idx' of an array 'arr'
    //which has capcity 'cap' and is 'n' elements filled
    //returns new size of array

    if (n == cap)   return n;
    
    for (int i = n - 1; i >= idx; --i)
        arr[i + 1] = arr[i];
    arr[idx] = x;
    return (n + 1);
}

int _delete(int arr[], int n, int x)
{
    //deletes element x if it is present
    //returns new size of array

    int i;
    for (i = 0; i < n; ++i)
        if (arr[i] == x)    break;

    if (i == n)     return n;
    for (int j = i; j < n - 1; ++j)
        arr[j] = arr[j + 1];
    return (n - 1);
}

void reverse(int arr[], int n)
{
    int low = 0, high = n - 1;
    while(low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        ++low; --high;
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5};
    int cap = 6, n = 5;

    cout << "original array: "; print_arr(arr, n);

    cout << "delete element 1: ";
    n = _delete(arr, n, 1);
    print_arr(arr, n);

    cout << "insert element 11 at index 0: ";
    n = insert(arr, n, cap, 11, 0);
    print_arr(arr, n);

    cout << "search index of 11: " << search(arr, n, 11) << endl;

    cout << "reversed array: ";
    reverse(arr, n);
    print_arr(arr, n);

    return 0;
}

