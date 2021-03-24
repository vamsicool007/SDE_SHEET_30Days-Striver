//Longest consecutive subsequence
#include<bits/stdc++.h>
using namespace std;



int main()
{
    //Method1: Using hashmap and checking if the a[i]-1 and a[i]+1 exist and updating the hashmap
    //with max(hash[a[i]-1]+1,hash[a[i]+1]+1) since adding +1 is for incrementing the current count 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    map<int,int>m;
    sort(a,a+n);
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        m[a[i]]=max(m[a[i]-1]+1,m[a[i]+1]+1);
        maxx=max(maxx,m[a[i]]);
    }
    cout<<maxx<<endl;
    return 0;
}