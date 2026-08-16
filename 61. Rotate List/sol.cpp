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
    ListNode* rotateRight(ListNode* head, int k) {
        if(not head or not k) return head;
        
        ListNode *tail = head;
        int n = 1;
        
        while(tail->next) n++, tail = tail->next;
        
        tail->next = head;
        int newHeadpos = n - k % n;
        tail = tail->next;
        
        for(int i = 1; i < newHeadpos and tail; i++, tail = tail->next);
        
        head = tail->next;
        tail->next = nullptr;
        
        return head;
    }
};
