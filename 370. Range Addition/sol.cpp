class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length);
        
        for(auto &x : updates) {
            arr[x[0]] += x[2];
            
            if(x[1] + 1 < length)
                arr[x[1] + 1] -= x[2];
        }
        
        int s = 0;
        
        for(int i = 0; i < length; i++)
            s += arr[i], arr[i] = s;
        
        return arr;
    }
};
