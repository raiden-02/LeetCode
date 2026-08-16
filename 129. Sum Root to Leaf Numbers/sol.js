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
 * @return {number}
 */
var sumNumbers = function(root) {
    let ans = 0;
    let helper = function(root, s) {
        if(root == null) return;

        if(root.left == null && root.right == null) {
            ans += s * 10 + root.val;
            return;
        }

        helper(root.left, s * 10 + root.val);
        helper(root.right, s * 10 + root.val);
    }
    
    helper(root, 0);
    return ans;
};
