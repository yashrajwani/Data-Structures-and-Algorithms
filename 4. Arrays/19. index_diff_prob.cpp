//Given an array A[] of N positive integers. 
//The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].


int maxIndexDiff(int arr[], int n) 
{ 
    
    // Your code here
    int max_diff, i, j;
    int* lmin = new int[n];
    int* rmax = new int[n];
    
    lmin[0] = arr[0];
    for (int i = 1; i < n; ++i)
        lmin[i] = min(lmin[i-1], arr[i]);
        
    rmax[n-1] = arr[n-1];
    for (int i = n-1; i >= 0; ++i)
        rmax[i] = min(rmax[i+1], arr[i]);
        
    i = 0; j = 0; max_diff = -1;
    while ((i < n) && (j < n))
    {
        if (lmin[i] <= rmax[j])
        {
            max_diff = max(j-i, max_diff);
            j++;
        }
        else    i++;
    }
    return max_diff; 
}

int main()
{
    int arr[] = {34,8,10,3,2,80,30,33,1}
    int n = sizeof(arr)/ sizeof(arr[0]);
    return 0;
}