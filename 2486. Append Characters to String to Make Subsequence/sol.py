class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        si, ti = 0, 0

        while(si < m and ti < n):
            if(s[si] == t[ti]):
                ti += 1
            si += 1
        
        return n - ti
