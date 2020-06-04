#include <iostream>
using namespace std;

void naive_leader(int arr[], int n)
{
    //time-> theta(n^2)
    //aux space -> theta(1)

    for (int i = 0; i < n; ++i)
    {
        bool flag = false;
        for (int j = i; j < n; ++j)
            if (arr[j] > arr[i])    flag = true;
        
        if (flag == false)  cout << arr[i] << " ";
    }
    cout << endl;
}

void leader(int arr[], int n)
{
    //time-> theta(n)
    //aux space -> theta(1)

    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";    //rightmost element in an array is always a leader

    for (int i = n - 2; i >= 0; --i)
    {
        if (arr[i] > curr_ldr)
        {
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
    cout << endl;
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n = 7;
    int arr1[] = {7,6,5,4,3,2,1};
    int arr2[] = {1,2,3,4,5,6,7};
    int arr3[] = {7,10,4,3,6,5,2};

    cout << "Array leaders\n\n";

    cout << "array: "; print_arr(arr1, n);
    cout << "leaders[naive]:     "; naive_leader(arr1, n);
    cout << "leaders[efficient]: "; leader(arr1, n);
    cout << endl;

    cout << "array: "; print_arr(arr2, n);
    cout << "leaders[naive]:     "; naive_leader(arr2, n);
    cout << "leaders[efficient]: "; leader(arr2, n);
    cout << endl;

    cout << "array: "; print_arr(arr3, n);
    cout << "leaders[naive]:     "; naive_leader(arr3, n);
    cout << "leaders[efficient]: "; leader(arr3, n);
    cout << endl;
    


    return 0;
}