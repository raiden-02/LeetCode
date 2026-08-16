public class Solution {
    private const int MOD = 1_000_000_007;
    private int[,,,] memo;

    private int Helper(int zero, int one, int prev, int cnt, int limit) {
        if (zero < 0 || one < 0) return 0;
        if (zero == 0 && one == 0) return 1;

        if (memo[zero, one, prev, cnt] != -1)
            return memo[zero, one, prev, cnt];

        long ans = 0;

        if (prev == 0) {
            if (cnt < limit) ans += Helper(zero - 1, one, 0, cnt + 1, limit);
            ans += Helper(zero, one - 1, 1, 1, limit);
        }

        else {
            if (cnt < limit) ans += Helper(zero, one - 1, 1, cnt + 1, limit);
            ans += Helper(zero - 1, one, 0, 1, limit);
        }

        return memo[zero, one, prev, cnt] = (int)(ans % MOD);
    }

    public int NumberOfStableArrays(int zero, int one, int limit) {
        memo = new int[zero + 1, one + 1, 2, limit + 1];
        for (int i = 0; i <= zero; i++)
            for (int j = 0; j <= one; j++)
                for (int p = 0; p < 2; p++)
                    for (int c = 0; c <= limit; c++)
                        memo[i, j, p, c] = -1;
                        
        long ans = 0;
        ans += Helper(zero - 1, one, 0, 1, limit);
        ans += Helper(zero, one - 1, 1, 1, limit);
        
        return (int)(ans % MOD);
    }
}
