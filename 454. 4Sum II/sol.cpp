class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        for(int &i : A) {
            for(int &j : B)
                mp[i + j]++;
        }
        
        int ans = 0;
        for(int &i : C) {
            for(int &j : D) {
                if(mp.find(-i - j) != mp.end())
                    ans += mp[-i - j];
            }
        }
        
        return ans;
    }
};
