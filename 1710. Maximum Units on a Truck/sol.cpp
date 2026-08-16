class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        };
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans = 0;
        
        for(auto &x : boxTypes) {
            if(truckSize == 0) break;
            
            if(truckSize >= x[0])
                ans += x[0] * x[1], truckSize -= x[0];
            
            else
                ans += truckSize * x[1], truckSize = 0;
        }
        
        return ans;
    }
};
