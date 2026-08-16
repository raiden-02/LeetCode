class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int x = target / (n - i);
            
            x = abs(target - x * (n - i)) > abs(target - (x + 1) * (n - i)) ? x + 1 : x;
            
            if(x < arr[i])
                return x;
            
            target -= arr[i];
        }
        
        return arr.back();
    }
};
