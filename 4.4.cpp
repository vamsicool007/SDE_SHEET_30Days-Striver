//Longest Subarray with 0 sum 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1: Using prefix sum and hashmap
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    map<int,vector<int>>m;
    int pre[n];
    pre[0]=a[0];
    m[pre[0]].push_back(0);
    for(int i=1;i<n;i++)
    {
        pre[i]=(pre[i-1]+a[i]);
        m[pre[i]].push_back(i);
    }

    int maxx=-1;
    for(auto i:m)
    {
        int s=0;
        for(int j=1;j<i.second.size();j++)
            s+=(i.second[j]-i.second[j-1]);
        if(i.first==0)
            maxx=max(maxx,i.second[i.second.size()-1]+1);
        maxx=max(maxx,s);
    }
    cout<<maxx<<endl;
    return 0;
}