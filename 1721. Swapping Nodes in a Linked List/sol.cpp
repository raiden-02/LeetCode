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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head, *end = head, *fast = head;
        int cnt = 1;

        while(start && cnt < k) {
            start = start->next;
            fast = fast->next;
            cnt++;
        }

        while(fast && fast->next) {
            fast = fast->next;
            end = end->next;
        }

        if(start && end) {
            swap(start->val, end->val);
        }

        return head;
    }
};
