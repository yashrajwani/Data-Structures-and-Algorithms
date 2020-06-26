#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //Using binary_search on vectors
    vector <int> vec = {10,15,20,30,35,40,45,50};
    if (binary_search(vec.begin(), vec.end(), 15))      cout << "15 exists in vector\n";
    else    cout << "15 doesn't exist in vector\n";
    
    //Using binary search on arrays
    int arr[] = {10,15,20,30,35,40,45,50};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (binary_search(arr, arr+n, 150))      cout << "150 exists in array\n";
    else    cout << "150 doesn't exist in array\n";

    return 0;
}