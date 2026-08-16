#recur with memo
class Solution:
    def bestTeamScore(self, w: List[int], a: List[int]) -> int:
        n = len(a)
        arr = [(a[i], w[i]) for i in range(n)]
        arr.sort()
        arr.insert(0, (-1, -1))
        cache = [[-1] * (n + 1) for _ in range(n + 1)]
        
        def helper(ind, prev):
            if ind >= (n + 1):
                return 0
            
            if(cache[prev][ind] != -1):
                return cache[prev][ind]
            
            if arr[ind][1] < arr[prev][1]:
                ans = helper(ind + 1, prev)
                cache[prev][ind] = ans
                return ans
            
            ans = max(helper(ind + 1, ind) + arr[ind][1], helper(ind + 1, prev)) 
            cache[prev][ind] = ans
            return ans

        return helper(1, 0)

#bottom up

# --- alternate solution ---

class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(ages)
        dp = [0] * n
        arr = [(ages[i], scores[i]) for i in range(n)]
        arr.sort()
        ans = 0
        
        for i in range(n):
            dp[i] = arr[i][1]
            
            for j in range(i):
                
                if(arr[j][1] <= arr[i][1]):
                    dp[i] = max(dp[j] + arr[i][1], dp[i])
                    
            ans = max(dp[i], ans)
        
        return ans
