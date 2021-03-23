//Find x^n in O(log(n)) usually known as fast power
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1: Using fast power algorithm.Here we store the x and multiply the x with itself if
    //power is even since if the power is even the number will repeat and if power is odd multiply
    //the res with x  
    double ans=1.0;
    double x
    int n;
    cin>>x>>n;
    while(n)
    {
        if(n&1)
            ans*=x;
        x*=x;
        n/=2;
    }
    cout<<ans<<endl;
    return 0;
}