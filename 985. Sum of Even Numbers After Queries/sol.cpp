class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        vector<int> ans;
        
        for(int x : nums) 
            if(x % 2 == 0) s += x;
        
        for(auto &query : queries) {
            int prev = nums[query[1]];
            nums[query[1]] += query[0];
            int nval = nums[query[1]];
            
            if(prev % 2 == 0 and nval % 2 == 0)
                s += query[0];
            
            else if(prev % 2 == 0 and nval % 2)
                s -= prev;
            
            else if(prev % 2 and nval % 2 == 0)
                s += nval;
            
            ans.push_back(s);
        }
        
        return ans;
    }
};
