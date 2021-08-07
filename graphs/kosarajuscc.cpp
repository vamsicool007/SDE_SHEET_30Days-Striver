//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//* vamsicool007      Nothing is IMPOSSIBLE as the word itself says I'M POSSIBLE!!       vamsicool007 *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include<bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define all(v) (v).begin(),(v).end() 
#define endl "\n"
#define int long long int
#define ll long long
#define ld long double
const int mod = 1000000007;
const int N=200005;
const int inf=1e18;


//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll power(ll x,ll y){ll res=1;x=x;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res%mod;}
ll gcd(ll a,ll b){if (a==0)return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return (a/gcd(a,b)*b);}
ll max(ll a,ll b){ll ans=a>b?a:b;return ans;}
ll min(ll a,ll b){ll ans=a<b?a:b;return ans;}

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void fun()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void dfs(int u,stack<int> &s,vector<int> &visited,vector<vector<int>> &adj)
{
    visited[u]=1;
    for(auto i:adj[u])
    {
        if(!visited[i])
            dfs(i,s,visited,adj);
    }
    s.push(u);
}


vector<int> toposort(int n,vector<vector<int>> &adj)
{
    stack<int>s;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(i,s,visited,adj);
    }

    vector<int>v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

void transposefuntion(int n,vector<vector<int>> &transpose,vector<vector<int>> &adj)
{
    for(int i=0;i<n;i++)
    {
        for(auto j:adj[i])
            transpose[j].push_back(i);
    }
}

void kosaraju(int n,vector<vector<int>> &adj)
{
    //finding transpose
    vector<vector<int>>transpose(N);
    transposefuntion(n,transpose,adj);

    //finding finish time using toposort
    vector<int>v=toposort(n,adj);
    
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            stack<int>s;
            cout<<"SCC: ";
            dfs(i,s,vis,transpose);
            while(!s.empty())
                {cout<<s.top()<<" ";s.pop();}
            cout<<endl;
        }
    }
}

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

signed main()
{
    flash;
    fun();
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        int e;
        cin>>e;
        vector<vector<int>>adj(N);
        for(int i=0;i<e;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        kosaraju(n,adj);
    }
    return 0;
}