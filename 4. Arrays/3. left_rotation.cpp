#include <iostream>
using namespace std;

void left_rotate_by_one(int arr[], int n)
{
    //left roates array by one position
    int temp = arr[0];
    for (int i = 1; i < n; ++i)
        arr[i - 1] = arr[i];
    arr[n - 1] = temp;
}

void left_rotate_v1(int arr[], int n, int d)
{
    //left rotates array by "d" positions
    //time -> theta(n*d)
    //space -> theta(1)

    for (int i = 0; i < d; ++i)
        left_rotate_by_one(arr, n);
}

void left_rotate_v2(int arr[], int n, int d)
{
    //left rotates array by "d" positions
    //time -> theta(n)
    //space -> theta(d)
    int temp[d];
    for (int i = 0; i < d; ++i)
        temp[i] = arr[i];
    
    for (int i = d; i < n; ++i)
        arr[i - d] = arr[i];
    
    for (int i = 0; i < d; ++i)
        arr[n - d + i] = temp[i];
}

void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        ++low; --high;
    }
}

void left_rotate_v3(int arr[], int n, int d)
{
    //left rotates array by "d" positions
    //time -> theta(n)
    //space -> theta(1)

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7}, n = 7, d = 2;
    cout << "Original array: "; print_arr(arr, n); 
    cout << endl;
    
    left_rotate_v1(arr, n, d);
    cout << "[v1]Left rotated by " << d << ":   "; print_arr(arr, n);
    left_rotate_v2(arr, n, d);
    cout << "[v2]Left rotated by " << d << ":   "; print_arr(arr, n);
    left_rotate_v3(arr, n, d);
    cout << "[v3]Left rotated by " << d << ":   "; print_arr(arr, n);

    return 0;
}