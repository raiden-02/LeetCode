//topological sort
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<>();
        ans.add(0);
        
        if(edges.length == 0)
            return ans;
        
        Map<Integer, List<Integer>> g = new HashMap<>();
        int[] deg = new int[n];
        
        for(int[] x : edges) {
            g.computeIfAbsent(x[0], o -> new ArrayList<>()).add(x[1]);
            g.computeIfAbsent(x[1], o -> new ArrayList<>()).add(x[0]);
            deg[x[0]]++; deg[x[1]]++;
        }
        
        
        Queue<Integer> q = new LinkedList<>();
        boolean vis[] = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1) {
                q.add(i);
                vis[i] = true;
            }
            
            ans.add(i);
        }
        
        while(!q.isEmpty()) {
            
            int s = q.size();
            ans.clear();
            
            while(s != 0) {
                int cur = q.poll();
                ans.add(cur);
                
                for(int neigh : g.get(cur)) {
                    if(vis[neigh]) continue;
                    deg[neigh]--;
                    
                    if(deg[neigh] == 1) {
                        q.offer(neigh);
                        vis[neigh] = true;
                    }
                }
                
                s--;
            }
        }
        
        return ans;
    }
}

//topological sort
