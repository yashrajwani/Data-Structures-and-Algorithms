// rod cutting
// Given a rope of length "n". Find max number of pieces such that every piece is of length in set {a, b, c}
// For given values of a, b, c
// Returns -1 if not possible
#include <iostream>
using namespace std;

int max_pieces(int n, int a, int b, int c)
{
    if (n == 0)     return 0;
    if (n < 0)      return -1;

    int res = max(max(max_pieces(n - a, a, b, c), max_pieces(n - b, a, b, c)), max_pieces(n - c, a, b, c));

    if (res == -1)   return -1;
    return 1 + res;
}



int main()
{
    int n, a, b, c;
    cout << "Input values of n, a, b, c [separated by spaces]\n";
    cin >> n >> a >> b >> c;
    cout << "Maximum no. of pieces: " << max_pieces(n, a, b, c);
    return 0;
}