class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<vector<int>> ans;
        
        /*points a, b, c
        slope(b, a) - slope(c - b) = orientation
        b[1] - a[1]   c[1] - b[1]
        ----------- - ------------ > 0 (anti clock), < 0 (clock), = 0(linear)
        b[0] - a[0]   c[0] - b[0]
        
        =>  (b[1] - a[1]) * (c[0] - b[0]) - (c[1] - b[1]) * (b[0] - a[0])
        denominator goes to rhs and gets mulitplied by 0 so its not required
        */
        
        auto orientation = [](vector<int> &a, vector<int> &b, vector<int> &c) {
            return (b[1] - a[1]) * (c[0] - b[0]) - (c[1] - b[1]) * (b[0] - a[0]);
        };
        
        sort(trees.begin(), trees.end());
        
        for(int i = 0; i < n; i++) {
            while(ans.size() > 1 and orientation(ans[ans.size() - 2], ans.back(), trees[i]) < 0)
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        
        if(ans.size() == n) return ans;
        
        for(int i = n - 2; i >= 0; i--) {
            while(ans.size() > 1 and orientation(ans[ans.size() - 2], ans.back(), trees[i]) < 0)
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        
        ans.pop_back();
        
        return ans;
    }
};
