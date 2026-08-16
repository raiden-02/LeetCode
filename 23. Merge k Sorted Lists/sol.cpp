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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(ListNode* x : lists) {
            ListNode* tmp = x;
            while(tmp != nullptr) {
                pq.push(tmp->val);
                tmp = tmp->next;
            }
        }
        ListNode *ans = new ListNode();
        ListNode *tmp = ans;
        while(!pq.empty()) {
            tmp->next = new ListNode(pq.top());
            tmp = tmp->next;
            pq.pop();
        }
        return ans->next;
    }
};
