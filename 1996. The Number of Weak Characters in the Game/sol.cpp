class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0] or (a[0] == b[0] and a[1] < b[1]);
        };
        
        sort(properties.begin(), properties.end(), comp);
        
        int ans = 0, maxThusFar = INT_MIN;
        
        for(int i = 0; i < properties.size(); i++) {
            if(maxThusFar > properties[i][1])
                ans++;
            else
                maxThusFar = properties[i][1];
        }
        
        return ans;
    }
};
