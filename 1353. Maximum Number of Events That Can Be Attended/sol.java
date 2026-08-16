class Solution {
    
    //segemnt tree node class
    class SegmentTreeNode {
        int start, end;
        SegmentTreeNode left, right;
        boolean val;
        
        public SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            left = null;
            right = null;
            val = true;
        }
    }
    
    // Method to return the maximum programs can attend
    public int maxEvents(int[][] programs) {
        int start = Integer.MAX_VALUE, end = Integer.MIN_VALUE;
        int ans = 0;
        Arrays.sort(programs, (i, j) -> Integer.compare(i[1], j[1]));
        for(int[] x : programs) {
            start = Math.min(start, x[0]);
            end = Math.max(end, x[1]);
        }
        SegmentTreeNode root = buildSegmentTree(start, end);
        for(int[] x : programs) {
            if(query(root, x[0], x[1]))
                ans += 1;
        }
        return ans;
    }
    
    // Method to build segment tree
    private SegmentTreeNode buildSegmentTree(int start, int end) {
        SegmentTreeNode root = new SegmentTreeNode(start, end);
        if(start >= end) return root;
        int m = (start + end) / 2;
        root.left = buildSegmentTree(start, m);
        root.right = buildSegmentTree(m + 1, end);
        return root;
    }
    
    // Method to perform Query
    private boolean query(SegmentTreeNode curr, int left, int right) {
        if(curr == null || right < curr.start || left > curr.end || curr.val == false)
            return false;
        if(curr.start == curr.end) {
            curr.val = false;
            return true;
        }
        curr.val = query(curr.left, left, right) || query(curr.right, left, right);
        return curr.val;
    }  
    
}
