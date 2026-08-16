class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);

        for(int i = 0; i < n; i++)
            arr[i] = to_string(nums[i]);
        
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            return b + a < a + b;
        });

        if(arr[0] == "0") return "0";
        
        string ret;
        for(string &x : arr)
            ret += x;
        
        return ret;
    }
};
