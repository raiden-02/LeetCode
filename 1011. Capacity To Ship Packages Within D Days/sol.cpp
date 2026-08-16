//intuitive top down memo TLE
class Solution {
    vector<vector<unordered_map<int, int>>> dp;
    
    int helper(vector<int> &weights, int d, int ind, int cap) {
        if(d == 0 and ind >= weights.size())
            return cap;
        
        if(d < 0 or ind >= weights.size())
            return INT_MAX;
        
        if(dp[ind][d].find(cap) != dp[ind][d].end())
            return dp[ind][d][cap];
        
        int s = 0, ans = INT_MAX;
        
        for(int i = ind; i < weights.size(); i++) {
            s += weights[i];
            ans = min(ans, helper(weights, d - 1, i + 1, max(cap, s)));
        }
        
        return dp[ind][d][cap] = ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        dp.resize(weights.size(), vector<unordered_map<int, int>>(D + 1));
        
        return helper(weights, D, 0, 0);
    }
};

//binary search nlogn

// --- alternate solution ---

class Solution {
    bool canShip(vector<int> &weights, int cap, int const& d) {
        int daysneed = 1, curw = 0;
        
        for(int &i : weights) {
            curw += i;
            
            if(curw > cap) {
                daysneed += 1;
                curw = i;
            }
        }
        
        return daysneed <= d;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while(left < right) {
            int mid = (left + right) >> 1;
            
            if(canShip(weights, mid, D))
                right = mid;
            
            else
                left = mid + 1;
        }
        
        return left;
    }
};
