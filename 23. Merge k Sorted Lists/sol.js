/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
const mergeKLists = function(lists) {
  const pq = new MinPriorityQueue({ priority: x => x.val })
  let ans = new ListNode()
  const head = ans

  for (const head of lists) {
    if (head) {
      pq.enqueue(head)
    }
  }

  

  while (!pq.isEmpty()) {
    const { val, next } = pq.dequeue().element

    ans.next = new ListNode(val)
    ans = ans.next

    if (next) {
      pq.enqueue(next)
    }
  }

  return head.next
}
