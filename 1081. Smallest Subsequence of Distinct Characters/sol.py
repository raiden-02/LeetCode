class Solution:
    def smallestSubsequence(self, s: str) -> str:
        st = []
        mp = Counter(s)
        vis = defaultdict(bool)
        
        for i in s:
            mp[i] -= 1
            
            if(vis[i]): continue
            
            while st and i < st[-1] and mp[st[-1]]:
                vis[st.pop()] = False
            
            st.append(i)
            vis[i] = True
        
        return ''.join(st)
