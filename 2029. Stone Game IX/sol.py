class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt0: int = 0
        cnt1: int = 0
        cnt2: int = 0

        for stone in stones:
            if stone % 3 == 0:
                cnt0 += 1
            
            elif stone % 3 == 1:
                cnt1 += 1
            
            elif stone % 3 == 2:
                cnt2 += 1
        
        if cnt0 % 2 == 0:
            return cnt1 > 0 and cnt2 > 0
        
        return abs(cnt1 - cnt2) > 2
