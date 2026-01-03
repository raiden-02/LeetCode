public class Solution {
    private readonly int[,,,] _dp = new int[5001, 4, 4, 4];
    private const int Mod = 1_000_000_007;

    private int Helper(int n, int ind, int a, int b, int c) {
        if (ind >= n)
            return 1;

        if (_dp[ind, a, b, c] != -1)
            return _dp[ind, a, b, c];

        long ans = 0;

        for (int i = 1; i <= 3; i++) {
            if (i == a) continue;

            for (int j = 1; j <= 3; j++) {
                if (j == i || j == b) continue;

                for (int k = 1; k <= 3; k++) {
                    if (k == j || k == c) continue;

                    ans = (ans + Helper(n, ind + 1, i, j, k)) % Mod;
                }
            }
        }

        return _dp[ind, a, b, c] = (int)ans;
    }

    public int NumOfWays(int n) {
        System.Runtime.InteropServices.MemoryMarshal.CreateSpan(ref _dp[0, 0, 0, 0], _dp.Length).Fill(-1);
        
        return Helper(n, 0, 0, 0, 0);
    }
}
