//Stock Buy and Sell
#include<bits/stdc++.h>
using namespace std;



int main()
{
    
    //Method1: Linear traversal from back and check for max as in this problem we first buy and then sell
    //so selling price should be greater
    int n;
    cin>>n;
    int a[n];
    int profit=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int maxx=-1000000;
    for(int i=n-1;i>=0;i--)
    {
        maxx=max(maxx,a[i]);
        profit=max(profit,maxx-a[i]);
    }
    cout<<profit;
    return 0;
}