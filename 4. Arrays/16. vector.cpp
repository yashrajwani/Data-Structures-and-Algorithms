#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;

    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    cout << "Size: " << v.size();

    (v.empty()) ? (cout << "\nEmpty") : (cout << "\nNot Empty");

    cout << "\nVector elements:\n";
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << " " << *i;
    cout << endl;

    v.emplace(v.begin(), 10000);
    cout << "\nFirst Element: " << v[0];

    v.emplace_back(20);
    cout << "\nLast Element: " << v[v.size() - 1];

    v.clear();
    cout << "\nafter clearing v.size() is " << v.size();

    return 0;
}