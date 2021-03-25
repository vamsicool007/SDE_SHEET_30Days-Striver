//Find the middle node if there are two middle nodes print the 2nd node
#include<bits/stdc++.h>
using namespace std;

struct listnode
{
    listnode *link;
    int data;
};

listnode* insert(int x,listnode *temp)
{
    listnode *nextnode=new listnode();
    nextnode->data=x;
    nextnode->link=temp;
    return nextnode;
}

int findmiddle(listnode* head)
{
    listnode *slow,*fast;
    slow=head;
    fast=head;

    while((fast->link)!=NULL && (fast->link)->link !=NULL)
    {
        slow=slow->link;
        fast=(fast->link)->link;
    }
    return slow->data;
}

int main()
{ 
    int n;
    cin>>n;
    listnode *head=new listnode();
    head=NULL;
    listnode *temp=head;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        temp=insert(x,temp);  //this is inserting the list in reverse order i.e adding every new node in front
    }  
    head=temp;
    //Method1: Here we will be using the tortoise method. In this there will be two pointers slow and
    //fast the slow pointer will iterate by 1 and fast by 2 then if we find fast is at null then we stop
    //Since slow will cover half the distance covered by fast.
    cout<<findmiddle(head);
    return 0;
}