class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> tokens;
        istringstream stream(sentence);
        string token;

        while(getline(stream, token, ' ')) {
            tokens.push_back(token);
        }

        int n = tokens.size();

        for(int i = 0; i < n; i++) {
            if(tokens[i].back() != tokens[(i + 1) % n][0]) {
                return false;
            }
        }

        return true;
    }
};
