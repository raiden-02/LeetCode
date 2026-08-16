class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> arr = nums;
        vector<vector<int>> ans = {nums};
        
        do {
            next_permutation(arr.begin(), arr.end());
            
            if(arr != nums)
                ans.push_back(arr);
            
        } while(arr != nums);
        
        return ans;
    }
};
