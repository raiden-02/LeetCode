class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n);
        
        for(int x : nums) {
            freq[x - 1]++;
            if(freq[x - 1] > 1)
                return x;
        }
        
        return -1;
    }
};

// --- alternate solution ---

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        
        for(int x : nums) {
            if(st.find(x) != st.end())
                return x;
            st.insert(x);
        }
        
        return -1;
    }
};

// --- alternate solution ---

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]]) swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};
