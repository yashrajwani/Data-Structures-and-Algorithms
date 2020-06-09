#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr = {1,2,3,4,5};
    vector <int> :: iterator ptr = arr.begin();

    //Using advance to increment iterator position
    advance(ptr, 3);
    cout << "Position of iterator after advancing : " << *ptr << endl;

    //Using next() to return new iterator
    ptr = arr.begin();
    auto it = next(ptr, 3);
    cout << "\nThe position of new iterator using next() is : ";
    cout << *it  << endl;

    //Using prev() to return new iterator
    ptr = arr.end();
    auto it1 = prev(ptr, 3);
    cout << "The position of new iterator using prev() is : ";
    cout << *it1 << endl;

    vector <int> arr1 = {10,20,30};
    ptr = next(arr.begin(), 3);
    //copying one vector elements into other suing inserter()
    //inserts arr1 from third position into arr
    copy(arr1.begin(), arr1.end(), inserter(arr, ptr));

    cout << "\nNew vector after inserting new elements:\n";
    for (int &x : arr)
        cout << x << " ";

    return 0;
}