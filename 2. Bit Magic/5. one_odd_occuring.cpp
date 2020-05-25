//Returns odd occuring number in an array
#include <iostream>
using namespace std;

int naive_oddOccuring(int arr[], int n)
{
    int count;
    for (int i = 0; i < n; ++i)
    {
        count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] == arr[j])   ++count;
        }
        if (count % 2 != 0)     return arr[i];
    }
}

int xor_oddOccuring(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = res ^ arr[i];

    return res;
}

int main()
{
    int N;
    do
    {
        cout << "Array Size[must be odd]: "; cin >> N;
    }
    while (N % 2 == 0);

    int arr[N];
    cout << "Enter array elements separated by space.\n";
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << "Odd Occuring element[naive]: " << naive_oddOccuring(arr, N) << endl;
    cout << "Odd Occuring element[ XOR ]: " << xor_oddOccuring(arr, N) << endl;

}
