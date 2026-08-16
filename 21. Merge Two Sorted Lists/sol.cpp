//sol 1
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *ans = new ListNode();
        ListNode *res = ans;
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val < temp2->val) {
                res->next = temp1;
                temp1 = temp1->next;
            }
            else {
                res->next = temp2;
                temp2 = temp2->next;
            }
            res = res->next;
        }
        while(temp1 != NULL) {
            res->next = temp1;
            res = res->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            res->next = temp2;
            res = res->next;
            temp2 = temp2->next;
        }
        return ans->next;
    }
};

//sol 2 pq
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        if(l1)
            pq.push({l1->val, l1});
        
        if(l2)
            pq.push({l2->val, l2});
        
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            tmp->next = cur.second;
            tmp = tmp->next;
            
            if(cur.second->next)
                pq.push({cur.second->next->val, cur.second->next});
        }
        
        return ans->next;
    }
};
