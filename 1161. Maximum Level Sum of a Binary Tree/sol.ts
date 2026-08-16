/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function maxLevelSum(root: TreeNode | null): number {
    if(root == null)
        return null;

    let queue: Array<TreeNode>  = new Array<TreeNode>();
    queue.push(root);
    let ans: number = root.val;
    let level: number = 1;
    let lvl: number = 1;

    while(queue.length != 0) {
        let n: number = queue.length;
        let s: number = 0;
        let bchild: boolean = false;

        while(n--) {
            let cur: TreeNode = queue.shift();
            
            if(cur.left != null) {
                queue.push(cur.left);
                s += cur.left.val;
                bchild = true;
            }

            if(cur.right != null) {
                queue.push(cur.right);
                s += cur.right.val;
                bchild = true;
            }
        }

        lvl++;

        if(bchild && ans < s) {
            ans = s;
            level = lvl;
        }
    }

    return level;
};
