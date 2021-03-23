//Given a 2D matrix where the elements are sorted in each row and each coloumn,find the target
#include<bits/stdc++.h>
using namespace std;
void fun()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    fun();
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    int x;
    cin>>x; //taking input for target 
    
    //Method1: Doing liner search not optimal as time complexity is O(n*m) but it will be O(1) space
    //Method2: Doing binary search on each row which will be O(nlog2(m))
    //Method3: Optimal approach is take a pointer pointing elemnet of first row and last coloumn then
    //iterating it downward if target is greater and iterating towards left if target is lesser 
    //and if the pointer goes out of bound then not found

    int i=0,j=m-1,flag=1;
    while(a[i][j]!=x)
    {
        if(x>a[i][j])
            i++;
        else
            j--;
        if(i==n || j==-1)
            {flag=0;break;}
    }
    if(!flag)
        cout<<"Element not found"<<endl;
    else
        cout<<"Element found at "<<i+1<<" "<<j+1<<endl;
    return 0;
}