class Solution {
public:
    string originalDigits(string s) {
        vector<string> eng = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<char> keys = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> freq(26);
        string ans;
        
        for(char x : s)
            freq[x - 'a']++;
        
        for(int i = 0; i < 10; i++) {
            int c = freq[keys[i] - 'a'];
            //cout << keys[i] << " " << c<< endl;
            for(int j = 0; j < eng[i].length(); j++) //deleting other chars in the eng word to not interfere with character keys of the other numbers, for this current char key it will become 0, wont be used again
                freq[eng[i][j] - 'a'] -= c;
            
            while(c--)
                ans.push_back(nums[i] + '0');
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
