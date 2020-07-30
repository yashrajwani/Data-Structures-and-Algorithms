#include <iostream>
#include <unordered_map>
using namespace std;

//prints elements with over n/k occurences
int printNbyK (int arr[], int n, int k)
{
    //O(nk) Time Complexity
    //O(k) Aux Space
    unordered_map <int, int> m;
    for (int i = 0; i < n; ++i)
    {
        //Step1: Candidate Selection
        if (m.find(arr[i]) != m.end())      m[arr[i]]++;        //element in hash map incerement count
        else if (m.size() < k)      m[arr[i]]++;                //new element and map size < k because 
                                                                //in an arr of size n there can be maximum k-1 elemets 
                                                                //that have over n/k occurence
        else
            for (auto x : m)
            {
                x.second--;
                if (!x.second)  m.erase(x.first);
            }
    }
    
    //Step2: Candidate Verification
    for (auto x : m)
        if (x.second > n/k)     cout << x.first << " ";
    cout << endl;
}

//If there are no space constarints
int printNbyK_2 (int arr[], int n, int k)
{
    //O(n) Time Complexity
    //O(n) Aux Space
    unordered_map <int, int> m;
    for (int i = 0; i < n; ++i)     m[arr[i]]++;
    
    for (auto x : m)
        if (x.second > n/k)     cout << x.first << " ";
    cout << endl;
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,2,3,4,5,6,9,9,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 8, k2 = 4;

    cout << "Elements with over " << n/k1 << "occurences: "; printNbyK(arr, n, k1);     //Elements with over 2 occurences: 2 9 
    cout << "Elements with over " << n/k2 << "occurences: "; printNbyK_2(arr, n, k2);   //Elements with over 4 occurences: 9 
     
    return 0;
}