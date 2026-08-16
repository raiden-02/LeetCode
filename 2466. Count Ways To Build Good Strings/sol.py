# Memoization/Top Down
class Solution:
    
    MOD = int(1e9 + 7)

    def helper(self, low: int, high: int, zero: int, one: int, dp, length: int) -> int:
        if(length > high):
            return 0
        
        if(dp[length] != -1):
            return dp[length]

        ans = 0

        if(low <= length <= high):
            ans += 1
        
        if(one + length <= high):
            ans += self.helper(low, high, zero, one, dp, length + one)
        
        if(zero + length <= high):
            ans += self.helper(low, high, zero, one, dp, length + zero)
        
        dp[length] = ans % Solution.MOD
        return dp[length]

    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp = [-1] * (high + 1)
        return self.helper(low, high, zero, one, dp, 0)
        

# Bottom Up

# --- alternate solution ---

class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = int(1e9 + 7)
        dp = [0] * (high + 1)
        
        dp[0] = 1
        
        for length in range(1, high + 1):
            if length - zero >= 0:
                dp[length] += dp[length - zero]
            
            if length - one >= 0:
                dp[length] += dp[length - one]
            
            dp[length] %= MOD
        
        ans = 0
        for length in range(low, high + 1):
            ans += dp[length]
            ans %= MOD
        
        return ans
