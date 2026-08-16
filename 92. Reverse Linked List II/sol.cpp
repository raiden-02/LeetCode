//ez method
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vec;
        ListNode *cur = head;
        int i = 1;
        
        for(; i < left and cur; i++, cur = cur->next);
        
        for(; i <= right and cur; i++, cur = cur->next) vec.push_back(cur->val);
        
        reverse(vec.begin(), vec.end());
        
        int ind = 0;
        i = 1, cur = head;
        
        for(; i < left and cur; i++, cur = cur->next);
        
        for(; i <= right and cur; i++, cur = cur->next) cur->val = vec[ind++];
        
        return head;
    }
};

//pointer method
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(not head) return head;
        
        ListNode *cur = head, *sent = nullptr;
        
        for(int i = 1; i < left; i++)
            sent = cur, cur = cur->next; 
        
        ListNode *tail = cur, *nex = nullptr, *prev = sent;
        
        for(int i = 1; i <= right - left + 1; i++) {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        if(sent)
            sent->next = prev;
        else 
            head = prev;
        
        tail->next = nex;
        
        return head;
    }
};
