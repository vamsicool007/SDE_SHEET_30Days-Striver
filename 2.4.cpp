//Inversion of Array (Using Merge Sort) i.e i<j but a[i]>a[j]
#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int b[],int l,int mid,int r)
{
    int i=l,j=mid+1,k=l;
    int cnt=0;
    while(k<=r)
    {
        if(i==mid+1)
            {b[k++]=a[j++];continue;}
        if(j==r+1)
            {b[k++]=a[i++];continue;}
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
        {
            cnt+=(mid-i+1);
            b[k++]=a[j++];
        }
    }
    for(int i=l;i<=r;i++)
        a[i]=b[i];
    return cnt;
}
int mergesort(int a[],int b[],int l,int r)
{
    int cnt=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        cnt+=mergesort(a,b,l,mid);
        cnt+=mergesort(a,b,mid+1,r);
        
        cnt+=merge(a,b,l,mid,r);
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n]={};
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<mergesort(a,b,0,n-1);
    return 0;
}