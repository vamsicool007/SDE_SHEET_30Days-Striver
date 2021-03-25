//Merge two sorted Linked List
//Method1: Creating a separate linked list and adding nodes according to priority
struct ListNode
{
    ListNode *next;
    int data;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{           
    ListNode *prev=new ListNode();
    ListNode *head=prev;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1==NULL)
        {
            while(l2!=NULL)
            {
                ListNode *temp=new ListNode();
                temp->val=l2->val;
                prev->next=temp;
                prev=temp;
                l2=l2->next;
            }
        }
        else if(l2==NULL)
        {
            while(l1!=NULL)
            {
                ListNode *temp=new ListNode();
                temp->val=l1->val;
                prev->next=temp;
                prev=temp;
                l1=l1->next;
            }
        }
        else if((l1->val)<=(l2->val))
        {
            ListNode *temp=new ListNode();
            temp->val=l1->val;
            prev->next=temp;
            prev=temp;
            l1=l1->next;
        }
        else
        {
            ListNode *temp=new ListNode();
            temp->val=l2->val;
            prev->next=temp;
            prev=temp;
            l2=l2->next;
        }
    }
    return head->next;
}

//Method2: We are going to break the inner links and create new links between the lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    if(l1->val>l2->val)
    {
        ListNode *temp=l1;
        l1=l2;
        l2=temp;
    }
    
    ListNode *res=l1;
    while(l1!=NULL && l2!=NULL)
    {
        ListNode *temp=NULL;
        while(l1!=NULL && (l1->val<=l2->val))
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return res;
}