class Solution {
    vector<int> helper(vector<int> &box1, vector<int> &box2) {
        if(box2.size() < box1.size())
            return helper(box2, box1);

        vector<int> ans;
        unordered_map<int, int> val2ind;
        for(int i = 0; i < box2.size(); i++)
            val2ind[box2[i]] = i;
    
        for(int i = 0; i < box1.size(); i++) {
            int cur = box1[i];
            bool f = false;

            for(int j = val2ind[cur]; j < box2.size(); j++) {
                if(box2[j] > cur) {
                    cur = box2[j];
                    f = true;
                    break;
                }
            }
            if(!f)
                ans.push_back(-1);
            else
                ans.push_back(cur);
        }
        return ans; 
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2);
    }
};
