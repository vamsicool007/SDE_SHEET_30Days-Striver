//Next Permutation 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    //Method1: Basic algo of next permutation
    //Step1: Traverse from back and find an index where a[i]<a[i+1] since we need to find the peak
    //and break it down since if a[i+1] is lesser than a[i] and again a[i] is lesser than a[i-1] then
    //there is an increasing peak so we have to find the peak and break it
    int idx=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
            {idx=i;break;}
    }
    if(idx>=0)
    {
        //Step2: Since it is next permutation we have to replace the a[idx] with just greater number than that
        int idx2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>a[idx])
                {idx2=i;break;}
        }
        swap(a[idx],a[idx2]);
        //Step3: This is because now after the swap we will have the decreasing order for new combo
        //it should be increasing for the new combo
        reverse(a.begin()+idx+1,a.end());
    }
    else  //this means that it is the largest permutation possible no after the largest the next permutation will be smallest
        reverse(a.begin(),a.end());
    for(auto i:a)
        cout<<i<<" ";
    return 0;
}