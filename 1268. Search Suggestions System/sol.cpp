class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        vector<vector<string>> ans;
        
        sort(products.begin(), products.end());
        
        auto start = products.begin();
        string s;
        
        for(char &x : searchWord) {
            s += x;
            start = lower_bound(start, products.end(), s);
            int ind = start - products.begin();
            
            vector<string> tmp;
            for(int i = ind; i < min(ind + 3, n); i++)
                if(products[i].find(s) != string::npos)
                    tmp.push_back(products[i]);
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
