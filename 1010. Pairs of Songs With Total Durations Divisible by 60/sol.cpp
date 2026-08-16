class Solution {
    //for 0 case (A + B) % N = (A % N + B % N) % N
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mp(60);
        int ans = 0;
        
        for(int &i : time)
            ans += mp[(60 - i % 60) % 60], mp[i % 60]++;
        
        return ans;
    }
};
