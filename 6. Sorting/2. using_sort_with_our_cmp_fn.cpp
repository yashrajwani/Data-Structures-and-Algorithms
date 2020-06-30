#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool myCmp(Point p1, Point p2)
{
    return (p1.x < p2.x);
}

int main()
{
    Point arr[] = {{4,6},{8,4},{3,56}, {3,5},{9,4}};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, myCmp);
    for (auto p : arr)  cout << p.x << " " << p.y << endl;
    return 0;
}