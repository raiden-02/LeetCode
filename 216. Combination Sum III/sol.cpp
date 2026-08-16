class Solution {
    vector<vector<int>> ans;
    
    void helper(int k, int n, vector<int> &tmp, int ind) {
        if(k == 0 and n == 0) {
            ans.push_back(tmp);
            return;
        }
        
        if(k < 0 or n < 0)
            return;
        
        int prev = -1;
        
        for(int i = ind; i <= 9; i++) {
            if(prev == i) continue;
            
            if(k - 1 >= 0 and n - i >= 0) {
                tmp.push_back(i);
                helper(k - 1, n - i, tmp, i + 1);
                tmp.pop_back();
            }
            
            prev = i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        helper(k, n, tmp, 1);
        return ans;
    }
};
