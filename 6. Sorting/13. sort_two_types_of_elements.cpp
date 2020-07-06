//sorting a binary array in O(n) time complexity

//can be modified to segregate
//-ve and +ve
//even and odd

#include <iostream>
using namespace std;

void sort (int arr[], int n)
{
    //Sorting a binary array using hoare partition
    int i = -1, j = n;
    while (true)
    {
        do{
            i++;
        } while (arr[i] == 0);

        do{
            j--;
        } while (arr[j] == 1);

        if (i >= j)     return;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {1,0,1,0,1,0,1,0,1,1,1,0};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n1);
    for (auto x : arr)  cout << x << " ";
    return 0;
}