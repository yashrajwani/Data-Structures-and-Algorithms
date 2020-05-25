//Program returns true if input number is a power of 2
#include <iostream>
using namespace std;

bool naive_powerOf2(int N)
{
    while (N != 1)
    {
        if (N % 2 == 1) return false;
        N /= 2;
    }
    return true;
}

bool brianKerningham_powerOf2(int N)
{
    return (N & (N - 1)) == 0;
}

int main()
{
    int N;
    cout << "Enter N: "; cin >> N;
    cout << N << " is power of 2[naive algo]: " << boolalpha << naive_powerOf2(N) << endl;
    cout << N << " is power of 2[Brian Kerningham condition]: " << boolalpha << brianKerningham_powerOf2(N) << endl;
    
}