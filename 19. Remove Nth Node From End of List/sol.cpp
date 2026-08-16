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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sent = new ListNode(-1, head);
        ListNode* fast = sent, *slow = sent;
        
        for(int i = 0; i <= n; i++)
            fast = fast->next;
        
        while(fast)
            slow = slow->next, fast = fast->next;
        
        slow->next = slow->next->next;
        
        return sent->next;
    }
};

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

// --- alternate solution ---

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        int dist = 0;
        
        while(fast and dist < n)
            fast = fast->next, dist++;
        
        while(slow and fast)
            fast = fast->next, prev = slow, slow = slow->next;
        
        if(slow == head)
            head = head->next, delete(slow);
        
        else if(prev)
            prev->next = slow->next, delete(slow);
        
        return head;
    }
};
