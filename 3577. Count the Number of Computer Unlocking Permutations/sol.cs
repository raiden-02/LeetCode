public class Solution {
    private const int MAX_N = 100_000;
    private const int MOD   = 1_000_000_007;
    private static readonly int[] fact = new int[MAX_N + 1];

    static Solution() {
        fact[0] = 1;
        for (int i = 1; i <= MAX_N; i++)
            fact[i] = (int)((long)fact[i - 1] * i % MOD);
    }

    public int CountPermutations(int[] complexity) {
        int n = complexity.Length;
        int root = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= root) {
                return 0;
            }
        }

        return fact[n - 1];
    }
}
