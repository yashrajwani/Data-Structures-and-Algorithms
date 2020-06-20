#include <iostream> 
using namespace std;

int sqrtFloor(int x)
{
    int low = 1, high = x, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sqr = mid*mid;

        if (sqr == x)   return mid;
        else if (sqr > x)   high = mid - 1;
        else
        {
            low = mid + 1;
            res = mid;
        }
    }
    return res;
}

int main()
{
    int x = 10000;
    cout << sqrtFloor(x);
    return 0;
}