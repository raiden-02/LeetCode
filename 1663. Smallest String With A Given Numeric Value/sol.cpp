class Solution {
public:
    string getSmallestString(int n, int k) {
        string alpha = "abcdefghijklmnopqrstuvwxyz", ans;
        
        for(int i = 0; i < n; i++) {
            int rem = n - i - 1;
            
            for(char x : alpha) {
                int val = x -'a' + 1;
                
                if(k - val <= 26 * rem) {
                    ans.push_back(x), k -= val;
                    break;
                }
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i = 1; i <= n; i++) {
            int rem = n - i;
            for(char c = 'a'; c <= 'z'; c++) {
                if(k - (c - 'a' + 1) <= rem * 26) {
                    k -= (c - 'a' + 1);
                    ans += c;
                    break;
                }
            }
        }
        return ans;
    }
};
