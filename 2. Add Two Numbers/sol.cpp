//more concise version
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2, *ret = new ListNode(), *ans = ret;
        int carry = 0;
        
        while(ptr1 or ptr2) {
            int a = 0, b = 0;
            
            if(ptr1) a = ptr1->val, ptr1 = ptr1->next;
            if(ptr2) b = ptr2->val, ptr2 = ptr2->next;
            
            int s = a + b + carry;
            
            ans->next = new ListNode(s % 10);
            carry = s / 10;
            ans = ans->next;
        }
        
        if(carry) ans->next = new ListNode(carry);
        
        return ret->next;
    }
};


//inital attempt long code
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2;
        ListNode *sen = new ListNode(-1);
        ListNode *ans = sen;
        int carry = 0;
        
        while(t1 && t2) {
            int cur = carry;
            if(t1) {
                cur += t1->val;
                t1 = t1->next;
            }
            if(t2) {
                cur += t2->val;
                t2 = t2->next;
            }
            ans->next = new ListNode(cur % 10);
            ans = ans->next;
            carry = cur / 10;
        }
        
        //cout << carry << endl;
        while(t1) {
            int cur = carry;
            cur += t1->val;
            ans->next = new ListNode(cur % 10);
            ans = ans->next;
            carry = cur / 10;
            t1 = t1->next;
        }
        
        while(t2) {
            int cur = carry;
            cur += t2->val;
            ans->next = new ListNode(cur % 10);
            ans = ans->next;
            carry = cur / 10;
            t2 = t2->next;
        }
        
        while(carry) {
            ans->next = new ListNode(carry % 10);
            carry /= 10;
        }
        return sen->next;
    }
};
