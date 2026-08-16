class Solution {
public:
    bool winnerOfGame(string colors) {
        char prev = colors[0];
        int len = 1, aCnt = 0, bCnt = 0;

        for(int i = 1; i < colors.length(); i++) {
            if(colors[i] == prev) {
                len++;
            }

            else {
                if(prev == 'A' && len >= 3) aCnt += (len - 2);
                else if(prev == 'B' && len >= 3) bCnt += (len - 2);
                prev = colors[i];
                len = 1;
            }
        }

        if(prev == 'A' && len >= 3) aCnt += (len - 2);
        else if(prev == 'B' && len >= 3) bCnt += (len - 2);
        
        return aCnt > bCnt;
    }
};
