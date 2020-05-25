
//Program to find if kth bit of a number n from right is set or equals 1

#include <iostream>
using namespace std;

void isKth_bit_set_v1(int n, int k)
{
    //Using right shift
    if (1 & (n >> k - 1))   cout << "SET";
    else    cout << "NOT SET";
}

void isKth_bit_set_v2(int n, int k)
{
    //Using left shift
    if (n & (1 << k - 1))   cout << "SET";
    else    cout << "NOT SET";
}

int main()
{
    unsigned int N, k;
    cout << "Program to find if a k-th bit of number N is set" << endl;
    cout << "Input N: "; cin >> N;
    cout << "Input k: "; cin >> k;

    if (k > 8 * sizeof(N))
    {
        cout << "k out of range";
        return -1;
    }

    cout << "Using right shift: "; isKth_bit_set_v1(N, k); cout << endl;
    cout << "Using left  shift: "; isKth_bit_set_v2(N, k); cout << endl;


    return 0;
}
