class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if(n < 3):
            return 0
        
        ans = 0
        diff = nums[1] - nums[0]
        dp = [0] * n
        c = 2

        for i in range(2, n):
            cur = nums[i] - nums[i - 1]
            c += 1
            
            if(cur == diff and c >= 3):        
                dp[i] = dp[i - 1] + 1
            
            else:
                diff = cur
                c = 2
            
            ans += dp[i]
        
        return ans
