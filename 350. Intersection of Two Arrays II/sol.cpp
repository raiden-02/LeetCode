class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> m1, m2;
        vector<int> ans;
        
        for(int x : nums1) m1[x]++;
        for(int x : nums2) m2[x]++;
        
        for(auto &x : m1) {
            auto it = m2.find(x.first);
            
            if(it != m2.end()) {
                int len = min(x.second, it->second);
                
                for(int i = 0; i < len; i++)
                    ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};
