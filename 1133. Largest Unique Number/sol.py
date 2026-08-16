class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        freq = Counter(A)
        ans = -1
        
        for i in A:
            if(freq[i] == 1):
                ans = max(ans, i)
        
        return ans
