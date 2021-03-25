//Add two numbers as LinkedList
//Method1: Iterate through linked lists and if there is a carry add it next time and after last iteration
//if carry is found make one more node and link it to previous
struct ListNode
{
    ListNode *next;
    int data;
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *temp=new ListNode();
    ListNode *cur=temp;
    int carry=0;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1==NULL)
        {
            while(l2!=NULL)
            {
                ListNode *sum=new ListNode();
                sum->val=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                l2=l2->next;
                temp->next=sum;
                temp=sum;
            }
        }
        else if(l2==NULL)
        {
            while(l1!=NULL)
            {
                ListNode *sum=new ListNode();
                sum->val=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                l1=l1->next;
                temp->next=sum;
                temp=sum;
            }
        }
        else
        {
            ListNode *sum=new ListNode();
            sum->val=((l1->val)+(l2->val)+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
            temp->next=sum;
            temp=sum;
        }
    }
    if(carry)
    {
        ListNode *sum=new ListNode();
        sum->val=carry;
        temp->next=sum;
        temp=sum;
    }
    return cur->next;
}