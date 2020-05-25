//This program swaps odd and even bits of a number
#include <iostream>
using namespace std;

int swapBits(unsigned int n)
{
    //For 32 bit integers only
    int all_even_set = 0xAAAAAAAA;
    int all_odd_set = 0x55555555;

    return ((n & all_even_set) >> 1) | ((n & all_odd_set) << 1);
}

int main()
{
    unsigned int N;
    cin >> N;
    cout << swapBits(N);
    return 0;
}