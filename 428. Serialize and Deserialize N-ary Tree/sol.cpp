class Codec {
    void helper(Node* root, ostringstream &ss) {
        if(not root) return;
        ss << root->val << " " << root->children.size() << " ";
        for(Node* child : root->children) helper(child, ss);
    }

    Node* helper(istringstream &ss) {
        ss.peek();
        if(ss.eof()) return nullptr;
        int childsize;
        Node* node = new Node();
        ss >> node->val >> childsize;
        for(int i = 0; i < childsize; i++) node->children.push_back(helper(ss));

        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        ostringstream s;
        helper(root, s);
        return s.str();
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream ss(data);
        return helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
