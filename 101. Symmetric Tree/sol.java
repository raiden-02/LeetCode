/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private boolean helper(TreeNode x, TreeNode y) {
        if(x != null && y != null)
            return x.val == y.val && helper(x.left, y.right) && helper(x.right, y.left);
        if(x != null || y != null)
            return false;
        return true;
    }
    
    public boolean isSymmetric(TreeNode root) {
        return helper(root, root);
    }
}
