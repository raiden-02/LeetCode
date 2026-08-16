class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
        
        queue<string> q;
        q.push(start);
        int ans = 0;
        unordered_set<string> vis;
        vis.insert(start);
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                string cur = q.front(); q.pop();
                for(string &x : bank) {
                    if(vis.find(x) != vis.end()) continue;
                    int cnt = 0;
                    
                    for(int i = 0; i < 8; i++) {
                        if(cur[i] != x[i]) cnt++;
                        if(cnt > 1) break;
                    }
                    
                    if(cnt == 1) {
                        if(x == end) return ans + 1;
                        else vis.insert(x), q.push(x);
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};
