class Solution {
    private List<Integer> ans = new ArrayList<Integer>();
    private void helper(TreeNode root) {
        if(root == null)
            return;
        ans.add(root.val);
        helper(root.left);
        helper(root.right);
    }
    
    public List<Integer> preorderTraversal(TreeNode root) {
        helper(root);
        return ans;
    }
}
