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
    Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
    
    public boolean checkEqualTree(TreeNode root) {
        int total = helper(root);
        
        if(total == 0)
            return mp.getOrDefault(total, 0) > 1;
        
        return total % 2 == 0 && mp.containsKey(total / 2);
    }
    
    public int helper(TreeNode root) {
        if(root == null)
            return 0;
        
        int s = root.val + helper(root.left) + helper(root.right);
        
        mp.put(s, mp.getOrDefault(s, 0) + 1);
        
        return s;
    }
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
