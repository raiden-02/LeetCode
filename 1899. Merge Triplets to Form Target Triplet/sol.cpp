class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> prev(3);
        //sort(triplets.begin(), triplets.end());
        
        for(int i = 0; i < triplets.size(); i++) {
            bool f = false;
            
            for(int j = 0; j < 3; j++) {
                if(triplets[i][j] > target[j]) {
                    f = true;
                    break;
                }
            }
            
            if(f) continue;
            
            for(int j = 0; j < 3; j++)
                triplets[i][j] = max(triplets[i][j], prev[j]);
            
            if(triplets[i] == target)
                return true;
            
            prev = triplets[i];
        }
        
        return false;
    }
};
