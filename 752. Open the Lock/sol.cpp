class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(), deadends.end());
        string start = "0000";
        
        if(vis.find(start) != vis.end())
            return -1;
        
        int ans = 0;
        queue<string> q;
        unordered_map<char, vector<char>> neigh = {{'0', {'9', '1'}}, {'1', {'0', '2'}}, {'2', {'1', '3'}}, {'3', {'2', '4'}}, {'4', {'3', '5'}}, {'5', {'4', '6'}}, {'6', {'5', '7'}}, {'7', {'6', '8'}}, {'8', {'7', '9'}}, {'9', {'8', '0'}}};
        
        q.push(start);
        vis.insert(start);
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                string cur = q.front(); q.pop();
                
                if(cur == target) 
                    return ans;
                
                for(int i = 0; i < 4; i++) {
                    char prev = cur[i];
                    
                    for(char nn : neigh[prev]) {
                        cur[i] = nn;
                        
                        if(cur == target)
                            return ans + 1;
                        
                        if(vis.find(cur) == vis.end())
                            q.push(cur), vis.insert(cur);
                        
                        cur[i] = prev;
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};

// --- alternate solution ---

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(), deadends.end());
        string start = "0000";
        
        if(vis.find(start) != vis.end() or vis.find(target) != vis.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        int ans = 0;
        vis.insert(start);
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                string cur = q.front(); q.pop();
                if(cur == target) return ans;

                for(int i = 0; i < 4; i++) {
                    char prev = cur[i];

                    cur[i] = prev + 1 > '9' ? '0' : prev + 1;
                    if(cur == target) return ans + 1;
                    if(vis.find(cur) == vis.end()) q.push(cur), vis.insert(cur);

                    cur[i] = prev - 1 < '0' ? '9' : prev - 1;
                    if(cur == target) return ans + 1;
                    if(vis.find(cur) == vis.end()) q.push(cur), vis.insert(cur);

                    cur[i] = prev;
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};
