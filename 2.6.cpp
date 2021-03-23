//Rotate Matrix by 90 degress without using extra space
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1: Find transpose of the matrix and reverse every row
    int n;
    cin>>n;
    int m=n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    //Step1: Finding transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
            swap(a[i][j],a[j][i]);
    }
    //Step2:Reversing each row
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m/2;j++)
            swap(a[i][j],a[i][m-j-1]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}