class Solution {
    private void reverse(int[] nums, int start, int end) {
        for(int l = start, r = end; l <= r; l++, r--) {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
        }
    }
    
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
}

//O(n) time O(1) space

// --- alternate solution ---

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> q(nums.begin(), nums.end());
        
        while(k--) {
            int cur = q.back(); q.pop_back();
            q.push_front(cur);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = q.front(); q.pop_front();
        }
    }
};

// --- alternate solution ---

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++)
            temp[(i + k) % n] = nums[i];
        for(int i = 0; i < n; i++)
            nums[i] = temp[i];
    }
};

//O(n) time O(n) space deque

// --- alternate solution ---

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

//O(n) time O(n) space
