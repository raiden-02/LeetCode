class Solution {
    private List<List<Integer>> ans;
    private boolean vis[];
    private int n;
    
    private void dfs(int cur, int[][] g, List<Integer> path) {
        vis[cur] = true;
        path.add(cur);
        
        for(int x : g[cur]) {
            if(!vis[x]) {
                if(x == n - 1) {
                    path.add(x);
                    ans.add(new ArrayList<>(path));
                    path.remove(path.size() - 1);
                }
                
                else
                    dfs(x, g, path);
            }
        }
        
        vis[cur] = false;
        path.remove(path.size() - 1);
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        n = graph.length;
        vis = new boolean[n];
        List<Integer> path = new ArrayList<>();
        ans = new ArrayList<>();
        dfs(0, graph, path);
        return ans;
    }
}
