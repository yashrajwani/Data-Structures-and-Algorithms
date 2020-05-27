#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)     return 1;
    return n * factorial(n - 1);
}

int tail_recursive_fact(int n, int res = 1)
{
    if (n == 0)     return res;
    return tail_recursive_fact(n - 1, res * n);
}

int main()
{
    int n;
    cout << "Find factorial of N = "; cin >> n;
    cout << n << "! = " << factorial(n) << endl;
    cout << n << "! = " << tail_recursive_fact(n) << endl;
    return 0;
}