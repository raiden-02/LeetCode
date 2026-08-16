class Solution:
    def longestValidParentheses(self, s: str) -> int:
        st = []
        ans = [False for _ in range(len(s))]
        
        for i in range(len(s)):
            if(s[i] == ')' and st != []):
                ans[st.pop()] = ans[i] = True
            
            elif(s[i] == '('):
                st.append(i)
        
        out, c = 0, 0
        for i in ans:
            c = c + 1 if i else 0
            out = max(c, out)
        
        return out
