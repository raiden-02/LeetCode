/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
    void serialize(TreeNode* root, ostringstream &s) {
        if(not root) {
            s << "$ ";
            return;
        }
        
        s << root->val << " ";
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
    TreeNode* deserialize(istringstream &s) {
        string k;
        s >> k;
        if(k == "$")
            return nullptr;
        
        TreeNode* root = new TreeNode(stoi(k));
        root->left = deserialize(s);
        root->right = deserialize(s);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
