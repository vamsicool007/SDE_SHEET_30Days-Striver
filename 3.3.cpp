//Majority element in an array (>n/2 times) using O(1) space complexity
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1: Using count method  
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int count=0;
    int element;
    for(int i=0;i<n;i++)
    {
        if(!count)
            element=a[i];
        if(element==a[i])
            count++;
        else
            count--;
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==element)
            count++;
    }
    if(count>(n/2))
        cout<<"The majority element is "<<element;
    else
        cout<<"There are no majority elements";
    return 0;
}