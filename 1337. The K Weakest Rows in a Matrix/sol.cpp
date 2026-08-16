class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if(mat.empty() || mat[0].empty())
            return {};
        
        multimap<int, int> f2i;
        int m = mat.size(), n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            int c = 0;
            for(int &x : mat[i]) {
                if(x != 1)
                    break;
                c += 1;
            }
            f2i.emplace(c, i);
        }
        vector<int> ans;
        int i = 0;
        for(auto it = f2i.begin(); i < k && it != f2i.end(); it++, i++)
            ans.push_back(it->second);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < mat[0].size(); j++) if(mat[i][j]) cnt++;
            
            pq.push({cnt, i});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        
        while(not pq.empty()) ans.push_back(pq.top().second), pq.pop();
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
