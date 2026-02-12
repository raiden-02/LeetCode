public class Solution {
    public int LongestBalanced(string s) {
        int n = s.Length;
        int[][] pref = new int[n + 1][];
        pref[0] = new int[26];

        for (int i = 0; i < n; i++) {
            pref[i + 1] = (int[])pref[i].Clone();
            pref[i + 1][s[i] - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int target = 0;
                bool ok = true;

                for (int c = 0; c < 26; c++) {
                    int cnt = pref[j][c] - pref[i][c];
                    if (cnt == 0) continue;

                    if (target == 0) target = cnt;
                    else if (cnt != target) { ok = false; break; }
                }

                if (ok) ans = Math.Max(ans, j - i);
            }
        }

        return ans;
    }
}
