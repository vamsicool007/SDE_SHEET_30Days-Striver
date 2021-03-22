//Find the duplicate in an array of N+1 integers with O(1) space and not modifying the array
#include<bits/stdc++.h>
using namespace std;
void fun()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    fun();
    int n;
    cin>>n; //here the input is taken for n+1 integers
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    //Method1: Using the tortoise method in which where the cycle ends that is the repeating number
    //but since we have to to O(1) space complexity we can't take a array or map for visited values

    int slow=0;  //the slow pointer is incremented once and fast twice since one number will be repeating 
    int fast=0;  //there will be a formation of cycle and slow and fast will collide then again slow 
                 //will be placed on the first position and then both fast and slow will be incremented
                 //and again there will be collision and this time the collided is the repeating number

    do
    {
        slow=a[slow];
        fast=a[a[fast]];
    }while(slow!=fast);

    slow=0;
    do
    {
        slow=a[slow];
        fast=a[fast];
    }while(slow!=fast);

    cout<<slow;
    return 0;
}