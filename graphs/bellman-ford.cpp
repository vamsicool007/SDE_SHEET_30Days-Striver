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
map<pair<int,int>,int>adj;

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

bool bellmanford(int n,int source)
{
	vector<int>dist(n,inf);
	dist[source]=0;
	for(int i=0;i<n-1;i++)
	{
		for(auto j:adj)
		{
			int c=j.first.first;
			int d=j.first.second;
			int key=j.second;

			if(dist[c]==inf && dist[d]==inf)
				continue;
			else if(dist[c]+key<dist[d])
				dist[d]=dist[c]+key;
		}
		// for(auto j:dist)
		// 	cout<<j<<" ";cout<<endl;
	}

	for(auto i:adj)
	{
		int c=i.first.first;
		int d=i.first.second;
		int key=i.second;

		if(dist[c]==inf && dist[d]==inf)
			continue;
		else if(dist[c]+key<dist[d])
		{
			dist[d]=dist[c]+key;
			return true;
		} 
	}

	return false;
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
            adj[{u,v}]=d;
        }
        cout<<bellmanford(n,0);
    }
    return 0;
}