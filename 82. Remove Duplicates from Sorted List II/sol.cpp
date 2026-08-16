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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(0, head);
        ListNode *prev = res;
        
        while(head != NULL && head->next != NULL) {
            if(head->next != NULL && head->next->val == head->val) {
                while(head->next != NULL && head->next->val == head->val)
                    head = head->next;
                prev->next = head->next;
            }
            else
                prev = prev->next;
            
            head = head->next;
        }
        
        return res->next;
    }
};
