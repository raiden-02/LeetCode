//intuitive O(n) with extra memory
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> left, right;
        
        for(int &x : nums)
            x ? left.push_back(x) : right.push_back(x);
        
        left.insert(left.end(), right.begin(), right.end());
        
        for(int i = 0; i < n; i++) nums[i] = left[i];
    }
};

//O(n) in place

// --- alternate solution ---

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                if(i != ind)
                    nums[ind] = nums[i], nums[i] = 0;
                ind++;
            }
        }
    }
};

// --- alternate solution ---

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                swap(nums[ind++], nums[i]);
        }
    }
};
