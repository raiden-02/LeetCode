class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        ans = []

        @lru_cache(None)
        def helper(s):
            if(len(s) == n):
                ans.append(int(s))
                return

            last = int(s[-1])

            if(last + k < 10):
                helper(s + str(last + k))

            if(last - k >= 0):
                helper(s + str(last - k))

        for i in range(1, 10):
            helper(str(i))

        return ans
