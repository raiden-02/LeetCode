//intuitive constructor : Time O(N) Space O(N), pick : time O(1)

class Solution {
    unordered_map<int, vector<int>> index;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            index[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int randind = rand() % index[target].size();
        return index[target][randind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
 
 //constructor : time O(1) space O(1), pick : O(N) Reservior Sampling
 class Solution {
    vector<int> *arr;
public:
    Solution(vector<int>& nums) {
        arr = &nums; //assign reference
    }
    
    int pick(int target) {
        int ret = -1;
        int i = 0, c = 0;
        
        for(int &x : *arr) {
            if(target == x) {
                if(rand() % (c + 1) == c)  //if the random gives c then select the last one that is new one
                    ret = i;
                c++;
            }
            i++;
        }
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
 
 //constructor : time O(NLogN) space O(N), pick : O(logN) binary search
 class Solution {
    vector<pair<int, int>> arr;
    
    static bool comp(pair<int, int> const& a, pair<int, int> const& b) {
        return a.first < b.first;
    }
    
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], i});
        
        sort(arr.begin(), arr.end(), comp);
    }
    
    int pick(int target) {
        
        auto bounds = equal_range(arr.begin(), arr.end(), pair<int, int>({target, 0}), comp);
        int start = bounds.first - arr.begin(), end = bounds.second - arr.begin();
        
        return arr[start + rand() % (end - start)].second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
