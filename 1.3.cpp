//Merge two sorted arrays without using extra space
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
        cin>>b[i];

    //Method1: Using two pointer method
    cout<<"Array1: ";
    int i=0,j=0,k=0;
    while(i<n || j<m)
    {
        if(k==n)
            cout<<endl<<"Array2: ";
        if(i==n)
        {
            cout<<b[j++]<<" ";
            k++;
            if(j==m)
                break;
            continue;
        }
        if(j==m)
        {
            cout<<a[i++]<<" ";
            k++;
            if(i==n)
                break;
            continue;
        }
        if(a[i]<b[j])
            cout<<a[i++]<<" ";
        else
            cout<<b[j++]<<" ";
        k++;
    }

    //Method2: GAP algorithm which uses O((n+m)log(n+m)) time complexity but the above code is
    //O(n+m) time complexity.
    return 0;
}