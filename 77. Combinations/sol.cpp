class Solution {
    vector<vector<int>> ans;
    
    void helper(int const& n, int k, vector<int> &tmp, int ind) {
        if(k == 0) {
            ans.push_back(tmp);
            return;
        }
        
        if(k - 1 < 0 || ind > n)
            return;
        
        for(int i = ind; i <= n; i++) {
            tmp.push_back(i);
            
            helper(n, k - 1, tmp, i + 1);
            
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        helper(n, k, tmp, 1);
        
        return ans;
    }
};
