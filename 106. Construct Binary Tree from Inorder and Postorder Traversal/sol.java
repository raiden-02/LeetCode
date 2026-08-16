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
    private int ind;
    private Map<Integer, Integer> mp;
    
    private TreeNode helper(int[] inorder, int[] postorder, int l, int r) {
        if(l > r) return null;
        
        int val = postorder[ind];
        TreeNode root = new TreeNode(val);
        int p = mp.get(val);
        ind--;
        
        root.right = helper(inorder, postorder, p + 1, r);
        root.left = helper(inorder, postorder, l, p - 1);
        
        return root;
    }
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        ind = postorder.length - 1;
        mp = new HashMap<>();
        
        for(int i = 0; i < inorder.length; i++) 
            mp.put(inorder[i], i);
        
        return helper(inorder, postorder, 0, inorder.length - 1);
    }
}

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
