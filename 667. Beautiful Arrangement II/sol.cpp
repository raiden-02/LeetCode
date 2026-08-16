class Solution {
public:
    vector<int> constructArray(int n, int k) {
        unordered_set<int> vis = {1};
        vector<int> ans = {1};
        int prev = 1;
        bool f = true;
        
        while(k != 0) {
            if(f) {
                ans.push_back(prev + k);
                vis.insert(prev + k);
                prev = prev + k;
                f = false;
            }
            
            else {
                ans.push_back(prev - k);
                vis.insert(prev - k);
                prev = prev - k;
                f = true;
            }
            
            k -= 1;
        }
        
        for(int i = 2; i <= n; i++) {
            if(vis.find(i) == vis.end())
                ans.push_back(i);
        }
        
        return ans;
    }
};
