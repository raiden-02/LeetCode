class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s) // 2
        a, b = 0, 0
        for i in s[:n]:
            if i.lower() in "aeiou":
                a += 1
        for i in s[n:]:
            if i.lower() in "aeiou":
                b += 1
        return a == b
