//prints power set of a string considered every character as an individual element
//input -> "ab"
//o/p -> "" "a" "b" "ab"
#include <iostream>
#include <cmath>
using namespace std;

void printPowSet(string str)
{
    int n = str.length();
    int powSetSize = pow(2, n);

    for (int ctr = 0; ctr < powSetSize; ++ctr)
    {
        for (int i = 0; i < n; ++i)
        {
            if (ctr & (1 << i))   cout << str[i];
        }
        cout << endl;
    }
}

int main()
{
    string str;
    cout << "Input set without spaces[each character would be considered an individual element]" << endl;
    cin >> str;
    printPowSet(str);
}