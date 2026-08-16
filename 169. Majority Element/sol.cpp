//Moore's O(n) time O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maj = nums[0], cnt = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == maj)
                cnt++;
            else
                cnt--;
            
            if(cnt == 0)
                maj = nums[i], cnt = 1;
        }
        
        return maj;
    }
};

//regular method O(n) S&T

// --- alternate solution ---

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size() / 2;
        
        for(int x : nums) {
            mp[x]++;
            
            if(mp[x] > n)
                return x;
        }
        
        return -1;
    }
};
