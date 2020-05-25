//This programs uses Sieve of Erathosthenes to find primes up N
#include <iostream>
using namespace std;

int HCF(int a, int b)
{
    //Euclidean algorithms for HCF
    if (a == 0)
        return b;

    return HCF(b % a, a);
}

int LCM (int a, int b)
{
    return a * b / HCF(a, b);
}

int main()
{
    int N1, N2;
    cout << "LCM and HCF\nEnter Number 1: ";
    cin >> N1;
    cout << "Enter Number 2: ";
    cin >> N2;

    cout << "LCM : " << LCM(N1, N2) << endl;
    cout << "HCF : " << HCF(N1, N2);

    return 0;
}
