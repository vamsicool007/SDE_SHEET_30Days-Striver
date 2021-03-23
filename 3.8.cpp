//Counting trailing zeroes in n factorial
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1:The basic idea is whenever 5 multiplied by 2 we generate a zero so there will always
    //extra 2's for each 5 therefore the ans will no. of 5's occuring before n
    int n;
    cin>>n;
    cout<<n/5<<endl;
    return 0;
}