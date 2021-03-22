//Sorting 0's 1's 2's in the least time possible without using sorting algo and O(1) space complexity
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    //Method1: Count number of 0's 1's 2's and print them individually
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++) 
    {
        if(a[i]==0)
            cnt0++;
        else if(a[i]==1)
            cnt1++;
        else
            cnt2++;
    }
    for(int i=0;i<cnt0;i++)
        cout<<0<<" ";
    for(int i=0;i<cnt1;i++)
        cout<<1<<" ";
    for(int i=0;i<cnt2;i++)
        cout<<2<<" ";

    //Method2: Using 3 pointer method
    int low=0,mid=0,high=n-1;   //elements left of a[low] will be 0 
                                //elements right of a[high] will be 2 
                                //elements between low and high will be 1
    //if mid points 0 swap a[low] with a[mid] and increment both low and mid
    //if mid points 1 increment mid
    //if mid points 2 swap a[high] with a[mid] and increment mid and decrement high


    while(mid<=high)
    {
        if(a[mid]==0)
            swap(a[low++],a[mid++]);
        else if(a[mid]==1)
            mid++;
        else
            swap(a[high--],a[mid]);
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}