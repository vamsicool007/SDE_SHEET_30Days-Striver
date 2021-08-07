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
vector<int>vis(N);
vector<pair<int,int>>adj[N];
int par[N];

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

int prim(int n)
{
	int mst[n];
	int dist[n];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

	for(int i=0;i<n;i++)
		dist[i]=inf;

	memset(par,-1,sizeof(par));
	memset(mst,0,sizeof(mst));

	dist[0]=0;
	pq.push({dist[0],0});
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		int index=pq.top().second;
		int d=pq.top().first;
		pq.pop();
		sum+=d;
		mst[index]=1;
		for(auto j:adj[index])
		{
			if(dist[j.first]>j.second && !mst[j.first])
			{
				par[j.first]=index;
				dist[j.first]=j.second;
				pq.push({dist[j.first],j.first});
			}
		} 
	}
	sum+=pq.top().first;
	return sum;
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
        for(int i=0;i<e;i++)
        {
            int u,v,d;
            cin>>u>>v>>d;
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        cout<<prim(n)<<endl;

        for(int i=1;i<n;i++)
        {
        	cout<<par[i]<<" "<<i<<" "<<endl;
        }
    }
    return 0;
}