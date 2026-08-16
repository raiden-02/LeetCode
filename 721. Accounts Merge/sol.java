class Solution {
    private Map<String, Set<String>> mp;
    private Map<String, Boolean> vis;
    
    private List<String> bfs(String s) {
        if(vis.getOrDefault(s, false)) return new ArrayList<>();
        
        List<String> tmp = new ArrayList<>();
        Queue<String> q = new LinkedList<>();
        q.add(s);
        vis.put(s, true);
        
        while(!q.isEmpty()) {
            String cur = q.poll();
            tmp.add(cur);
            
            for(String neigh : mp.getOrDefault(cur, new HashSet<>())) {
                if(!vis.getOrDefault(neigh, false)) {
                    q.add(neigh);
                    vis.put(neigh, true);
                }
            }
        }
        
        return tmp;
    }
    
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        mp = new HashMap<>();
        vis = new HashMap<>();
        
        for(List<String> account : accounts) {
            for(int i = 1; i < account.size(); i++) {
                for(int j = i + 1; j < account.size(); j++) {
                    if(i == j) continue;
                    if(!mp.containsKey(account.get(i)))
                        mp.put(account.get(i), new HashSet<>());
                    if(!mp.containsKey(account.get(j)))
                        mp.put(account.get(j), new HashSet<>());
                    mp.get(account.get(i)).add(account.get(j));
                    mp.get(account.get(j)).add(account.get(i));
                }
            }
        }
        
        List<List<String>> ans = new ArrayList<>();
        
        for(List<String> account : accounts) {
            List<String> tmp = bfs(account.get(1));
            
            if(!tmp.isEmpty()) {
                Collections.sort(tmp);
                tmp.add(0, account.get(0));
                ans.add(tmp);
            }
        }
        
        return ans;
    }
}
