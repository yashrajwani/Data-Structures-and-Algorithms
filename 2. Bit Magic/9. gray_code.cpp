#include <iostream>
using namespace std;

int bin_to_gray(unsigned int N)
{
    return N ^ (N >> 1);
}

int gray_to_bin(unsigned int N)
{
    int b = 0;
    while(N)
    {
        b ^= N;
        N >>= 1;
    }
    return b;
}

int main()
{
    unsigned int N;
    cin >> N;

    cout << "N is " << gray_to_bin(bin_to_gray(N));

    return 0;
}