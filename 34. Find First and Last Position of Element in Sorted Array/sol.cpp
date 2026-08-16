class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1, pos = -1;
        
        while(left <= right) {
            int mid = (left + right) >> 1;
            
            if(arr[mid] == target) {
                pos = mid;
                break;
            }
            
            if(arr[mid] < target)
                left = mid + 1;
            
            else
                right = mid - 1;
        }
        
        if(pos == -1)
            return {-1, -1};
        
        left = pos - 1, right = pos + 1;
        
        while((left >= 0 and arr[left] == arr[pos]) or (right < arr.size() and arr[right] == arr[pos])) {
            if(left >= 0 and arr[left] == arr[pos])
                left--;
            if(right < arr.size() and arr[right] == arr[pos])
                right++;
        }
        
        return {left + 1, right - 1};
    }
};

//O(n)

// --- alternate solution ---

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(start == -1) start = i;
                end = i;
            }
            
            else if(nums[i] > target)
                break;
        }
        
        return {start, end};
    }
};

// --- alternate solution ---

//binary search c++ stl
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(l >= nums.size() or nums[l] != target) return {-1, -1};
        
        return {l, r - 1};
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(l == r)
            return {-1, -1};
        
        return {l, r - 1};
    }
};


//binary search O(logn)
