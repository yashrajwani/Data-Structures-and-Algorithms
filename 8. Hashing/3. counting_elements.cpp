#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//count idstinct elements in an array of size n
int countDistinct (int arr[], int n)
{
    unordered_set <int> s;
    for (int i = 0; i < n; ++i)     s.insert(arr[i]);
    return s.size();
}

//count frequency of array elements
void countFrequency (int arr[], int n)
{
    unordered_map <int, int> m;
    for (int i = 0; i < n; ++i)     m[arr[i]]++;
    for (auto x : m)     cout << x.first << " occurs " << x.second << "times.\n";
}

int main ()
{
    int arr[] = {0,0,0,0,1,1,1,2,3,2,3,2,3,2,3};
    int n=  sizeof(arr) / sizeof(arr[0]);
    cout << "Distinct elements in array: " << countDistinct(arr, n) << endl;
    countFrequency(arr, n);
    return 0;
}
