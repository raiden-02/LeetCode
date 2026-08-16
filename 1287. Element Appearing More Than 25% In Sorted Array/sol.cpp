class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), freq = n / 4;
        vector<int> tmp = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};

        for(int x : tmp) {
            int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;

            if(r - l + 1 > freq) return x;
        }

        return -1;
    }
};
