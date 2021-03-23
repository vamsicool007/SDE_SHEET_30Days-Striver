//Set matrix zeroes if you find a zero in matrix make that entire row and coloumn zero
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    //Method1: Using hash map for which row and coloumn we have to update if there are 
    //multiple zeroes in same row or coloumn
    map<int,int>row;
    map<int,int>col;
    int b[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
            if(!a[i][j])
                row[i]++,col[j]++;
        }
    }
    for(auto i:row)
    {
        for(int j=0;j<m;j++)
            b[i.first][j]=0;
    }
    for(auto i:col)
    {
        for(int j=0;j<n;j++)
            b[j][i.first]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }

    //Method2: Using dummy array inside the matrix giving O(1) space complexity
    int c=0;
    for(int i=0;i<n;i++) 
    {
        if(a[i][0])
            c=0;
        for(int j=1;j<m;j++)
        {
            if(a[i][j]==0)
                a[i][0]=a[0][j]=0;
        }
    }
    //updating the array from last as the dummy row and col should be updated last for correct matrix 
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=1;j--)
        {
            if(a[i][0]==0 || a[0][j]==0)
                a[i][j]=0;
        }
        if(c==0)
            a[i][0]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}