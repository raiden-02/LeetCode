//topological sort
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> g = new HashMap<>();
        int[] indeg = new int[numCourses];
        int zeroIn = 0;
        
        for(int[] x : prerequisites) {
            if(!g.containsKey(x[1]))
                g.put(x[1], new ArrayList<>());
            
            g.get(x[1]).add(x[0]);
            indeg[x[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        List<Integer> ans = new ArrayList<>();
        
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.add(i);
                zeroIn++;
                ans.add(i);
            }
        }
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            
            for(int neigh : g.getOrDefault(cur, new ArrayList<>())) {
                indeg[neigh]--;
                
                if(indeg[neigh] == 0) {
                    ans.add(neigh);
                    q.add(neigh);
                    zeroIn++;
                }
            }
        }
        
        if(zeroIn != numCourses) return new int[0];
        
        int[] ret = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++) ret[i] = ans.get(i);
        
        return ret;
    }
}
