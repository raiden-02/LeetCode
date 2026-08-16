class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        sc = sum(chalk)

        k = k % sc

        for i in range(len(chalk)):
            if chalk[i] > k:
                return i
            k -= chalk[i]
        
        return -1
