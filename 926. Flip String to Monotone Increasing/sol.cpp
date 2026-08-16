class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0, ones = 0;

        for(char x : s)
            x == '1' ? ones++ : flips = min(++flips, ones);
        
        return flips;
    }
};
