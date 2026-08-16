class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n + 1);
        
        for(int &x : nums)
            vis[x] = true;
        
        for(int i = 0; i < n + 1; i++) {
            if(!vis[i])
                return i;
        }
        
        return -1;
    }
};

//O(1) space O(n) time intuitive math

// --- alternate solution ---

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        int s = n * (n + 1) / 2, i = 0;
        
        for(; i < n + 1; i++) {
            if(s - x == i)
                break;
        }
        
        return i;
    }
};

//O(1) space O(n) time xor

// --- alternate solution ---

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int calc_sum = n * (n + 1) / 2;
        int actual_sum = accumulate(nums.begin(), nums.end(), 0);

        return calc_sum - actual_sum; 
    }
};

//O(n) space O(n) time intuitive

// --- alternate solution ---

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            n ^= (i ^ nums[i]); //xor
        return n;
    }
};
