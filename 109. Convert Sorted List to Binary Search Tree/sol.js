/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @return {TreeNode}
 */
var sortedListToBST = function(head) {
    let helper = (arr, l, r) => {
        if(l > r) return undefined;

        let mid = (l + r) >> 1;
        let nn = new TreeNode(arr[mid], helper(arr, l, mid - 1), helper(arr, mid + 1, r));
        return nn;
    }

    if(head == null) return null;

    const arr = [];

    for(let tmp = head; tmp != null; tmp = tmp.next) {
        arr.push(tmp.val);
    }

    return helper(arr, 0, arr.length - 1);
};
