public class Solution
{
    private static void RayFill(int si, int sj, int di, int dj, int[,] grid, int m, int n)
    {
        int i = si + di, j = sj + dj;
        while (i >= 0 && i < m && j >= 0 && j < n && (grid[i, j] == 0 || grid[i, j] == 2))
        {
            grid[i, j] = 2;     // 2 = seen/guarded
            i += di;
            j += dj;
        }
    }

    public int CountUnguarded(int m, int n, int[][] guards, int[][] walls)
    {
        var grid = new int[m, n]; // 0 empty, 1 guard, -1 wall, 2 guarded

        foreach (var w in walls)  grid[w[0], w[1]] = -1;
        foreach (var g in guards) grid[g[0], g[1]] =  1;

        // Cast rays from each guard
        foreach (var g in guards)
        {
            int i = g[0], j = g[1];
            RayFill(i, j,  1,  0, grid, m, n);
            RayFill(i, j, -1,  0, grid, m, n);
            RayFill(i, j,  0,  1, grid, m, n);
            RayFill(i, j,  0, -1, grid, m, n);
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i, j] == 0) ans++;

        return ans;
    }
}
