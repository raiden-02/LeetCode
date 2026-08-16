//intuitvie
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        for(int i = 0; i < n; i++) {
            int c = 0;
            
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                
                if(knows(j, i) and not knows(i, j))
                    c++;
                
                else break;
            }
            if(c == n - 1)
                return i;
        }
        return -1;
    }
};

//two pass
/* The knows API is defined for you.
      bool knows(int a, int b); */

// --- alternate solution ---

class Solution {
public:
    int findCelebrity(int n) {
        if(n <= 1) return n;
        
        int ans = 0;
        
        for(int i = 1; i < n; i++)
            if(not knows(i, ans))
                ans = i;
        
        for(int i = 0; i < n; i++) {
            if(i == ans) continue;
            
            if(knows(ans, i) or not knows(i, ans)) return -1;
        }
        
        return ans;
    }
};
