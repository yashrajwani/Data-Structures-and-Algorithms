#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void showList(list <int> g)
{
    list <int> :: iterator iter;
    for (iter = g.begin(); iter != g.end(); ++iter)
        cout << "\t" << *iter;
    cout << endl;
}

int main()
{
    list <int> l1, l2;

    for (int i =0; i < 10; ++i)
    {
        l1.push_back(i * 9);
        l2.push_front(i * 2);
    }
    cout << "\n List 1 ";
    showList(l1);
    
    cout << "\n List 2 ";
    showList(l2);

    cout << "\nlist1 front: " << l1.front();
    cout << "\nlist1 back: " << l1.back();

    cout << "\nlist2 front: " << l2.front();
    cout << "\nlist2 back: " << l2.back();

    l1.pop_front();
    cout << "\nList1 popFront: "; showList(l1);

    l2.pop_back();
    cout << "\nList1 popBack: "; showList(l2);

    l1.reverse();
    cout << "\nReverse List1: "; showList(l1);

    l2.sort();
    cout << "\nSorted List2: "; showList(l2);
    
    
    return 0;
}