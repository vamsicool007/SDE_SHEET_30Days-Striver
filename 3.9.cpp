//Finding gcd of a,b in time complexity O(logn)
#include<bits/stdc++.h>
using namespace std;

//Method1: Euclid's gcd algo
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}