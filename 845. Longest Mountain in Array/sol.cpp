class Solution {
public:
    int longestMountain(vector<int>& arr) {
        bool inc = false, dec = false;
        int n = arr.size(), ans = 0, len = 1;
        
        for(int i = 0; i < n - 1; i++) {
            if(not inc and not dec) {
                if(arr[i + 1] > arr[i]) inc = true, len++;
            }
            
            else if(inc and not dec) {
                if(arr[i + 1] > arr[i]) len++;
                else if(arr[i + 1] < arr[i]) dec = true, len++;
                else len = 1, inc = false, dec = false;
            }
            
            else if(inc and dec) {
                if(arr[i + 1] < arr[i]) len++;
                else {
                    inc = false, dec = false, ans = max(ans, len);
                    arr[i + 1] > arr[i] ? len = 2, inc = true : len = 1;
                }
            }
        }
        
        if(inc and dec) ans = max(ans, len);
        
        return ans;
    }
};
