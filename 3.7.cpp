//Excel coloumn number A->1 B->2 C->3...Y->25 Z->26 AA->27 AB->28...AZ->52 BA->53...ZA->677...ZZ->702
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1: Using formula since it will form an equation
    //eg: ABCD=((((1)*26+2)*26+3)*26+4)  
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans*=26;
        ans+=(s[i]-'A'+1);
    }
    cout<<ans<<endl;
    return 0;
}