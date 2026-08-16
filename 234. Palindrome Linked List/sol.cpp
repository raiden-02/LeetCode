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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;

        ListNode* first = head, *second = head, *slow = head, *fast = head, *prev = nullptr;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) prev->next = nullptr;
        second = slow;

        if(first == second) return true;

        ListNode* cur = nullptr, *ptr = second;

        while(ptr) {
            ListNode* nex = ptr->next;
            ptr->next = cur;
            cur = ptr;
            ptr = nex;
        }

        second = cur;

        for(; first && second; first = first->next, second = second->next) {
            if(first->val != second->val) return false; 
        }
        
        return true;
    }
};
