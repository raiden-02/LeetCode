class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lm, ans = float('inf'), 0
        
        for i in prices:
            lm = min(lm, i)
            ans = max(ans, i - lm)
            
        return ans
