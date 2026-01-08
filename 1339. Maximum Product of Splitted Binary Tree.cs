public class Solution
{
    private const int MOD = 1_000_000_007;
    private long best = 0;

    private long TotalSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + TotalSum(root.left) + TotalSum(root.right);
    }

    private long Dfs(TreeNode node, long total) {
        if (node == null) return 0;

        long left = Dfs(node.left, total);
        long right = Dfs(node.right, total);

        long sub = node.val + left + right;

        best = Math.Max(best, sub * (total - sub));

        return sub;
    }

    public int MaxProduct(TreeNode root) {
        long total = TotalSum(root);
        Dfs(root, total);
        return (int)(best % MOD);
    }
}
