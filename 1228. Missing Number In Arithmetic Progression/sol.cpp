class Solution {
public:
    int missingNumber(vector<int>& arr) {
        bool f = arr[1] - arr[0] > 0;
        int ans = INT_MIN;
        
        if(!f)
            reverse(arr.begin(), arr.end());
        
        for(int i = 1; i < arr.size(); i++) {
            int d = arr[i] - arr[i - 1];
            ans = max(ans, d);
        }
        
        for(int i = 1; i < arr.size(); i++) {
            int d = arr[i] - arr[i - 1];
            
            if(d == ans)
                return (arr[i - 1] + arr[i]) / 2;
        }
        
        return -1;
    }
};
