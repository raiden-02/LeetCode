//Floyd Warshall

class Solution {
public:
    /*It depends. Running Dijkstra for all nodes gives you O(VE + V^2log V), while Floyd's is     O(V^3). If E = O(V^2), then the two are theoretically identical, with Floyd being faster     in practice. If you E = O(V), then running Dijkstra for all nodes if better both in           theory and in practice.

    Basically, run Dijkstra from all nodes if you expect to have about as many edges as you       have nodes, and run Floyd if you expect to have almost complete graphs.
    */
    
    //this question from the constraints it can be inferred that we will have complete graphs in our test cases => floyd warshall better than djikstra
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int>(n, 10001));
        
        for(auto &x : edges)
            d[x[0]][x[1]] = x[2], d[x[1]][x[0]] = x[2];
        
        for (int k = 0; k < n; ++k) {
            d[k][k] = 0;
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] < 10001 && d[k][j] < 10001) // for negativ edge weights(not present in this problem)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                }
            }
        }
        
        int city = -1;
        int minCount = n;
        
        for(int i = 0; i < n; i++) {
            int counter = 0;
                
            for(int j = 0; j < n; j++) {
                if(d[i][j] <= distanceThreshold)
                    counter++;
            }
            
            if(counter <= minCount) //return the city with the greatest number if minCount is equal
                minCount = counter, city = i;
        }
        
        return city;
    }
};
