class Solution {
    private List<Integer> ans = new ArrayList<Integer>();
    private void helper(TreeNode root) {
        if(root == null)
            return;
        
        helper(root.left);
        ans.add(root.val);
        helper(root.right);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        helper(root);
        return ans;
    }
}
