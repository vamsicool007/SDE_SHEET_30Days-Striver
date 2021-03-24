//Count number of subarrays having a given XOR(this clears a lot of problems) 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    //Method1: Take prefix xor till ith element then if prefix xor == k(target xor) then we can surely
    //say that subarray will occur 100% which increments count by 1.Storing prefix xor in hash map with
    //count of how many times each prefix xor occured. Now we know that a^b=c therefore,b=a^c. 
    //With this we can say that if prefix xor=k^y then y=k^(prefix xor) now we know that how many times y
    //has occured earlier through hash map which leads to how many times k xor had occured i.e. hash[y].   
    int n;
    cin>>n;
    int k;
    cin>>k; //target xor
    int a[n];
    map<int,int>m;
    int x=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        x^=a[i];
        c+=m[k^x];
        if(x==k)
            c++;
        m[x]++;
    }
    cout<<c<<endl;
    return 0;
}