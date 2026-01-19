public class Solution {
    public int MaxSideLength(int[][] mat, int threshold) {
        int m = mat.Length, n = mat[0].Length;
        int ans = 0;

        for (int i = 1; i < m; i++) mat[i][0] += mat[i - 1][0];
        for (int j = 1; j < n; j++) mat[0][j] += mat[0][j - 1];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }

        for (int len = 1; len <= Math.Min(m, n); len++) {
            bool f = false;

            for (int i = len - 1; i < m; i++) {

                for (int j = len - 1; j < n; j++) {
                    int a = j - len >= 0 ? mat[i][j - len] : 0;
                    int b = i - len >= 0 ? mat[i - len][j] : 0;
                    int c = i - len >= 0 && j - len >= 0 ? mat[i - len][j - len] : 0;
                    int s =  mat[i][j] - a - b + c;

                    if (s <= threshold) {
                        ans = Math.Max(ans, len);
                        f = true;
                    }

                    if (f) break;
                }

                if (f) break;
            }
        }

        return ans;
    }
}
