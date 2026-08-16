class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        ans = []
        
        def valid(s):
            return s == s[::-1]
        
        def helper(start, cur):
            if(start >= n):
                ans.append(cur)
                return
            
            for i in range(start, n):
                left = s[start : i + 1]
                #print(left)
                
                if(valid(left)):
                    helper(i + 1, cur + [left])
                
        helper(0, [])
        return ans
