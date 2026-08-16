//intuitive O(n * (no of repeated elements more than 2) * len vector to be shifted)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp, ind;
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            int val = nums[i];
            mp[val]++;
            
            if(mp[val] > 2)
                nums.erase(nums.begin() + i), mp[val]--;
        }
        
        return nums.size();
    }
};

//optimized O(n)

// --- alternate solution ---

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        for(int &x : nums) {
            if(i < 2 or x > nums[i - 2])
                nums[i++] = x;
        }
        
        return i;
    }
};
