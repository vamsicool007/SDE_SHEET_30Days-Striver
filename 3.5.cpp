//No. of unique paths in a grid form (0,0) to (n-1,m-1) while moving only down and right
#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[105][105];
int solve1(int i,int j)
{
    if(i==n || j==m)
        return 0;
    if(i==n-1 && j==m-1)
        return 1;

    return solve1(i+1,j)+solve1(i,j+1);
}
int solve2(int i,int j)
{
    if(i==n || j==m)
        return 0;
    if(i==n-1 && j==m-1)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=solve2(i+1,j)+solve2(i,j+1);
}
int solve3()
{
    int r=m-1;
    int d=n-1;
    //Idea is you need to take some total t=(r+d) steps and in that r will be right and d will be down
    //therefore t!/(r!*d!) is the ans
    int t=r+d;
    //pascal triangle ncr method
    long long int ans=1;
    for(int i=1;i<=r;i++)
        ans=ans*(t-r+i)/i;
    return ans;
}
int main()
{  
    cin>>n>>m;
    //Method1: Using recursion but the time complexity will be exponential
    cout<<solve1(0,0);
    //Method2: Using DP but the time complexity will be n*m and space will also be same
    memset(dp,-1,sizeof(dp));
    cout<<solve2(0,0);
    //Method3: Using permutation and combination
    cout<<solve3();
    return 0;
}