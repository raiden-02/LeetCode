/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

var isCompleteTree = function(root) {
    let q = [root];
    let prev = false;

    while(q.length != 0) {
        const cur = q.shift();
        
        if(!cur) {
            prev = true;
            continue;
        }

        if(prev) return false;

        q.push(cur.left, cur.right);
    }

    return true;
};
