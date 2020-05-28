#include <iostream>
using namespace std;

int jos(int n, int k)
{
    if (n == 1)     return 0;

    /*Add k to recursive output bcoz positions are shifted by k in recursive calls
    modulo n bcoz out must be in [0, n-1]  */
    return (jos(n - 1, k) + k) % n;     
}

int jos_one_indexed(int N, int k)
{
    return 1 + jos(N, k);
}

int main()
{
    int N, k;
    cout << "Josephus Problem\n\nN, k = "; cin >> N >> k; cout << endl;
    cout << "Survivor index[0 indexing] = "<< jos(N, k);
    cout << "Survivor index[1 indexing] = "<< jos_one_indexed(N, k);
    
    return 0;
}
