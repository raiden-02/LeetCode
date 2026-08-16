//hashmap optimised linear
class Solution {
public:
    /*
    for [23, 2, 4, 6, 6] 7
    remainder map = 2,0  4,1  1,2  0,3  6,4
    we are finding a subset[0:4] where the sum is divisible by 7
    if a sum is directly divisible without any slicing or using the criteria, then to satisfy the lenght condition we put map[0] = -1, otherwise this would return false since there is no other 0 remainder in the map 
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp = {{0, -1}};//remainder->index
        int s = 0;
        
        for(int i = 0; i < n; i++) {
            s += nums[i];
            
            if(k)
                s %= k;
            
            if(mp.find(s) != mp.end()) {
                if(i - mp[s] > 1)
                    return true;
            }
            else
                mp[s] = i;
        }
        
        return false;
    }
};

//quadratic time

// --- alternate solution ---

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n + 1);
        
        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + nums[i];
        
        //cout << 0 % 5 << endl;
        for(int i = 0; i < n + 1; i++) {
            for(int j = i + 1; j < n + 1; j++) {
                //cout << i << " " << j << endl;
                int cur = ps[j] - ps[i];
                if(j - i > 1 and k != 0 and cur % k == 0)
                    return true;
                if(j - i > 1 and cur == 0 and k == 0)
                    return true;
            }
        }
        
        return false;
    }
};
