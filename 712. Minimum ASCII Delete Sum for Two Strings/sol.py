class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        
        @lru_cache(None)
        def helper(si, pi):
            if(si == m and pi == n):
                return 0
            
            if(si != m and pi == n):
                return sum(ord(c) for c in s1[si:])
            
            if(si == m and pi != n):
                return sum(ord(c) for c in s2[pi:])
            
            if(s1[si] == s2[pi]):
                return helper(si + 1, pi + 1)
            
            return min(helper(si + 1, pi) + ord(s1[si]), helper(si, pi + 1) + ord(s2[pi]))
        
        return helper(0, 0)
