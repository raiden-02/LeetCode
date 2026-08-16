#python solution
class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        wordset = set(wordlist)
        cap = defaultdict(str)
        vow = defaultdict(str)
        
        for word in wordlist:
            if word.upper() not in cap:
                cap[word.upper()] = word
            
            encode = ''.join(['.' if x.lower() in "aeiou" else x.upper() for x in word])
            if encode not in vow:
                vow[encode] = word
                
        
        ans = []
        for i in queries:
            t = ""
            if(i in wordset):
                t = i
            elif(i.upper() in cap):
                t = cap[i.upper()]
            else:
                encode = ''.join(['.' if x.lower() in "aeiou" else x.upper() for x in i])
                if encode in vow:
                    t = vow[encode]
            
            ans.append(t)
        
        return ans
//c++ solution
