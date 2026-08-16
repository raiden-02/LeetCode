class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0, r = tokens.size() - 1, score = 0;
        sort(tokens.begin(), tokens.end());
        
        while(l <= r) {
            if(power >= tokens[l]) {
                power -= tokens[l];
                score++;
                l++;
            }

            else if(score >= 1) {
                if(l != r) { // only if there's something more to add to score
                    power += tokens[r];
                    score--;
                    r--;
                }

                else return score;
            }

            else return 0;
        }

        return score;
    }
};
