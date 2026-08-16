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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> frq;
        ListNode* sent = new ListNode();
        sent->next = head;
        ListNode* ptr = sent;
        
        while(ptr->next) {
            frq[ptr->next->val]++;
            ptr = ptr->next;
        }
        
        ptr = sent;
        
        while(ptr and ptr->next) {
            ListNode* ptr2 = ptr->next;
            
            while(ptr2 and frq[ptr2->val] > 1)
                ptr2 = ptr2->next;
            
            ptr->next = ptr2;
            ptr = ptr->next;
        }
        
        return sent->next;
    }
};
