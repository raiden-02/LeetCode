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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        int s = 0;
        
        for(ListNode* ptr = head->next; ptr; ptr = ptr->next) {
            if(ptr->val == 0) {
                if(s == 0) continue;
                tmp->next = new ListNode(s);
                tmp = tmp->next;
                s = 0;
            }
            
            else s += ptr->val;
        }

        return ans->next;
    }
};
