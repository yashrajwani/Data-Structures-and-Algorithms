//Given two sorted arrays
//find median of combined array

#include <iostream>
using namespace std;

double getMedian(int a1[], int a2[], int n1, int n2)
{
    //array1 is smaller array
    int *array1, *array2, smaller_size;
    if (n1 >= n2)   
    {
        array1 = a2;
        array2 = a1;
        smaller_size = n2;
    }
    else
    {
        array1 = a1;
        array2 = a2;
        smaller_size = n1;
    }

    int begin1 = 0, end1 = smaller_size;
    while (begin1 <= end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int min1 = (i1 == n1) ? INT32_MAX : array1[i1];       //min of right side of array1
        int max1 = (i1 == 0) ? INT32_MIN : array1[i1 - 1];    //max of left side of array1
        int min2 = (i2 == n2) ? INT32_MAX : array2[i2];       //min of right side of array2
        int max2 = (i2 == 0) ? INT32_MIN : array2[i2 - 1];    //max of left side of array2

        if ((max1 <= min2) && (max2 <= min1))
        {
            if ((n1 + n2) % 2 == 0)
                return ((double) max(max1, max2) + min(min1, min2)) / 2;
            else    
                return (double) max(max1, max2);
        }
        else if (max1 > min2)   end1 = --i1;
        else    begin1 = ++i1;
    }
}


int main()
{
    int a1[] = {1,2,3,4,5,6,7,10,20,30,40}, a2[] = {8,9,50,60,70,80,90,100};
    int n1 = sizeof(a1) / sizeof(a1[0]), n2 = sizeof(a2) / sizeof(a2[0]);

    cout << getMedian(a1, a2, n1, n2);
    return 0;
}
