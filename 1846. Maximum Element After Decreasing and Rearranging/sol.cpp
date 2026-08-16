class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1)
            return 1;
        
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i - 1])
                arr[i] = arr[i - 1];
            
            else if(arr[i] - arr[i - 1] > 1)
                arr[i] = arr[i - 1] + 1;
            
            else
                arr[i] = arr[i];
        }
        
        return arr.back();
    }
};
