class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vis(nums.begin(), nums.end());
        int ans = 0, len = 0, prev, next;
        
        for(int &x : nums) {
            if(vis.find(x) == vis.end()) continue;
            
            len = 1, vis.erase(x), prev = x - 1, next = x + 1;
            
            while(vis.find(next) != vis.end()) len++, vis.erase(next++);
            while(vis.find(prev) != vis.end()) len++, vis.erase(prev--);
            
            ans = max(ans, len);
        }
        
        return ans;
    }
};

//O(nlogn) set

// --- alternate solution ---

//O(nlogn) intuitive
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int len = 1, ans = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            //cout << nums[i] << " " << len << endl;
            
            if(nums[i] == nums[i - 1] + 1) len++;
            else if(nums[i] == nums[i - 1]) continue;
            else len = 1;
            
            ans = max(ans, len);
        }
        
        return max(ans, len);
    }
};

//avg O(n) unordered_set

// --- alternate solution ---

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        set<int> st(nums.begin(), nums.end());
        nums = vector<int>(st.begin(), st.end());
        int ans = 0, c = 1;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i + 1] == nums[i] + 1)
                 c += 1;
            
            else {
                ans = max(c, ans);
                c = 1;
            }
        }
        ans = max(c, ans);
        return ans;
    }
};
