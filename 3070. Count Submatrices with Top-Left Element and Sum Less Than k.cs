public class Solution {
    public int CountSubmatrices(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length, ans = 0;
        int[,] prefix = new int[m + 1, n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i, j] = grid[i - 1][j - 1]
                            + prefix[i - 1, j]
                            + prefix[i, j - 1]
                            - prefix[i - 1, j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = prefix[i + 1, j + 1];

                if (sum <= k) ans += 1;
            }
        }

        return ans;
    }
}
