class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans, tmp;
        int chars = 0, spaces = 0;
        vector<vector<string>> lines;

        for(int i = 0; i < words.size(); i++) {
            tmp.push_back(words[i]);
            chars += words[i].length();
            spaces = tmp.size() - 1;

            if(chars + spaces <= maxWidth)
                continue;
            
            else {
                tmp.pop_back();
                lines.push_back(tmp);
                tmp = {words[i]};
                chars = words[i].length();
                spaces = 0;
            }
        }

        if(not tmp.empty())
            lines.push_back(tmp);

        for(int ind = 0; ind < lines.size(); ind++) {
            auto &vec = lines[ind];
            int s = vec.size();
            int chars = 0, spaces = 0;

            for(string &word : vec)
                chars += word.length();
            
            spaces = maxWidth - chars;
            int gaps = s - 1;

            string t;

            if(ind == lines.size() - 1) {
                for(int i =0 ; i < s; i++)
                    if(i == s - 1) t += vec[i];
                    else t += vec[i] + ' ';
            }
            else {
                for(int i = 0; i < s; i++) {
                    int add = gaps == 0 ? 0 : ceil((float)spaces / (float)gaps);
                    t += vec[i] + string(add, ' ');
                    spaces -= add, gaps -= 1;
                }
            }

            while(t.length() < maxWidth) t += ' ';

            ans.push_back(t);
        }

        return ans;
    }
};
