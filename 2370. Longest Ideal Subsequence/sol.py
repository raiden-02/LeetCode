class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp = [0 for _ in range(26)]
        n = len(s)

        for i in range(n):
            ind = ord(s[i]) - ord('a')
            maxind = float('-inf')

            left, right = max(ind - k, 0), min(ind + k, 25)

            for j in range(left, right + 1):
                maxind = max(maxind, dp[j])
            
            dp[ind] = maxind + 1
        

        return max(dp)
