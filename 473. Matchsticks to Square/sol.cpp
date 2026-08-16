class Solution {
    vector<bool> vis;
    
    bool helper(vector<int> const& arr, int ind, int s, int const& tot, int div) {
        if(div == 1)
            return true;
        
        if(s == tot)
            return helper(arr, 0, 0, tot, div - 1);
        
        for(int i = ind; i < arr.size(); i++) {
            if(vis[i] or arr[i] + s > tot) continue;
            
            vis[i] = true;
            if(helper(arr, i + 1, s + arr[i], tot, div)) return true;
            vis[i] = false;
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int tot = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if(matchsticks.size() < 4 or tot % 4)
            return false;
        
        tot /= 4;
        vis.resize(matchsticks.size(), false);
        
        return helper(matchsticks, 0, 0, tot, 4);
    }
};

// --- alternate solution ---

#include <ciso646>

using namespace std;

vector<bool> vis;

bool helper(vector<int> const& arr, int const& n, int ind, int div, int s, int const& tot) {
    if(div == 3) return true;

    if(s == tot) return helper(arr, n, 0, div + 1, 0, tot);

    for(int i = ind; i < n; i++) {
        if(vis[i] or arr[i] + s > tot) continue;

        vis[i] = true;
        if(helper(arr, n, i + 1, div, s + arr[i], tot)) return true;
        vis[i] = false;
    }

    return false;
}

int main() {
    int n, s = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i], s += arr[i];

    vis.assign(n, false);
    n < 4 or s % 4 ? cout << "false" : helper(arr, n, 0, 0, 0, s / 4) ? cout << "true" : cout << "false";
}

// --- alternate solution ---

#include <iostream>

// --- alternate solution ---

#include <vector>
