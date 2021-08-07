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
vector<vector<int>>adj(N);

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
int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int total=0,count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    total++;
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        
        int time=0;

        while(!q.empty())
        {
            int k=q.size();
            count+=k;
            while(k--)
            {
                int c=q.front().first;
                int d=q.front().second;
                q.pop();
                if(c+1<n && grid[c+1][d]==1)
                {
                    q.push({c+1,d});
                    grid[c+1][d]=2;
                }
                if(c-1>=0 && grid[c-1][d]==1)
                {
                    q.push({c-1,d});
                    grid[c-1][d]=2;
                }
                if(d+1<m && grid[c][d+1]==1)
                {
                    q.push({c,d+1});
                    grid[c][d+1]=2;
                }
                if(d-1>=0 && grid[c][d-1]==1)
                {
                    q.push({c,d-1});
                    grid[c][d-1]=2;
                }
            }
            
            if(!q.empty())
                time++;
            //cout<<q.size();
            //break;
        }
        
        if(count==total) return time;
        return -1;
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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>grid;
        for(int i=0;i<n;i++)
        {
            vector<int>v(m);
            for(int j=0;j<m;j++)
            {
                int x;cin>>x;
                v.push_back(x);
            }
            grid.push_back(v);
        }
        cout<<orangesRotting(grid);
    }   
    return 0;
}