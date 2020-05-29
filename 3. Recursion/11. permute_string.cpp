#include <iostream>
using namespace std;

void permute(string &str, int l = 0)
{
    int r = str.length() - 1;
    if(l == r)
    {
        cout << str << " ";
        return;
    }
    
    for (int i = l; i <= r; ++i)
    {
        swap(str[i], str[l]);
        permute(str, l + 1);
        swap(str[i], str[l]);
    }
}

int main()
{
    string str;
    cin >> str;
    permute(str);
    return 0;
}