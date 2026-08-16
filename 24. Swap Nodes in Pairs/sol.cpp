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
    ListNode* swapPairs(ListNode* head) {
        if(not head) return nullptr;
        
        ListNode *cur = head, *nex = nullptr, *nhead = nullptr, *prev = nullptr;
        
        while(cur and cur->next) {
            nex = cur->next;
            if(not nhead) nhead = nex;
            
            cur->next = nex->next;
            nex->next = cur;
            
            if(prev) prev->next = nex;
            prev = cur;
            
            cur = cur->next;
        }
        
        if(not nhead) nhead = head;
        
        return nhead;
    }
};
