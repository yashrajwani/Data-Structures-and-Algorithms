#include <iostream>
using namespace std;

void sorted_intersection (int a[], int b[], int n1, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (i != 0 && a[i] == a[i-1])   continue;
        
        if (a[i] < b[j])    ++i;
        else if (a[i] > b[j])   ++j;
        else
        {
            cout << a[i] << " ";
            ++i;
            ++j;
        }
    }
    cout << endl;
}

void sorted_union (int a[], int b[], int n1, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (i != 0 && a[i] == a[i-1])   continue;
        if (j != 0 && b[j] == b[j-1])   continue;

        if (a[i] < b[j])    cout << a[i++] << " ";
        else if (a[i] > b[j])   cout << b[j++] << " ";
        else
        {
            cout << a[i] << " ";
            ++i;
            ++j;
        }
    }
    while (i < n1)      if (i == 0 || a[i] != a[i-1])   cout << a[i++] << " ";
    while (j < n2)      if (j == 0 || b[j] != b[j-1])   cout << b[j++] << " ";
    
    cout << endl;
}

int main()
{
    int arr1[] = {1,2,3,4,7,8,9};
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Union : "; 
    sorted_union(arr1, arr2, n1, n2);

    cout << "Intersection : ";
    sorted_intersection(arr1, arr2, n1, n2);
    return 0;
}