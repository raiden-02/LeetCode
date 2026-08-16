class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if(k == 0): 
            return num
        
        if(k >= len(num)):
            return "0"

        st = []

        for x in num:
            while(len(st) > 0 and k > 0 and st[-1] > x):
                st.pop()
                k -= 1
            
            st.append(x)

            if(len(st) == 1 and st[-1] == '0'):
                st.pop()
        
        while(k > 0 and len(st) > 0):
            st.pop()
            k -= 1
        
        ans = ''.join(st)

        return "0" if len(ans) == 0 else ans
