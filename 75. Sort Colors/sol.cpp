class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> mp(3);
        for(int &i : nums)
            mp[i]++;
        
        int i = 0, j = 0;
        while(i < 3 and j < nums.size()) {
            if(mp[i])
                nums[j] = i, mp[i]--, j++;
            else
                i++;
        }
    }
};

// --- alternate solution ---

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1 = 0, c2 = 0, c3 = 0;
        
        for(int &x : nums) x == 0 ? c1++ : x == 1 ? c2++ : c3++;
        
        for(int i = 0; i < nums.size(); i++) c1 ? nums[i] = 0, c1-- : c2 ? nums[i] = 1, c2-- : nums[i] = 2, c3--;
    }
};
