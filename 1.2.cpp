//Find the repeating and missing element in an array considered the original array is a permutation
#include<bits/stdc++.h>
using namespace std;

void solve1(int a[],int n)
{
    //Method1: Modifying indexes and marking the visited places
    cout<<"The repeating and missing elements are ";
    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])-1]>0)
            a[abs(a[i])-1]=-a[abs(a[i])-1];
        else
            cout<<abs(a[i])<<" and ";
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
            cout<<i+1<<endl;
    }
}

void solve2(int b[],int n)
{
    //Method2: Using equations of sum of natural nuumbers and sum of squares of natural numbers
    int s1=0;
    for(int i=0;i<n;i++)
        s1+=b[i];
    int s2=(n*(n+1))/2;
    int c=s1;
    int d=s2;
    s2=abs(s2-s1); //this will give the difference between missing and repeating elements
    int s3=0;
    for(int i=0;i<n;i++)
        s3+=(b[i]*b[i]);
    int s4=(n*(n+1)*(2*n+1))/6;
    s4=abs(s4-s3); //this will give the difference between squares of missing and repeating elements
    //therefore x^2-y^2=(x+y)*(x-y) and we already have a-b

    int s5=s4/s2; //this will give the sum of missing and repeating elements
    int x=(s5+s2)/2;
    int y=(s5-s2)/2;
    if(d>c)
    cout<<"The repeating and missing elements are "<<min(x,y)<<" and "<<max(x,y)<<endl;
    else
    cout<<"The repeating and missing elements are "<<max(x,y)<<" and "<<min(x,y)<<endl;
}

void solve3(int c[],int n)
{
    //Method3: Using xor operations  
    int x1=c[0]^1;            
    for(int i=1;i<n;i++)
    {
        x1^=c[i];
        x1^=(i+1);
    }
    //x1 is the xor of the repeating and missing elements 
    //as the xor of each index cancels out with element repeating once

    //get the rightmost set bit
    //dividing the elements into two sets and later again xoring with the indexs resulting
    //in a missing and repeating elements as the previous elements will be cancelled 
    int set_bit_no=x1 & ~(x1-1);
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(c[i] & set_bit_no)
            x^=c[i];
        else
            y^=c[i];
        if((i+1) & set_bit_no)
            x^=(i+1);
        else
            y^=(i+1);
    }
    cout<<"The repeating and missing elements are "<<x<<" and "<<y<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    solve1(a,n);
    solve2(b,n);
    solve3(c,n);
    return 0;
}