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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* tmp = head;
        
        while(tmp) {
            ans = ans * 2 + tmp->val;
            tmp = tmp->next;
        }
        
        return ans;
    }
};
