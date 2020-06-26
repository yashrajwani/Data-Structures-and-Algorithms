#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    //Using upper_bound() and lower_bound() with vectors
    vector <int> v {10,20,30,40,50,60,70,80};
    
    //print vector
    cout << "Vector contains: ";
    for (int i = 0; i < v.size(); ++i)  cout << v[i] << " ";
    cout << endl;

    vector <int> :: iterator upper1, upper2;
    upper1 = upper_bound(v.begin(), v.end(), 35);
    upper2 = upper_bound(v.begin(), v.end(), 45);
    
    cout << "upper bound for 35 is at position " << upper1 - v.begin() << endl;
    cout << "upper bound for 45 is at position " << upper2 - v.begin() << endl;

    vector <int> :: iterator low1, low2;
    low1 = lower_bound(v.begin(), v.end(), 35);
    low2 = lower_bound(v.begin(), v.end(), 45);
    
    cout << "lower bound for 35 is at position " << low1 - v.begin() << endl;
    cout << "lower bound for 45 is at position " << low2 - v.begin() << endl;
    
    cout << endl;

    //Using upper_bound() and lower_bound() with arrays
    int arr[] = {10,20,30,40,50,60,70,80};
    int n = sizeof(arr) / sizeof(arr[0]);
    //print array
    cout << "Array contains: ";
    for (int i = 0; i < n; ++i)  cout << arr[i] << " ";
    cout << endl;

    int *up1 = upper_bound(arr, arr + n, 35);
    int *up2 = upper_bound(arr, arr + n, 45);
    
    cout << "upper bound for 35 is at position " << up1 - arr << endl;
    cout << "upper bound for 45 is at position " << up2 - arr << endl;

    int *l1 = lower_bound(arr, arr + n, 35);
    int *l2 = lower_bound(arr, arr + n, 55);
    
    cout << "lower bound for 35 is at position " << l1 - arr << endl;
    cout << "lower bound for 55 is at position " << l2 - arr << endl;

    return 0;
}