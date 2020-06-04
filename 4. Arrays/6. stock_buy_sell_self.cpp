#include <iostream>
using namespace std;

bool is_localmin(int arr[], int n, int idx)
{
    int left = idx - 1, right = idx + 1;
    if (left < 0)   left = right;
    else if (right >= n)     right = left;
    
    if (arr[idx] <= arr[left] && arr[idx] < arr[right] && idx != n-1)    return true;
    return false;
}
bool is_localmax(int arr[], int n, int idx)
{
    int left = idx - 1, right = idx + 1;
    if (left < 0)   left = right;
    if (right >= n)     right = left;
    
    if (arr[idx] >= arr[left] && arr[idx] > arr[right])    return true;
    return false;
}

int stockBuySell(int arr[], int n)
{
    bool bought = false;
    int buy = -1, sell = -1, profit = 0;
    
    for (int i = 0; i < n; ++i)
    {
       if (is_localmin(arr, n, i) and !bought)
       {
           //cout << "Buy at " << arr[i] << endl;
           bought = true;
           buy = i;
           cout << "(" << buy;
       }
       else if (is_localmax(arr, n, i) and bought)
       {
           //cout << "Sell at " << arr[i] << endl;
           bought = false;
           sell = i;
           cout << " " << sell <<") ";
           profit += arr[sell] - arr[buy];
       }
    }
    if (buy == sell)  cout << "No Profit";
    return profit;
}

int main()
{
  int arr[] = {1,5,3,8,12};
  int n = 5;
  int max_profit = stockBuySell(arr, n);
  cout << "\nMax profit: " << max_profit;
  
  return 0;
}
