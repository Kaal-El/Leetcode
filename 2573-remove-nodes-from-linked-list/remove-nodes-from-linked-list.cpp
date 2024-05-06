/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* current=head;
        ListNode*prev=NULL;
        ListNode* next=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        ListNode* ptr=head;
        int val=ptr->val;
        while(ptr!=NULL)
        {
            if(val<ptr->val) val=ptr->val;
            if(ptr->next!=NULL and ptr->next->val<val)ptr->next=ptr->next->next;
            else ptr=ptr->next;
        }
        return(reverse(head)); 
    }
};