class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> pos;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                pos.push_back(i);
        }
        for(int i = 1; i < pos.size();  i++) {
            if(pos[i] - pos[i - 1] - 1 < k)
                return false;
        }
        return true;
    }
};
