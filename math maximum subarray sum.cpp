/// O(n)
#include "bits/stdc++.h"
using namespace std;

int kadane(int a[], int n)
{
    int max_so_far=0,max_ending_here=0;
    for (int i=0;i<n;i++)
    {
        max_ending_here+=a[i];
        if(max_ending_here<0)max_ending_here=0;
        if(max_ending_here>max_so_far)max_so_far=max_ending_here;
    }
    return max_so_far;
}


int maxCircularSum(int a[], int n)
{
    int max_kadane=kadane(a,n);

    int max_wrap=0;
    for(int i=0;i<n;i++)
    {
         max_wrap+=a[i];
         a[i]=-a[i];
    }

    max_wrap+=kadane(a,n);

    return max(max_wrap,max_kadane);
}

int main()
{
    int a[]={3,-10,-10,14,-3,-2,4};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %d\n",maxCircularSum(a,n));
    return 0;
}
