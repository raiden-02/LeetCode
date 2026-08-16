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
    void reorderList(ListNode* head) {
        if(!head->next) return;

        vector<ListNode*> arr;

        for(ListNode* tmp = head; tmp; tmp = tmp->next) {
            arr.push_back(tmp);
        }

        ListNode* prev = nullptr;
        int l = 0, r = arr.size() - 1;

        for(; l < r; l++, r--) {
            if(prev) prev->next = arr[l];
            arr[l]->next = arr[r];
            arr[r]->next = nullptr;
            prev = arr[r];
        }

        if(l == r) prev->next = arr[r], arr[r]->next = nullptr;
    }
};
