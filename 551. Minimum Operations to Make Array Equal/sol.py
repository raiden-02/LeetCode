class Solution:
    """
    initial naive:
    [1 3 5 7 9 11]
    avg = 6
    dev = [5 3 1 1 3 5] ans = 9 = 5 + 3 + 1
    [1 3 5]
    avg = 3
    dev = [2 0 2] ans = 2 + 0
    
    optimized (math):
    avg is just n if you look at the pattern, and the fact that avg of the first n odd natural numbers in n
    return sum of ap where d = 2, a = avg - 1 (first deviation), and n = n / 2 (since after that the deviations repeat)
    """
    def minOperations(self, n: int) -> int:
        a = n - 1
        n = n // 2
        return int((n / 2) * (2 * a + (n - 1) * -2))

# --- alternate solution ---

#naive brute force
class Solution:
    """
    [1 3 5 7 9 11]
    avg = 6
    dev = [5 3 1 1 3 5] ans = 9 = 5 + 3 + 1
    [1 3 5]
    avg = 3
    dev = [2 0 2] ans = 2 + 0
    """
    def minOperations(self, n: int) -> int:
        l = [(2 * i + 1) for i in range(n)]
        avg = sum(l) // n
        
        st = set()
        ans = 0
        for i in l:
            k = abs(avg - i)
            if k in st:
                break
            ans += k
            st.add(k)
        
        return ans

#optimized math
