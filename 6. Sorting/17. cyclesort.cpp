#include <iostream>
using namespace std;

void distinctCycleSort (int arr[], int n)
{
    for (int cs = 0; cs < n-1; ++cs)
    {
        int item = arr[cs];
        int pos = cs;

        for (int i = cs+1; i < n; ++i)  
            if (arr[i] < item)  ++pos;

        swap (arr[pos], item);
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs+1; i < n; ++i)  
                if (arr[i] < item)  ++pos;
            swap (arr[pos], item);
        }
    }
}

int main()
{
    int arr[] = {5,9,8,7,4,6,3,2,1};
    distinctCycleSort(arr, sizeof(arr)/sizeof(arr[0]));
    for (auto x : arr)  cout << x << " ";
    return 0;
}