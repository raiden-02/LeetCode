class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1])
                continue;
            
            nums[ind++] = nums[i];
        }
        
        return ind;
    }
};
