class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        if(words.find(endWord) == words.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                string cur = q.front(); q.pop();
                if(cur == endWord)
                    return ans;
                words.erase(cur);
            
                for(int i = 0; i < cur.length(); i++) {
                    for(char x = 'a'; x <= 'z'; x++) {
                        char c = cur[i];
                    
                        if(x == c)
                            continue;
                    
                        cur[i] = x;
                    
                        if(endWord == cur)
                            return ans + 1;
                    
                        else if(words.find(cur) != words.end())
                            q.push(cur), words.erase(cur);
                    
                        cur[i] = c;
                    }
                }
            }
            ans++;
        }
        
        return 0;
    }
};
