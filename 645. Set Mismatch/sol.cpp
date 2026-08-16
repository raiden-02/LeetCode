class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        
        for(int i = 0; i < n;) {
            if(nums[i] == i + 1) {
                i++;
                continue;
            }
            
            if(nums[i] == nums[nums[i] - 1]) {
                ans[0] = nums[i];
                i++;
                continue;
            }
            
            swap(nums[i], nums[nums[i] - 1]);
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 != i) {
                ans[1] = i + 1;
                break;
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size() == 2)
                ans[0] = nums[i];
        }
        
        for(int i = 1; i <= n; i++) {
            if(mp.find(i) == mp.end()) {
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};
