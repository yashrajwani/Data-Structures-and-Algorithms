#include <iostream>
using namespace std;

bool isPalindrome(string str, int s = 0, int e = -1)
{   
    if (e < 0)      e = str.length() - 1; //Initialize e once during 1st call
    if ((s == e) || (s > e))    return true;
    if (str[s] != str[e])       return false;
    
    return isPalindrome(str, s + 1, e - 1);
}

int main()
{
    string s;
    cout << "Input string:" ; cin >> s;
    cout << "isPalindrome: "; cout << boolalpha << isPalindrome(s);
    return 0;
}