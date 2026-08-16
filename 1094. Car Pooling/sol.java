class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer, Integer> time2pass = new TreeMap<>();
        
        for(int[] x : trips) {
            time2pass.put(x[1], x[0] + time2pass.getOrDefault(x[1], 0));
            time2pass.put(x[2], time2pass.getOrDefault(x[2], 0) - x[0]);
        }
        
        for(int x : time2pass.values()) {
            capacity -= x;
            
            if(capacity < 0)
                return false;
        }
        
        return true;
    }
}
