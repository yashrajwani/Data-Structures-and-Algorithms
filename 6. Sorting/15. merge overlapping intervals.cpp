#include <iostream>
#include <algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
};

bool cmpStart (Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mergeIntervals (Interval arr[], int n)
{
    sort (arr, arr+n, cmpStart);
    int res = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[res].end >= arr[i].start)
        {
            arr[res].start = min(arr[res].start, arr[i].start);
            arr[res].end = max(arr[res].end, arr[i].end);
        }
        else    arr[++res] = arr[i];
    }

    for (int i = 0; i <= res; ++i)
        cout << "{"<< arr[i].start << ", " << arr[i].end << "} ";
    cout << endl;
}

int main()
{
    Interval arr1[] = {{5,10}, {3,15}, {18,30}, {2,7}},
             arr2[] = {{7,9}, {6,10}, {4,5}, {1,3}, {2,4}};
    int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeIntervals(arr1, n1);       //{2, 15} {18, 30} 
    mergeIntervals(arr2, n2);       //{1, 5} {6, 10}

    return 0;
}


