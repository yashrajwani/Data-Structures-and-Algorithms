//Returns two odd occuring numbers in an array
#include <iostream>
using namespace std;

void naive_oddOccuring(int arr[], int n)
{
    int count;
    for (int i = 0; i < n; ++i)
    {
        count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] == arr[j])   ++count;
        }
        if (count % 2 != 0)     cout << arr[i] << " ";
    }
}

void xor_twoOddOccuring(int arr[], int n)
{
    int res1 = 0, res2 = 0, xor_ = 0, rightmost_bit;
    for (int i = 0; i < n; ++i)
        xor_ = xor_ ^ arr[i];

    rightmost_bit = xor_ & ~(xor_ - 1);   //Find rightmost bit
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] & rightmost_bit)  res1 = res1 ^ arr[i];   //xor value of grp1
        else    res2 = res2 ^ arr[i];          //xor value of grp2
    }
    cout << res1 << " " << res2;
}
int main()
{
    int N;
    do
    {
        cout << "Array Size: "; cin >> N;
    }
    while (N < 2);

    int arr[N];
    cout << "Enter array elements separated by space.\n";
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << "Odd Occuring element[naive]: "; naive_oddOccuring(arr, N); cout << endl;
    cout << "Odd Occuring element[ XOR ]: "; xor_twoOddOccuring(arr, N); cout << endl;

}
