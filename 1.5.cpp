//Merge Overlapping Subintervals
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v; //pairs wiil be added to vector pair to simplify out sort 
        a[i]={u,v};
    }
    //Method1: This is the optimal approach using 2 pointers
    sort(a.begin(),a.end());
    vector<pair<int,int>>ans; 
    int c=a[0].first;
    int d=a[0].second;
    for(int i=1;i<n;i++)
    {
        //if the first element of the pair is in the interval we have to merge the intervals
        if(a[i].first>=c && a[i].first<=d)
            d=max(a[i-1].second,a[i].second);
        //else we have to push back the pair in ans vector and update the c and d values for new interval
        else
        {
            ans.push_back({c,d});
            c=a[i].first;
            d=a[i].second;
        }
    }
    ans.push_back({c,d});
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}