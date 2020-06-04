//max value of arr[j] - arr[i] such that j > i

#include <iostream>
using namespace std;

int naive_max_diff(int arr[], int n)
{
    //time -> theta(n^2)
    //aux space -> theta(1)

    if (n == 1)     return 0;
    int res = arr[1] - arr[0];

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            res = max(res, arr[j] - arr[i]);

    return res;
}

int max_diff(int arr[], int n)
{
    //time -> theta(n)
    //aux space -> theta(1)

    int minVal = arr[0];
    int res = arr[1] - arr[0];

    for (int i = 1; i < n; ++i)
    {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
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
    int numTests = 3;
    int n = 7;
    int test_arrays[3][7] = {
                            {2,3,10,6,4,8,1},
                            {10,20,30,40,50,60,70},
                            {70,60,50,40,10,8,2},
                            };

    cout << "Max difference\nmax value of arr[j] - arr[i] such that j > i\n\n";
    for (int i = 0; i < numTests; ++i)
    {
        cout << "original array: "; print_arr(test_arrays[i], n);
        cout << "max difference[naive]    : " << naive_max_diff(test_arrays[i], n);
        cout << "\nmax difference[efficient]: " << max_diff(test_arrays[i], n);
        cout << endl << endl;
    }
    return 0;
}
