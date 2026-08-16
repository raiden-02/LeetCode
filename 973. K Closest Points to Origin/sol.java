class Solution {
    public int[][] kClosest(int[][] points, int k) {
        List<List<Integer>> dists = new ArrayList<>();
        
        for(int i = 0; i < points.length; i++)
            dists.add(new ArrayList<>(Arrays.asList(points[i][0] * points[i][0] + points[i][1] * points[i][1], points[i][0], points[i][1])));
        
        Collections.sort(dists, (a, b)-> Integer.compare(a.get(0), b.get(0)));
        
        List<List<Integer>> ans = new ArrayList<>();
        
        for(int i = 0; i < k; i++)
            ans.add(dists.get(i));
        
        int[][] ret = new int[ans.size()][];
        
        for(int i = 0; i < k; i++)
            ret[i] = new int[]{ans.get(i).get(1), ans.get(i).get(2)};
        
        return ret;
            
    }
}
