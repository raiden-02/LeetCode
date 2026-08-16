public class Solution {
    public int[] CountWordOccurrences(string[] chunks, string[] queries) {
        StringBuilder sb = new StringBuilder();
        foreach (string chunk in chunks) {
            sb.Append(chunk);
        }
        string s = sb.ToString();
        
        Dictionary<string, int> fs = new Dictionary<string, int>();
        StringBuilder tmp = new StringBuilder();
        
        for (int i = 0; i <= s.Length; i++) {
            // Check if current position is a separator OR end of string
            bool isSeparator = false;
            if (i < s.Length) {
                if (s[i] == '-') {
                    // Check if it's a joiner hyphen
                    if (i - 1 >= 0 && char.IsLower(s[i - 1]) && 
                        i + 1 < s.Length && char.IsLower(s[i + 1])) {
                        tmp.Append(s[i]);
                    } else {
                        isSeparator = true;
                    }
                } else if (s[i] == ' ' || !char.IsLower(s[i])) {
                    isSeparator = true;
                } else {
                    tmp.Append(s[i]);
                }
            } else {
                // End of string - process last word
                isSeparator = tmp.Length > 0;
            }
            
            // Process completed word
            if (isSeparator && tmp.Length > 0) {
                string word = tmp.ToString();
                if (fs.ContainsKey(word)) {
                    fs[word]++;
                } else {
                    fs[word] = 1;
                }
                tmp.Clear();
            }
        }
        
        int[] ans = new int[queries.Length];
        for (int i = 0; i < queries.Length; i++) {
            ans[i] = fs.ContainsKey(queries[i]) ? fs[queries[i]] : 0;
        }
        
        return ans;
    }
}
