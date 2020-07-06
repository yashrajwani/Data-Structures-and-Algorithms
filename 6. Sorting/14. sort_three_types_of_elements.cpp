//sorting a array with three types of elements in O(n) time complexity

//can be modified for
//three way partitioning when multiple occurences of pivot may exist
//partitioning around a range

#include <iostream>
using namespace std;

void sort (int arr[], int n)
{
    //Dutch national flag algorithm
    int lo = 0, mid = 0, hi = n-1;
    while (mid <= hi)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[mid++], arr[lo++]);
            break;
        
        case 1:
            ++mid;
            break;

        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }
}

int main()
{
    int arr[] = {1,0,1,0,1,0,2,0,1,2,0,0,2,2,2,2,2,2,2,1,0,1,0,1,1,1,0};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n1);
    for (auto x : arr)  cout << x << " ";       //0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2  
    return 0;
}
