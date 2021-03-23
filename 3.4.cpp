//Majority element in an array (>n/3 times) using O(1) space complexity
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Method1: Using count method. This is an extension of previous algorithm(Boyer Moore Voting algo)  
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int count1=0,count2=0;
    int element1=-1,element2=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==element1)
            count1++;
        else if(a[i]==element2)
            count2++;
        else if(count1==0)
        {
            element1=a[i];
            count1=1;
        }
        else if(count2==0)
        {
            element2=a[i];
            count2=1;
        }
        else
            count1--,count2--;
    }
    count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==element1)
            count1++;
        else if(a[i]==element2)
            count2++;
    }
    if(count1>(n/3) && count2>(n/3))
        cout<<"The majority elements are "<<element1<<" "<<element2;
    else if(count1>(n/3))
        cout<<"The majority element is "<<element1;
    else if(count2>(n/3))
        cout<<"The majority element is "<<element2;
    else
        cout<<"There are no majority elements";
    return 0;
}