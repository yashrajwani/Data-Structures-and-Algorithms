#include <iostream>
using namespace std;

int counter = 2;

bool isLucky(int n) {
    //consider n to be position here not a number
    if (n % counter == 0)
        return false;
        
    else if (counter > n)
        return true;
    
    int next = n - (n/counter); //if number isn't eliminated its position changes with each iteration
    ++counter;                  //Moving on to next iteration
    return isLucky(next);
}

int main()
{
    int n;
    
    cout << "Input int:" ; cin >> n;
    cout << "isLucky: " << boolalpha << isLucky(n);
    return 0;
}