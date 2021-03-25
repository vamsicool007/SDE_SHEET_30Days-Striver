//Remove N-th node from back of LinkedList
//Method1: We will be again using tortoise method here by creating gap in slow and fast i.e traversing
//fast first by n and then again traversing slow and fast each by one until fast->next is null
struct ListNode
{
    ListNode *next;
    int data;
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *temp=new ListNode();
    temp->next=head;
    ListNode *slow=temp;
    ListNode *fast=temp;
    
    for(int i=1;i<=n;i++)
        fast=fast->next;
    
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    slow->next=slow->next->next;
    return temp->next;
}