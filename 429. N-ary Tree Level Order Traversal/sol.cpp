class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(not root)
            return {};
        
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});
        
        while(not q.empty()) {
            int s = q.size();
            vector<int> tmp;
            
            while(s--) {
                Node* cur = q.front(); q.pop();
    
                for(Node* child : cur->children) {
                    q.push(child);
                    tmp.push_back(child->val);
                }
            }
            
            if(tmp.empty()) continue;
            ans.push_back(tmp);
        }
        
        return ans;
    }
};

/*
// Definition for a Node.

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(not root) return {};
        
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(not q.empty()) {
            int s = q.size();
            vector<int> tmp;
            
            while(s--) {
                Node* cur = q.front(); q.pop();
                tmp.push_back(cur->val);
                
                for(Node* node : cur->children)
                    q.push(node);
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};

// --- alternate solution ---

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// --- alternate solution ---

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
