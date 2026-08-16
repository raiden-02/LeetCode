class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> ver1, ver2;
        string s;
        stringstream s1(version1), s2(version2);
        
        while(getline(s1, s, '.'))
            ver1.push_back(s);
        
        while(getline(s2, s, '.'))
            ver2.push_back(s);
        
        int i = 0, m = ver1.size(), n = ver2.size(), len = min(m, n);
        
        for(; i < len; i++) {
            int k = 0, l = 0;
            
            while(k < ver1[i].size() and ver1[i][k] == '0')
                k++;
            
            while(l < ver2[i].size() and ver2[i][l] == '0')
                l++;
            
            string v1 = ver1[i].substr(k), v2 = ver2[i].substr(l);
            int a = v1.empty() ? 0 : stoi(v1), b = v2.empty() ? 0 : stoi(v2);
            
            if(a < b) return -1;
            else if(a > b) return 1;
        }
        
       for(int j = i; j < ver1.size(); j++) {
            for(char x : ver1[j])
                if(x != '0')
                    return 1;
        }
        
        for(int j = i; j < ver2.size(); j++) {
            for(char x : ver2[j])
                if(x != '0')
                    return -1;
        }
        
        return 0;
    }
};

// --- alternate solution ---

class Solution {
public:
    int compareVersion(string s, string t) {
        int i = 0, j = 0;
        bool f1 = false, f2 = false;
        
        while(not(f1 and f2)) {
            string rs, rt;
            int n1, n2;
            
            if(i >= s.length())
                n1 = 0, f1 = true;
            else {
                while(i < s.length() and s[i] != '.')
                    rs += s[i], i++;
                i++;
                n1 = stoi(rs);
            }
            
            if(j >= t.length())
                n2 = 0, f2 = true;
            else {
                while(j < t.length() and t[j] != '.')
                    rt += t[j], j++;
                j++;
                n2 = stoi(rt);
            }
            
            if(n1 > n2)
                return 1;
            
            else if(n1 < n2)
                return -1;
        }
        
        return 0;
    }
};
