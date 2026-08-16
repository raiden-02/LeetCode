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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sentA = new ListNode(), *sentB = new ListNode();
        ListNode* ptr = head, *ptrA = sentA, *ptrB = sentB;

        while(ptr) {
            if(ptr->val < x) {
                ptrA->next = new ListNode(ptr->val);
                ptrA = ptrA->next;
            }

            else {
                ptrB->next = new ListNode(ptr->val);
                ptrB = ptrB->next;
            }

            ptr = ptr->next;
        }

        ptrA->next = sentB->next;
        
        return sentA->next;
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *sent = new ListNode(-101, head);
        ListNode* p1 = head, *p2 = sent;
        
        while(p1) {
            if(p1->val < x)
                p2->next = new ListNode(p1->val), p2 = p2->next, p1->val = -101;
            p1 = p1->next;
        }
        
        p1 = head;
        
        while(p1) {
            if(p1->val != -101)
                p2->next = new ListNode(p1->val), p2 = p2->next;
            p1 = p1->next;
        }
        
        return sent->next;
    }
};
