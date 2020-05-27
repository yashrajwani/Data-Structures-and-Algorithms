// prints all subsequences of a string
#include <iostream>
using namespace std;

void printAllSubsets(string str, int idx = 0, string curr = "")
{
    if (idx == str.length())
    {
        cout << curr << " " ;
        return;
    }
    printAllSubsets(str, idx + 1, curr);
    printAllSubsets(str, idx + 1, curr + str[idx]);
}



int main()
{
    string str;
    cout << "Input set without spaces[each character would be considered an individual element]" << endl;
    cin >> str;
    printAllSubsets(str);
}