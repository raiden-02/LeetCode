class Solution {
public:
    bool detectCapitalUse(string word) {
        bool a = true, b = true, c = isupper(word[0]);

        for(int i = 0; i < word.length(); i++) {
            if(a and not isupper(word[i])) {
                a = false;
            }

            else if(b and not islower(word[i])) {
                b = false;
            }

            else if(i > 0 and not islower(word[i])) {
                c = false;
            }

            else if(not a and not b and not c)
                break;
        }

        return a or b or c;
    }
};
