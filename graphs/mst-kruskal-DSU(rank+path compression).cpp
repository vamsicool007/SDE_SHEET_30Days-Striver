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
vector<pair<int,pair<int,int>>>adj;
int par[N];
int rankkk[N];
vector<pair<int,int>>ans;

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

int findparent(int x)
{
    if(par[x]==-1)
        return x;
    return par[x]=findparent(par[x]);
}

void unionn(int x,int y)
{
    x=findparent(x);
    y=findparent(y);

    if(rankkk[x]<rankkk[y])
        par[x]=y;
    else if(rankkk[x]>rankkk[y])
        par[y]=x;
    else
        {par[x]=y;rankkk[y]++;}
}

int kruskal(int n,vector<pair<int,pair<int,int>>>&v)
{
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int c=findparent(v[i].second.first);
        int d=findparent(v[i].second.second);
        if((c==d && d==-1) || c!=d)
        {
            unionn(findparent(v[i].second.first),findparent(v[i].second.second));
            ans.push_back({v[i].second.first,v[i].second.second});
            sum+=v[i].first;
        }
    }
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
            adj.push_back({d,{u,v}});
        }
        for(int i=0;i<n;i++)
            par[i]=-1,rankkk[i]=0;

        cout<<kruskal(n,adj)<<endl;

        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}