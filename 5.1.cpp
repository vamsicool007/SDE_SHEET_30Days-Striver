//Reversing a linked list
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
    temp->data=x;
    temp->link=nextnode;
    return nextnode;
}

listnode* reverse(listnode *head)
{
    listnode *cur,*prev;
    cur=head;
    prev=NULL;
    //here prev is used as temp variable which will make the head point out null
    //after first iteration and then we will iterate head to further link and prev will be 
    //previous head,basically we are breaking the prev link and updating link to prev

    while(cur!=NULL)
    {
        cur=head->link;
        head->link=prev;
        prev=head;
        head=cur;
    }
    head=prev;  //here after last iteration head will be pointing to null therefore we have to make it
                //point to prev 
    return head;
}   

void reverse1(listnode *head)
{
    if(head->link==NULL)
        return;
    reverse1(head->link);
    cout<<head->data<<" ";
}
int main()
{
    int n;
    cin>>n;
    listnode *temp=new listnode();
    listnode *head=temp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        temp=insert(x,temp);
    }
    cout<<"List before reversing: ";
    listnode *cur=head;
    while(cur->link!=NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->link;
    }


    cout<<endl<<"List after reversing: ";
    //Method1: Using recursion
    reverse1(head);

    cout<<endl<<"List after reversing: ";
    //Method2: Reversing the list, breaking the link and recreating link reversely using temp variable
    cur=reverse(head);
    cur=cur->link;
    while(cur!=NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->link;
    }    
    return 0;
}