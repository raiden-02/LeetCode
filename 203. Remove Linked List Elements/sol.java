/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode sent = new ListNode(-1, head), ptr = head, prev = sent;
        
        while(ptr != null) {
            if(ptr.val == val)
                prev.next = ptr.next;
            else
                prev = prev.next;
            
            ptr = ptr.next;
        }
        
        return sent.next;
    }
}
