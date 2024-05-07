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
    ListNode* reverse(ListNode* left,ListNode* right)
    {
        ListNode* prev=NULL;
        ListNode* curr=left;
        ListNode* next=NULL;
        while(curr!=right)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* left0=NULL;
        ListNode* left1=NULL;
        ListNode* right0=NULL;
        ListNode* right1=NULL;
        ListNode* ptr=head;
        int count=1;
        while(ptr!=NULL)
        {
            if(count==left-1) left0=ptr;
            if(count==left) left1=ptr;
            if(count==right) right0=ptr;
            if(count==right+1) right1=ptr;
            ptr=ptr->next;
            count++;
        }
        ptr = reverse(left1, right1);
        if (left == 1)
        head = ptr; // Update head if left is the beginning of the list
        else
            left0->next = right0;
        left1->next = right1;
        return head;

    }
};