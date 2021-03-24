//2 Sum problem 
#include<bits/stdc++.h>
using namespace std;


int main()
{
    //Method1: Using hashmap and then checking if every target-a[i] element exists previously 
    //if exists that will be the ans

    int n;
    cin>>n;
    int x;
    cin>>x;  //target sum
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    map<int,int>m;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(m[x-a[i]])
        {
            ans.push_back(m[x-a[i]]-1);
            ans.push_back(i);
            break;
        }
        m[a[i]]=i+1;
    }
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}