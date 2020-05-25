//This programs uses Sieve of Erathosthenes to find primes up N
#include <iostream>
#include <cstring>
using namespace std;

void primes_upto(int N)
{
    //Initializing array
    bool sieve[N + 1];
    memset(sieve, true, sizeof(sieve));

    //Sieveing out multiples
    for (int i = 2; i*i <= N; ++i)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    //Printing primes
    for (int i = 2; i <= N; ++i)
    {
        if (sieve[i])
            cout << i << " ";
    }
}

int main()
{
    int N;
    cout << "Find prime numbers upto: ";
    cin >> N;

    cout << "Primes below " << N << " are:" << endl;
    primes_upto(N);

    return 0;
}
