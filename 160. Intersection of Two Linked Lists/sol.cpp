/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        int la = 0, lb = 0;
        
        while(a) {
            la++;
            a = a->next;
        }
        
        while(b) {
            lb++;
            b = b->next;
        }
        
        a = headA; b = headB;
        if(la > lb) {
            int d = la - lb;
            while(d--)
                a = a->next;
        }
        
        else if(lb > la) {
            int d = lb - la;
            while(d--)
                b = b->next;
        }
        
        while(a && b) {
            if(a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};
