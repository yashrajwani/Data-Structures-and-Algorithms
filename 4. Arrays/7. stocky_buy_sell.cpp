#include <iostream>
using namespace std;

int naive_stockBuySell(int price[], int n, int start, int end)
{
    if (end <= start)   return 0;
    int profit = 0;

    for (int i = start; i < end; ++i)       //i<end bcoz if we buy stock at last price in array then we cannot sell it
        for (int j = i + 1; j <= end; ++j)     //j<=end bcoz we can sell stock at last price in array and still book profits
        {
            if (price[j] > price[i])
            {
                int curr_profit = price[j] - price[i] + 
                                    naive_stockBuySell(price, n ,start, i -1) +
                                    naive_stockBuySell(price, n, j + 1, end);

                profit = max(profit, curr_profit);
            }
        }
    return profit;
}

int stockBuySell(int arr[], int n)
{
    int profit = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] < arr[i+1])  profit += arr[i+1] - arr[i];
    }
    return profit;
}


int main()
{
  int arr[] = {1,5,3,8,12};
  int n = 5; 
  
  cout << "Max profit[naive]    : " << naive_stockBuySell(arr, n, 0, n-1);
  cout << "\nMax profit[efficient]: " << stockBuySell(arr, n);
  
  
  return 0;
}