class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        combined_counter = Counter(s1.split() + s2.split())
        
        return [word for word, count in combined_counter.items() if count == 1]
