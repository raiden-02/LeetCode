/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode* slow = head, *fast = head;

        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        slow = head;

        while(slow && fast && slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

// # Definition for singly-linked list.
// # class ListNode:
// #     def __init__(self, x):
// #         self.val = x
// #         self.next = None

// class Solution:
//     def detectCycle(self, head: ListNode) -> ListNode:
//         if(not head or not head.next):
//             return None
        
//         slow = head
//         fast = head
//         f = False
        
//         #find intersection
//         while(slow and fast):
//             slow = slow.next
//             if(fast.next):
//                 fast = fast.next.next
//             else:
//                 return None
//             if(slow == fast):
//                 f = True
//                 break
        
//         if(not f):
//             return None
        
//         #find entrance of the cycle
//         slow = head
//         while(slow != fast):
//             slow = slow.next
//             fast = fast.next
        
//         return slow
