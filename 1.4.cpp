//Kadane’s Algorithm i.e. findout maximum subarray sum
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    //Merhod1: Using naive approach i.e considering all the subarray sums and finding maximum
    int maxx=-1000005;
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=i;j<n;j++)
        {
            s+=a[j];
            maxx=max(maxx,s);
        }
    }
    cout<<maxx<<endl;

    //Method2: Using kadane's algorithm
    int dp[n+1]={0};
    maxx=-1000005;
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(a[i-1],dp[i-1]+a[i-1]); //storing the sum till now and comparing if we add
                                          //a[i] to the sum till now
        maxx=max(maxx,dp[i]);              //taking maxx of sum till now
    }
    cout<<maxx<<endl;
    return 0;
}