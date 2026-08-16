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
    private int s = 0;
    
    private void helper(TreeNode root) {
        if(root == null) return;
        
        if(root.left != null) {
            if(root.left.left == null && root.left.right == null)
                s += root.left.val;
        }
        
        //else s += root.val;
        
        helper(root.left);
        helper(root.right);
    }
    public int sumOfLeftLeaves(TreeNode root) {
        helper(root);
        return s;
    }
}
