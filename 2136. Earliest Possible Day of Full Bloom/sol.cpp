class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size(), ans = 0, totalPlantTime = 0;
        vector<int> sortedIndices(n);
        
        for(int i = 0; i < n; i++)
            sortedIndices[i] = i;
        
        sort(sortedIndices.begin(), sortedIndices.end(), [&](int x, int y) {
            return growTime[x] > growTime[y]; 
        });
        
        for(int i = 0; i < n; i++) {
            totalPlantTime += plantTime[sortedIndices[i]];
            
            ans = max(ans, totalPlantTime + growTime[sortedIndices[i]]);
        }
        
        return ans;
    }
};
