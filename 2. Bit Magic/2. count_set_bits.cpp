//Program to count set bits of a given number
#include <iostream>

using namespace std;

int naive_countBits(int N)
{
    int count = 0;
    while (N)
    {
        count += 1 & N;
        N = N >> 1;
        //cout << N << " ";
    }
    return count;
}

int brian_kerningham_countBits(int N)
{
    int count = 0;
    while (N)
    {
        N = N & (N - 1); //eliminate rightmost bit
        ++count;
    }
    return count;
}

void initialize_table(int table[])
{
    table[0] = 0;
    for (int i = 1; i < 256; ++i)
    {
        table[i] = table[i / 2] + (i & 1);
    }
}
int lookupTable_countBits(int N, int table[])
{
    int result = 0;
    while (N)
    {
        result += table[N & 0xff];  //reduce N to [0, 255]
        N = N >> 8;
    }
    return result;
}
int main()
{
    unsigned int N;

    int table[256];
    initialize_table(table);

    cout << "Input N: "; cin >> N;
    cout << "[Naive algo]Total Set Bits: " << naive_countBits(N) << endl;
    cout << "[Brian Kerningham algo]Total Set Bits: " << brian_kerningham_countBits(N) << endl;
    cout << "[Lookup table]Total Set Bits: " << lookupTable_countBits(N, table) << endl;

}
