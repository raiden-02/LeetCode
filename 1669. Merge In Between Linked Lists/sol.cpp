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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail2 = list2;
        while(tail2->next) tail2 = tail2->next;
        ListNode* ptr = list1, *pp = list1, *pn = nullptr;

        for(int i = 0; i <= b && ptr; i++, ptr = ptr->next) {
            if(i == a - 1) pp = ptr;
            if(i == b) pn = ptr->next; 
        }
        pp->next = list2;
        tail2->next = pn;

        return list1;
    }
};
