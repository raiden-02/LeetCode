class Solution {
    Node *head, *tail;
    
    void helper(Node *root) {
        if(not root)
            return;
        
        helper(root->left);
        
        if(tail)
            tail->right = root, root->left = tail;
        else
            head = root;
        
        tail = root;
        
        helper(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(not root)
            return nullptr;
        
        helper(root);
        
        head->left = tail;
        tail->right = head;
        
        return head;
    }
};

// --- alternate solution ---

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
