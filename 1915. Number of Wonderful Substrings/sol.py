class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        ans = 0
        mp = defaultdict(int)
        mp[0] = 1
        mask = 0

        for x in word:
            loc = ord(x) - ord('a')
            mask ^= 1 << loc
            ans += mp[mask] #all even

            for i in range(10):
                premask = mask ^ (1 << i) #flipping 1 bit (odd to even or even to odd)
                ans += mp[premask] #at most 1 odd
            
            mp[mask] += 1
        
        return ans
