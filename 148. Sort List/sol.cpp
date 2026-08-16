//merge sort
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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* lp = left, *rp = right, *ret = new ListNode(), *rtp = ret;
        
        while(lp and rp) {
            if(lp->val < rp->val)
                rtp->next = lp, lp = lp->next;
            
            else
                rtp->next = rp, rp = rp->next;
            
            rtp = rtp->next;
        }
        
        while(lp)
            rtp->next = lp, lp = lp->next, rtp = rtp->next;
        
        while(rp)
            rtp->next = rp, rp = rp->next, rtp = rtp->next;
        
        return ret->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(not head or not head->next) return head;
        
        ListNode* slow = head, *fast = head, *prev = nullptr;
        
        while(fast and fast->next)
            prev = slow, slow = slow->next, fast = fast->next->next;
        
        prev->next = nullptr;
        
        ListNode* left = sortList(head), *right = sortList(slow);
        
        return merge(left, right);
    }
};

//extra memory
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
    ListNode* sortList(ListNode* head) {
        if(not head)
            return nullptr;
        
        ListNode* tmp = head;
        vector<int> ans;
        
        while(tmp) {
            ans.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        sort(ans.begin(), ans.end());
        
        int i = 0;
        for(tmp = head; tmp; tmp = tmp->next)
            tmp->val = ans[i++];
        
        return head;
    }
};
