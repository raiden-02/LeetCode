/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
    let cur: ListNode | null = head;
    let prev: ListNode | null = null;
    let prev_crit: ListNode | null = null;
    let first_crit: ListNode | null = null;
    let first_crit_idx: number = 0;
    let prev_crit_idx: number = 0;
    let cur_idx: number = 0;
    let minDist: number = Infinity;

    while (cur !== null) {
        if (prev !== null && cur.next !== null) {
            if ((cur.val > prev.val && cur.val > cur.next.val) ||
                (cur.val < prev.val && cur.val < cur.next.val)) {
                if (first_crit === null) {
                    first_crit = cur;
                    first_crit_idx = cur_idx;
                } else {
                    minDist = Math.min(minDist, cur_idx - prev_crit_idx);
                }
                prev_crit = cur;
                prev_crit_idx = cur_idx;
            }
        }

        prev = cur;
        cur = cur.next;
        cur_idx += 1;
    }

    if (minDist === Infinity) return [-1, -1];
    return [minDist, prev_crit_idx - first_crit_idx];
};
