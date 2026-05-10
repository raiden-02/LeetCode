public class Solution {
    public int[][] RotateGrid(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int sr = 0, er = m - 1, sc = 0, ec = n - 1;

        Console.WriteLine(sr + " " + er + " " + sc + " " + ec);

        while (sr < er && sc < ec) {
            List<int> tmp = new List<int>();

            // top row
            for (int j = sc; j <= ec; j++) {
                tmp.Add(grid[sr][j]);
            }

            // right column
            for (int i = sr + 1; i <= er; i++) {
                tmp.Add(grid[i][ec]);
            }

            // bottom row
            for (int j = ec - 1; j >= sc; j--) {
                tmp.Add(grid[er][j]);
            }

            // left column
            for (int i = er - 1; i > sr; i--) {
                tmp.Add(grid[i][sc]);
            }

            int len = tmp.Count;

            int[] rotated = new int[len];

            for (int i = 0; i < len; i++) {
                rotated[i] = tmp[(i + k) % len];
            }

            int ti = 0;

            // top row
            for (int j = sc; j <= ec; j++) {
                grid[sr][j] = rotated[ti++];
            }

            // right column
            for (int i = sr + 1; i <= er; i++) {
                grid[i][ec] = rotated[ti++];
            }

            // bottom row
            for (int j = ec - 1; j >= sc; j--) {
                grid[er][j] = rotated[ti++];
            }

            // left column
            for (int i = er - 1; i > sr; i--) {
                grid[i][sc] = rotated[ti++];
            }

            sr++;
            sc++;
            er--;
            ec--;
        }

        return grid;
    }
}
