#include <iostream>
using namespace std;

void print_from(int n, bool reverse)
{
    if (n == 0)     return;
    if (reverse)    cout << n << " ";
    print_from(n - 1, reverse);
    if (!reverse)   cout << n << " ";
}

int main()
{
    int n; bool rev;
    cout << "Print from N = "; cin >> n;
    cout << "Reverse:" ; cin >> rev;
    print_from(n, rev);
    return 0;
}