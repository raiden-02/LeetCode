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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        
        while(tmp)
            n++, tmp = tmp->next;
        
        vector<ListNode*> ans(k, nullptr);
        tmp = head;
        
        int len = n / k, rem = n % k;
        ListNode* prev = nullptr;
        
        for(int i = 0; tmp and i < k; i++, rem--) {
            ans[i] = tmp;
            
            for(int j = 0; j < len + (rem > 0) and tmp; j++) {
                prev = tmp;
                tmp = tmp->next;
            }
            
            prev->next = nullptr;
        }
        
        return ans;
    }
};
