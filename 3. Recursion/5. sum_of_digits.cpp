#include <iostream>
using namespace std;

int sum_digits(int n)
{   
    if (n % 10 == 0)      return n;
    return ((n % 10) + sum_digits(n / 10));
}

int tail_recursive_sum_digits(int n,int ans = 0)
{   
    if (n % 10 == 0)      return ans;
    return tail_recursive_sum_digits(n / 10, ans + (n % 10));
}


int main()
{
    int n;
    cout << "Input N: " ; cin >> n;
    cout << "Sum of digits of " << n << ":  " << sum_digits(n) << endl;
    cout << "Sum of digits of " << n << ":  " << tail_recursive_sum_digits(n);
    
    return 0;
}