class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans = {0};
        
        while(ans.size() <= num) {
            vector<int> tmp;
            for(int &x : ans)
                tmp.push_back(x + 1);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        
        return vector<int>(ans.begin(), ans.begin() + num + 1);
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0};
        
        while(ans.size() <= n) {
            int len = ans.size();
            
            for(int i = 0; i < len && ans.size() <= n; i++)
                ans.push_back(ans[i] + 1);
        }
        
        return ans;
    }
};
