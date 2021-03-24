//Longest substring without repeatition
#include<bits/stdc++.h>
using namespace std;


int main()
{
    //Method1: Using hashmap and storing indexes of each character where you can directly make l
    //to jump on the last occured character+1 Time Complexity=O(n)
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=0,c=0;
    map<char,int>m;
    while(r<n)
    {
        if(m.find(s[r])!=m.end())
            l=max(l,1+m[s[r]]);     //if the character had already occured then there is a 
                                    //chance we are using previous index if we don't take max
        m[s[r]]=r;                  //updating index of each character
        c=max(c,r-l+1);
        r++;
    } 
    cout<<c<<endl;    
    return 0;
}