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
    int pairSum(ListNode* head) {
        vector<int> arr;
        int ans = 0;
        
        for(ListNode* ptr = head; ptr; ptr = ptr->next) {
            arr.push_back(ptr->val);
        }

        int n = arr.size();
        int mid = n % 2 ? (n / 2) + 1 : n / 2;

        for(int i = 0; i < n / 2; i++) {
            ans = max(ans, arr[i] + arr[n - i - 1]);
        }

        return ans;
    }
};
