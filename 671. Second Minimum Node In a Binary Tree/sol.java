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
    private boolean flag = false;
    private int ans = Integer.MAX_VALUE;
    
    private void helper(int m, TreeNode root) {
        if(root == null)
            return;
        
        if(root.val > m && root.val <= ans) {
            ans = root.val;
            flag = true;
        }
        
        helper(m, root.left);
        helper(m, root.right);
    }
    
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null || (root.left == null && root.right == null))
            return -1;
        
        helper(root.val, root);
        
        if(!flag) return -1;
        return ans;
    }
}
