#include <iostream>
#include <unordered_set>
using namespace std;

//returns if theres exists a pair with given sum
bool isPair (int arr[], int n, int sum)
{
    unordered_set <int> s;
    for (int i = 0; i < n; ++i)
    {
        if (s.find(sum - arr[i]) != s.end())    return true;
        s.insert(arr[i]);
    }
    return false;
}


int main ()
{
    int arr1[] = {1,2,3,5,4,6,7,8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Pair with sum 9 = " << boolalpha << isPair(arr1, n1, 9) << endl;
    cout << "Pair with sum 0 = " << boolalpha << isPair(arr1, n1, 0) << endl;
    
    return 0;
}
