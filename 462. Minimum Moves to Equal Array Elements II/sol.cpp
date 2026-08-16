//O(nlogn) intuitive
class Solution {
    /*
    1) find the median
    2) subtract the median from all elements and sum
    */
    
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        int med, mid = n / 2, ans = 0;
        sort(nums.begin(), nums.end());
        
        if(n % 2)
            med = nums[mid];
        else
            med = (nums[mid - 1] + nums[mid]) / 2;
        
        for(int &x : nums)
            ans += (abs(x - med));
        
        return ans;
    }
};

//O(n) avg O(nlogn) worst using nth_element to find median instead of sort

// --- alternate solution ---

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int med = *mid, ans = 0;
        
        for(int &x : nums)
            ans += abs(x - med);
        
        return ans;
    }
};
