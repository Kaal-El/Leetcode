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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(0);
        ListNode* ptr=dummy;
        while(list1!=NULL and list2!=NULL)
        {
            if(list1->val>list2->val)
            {
                ptr->next=list2;
                list2=list2->next;
            }
            else
            {
                ptr->next=list1;
                list1=list1->next;
            }
            ptr=ptr->next;
        }
        ptr->next = list1 ? list1 : list2;

        return dummy->next;
        
    }
};