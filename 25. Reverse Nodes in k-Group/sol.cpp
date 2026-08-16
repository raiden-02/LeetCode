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
    ListNode *reverse(ListNode *head, int k) {
        ListNode *prev = nullptr;
        
        while(head and k--) {
            ListNode *nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *root = new ListNode(-1);
        ListNode *prev = root, *cur = head;
        
        while(cur) {
            int ind = 0;
            ListNode *tail = cur;
            
            while(cur and ind < k)
                cur = cur->next, ind++;
            
            if(ind != k)
                prev->next = tail;
            
            else {
                prev->next = reverse(tail, k);
                prev = tail;
            }
        }
        
        return root->next;
    }
};
