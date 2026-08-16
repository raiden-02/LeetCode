class Solution {
private:
    vector<string> tokenize(string const& s) {
        stringstream ss(s);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ' ')) { // Tokenize by space
            tokens.push_back(token);
        }

        return tokens;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> vec1 = tokenize(sentence1), vec2 = tokenize(sentence2);
        size_t m = vec1.size(), n = vec2.size();
        int l1 = 0, l2  = 0, r1 = m - 1, r2 = n - 1;
        if(m < n) swap(vec1, vec2), swap(m, n), swap(r1, r2);
        int cnt = 0;

        while(l1 <= r1 && l2 <= r2 && vec1[l1] == vec2[l2]) {
            cnt++; 
            l1++ , l2++;
        }

        while(l1 <= r1 && l2 <= r2 && vec1[r1] == vec2[r2]) {
            cnt++;
            r1--, r2--;
        }

        cout << cnt << endl;
        return cnt == n;
    }
};
