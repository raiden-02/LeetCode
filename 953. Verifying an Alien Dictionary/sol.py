class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        mp = {order[i] : i for i in range(len(order))}
        
        def helper(first, second):
            maxl = len(max(first, second, key = len))
            
            for i in range(maxl):
                a = mp[first[i]] if i < len(first) else -2
                b = mp[second[i]] if i < len(second) else -1
                
                if a < b:
                    return True
                elif a > b:
                    return False
            
            return True if len(first) <= len(second) else False
        
        for i in range(1, len(words)):
            if not helper(words[i - 1], words[i]):
                return False
        return True
