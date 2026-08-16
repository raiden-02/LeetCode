class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex] == target) return 0;
        
        int n = words.size(), cnt = 1;
        int l = (startIndex - 1 + n) % n, r = (startIndex + 1) % n;
        
        while(l != startIndex and r != startIndex) {
            if(words[l] == target or words[r] == target) return cnt;
            l = (l - 1 + n) % n;
            r = (r + 1) % n;
            cnt++;
        }
        
        return -1;
    }
};
