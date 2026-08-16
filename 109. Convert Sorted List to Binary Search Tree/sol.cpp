/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ 
    TreeNode *helper(int l, int r, vector<int> &arr) {
        if(l > r)
            return nullptr;
        
        int mid = (l + r) >> 1;
        
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = helper(l, mid - 1, arr);
        root->right = helper(mid + 1, r, arr);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(not head)
            return nullptr;
        
        vector<int> arr;
        
        for(ListNode *tmp = head; tmp; tmp = tmp->next)
            arr.push_back(tmp->val);
        
        return helper(0, arr.size() - 1, arr);
    }
};
