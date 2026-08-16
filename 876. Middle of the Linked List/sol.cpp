//straightforward 2 pass
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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        
        for(ListNode *tmp = head; tmp; tmp = tmp->next, n++);
        
        ListNode *tmp = head;
        int i = 0, mid = n / 2;
        
        while(i < mid) {
            tmp = tmp->next;
            i++;
        }
        
        return tmp;
    }
};

//two pointer
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        for(; fast and fast->next; slow = slow->next, fast = fast->next->next);
        
        return slow;
    }
};
