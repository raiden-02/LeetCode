class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null)
            return root;
        
        if(root.val == key) {
            if(root.left != null && root.right != null) {
                TreeNode l = root.left;
                root = root.right;

                TreeNode cur = root;

                while(cur != null && cur.left != null)
                    cur = cur.left;

                if(cur != null) cur.left = l;
            }
            
            else if(root.left == null || root.right == null) {
                if(root.left != null)
                    root = root.left;
                else
                    root = root.right;
            }
            
            return root;
        }
        
        if(key < root.val)
            root.left = deleteNode(root.left, key);
        
        else
            root.right = deleteNode(root.right, key);
        
        return root;
    }
}
