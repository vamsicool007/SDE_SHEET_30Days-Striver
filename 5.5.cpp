//Delete a given Node when a node is given. (0(1) solution)
//You will not be given access to the head of the list, 
//instead you will be given access to the node to be deleted directly.
struct ListNode
{
    ListNode *next;
    int data;
};

//in this copy the next node val into current node and break the link between current and next
//and make a link between cur and next to next
void deleteNode(ListNode* node) {
        node->val=(node->next)->val;
        node->next=(node->next)->next;
    }