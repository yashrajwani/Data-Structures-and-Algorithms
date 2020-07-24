#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//intersection of two arrays
void intersection (int arr1[], int arr2[], int n1, int n2)
{
    unordered_set <int> s;
    for (int i = 0; i < n1; ++i)     s.insert(arr1[i]);
    for (int i = 0; i < n2; ++i)    
        if (s.find(arr2[i]) != s.end())   cout << arr2[i] << " ";
    cout << endl;
}

//union of two arrays
void union_ (int arr1[], int arr2[], int n1, int n2)
{
    unordered_set <int> s;
    for (int i = 0; i < n1; ++i)     s.insert(arr1[i]);
    for (int i = 0; i < n2; ++i)     s.insert(arr2[i]);
    for (auto x : s)    cout << x << " ";
    cout << endl;   
}



int main ()
{
    int arr1[] = {1,2,3,5,4,6,7,8}, arr2[] = {9,8,7,6,5,4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Union of arrays: "; union_(arr1, arr2, n1, n2);
    cout << "Intersection of arrays: "; intersection(arr1, arr2, n1, n2);
    
    return 0;
}


// Union of arrays: 9 8 7 6 4 5 3 2 1 
// Intersection of arrays: 8 7 6 5 4 