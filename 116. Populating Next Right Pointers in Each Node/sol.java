class Solution {
    public Node connect(Node root) {
        if(root == null) return root;
        
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        
        while(!q.isEmpty()) {
            int s = q.size();
            List<Node> list = new ArrayList<>();
            
            while(s-- > 0) {
                Node cur = q.poll();
                list.add(cur);
                
                if(cur.left != null)
                    q.add(cur.left);
                
                if(cur.right != null)
                    q.add(cur.right);
            }
            
            for(int i = 0; i < list.size() - 1; i++)
                list.get(i).next = list.get(i + 1);
            
            list.get(list.size() - 1).next = null;
        }
        
        return root;
    }
}

/*
// Definition for a Node.
