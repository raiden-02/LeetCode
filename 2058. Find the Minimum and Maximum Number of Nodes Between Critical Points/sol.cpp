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
    const int MAXM = numeric_limits<int>::max();
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mind = MAXM, maxd = -1;
        int curpos = 0, prevpos = -1;
        int cstart = -1, cend = -1;

        for(ListNode* ptr = head; ptr; ptr = ptr->next, curpos++) {
            if(ptr->next && ptr->next->next) {
                int mid = ptr->next->val;
                int prev = ptr->val;
                int next = ptr->next->next->val;

                if((mid > prev && mid > next) || (mid < prev && mid < next)) {
                    if(cstart == -1) {
                        cstart = cend = curpos + 1;
                        prevpos = curpos + 1;
                    }

                    else {
                        mind = min(curpos + 1 - prevpos, mind);
                        prevpos = curpos + 1;
                        cend = curpos + 1;
                    }
                }
            }
        }

        maxd = cend - cstart;

        if(mind <= 0 || maxd <= 0) return {-1, -1};

        return {mind, maxd};
    }
};
