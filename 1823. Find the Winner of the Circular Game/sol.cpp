//intuitive simulation
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> arr(n);
        int rem = n, pos = 0, ans;
        
        while(rem > 1) {
            int counter = 0;
            int mark = pos;
            
            while(counter != k) {
                
                if(!arr[pos])
                    counter++, mark = pos;
                
                pos = (pos + 1) % n;
            }
            rem--;
            arr[mark] = true;
        }
        
        for(int i = 0; i < n; i++) {
            if(!arr[i]) {
                ans = i + 1;
                break;
            }
        }
        
        return ans;
    }
};

//josephus problem

// --- alternate solution ---

class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
            ans = (ans + k) % i;
        
        return ans + 1;
    }
};
