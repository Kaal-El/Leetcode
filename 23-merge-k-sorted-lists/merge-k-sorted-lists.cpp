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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        vector<int> ans;
        for (int i = 0; i < lists.size(); i++) {
            if(lists[i] == nullptr)
                continue;
            ListNode* ptr = lists[i];
            while (ptr != NULL) {
                ans.push_back(ptr->val);
                ptr = ptr->next;
            }
         }
        if(ans.empty())
            return nullptr;
         sort(ans.begin(),ans.end());
        ListNode*root = new ListNode(ans[0]);
        ListNode*curr = root;

        for(int i=1;i<ans.size();i++)
        {
            ListNode*temp = new ListNode(ans[i]);
            curr->next = temp;
            curr = curr->next;
        }

        return root;

        }

    
};