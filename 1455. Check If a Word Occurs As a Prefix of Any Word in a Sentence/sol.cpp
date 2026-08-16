// Main thing to note here is using std::string_view instead of std::string as it avoids copying strings, string_view doesn't own its memory and just points to an existing string (non-owning view ober a contiguous sequence of characters)

class Solution {
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        string_view view = str;
        size_t start = 0, end;

        while((end = view.find(delimiter, start)) != string_view::npos) {
            tokens.emplace_back(view.substr(start, end - start));
            start = end + 1;
        }

        tokens.emplace_back(view.substr(start));
        return tokens;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> tokens = split(sentence, ' ');

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i].starts_with(searchWord))
                return i + 1;
        }

        return -1;
    }
};
