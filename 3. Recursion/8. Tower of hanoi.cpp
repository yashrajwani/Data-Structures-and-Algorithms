#include <iostream>
using namespace std;

void TOH(int n, char A = 'A', char B = 'B', char C = 'C')
{
    if (n == 1)
    {
        cout << "Move disc 1 from " << A << " to " << C << endl;
        return;
    }

    TOH(n-1, A, C, B);
    cout << "Move disc " << n << " from " << A << " to " << C << endl; 
    TOH(n-1, B, A, C);
    return;
}
int main()
{
    int N;
    cout << "Tower of Hanoi\n\nNumber of discs = "; cin >> N; cout << endl;
    TOH(N);
    return 0;
}
